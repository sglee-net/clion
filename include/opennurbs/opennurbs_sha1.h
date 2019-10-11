/*
//
// Copyright (c) 1993-2015 Robert McNeel & Associates. All rights reserved.
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

#if !defined(OPENNURBS_SHA1_INC_)
#define OPENNURBS_SHA1_INC_

class ON_CLASS ON_SHA1_Hash
{
public:
  static const ON_SHA1_Hash ZeroDigest;       // all digest bytes are zero
  static const ON_SHA1_Hash EmptyContentHash; // SHA-1 hash of zero bytes

  // The default constructor creates a zero digest sha1 hash
  ON_SHA1_Hash();

  ~ON_SHA1_Hash() = default;
  ON_SHA1_Hash(const ON_SHA1_Hash&) = default;
  ON_SHA1_Hash& operator=(const ON_SHA1_Hash&) = default;

  static int Compare(
    const ON_SHA1_Hash& a,
    const ON_SHA1_Hash& b
    );

  /*
  Parameters:
    buffer - [in]
    sizeof_buffer - [in]
      number of bytes in buffer
  Returns:
    SHA1-1 hash of the buffer.
  */
  static ON_SHA1_Hash BufferContentHash(
    const void* buffer,
    size_t sizeof_buffer
    );

  /*
  Parameters:
    file_name - [in]
      Name of file
    sizeof_file - [out]
      number of bytes in file
  Returns:
    SHA1-1 hash of the buffer.
  */
  static ON_SHA1_Hash FileContentHash(
    const wchar_t* file_name,
    ON__UINT64& sizeof_file
    );

  static ON_SHA1_Hash FileContentHash(
    const char* file_name,
    ON__UINT64& sizeof_file
    );
    
  /*
  Description:
    Return a hash of the file system path that is independent 
    of the size of wchar_t, constant across platforms, and 
    constant across varations in the way the path is formatted.

  Parameters:
    path - [in]
      File system path to a directory or file.

  Returns:
    SHA1-1 hash of the buffer.

  Example:
    These file system paths have identical values of FileSystemPathHash().
    /x/y/z/name.ext
    \x\y\z\name.ext
    /x//y//z/name.ext
    /x/y/a/b/c/../../../z/name.ext
    /X/Y/Z/NAME.EXT (When ON_ComparePathIgnoreCase() is true)

  Remarks:
    This function uses the value of ON_FileSystemPath::PlatformPathIgnoreCase()
    to determine  if case should be ignored. Use the version with a bIgnoreCase
    parameter if you want to explicitly control this decision.
  */
  static ON_SHA1_Hash FileSystemPathHash(
    const wchar_t* path
    );

  static ON_SHA1_Hash FileSystemPathHash(
    const char* path
    );

  static ON_SHA1_Hash FileSystemPathHash(
    const wchar_t* path,
    bool bIgnoreCase
    );

  static ON_SHA1_Hash FileSystemPathHash(
    const char* path,
    bool bIgnoreCase
    );

  /*
  Parameters:
    file - [in]
      File stream from ON_FileStream::Open(...,L"rb");
    sizeof_file - [out]
      number of bytes in file
  Returns:
    SHA1-1 hash of the file stream from the current
    offset to the end of the file.
  */
  static ON_SHA1_Hash FileContentHash(
    FILE* file,
    ON__UINT64& sizeof_file
    );

  /*
  Parameters:
    str - [in]
      string
    byte_count - [out]
      number of bytes in UTF-8 encoding of the string.
  Returns:
    SHA1-1 hash of the UTF-8 encoding of the string. (Platforms and endian independent.)
  */
  static ON_SHA1_Hash StringHash(
    const ON_wString& str,
    ON__UINT64& byte_count
    );

  static ON_SHA1_Hash StringHash(
    const wchar_t* str,
    size_t str_length,
    ON__UINT64& byte_count
    );

  static ON_SHA1_Hash StringHash(
    const wchar_t* null_terminated_string
    );

  /*
  Parameters:
    str - [in]
    byte_count - [out]
      number of bytes in the string.
  Returns:
    SHA1-1 hash of the UTF-8 encoding of the string. (Platforms and endian independent.)
  */
  static ON_SHA1_Hash StringHash(
    const ON_String& str,
    ON__UINT64& byte_count
    );

  static ON_SHA1_Hash StringHash(
    const char* str,
    size_t str_length,
    ON__UINT64& byte_count
    );


  static ON_SHA1_Hash StringHash(
    const char* null_terminated_string
    );

  /*
  Parameters:
    bUpperCaseHexadecimalDigits - [in]
      false - use 0-9, a-f
      true - use 0-9, A-F
  Returns:
    The SHA-1 hash value as a 40 hexadecimal digits.
    The first digit in the string is the hexadecimal value of m_digest[0].
  */
  const ON_String ToUTF8String(
    bool bUpperCaseHexadecimalDigits
    ) const;

  /*
  Parameters:
    bUpperCaseHexadecimalDigits - [in]
      false - use 0-9, a-f
      true - use 0-9, A-F
  Returns:
    The SHA-1 hash value as a 40 hexadecimal digits.
    The first digit in the string is the hexadecimal value of m_digest[0].
  */
  const ON_wString ToString(
    bool bUpperCaseHexadecimalDigits
    ) const;

  bool Read(
    class ON_BinaryArchive& archive
    );

  bool Write(
    class ON_BinaryArchive& archive
    ) const;

  void Dump(
    class ON_TextLog& text_log
    ) const;

  /*
  Returns:
    True if this and ON_SHA1_Hash::ZeroDigest have identical digest values.
  */
  bool IsZeroDigest() const;

  /*
  Returns:
    True if this and ON_SHA1_Hash::EmptyContentHash have identical digest values.
  */
  bool IsEmptyContentHash() const;

  bool IsZeroDigentOrEmptyContentHash() const;

  ON__UINT8 m_digest[20]; 
};



