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

////////////////////////////////////////////////////////////////
//
//   defines ON_Color and ON_Material
//
////////////////////////////////////////////////////////////////

#if !defined(OPENNURBS_TEXTURE_INC_)
#define OPENNURBS_TEXTURE_INC_

///////////////////////////////////////////////////////////////////////////////
//
// Class ON_Texture
// 

class ON_CLASS ON_Texture : public ON_Object
{
  ON_OBJECT_DECLARE(ON_Texture);

public:
  ON_Texture() = default;
  ~ON_Texture() = default;
  ON_Texture(const ON_Texture&) = default;
  ON_Texture& operator=(const ON_Texture&) = default;

public:
  static const ON_Texture Default;

  /*
  Parameters:
    original - [in]
      A brep used as a picture object (1 face with a bitmap texture applied)
    shrunk - [in]
      A copy of original with the face's surface shrunk in some way.
      The domain of the shrunk surface must be contained in the domain
      of the original surface.
    error_return - [in]
      value to return if the input parameters are not valid. If error_return
      is nullptr, then ON_Xform::Nan is returned when input parameters are not valid.

  Returns:
    Texture transformation that will map a [0,1]x[0,1] to the appropriate
    sub rectangle of the picture image.

  Example:
    ON_Brep original_picture = ...;
    ON_Brep shrunk_picture = original_picture;
    shrunk_picture.ShrinkSurfaces();
    ON_Material original_material = ...;
    ON_Material new_material = original_material;
    ON_Texture& new_texture = new_material.m_textures[0];
    new_texture.m_uvw 
     = ON_Texture::GetPictureShrinkSurfaceTransformation(
         &original_picture,
         &shrunk_picture,
         &ON_Xform::IdentityXform)*new_texture.m_uvw;
  */
  static ON_Xform GetPictureShrinkSurfaceTransformation(
    const class ON_Brep* original,
    const class ON_Brep* shrunk,
    const ON_Xform* error_return
  );

  /*
  Parameters:
    original - [in]
      A surface used as a picture object (1 face with a bitmap texture applied)
    shrunk - [in]
      A surface trimmed/split from the original
    error_return - [in]
      value to return if the input parameters are not valid. If error_return
      is nullptr, then ON_Xform::Nan is returned when input parameters are not valid.

  Returns:
    Texture transformation that will map a [0,1]x[0,1] to the appropriate
    sub rectangle of the picture image.

  Example:
    ON_Brep original_picture = ...;
    ON_Brep shrunk_picture = original_picture;
    shrunk_picture.ShrinkSurfaces();
    ON_Material original_material = ...;
    ON_Material new_material = original_material;
    ON_Texture& new_texture = new_material.m_textures[0];
    new_texture.m_uvw 
     = ON_Texture::GetPictureShrinkSurfaceTransformation(
         &original_picture,
         &shrunk_picture,
         &ON_Xform::IdentityXform)*new_texture.m_uvw;
  */
  static ON_Xform GetPictureShrinkSurfaceTransformation(
    const class ON_Surface* original,
    const class ON_Surface* shrunk,
    const ON_Xform* error_return
  );

  /*
  Parameters:
    original_udomain - [in]
    original_vdomain - [in]
      original picture surface domain
    shrunk_udomain - [in]
    shrunk_vdomain - [in]
      sub-domain of the original picture.
    error_return - [in]
      value to return if the input parameters are not valid. If error_return
      is nullptr, then ON_Xform::Nan is returned when input parameters are not valid.

  Returns:
    Texture transformation that will map a [0,1]x[0,1] to the appropriate
    sub rectangle of the picture image.

  Example:
    ON_Brep original_picture = ...;
    ON_Brep shrunk_picture = original_picture;
    shrunk_picture.ShrinkSurfaces();
    ON_Material original_material = ...;
    ON_Material new_material = original_material;
    ON_Texture& new_texture = new_material.m_textures[0];
    new_texture.m_uvw 
     = ON_Texture::GetPictureShrinkSurfaceTransformation(
         &original_picture,
         &shrunk_picture,
         &ON_Xform::IdentityXform)*new_texture.m_uvw;
  */
  static ON_Xform GetPictureShrinkSurfaceTransformation(
    const class ON_Interval& original_udomain,
    const class ON_Interval& original_vdomain,
    const class ON_Interval& shrunk_udomain,
    const class ON_Interval& shrunk_vdomain,
    const ON_Xform* error_return
  );

public:
  /////////////////////////////////////////////////////////////////
  // ON_Object overrides
  bool IsValid( class ON_TextLog* text_log = nullptr ) const override;

