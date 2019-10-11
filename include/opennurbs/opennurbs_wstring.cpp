/* $NoKeywords: $ */
/*
//
// Copyright (c) 1993-2012 Robert McNeel & Associates. All rights reserved.
// OpenNURBS, Rhinoceros, and Rhino3D are registered trademarks of Robert
// McNeel & Associates.
//
// THIS SOFTWARE IS PROVIDED "AS IS" WITHOUT EXPRESS OR IMPLIED WARRANTY.
// ALL IMPLIED WARRANTIES OF FITNESS FOR ANY PARTICULAR PURPOSE AND OF
// MERCHANTABILITY ARE HEREBY DISCLAIMED.
//				
// For complete openNURBS copyright information see <http://www.opennurbs.org>.
//
////////////////////////////////////////////////////////////////
*/

#include "opennurbs.h"

#if !defined(ON_COMPILING_OPENNURBS)
// This check is included in all opennurbs source .c and .cpp files to insure
// ON_COMPILING_OPENNURBS is defined when opennurbs source is compiled.
// When opennurbs source is being compiled, ON_COMPILING_OPENNURBS is defined 
// and the opennurbs .h files alter what is declared and how it is declared.
#error ON_COMPILING_OPENNURBS must be defined when compiling opennurbs
#endif

// wide char (utf-8 / utf-16 / utf-23) <-> char (utf-8) converter
static int w2c_size( int, const wchar_t* ); // gets minimum "c_count" arg for w2c().
static int w2c( int,            // w_count = number of wide chars to convert
                const wchar_t*, // source wide char string
                int,            // c_count, 
                char*           // array of at least c_count+1 characters
                );
static int c2w( int,           // c_count = number of chars to convert
                const char*,   // source byte char string
                int,           // w_count, 
                wchar_t*       // array of at least c_count+1 wide characters
                );

static int w2c_size( int w_count, const wchar_t* w )
{
  // returns number of bytes used in wide conversion.  Does not
  // include nullptr terminator.
  int rc = 0;
  if ( w ) {
    unsigned int error_status = 0;
    rc = ON_ConvertWideCharToUTF8(false,w,w_count,0,0,&error_status,0,0,0);
    if ( error_status )
    {
      ON_ERROR("wchar_t string is not valid.");
    }
    if ( rc < 0 )
      rc = 0;
  }
  return rc;
}

static int w2c( int w_count, 
                const wchar_t* w, 
                int c_count, 
                char* c // array of at least c_count+1 characters
                )
{
  // convert wide char string to UTF-8 string
  int rc = 0;
  if ( c ) 
    c[0] = 0;
  // returns length of converted c[]
  if ( c_count > 0 && c )
  {
    c[0] = 0;
    if ( w ) 
    {
      unsigned int error_status = 0;
      unsigned int error_mask = 0xFFFFFFFF;
      ON__UINT32 error_code_point = 0xFFFD;
      const wchar_t* p1 = 0;
      rc = ON_ConvertWideCharToUTF8(false,w,w_count,c, c_count, &error_status,error_mask,error_code_point,&p1);
      if ( error_status )
      {
        ON_ERROR("wchar_t string is not valid.");
      }
      if ( rc > 0 && rc <= c_count )
        c[rc] = 0;
      else 
      {
        c[c_count] = 0;
        rc = 0;
      }
    }
  }
	return rc;
}

static int c2w( int c_count, 
                const char* c, 
                int w_count, 
                wchar_t* w // array of at least w_count+1 wide characters
                )
{
  // convert UTF-8 string to UTF-16 string
  int rc = 0;
  if ( w ) 
    w[0] = 0;
  // returns length of converted c[]
  if ( w_count > 0 && w && c_count > 0 && c && c[0] ) {
    w[0] = 0;
    if ( c ) 
    {
      unsigned int error_status = 0;
      unsigned int error_mask = 0xFFFFFFFF;
      ON__UINT32 error_code_point = 0xFFFD;
      const char* p1 = 0;
      rc = ON_ConvertUTF8ToWideChar(false,c,c_count,w,w_count,&error_status,error_mask,error_code_point,&p1);
      if ( rc > 0 && rc <= w_count )
        w[rc] = 0;
      else {
        w[w_count] = 0;
        rc = 0;
      }
      if ( 0 != error_status )
      {
        ON_ERROR("Error converting UTF-8 encoded char string to UTF-16 encoded wchar_t string.");
      }
    }
  }
	return rc;
}


void ON_String::CopyToArray( int w_count, const wchar_t* w )
{
  // if sizeof(wchar_t) is 2, this converts a UTF-16 string to UTF-8 string
  // if sizeof(wchar_t) is 4, this converts a UTF-32 string to UTF-8 string
  int c_count = w2c_size( w_count, w );
  char* c = (char*)onmalloc(c_count+1);
  memset( c, 0, c_count+1 );
  const int c_length = w2c( w_count, w, c_count, c );
  c[c_length] = 0;
  CopyToArray( c_count, c );
  onfree(c);
}



/////////////////////////////////////////////////////////////////////////////
// Empty strings point at empty_wstring

class ON_wStringHeader
{
private:
  ON_wStringHeader() = delete;
public:
  ~ON_wStringHeader() = default;
  ON_wStringHeader(const ON_wStringHeader&) = default;
  ON_wStringHeader& operator=(const ON_wStringHeader&) = default;

public:
  ON_wStringHeader(
    int initial_ref_count,
    int capacity
  )
    : ref_count(initial_ref_count)
    , string_capacity(capacity)
  {}

public:
  // NOTE WELL: 
  //  ref_count must be a signed 32-bit integer type that
  //  supports atomic increment/decrement operations.
  std::atomic<int> ref_count;
	int string_length=0;   // does not include null terminator
	int string_capacity; // does not include null terminator
	wchar_t* string_array() {return (wchar_t*)(this+1);}
};

class ON_Internal_Empty_wString
{
private:
  ON_Internal_Empty_wString(const ON_Internal_Empty_wString&) = delete;
  ON_Internal_Empty_wString& operator=(const ON_Internal_Empty_wString&) = delete;

public: 
  ON_Internal_Empty_wString()
    : header(-1,0)
  {}
  ~ON_Internal_Empty_wString() = default;

public:
  ON_wStringHeader header;
  wchar_t  s = 0;    
};

static ON_Internal_Empty_wString empty_wstring;
static const ON_wStringHeader* pEmptyStringHeader = &empty_wstring.header;
static const wchar_t* pEmptywString = &empty_wstring.s;

static void ON_wStringHeader_DecrementRefCountAndDeleteIfZero(class ON_wStringHeader* hdr)
{
  //// sz must be = 12 or SDK breaks
  //size_t sz = sizeof(*hdr);
  //ON_TextLog::Null.Print((const char*)nullptr, (int)sz);

  if (nullptr == hdr || hdr == pEmptyStringHeader)
    return;

  //const int ref_count = ON_AtomicDecrementInt32(&hdr->ref_count);
  const int ref_count = --hdr->ref_count;
  if (0 == ref_count)
  {
    // zero entire header to help prevent crashes from corrupt string bug
    hdr->string_length = 0;
    hdr->string_capacity = 0;
    onfree(hdr);
  }
}

//////////////////////////////////////////////////////////////////////////////
// protected helpers

void ON_wString::Create()
{
  //// sz must be = sizeof(void*) or SDK breaks
  //size_t sz = sizeof(*this);
  //ON_TextLog::Null.Print((const char*)nullptr, (int)sz);

  m_s = (wchar_t*)pEmptywString;
}