ON_DECL
bool operator==(const ON_SHA1_Hash& a, const ON_SHA1_Hash& b);

ON_DECL
bool operator!=(const ON_SHA1_Hash& a, const ON_SHA1_Hash& b);

/*
Description:
  ON_SHA1 is a small class for calculating the SHA-1 hash of a sequence of bytes.
  It may be use incrementally (the bytes do not have to be in a contiguous
  array in memory at one time).  
  
Remarks:
  The ON_SHA1 class cannot be used for cryptographic or security applications.
  The SHA-1 hash algorithm is not suitable for cryptographic or security applications.
  The ON_SHA1 class does not "wipe" intermediate results.

  If you have two different seqences of N bytes storing information (lower entropy
  than a random sequence) are you are not intentionally calculating the information
  to create a SHA-1 hash collision, then the probability that the sequences have
  the same SHA-1 hash is approximately 2^-80 ~ 10^-24.
*/
class ON_CLASS ON_SHA1
{
public:

	ON_SHA1() = default;
	~ON_SHA1() = default;
  ON_SHA1(const ON_SHA1&) = default;
  ON_SHA1& operator=(const ON_SHA1&) = default;

  /*
  Description:
    Make one or more calls to AccumulateBytes() as the sequenence of bytes is available.

  Parameters:
    buffer - [in]
    sizeof_buffer - [in]
      number of bytes in buffer
  */
#if defined(ON_COMPILER_MSC) && defined(NDEBUG)
  // Reduces release build link time optimization by several hours for
  // large programs that make lots of calls to ON_SHA1.Accumulate*() functions.
  __declspec(noinline)
#endif
  void AccumulateBytes(
    const void* buffer,
    ON__UINT64 sizeof_buffer
    );

  /*
  Description:
    Add the double value to the SHA1 in a manner that
    -0.0 and +0.0 will generate identical SHA-1 values
    and the result is independent of endian byte order.
  */
  void AccumulateDouble(
    double x
    );

  /*
  Description:
    Add the double value to the SHA1 in a manner that
    -0.0 and +0.0 will generate identical SHA-1 values
    and the result is independent of endian byte order.
  */
  void AccumulateDoubleArray(
    size_t count,
    const double* a
    );

  void Accumulate2dPoint(
    const class ON_2dPoint& point
    );

  void Accumulate3dPoint(
    const class ON_3dPoint& point
    );

  void Accumulate4dPoint(
    const class ON_4dPoint& point
    );

  void Accumulate2dVector(
    const class ON_2dVector& vector
    );