  void Dump( ON_TextLog& ) const override;

  unsigned int SizeOf() const override;

  bool Write(
    ON_BinaryArchive& binary_archive
    ) const override;

  bool Read(
    ON_BinaryArchive& binary_archive
    ) override;

  /////////////////////////////////////////////////////////////////
  //

  static int Compare(
    const ON_Texture& a,
    const ON_Texture& b
  );

  static int CompareAppearance(
    const ON_Texture& a,
    const ON_Texture& b
  );

  /*
  Description:
    Reverses the texture in the specified direction.
  Parameters:
    dir - [in] 0 = reverse "u", 1 = reverse "v", 2 = reverse "w".
  Remarks:
    Modifes m_uvw so that the spedified direction transforms
    the texture coordinate t to 1-t.
  Returns:
    True if input is valid.
  */
  bool ReverseTextureCoordinate( int dir );

  /*
  Description:
    Swaps the specified texture coordinates.
  Parameters:
    i - [in]
    j - [in]  (0 <= i, j <= 3 and i != j)
  Remarks:
    Modifes m_uvw so that the specified texture coordinates are swapped.
  Returns:
    True if input is valid.
  */
  bool SwapTextureCoordinate( int i, int j );

  /*
  Description:
    Tiles the specified texture coordinates.
  Parameters:
    dir - [in] 0 = reverse "u", 1 = reverse "v", 2 = reverse "w".
    count - [in] number of tiles (can be negative)
    offset - [in] offset of the tile (can be any number)
  Remarks:
    Modifes m_uvw so that the specified texture coordinate is
    tiled.
  Returns:
    True if input is valid.
  */
  bool TileTextureCoordinate( int dir, double count, double offset );

  /*
  Description:
    Examines the m_uvw matrix and harvests tiling constants.
  Parameters:
    dir - [in] 0 = reverse "u", 1 = reverse "v", 2 = reverse "w".
    count - [out] number of tiles
    offset - [out] offset of the tile
  Returns:
    True if if the m_uvw matrix had entries that were compatible
    with tiling.
  */
  bool IsTiled( int dir, double* count, double* offset ) const;


  ON_UUID m_texture_id = ON_nil_uuid;

  // list of pre-defined channel ids
  enum class MAPPING_CHANNEL : unsigned int
  {
    tc_channel      = 0U,     // Use the texture coordinate values
                             // currently on the geometric object.
    default_channel = 1U,	 // Use either default mappingU, or the "Custom" mapping applied to the object

	  screen_based_channel					= 0xFFFFFFF1U,
	  wcs_channel								= 0xFFFFFFF2U,
	  wcs_box_channel							= 0xFFFFFFF3U,
	  environment_map_box_channel				= 0xFFFFFFF4U,
	  environment_map_light_probe_channel		= 0xFFFFFFF5U,
	  environment_map_spherical_channel		= 0xFFFFFFF6U,
	  environment_map_cube_map_channel		= 0xFFFFFFF7U,
	  environment_map_vcross_cube_map_channel = 0xFFFFFFF8U,
	  environment_map_hcross_cube_map_channel = 0xFFFFFFF9U,
	  environment_map_hemispherical_channel	= 0xFFFFFFFAU,
	  environment_map_emap_channel			= 0xFFFFFFFFU,

    srfp_channel = 0xFFFFFFFEU, // Use surface parameterization.
    emap_channel = 0xFFFFFFFFU  // Environment map the geometric object - deprecated.  Use environment_map_emap_channel instead
  };

  static ON_Texture::MAPPING_CHANNEL BuiltInMappingChannelFromUnsigned(
    unsigned int mapping_channel_as_unsigned
    );
  static bool IsBuiltInMappingChannel(
    unsigned int mapping_channel_id
    );