bool ON_wString::IsValid(
  bool bLengthTest
) const
{
  if (m_s == pEmptywString)
    return true;
  for (;;)
  {
    // These checks attempt to detect cases when the memory used for the header informtion
    // no longer contains valid settings.
    const wchar_t* s = m_s;
    if (nullptr == s)
      break;
#if defined(ON_DEBUG) && defined(ON_RUNTIME_WIN) && defined(ON_64BIT_RUNTIME)
    // WINDOWS 64-bit pointer brackets in debug heap
    // https://docs.microsoft.com/en-us/windows-hardware/drivers/gettingstarted/virtual-address-spaces
    if (((ON__UINT_PTR)s) <= 0x10000ull)
      break;
    if (((ON__UINT_PTR)s) > 0x7FFFFFFFFFFull)
      break;
    if (0 != ((ON__UINT_PTR)s) % 4)
      break;
#endif
    const ON_wStringHeader* hdr = Header();
    if (nullptr == hdr)
      break;

#if defined(ON_DEBUG) && defined(ON_RUNTIME_WIN) && defined(ON_64BIT_RUNTIME)
    if (0 != ((ON__UINT_PTR)hdr) % 8)
      break;
#endif

    // If the string is corrupt, there may be a crash on one of the 3 const int xxx = hdr->xxx; lines.
    // But, if we do nothing that crash that was going to happen in the very near future when
    // the code calling this function tries to use the string.
    // If the memory was recently freed or corrupted, there is a non-zero chance
    // these checks will break out of the for(;;){} scope, we will prevent
    // the crash by setting "this" to the empty string.
    const int string_capacity = hdr->string_capacity;
    if (string_capacity <= 0)
      break;
    if (string_capacity > ON_String::MaximumStringLength)
      break;
    const int string_length = hdr->string_length;
    if (string_length < 0)
      break;
    if (string_length > string_capacity)
      break;
    const int ref_count = (int)(hdr->ref_count);
    if (ref_count <= 0)
      break;
    const wchar_t* s1 = s + string_length;
    if (s1 < s)
    {
      // overflow check
      break;
    }
#if defined(ON_DEBUG) && defined(ON_RUNTIME_WIN) && defined(ON_64BIT_RUNTIME)
    // WINDOWS 64-bit pointer brackets in debug heap
    // https://docs.microsoft.com/en-us/windows-hardware/drivers/gettingstarted/virtual-address-spaces
    if (((ON__UINT_PTR)s1) <= 0x10000ull)
      break;
    if (((ON__UINT_PTR)s1) > 0x7FFFFFFFFFFull)
      break;
#endif
    if (bLengthTest)
    {
      // Because the ON_wString m_s[] array can have internal null elements,
      // the length test has to be enabled in situations where it is certain
      // that we are in the common situation where m_s[] is a single null teminated 
      // sting and hdr->string_length is the m_s[] index of the null terminator.
      while (s < s1 && 0 != *s)
        s++;
      if (s != s1)
        break;
      if (0 != *s)
        break;
    }
    return true;
  }
  // prevent imminent and unpredictable crash
  //
  // The empty string is used (as opposed to something like "YIKES - CALL TECH SUPPORT")
  // becuase anything besides the empty string introduces using heap in a class that
  // has been corrupted by some earlier operation.
  const_cast<ON_wString*>(this)->m_s = (wchar_t*)pEmptywString;
  // Devs
  //  If you get this error, some earlier operation corrupted the string
  //  It is critical to track this bug down ASAP.
  ON_ERROR("Corrupt ON_wString - crash prevented.");
  return false;
}

ON_wStringHeader* ON_wString::IncrementedHeader() const
{
  ON_wStringHeader* hdr = (ON_wStringHeader*)m_s;
  if (nullptr == hdr)
    return nullptr;
  
  hdr--;
  if (hdr == pEmptyStringHeader)
    return nullptr;

  //ON_AtomicIncrementInt32(&hdr->ref_count);
  ++hdr->ref_count;
  return hdr;
}

ON_wStringHeader* ON_wString::Header() const
{
  ON_wStringHeader* hdr = (ON_wStringHeader*)m_s;
  if (hdr)
    hdr--;
  else
    hdr = &empty_wstring.header;
  return hdr;
}

wchar_t* ON_wString::CreateArray( int capacity )
{
  Destroy();
  if (capacity > ON_String::MaximumStringLength)
  {
    ON_ERROR("Requested capacity > ON_String::MaximumStringLength");
    return nullptr;
  }
  if ( capacity > 0 ) 
  {
    // This scope does not need atomic operations
		void* buffer = onmalloc( sizeof(ON_wStringHeader) + (capacity+1)*sizeof(*m_s) );
    ON_wStringHeader* hdr = new(buffer) ON_wStringHeader(1,capacity);
		m_s = hdr->string_array();
    memset( m_s, 0, (capacity+1)*sizeof(*m_s) );
    return m_s;
  }
  return nullptr;
}

void ON_wString::Destroy()
{
  ON_wStringHeader* hdr = Header();
  if ( hdr != pEmptyStringHeader && nullptr != hdr && (int)(hdr->ref_count) > 0 )
    ON_wStringHeader_DecrementRefCountAndDeleteIfZero(hdr);
	Create();
}

void ON_wString::Empty()
{
  Destroy();
  Create();  
}

void ON_wString::EmergencyDestroy()
{
	Create();
}

void ON_wString::EnableReferenceCounting( bool bEnable )
{
  // OBSOLETE - DELETE WHEN SDK CAN BE BROKEN
}

bool ON_wString::IsReferenceCounted() const
{
  return true;
}


void ON_wString::CopyArray()
{
  // If 2 or more string are using array, it is duplicated.
  // Call CopyArray() before modifying array contents.
  // hdr0 = original header
  ON_wStringHeader* hdr0 = Header();
  if ( hdr0 != pEmptyStringHeader && nullptr != hdr0 && (int)(hdr0->ref_count) > 1 ) 
  {
    // Calling Create() here insures hdr0 remains valid until we decrement below.
    Create();
    CopyToArray( hdr0->string_capacity, hdr0->string_array() );
    if ( hdr0->string_length < hdr0->string_capacity )
    {
      // Set new header string length;
      Header()->string_length = hdr0->string_length;
    }
    // "this" no longer requires access to the original header
    // If we are in a multi-threaded situation and another thread
    // has decremented ref_count since the > 1 check above,
    // we might end up deleting hdr0.
    ON_wStringHeader_DecrementRefCountAndDeleteIfZero(hdr0);
  }
}

wchar_t* ON_wString::ReserveArray( size_t array_capacity )
{
  if (array_capacity <= 0)
    return nullptr;

  if (array_capacity > (size_t)ON_String::MaximumStringLength)
  {
    ON_ERROR("Requested capacity > ON_String::MaximumStringLength");
    return nullptr;
  }

  const int capacity = (int)array_capacity; // for 64 bit compiler
  ON_wStringHeader* hdr0 = Header();
  if ( hdr0 == pEmptyStringHeader || nullptr == hdr0 ) 
  {
		CreateArray(capacity);
  }
  else if ( (int)(hdr0->ref_count) > 1 ) 
  {
    // Calling Create() here insures hdr0 remains valid until we decrement below.
    Create();

    // Allocate a new array
		CreateArray(capacity);
    ON_wStringHeader* hdr1 = Header();
    const int size = (capacity < hdr0->string_length) ? capacity : hdr0->string_length;
    if ( size > 0 ) 
    {
      memcpy( hdr1->string_array(), hdr0->string_array(), size*sizeof(*m_s) );
      hdr1->string_length = size;
    }
    // "this" no longer requires access to the original header
    // If we are in a multi-threaded situation and another thread
    // has decremented ref_count since the > 1 check above,
    // we might end up deleting hdr0.
    ON_wStringHeader_DecrementRefCountAndDeleteIfZero(hdr0);
  }
	else if ( capacity > hdr0->string_capacity ) 
  {
		hdr0 = (ON_wStringHeader*)onrealloc( hdr0, sizeof(ON_wStringHeader) + (capacity+1)*sizeof(*m_s) );
    m_s = hdr0->string_array();
    memset( &m_s[hdr0->string_capacity], 0, (1 + capacity - hdr0->string_capacity)*sizeof(*m_s) );
    hdr0->string_capacity = capacity;
	}
  return Array();
}

void ON_wString::ShrinkArray()
{
  ON_wStringHeader* hdr0 = Header();
  if (nullptr == hdr0)
  {
    Create();
  }
  else if ( hdr0 != pEmptyStringHeader ) 
  {
    if ( hdr0->string_length < 1 ) 
    {
      Destroy();
      Create();
    }
    else if ( (int)(hdr0->ref_count) > 1 ) 
    {
      // Calling Create() here insures hdr0 remains valid until we decrement below.
      Create();

      // shared string
      CreateArray(hdr0->string_length);
		  ON_wStringHeader* hdr1 = Header();
      memcpy( m_s, hdr0->string_array(), hdr0->string_length*sizeof(*m_s));
      hdr1->string_length = hdr0->string_length;
      m_s[hdr1->string_length] = 0;
      // "this" no longer requires access to the original header
      // If we are in a multi-threaded situation and another thread
      // has decremented ref_count since the > 1 check above,
      // we might end up deleting hdr0.
      ON_wStringHeader_DecrementRefCountAndDeleteIfZero(hdr0);
    }
	  else if ( hdr0->string_length < hdr0->string_capacity )
    {
      // onrealloc string
		  hdr0 = (ON_wStringHeader*)onrealloc( hdr0, sizeof(ON_wStringHeader) + (hdr0->string_length+1)*sizeof(*m_s) );
      hdr0->string_capacity = hdr0->string_length;
      m_s = hdr0->string_array();
      m_s[hdr0->string_length] = 0;
	  }
  }
}