  void Accumulate3dVector(
    const class ON_3dVector& vector
    );

  void AccumulateBoundingBox(
    const class ON_BoundingBox& bbox
  );

  void AccumulateUnitSystem(
    const class ON_UnitSystem& unit_system
  );

  void AccumulateLengthUnitSystem(
    const ON::LengthUnitSystem length_unit_system
  );

  /*
  Description:
    Accumuates the full and relative path names.
  */
  void AccumulateFileReference(
    const class ON_FileReference& file_reference
  );

  void AccumulateTransformation(
    const class ON_Xform& xform
  );
  
  void AccumulateInteger8(
    ON__INT8 i
    );
  
  void AccumulateUnsigned8(
    ON__UINT8 u
    );
    
  void AccumulateInteger16(
    ON__INT16 i
    );
  
  void AccumulateUnsigned16(
    ON__UINT16 u
    );

  void AccumulateInteger32(
    ON__INT32 i
    );
  
  void AccumulateUnsigned32(
    ON__UINT32 u
    );

  void AccumulateInteger64(
    ON__INT64 i
    );
  
  void AccumulateUnsigned64(
    ON__UINT64 u
    );


  void AccumulateBool(
    bool b
    );


  void AccumulateString(
    const class ON_String& str
    );

  void AccumulateString(
    const class ON_wString& str
    );

  void AccumulateId(
    const ON_UUID& id
  );

  void AccumulateString(
    const char* sUTF8,
    int element_count,
    ON_StringMapOrdinalType mapping
    );

  void AccumulateString(
    const wchar_t* sUTF8,
    int element_count,
    ON_StringMapOrdinalType mapping
    );

  void AccumulateString(
    const class ON_String& str,
    ON_StringMapOrdinalType mapping
    );

  void AccumulateString(
    const class ON_wString& str,
    ON_StringMapOrdinalType mapping
    );


  void AccumulateSubHash(
    const class ON_SHA1_Hash& sub_hash
    );

private:
  void Internal_SwapBigEndianUpdate(
    const void* buffer,
    ON__UINT64 sizeof_buffer
  );

public:
  /*
  Returns:
    Total number of bytes passed to Update().
  */
  ON__UINT64 ByteCount() const;

  /*
  Returns:
    SHA-1 hash value of the sequenence of ByteCount() bytes that have been
    passed to this ON_SHA1 classe's Update() function since construction
    or the last call to Reset().
  Remarks:
    You may use Hash() to compute intermediate SHA-1 hash values. 
    
    Put another way, you may call Update() zero or more times passing in N1 bytes, 
    call Digest() to get the SHA-1 hash of those N1 bytes, make zero or more additional
    calls to Update() passing in N2 additional bytes, call digest to get the SHA-1 hash
    of the seqence of (N1 + N2) bytes, and so on.
  */
  ON_SHA1_Hash Hash() const;

  /*
  Description:
    Reset this ON_SHA1 class so it can be reused.  
  */
  void Reset();

  /*
  Description:
    This is a static function that uses ON_SHA1 to compute SHA-1 hash values
    of sequences of bytes with known SHA-1 hash values and compares the 
    results from ON_SHA1 with the known SHA-1 hash values.

    This function can be used to validate the ON_SHA1 class compiled correctly.

  Returns:
    true 
      All validation tests passed.
    false 
      At least one validation test failed.
  */
  static bool Validate();

private:
  void Internal_Accumulate(const ON__UINT8* input, ON__UINT32 length);
  void set_final_hash();

  ON__UINT64 m_byte_count = 0; // number of bytes that have passed through calls to update().
  // if 1 == m_status_bits & 1, then update has been called at least once (perhaps with 0 bytes).
  // if 2 == m_status_bits & 2, then m_sha1_hash is current.
  mutable ON__UINT32 m_status_bits = 0;
  ON__UINT32 m_reserved = 0;  

  // current "remainder"
  ON__UINT8 m_buffer[64];      // bytes that didn't fit in last 64 byte chunk
	ON__UINT32 m_bit_count[2];   // number of bits (lo, hi)
	ON__UINT32 m_state[5];       // current state

  // chached SHA1 hash - valid if 2 = (2 & m_status_bits)
	mutable ON_SHA1_Hash m_sha1_hash;
};

#endif