  const ON_SHA1_Hash ContentHash() const;

  // If the m_mapping_channel_id value is one of the built-in 
  // mappings listed in the MAPPING_CHANNEL enum, then that 
  // mapping is used.  Otherwise, if an object has rendering
  // attributes with an ON_MappingChannel entry that has a 
  // matching m_mapping_channel_id value, then the mapping 
  // identified by ON_MappingChannel::m_mapping_id is used.
  // A value of zero means no mapping is supplied
  // and the texture coordinates on the mesh are
  // used.
  void SetBuiltInMappingChannel(
    ON_Texture::MAPPING_CHANNEL built_in_mapping_channel_as_unsigned
    );
  void SetMappingChannel(
    unsigned int mapping_channel_id
    );
  unsigned int m_mapping_channel_id = 0;

  // Image file
  //   If m_image_file_reference is set and m_image_file_reference.FullPath()
  //   exists, it is the image file being used. This is the common situation
  //   during runtime.
  ON_FileReference m_image_file_reference = ON_FileReference::Unset;

  // If false, texture is off and should be ignored.
  // The intended use is to allow people to turn textures
  // on and off without have to create/destroy or change 
  // other texture settings.
  bool m_bOn = true;

  // do not change TYPE enum values - they are saved in 3dm files.
  // The "TYPE" setting controls how the pixels in the bitmap
  // are interpreted.
  enum class TYPE : unsigned int
  {
    no_texture_type = 0U,

    bitmap_texture       = 1U, // "standard" image texture.
    bump_texture         = 2U, // bump map - see m_bump_scale comment
    transparency_texture = 3U, // value = alpha (see m_tranparancy_id)

    // emap_texture is OBSOLETE - set m_mapping_channel_id = ON_MappingChannel::emap_mapping
    emap_texture = 86U // spherical environment mapping.
  };

  static ON_Texture::TYPE TypeFromUnsigned(
    unsigned int type_as_unsigned
    );

  ON_Texture::TYPE m_type = ON_Texture::TYPE::bitmap_texture;

  // m_mode determines how the texture is
  // do not change MODE enum values - they are saved in 3dm files.
  enum class MODE : unsigned int
  {
    no_texture_mode  = 0,
    modulate_texture = 1,  // modulate with material diffuse color
    decal_texture    = 2,  // decal
    blend_texture    = 3,  // blend texture with others in the material
                           // To "add" a texture, set m_blend_amount = +1
                           // To "subtract" a texture, set m_blend_amount = -1
  };
  
  static ON_Texture::MODE ModeFromUnsigned(
    unsigned int mode_as_unsigned
    );

  ON_Texture::MODE m_mode = ON_Texture::MODE::modulate_texture;

  enum class FILTER : unsigned int
  {
    nearest_filter = 0, // nearest texture pixel is used
    linear_filter  = 1  // weighted average of corresponding texture pixels
  };

  static ON_Texture::FILTER FilterFromUnsigned(
    unsigned int filter_as_unsigned
    );

  // The value of m_minfilter determines how the color
  // of the image pixel is calculated when the image pixel
  // corresponds to multiple texture bitmap pixels.
  ON_Texture::FILTER m_minfilter = ON_Texture::FILTER::linear_filter;  

  // The magfilter setting controls how the color
  // of the image pixel is calculated when the image pixel
  // corresponds to a fraction of a texture bitmap pixel.
  ON_Texture::FILTER m_magfilter = ON_Texture::FILTER::linear_filter;

  enum class WRAP : unsigned int
  {
    repeat_wrap      = 0,
    clamp_wrap       = 1
  };

  static ON_Texture::WRAP WrapFromUnsigned(
    unsigned int wrap_as_unsigned
    );

  WRAP m_wrapu = ON_Texture::WRAP::repeat_wrap;
  WRAP m_wrapv = ON_Texture::WRAP::repeat_wrap;
  WRAP m_wrapw = ON_Texture::WRAP::repeat_wrap;

  // Texture coordinate transformation.
  ON_Xform m_uvw = ON_Xform::IdentityTransformation;