void ON_wString::CopyToArray( const ON_wString& s )
{
  CopyToArray( s.Length(), s.Array() );
}

void ON_wString::CopyToArray( int size, const char* s )
{
  while ( size > 0 && s && s[0] ) 
  {
    if (nullptr == ReserveArray(size))
      break;
    // s = UTF-8 string.
    // m_s = UTF-8, UTF-16, or UTF-32 encoded string.
    // Even with errors, the number of wchar_t elments <= UTF-8 length
    Header()->string_length = c2w( size, s, Header()->string_capacity, m_s );
    m_s[Header()->string_length] = 0;
    return;
  }

  Destroy();
  Create();
}

void ON_wString::CopyToArray( int size, const unsigned char* s )
{
  CopyToArray( size, ((char*)s) );
}

void ON_wString::CopyToArray( int size, const wchar_t* s )
{
  if (size > ON_String::MaximumStringLength)
  {
    ON_ERROR("Requested size > ON_String::MaximumStringLength.");
    size = 0;
  }

  if ( size > 0 && s && s[0] ) 
  {
    ON_wStringHeader* hdr0 = Header();
    // Calling Create() here preserves hdr0 in case s is in its m_s[] buffer.
    Create();

    // ReserveArray() will allocate a new header 
	  ReserveArray(size);
    ON_wStringHeader* hdr1 = Header();
    if (nullptr != hdr1 && hdr1 != pEmptyStringHeader)
    {
      memcpy(m_s, s, size * sizeof(*m_s));
      hdr1->string_length = size;
      m_s[hdr1->string_length] = 0;
    }
    // "this" no longer requires access to the original header
    ON_wStringHeader_DecrementRefCountAndDeleteIfZero(hdr0);
  }
  else
  {
    Destroy();
    Create();
  }
}

void ON_wString::AppendToArray( const ON_wString& s )
{
  AppendToArray( s.Length(), s.Array() );
}

void ON_wString::AppendToArray( int size, const char* s )
{
  if ( size > 0 && s && s[0] ) 
  {
    if (nullptr == ReserveArray(size + Header()->string_length))
      return;
    Header()->string_length += c2w( size, s, Header()->string_capacity-Header()->string_length, &m_s[Header()->string_length] );
    m_s[Header()->string_length] = 0;
  }
}

void ON_wString::AppendToArray( int size, const unsigned char* s )
{
  AppendToArray( size, ((char*)s) );
}

void ON_wString::AppendToArray( int size, const wchar_t* s )
{
  if ( size > 0 && s && s[0] ) 
  {
    if (nullptr == ReserveArray(size + Header()->string_length))
      return;
	  memcpy(&m_s[Header()->string_length], s, size*sizeof(*m_s));
	  Header()->string_length += size;
    m_s[Header()->string_length] = 0;
  }
}


int ON_wString::Length(const wchar_t* s)
{
  return ON_wString::Length(s, 2147483645);
}

int ON_wString::Length(
  const wchar_t* s,
  size_t string_capacity
)
{
  if (nullptr == s)
    return 0;
  if (string_capacity > 2147483645)
    string_capacity = 2147483645;
  size_t slen = 0;
  while (slen < string_capacity && 0 != *s++)
    slen++;
  return ((int)slen);
}

unsigned int ON_wString::UnsignedLength(const wchar_t* s)
{
  return (unsigned int)Length(s);
}


//////////////////////////////////////////////////////////////////////////////
// Construction/Destruction


ON_wString::ON_wString() ON_NOEXCEPT
{
	Create();
}

ON_wString::~ON_wString()
{
  Destroy();
}

ON_wString::ON_wString(const ON_wString& src)
{
  const ON_wStringHeader* p = src.IncrementedHeader();
	if ( nullptr != p )	
  {
		m_s = src.m_s;
	}
	else 
  {
		Create();
	}
}

#if defined(ON_HAS_RVALUEREF)

// Clone constructor
ON_wString::ON_wString( ON_wString&& src ) ON_NOEXCEPT
{
  m_s = src.m_s;
  src.m_s = (wchar_t*)pEmptywString;
}

// Clone Assignment operator
ON_wString& ON_wString::operator=( ON_wString&& src ) ON_NOEXCEPT
{
  if ( this != &src )
  {
    this->Destroy();
    m_s = src.m_s;
    src.m_s = (wchar_t*)pEmptywString;
  }
  return *this;
}

#endif


ON_wString::ON_wString(const ON_String& src)
{
	Create();
	*this = src;
}

ON_wString::ON_wString( const char* s )
{
	Create();
  if ( s && s[0] ) 
  {
    CopyToArray( (int)strlen(s), s ); // the (int) is for 64 bit size_t conversion
  }
}

ON_wString::ON_wString( const char* s, int length )
{
	Create();
  if ( s && length > 0 ) {
    CopyToArray(length,s);
	}
}

ON_wString::ON_wString( char c, int repeat_count )
{
  Create();
  if ( repeat_count > 0 ) {
    char* s = (char*)onmalloc((repeat_count+1)*sizeof(*s));
    s[repeat_count] = 0;
    memset( s, c, repeat_count*sizeof(*s) );
    CopyToArray( repeat_count, s );
    onfree(s);
    m_s[repeat_count] = 0;
    Header()->string_length = repeat_count;
  }
}

ON_wString::ON_wString( const unsigned char* s )
{
	Create();
  if ( s && s[0] ) {
    CopyToArray( (int)strlen((const char*)s), (const char*)s ); // the (int) is for 64 bit size_t conversion
  }
}

ON_wString::ON_wString( const unsigned char* s, int length )
{
	Create();
  if ( s && length > 0 ) {
    CopyToArray(length,s);
	}
}

ON_wString::ON_wString( unsigned char c, int repeat_count )
{
  Create();
  if ( repeat_count > 0 ) {
    char* s = (char*)onmalloc((repeat_count+1)*sizeof(*s));
    s[repeat_count] = 0;
    memset( s, c, repeat_count*sizeof(*s) );
    CopyToArray( repeat_count, s );
    onfree(s);
    m_s[repeat_count] = 0;
    Header()->string_length = repeat_count;
  }
}


ON_wString::ON_wString( const wchar_t* s )
{
	Create();
  if ( s && s[0] ) {
    CopyToArray( (int)wcslen(s), s ); // the (int) is for 64 bit size_t conversion
  }
}

ON_wString::ON_wString( const wchar_t* s, int length )
{
	Create();
  if ( s && length > 0 ) {
    CopyToArray( length, s );
	}
}

ON_wString::ON_wString( wchar_t c, int repeat_count )
{
  Create();
  if (repeat_count > ON_String::MaximumStringLength)
  {
    ON_ERROR("Requested size > ON_String::MaximumStringLength");
    return;
  }
  if ( repeat_count > 0 ) 
  {
    ReserveArray(repeat_count);
    for (int i=0;i<repeat_count;i++)
      m_s[i] = c;
    m_s[repeat_count] = 0;
    Header()->string_length = repeat_count;
  }
}

#if defined(ON_RUNTIME_WIN)
bool ON_wString::LoadResourceString(HINSTANCE instance, UINT id )
{
  bool rc = false;
  wchar_t s[2048]; // room for 2047 characters
  int length;

  Destroy();
  length = ::LoadStringW( instance, id, s, 2047 );
  if ( length > 0 && length < 2048 ) {
    CopyToArray( length, s );
    rc = true;
  }
  return rc;
}
#endif


#if defined(ON_RUNTIME_APPLE_CORE_TEXT_AVAILABLE)
ON_String::ON_String(CFStringRef appleString)
{
  Create();
  for (;;)
  {
    if (nullptr == appleString)
      break;

    const char * utf8_str = CFStringGetCStringPtr(appleString, kCFStringEncodingUTF8);
    ON_SimpleArray<char> local_buffer;
    if (nullptr == utf8_str)
    {
      CFIndex utf16_count = CFStringGetLength(appleString);
      if (utf16_count <= 0)
        break;
      // get local storage
      CFIndex utf8_capacity = 6*utf16_count;
      local_buffer.Reserve((int)(utf8_capacity+1));
      local_buffer.SetCount((int)(utf8_capacity+1));
      local_buffer.Zero();
      Boolean b = CFStringGetCString(appleString, local_buffer.Array(), utf8_capacity, kCFStringEncodingUTF8);
      if (b)
        utf8_str = local_buffer.Array();
      if (nullptr == utf8_str)
        break;
    }
    if ( 0 == utf8_str[0])
      break;
    this->operator=(utf8_str);
    break;
  }
}

ON_wString::ON_wString(CFStringRef appleString)
{
  Create();
  for (;;)
  {
    if (nullptr == appleString)
      break;
    CFIndex utf16_count = CFStringGetLength(appleString);
    if (utf16_count <= 0)
      break;
    const UniChar * utf16_str = CFStringGetCharactersPtr(appleString);
    ON_SimpleArray<UniChar> local_buffer;
    if (nullptr == utf16_str)
    {
      // get local storage
      local_buffer.Reserve((int)(utf16_count + 1));
      local_buffer.SetCount((int)(utf16_count + 1));
      CFRange range;
      range.length = utf16_count;
      range.location = 0;
      CFStringGetCharacters(appleString, range, local_buffer.Array());
      local_buffer[(int)utf16_count] = 0;
      utf16_str = local_buffer.Array();
    }

    ReserveArray(utf16_count);
    if (2 == ON_SIZEOF_WCHAR_T)
    {
      for (CFIndex i = 0;i < utf16_count;i++)
        m_s[i] = (wchar_t)(utf16_str[i]);
      m_s[utf16_count] = 0;
      Header()->string_length = utf16_count;      
    }
    else
    {
      ON__UINT32 code_point;
      int utf32_count = 0;
      for (CFIndex i = 0;i < utf16_count;i++)
      {
        code_point = (ON__UINT32)(utf16_str[i]);
        if (
          0 == ON_IsValidUTF16Singleton(code_point)
          && ( i+1 < utf16_count )
          && ON_IsValidUTF16SurrogatePair(code_point,utf16_str[i + 1])
          )
        {
          code_point = ON_DecodeUTF16SurrogatePair(code_point, utf16_str[i + 1], ON_UnicodeCodePoint::ON_InvalidCodePoint);
          if (ON_UnicodeCodePoint::ON_InvalidCodePoint != code_point)
            i++;
          else
            code_point = (ON__UINT32)(utf16_str[i]);
        }
        m_s[utf32_count++] = (wchar_t)code_point;
      }
      m_s[utf32_count] = 0;
      Header()->string_length = utf32_count;      
    }
    break;
  }
}

CFStringRef ON_wString::ToAppleCFString() const
{
  if ( IsEmpty() || Length() <= 0)
    return nullptr;
  const ON_String utf8_string(*this);
  return utf8_string.ToAppleCFString();
}

CFStringRef ON_String::ToAppleCFString() const
{
  for(;;)
  {
    if ( IsEmpty() || Length() <= 0 )
      break;
    CFAllocatorRef alloc = nullptr;
    const UInt8 *bytes = (UInt8 *)static_cast<const char*>(*this);
    if (nullptr == bytes || 0 == bytes[0])
      break;
    CFIndex numBytes = (CFIndex)Length();
    CFStringEncoding encoding = kCFStringEncodingUTF8;
    Boolean isExternalRepresentation = true;
    CFStringRef appleString = CFStringCreateWithBytes( alloc, bytes, numBytes, encoding, isExternalRepresentation);
    if (nullptr == appleString)
      break;
    return appleString;
  }
  return nullptr;
}
#endif

int ON_wString::Length() const
{
  return Header()->string_length;
}

unsigned int ON_wString::UnsignedLength() const
{
  return (unsigned int)Header()->string_length;
}

wchar_t& ON_wString::operator[](int i)
{
  CopyArray();
  return m_s[i];
}

wchar_t ON_wString::operator[](int i) const
{
  return m_s[i];
}

bool ON_wString::IsEmpty() const
{
  return (Header()->string_length <= 0) ? true : false;
}

bool ON_wString::IsNotEmpty() const
{
  return (Header()->string_length > 0) ? true : false;
}

const ON_wString& ON_wString::operator=(const ON_wString& src)
{
	if (m_s != src.m_s)	
  {
    if ( nullptr != src.IncrementedHeader() )
    {
      Destroy();
      m_s = src.m_s;
    }
    else
    {
      Destroy();
      Create();
    }
  }
	return *this;
}

const ON_wString& ON_wString::operator=(const ON_String& src)
{
  *this = src.Array();
  return *this;
}

const ON_wString& ON_wString::operator=( char c )
{
	CopyToArray( 1, &c );
	return *this;
}

const ON_wString& ON_wString::operator=( const char* s )
{
  if ( (void*)s != (void*)m_s )
	  CopyToArray( ON_String::Length(s), s);
	return *this;
}

const ON_wString& ON_wString::operator=( unsigned char c )
{
	CopyToArray( 1, &c );
	return *this;
}

const ON_wString& ON_wString::operator=( const unsigned char* s )
{
  if ( (void*)s != (void*)m_s )
	  CopyToArray( ON_String::Length((const char*)s), s);
	return *this;
}

const ON_wString& ON_wString::operator=( wchar_t c )
{
	CopyToArray( 1, &c );
	return *this;
}

const ON_wString& ON_wString::operator=( const wchar_t* s )
{
  if ( (void*)s != (void*)m_s )
	  CopyToArray( Length(s), s);
	return *this;
}

ON_wString ON_wString::operator+(const ON_wString& s2) const
{
	ON_wString s(*this);
  s.AppendToArray( s2 );
	return s;
}

ON_wString ON_wString::operator+(const ON_String& s2) const
{
	ON_wString s(*this);
  s.AppendToArray( s2.Length(), s2.Array() );
	return s;
}

ON_wString ON_wString::operator+(char s2 ) const
{
	ON_wString s(*this);
  s.AppendToArray( 1, &s2 );
	return s;
}

ON_wString ON_wString::operator+(unsigned char s2 ) const
{
	ON_wString s(*this);
  s.AppendToArray( 1, &s2 );
	return s;
}

ON_wString ON_wString::operator+( wchar_t s2 ) const
{
	ON_wString s(*this);
  s.AppendToArray( 1, &s2 );
	return s;
}

ON_wString ON_wString::operator+(const char* s2) const
{
	ON_wString s(*this);
  s.AppendToArray( ON_String::Length(s2), s2 );
	return s;
}

ON_wString ON_wString::operator+(const unsigned char* s2) const
{
	ON_wString s(*this);
  s.AppendToArray( ON_String::Length((const char*)s2), s2 );
	return s;
}

ON_wString ON_wString::operator+(const wchar_t* s2) const
{
	ON_wString s(*this);
  s.AppendToArray( ON_wString::Length(s2), s2 );
	return s;
}

//////////////////////////////////////////////////////////////////////////////
// operator+=()

void ON_wString::Append( const char* s , int count )
{
  // append specified number of characters
  if ( s && count > 0 )
    AppendToArray(count,s);
}

void ON_wString::Append( const unsigned char* s , int count )
{
  // append specified number of characters
  if ( s && count > 0 )
    AppendToArray(count,s);
}


void ON_wString::Append( const wchar_t* s, int count )
{
  // append specified number of characters
  if ( s && count > 0 )
    AppendToArray(count,s);
}

const ON_wString& ON_wString::operator+=(const ON_wString& s)
{
  AppendToArray(s);
	return *this;
}

const ON_wString& ON_wString::operator+=(const ON_String& s)
{
  AppendToArray( s.Length(), s.Array() );
	return *this;
}

const ON_wString& ON_wString::operator+=( char s )
{
  AppendToArray(1,&s);
	return *this;
}

const ON_wString& ON_wString::operator+=( unsigned char s )
{
  AppendToArray(1,&s);
	return *this;
}