  // If ON_UNSET_COLOR != m_border_color, then this color
  // is used when the texture coordinates are <=0 or >=1
  // and the m_wrap* value is clamp_wrap.
  ON_Color m_border_color = ON_UNSET_COLOR;

  // This field is used for textures with type
  // bitmap_texture that reference bitmap files that do
  // not have an alpha channel and is used to set
  // runtime alpha values.  It needs to be parsed when the
  // texture is loaded and can be ignored at runtime.
  // 
  // If ON_UNSET_COLOR != m_transparent_color, then 
  // a pixel in the bitmap file with a matching RGB
  // value is assigned the alpha value (ON_Color::Alpha)
  // in m_transparent_color. The intended use is 
  // for non-rectangular decals defined by RGB bitmaps in
  // files that don't save an alpha channel.
  //
  // For example if the decal is a red number 7 with a 
  // white background, then you would set m_transparent_color's
  // RGB to white and its A to zero.
  ON_Color m_transparent_color = ON_UNSET_COLOR;

  // This field is used for textures with type
  // bitmap_texture that reference bitmap files that do
  // not have an alpha channel and is used to set
  // runtime alpha values.  It needs to be parsed when the
  // texture is loaded and can be ignored at runtime.
  // 
  // If m_transparency_id is not nil, it is the id of another
  // texture in the ON_Material.m_textures[] array that has
  // type m_transparency_texture.  The runtime bitmap_texture's
  // alpha is set to (255-max(R,G,B)) (the "value" in the hue,
  // saturation,value sense) of the correspondeing 
  // transparency_texture pixel. 
  //
  // For example, if you had a bitmap texuture that was green 
  // with purple dots saved in a RGB .bmp file and you wanted
  // the purple dots to be semi-transparent, you could create
  // another bitmap that was black, where the original was green,
  // and gray, where the original was purple, have an 
  // transparency_texture reference the white/gray bitmap,
  // and have the bitmap_texture's m_transparency_id 
  // reference the transparency map.
  ON_UUID m_transparency_texture_id = ON_nil_uuid;

  // If the m_type is bump_texture, the height of the
  // bump is m_bump_scale.ParameterAt(value), where
  // value is in the HSV sense and normalized 
  // (black=0, white=1).  The interval can be 
  // decreasing.
  ON_Interval m_bump_scale = ON_Interval::ZeroToOne;

  // If the m_mode is blend_texture, then m_blend_A[]
  // and m_blend_RGB[] determine the blending function.
  //
  //  new alpha  = m_blend_constant_A 
  //             + m_blend_A[0]*(current alpha)
  //             + m_blend_A[1]*(texture alpha)
  //             + m_blend_A[2]*min(current alpha,texture alpha)
  //             + m_blend_A[3]*max(current alpha,texture alpha)
  //  new rgb    = m_blend_constant_RGB 
  //             + m_blend_RGB[0]*(current RGB)
  //             + m_blend_RGB[1]*(texture RGB)
  //             + m_blend_RGB[2]*min(current RGB,texture RGB)
  //             + m_blend_RGB[3]*max(current RGB,texture RGB)
  //
  // Results are clamped to handle underflow or overflow.
  
  double m_blend_constant_A = 1.0;
  
  double m_blend_A0 = 1.0;
  double m_blend_A1 = 1.0;
  double m_blend_A2 = 0.0;
  double m_blend_A3 = 0.0;
  
  ON_Color m_blend_constant_RGB = ON_Color::Black;
  
  double m_blend_RGB0 = 1.0;
  double m_blend_RGB1 = 1.0;
  double m_blend_RGB2 = 0.0;
  double m_blend_RGB3 = 0.0;

  // If an ON_Material m_textures[] array has more than
  // one texture, the textures are blended, and the textures
  // have different m_blend_order values, the the texture 
  // with the smaller m_blend_order is first. 
  int m_blend_order = 0;
};

#if defined(ON_DLL_TEMPLATE)
ON_DLL_TEMPLATE template class ON_CLASS ON_ClassArray<ON_Texture>;
ON_DLL_TEMPLATE template class ON_CLASS ON_ObjectArray<ON_Texture>;
#endif

#endif