const ON_wString& ON_wString::operator+=( wchar_t s )
{
  AppendToArray(1,&s);
	return *this;
}

const ON_wString& ON_wString::operator+=( const char* s )
{
  AppendToArray(ON_String::Length(s),s);
	return *this;
}

const ON_wString& ON_wString::operator+=( const unsigned char* s )
{
  AppendToArray(ON_String::Length((const char*)s),s);
	return *this;
}

const ON_wString& ON_wString::operator+=( const wchar_t* s )
{
  AppendToArray(ON_wString::Length(s),s);
	return *this;
}

wchar_t* ON_wString::SetLength(size_t string_length)
{
  if (string_length >= (size_t)ON_String::MaximumStringLength)
  {
    ON_ERROR("Requested size > ON_String::MaximumStringLength");
    return nullptr;
  }
  int length = (int)string_length; // for 64 bit compilers
  if ( length >= Header()->string_capacity )
  {
    ReserveArray(length);
  }
  if ( length >= 0 && length <= Header()->string_capacity ) 
  {
    CopyArray();
    Header()->string_length = length;
    m_s[length] = 0;
    return m_s;
  }
  return nullptr;
}

wchar_t* ON_wString::Array()
{
  CopyArray();
  return ( Header()->string_capacity > 0 ) ? m_s : 0;
}

const wchar_t* ON_wString::Array() const
{
  return ( Header()->string_capacity > 0 ) ? m_s : 0;
}

/*
Returns:
  Total number of bytes of memory used by this class.
  (For use in ON_Object::SizeOf() overrides.
*/
unsigned int ON_wString::SizeOf() const
{
  size_t sz = sizeof(*this);
  if ( ((const void*)m_s) != ((const void*)pEmptywString) )
    sz += (sizeof(ON_wStringHeader) + sizeof(wchar_t)*(Header()->string_capacity+1));
  return ((unsigned int)sz);
}

ON__UINT32 ON_wString::DataCRC(ON__UINT32 current_remainder) const
{
  int string_length = Header()->string_length;
  if ( string_length > 0 )
  {
    current_remainder = ON_CRC32(current_remainder,string_length*sizeof(*m_s),m_s);
  }
  return current_remainder;
}

ON__UINT32 ON_wString::DataCRCLower(ON__UINT32 current_remainder) const
{
  int string_length = Header()->string_length;
  if ( string_length > 0 )
  {
    ON_wString s(*this);
    s.MakeLower();
    current_remainder = s.DataCRC(current_remainder);
  }
  return current_remainder;
}


int ON_wString::Compare( const wchar_t* s ) const
{
  return ON_wString::CompareOrdinal(s,false);
}

int ON_wString::CompareNoCase( const wchar_t* s) const
{
  return ON_wString::CompareOrdinal(s,true);
}

bool ON_WildCardMatch(const wchar_t* s, const wchar_t* pattern)
{
  if ( !pattern || !pattern[0] ) {
    return ( !s || !s[0] ) ? true : false;
  }

  if ( *pattern == '*' ) {
    pattern++;
    while ( *pattern == '*' )
      pattern++;
    
    if ( !pattern[0] )
      return true;

    while (*s) {
      if ( ON_WildCardMatch(s,pattern) )
        return true;
      s++;
    }

    return false;
  }

  while ( *pattern != '*' )
  {
    if ( *pattern == '?' ) {
      if ( *s) {
        pattern++;
        s++;
        continue;
      }
      return false;
    }
    
    if ( *pattern == '\\' ) {
      switch( pattern[1] )
      {
      case '*':
      case '?':
        pattern++;
        break;
      }
    }
    if ( *pattern != *s ) {
      return false;
    }

    if ( *s == 0 )
      return true;

    pattern++;
    s++;
  }
  
  return ON_WildCardMatch(s,pattern);
}


bool ON_WildCardMatchNoCase(const wchar_t* s, const wchar_t* pattern)
{
  if ( !pattern || !pattern[0] ) {
    return ( !s || !s[0] ) ? true : false;
  }

  if ( *pattern == '*' ) 
  {
    pattern++;
    while ( *pattern == '*' )
      pattern++;
    
    if ( !pattern[0] )
      return true;

    while (*s) {
      if ( ON_WildCardMatchNoCase(s,pattern) )
        return true;
      s++;
    }

    return false;
  }

  while ( *pattern != '*' )
  {
    if ( *pattern == '?' )
    {
      if ( *s) {
        pattern++;
        s++;
        continue;
      }
      return false;
    }
    
    if ( *pattern == '\\' )
    {
      switch( pattern[1] )
      {
      case '*':
      case '?':
        pattern++;
        break;
      }
    }
    if ( towupper(*pattern) != towupper(*s) )
    {
      return false;
    }

    if ( *s == 0 )
      return true;

    pattern++;
    s++;
  }
  
  return ON_WildCardMatchNoCase(s,pattern);
}

bool ON_wString::WildCardMatch( const wchar_t* pattern ) const
{
  return ON_WildCardMatch(m_s,pattern);
}


bool ON_wString::WildCardMatchNoCase( const wchar_t* pattern ) const
{
  return ON_WildCardMatchNoCase(m_s,pattern);
}

/*
static TestReplace( ON_TextLog* text_log )
{
  int len, len1, len2, i, count, gap, k, i0, repcount, replen;
  ON_wString str;

  bool bRepeat = false;

  wchar_t ws[1024], wsToken1[1024], wsToken2[1024];

  memset(ws,     0,sizeof(ws));
  memset(wsToken1,0,sizeof(wsToken1));
  memset(wsToken2,0,sizeof(wsToken2));

	for ( len = 1; len < 32; len++ )
  {
    for ( len1 = 1; len1 < len+1; len1++ )
    {
      if ( len1 > 0 )
        wsToken1[0] = '<';
      for ( i = 1; i < len1-1; i++ )
        wsToken1[i] = '-';
      if ( len1 > 1 )
        wsToken1[len1-1] = '>';
      wsToken1[len1] = 0;

      for ( len2 = 1; len2 < len1+5; len2++ )
      {
        if ( len2 > 0 )
          wsToken2[0] = '+';
        for ( i = 1; i < len2-1; i++ )
          wsToken2[i] = '=';
        if ( len2 > 1 )
          wsToken2[len2-1] = '*';
        wsToken2[len2] = 0;

        for ( k = 1; k*len1 <= len+1; k++ )
        {
          gap = (len/k) - len1;
          if (0 == len1 && gap < 1 )
            gap = 1;
          else if ( gap < 0 )
            gap = 0;
          bRepeat = false;
          for ( i0 = 0; i0 < 2*len1 + gap; i0++ )
          {
            for ( i = 0; i < len; i++ )
            {
              ws[i] = (wchar_t)('a' + (i%26));
            }
            ws[len] = 0;
            count = 0;
            for ( i = i0; i+len1 <= len; i += (gap+len1) )
            {
              memcpy(&ws[i],wsToken1,len1*sizeof(ws[0]));
              count++;
            }
            str = ws;
            repcount = str.Replace(wsToken1,wsToken2);
            replen = str.Length();
            if ( repcount != count || replen != len + count*(len2-len1) )
            {
              if ( text_log )
              {
                text_log->Print("%ls -> %ls failed\n",wsToken1,wsToken2);
                text_log->Print("%ls (%d tokens, %d chars)\n",ws,count,len);
                text_log->Print("%ls (%d tokens, %d chars)\n",str.Array(),repcount,replen);
              }
              if ( bRepeat )
              {
                bRepeat = false;
              }
              else
              {
                bRepeat = true;
                i0--;
              }
            }
          }
          bRepeat = false;
        }
      }
    }
  }
}
*/

int ON_wString::Replace( const wchar_t* token1, const wchar_t* token2 )
{
  int count = 0;

  if ( 0 != token1 && 0 != token1[0] )
  {
    if ( 0 == token2 )
      token2 = L"";
    const int len1 = (int)wcslen(token1);
    if ( len1 > 0 )
    {
      const int len2 = (int)wcslen(token2);
      int len = Length();
      if ( len >= len1 )
      {
        // in-place
        ON_SimpleArray<int> n(32);
        const wchar_t* s = m_s;
        int i;
        for ( i = 0; i <= len-len1; /*empty*/ )
        {
          if ( wcsncmp(s,token1,len1) )
          {
            s++;
            i++;
          }
          else
          {
            n.Append(i);
            i += len1;
            s += len1;
          }
        }

        count = n.Count();

        // reserve array space - must be done even when len2 <= len1
        // so that shared arrays are not corrupted.
        const int newlen = len + (count*(len2-len1));
        if ( 0 == newlen )
        {
          Destroy();
          return count;
        }

        CopyArray();

        // 24 August 2006 Dale Lear
        //    This used to say
        //       ReserveArray(newlen);
        //    but when newlen < len and the string had multiple
        //    references, the ReserveArray(newlen) call truncated
        //    the input array.  
        if (nullptr == ReserveArray((newlen < len) ? len : newlen))
          return 0;

        int i0, i1, ni, j;

        if ( len2 > len1 )
        {
          // copy from back to front
          i1 = newlen;
          i0 = len;
          for ( ni =0; ni < count; ni++ )
            n[ni] = n[ni] + len1;
          for ( ni = count-1; ni >= 0; ni-- )
          {
            j = n[ni];
            while ( i0 > j )
            {
              i0--;
              i1--;
              m_s[i1] = m_s[i0];
            }
            i1 -= len2;
            i0 -= len1;
            memcpy(&m_s[i1],token2,len2*sizeof(m_s[0]));
          }
        }
        else
        {
          // copy from front to back
          i0 = i1 = n[0];
          n.Append(len);
          for ( ni = 0; ni < count; ni++ )
          {
            if ( len2 > 0 )
            {
              memcpy(&m_s[i1],token2,len2*sizeof(m_s[0]));
              i1 += len2;
            }
            i0 += len1;
            j = n[ni+1];
            while ( i0 < j )
            {
              m_s[i1++] = m_s[i0++];
            }
          }
        }
        Header()->string_length = newlen;
        m_s[newlen] = 0;
      }
    }
  }

  return count;
}

int ON_wString::Replace( wchar_t token1, wchar_t token2 )
{
  int count = 0;
  int i = Length();
  while (i--)
  {
    if ( token1 == m_s[i] )
    {
      if ( 0 == count )
        CopyArray();
      m_s[i] = token2;
      count++;
    }
  }
  return count;
}


void ON_wString::UrlEncode()
{
  wchar_t c, c0, c1;
  wchar_t* buffer = 0;
  wchar_t* s1 = 0;
  const wchar_t* s = Array();
  const int count = Length();
  int i;

  for ( i = 0; i < count; i++ )
  {
    c = *s++;
    if ( 0 == c )
      break;
    if ('0' <= c && c <= '9')
    {
      if ( s1 )
        *s1++ = c;
      continue;
    }
    if ('a' <= c && c <= 'z')
    {
      if ( s1 )
        *s1++ = c;
      continue;
    }
    if ('A' <= c && c <= 'Z')
    {
      if ( s1 )
        *s1++ = c;
      continue;
    }
    if (c >= 256)
    {
      if ( s1 )
        *s1++ = c;
      continue;
    }

    // convert this character to %xx
    if ( !s1 )
    {
      buffer = (wchar_t*)onmalloc((count*3 + 1)*sizeof(buffer[0]));
      if ( i > 0 )
        memcpy(buffer,Array(),i*sizeof(buffer[0]));
      s1 = buffer+i;
    }
    c0 = ((c/16)%16) + '0';
    if ( c0 > '9' )
      c0 += ('A'-'9'-1);
    c1 = (c%16) + '0';
    if ( c1 > '9' )
      c1 += ('A'-'9'-1);
    *s1++ = '%';
    *s1++ = c0;
    *s1++ = c1;
  }
  if ( s1 )
  {
    *s1 = 0;
    *this = buffer;
    onfree(buffer);
  }
}

static bool UrlDecodeHelper( wchar_t* s)
{
  // if s[0] and s[1] are hex digits, then s[1] is
  // set to the wchar_t with that hex value.
  if ( !s )
    return false;

  wchar_t c0 = *s++;
  if ( c0 >= '0' && c0 <= '9' )
    c0 -= '0';
  else if ( c0 >= 'A' && c0 <= 'F' )
    c0 -= 'A' - 0x0A;
  else if ( c0 >= 'a' && c0 <= 'f' )
    c0 -= 'a' - 0x0A;
  else
    return false;

  wchar_t c1 = *s;
  if ( c1 >= '0' && c1 <= '9' )
    c1 -= '0';
  else if ( c1 >= 'A' && c1 <= 'F' )
    c1 -= 'A' - 0x0A;
  else if ( c1 >= 'a' && c1 <= 'f' )
    c1 -= 'a' - 0x0A;
  else
    return false;

  *s = c0*0x10 + c1;
  return true;
}

static bool IsValidUrlChar(wchar_t c)
{
  if ( c >= '0' && c <= '9' )
    return true;
  if ( c >= 'A' && c <= 'Z' )
    return true;
  if ( c >= 'A' && c <= 'z' )
    return true;

  // ON_wString::UrlEncode() encodes assumes the following
  // characters are literal and encodes them.  However,
  // it is permitted for these characters to appear in
  // a URL.
  switch(c)
  {
  case '$':
  case '-':
  case '_':
  case '.':
  case '+':
  case '!':
  case '*':
  case '\'':
  case '(':
  case ')':
    // RFC 1738 character
    return true;
  case '&':
  case ',':
  case '/':
  case ':':
  case ';':
  case '=':
  case '?':
  case '@':
    // permitted URL syntax character
    return true;
  case '#':
    //  URL bookmark character
    return true;
  }

  return false;
}

bool ON_wString::UrlDecode()
{
  CopyArray();

  bool rc = true;
  wchar_t c;
  wchar_t* s0 = Array();
  if ( !s0 )
    return true;
  wchar_t* s1 = s0;
  //const wchar_t* debg = s1;
  int i;
  for (i = Length(); i > 0; i-- )
  {
    c = *s0++;
    if (0==c)
      break;
    if (i >= 3 && '%' == c && UrlDecodeHelper(s0) )
    {
      s0++;
      *s1++ = *s0++;
      i -= 2;
    }
    else
    {
      *s1++ = c;
      if (rc)
        rc = IsValidUrlChar(c);
    }
  }
  *s1 = 0;
  SetLength(s1 - Array());
  return rc;
}



static bool IsWhiteSpaceHelper( wchar_t c, const wchar_t* whitespace )
{
  while ( *whitespace )
  {
    if ( c == *whitespace++ )
      return true;
  }
  return false;
}

int ON_wString::ReplaceWhiteSpace( wchar_t token, const wchar_t* whitespace )
{
  wchar_t* s0;
  wchar_t* s1;
  int n;
  wchar_t c;

  if ( 0 == (s0 = m_s) )
    return 0;
  s1 = s0 + Length();
  if ( whitespace && *whitespace )
  {
    while( s0 < s1 )
    {
      if (IsWhiteSpaceHelper(*s0++,whitespace))
      {
        // need to modify this string
        n = ((int)(s0 - m_s)); // keep win64 happy with (int) cast
        CopyArray(); // may change m_s if string has multiple refs
        s0 = m_s + n;
        s1 = m_s + Length();
        s0[-1] = token;
        n = 1;
        while ( s0 < s1 )
        {
          if ( IsWhiteSpaceHelper(*s0++,whitespace) )
          {
            s0[-1] = token;
            n++;
          }
        }
        return n;
      }
    }
  }
  else
  {
    while( s0 < s1 )
    {
      c = *s0++;
      if ( (1 <= c && c <= 32) || 127 == c )
      {
        // need to modify this string
        n = ((int)(s0 - m_s)); // keep win64 happy with (int) cast
        CopyArray(); // may change m_s if string has multiple refs
        s0 = m_s + n;
        s1 = m_s + Length();
        s0[-1] = token;
        n = 1;
        while ( s0 < s1 )
        {
          c = *s0++;
          if ( (1 <= c && c <= 32) || 127 == c )
          {
            s0[-1] = token;
            n++;
          }
        }
        return n;
      }
    }
  }
  return 0;
}

int ON_wString::RemoveWhiteSpace( const wchar_t* whitespace )
{
  wchar_t* s0;
  wchar_t* s1;
  wchar_t* s;
  int n;
  wchar_t c;

  if ( 0 == (s0 = m_s) )
    return 0;
  s1 = s0 + Length();
  if ( whitespace && *whitespace )
  {
    while( s0 < s1 )
    {
      if (IsWhiteSpaceHelper(*s0++,whitespace))
      {
        // need to modify this string
        n = ((int)(s0 - m_s)); // keep win64 happy with (int) cast
        CopyArray(); // may change m_s if string has multiple refs
        s0 = m_s + n;
        s = s0-1;
        s1 = m_s + Length();
        while ( s0 < s1 )
        {
          if ( !IsWhiteSpaceHelper(*s0,whitespace) )
          {
            *s++ = *s0;
          }
          s0++;
        }
        *s = 0;
        n = ((int)(s1 - s)); // keep win64 happy with (int) cast
        Header()->string_length -= n;
        return n;
      }
    }
  }
  else
  {
    while( s0 < s1 )
    {
      c = *s0++;
      if ( (1 <= c && c <= 32) || 127 == c )
      {
        // need to modify this string
        n = ((int)(s0 - m_s)); // keep win64 happy with (int) cast
        CopyArray(); // may change m_s if string has multiple refs
        s0 = m_s + n;
        s = s0-1;
        s1 = m_s + Length();
        while ( s0 < s1 )
        {
          c = *s0;
          if ( c < 1 || (c > 32 && 127 != c) )
          {
            *s++ = *s0;
          }
          s0++;
        }
        *s = 0;
        n = ((int)(s1 - s)); // keep win64 happy with (int) cast
        Header()->string_length -= n;
        return n;
      }
    }
  }
  return 0;
}


const ON_wString ON_wString::RemovePrefix(
  const wchar_t* prefix,
  const class ON_Locale& locale,
  bool bIgnoreCase
) const
{
  const wchar_t* str = static_cast<const wchar_t*>(*this);
  const int str_len = Length();
  const int prefix_length = ON_wString::Length(prefix);
  if (
    prefix_length > 0
    && str_len >= prefix_length
    && ON_wString::Equal(
      str,
      prefix_length,
      prefix,
      prefix_length,
      locale,
      bIgnoreCase)
    )
  {
    ON_wString s;
    s.CopyToArray(str_len - prefix_length, str + prefix_length);
    return s;
  }

  return *this;
}

const ON_wString ON_wString::RemoveSuffix(
  const wchar_t* suffix,
  const class ON_Locale& locale,
  bool bIgnoreCase
) const
{
  const wchar_t* str = static_cast<const wchar_t*>(*this);
  const int suffix_length = ON_wString::Length(suffix);
  const int str_len = Length();
  if (
    suffix_length > 0
    && str_len >= suffix_length
    && ON_wString::Equal(
      str + (str_len - suffix_length),
      suffix_length,
      suffix,
      suffix_length,
      locale,
      bIgnoreCase)
    )
  {
    ON_wString s;
    s.CopyToArray( str_len - suffix_length, str );
    return s;
  }

  return *this;
}


///////////////////////////////////////////////////////////////////////////////

ON_wString::operator const wchar_t*() const
{
  return ( nullptr == m_s || m_s == pEmptywString ) ? L"" : m_s;
}

int ON_wString::Find(char utf8_single_byte_c) const
{
  return (utf8_single_byte_c >= 0 && ON_IsValidSingleElementUTF8Value(utf8_single_byte_c))
    ? Find((wchar_t)utf8_single_byte_c, 0)
    : -1;
}

int ON_wString::Find(unsigned char utf8_single_byte_c) const
{
  return (ON_IsValidSingleElementUTF8Value(utf8_single_byte_c))
    ? Find((wchar_t)utf8_single_byte_c, 0)
    : -1;
}

int ON_wString::Find(wchar_t w) const
{
  return Find(w,0);
}

int ON_wString::Find(const char* s) const
{
  return Find(s, 0);
}

int ON_wString::Find(const unsigned char* s) const
{
  return Find(s, 0);
}

int ON_wString::Find(const wchar_t* s) const
{
  return Find(s, 0);
}

int ON_wString::Find(
  char utf8_single_byte_c,
  size_t start_index
  ) const
{
  return (utf8_single_byte_c >= 0 && ON_IsValidSingleElementUTF8Value(utf8_single_byte_c))
    ? Find((wchar_t)utf8_single_byte_c, start_index)
    : -1;
}

int ON_wString::Find(
  unsigned char utf8_single_byte_c,
  size_t start_index
  ) const
{
  return (ON_IsValidSingleElementUTF8Value(utf8_single_byte_c))
    ? Find((wchar_t)utf8_single_byte_c, start_index)
    : -1;
}

int ON_wString::Find(
  wchar_t w,
  size_t start_index
  ) const
{
  if (ON_IsValidSingleElementWideCharValue(w))
  {
    // find first single character
    const wchar_t s[2] = { w, 0 };
    return Find(s, start_index);
  }
  return -1;
}

int ON_wString::Find(
  wchar_t w,
  int start_index
  ) const
{
  return (start_index >= 0) ? Find(w, (size_t)start_index) : -1;
}

int ON_wString::Find(
  const char* sUTF8,
  size_t start_index
  ) const
{
  const ON_wString w(sUTF8);
  return Find( static_cast< const wchar_t* >(w), start_index);
}

int ON_wString::Find(
  const unsigned char* sUTF8,
  size_t start_index
  ) const
{
  return Find((const char*)sUTF8, start_index);
}

int ON_wString::Find(
  const wchar_t* wcharString,
  size_t start_index
  ) const
{
  if ( start_index < 0x7FFFFFFF )
  {
    const int start_index_as_int = (int)start_index;
    const int length = ON_wString::Length(wcharString);
    if (length > 0)
    {
      const int this_length = Length();
      if ( start_index_as_int < this_length && (this_length - start_index_as_int) >= length )
      {
        const wchar_t w0 = wcharString[0];
        const wchar_t* p1 = m_s + (this_length - length);
        for (const wchar_t* p = m_s + start_index_as_int; p <= p1; p++)
        {
          if (w0 == p[0] && ON_wString::EqualOrdinal(p, length, wcharString, length, false) )
            return ((int)(p - m_s));
        }
      }
    }
  }
  return -1;
}

int ON_wString::Find(
  const wchar_t* wcharString,
  int start_index
  ) const
{
  return (start_index < 0) ? -1 : Find(wcharString, (size_t)start_index);
}

int ON_wString::FindOneOf (const wchar_t* character_set) const
{
  if ( nullptr == character_set || 0 == character_set[0] || IsEmpty() )
    return -1;
  
  const wchar_t* s1 = character_set;
  while ( 0 != *s1 )
    s1++;

  ON_UnicodeErrorParameters e = { 0 };
  e.m_error_mask = 2 | 4 | 8;

  const wchar_t* s = character_set;
  wchar_t buffer[10] = { 0 };
  const int buffer_capacity = sizeof(buffer) / sizeof(buffer[0]) - 1;
  ON__UINT32 sUTF32[2] = { 0 };
  while (s < s1)
  {
    e.m_error_status = 0;
    int s_count = ON_DecodeWideChar(s, (int)(s1 - s), &e, &sUTF32[0]);
    if (s_count <= 0 || 0 == sUTF32[0] || 0 != sUTF32[1])
      break;
    e.m_error_status = 0;
    int buffer_count = ON_ConvertUTF32ToWideChar(
      false, 
      sUTF32, 1, 
      buffer, buffer_capacity,
      &e.m_error_status,
      e.m_error_mask,
      e.m_error_code_point,
      nullptr);
    if (0 == e.m_error_status && buffer_count > 0 && buffer_count < buffer_capacity)
    {
      buffer[buffer_count] = 0;
      int rc = Find(buffer);
      if (rc >= 0)
        return rc;
    }
    s += s_count;
  }
  return -1;
}


int ON_wString::ReverseFind(char utf8_single_byte_c) const
{
  return (utf8_single_byte_c >= 0 && ON_IsValidSingleElementUTF8Value(utf8_single_byte_c))
    ? ReverseFind((wchar_t)utf8_single_byte_c)
    : -1;
}

int ON_wString::ReverseFind(unsigned char utf8_single_byte_c) const
{
  return (ON_IsValidSingleElementUTF8Value(utf8_single_byte_c))
    ? ReverseFind((wchar_t)utf8_single_byte_c)
    : -1;
}

int ON_wString::ReverseFind( wchar_t c ) const
{
  if (ON_IsValidSingleElementWideCharValue(c))
  {
    // find first single character
    int i = Length();
    while( i > 0 ) 
    {
      if (c == m_s[--i])
        return i;
    }
  }
  return -1;
}

int ON_wString::ReverseFind(const char* s) const
{
  const ON_wString w(s);
  return ReverseFind(static_cast< const wchar_t* >(w));
}

int ON_wString::ReverseFind(const wchar_t* s) const
{
  const int s_len = ON_wString::Length(s);
  const int this_len = Length();
  if (s_len > 0 && s_len <= this_len )
  {
    const wchar_t* p0 = m_s;
    const wchar_t* p = p0 + (this_len - s_len + 1);
    const wchar_t w0 = s[0];
    while (p > p0)
    {
      p--;
      if ( w0 == p[0] && ON_wString::EqualOrdinal(p,s_len,s,s_len,false) )
        return ((int)(p - p0));
    }
  }
  return -1;
}

void ON_wString::MakeReverse()
{
  if ( IsNotEmpty() ) 
  {
  	CopyArray();
    ON_wString::Reverse(m_s,Length());
  }
}

ON_wString ON_wString::Reverse() const
{
  ON_wString reverse_string(*this);
  reverse_string.MakeReverse();
  return reverse_string;
}

static void ON_String_ReverseUTF16(
  wchar_t* string,
  int element_count
  )
{
  if ( element_count < 2 || nullptr == string )
    return;

  ON_wString buffer(string,element_count);
  const wchar_t* b0 = static_cast<const wchar_t*>(buffer);
  const wchar_t* b1 = b0+element_count;
  wchar_t* s1 = string + (element_count-1);

  while (b0 < b1)
  {
    const wchar_t c = *b0++;
    if ( c >= 0xD800 && c <= 0xDBFF && b0 < b1 && (*b0 >= 0xDC00 && *b0 <= 0xDFFF) )
    {
      // c, b0[0] is a surrogate pair
      *s1-- = *b0++;
    }    
    *s1-- = c;
  }
}

wchar_t* ON_wString::Reverse(
  wchar_t* string,
  int element_count
  )
{
  if (element_count < 0)
  {
    element_count = ON_wString::Length(string);
    if (element_count < 0)
      return nullptr;
  }
  if ( 0 == element_count )
    return string;

  if (nullptr == string)
  {
    ON_ERROR("string is nullptr.");
    return nullptr;
  }

  int i, j;
  wchar_t a, b;

  for (i = 0, j = element_count - 1; i < j; i++, j--)
  {
    a = string[i];
    b = string[j];

    // The surrogate pair value ranges (0xD800, ..., 0xDBFF) and
    // (0xDC00, ..., 0xDFFF) are not unicode code points.
    // If they appear in a UTF-32 encode string, it means the
    // encoding contains errors.  This happens when a UTF-16
    // string is incorrectly converted into a UTF-32 encoded string
    // by an ordinal copy.  For this reason, the surrogate pair
    // test is done unconditionally, including when wchar_t
    // strings are supposed to be UTF-32 encoded.
    if ((a >= 0xD800 && a <= 0xDBFF) || (b >= 0xDC00 && b <= 0xDFFF))
    {
      ON_String_ReverseUTF16(string + i, j - i + 1);
      return string;
    }


    string[i] = b;
    string[j] = a;
  }

  return string;
}

void ON_wString::TrimLeft(const wchar_t* s)
{
  wchar_t c;
  const wchar_t* sc;
  wchar_t* dc;
  int i;
  if ( !IsEmpty() ) {
    if (nullptr == s)
    {
      for (i = 0; 0 != (c = m_s[i]); i++)
      {
        if ( c < 0 || c > ON_wString::Space )
          break;
      }
    }
    else
    {
      for (i = 0; 0 != (c = m_s[i]); i++)
      {
        for (sc = s; *sc; sc++) {
          if (*sc == c)
            break;
        }
        if (!(*sc))
          break;
      }
    }
    if ( i > 0 ) {
      if ( m_s[i] ) {
        CopyArray();
        dc = m_s;
        sc = m_s+i;
        while( 0 != (*dc++ = *sc++) );
        Header()->string_length -= i;
      }
      else
        Destroy();
    }
  }
}

void ON_wString::TrimRight(const wchar_t* s)
{
  wchar_t c;
  const wchar_t* sc;
  int i = Header()->string_length;
  if ( i > 0 ) {
    if (nullptr == s)
    {
      for (i--; i >= 0 && 0 != (c = m_s[i]); i--)
      {
        if ( c < 0 || c > ON_wString::Space )
          break;
      }
    }
    else
    {
      for (i--; i >= 0 && 0 != (c = m_s[i]); i--)
      {
        for (sc = s; *sc; sc++) {
          if (*sc == c)
            break;
        }
        if (!(*sc))
          break;
      }
    }
    if ( i < 0 )
      Destroy();
    else if ( m_s[i+1] ) {
      CopyArray();
      m_s[i+1] = 0;
      Header()->string_length = i+1;
    }
  }
}

void ON_wString::TrimLeftAndRight(const wchar_t* s)
{
  TrimRight(s);
  TrimLeft(s);
}


int ON_wString::Remove(char c)
{
  if (c >= 0 && ON_IsValidSingleElementUTF8Value((ON__UINT32)c))
    return Remove((wchar_t)c);
  return 0;
}

int ON_wString::Remove(unsigned char c)
{
  if (ON_IsValidSingleElementUTF8Value((ON__UINT32)c))
    return Remove((wchar_t)c);
  return 0;
}

int ON_wString::Remove(wchar_t c)
{
  if (ON_IsValidSingleElementWideCharValue(c))
  {
    wchar_t* s0;
    wchar_t* s1;
    wchar_t* s;
    int n;

    if (0 == (s0 = m_s))
      return 0;
    s1 = s0 + Length();
    while (s0 < s1)
    {
      if (c == *s0++)
      {
        // need to modify this string
        n = ((int)(s0 - m_s));
        CopyArray(); // may change m_s if string has multiple refs
        s0 = m_s + n;
        s = s0 - 1;
        s1 = m_s + Length();
        while (s0 < s1)
        {
          if (c != *s0)
          {
            *s++ = *s0;
          }
          s0++;
        }
        *s = 0;
        n = ((int)(s1 - s));
        Header()->string_length -= n;
        return n;
      }
    }
  }
  return 0;
}

wchar_t ON_wString::GetAt(int i) const
{
  return m_s[i];
}


void ON_wString::SetAt( int i, char c )
{
  if ( i >= 0 && i < Header()->string_length ) {
	  CopyArray();
    if (c < 0 || c > 127)
    {
      ON_ERROR("c is not a valid single byte utf-8 value.");
    }
	  m_s[i] = (wchar_t)c;
  }
}

void ON_wString::SetAt( int i, unsigned char c )
{
  SetAt( i, (char)c );
}

void ON_wString::SetAt( int i, wchar_t c )
{
  if ( i >= 0 && i < Header()->string_length ) {
	  CopyArray();
	  m_s[i] = c;
  }
}

ON_wString ON_wString::Mid(int i, int count) const
{
  if ( i >= 0 && i < Length() && count > 0 ) 
  {
    if ( count > Length() - i )
      count = Length() - i;
    if (count > 0)
    {
      ON_wString s;
      s.CopyToArray(count, &m_s[i]);
      return s;
    }
  }
  return ON_wString::EmptyString;
}

ON_wString ON_wString::Mid(int i) const
{
  return Mid( i, Length() - i );
}

const ON_wString ON_wString::SubString(
  int start_index
) const
{
  return Mid( start_index, Length() - start_index );
}

const ON_wString ON_wString::SubString(
  int start_index,
  int count
) const
{
  return Mid(start_index, count);
}

ON_wString ON_wString::Left(int count) const
{
  ON_wString s;
  if ( count > Length() )
    count = Length();
  if ( count > 0 ) {
    s.CopyToArray( count, m_s );
  }
  return s;
}

ON_wString ON_wString::Right(int count) const
{
  ON_wString s;
  if ( count > Length() )
    count = Length();
  if ( count > 0 ) {
    s.CopyToArray( count, &m_s[Length()-count] );
  }
  return s;
}

