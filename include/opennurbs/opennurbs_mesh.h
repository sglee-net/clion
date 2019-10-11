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

#if !defined(OPENNURBS_MESH_INC_)
#define OPENNURBS_MESH_INC_

///////////////////////////////////////////////////////////////////////////////
//
// Class  ON_Mesh
//
class ON_CLASS ON_MeshParameters
{
  // surface meshing perameters
public:

  // The Rhino legacy mesher is the mesher used in Rhino 1, 2, 3, 4, 5, 6.
  // {F15F67AA-4AF9-4B25-A3B8-517CEDDAB134}
  static const ON_UUID RhinoLegacyMesherId;

  // {EB6F6F3F-F975-4546-9D1C-64E9423BEB7F}
  static const ON_UUID PangolinMesherId;

  enum class MESH_STYLE : unsigned char
  {
    // All of these enum values must be in the range 0-255 because
    // unsigned chars are use for storage in some locations.
    unset_mesh_style      =   0,
    render_mesh_fast      =   1, // Use ON_MeshParameters::FastRenderMesh
    render_mesh_quality   =   2, // Use ON_MeshParameters::QualityRenderMesh
    // 3 - 8 reserved for future predefined render mesh styles
    render_mesh_custom    =   9,// Use ON_3dmSettings::m_CustomRenderMeshSettings
    render_mesh_per_object = 10 // Use ON_Object::GetMeshParameters().
  };

  static ON_MeshParameters::MESH_STYLE MeshStyleFromUnsigned(
    unsigned int mesh_style_as_unsigned
  );


  //////////////////////////////////////////////////////////////
  //
  // The MESH_PARAMETER_ID enum values are used to identify
  // mesh creation parameters.
  //
  enum class MESH_PARAMETER_ID : unsigned int
  {
    unspecified_mesh_parameter_id = 0,
    
    ////////////////////////////////////////////////////////
    // BEGIN Legacy parameters.
    //

    bComputeCurvature_parameter_id = 1,
    bSimplePlanes_parameter_id = 2,
    bRefine_parameter_id = 3,
    bJaggedSeams_parameter_id = 4,
    bDoublePrecision_parameter_id = 5,
    mesher_parameter_id = 6,
    texture_range_parameter_id = 7,
    tolerance_parameter_id = 8,
    relative_tolerance_parameter_id = 9,
    min_tolerance_parameter_id = 10,
    min_edge_length_parameter_id = 11,
    max_edge_length_parameter_id = 12,
    grid_aspect_ratio_parameter_id = 13,
    grid_min_count_parameter_id = 14,
    grid_max_count_parameter_id = 15,
    grid_angle_parameter_id = 16,
    grid_amplification_parameter_id = 17,
    refine_angle_parameter_id = 18,
    face_type_parameter_id = 19,
    srf_domain_parameter_id = 20,
    bClosedObjectPostProcess_id = 21,

    //
    // END Legacy parameters.
    ////////////////////////////////////////////////////////

    // UUID parameter identifying what mesher code created the mesh.
    mesher_id = 22,

    ////////////////////////////////////////////////////////
    // BEGIN Pangolin parameters
    //

    crv_tess_min_num_segments_parameter_id = 23,
    crv_tess_angle_tol_in_degrees_parameter_id = 24,
    crv_tess_max_dist_between_points_parameter_id = 25, // Not same as 'max_edge_length_parameter_id' since
                                                        // 'curve_tess_max_dist_between_points' is only for
                                                        // curves, not surfaces.
    crv_tess_min_parametric_ratio_parameter_id = 26,
    bEvaluatorBasedTessellation_parameter_id = 27,
    srf_tess_chord_height_parameter_id = 28, // Not same as 'tolerance_parameter_id' since
                                             // 'surface_tess_chord_height' is only for
                                             // surfaces, not curves.
    srf_tess_angle_tol_in_degrees_parameter_id = 29,
    srf_tess_max_edge_length_parameter_id = 30,
    srf_tess_min_edge_length_parameter_id = 31,
    srf_tess_min_edge_length_ratio_uv_parameter_id = 32,
    srf_tess_max_aspect_ratio_parameter_id = 33,
    smoothing_passes_parameter_id = 34,

    //
    // END Pangolin parameters
    ////////////////////////////////////////////////////////

    max_mesh_parameter_id
  };

  static ON_MeshParameters::MESH_PARAMETER_ID MeshParameterIdFromUnsigned(
    unsigned int mesh_parameter_id_as_unsigned
  );

  /*
  Description:
    Mesh creationg parameters to create the default render mesh.
  */
  static 
  const ON_MeshParameters DefaultMesh;

  /*
  Description:
    Mesh creationg parameters to create the a render mesh
    when meshing speed is prefered over mesh quality.
  */
  static 
  const ON_MeshParameters FastRenderMesh;

  /*
  Description:
    Mesh creationg parameters to create the a render mesh
    when mesh quality is prefered over meshing speed.
  */
  static 
  const ON_MeshParameters QualityRenderMesh;

  /*
  Description:
    Mesh creationg parameters to create the default analysis mesh.
  */
  static 
  const ON_MeshParameters DefaultAnalysisMesh;

  /*
  Description:
    Get a value to use for tolerance based on the relative_tolerance
    and actual size.
  Parameters:
    relative_tolerance - [in] 
      See m_relative_tolerance field
    actual_size - [in]
      Length of object's bounding box diagonal or some similar 
      measure of the object's 3d size.
  Returns:
    A value that can be used for m_tolerance if no
    user specified value is available.
  */
  static
  double ToleranceFromObjectSize( double relative_tolerance, double actual_size );

  /*
  Description:
    Get a value to use for minimum edge length base on max_edge_length
    and tolerance settings.
  Parameters:
    max_edge_length - [in] 
      3d maximum edge length used to create mesh.
    tolerance - [in]
      3d distance tolerance used to create mesh.
  Returns:
    A value that can be used for m_min_edge_length if no
    user specified value is available.
  */
  static
  double MinimumEdgeLengthFromTolerance( double max_edge_length, double tolerance );

  ON_MeshParameters() = default;
  ~ON_MeshParameters() = default;
  ON_MeshParameters(const ON_MeshParameters&) = default;
  ON_MeshParameters& operator=(const ON_MeshParameters&) = default;

  /*
  Description:
    Tool for provding a simple slider interface.
  Parameters:
    density - [in] 0.0 <= density <= 1.0
      0 quickly creates coarse meshes.
      1 slowly creates dense meshes.
    min_edge_length - [in]
      > 0.0 custom value
      ON_UNSET_VALUE: for default (0.0001)
  */
  ON_MeshParameters(
    double density,
    double min_edge_length = ON_UNSET_VALUE
    );

  // C++ default works fine // ON_MeshParameters(const ON_MeshParameters& );
  // C++ default works fine // ON_MeshParameters& operator=(const ON_MeshParameters&);
 
  void Dump( ON_TextLog& test_log ) const;


  /*
  */
  static int Compare( 
    const ON_MeshParameters& a,
    const ON_MeshParameters& b
    );

  /*
  Description:
    Compares all meshing parameters that control mesh geometry.
    Does not compare m_bCustomSettings, CustomSettingsEnabled(),
    m_bComputeCurvature,  m_bDoublePrecision, MinimumTolerance(),
    m_texture_range, m_srf_domain0 and m_srf_domain1.
  */
  static int CompareGeometrySettings(
    const ON_MeshParameters& a,
    const ON_MeshParameters& b
    );

  ON_SHA1_Hash ContentHash() const;
  ON_SHA1_Hash GeometrySettingsHash() const;

  ON_UUID MesherId() const;
  void SetMesherId(
    ON_UUID
  );


  /*
  Returns:
    ON_MeshParameters::render_mesh_fast
      ON_MeshParameters::FastRenderMesh and this have the same geometry settings
    ON_MeshParameters::render_mesh_quality
      ON_MeshParameters::QualityRenderMesh and this have the same geometry settings
    ON_MeshParameters::render_mesh_custom
      custom_mp is not null and has the same geometry settings
    no_match_found_result
      otherwise
  */
  const ON_MeshParameters::MESH_STYLE GeometrySettingsRenderMeshStyle(
    const ON_MeshParameters* custom_mp,
    ON_MeshParameters::MESH_STYLE no_match_found_result
    ) const;

  /*
  Returns:
    n in the range 0 to 100, inclusive, when 
      (0 == ON_MeshParameters::CompareGeometrySettings(*this,ON_MeshParameters(n/100.0))
    no_match_found_result:
      otherwise
  */
  const int GeometrySettingsDensityPercentage(
    int no_match_found_result
    ) const;

  bool Write( ON_BinaryArchive& ) const;
  bool Read( ON_BinaryArchive& );

  ON__UINT32 DataCRC(ON__UINT32) const;
    
  //////////////////////////////////////////////////////////////
  //
  // The CustomSettings() parameter applies when these mesh 
  // creation parameters specify how an object's mesh should
  // be created and these parameters should override the
  // the model or application default mesh creation parameters.
  //
  // When CustomSettings() is true, it indicates these mesh 
  // creation parameters are explictily set for the object
  // and context in question and should override the model
  // or application defaults.
  //
  // When CustomSettings() is false, it indicates these mesh
  // creation parameters were inherited from from model or 
  // application defaults and any mesh created with these
  // parameters should be updated when these parameters
  // differ from the current model or application defaults.
  //
  const bool CustomSettings() const;
  void SetCustomSettings(
    bool bCustomSettings
  );

  //////////////////////////////////////////////////////////////
  //
  // The CustomSettingsEnabled() value applies to mesh creation
  // parameters that are on ON_3dmObjectAttributes and have
  // CustomSettings() = true.  In this situation:
  //
  //   If CustomSettingsEnabled() is true, then the use of 
  //   these mesh creation parameters is enabled.
  //
  //   If CustomSettingsEnabled() is false, then these mesh
  //   creation parameters should be gnored.
  //
  const bool CustomSettingsEnabled() const;
  void SetCustomSettingsEnabled(
    bool bCustomSettingsEnabled
  );


  //////////////////////////////////////////////////////////////
  //
  // Meshing happens in two stages.  The first stage creates a
  // rectangular grid.  The second stage refines the grid until
  // the mesh meets all meshing requirements.  The third stage
  // combines coincident vertices if the resulting mesh is a composite.
  // 


  // false - (default) - ON_Mesh::m_K[] not computed
  // true  - ON_Mesh::m_K[] computed  bool ComputeCurvature() const;
  const bool ComputeCurvature() const;
  void SetComputeCurvature(
    bool bComputeCurvature
  );

  // false - (default) planar surfaces are meshed
  //          using the controls below.
  // true   - planar surfaces are meshed using
  //          minimal number of triangles and
  //          aspect/edge controls are ignored.
  const bool SimplePlanes() const;
  void SetSimplePlanes(
    bool bSimplePlanes
  );

public:
  // false - skip stage 2 mesh refinement step
  // true  - (default) do stage 2 mesh refinement step
  const bool Refine() const;
  void SetRefine(
    bool bRefine
  );

public:
  // false - (default) edges of meshes of joined 
  //          b-rep faces match with no gaps or
  //          "T" joints.
  // true   - faces in b-reps are meshed independently.
  //          This is faster but results in gaps and
  //          "T" joints along seams between faces.
  const bool JaggedSeams() const;
  void SetJaggedSeams(
    bool bJaggedSeams
  );

public:
  // false - (default) the mesh vertices will be 
  //         float precision values in the m_V[] array.
  // true -  The mesh vertices will be double precision
  //         values in the DoublePrecisionVertices()
  //         array.  Float precision values will also
  //         be returned in the m_V[] array.
  const bool DoublePrecision() const;
  void SetDoublePrecision(
    bool bDoublePrecision
  );

  // 0 = slow mesher, 1 = fast mesher
  const unsigned int Mesher() const;
  void SetMesher(
    unsigned int mesher
  );
    
  // 1: unpacked, unscaled, normalized
  //   each face has a normalized texture range [0,1]x[0,1].
  //   The normalized coordinate is calculated using the
  //   entire surface domain.  For meshes of trimmed
  //   surfaces when the active area is a small subset of
  //   the entire surface, there will be large regions of
  //   unsued texture space in [0,1]x[0,1].  When the 3d region
  //   being meshed is far from being sqaure-ish, there will be
  //   a substantual amount of distortion mapping [0,1]x[0,1]
  //   texture space to the 3d mesh.
  //   
  // 2: packed, scaled, normalized (default)
  //   each face is assigned a texture range that is a 
  //   subrectangle of [0,1]x[0,1].  The subrectangles are 
  //   mutually disjoint and packed into into [0,1]x[0,1]
  //   in a way that minimizes distortion and maximizes the
  //   coverage of [0,1]x[0,1].
  //   When the surface or surfaces being meshed are trimmed,
  //   this option takes into account only the region of the
  //   base surface the mesh covers and uses as much of 
  //   [0,1]x[0,1] as possible.  unsigned int TextureRange() const;
  const unsigned int TextureRange() const;
  void SetTextureRange(
    unsigned int texture_range
  );
  const bool TextureRangeIsValid() const;
  void SetTextureRangePictureFrameHack();

  // If the object being meshed is closed, m_bClosedObjectPostProcess is true, 
  // m_bJaggedSeams = false, and the resultig mesh is not closed, then a post meshing process
  // is applied to find and close gaps in the mesh. Typically the resulting mesh
  // is not closed because the input object has a geometric flaw like loops in
  // trimming curves.
  const bool ClosedObjectPostProcess() const;
  void SetClosedObjectPostProcess(
    bool bClosedObjectPostProcess
  );

  // These controls are used in both stages

  // approximate maximum distance from center of edge to surface
  const double Tolerance() const;
  void SetTolerance(
    double tolerance
  );

  /*
    If 0.0 < RelativeTolerance() < 1.0, 
    then the maximum distance from the
    center of an edge to the surface will
    be <= T, where T is the larger of
    (MinimumTolerance(),d*RelativeTolerance()), 
    where d is an esimate of the size of the
    object being meshed.
  */
  const double RelativeTolerance() const;
  void SetRelativeTolerance(
    double relative_tolerance
  );

  const double MinimumTolerance() const;
  void SetMinimumTolerance(
    double minimum_tolerance
  );

  // edges shorter than MinimumEdgeLength() will
  // not be split even if the do not meet other
  // meshing requirements
  const double MinimumEdgeLength() const;
  void SetMinimumEdgeLength(
    double minimum_edge_length
  );

  /*
  Returns:
    SubD display mesh density.
  Example:
    Use ON_MeshParameters to control the density of a SubD limit mesh.
    ON_MeshParameters mp = ...;
    ON_Mesh* mesh = subd->GetLimitSurfaceMesh(
      ON_SubDDisplayParameters::CreateFromDisplayDensity( mp.SubDDisplayMeshDensity() ),
      nullptr
      );
  */
  unsigned int SubDDisplayMeshDensity() const;

public:
  // edges longer than MaximumEdgeLength() will
  // be split even when they meet all other
  // meshing requirements
  const double MaximumEdgeLength() const;
  void SetMaximumEdgeLength(
    double maximum_edge_length
  );

  ////////////////////////////////////////////////////////////////////////////////////
  //
  // These controls are used during stage 1 to generate the grid
  //


  // desired aspect ratio of quads in grid
  // 0.0 = any aspect ratio is acceptable
  // values >0 and < sqrt(2) are treated as sqrt(2)
  const double GridAspectRatio() const;
  void SetGridAspectRatio(
    double grid_aspect_ratio
  );

  // minimum number of quads in initial grid
  const int GridMinCount() const;
  void SetGridMinCount(
    int grid_min_count
  );

  // desired masimum number of quads in initial grid
  const int GridMaxCount() const;
  void SetGridMaxCount(
    int grid_max_count
  );

  // maximum angle (radians) between surface
  // normal evaluated at adjacent vertices.
  // 0.0 is treated as pi.
  const double GridAngleRadians() const;
  void SetGridAngleRadians(
    double grid_angle_radians
  );

  // maximum angle (degrees) between surface
  // normal evaluated at adjacent vertices.
  // 0.0 is treated as 180.0.
  const double GridAngleDegrees() const;
  void SetGridAngleDegrees(
    double grid_angle_degrees
  );

  // The parameters above generate a grid.
  // If you want fewer quads, set m_grid_amplification
  // to a value < 1.  If you want more quads,
  // set m_grid_amplification to a value > 1.
  // default = 1 and values <= 0 are treated as 1.
  const double GridAmplification() const;
  void SetGridAmplification(
    double grid_amplification
  );

  ////////////////////////////////////////////////////////////////////////////
  //
  // These controls are used during stage 2 to refine the grid
  //


  // (in radians) maximum angle in radians between
  // surface normal evaluated at adjacent vertices.
  const double RefineAngleRadians() const;
  void SetRefineAngleRadians(
    double refine_angle_radians
  );
  const double RefineAngleDegrees() const;
  void SetRefineAngleDegrees(
    double refine_angle_degrees
  );

  ////////////////////////////////////////////////////////////////////////////
  //
  // These controls are used during stage 3
  //

  // 0 = mixed triangle and quads
  // 1 = all triangles
  // 2 = all quads
  const unsigned int FaceType() const;
  void SetFaceType(
    unsigned int face_type
  );


private:
  void Internal_SetBoolHelper(bool b, bool* dest);
  void Internal_SetCharHelper(unsigned int u, unsigned char minc, unsigned char maxc, unsigned char*);
  void Internal_SetDoubleHelper(double x, double minx, double maxx, double* dest);
  void Internal_SetIntHelper(int i, int mini, int maxi, int* dest);

private:
  //////////////////////////////////////////////////////////
  //
  // BEGIN Rhino Legacy parameters
  //
  bool m_bCustomSettings = false;
  bool m_bCustomSettingsEnabled = true;
  bool m_bComputeCurvature = false;
  bool m_bSimplePlanes = false; 
  
  bool m_bRefine = true;
  bool m_bJaggedSeams = false;
  bool m_bDoublePrecision = false;
  bool m_bClosedObjectPostProcess = false;

  ON_UUID m_mesher_id = ON_nil_uuid;
  
  unsigned char m_mesher = 0;
  unsigned char m_texture_range = 2;
  unsigned char m_face_type = 0;

  unsigned char m_reserved1 = 0;

  int m_grid_min_count = 0;
  int m_grid_max_count = 0;     
  mutable ON_SHA1_Hash m_geometry_settings_hash = ON_SHA1_Hash::ZeroDigest;

  ON__UINT32 m_reserved2 = 0;

  double m_tolerance = 0.0;
  double m_relative_tolerance = 0.0;
  double m_min_tolerance = 0.0;
  double m_min_edge_length = 0.0001;
  double m_max_edge_length = 0.0;
  double m_grid_aspect_ratio = 6.0;
  double m_grid_angle_radians = 20.0*ON_PI/180.0;
  double m_grid_amplification = 1.0;
  double m_refine_angle_radians = 20.0*ON_PI/180.0;
  //
  // BEGIN Rhino Legacy parameters
  //
  //////////////////////////////////////////////////////////

private:
  bool m_reserved3 = false;
  bool m_reserved4 = false;

private:
  //////////////////////////////////////////////////////////
  //
  // BEGIN Pangolin parameters
  //

  bool m_bEvaluatorBasedTessellation = false;
  int m_curve_tess_min_num_segments = 0;
  double m_curve_tess_angle_tol_in_degrees = 20.0;
  double m_curve_tess_max_dist_between_points = 0.0;
  double m_curve_tess_min_parametric_ratio = 0.00001;
  double m_surface_tess_angle_tol_in_degrees = 20.0;
  double m_surface_tess_max_edge_length = 0.0;
  double m_surface_tess_min_edge_length = 0.0;
  double m_surface_tess_min_edge_length_ratio_uv = 0.0001;
  double m_surface_tess_max_aspect_ratio = 0.0;
  int m_smoothing_passes = 0;

private:
  void Internal_AccumulatePangolinParameters(
    const ON_MeshParameters& pangolin_defaults,
    class ON_SHA1& sha1
  ) const;

  //
  // END Pangolin parameters
  //
  //////////////////////////////////////////////////////////

private:
  ON__UINT_PTR m_reserved5 = 0;
};

ON_DECL
bool operator!=(const ON_MeshParameters& a, const ON_MeshParameters& b);

ON_DECL
bool operator==(const ON_MeshParameters& a, const ON_MeshParameters& b);

class ON_CLASS ON_MeshCurvatureStats
{
public:
  ON_MeshCurvatureStats();
  ~ON_MeshCurvatureStats();
  ON_MeshCurvatureStats(const ON_MeshCurvatureStats& );
  ON_MeshCurvatureStats& operator=(const ON_MeshCurvatureStats&);

  void Destroy();
  void EmergencyDestroy();
  
  bool Set( ON::curvature_style,
            int,           // Kcount,
            const ON_SurfaceCurvature*, // K[]
            const ON_3fVector*, // N[] surface normals needed for normal sectional curvatures
            double = 0.0   // if > 0, value is used for "infinity"
            );

  bool Write( ON_BinaryArchive& ) const;
  bool Read( ON_BinaryArchive& );

  ON::curvature_style m_style;
  
  double m_infinity; // curvature values >= this are considered infinite
                     // and not used to compute the m_average or m_adev
  int    m_count_infinite; // number of "infinte" values
  int    m_count;    // count of "finite" values
  double m_mode;     // mode of "finite" values
  double m_average;  // average of "finite" values
  double m_adev;     // average deviation of "finite" values

  ON_Interval m_range;
};

///////////////////////////////////////////////////////////////////////////////
//
// Class  ON_MeshTopology
//

struct ON_MeshTopologyVertex
{
  // m_tope_count = number of topological edges that begin or 
  // end at this topological vertex.
  int m_tope_count;

  // m_topei[] is an array of length m_tope_count with the indices 
  // of the topological edges that begin or end at this topological
  // vertex.  Generally, these edges are listed in no particular
  // order.  If you want the edges listed "radially", then call
  // ON_MeshTopology::SortVertexEdges.
  const int* m_topei;

  // m_v_count = number of ON_Mesh vertices that correspond to 
  // this topological vertex.
  int m_v_count;

  // m_vi[] is an array of length m_v_count with the indices of the
  // ON_Mesh vertices that correspond to this topological vertex.
  const int* m_vi;
};

struct ON_MeshTopologyEdge
{
  // m_topvi[] = indices of the topological verteices where the 
  // edge begins and ends.
  int m_topvi[2];

  // m_topf_count = number of topological faces tat share this topological edge
  int m_topf_count;

  // m_topfi[] is an array of length m_topf_count with the indices of the
  // topological faces that share this topological edge.
  const int* m_topfi;
};

struct ON_CLASS ON_MeshTopologyFace
{
  /*
    m_topei[] = indices of the topological edges that bound the face.
    If m_topei[2] = m_topei[3], then the face is a triangle, otherwise
    the face is a quad.
 
    NOTE WELL:
      The topological edge with index m_topei[k] ENDS at the
      vertex corresponding to ON_MeshFace.vi[k]. So, ...

      If the face is a quad, (ON_MeshFace.vi[2]!=ON_MeshFace.vi[3]),
      the topological edge with index m_topei[0] STARTS at
      ON_MeshFace.vi[3] and ENDS at ON_MeshFace.vi[0],
      the topological edge with index m_topei[1] STARTS at
      ON_MeshFace.vi[0] and ENDS at ON_MeshFace.vi[1],
      the topological edge with index m_topei[2] STARTS at
      ON_MeshFace.vi[1] and ENDS at ON_MeshFace.vi[2], and
      the topological edge with index m_topei[3] STARTS at
      ON_MeshFace.vi[2] and ENDS at ON_MeshFace.vi[3],
      
      If the face is a triangle, (ON_MeshFace.vi[2]==ON_MeshFace.vi[3]),
      the topological edge with index m_topei[0] STARTS at
      ON_MeshFace.vi[2] and ENDS at ON_MeshFace.vi[0],
      the topological edge with index m_topei[1] STARTS at
      ON_MeshFace.vi[0] and ENDS at ON_MeshFace.vi[1],
      the topological edge with index m_topei[2] STARTS at
      ON_MeshFace.vi[1] and ENDS at ON_MeshFace.vi[2].
  */
  int m_topei[4];

  /*
    If m_reve[i] is 0, then the orientation of the edge matches the
    orientation of the face.  If m_reve[i] is 1, then the orientation
    of the edge is opposite that of the face.
  */
  char m_reve[4];

  /*
  Description:
    A topological mesh face is a valid triangle if m_topei[0], 
    m_topei[1], m_topei[2] are distinct edges and 
    m_topei[3]=m_topei[2].
  Returns:
    True if face is a triangle.
  */
  bool IsTriangle() const;

  /*
  Description:
    A topological mesh face is a valid quad if m_topei[0], 
    m_topei[1], m_topei[2], and m_topei[3] are distinct edges.
  Returns:
    True if face is a quad.
  */
  bool IsQuad() const;

  /*
  Description:
    A topological mesh face is valid if m_topei[0], m_topei[1], 
    and m_topei[2] are mutually distinct, and m_topei[3] is 
    either equal to m_topei[2] or mutually distinct from the
    first three indices.
  Returns:
    True if face is valid.
  */
  bool IsValid( ) const;
};

class ON_CLASS ON_MeshFace
{
public:
  static const ON_MeshFace UnsetMeshFace; // all vi[] values are -1.


  int vi[4]; // vertex index - vi[2]==vi[3] for tirangles

  /*
  Returns:
    True if vi[2] == vi[3];
  Remarks:
    Assumes the face is valid.
  */
  bool IsTriangle() const;

  /*
  Returns:
    True if vi[2] != vi[3];
  Remarks:
    Assumes the face is valid.
  */
  bool IsQuad() const;

  /*
  Description:
    Determine if a face is valid by checking that the vertices
    are distinct.
  Parameters:
    mesh_vertex_count - [in]
      number of vertices in the mesh
    V - [in]
      optional array of mesh_vertex_count vertex locations.
  Returns:
    true
      The face is valid.
    false
      The face is not valid. It may be possible to repair the
      face by calling ON_MeshFace::Repair().
  */
  bool IsValid(
    int mesh_vertex_count
    ) const;
  bool IsValid(
    unsigned int mesh_vertex_count
    ) const;
  bool IsValid(
        int mesh_vertex_count,
        const ON_3fPoint* V
        ) const;
  bool IsValid(
        int mesh_vertex_count,
        const ON_3dPoint* V
        ) const;

  /*
  Description:
    Reverses the order of the vertices in v[].
    vi[0] is not changed.
  */
  void Flip();

  /*
  Description:
    If IsValid() returns false, then you can use Repair()
    to attempt to create a valid triangle. 
  Parameters:
    mesh_vertex_count - [in]
      number of vertices in the mesh
    V - [in]
      optional array of mesh_vertex_count vertex locations.
  Returns:
    true
     repair was successful and v[0], v[1], vi[2] have distinct valid
     values and v[2] == v[3].
    false
     this face's vi[] values cannot be repaired    
  */
  bool Repair(
        int mesh_vertex_count
        );
  bool Repair(
        int mesh_vertex_count,
        const ON_3fPoint* V
        );
  bool Repair(
        int mesh_vertex_count,
        const ON_3dPoint* V
        );

  /*
  Description:
    Compute the face normal
  Parameters:
    dV - [in] double precision vertex array for the mesh
    fV - [in] float precision vertex array for the mesh
    FN - [out] face normal
  Returns:
    true if FN is valid.
  */
  bool ComputeFaceNormal( const ON_3dPoint* dV, ON_3dVector& FN ) const;
  bool ComputeFaceNormal( const ON_3fPoint* fV, ON_3dVector& FN ) const;
  bool ComputeFaceNormal( const class ON_3dPointListRef& vertex_list, ON_3dVector& FN ) const;

  /*
  Parameters:
    planar_tolerance - [in] 
      If planar_tolerance >= 0 and
      (maximum plane equation value - minimum plane equation value) > planar_tolerance,
      then false is returned.
    angle_tolerance_radians - [in]
      If angle_tolerance_radians >= 0.0 and the angle between opposite
      corner normals is > angle_tolerance_radians, then false is returned.
      A corner normal is the normal to the triangle formed by two
      adjacent edges and the diagonal connecting their endpoints.
      A quad has four corner normals.
      Passing in ON_PI/2 is a good way will result in false being
      returned for non-convex quads
    face_plane_equation - [out]
      If not null, the equation used to test planarity is returned here.
  Returns:
    True if the face is planar
  */
  bool IsPlanar( 
    double planar_tolerance,
    double angle_tolerance_radians,
    const class ON_3dPointListRef& vertex_list,
    ON_PlaneEquation* face_plane_equation
    ) const;

  /*
  Description:
    Get corner normals.
  Parameters:
    vertex_list - [in]
    corner_normals[4] - [out]
      For a triangle, all values are identical.
      If a corner normal cannot be calculated, ON_3dVector::UnsetVector
      is returned.
  Returns:
    Number of corner normals that are valid.
  */
  unsigned int GetCornerNormals(
    const class ON_3dPointListRef& vertex_list,
    ON_3dVector corner_normals[4]
    ) const;

  bool GetPlaneEquation(
    const class ON_3dPointListRef& vertex_list,
    ON_PlaneEquation& face_plane_equation
    ) const;

};


class ON_CLASS ON_MeshTriangle
{
public:
  static const ON_MeshTriangle UnsetMeshTriangle; // all vi[] values are ON_UNSET_UINT_INDEX.

  unsigned int m_vi[3]; // vertex index list

  /*
  Description:
    Determine if a triangle is valid by checking that the vertices
    are distinct.
  Parameters:
    mesh_vertex_count - [in]
      number of vertices in the mesh
    vertex_list - [in]
      optional list of mesh vertex locations.
  Returns:
    true
      The triangle is valid.
    false
      The triangle is not valid.
  */
  bool IsValid( 
    size_t mesh_vertex_count
    ) const;

  bool IsValid(
    size_t mesh_vertex_count,
    const class ON_3fPoint* vertex_list
    ) const;

  bool IsValid(
    size_t mesh_vertex_count,
    const class ON_3dPoint* vertex_list
    ) const;  

  bool IsValid(
    const class ON_3dPointListRef& vertex_list
    ) const;

  /*
  Description:
    Swaps the values of m_vi[1] and m_vi[2]. m_vi[0] is not changed.
  */
  void Flip();


  /*
  Description:
    Compute the triangle normal
  Parameters:
    dV - [in] double precision vertex array for the mesh
    fV - [in] float precision vertex array for the mesh
    vertex_list - [in] vertex locations
    triangle_normal - [out] triangle normal
  Returns:
    true if triangle_normal is valid.
  */
  bool GetTriangleNormal(
    const class ON_3dPoint* dV, 
    class ON_3dVector& triangle_normal 
    ) const;

  bool GetTriangleNormal(
    const class ON_3fPoint* fV, 
    class ON_3dVector& triangle_normal 
    ) const;

  bool GetTriangleNormal(
    const class ON_3dPointListRef& vertex_list, 
    class ON_3dVector& triangle_normal
    ) const;

 static bool GetTriangleNormal(
   ON_3dPoint point0,
   ON_3dPoint point1,
   ON_3dPoint point2,
   class ON_3dVector& triangle_normal
   );

};

class ON_CLASS ON_MeshFaceList
{
public:
  ON_MeshFaceList()
    : m_bQuadFaces(false)
    , m_face_count(0)
    , m_face_stride(0)
    , m_faces(0)
  {}

  ON_MeshFaceList(
    const ON_Mesh* mesh
    );

  static const ON_MeshFaceList EmptyFaceList;

  unsigned int SetFromTriangleList(
    size_t triangle_count,
    size_t triangle_stride,
    const unsigned int* triangles
    );
  
  unsigned int SetFromQuadList(
    size_t quad_count,
    size_t quad_stride,
    const unsigned int* quads
    );

  unsigned int SetFromMesh(
    const ON_Mesh* mesh
    );

  inline const unsigned int* Fvi(unsigned int face_index) const
  {
    return (face_index < m_face_count) ? (m_faces + (face_index*m_face_stride)) : 0;
  }

  inline unsigned int* QuadFvi(unsigned int face_index, unsigned int buffer[4]) const
  {
    if ( face_index < m_face_count )
    {
      const unsigned int* p = m_faces + (face_index*m_face_stride);
      buffer[0] = *p;
      buffer[1] = *(++p);
      buffer[2] = *(++p);
      buffer[3] = m_bQuadFaces ? *(++p) : buffer[2];
    }
    else
    {
      buffer[0] = buffer[1] = buffer[2] = buffer[3] = 0;
    }
    return buffer;
  }


  inline bool IsQuad(unsigned int face_index) const
  {
    if ( m_bQuadFaces && face_index < m_face_count )
    {
      const unsigned int* p = m_faces + (face_index*m_face_stride);
      return p[2] != p[3];
    }
    return false;
  }

  inline unsigned int FaceCount() const
  {
    return m_face_count;
  }

  inline unsigned int FaceVertexCount() const
  {
    return m_bQuadFaces?4:3;
  }

  size_t FaceStride() const
  {
    return m_face_stride;
  }

  /*
  Description:
    Get the minimum and maximum vertex indices referenced by a face in the list.
  Parameters:
  minimum_valid_vertex_index - [in]
    Any face with a vertex index < minimum_valid_vertex_index will be ignored.
  maximum_valid_vertex_index - [in]
    Any face with a vertex index > maximum_valid_vertex_index will be ignored.
  minimum_vertex_index - [out]
  maximum_vertex_index - [out]
    If there are no valid faces, then both output values are 0.
  Returns:
    Number of valid faces.
  */
  unsigned int GetVertexIndexInterval(
    unsigned int minimum_valid_vertex_index,
    unsigned int maximum_valid_vertex_index,
    unsigned int* minimum_vertex_index,
    unsigned int* maximum_vertex_index
    ) const;
  
private:
  bool m_bQuadFaces;
  unsigned int m_face_count;
  unsigned int m_face_stride;
  const unsigned int* m_faces;
};

class ON_CLASS ON_MeshVertexFaceMap
{
public:
  ON_MeshVertexFaceMap() ON_NOEXCEPT;
  ~ON_MeshVertexFaceMap();
  ON_MeshVertexFaceMap(const ON_MeshVertexFaceMap&);
  ON_MeshVertexFaceMap& operator=(const ON_MeshVertexFaceMap&);

#if defined(ON_HAS_RVALUEREF)
  // rvalue copy constructor
  ON_MeshVertexFaceMap( ON_MeshVertexFaceMap&& ) ON_NOEXCEPT;
  ON_MeshVertexFaceMap& operator=( ON_MeshVertexFaceMap&& ) ON_NOEXCEPT;
#endif

  bool SetFromMesh(
    const ON_Mesh* mesh,
    bool bMapInvalidFaces
    );

  bool SetFromFaceList(
    unsigned int vertex_count,
    const class ON_MeshFaceList& face_list,
    bool bMapInvalidFaces
    );

  void Destroy();

  /*
  Returns:
    Number a vertices.
  */
  unsigned int VertexCount() const;

  /*
  Returns:
    Number a faces.
  */
  unsigned int FaceCount() const;

  /*
  Parameters:
    vertex_index - [in]
      Index of a vertex.
  Returns:
    The number of faces that reference the vertex.
  Remarks:
    If vertex_index is out of range, then zero is returned.
  */
  unsigned int VertexFaceCount(
    unsigned int vertex_index
    ) const;
  
  /*
  Parameters:
    vertex_index - [in]
      Index of a vertex.
  Returns:
    An array of indices of faces that reference the vertex.
    The array has length VertexFaceCount(vertex_index).
    When the value of VertexFaceCount(vertex_index) is zero,
    this function returns a null pointer.
  Remarks:
    If vertex_index is out of range, then null is returned.
  */
  const unsigned int* VertexFaceList(
    unsigned int vertex_index
    ) const;

  /*
  Description:
    Expert user function for situations where rapid access to the
    vertex face list information is required.
  Returns:
    An array of VertexCount() unsigned int arrays that list the
    indices of faces that reference each vertex.
    VertexFaceMap()[vertex_index] is null if zero faces reference the
    indicated vertex. Otherwise, VertexFaceMap()[vertex_index][0] is
    the number of faces that reference the vertex and 
    VertexFaceMap()[vertex_index][1,...,n] are the indices of those faces,
    where "n" is the value of VertexFaceMap()[vertex_index][0].
  */
  const unsigned int *const* VertexFaceMap() const;

private:
  unsigned int m_vertex_count;
  unsigned int m_face_count;
  const unsigned int *const* m_vertex_face_map;
  void* m_p;
  void m_copy(const ON_MeshVertexFaceMap&);
  void* m_alloc(size_t);
};


class ON_CLASS ON_MeshNgonBuffer
{
  // An ON_MeshNgonBuffer provides memory for 
  // creating an ON_MeshNgon that is a triangle or quad.
public:
  ON_MeshNgonBuffer();
  const class ON_MeshNgon* Ngon() const;
  
  const class ON_MeshNgon* CreateFromMeshFaceIndex(
    const class ON_Mesh* mesh,
    unsigned int face_index
    );
  
  const class ON_MeshNgon* CreateFromMeshFace(
    const class ON_MeshFace* mesh_face,
    unsigned int face_index
    );
  
  const class ON_MeshNgon* CreateFromTriangle(
    const unsigned int triangle_vertex_indices[3],
    unsigned int face_index
    );

  const class ON_MeshNgon* CreateFromQuad(
    const unsigned int quad_vertex_indices[4],
    unsigned int face_index
    );

public:
  ON__UINT_PTR m_ngon_buffer[10];
};

class ON_CLASS ON_MeshNgon
{
public:
  // Number of N-gon corners (N >= 3)
  unsigned int m_Vcount; // number of vertices and sides (the "n" in n-gon)
  unsigned int m_Fcount; // number of faces

  // N-gon vertex indices
  // An array of m_Vcount indices into the mesh's m_V[] vertex array.
  // Unset elements have the value ON_UNSET_UINT_INDEX.  If the ngon
  // in managed by an ON_NgonAllocator, then the memory for m_vi[]
  // is also managed by that ON_NgonAllocator.
  unsigned int* m_vi;

  // N-gon face indices
  // An array of m_Fcount indices into the mesh's m_F[] face array.
  // Unset elements have the value ON_UNSET_UINT_INDEX.  If the ngon
  // in managed by an ON_NgonAllocator, then the memory for m_fi[]
  // is also managed by that ON_NgonAllocator.
  unsigned int* m_fi;

  /*
  Returns:
    0:   This n-gon is not managed by an ON_MeshNgonAllocator.
    >=0: The maximum capcity (maximum m_Vcount+m_Fcount) for this N-gon
  */
  unsigned int Capacity() const;

  static int Compare(
    const ON_MeshNgon* A,
    const ON_MeshNgon* B
    );

  /*
  Returns:
    32-bit cyclic redundancy check that can be used as a hash code.
  */
  ON__UINT32 CRC32() const;

  /*
  Returns:
    A SHA-1 has of the vertex and face indices.
  */
  ON_SHA1_Hash ContentHash() const;

  /*
  Parameters:
    mesh_face_list - [in]
      faces referenced by this n-gon.
  Returns:
    Total number of boundary edges, including interior edges.
  */
  unsigned int BoundaryEdgeCount(
    const ON_MeshFaceList& mesh_face_list
  ) const;

  /*
  Parameters:
    mesh - [in]
      mesh referenced by this n-gon.
  Returns:
    Total number of boundary edges, including interior edges.
  */
  unsigned int BoundaryEdgeCount(
    const ON_Mesh* mesh
  ) const;

  /*
  Returns:
    Total number of outer boundary edges.
  */
  unsigned int OuterBoundaryEdgeCount() const;

  /*
  Pamameters:
    mesh_face_list - [in]
      ON_Mesh face list.
    bPermitHoles - [in]
      true if the ngon is permitted to have interior holes
      false otherwise.
  Description:
    Determine if the ngon's boundary orientation matches that of the set of faces it is made from.
  Returns:
     1: The ngon does not have holes, the ngon's faces are compatibly oriented, 
        and the ngon's outer boundary orientation matches the faces' orientation.
    -1: The ngon does not have holes, the ngon's faces are compatibly oriented,
        and the ngon's outer boundary orientation is opposite the faces' orientation.
     0: Otherwise. The ngon may be invalid, have holes, the ngon's faces may not be compatibly oriented, 
        the ngons edges may not have a consistent orientation with respect to the faces, or some other issue.
  */
  int Orientation(
    const ON_MeshFaceList& mesh_face_list,
    bool bPermitHoles
  ) const;

  /*
  Pamameters:
    mesh_face_list - [in]
      ON_Mesh face list.
    bPermitHoles - [in]
      true if the ngon is permitted to have interior holes
      false otherwise.
  Description:
    Determine if the ngon's boundary orientation matches that of the set of faces it is made from.
  Returns:
     1: The ngon does not have holes, the ngon's faces are compatibly oriented, 
        and the ngon's outer boundary orientation matches the faces' orientation.
    -1: The ngon does not have holes, the ngon's faces are compatibly oriented,
        and the ngon's outer boundary orientation is opposite the faces' orientation.
     0: Otherwise. The ngon may be invalid, have holes, the ngon's faces may not be compatibly oriented, 
        the ngons edges may not have a consistent orientation with respect to the faces, or some other issue.
  */
  int Orientation(
    const ON_Mesh* mesh,
    bool bPermitHoles
  ) const;

  /*
  Description:
    Reverse the order of the m_vi[] array.
  */
  void ReverseOuterBoundary();

  /*
  Description:
    Use the ngon m_vi[] array to get a list of 3d points from
    mesh_vertex_list.
  Parameters:
    mesh_vertex_list - [in]
    bAppendStartPoint - [in]
      If true, the initial point in the boundary will be added
      as the first point of ngon_boundary_points[] and then
      added again as the last point of ngon_boundary_points[].
      This is useful when you need a closed polyline.
    ngon_boundary_points - [out]
      An array of ngon->m_Vcount + (bAppendStartPoint ? 1 : 0)
      points.
  Returns:
    Number of points added to ngon_boundary_points[] or 0 if invalid
    input is encountered.
  */
  unsigned int GetOuterBoundaryPoints(
    const class ON_3dPointListRef& mesh_vertex_list,
    bool bAppendStartPoint,
    ON_SimpleArray<ON_3dPoint>& ngon_boundary_points
    ) const;

  /*
  Description:
    Use the ngon m_vi[] array to get a list of 3d points from
    mesh_vertex_list.
  Parameters:
    mesh_vertex_list - [in]
    bAppendStartPoint - [in]
      If true, the initial point in the boundary will be added
      as the first point of ngon_boundary_points[] and then
      added again as the last point of ngon_boundary_points[].
      This is useful when you need a closed polyline.
    ngon_boundary_points - [out]
      An array of ngon->m_Vcount + (bAppendStartPoint ? 1 : 0) points
      is returned in ngon_boundary_points[].  The caller must insure
      that ngon_boundary_points[] has room for this many elements.
  Returns:
    Number of points added to ngon_boundary_points[] or 0 if invalid
    input is encountered.
  */
  unsigned int GetOuterBoundaryPoints(
    const class ON_3dPointListRef& mesh_vertex_list,
    bool bAppendStartPoint,
    ON_3dPoint* ngon_boundary_points
    ) const;


  /*
  Description:
    Use the ngon m_fi[] array to get a list of ngon boundary sides.
  Parameters:
    mesh_face_list - [in]
    ngon_boundary_sides - [out]
      ngon_boundary_sides[i]/8 = ON_MeshNon.m_fi[] array index
      ngon_boundary_sides[i]%4 = side index
        side index 0 identifies the side that runs from the first face
        vertex to the second face vertex.
      ngon_boundary_sides[i]&4 != 0 means the face side is reversed
        when used as an ngon boundary segment.
  Returns:
    Number of elements added to ngon_boundary_sides[] or 0 if invalid
    input is encountered.
  */
  unsigned int GetBoundarySides(
    const class ON_MeshFaceList& mesh_face_list,
    ON_SimpleArray<unsigned int>& ngon_boundary_sides
    ) const;


  //////////////////////////////////////////////////////////////
  //
  // Tools for finding a making n-gons
  //
  static unsigned int FindPlanarNgons(
    const class ON_3dPointListRef& vertex_list,
    const class ON_MeshFaceList& face_list,
    const unsigned int *const* vertex_face_map,
    double planar_tolerance,
    unsigned int minimum_ngon_vertex_count,
    unsigned int minimum_ngon_face_count,
    bool bAllowHoles,
    class ON_MeshNgonAllocator& NgonAllocator,
    ON_SimpleArray<unsigned int>& NgonMap,
    ON_SimpleArray<ON_MeshNgon*>& Ngons
    );

  /*
  Description:
    Get a list of vertices that form the boundary of a set of faces.
  Parameters:
    mesh_vertex_list - [in]
    mesh_face_list - [in]
    vertex_face_map - [in]
      null or a vertex map made from the information in
      mesh_vertex_list and mesh_face_list.
    ngon_fi_count - [in]
      length of ngon_fi[] array
    ngon_fi - [in]
      An array of length ngon_fi_count that contains the indices 
      of the faces that form the ngon.
    ngon_vi - [out]
      An array of vertex indices that make the ngon boundary.        
  Returns:
    Number of vertices in the ngon outer boundary or 0 if the input is
    not valid.
  */
  static unsigned int FindNgonOuterBoundary(
    const class ON_3dPointListRef& mesh_vertex_list,
    const class ON_MeshFaceList& mesh_face_list,
    const unsigned int *const* vertex_face_map,
    size_t ngon_fi_count,
    const unsigned int* ngon_fi,
    ON_SimpleArray<unsigned int>& ngon_vi
    );

  /*
  Description:
    Create an ngon pointer that contains a triangle (3-gon) 
    or quad (4-gon) from a mesh face.  
    This is handy when your code needs to handle both
    ngons and faces because it lets you convert a face to its
    ngon format and the rest of the code can work exclusively with
    ngons.
  Parameters:
    buffer - [in]
      an array with a capacity for at least 9 ON__UINT_PTR elements.
      The returned ngon information will be stored in this memory.
    mesh_face_index - [in]
    fvi - [in]
      mesh face vertex indices.
      If "f" is an ON_MeshFace, then pass (const unsigned int*)f.vi.
  Returns:
    If the input is valid, the returned ngon pointer is is the 
    face's triangle or quad.  All returned information is in the
    buffer[].
    null - invalid input.
  See Also:
    ON_Mesh::NgonFromComponentIndex()
  */
  static class ON_MeshNgon* NgonFromMeshFace(
    class ON_MeshNgonBuffer& ngon_buffer,
    unsigned int mesh_face_index,
    const unsigned int* fvi
    );

  /*
  Description:
    Create an array of a single ngon pointer that contains
    a triangle (3-gon) or quad (4-gon) from a mesh face.  
    This is handy when your code needs to handle both
    ngons and faces because it lets you convert a face to its
    ngon format and the rest of the code can work exclusively with
    ngons.
  Parameters:
    ngon_buffer - [in]
      memory used to create ngon classan array with a capacity for at least 10 ON__UINT_PTR elements.
    mesh_face_index - [in]
    fvi - [in]
      mesh face vertex indices.
      If "f" is an ON_MeshFace, then pass (const unsigned int*)f.vi.
  Returns:
    If the input is valid, the returned pointer is an array of a single ngon 
    that is the face's triangle or quad.  All returned information is in the
    buffer[].
    null - invalid input.
  */
  static class ON_MeshNgon** NgonListFromMeshFace(
    class ON_MeshNgonBuffer& ngon_buffer,
    unsigned int mesh_face_index,
    const unsigned int* fvi
    );

  /*
  Description:
    If a component index identifies a face or ngon, Get an array Create an array of a single ngon pointer that contains
    a triangle (3-gon) or quad (4-gon) from a mesh face.  
    This is handy when your code needs to handle both
    ngons and faces because it lets you convert a face to its
    ngon format and the rest of the code can work exclusively with
    ngons.
  Parameters:
    ngon_buffer - [in]
      memory used to create ON_MeshNgon class
    ci - [in]
    mesh - [in]
    ngon_list - [out]
      An array of ngon pointers.  Some pointers may be null.
  Returns:
    Number of ngon pointers in ngon_list.
  */
  static  unsigned int NgonListFromMeshFaceOrNgonComponent(
    class ON_MeshNgonBuffer& ngon_buffer,
    ON_COMPONENT_INDEX ci,
    const class ON_Mesh* mesh,
    const class ON_MeshNgon* const *& ngon_list
    );

  ////////////////////////////////////////////////////////////////////
  //
  // Tools for text output
  //
  ON_String ToString() const;

  ON_wString ToWideString() const;

  void Dump( 
    class ON_TextLog& text_log 
    )const;

  void AppendToString( 
    class ON_String& s
    )const;

  void AppendToString( 
    class ON_wString& s
    )const;


  ////////////////////////////////////////////////////////////////////
  //
  // Tools for validation output
  //

  /*
  Description:
    Test ngon to see if the vertex and face references are valid and
    pass partial boundary validity checks,
  Parameters:
    ngon - [in]
      ngon to test
    ngon_index - [in]
      This index is used in messages sent to text_log
    text_log - [in]
      nullptr or a place to send information about problems.
    mesh_vertex_count - [in]
      Number of vertices in the mesh
    mesh_face_count - [in]
      Number of face in the mesh
    mesh_F - [in]
      nullptr of mesh faces - required for boundary checks
    workspace_buffer - [in]
      If you are passing in mesh_F and you are testing testing multple 
      ngons, then consider providing a workspace_buffer that will be automatically
      reused for successive ngons.
  Returns:
    0: ngon is not valid
    >0: number of boundary edges.  
        If this number is > ngon->m_V_count, then the ngon has inner boundaries
        or duplicate vertices.       
  */
  static unsigned int IsValid(
    const ON_MeshNgon* ngon,
    unsigned int ngon_index,
    ON_TextLog* text_log,
    unsigned int mesh_vertex_count,
    unsigned int mesh_face_count,
    const ON_MeshFace* mesh_F
    );

  static unsigned int IsValid(
    const ON_MeshNgon* ngon,
    unsigned int ngon_index,
    ON_TextLog* text_log,
    unsigned int mesh_vertex_count,
    unsigned int mesh_face_count,
    const ON_MeshFace* mesh_F,
    ON_SimpleArray< unsigned int >& workspace_buffer
    );
};

class ON_CLASS ON_MeshNgonAllocator
{
public:
  ON_MeshNgonAllocator() ON_NOEXCEPT;
  ~ON_MeshNgonAllocator();

  /*
  Parameters:
    Vcount - [in] >= 3
    Fcount - [in] >= 0
  */
  ON_MeshNgon* AllocateNgon(
    unsigned int Vcount,
    unsigned int Fcount
    );

  /*
  Parameters:
    Vcount - [in] >= 3
    Fcount - [in] >= 0
  */
  ON_MeshNgon* ReallocateNgon(
    ON_MeshNgon* ngon,
    unsigned int Vcount,
    unsigned int Fcount
    );

  /*
  Parameters:
    ngon - in]
      An ngon pointer value that was previously returned by
      this allocator's AllocateNgon() or CopyNgon() function.
  */
  bool DeallocateNgon(
    ON_MeshNgon* ngon
    );

  /*
  Description:
    Returns a copy of ngon.
  Parameters:
    ngon - [in]
  Returns:
    If 
  */
  ON_MeshNgon* CopyNgon(
    const ON_MeshNgon* ngon
    );

  /*
  Description:
    Deallocate every n-gon managed by this allocator.
  */
  void DeallocateAllNgons();

#if defined(ON_HAS_RVALUEREF)
  ON_MeshNgonAllocator(ON_MeshNgonAllocator&&);
  ON_MeshNgonAllocator& operator=(ON_MeshNgonAllocator&&);
#endif

private:

  ON_FixedSizePool m_7;  // Vcount+Fcount <= 7
  ON_FixedSizePool m_15; // Vcount+Fcount <= 15
  void* m_31; // available for Vcount+Fcount <= 31
  void* m_63; // available for Vcount+Fcount <= 63
  void* m_active;   // active Vcount+Fcount >= 16

private:
  // prohibit copy construction. No implentation.
  ON_MeshNgonAllocator(const ON_MeshNgonAllocator&) = delete;

  // prohibit operator=. No implentation.
  ON_MeshNgonAllocator& operator=(const ON_MeshNgonAllocator&) = delete;
};

class ON_MeshFaceSide
{
public:
  unsigned int   m_vi[2]; // vertex indices or ids (equal values indicate unset)
  unsigned int   m_fi;    // face index or id
  unsigned char  m_side;  // triangles use 0,1,3, quads use 0,1,2,3
                          // m_side 0 connect face vertex 0 to face vertex 1.
  unsigned char  m_dir;   // 0 = counterclockwise, 1 = clockwise (reversed)
  unsigned short m_value; // Use depends on context.
  unsigned int   m_id;    // Use depends on context - typically identifies and edge or ngon

  static const ON_MeshFaceSide Unset; // all values are zero

  /*
  Description:
    Compare a and b in dictionary order comparing the field values in the order
      m_fi
      m_vi[0]
      m_vi[1]
      m_side
      m_dir
  Parameters:
    a - [in]
    b - [in]
  Returns:
    -1: *a < *b
     0: *a < *b
     1: *a > *b
  Remarks:
    The function is thread safe.
  */
  static int CompareFaceIndex(
    const ON_MeshFaceSide* a,
    const ON_MeshFaceSide* b
    );

  /*
  Description:
    Compare a and b in dictionary order comparing the field values in the order
      m_vi[0]
      m_vi[1]
      m_fi
      m_side
      m_dir
  Parameters:
    a - [in]
    b - [in]
  Returns:
    -1: *a < *b
     0: *a < *b
     1: *a > *b
  Remarks:
    The function is thread safe.
  */
  static int CompareVertexIndex(
    const ON_MeshFaceSide* a,
    const ON_MeshFaceSide* b
    );

  /*
  Description:
    Sort the face_sides[] using the compare function 
    ON_MeshFaceSide::CompareVertexIndex().
  Paramters:
    face_sides - [in/out]
      array to sort
    face_sides_count - [in]
      number of elements in the face_sides[] array.
  Remarks:
    The function is thread safe.
  */
  static void SortByVertexIndex(
    ON_MeshFaceSide* face_sides,
    size_t face_sides_count
    );

  /*
  Description:
    Sort the face_sides[] using the compare function 
    ON_MeshFaceSide::CompareFaceIndex().
  Paramters:
    face_sides - [in/out]
      array to sort
    face_sides_count - [in]
      number of elements in the face_sides[] array.
  Remarks:
    The function is thread safe.
  */
  static void SortByFaceIndex(
    ON_MeshFaceSide* face_sides,
    size_t face_sides_count
    );

  /*
  Description:
    Get a list of mesh face sides.
  Parameters:
    mesh_vertex_count - [in]
      Number of vertices in the mesh.
      This value is used to validate vertex index values in mesh_face_list.
    mesh_face_list - [in]
      Mesh faces
    fi_list - [in]
      - If fi_list null, then sides for every face in mesh_face_list will 
        be added and the ON_MeshFaceSide.m_fi values will be the 
        mesh_face_list[] index.
      - If fi_list is not null, then fi_list[] is an array of mesh_face_list[]
        indices and the ON_MeshFaceSide.m_fi values will be fi_list[] array 
        indices. For example, you may pass ON_MeshNon.m_fi as this parameter
        when you want a list of sides of faces in an ngon.
    fi_list_count - [in]
      - If fi_list is not null, then fi_list_count is the number of elements
        in the fi_list[] array.
      - If fi_list is null, then fi_list_count is ignored.
    vertex_id_map - [in] (can be null)
      - If vertex_id_map is null, then the ON_MeshFaceSide::m_vi[] values
        are the vertex index values from mesh_face_list[].
      - If vertex_id_map is not null, then vertex_id_map[] is an array
        with the mesh_vertex_count elements and ON_MeshFaceSide::m_vi[] values
        are vertex_id_map[mesh_face_list[] vertex indices]. A vertex_id_map[]
        is commonly used when coincident vertices need to be treated as
        a single topological entity.
    face_side_list - [out]
      - If the input value of face_side_list is not null, then face_side_list[] 
        must be long enough to hold the returned face_side_list list.  
        The maximum posssible length is 4*mesh_face_list.FaceCount().
      - If the input falue of face_side_list is null, memory will be allocated
        using onmalloc() and the caller is responsible for calling onfree() at
        an appropriate time.
      The returned is face_side_list[] is dictionary sorted by ON_MeshFaceSide.m_fi
      and then ON_MeshFaceSide.m_si. The vertex ids satisfy
      ON_MeshFaceSide.m_vi[0] < ON_MeshFaceSide.m_vi[1].  ON_MeshFaceSide.m_dir
      is 0 if the face vertex order is the same and 1 if the face vertex order
      is opposite. The static sorting functions on ON_MeshFaceSide can be used
      to change this ordering.
  Returns:
    Number of elements set in face_side_list[].
  Remarks:
    Faces in mesh_face_list with vertex indices that are >= mesh_vertex_count
    are ignored.  Degenerate faces are processed, but degenerate sides 
    (equal vertex ids) are not added to face_side_list[].
  */
  static unsigned int GetFaceSideList(
    size_t mesh_vertex_count,
    const class ON_MeshFaceList& mesh_face_list,
    const unsigned int* fi_list,
    size_t fi_list_count,
    const unsigned int* vertex_id_map,
    ON_MeshFaceSide*& face_side_list
    );
};


struct ON_MeshPart
{
  // ON_Mesh faces with indices fi[0] <= i < fi[1] reference
  // vertices with indices vi[0] <= j < vi[1].
  int vi[2]; // subinterval of mesh m_V[] array
  int fi[2]; // subinterval of mesh m_F[] array
  int vertex_count;   // = vi[1] - vi[0];
  int triangle_count; // tris + 2*quads >= fi[1] - fi[0]
};

#if defined(ON_DLL_TEMPLATE)
ON_DLL_TEMPLATE template class ON_CLASS ON_SimpleArray<ON_MeshFace>;
ON_DLL_TEMPLATE template class ON_CLASS ON_SimpleArray<ON_MeshNgon*>;
ON_DLL_TEMPLATE template class ON_CLASS ON_SimpleArray<ON_MeshTopologyVertex>;
ON_DLL_TEMPLATE template class ON_CLASS ON_SimpleArray<ON_MeshTopologyEdge>;
ON_DLL_TEMPLATE template class ON_CLASS ON_SimpleArray<ON_MeshTopologyFace>;
ON_DLL_TEMPLATE template class ON_CLASS ON_SimpleArray<struct ON_MeshPart>;
#endif

class ON_CLASS ON_MeshTopology
{
  // A mesh topology class is always associated with an ON_Mesh
  // and can be retrieved by calling ON_Mesh::Topology()
public:
  ON_MeshTopology();
  ~ON_MeshTopology();

  bool IsValid() const;

  void Dump( ON_TextLog& ) const;

  //////////
  // The parent ON_Mesh geometry used to compute this mesh topology.
  const ON_Mesh* m_mesh;

  //////////
  // number of topoligical vertices (<= m_mesh.VertexCount())
  int TopVertexCount() const;

  //////////
  // number of topoligical edges
  int TopEdgeCount() const;
  
  //////////
  // number of topoligical faces (same as m_mesh.FaceCount())
  int TopFaceCount() const;

  class ON_MeshComponentRef MeshComponentRef(
    ON_COMPONENT_INDEX ci
    ) const;

  /*
  Parameters:
    ci - [in]
      A component index with type of 
      ON_COMPONENT_INDEX::TYPE::mesh_vertex or 
      ON_COMPONENT_INDEX::TYPE::meshtop_vertex.
  Return:
    If ci correctly identifes a mesh topology vertex, then
    component index with type of ON_COMPONENT_INDEX::TYPE::meshtop_vertex is returned.
    Otherwise ON_COMPONENT_INDEX::UnsetComponentIndex is returned.
  */
  const ON_COMPONENT_INDEX TopVertexComponentIndex(
    ON_COMPONENT_INDEX ci
  ) const;

  /*
  Description:
    Get the 3d point location of a vertex.
  Parameters:
    topv_index - [in];
  Returns:
    Location of vertex.
  */
  ON_3dPoint TopVertexPoint(
    int topv_index
    ) const;

  /*
  Description:
    Get the 3d line along an edge.
  Parameters:
    tope_index - [in];
  Returns:
    Line along edge.  If input is not valid,
    the line.from and to are ON_3dPoint::UnsetPoint
  */
  ON_Line TopEdgeLine(
    int tope_index
    ) const;

  ////////
  // returns index of edge that connects topological vertices
  // returns -1 if no edge is found.
  int TopEdge(
    int vtopi0,
    int vtopi1 // ON_MeshTopology vertex topology indices
    ) const;

  ////////
  // returns ON_MeshTopology vertex topology index of a face
  // corner.  The face is triangle iv TopFaceVertex(2) = TopFaceVertex(3)
  bool GetTopFaceVertices(
    int topfi,    // ON_MeshTopology face topology index (= ON_Mesh face index)
    int topvi[4]  // ON_MeshTopology vertex indices returned here
    ) const;

  /*
  Parameters:
    topvi - [in]
      Topology vertex index
    mesh_facedex_to_ngondex_map - [in]
      If null, Mesh().NgonMap() will be used.  In cases where Mesh().NgonMap()
      does not exist and cannot be created, an expert user may pass in
      a local map that converts a face index into an ngon index.
  Returns:
    If the vertex is interior to a single ngon, then the index of the
    ngon is returned.  Otherwise ON_UNSET_UINT_INDEX is returned.
  */
  unsigned int NgonIndexFromTopologyVertexIndex(
    unsigned int topvi,
    const unsigned int* mesh_facedex_to_ngondex_map
    ) const;

  /*
  Parameters:
    topei - [in]
      Topology edge index
    mesh_facedex_to_ngondex_map - [in]
      If null, Mesh().NgonMap() will be used.  In cases where Mesh().NgonMap()
      does not exist and cannot be created, an expert user may pass in
      a local map that converts a face index into an ngon index.
  Returns:
    If the vertex is interior to a single ngon, then the index of the
    ngon is returned.  Otherwise ON_UNSET_UINT_INDEX is returned.
  */
  unsigned int NgonIndexFromTopologyEdgeIndex(
    unsigned int topei,
    const unsigned int* mesh_facedex_to_ngondex_map
    ) const;

  /*
  Description:
    Sort the m_topei[] list of a mesh topology vertex so that
    the edges are in radial order.  The "const" is a white
    lie to make this function easier to call.
  Parameter:
    topvi - [in] index of vertex in m_topv[] array.
  Remarks:
    A nonmanifold edge is treated as a boundary edge with respect
    to sorting.  If any boundary or nonmanifold edges end at the
    vertex, then the first edge will be a boundary or nonmanifold
    edge.
  */
  bool SortVertexEdges( int topvi ) const;

  /*
  Description:
    Sort the m_topei[] list of every mesh topology vertex so 
    that the edges are in radial order.  The "const" is a white
    lie to make this function easier to call.
  Remarks:
    Same as
    for ( int topvi = 0; topvi < m_topv.Count(); topvi++ )
      SortVertexEdges(topvi);
  */
  bool SortVertexEdges() const;

  /*
  Description:
    Returns true if the topological vertex is hidden. 
  Parameters:
    topvi - [in] mesh topology vertex index.
  Returns:
    True if mesh topology vertex is hidden.
  Remarks:
    The mesh topology vertex is hidden if and only if
    all the ON_Mesh vertices it represents is hidden.
  */
  bool TopVertexIsHidden( int topvi ) const;

  /*
  Description:
    Returns true if the topological edge is hidden. 
  Parameters:
    topei - [in] mesh topology edge index.
  Returns:
    True if mesh topology edge is hidden.
  Remarks:
    The mesh topology edge is hidden if and only if
    either of its mesh topology vertices is hidden.
  */
  bool TopEdgeIsHidden( int topei ) const;

  /*
  Description:
    Returns true if the topological face is hidden. 
  Parameters:
    topfi - [in] mesh topology face index.
  Returns:
    True if mesh topology face is hidden.
  Remarks:
    The mesh topology face is hidden if and only if
    any of its mesh topology edges are hidden.
  */
  bool TopFaceIsHidden( int topfi ) const;

  //////////
  // m_topv_map[] has length m_mesh.VertexCount() and 
  // m_topv[m_topv_map[vi]] is the topological mesh vertex that is assocated
  // the with the mesh vertex m_mesh.m_V[vi].
  ON_SimpleArray<int> m_topv_map;

  ////////////
  // Array of topological mesh vertices.  See the comments in the definition
  // of ON_MeshTopologyVertex for details.
  ON_SimpleArray<ON_MeshTopologyVertex> m_topv;

  ////////////
  // Array of topological mesh edges.  See the comments in the definition
  // of ON_MeshTopologyEdge for details.
  ON_SimpleArray<ON_MeshTopologyEdge> m_tope;

  ////////////
  // Array of topological mesh faces.  The topological face
  // m_topf[fi] corresponds to the mesh face ON_Mesh.m_F[fi].
  // See the comments in the definition of ON_MeshTopologyFace
  // for details. To get the indices of the mesh topology 
  // vertices at the face corners use 
  // topvi = m_topv_map[m_mesh.m_F[fi].vi[n]]
  ON_SimpleArray<ON_MeshTopologyFace> m_topf;

  /*
  Description:
    Expert user function for efficiently getting the
    integer arrays used by the ON_MeshTopologyVertex
    and ON_MeshTopologyEdge classes.
  Parameters:
    count - [in] number of integers in array
  Returns:
    pointer to integer array.  The array memory
    will be freed by ~ON_MeshTopology()
  */
  int* GetIntArray(int count);

private:
  friend class ON_Mesh;

  bool Create();
  void Destroy();
  void EmergencyDestroy();

  // efficient workspaces for
  struct memchunk
  {
    struct memchunk* next;
  } *m_memchunk;

  // NOTE: this field is a bool with valid values of 0 and 1.
  volatile int m_b32IsValid; // sizeof(m_bIsValid) must be 4 - it is used in sleep locks.
                    //    0: Not Valid
                    //    1: Valid
                    //   -1: Sleep locked - ON_Mesh::Topology() calculation is in progress
  int WaitUntilReady(int sleep_value) const; // waits until m_b32IsValid >= 0

private:
  // no implementation
  ON_MeshTopology(const ON_MeshTopology&);
  ON_MeshTopology& operator=(const ON_MeshTopology&);
};



class ON_CLASS ON_MeshPartition
{
public:
  ON_MeshPartition();
  ~ON_MeshPartition();

  // maximum number of vertices in a partition
  int m_partition_max_vertex_count;
  // maximum number of triangles in a partition (quads count as 2 triangles)
  int m_partition_max_triangle_count;

  // Partition i uses 
  // vertices m_V[j] where 
  //
  //   m_part[i].vi[0] <= j < m_part[i].vi[1] 
  //
  // and uses faces m_F[k] where
  //
  //    m_part[i].fi[0] <= k < m_part[i].fi[1]
  ON_SimpleArray<struct ON_MeshPart> m_part;
};



class ON_CLASS ON_MappingTag
{
public:
  ON_MappingTag();
  void Default();
  bool Write(ON_BinaryArchive&) const;
  bool Read(ON_BinaryArchive&);
  void Dump( ON_TextLog& ) const;
  void Transform( const ON_Xform& xform );
  void Set(const ON_TextureMapping& mapping);

  /*
  Description:
    Sets the tag to the value the meshes have that
    come out of ON_Brep::CreateMesh().
  */
  void SetDefaultSurfaceParameterMappingTag();

  int Compare( const ON_MappingTag& other,
               bool bCompareId = true,
               bool bCompareCRC = true,
               bool bCompareXform = true
               ) const;

  /*
  Returns:
    True if the mapping tag is set.
  */
  bool IsSet() const;

  /*
  Returns:
    True if the mapping tag is for a mapping with
    type ON_TextureMapping::srfp_mapping with
    m_uvw = identity.
  */
  bool IsDefaultSurfaceParameterMapping() const;

  // Identifies the mapping used to create the texture 
  // coordinates and records transformations applied 
  // to the mesh after the texture coordinates were
  // calculated.  If the texture mapping does not
  // change when the mesh is transformed, then set 
  // m_mesh_xform to zero so that compares will work right.
  //
  // 
  ON_UUID                 m_mapping_id;   // ON_TextureMapping::m_mapping_id
  ON_TextureMapping::TYPE m_mapping_type; // ON_TextureMapping::m_type
  ON__UINT32              m_mapping_crc;  // ON_TextureMapping::MappingCRC()
  ON_Xform                m_mesh_xform;
};

class ON_CLASS ON_TextureCoordinates
{
public:
  ON_TextureCoordinates();

  ON_MappingTag   m_tag;
  int                        m_dim; // 1, 2, or 3
  ON_SimpleArray<ON_3fPoint> m_T;   // texture coordinates
};


#if defined(ON_DLL_TEMPLATE)
ON_DLL_TEMPLATE template class ON_CLASS ON_SimpleArray<ON_MappingTag>;
ON_DLL_TEMPLATE template class ON_CLASS ON_ClassArray<ON_TextureCoordinates>;
#endif

class ON_CLASS ON_Mesh : public ON_Geometry
{
  ON_OBJECT_DECLARE(ON_Mesh);

public:
  ON_Mesh();
  ON_Mesh(
    int   initial_face_array_capacity,   // initial face array capacity
    int   initial_vertex_array_capacity, // initial vertex array capacity
    bool  has_vertex_normals,            // true if mesh has vertex normals
    bool  has_texture_coordinates        // true if mesh has texture coordinates
    );
  ON_Mesh( const ON_Mesh& );
  ON_Mesh& operator=( const ON_Mesh& );
  ~ON_Mesh();


  // Override of virtual ON_Object::MemoryRelocate
  void MemoryRelocate() override;

  // virtual ON_Object::DestroyRuntimeCache override
  void DestroyRuntimeCache( bool bDelete = true ) override;

  void Destroy();
  void EmergencyDestroy(); // Call only when memory used by this class's
                           // members will soon become invalid for reasons 
                           // beyond your control. EmergencyDestroy() zeros
                           // anything that could possibly cause
                           // ~ON_Mesh() to crash.  Calling
                           // EmergencyDestroy() under normal conditions 
                           // will result in ~ON_Mesh() leaking
                           // memory.


  void DestroyTree( bool bDeleteTree = true );

  /*
  Description:
    Check for corrupt data values that are likely to cause crashes.
  Parameters:
    bRepair - [in]
      If true, const_cast<> will be used to change the corrupt data
      so that crashes are less likely.
    bSilentError - [in]
      If true, ON_ERROR will not be called when corruption is detected.
    text_log - [out]
      If text_log is not null, then a description of corruption 
      is printed using text_log.
  Remarks:
    Ideally, IsCorrupt() would be a virtual function on ON_Object,
    but doing that at this point would break the public SDK.
  */
  bool IsCorrupt(
    bool bRepair,
    bool bSilentError,
    class ON_TextLog* text_log
  ) const;

  /////////////////////////////////////////////////////////////////
  // ON_Object overrides

  // virtual ON_Object::SizeOf override
  unsigned int SizeOf() const override;

  // virtual ON_Object::DataCRC override
  ON__UINT32 DataCRC(ON__UINT32 current_remainder) const override;

  bool IsValid( class ON_TextLog* text_log = nullptr ) const override;

  void Dump( ON_TextLog& ) const override; // for debugging

  bool Write( ON_BinaryArchive& ) const override;

  bool Read( ON_BinaryArchive& ) override;

  ON::object_type ObjectType() const override;

  /////////////////////////////////////////////////////////////////
  // ON_Geometry overrides

  int Dimension() const override;

  // virtual ON_Geometry GetBBox override		
  bool GetBBox( double* boxmin, double* boxmax, bool bGrowBox = false ) const override;

  // virtual ON_Geometry GetTightBoundingBox override		
  bool GetTightBoundingBox( class ON_BoundingBox& tight_bbox, bool bGrowBox = false, const class ON_Xform* xform = nullptr ) const override;

	bool GetTightBoundingBox(
		ON_BoundingBox& tight_bbox,
		bool bGrowBox ,
		const ON_SimpleArray<ON_PlaneEquation>& clipping_planes,		
		const ON_Xform* xform = nullptr
		) const ;

  bool Transform( 
         const ON_Xform&
         ) override;

  // virtual ON_Geometry::IsDeformable() override
  bool IsDeformable() const override;

  // virtual ON_Geometry::MakeDeformable() override
  bool MakeDeformable() override;

  bool SwapCoordinates(
        int, int        // indices of coords to swap
        ) override;


  // virtual ON_Geometry override
  bool EvaluatePoint( const class ON_ObjRef& objref, ON_3dPoint& P ) const override;


  /////////////////////////////////////////////////////////////////
  // Interface
  // 

  /*
  Returns
    true if there are zero vertices or zero faces.
  */
  bool IsEmpty() const;

  // creation
  bool SetVertex(
         int,              // vertex index
         const ON_3dPoint& // vertex location
         );
  bool SetVertex(
         int,              // vertex index
         const ON_3fPoint& // vertex location
         );
  bool SetVertexNormal(
         int,               // vertex index
         const ON_3dVector& // unit normal
         );
  bool SetVertexNormal(
         int,               // vertex index
         const ON_3fVector& // unit normal
         );
  bool SetTextureCoord(
         int,               // vertex index
         double, double     // texture coordinates
         );
  bool SetTriangle(
         int, // face index
         int,int,int // vertex indices
         );
  bool SetQuad(
         int, // face index
         int,int,int,int // vertex indices
         );

  /*
  Description:
    Use this function to append a duplicate of an existing vertex.
  Parameters:
    vertex_index - [in]
      index of the existing vertex
  Returns:
    If vertex_index is valid, the index of the duplicate is returned.
    Otherwise, ON_UNSET_UINT_INDEX is returned.
  Remarks:
    This function duplicates all information associated with
    the input vertex and is a good way to insure that
    optional vertex information like color, texture, surface
    parameters, curvatures, vertex normals, and so on get
    duplicated as well.
  */
  unsigned int AppendDuplicateVertex(
    unsigned int vertex_index
    );

  /*
  Description:
    Increases the capactiy of arrays used to hold vertex information.
  Parameters:
    new_vertex_capacity - [in]
      desired capacity
  Returns:
    true if successful.
  Remarks:
    This function is useful if you are getting ready to add a known number
    of vertices and want to increase the dynamic array capacities before
    you begin adding vertices.
  */  
  bool ReserveVertexCapacity(
    size_t new_vertex_capacity
    );

  /*
  Parameters:
    ci - [in]
      component index to test
  Returns:
    True if ci identifies a component (vertex, edge, face, ngon) that exists in this mesh.
  */
  bool IsValidMeshComponentIndex(
    ON_COMPONENT_INDEX ci
    ) const;

  class ON_MeshComponentRef MeshComponentRef(
    ON_COMPONENT_INDEX ci
    ) const;

  /*
  Parameters:
   ci - [in] a component index with type mesh_vertex, meshtop_vertex,
             meshtop_edge, or mesh_face.
  Returns:
    A pointer to an ON_MeshComponentRef
    The caller must delete the returned object when it is no longer
    needed.
  */
  class ON_MeshComponentRef* MeshComponent( 
      ON_COMPONENT_INDEX ci
      ) const;

  /*
  Description:
    Delete the portions of the mesh identified in ci_list[].
  Parameters:
    ci_list - [in]
      List of components to delete.
    ci_list_count - [in]
      Number of elements in the ci_list[] array.
      Can be zero if you are using this function to remove
      unused vertices or empty ngons.
    bIgnoreInvalidComponents - [in]
      If true, invalid elements in ci_list[] are ignored.
      If false and ci_list[] contains an invalid element,
      then no changes are made and false is returned.
    bRemoveDegenerateFaces - [in]
      If true, remove degenerate faces.
    bCullUnusedVertices - [in]
      Remove vertices that are not referenced by a face.
      Pass true unless you have a good reason for keeping
      unreferenced vertices.
    bRemoveEmptyNgons - [in]
      Remove ngons that are empty.
      Pass true unless you have a good reason for keeping
      empty ngons.
  Returns:
    True: succesful
    False: failure - no changes.
  */
  bool DeleteComponents(
    const ON_COMPONENT_INDEX* ci_list,
    size_t ci_count,
    bool bIgnoreInvalidComponents,
    bool bRemoveDegenerateFaces,
    bool bRemoveUnusedVertices,
    bool bRemoveEmptyNgons
    );

  /*
  Description:
    Calls the detailed version of DeleteComponents() with
    bool bIgnoreInvalidComponents = true;
    bool bRemoveDegenerateFaces = false;
    bool bRemoveUnusedVertices = true;
    bool bRemoveEmptyNgons = true;
  */
  bool DeleteComponents(
    const ON_COMPONENT_INDEX* ci_list,
    size_t ci_count
    ) override;

  /*
  Description:
    Calls the detailed version of DeleteComponents() with
    bool bIgnoreInvalidComponents = true;
    bool bRemoveDegenerateFaces = false;
    bool bRemoveUnusedVertices = true;
    bool bRemoveEmptyNgons = true;
  */
  bool DeleteComponents(
    const ON_SimpleArray<ON_COMPONENT_INDEX>& ci_list
    );

  /*
  Description:
    Calls the detailed version of DeleteComponents() with
    bool bIgnoreInvalidComponents = true;
    bool bRemoveDegenerateFaces = false;
    bool bRemoveUnusedVertices = true;
    bool bRemoveEmptyNgons = true;
  */
  bool DeleteComponent(
    ON_COMPONENT_INDEX ci
    );

  /*
  Description:
    Copy the subset of the mesh idenfied in the component list.
   Parameters:
     ci_list - [in]
     ci_count - [in]
       ci_list[] is an array of ci_count components that identify the
       parts of the mesh to copy.  If a face or ngon is specified, then
       any vertices or faces needed for a valid copy are automatically
       copied as well.
     destination_mesh - [in]
       If null, a new mesh is allocated for the copy.
       If not null, the copy is put in this mesh.
  Return:
    null - invalid input - no copy created
    not null - a pointer to the copy.
  */
  ON_Mesh* CopyComponents(
    const ON_COMPONENT_INDEX* ci_list,
    size_t ci_count,
    class ON_Mesh* destination_mesh
    ) const;

  /*
  Description:
    Copy the subset of the mesh idenfied in the component list.
   Parameters:
     ci_list - [in]
       ci_list[] is an array of ci_count components that identify the
       parts of the mesh to copy.  If a face or ngon is specified, then
       any vertices or faces needed for a valid copy are automatically
       copied as well.
     destination_mesh - [in]
       If null, a new mesh is allocated for the copy.
       If not null, the copy is put in this mesh.
  Return:
    null - invalid input - no copy created
    not null - a pointer to the copy.
  */  
  ON_Mesh* CopyComponents(
    const ON_SimpleArray<ON_COMPONENT_INDEX>& ci_list,
    class ON_Mesh* destination_mesh
    ) const;

  // query
  int VertexCount() const;
  unsigned int VertexUnsignedCount() const;
  int FaceCount() const;
  unsigned int FaceUnsignedCount() const;
  int QuadCount() const; // number of faces that are quads
  int TriangleCount() const; // number of faces that are triangles
  int InvalidFaceCount() const; // number of face that have invalid m_vi[] values.
  bool HasVertexNormals() const; // normals at vertices
  bool HasFaceNormals() const;
  bool HasTextureCoordinates() const;
  bool HasSurfaceParameters() const;
  bool HasPrincipalCurvatures() const;
  bool HasVertexColors() const;

  /*
  Returns:
    True if the mesh has ngons.
  */
  bool HasNgons() const;

  /*
  Returns:
    Number of vertices that are hidden.
  */
  int HiddenVertexCount() const;

  bool GetCurvatureStats( 
         ON::curvature_style, 
         ON_MeshCurvatureStats& 
         ) const;

  void InvalidateVertexBoundingBox(); // Call if defining geometry is changed by 
                             // directly manipulating the m_V[] array.
  void InvalidateVertexNormalBoundingBox(); // Call if defining geometry is changed by 
                             // directly manipulating the m_N[] array.
  void InvalidateTextureCoordinateBoundingBox(); // Call if defining geometry is changed by 
                             // directly manipulating the m_T[] array.
  void InvalidateCurvatureStats(); // Call if defining geometry is changed by 
                             // directly manipulating the m_T[] array.
  void InvalidateBoundingBoxes(); // Invalidates all cached bounding box information.


  void Flip(); // reverses face orientations and flips vertex and face normals

  void FlipVertexNormals(); // reverses vertex normals
  void FlipFaceNormals(); // reverses face normals
  void FlipFaceOrientation(); // reverses face orientation (does nothing to normals)
  void FlipNgonOrientation(); // reverses ngon boundary direction

  void SetMeshParameters( const ON_MeshParameters& );
  const ON_MeshParameters* MeshParameters() const;
  void DeleteMeshParameters();

  
  bool UnitizeVertexNormals();
  bool UnitizeFaceNormals();
  bool CountQuads();

  /*
  Description:
    Splits all quads along the short diagonal.
  */
  bool ConvertQuadsToTriangles();

  /*
  Description:
    Splits non-planer quads into two triangles.

  Parameters:
    planar_tolerance - [in]
      If planar_tolerance >= 0, then a quad is split if its vertices
      are not coplaner.  

      If both planar_tolerance = ON_UNSET_VALUE and angle_tolerance_radians >= 0.0,
      then the planarity test is skipped.

      If both planar_tolerance = ON_UNSET_VALUE and angle_tolerance_radians = ON_UNSET_VALUE,
      then all quads are split.

  angle_tolerance_radians - [in]
      If angle_tolerance_radians >= 0.0, then a quad is split if the
      angle between opposite corner normals is > angle_tolerance_radians.
      The corner normal is the normal to the triangle  formed by two
      adjacent edges and the diagonal connecting their endpoints.
      A quad has for corner normals.

      If both angle_tolerance_radians = ON_UNSET_VALUE and planar_tolerance >= 0.0,
      then the corner normal angle test is skipped.

      If both planar_tolerance = ON_UNSET_VALUE and angle_tolerance_radians = ON_UNSET_VALUE,
      then all quads are split.

    split_method - [in]
      0 default 
         Currently divides along the short diagonal. This may be
         changed as better methods are found or preferences change.
         By passing zero, you let the developers of this code
         decide what's best for you over time.
      1 divide along the short diagonal
      2 divide along the long diagonal
      3 minimize resulting area
      4 maximize resulting area
      5 minimize angle between triangle normals
      6 maximize angle between triangle normals

  bDeleteNgonsContainingSplitQuads - [in]
    If true, ngons that contain a split quad are deleted.

  Returns:
    Number of quads that were converted to triangles.
  */
  unsigned int ConvertNonPlanarQuadsToTriangles(
    double planar_tolerance,
    double angle_tolerance_radians,
    unsigned int split_method
    );

  unsigned int ConvertNonPlanarQuadsToTriangles(
    double planar_tolerance,
    double angle_tolerance_radians,
    unsigned int split_method,
    bool bDeleteNgonsContainingSplitQuads
    );

  /*
  Description:
    Joins adjacent triangles into quads if the resulting quad
    is nice.
  Parameters:
    angle_tol_radians - [in] Used to compare adjacent
      triangles' face normals.  For two triangles to be considered,
      the angle between their face normals has to be <= angle_tol_radians.
      When in doubt use ON_PI/90.0 (2 degrees).
    min_diagonal_length_ratio - [in] ( <= 1.0) For two triangles to be
       considered the ratio of the resulting quad's diagonals
       (length of the shortest diagonal)/(length of longest diagonal).
       has to be >= min_diagonal_length_ratio.
       When in doubt us .875.
  */
  bool ConvertTrianglesToQuads(
    double angle_tol_radians,
    double min_diagonal_length_ratio
    );

  bool ComputeFaceNormals();   // compute face normals for all faces
  bool ComputeFaceNormal(int); // computes face normal of indexed face

  /*
  Description:
    Get a list of pairs of faces that clash.
  Parameters:
    max_pair_count - [in]
      If max_pair_count > 0, then at most this many pairs
      will be appended to the clashing_pairs[] array.
      If max_pair_count <= 0, then all clashing pairs
      will be appended to the clashing_pairs[] array.
    clashing_pairs - [out]
      The faces indices of clashing pairs are appended
      to this array. 
  Returns:
    Number of pairs appended to clashing_pairs[].
  */
  int GetClashingFacePairs( 
    int max_pair_count,
    ON_SimpleArray< ON_2dex >& clashing_pairs
    ) const;

  /*
  Description:
    Cull clashing faces from the mesh.
  Parameters:
    what_to_cull - [in]
      0: when a pair of faces clash, cull both faces
      1: when a pair of faces clash, leave the face with the
         longest edge.
      2: when a pair of faces clash, cull the face with the
         longest edge.
      3: when a pair of faces clash, leave the face with
         the largest area.
      4: when a pair of faces clash, cull the face with
         the largest area.
  Returns:
    Number of faces culled from the mesh.
  Remarks:
    If a large face clashes with many small faces, the large
    face and one small face will be removed.  When a degenerate
    face is encountered, it is also culled.
  */
  int CullClashingFaces( int what_to_cull );

  unsigned int CullDegenerateFaces(); // returns number of degenerate faces

  int CullUnusedVertices(); // returns number of culled vertices

  // Description:
  //   Removes any unreferenced objects from arrays, reindexes as needed,
  //   and shrinks arrays to minimum required size.
  bool Compact();

  /*
  Description:
    Removes and unsets all possible cached information and 
    then calls Compact().
  Parameters:
    bRemoveNgons - [in]
      If true, all n-gon information is removed.
    bRemoveDegenerateFaces - [in]
      If true, CullDegenerateFaces() is used to remove degenerate faces.
    bCompact - [in]
      If true, Compact() is called after removing cached information.
  */
  void Cleanup(
    bool bRemoveNgons,
    bool bRemoveDegenerateFaces,
    bool bCompact
    );

  /*
  Description:
    Calls the latest version of the detailed cleanup command passing the value for bRemoveNgons
    and setting all other parameters to true.
  Parameters:
    bRemoveNgons - [in]
      If true, all n-gon information is removed.
  */
  void Cleanup(
    bool bRemoveNgons
    );

  bool ComputeVertexNormals();    // uses face normals to cook up a vertex normal
  
  //////////
  // Scales textures so the texture domains are [0,1] and
  // eliminates any texture rotations.
  bool NormalizeTextureCoordinates();

	/////////
	// Description:
	//		Transposes the texture coordinates
	//  Returns
	//			true  -  success
	bool TransposeTextureCoordinates();
	bool TransposeSurfaceParameters();
 
	/////////
	// Description:
	//		Reverse one coordinate direction of the texture coordinates, within texture domain m_tex_domain
	//	Parameters:
	//		dir  -[in]	-   dir=0  first texture coordinate is reversed
	//									  dir=1 second texture coordinate is reversed
	//  Returns
	//			true  -  success
	bool ReverseTextureCoordinates( int dir );
	bool ReverseSurfaceParameters( int dir );
 


  /*
  Description:
    Use a texture mapping function to set the m_T[] values.
  Parameters:
    mapping - [in]
    mesh_xform - [in]
      If not nullptr, the mapping calculation is performed as
      if the mesh were transformed by mesh_xform; the
      location of the mesh is not changed.
    bLazy - [in]
      If true and the m_T[] values were set using the same
      mapping parameters, then no calculation is performed.
  Returns:
    True if successful.
  See Also:
    ON_TextureMapping::GetTextureCoordinates
  */
  bool SetTextureCoordinates( 
          const class ON_TextureMapping& mapping,
					const class ON_Xform* mesh_xform = 0,
          bool bLazy = true
          );

  bool HasCachedTextureCoordinates() const;

  const ON_TextureCoordinates* CachedTextureCoordinates( 
          const ON_UUID& mapping_id 
          ) const;

  const ON_TextureCoordinates* SetCachedTextureCoordinates( 
          const class ON_TextureMapping& mapping,
					const class ON_Xform* mesh_xform = 0,
          bool bLazy = true
          );

  bool EvaluateMeshGeometry( const ON_Surface& ); // evaluate surface at tcoords
                                                  // to set mesh geometry

  // finds all coincident vertices and merges them if break angle is small enough
  bool CombineCoincidentVertices( 
          ON_3fVector, // coordinate tols for considering vertices
                       // to be coincident
          double  // cosine normal angle tolerance in radians
                  // if vertices are coincident, then they are combined
                  // if NormalA o NormalB >= this value
          );

  /*
  Description:
    Combines identical vertices.
  Parameters:
    bIgnoreVertexNormals - [in] If true, then vertex normals
      are ignored when comparing vertices.
    bIgnoreTextureCoordinates - [in] If true, then vertex
      texture coordinates, colors, and principal curvatures
      are ignored when comparing vertices.
  Returns:
    True if the mesh is changed, in which case the returned
    mesh will have fewer vertices than the input mesh.
  */
  bool CombineIdenticalVertices(
          bool bIgnoreVertexNormals = false,
          bool bIgnoreTextureCoordinates = false
          );

  void Append( const ON_Mesh& ); // appends a copy of mesh to this and updates
                                 // indices of appended mesh parts

  /*
  Description:
    Append a list of meshes. This function is much more efficient
    than making repeated calls to ON_Mesh::Append(const ON_Mesh&)
    when lots of meshes are being joined into a single large mesh.
  Parameters:
    count - [in]
      length of meshes[] array.
    meshes - [in]
      array of meshes to append.
  */
  void Append( int count, const ON_Mesh* const* meshes );
  
  /*
  Description:
    Expert user function to set m_is_closed member.  
    Setting this value correctly after a mesh is constructed 
    can save time when IsClosed() is called.
    This function sets the private member variable m_is_closed.
  Paramters:
    closed - [in]
      0: The mesh is not closed.  There is at least one face with an 
         edge that is geometrically distinct (as an unoriented line segment)
         from all other edges.
      1: The mesh is closed.  Every geometrically distict edge is used
         by two or more faces.
  */
  void SetClosed(int closed);

  /*
  Returns:
    True if every mesh "edge" has two or more faces.
  */
  bool IsClosed() const;

  /*
  Returns:
    True if every mesh "edge" has at most two faces.
  */
  bool IsManifold() const;

  /*
  Returns:
    True if the mesh is manifold and every pair of faces
    that share an "edge" have compatible orientations.
  */
  bool IsOriented() const;

  /*
  Description:
    Determine if the mesh is a manifold.
  Parameters:
    bTopologicalTest - [in]
      If true, the query treats coincident vertices as
      the same.
    pbIsOriented - [out]
      If the input pointer is not nullptr, then the returned
      value of *pbIsOriented will be true if the mesh
      is a manifold and adjacent faces have compatible
      face normals.
    pbHasBoundary - [out]
      If the input pointer is not nullptr, then the returned
      value of *pbHasBoundary will be true if the mesh
      is a manifold and there is at least one "edge"
      with no adjacent faces have compatible
      face normals.
  Returns:
    True if every mesh "edge" has at most two adjacent faces.
  */
  bool IsManifold(
    bool bTopologicalTest,
    bool* pbIsOriented = nullptr,
    bool* pbHasBoundary = nullptr
    ) const;

  /*
  Description:
    Expert user function to set m_is_solid member.  
    Setting this value correctly after a mesh is constructed 
    can save time when IsSolid() is called.
    This function sets the private member variable m_is_solid.
    If solid is nonzero, it will set m_is_closed to 1.
  Paramters:
    solid - [in]
      0: The mesh is not an oriented manifold solid mesh. Either
         the mesh is not closed, not manifold, or the faces are
         not oriented compatibly.
      1: The mesh is an oriented manifold solid whose face normals
         point outwards.
     -1: The mesh is an oriented manifold solid whose face normals
         point inwards.
  */
  void SetSolidOrientation(int solid_orientation);

  /*
  Description:
    Determine orientation of a mesh.
  Returns:
    +1     mesh is a solid with outward facing normals
    -1     mesh is a solid with inward facing normals
     0     mesh is not a solid
  See Also:
    ON_Mesh::IsSolid
  */
  int SolidOrientation() const;

  /*
  Description:
    Test mesh to see if it is a solid.  (A "solid" is
    a closed oriented manifold.)
  Returns:
    true       mesh is a solid
    fals       mesh is not a solid
  See Also:
    ON_Mesh::SolidOrientation
    ON_Mesh::IsManifold
  */
  bool IsSolid() const;

  /*
  Description:
    Determine if a point is inside a solid brep.
  Paramters:
    test_point - [in]
    tolerance - [in] >= 0.0
      3d distance tolerance used for ray-mesh intersection
      and determining strict inclusion.
    bStrictlyInside - [in] 
      If bStrictlyInside is true, then test_point must be inside mesh
      by at least tolerance in order for this function to return
      true. If bStrictlyInside is false, then this function will return
      true if test_point is inside or the distance from test_point to
      a mesh face is <= tolerance.
  Returns:
    True if test_point is inside the solid mesh.
  Remarks:
    The caller is responsible for making certing the mesh is
    solid before calling this function. If the mesh is not
    solid, the behavior is unpredictable.
  See Also:
    ON_Mesh::IsSolid()
  */
  bool IsPointInside(
          ON_3dPoint test_point, 
          double tolerance,
          bool bStrictlyInside
          ) const;

  /*
  Description:
    Appends a list of mesh edges that begin or end at the specified
    vertices to the edges[] array.
  Parameters:
    vcount - [in]
      number of vertices
    vertex_index - [in]
      array of vertex indices
    bNoDuplicates - [in]
      If true, then only one edges[] is added for each edge,
      the first vertex index will alwasy be less than the
      second, and the returned elements are sorted in dictionary
      order.
      If false and an edge is shared by multiple faces, then
      there will be an edges[] element added for each face and the
      order of the vertex indicies will indicate the orientation
      of the edge with respect to the face.  No sorting is performed
      in this case.
    edges - [out]
      Edges that begin or end at one of the specified vertices are
      appended to this array.  Each ON_2dex records the start and
      end vertex index.
  Returns:
    Number of ON_2dex values appended to the edges[] array.
  */
  int GetVertexEdges( 
    int vcount,
    const int* vertex_index, 
    bool bNoDuplicates,
    ON_SimpleArray<ON_2dex>& edges
    ) const;


  /*
  Description:
    Appends a list of mesh edges to the edges[] array.
  Parameters:
    edges - [out]
      Each edges[] element is a pair of vertex indices.  There
      is at least one face in the mesh with an edge running between
      the indicies.
  Returns:
    Number of ON_2dex values appended to the edges[] array.
  */
  int GetMeshEdges( 
    ON_SimpleArray<ON_2dex>& edges
    ) const;

  /*
  Description:
    Assign a unique id to each vertex location.  Coincident vertices
    get the same id.
  Parameters:
    first_vid - [in]
      Initial vertex id.  Typically 1 or 0.
    Vid - [out]
      If not null, then Vid[] sould be an array of length VertexCount().
      and the vertex ids will be stored in this array.  If null,
      the array will be allocated by calling onmalloc().  The returned
      array Vid[i] is the id of the vertex m_V[i].  If m_V[i] and
      m_V[j] are the same 3d point, then Vid[i] and Vid[j] will have
      the same value.
    Vindex - [out] (can be null)
      If Vindex is not null, then it must have length at least m_V.Count()
      and the returned array will be a permutation of (0,1,...,m_V.Count()-1)
      such (Vid[Vindex[0]], Vid[Vindex[1]], ..., Vid[Vindex[m_V.Count()-1]])
      is an increasing list of value.
  Returns:
    null if the mesh has no vertices.
    An array of length VertexCount(). If vertices m_V[i] and m_V[j]
    are coincident, then Vid[i] = Vid[j].  The id values begin at first_vid.
    The maximum vertex id is Vid[Vindex[m_V.Count()-1]].  The number of
    unique vertex locations is (Vid[Vindex[m_V.Count()-1]] - first_vid + 1).
  */
  unsigned int* GetVertexLocationIds( 
    unsigned int first_vid,
    unsigned int* Vid,
    unsigned int* Vindex
    ) const;

  /*
  Description:
    Get a list of the sides of every face.
  Parameters:
    Vid - [in] (can be null)
      If Vid is null, then the mesh m_V[] index values are used to set
      the ON_MeshFaceSide::vi[] values.
      If Vid is not null, then it must be an array of length VertexCount().
      The value Vid[mesh m_V[] index] will be used to set the
      ON_MeshFaceSide::vi[] values.
    sides - [out]
      If the input value of sides is not null, then sides[] must be long 
      enough to hold the returned side list.  The maximum posssible length
      is 4*FaceCount() for a mesh contining FaceCount() nondegenerate quads.
      If the input value of sides is null, memory will be allocated using
      onmalloc() and the caller is responsible for calling onfree() at an
      appropriate time.  This function fills in the sides[] array
      with face side information.  The returned list is sorted by sides[].fi
      and the sides[].side and each element has vi[0] <= vi[1].  
      The function ON_SortMeshFaceSidesByVertexIndex() can be used to sort the 
      list by the sides[].vi[] values.
  Returns:
    Number of elements added to sides[].
  Remarks:
    Faces with out of range ON_MeshFace.vi[] values are skipped. 
    Degenerate faces are processed, but degenerate sides (equal vertex indices)
    are not added to the list.
  */
  unsigned int GetMeshFaceSideList( 
      const unsigned int* Vid,
      class ON_MeshFaceSide*& sides
      ) const;


  ///////////////////////////////////////////////////////////////////////
  //
  // mesh editing
  //

  /*
  Description:
    Replace a mesh edge with a vertex at its center and update
    adjacent faces as needed.
  Parameters:
    topei - [in] index of edge in MeshTopology().m_tope[] array
  Returns:
    true if successful.
  */
  bool CollapseEdge( int topei );

  /*
  Description:
    Tests a mesh edge to see if it is valid as input to
    ON_Mesh::SwapMeshEdge.
  Parameters:
    topei - [in] index of edge in MeshTopology().m_tope[] array
  Returns:
    true if edge can be swapped by ON_Mesh::SwapMeshEdge.
  See Also:
    ON_Mesh::SwapEdge
  */
  bool IsSwappableEdge( int topei );


  /*
  Description:
    If the edge is shared by two triangular face, then
    the edge is "swapped".
  Parameters:
    topei - [in] index of edge in MeshTopology().m_tope[] array
  Returns:
    true if successful
  See Also:
    ON_Mesh::IsSwappableEdge
  */
  bool SwapEdge( int topei );

  /*
  Description:
    Removes a face from a mesh and does not alter the
    geometry of the remaining mesh.
  Parameters:
    meshfi - [in] index of face in ON_Mesh.m_F[] array
  Remarks:
    This function calls DestroyTopology() and DestroyPartition().
    The caller is responsible for calling Compact() if that step
    is required.
  Returns:
    true if successful
  */
  bool DeleteFace( int meshfi );

  /*
  Description:
    Destroys the m_H[] array and sets m_hidden_count=0.
  */
  void DestroyHiddenVertexArray();

  /*
  Returns:
    If the mesh has some hidden vertices, then an array
    of length VertexCount() is returned and the i-th
    element is true if the i-th vertex is hidden.
    If no vertices are hidden, nullptr is returned.
  */
  const bool* HiddenVertexArray() const;

  /*
  Description:
    Set the runtime vertex hidden flag.
  Parameters:
    meshvi - [in] mesh vertex index
    bHidden - [in] true to hide vertex
  */
  void SetVertexHiddenFlag( int meshvi, bool bHidden );

  /*
  Description:
    Returns true if the mesh vertex is hidden.  This is a runtime
    setting that is not saved in 3dm files.
  Parameters:
    meshvi - [in] mesh vertex index.
  Returns:
    True if mesh vertex is hidden.
  */
  bool VertexIsHidden( int meshvi ) const;

  /*
  Description:
    Returns true if the mesh face is hidden.  This is a runtime
    setting that is not saved in 3dm files.
  Parameters:
    meshfi - [in] mesh face index.
  Returns:
    True if mesh face is hidden.
  Remarks:
    A face is hidden if, and only if, at least one of its
    vertices is hidden.
  */
  bool FaceIsHidden( int meshvi ) const;


  ///////////////////////////////////////////////////////////////////////
  //
  // mesh topology
  //
  // In order to keep the mesh facet definition simple and make the mesh
  // definition easily used in common rendering application, if two facets
  // share a vertex location but have different normals, curvatures, 
  // textures, etc., at that common vertex location, then the vertex is
  // duplicated.  When the topology of the mesh needs to be known,
  // use Topology() to get a class that provides complete topological
  // information about the mesh.
  const ON_MeshTopology& Topology() const;

  ///////////////////////////////////////////////////////////////////////
  // If you modify the mesh in any way that may change its topology,
  // then call DestroyTopology().  Specifically if you add or remove
  // vertices or face, change vertex locations, or change the face m_vi[]
  // values, then you must call DestroyTopology().
  void DestroyTopology();

  /*
  Returns:
    This is an expert user function that returns true if the topology
    information is already calculated and cached.  It can be used to
    to avoid calling the Topology() function when the expensive creation
    step will be performed.
  */
  /* obsolete - used HasMeshTopology() */ bool TopologyExists() const;
  bool HasMeshTopology() const;

  ///////////////////////////////////////////////////////////////////////
  //
  // mesh partitions
  //
  // In ancient times, some rendering engines were only able to process
  // small batches of triangles and th CreatePartition() function was
  // provided to partition the mesh into subsets of vertices and faces
  // that those renering engines could handle.
  //
  const ON_MeshPartition* CreatePartition( 
                int, // maximum number of vertices in a partition
                int  // maximum number of triangles in a partition
                );
  const ON_MeshPartition* Partition() const;
  void DestroyPartition();

  /*
  Description:
    Extract the portion of this mesh defined by mesh_part.
  Parameters:
    mesh_part - [in]
      defines portion of the mesh to extract.
    mesh - [in] (can be null, cannot be = "this).
      If mesh is no null, the extracted mesh will be put into
      this mesh.  If mesh is null, the extracted mesh will
      be created in a mesh allocated on the heap using the
      new operator.
  Returns:
    A pointer to the submesh.  If the input mesh parameter is null,
    then the caller must delete this mesh when it is no longer needed.
    If the input is invalid, then null is returned.
  */
  ON_Mesh* MeshPart( 
    const ON_MeshPart& mesh_part,
    ON_Mesh* mesh 
    ) const;

  /*
  Description:
    Create a mesh that is a single face of this mesh.
  Parameters:
  Returns:
    A pointer to the submesh.  If the input mesh parameter is null,
    then the caller must delete this mesh when it is no longer needed.
    If the input is invalid, then null is returned.
  */
  ON_Mesh* DuplicateFace( 
    int face_index,
    ON_Mesh* mesh 
    ) const;

  ///////////////////////////////////////////////////////////////////////
  //
  // mesh N-gon lists.  
  //   ON_Mesh objects support faces that are triangle or quads.
  //   When a mesh is created from a format that supports N-gons
  //   for N larger than 4, an optional N-gon list can be added 
  //   that specifies the vertices and faces that make up the N-gon.
  //

  /*
  Description:
    If the mesh has an N-gon list, return a pointer to it.
  Returns:
    A pointer to the current N-gon list or nullptr.
  */
  const class ON_V4V5_MeshNgonList* V4V5_NgonList() const;

  /*
  Description:
    If an N-gon list exists, it is returned and can be modified.
    If no N-gon list exists, a new empty list is returned and
    it can be modified.
  Returns:
    A pointer to the N-gon list that can be modified.
  */
  class ON_V4V5_MeshNgonList* V4V5_ModifyNgonList();

  /*
  Description:
    Destroy any existing N-gon list.
  */
  void V4V5_DestroyNgonList();

  ///////////////////////////////////////////////////////////////////////
  //
  // mesh components
  //   ON_Mesh objects can consist of sets of faces that are isolated
  //   from any other sets of faces.  The following 2 functions will
  //   dissect a mesh into these sets, called components.  Not to be 
  //   confused with ON_COMPONENT_INDEX.

  /*
    Description:
      Calculates the components of a mesh and sets a label for each face in
      the facet_component_labels array.
    Parameters:
      bUseVertexConnections- [in]
        If this parameter is true, then facets that share a common vertex
        are considered connected.
        If this parameter is false, then facets must share an edge to
        be considered connected.
      bUseTopologicalConnections - [in]
        If this parameter is true, then geometric location is used
        to determine if facets are connected. 
        If this parameter is false, then facets must share the same vertex 
        or vertices to be considered connected.
      facet_component_labels- [out]
        facet_component_labels[] will be an array with the same size
        as ON_Mesh.m_F.Count() and facet_component_labels[i]
        is the component id m_F[i] belongs to.  The component id
        will be 1 to the number of compoents.
    Returns:
      Number of components on success, 0 on failure 
  */

  int GetConnectedComponents( bool bUseVertexConnections, 
                              bool bTopologicalConnections, 
                              ON_SimpleArray<int>& facet_component_labels
                            ) const;

  /*
    Description:
      Calculates the components of a mesh and sets a label for each face in
      the facet_component_labels array.
    Parameters:
      bUseVertexConnections- [in]
        If this parameter is true, then facets that share a common vertex
        are considered connected.
        If this parameter is false, then facets must share an edge to
        be considered connected.
      bUseTopologicalConnections - [in]
        If this parameter is true, then geometric location is used
        to determine if facets are connected. 
        If this parameter is false, then facets must share the same vertex 
        or vertices to be considered connected.
      components   - [out]
        New components are appended to this array
        if this parameter is null, then the components are just counted.
    Returns:
      Number of components on success, 0 on failure 
  */

  int GetConnectedComponents( bool bUseVertexConnections, 
                              bool bTopologicalConnections, 
                              ON_SimpleArray<ON_Mesh*>* components
                            ) const;


  /////////////////////////////////////////////////////////////////
  // 
  // Double precision vertex support
  // 

  /*
  Returns:
    True if the mesh vertex count is > 0, the mesh has single and double 
    precision vertices, and the values of the locations are synchronized.
  */
  bool HasSynchronizedDoubleAndSinglePrecisionVertices() const;

  /*
  Returns:
    True if the mesh has double precision vertices (m_dV.Count() > 0).
  Remarks:
    Use ON_Mesh::UpdateDoublePrecisionVertices()
    or ON_Mesh::UpdateSinglePrecisionVertices() to synchronize
    values of single and double precision vertices.
  */
  bool HasDoublePrecisionVertices() const;

   bool HasSinglePrecisionVertices() const;


  /*
  Description:
    If you modify the values of double precision vertices,
    then you must call UpdateSinglePrecisonVertices().
  Remarks:
    If double precision vertices are not present, this function
    does nothing.
  */
  void UpdateSinglePrecisionVertices();

  /*
  Description:
    If you modify the values of the single precision vertices
    in m_V[], then you must call UpdateDoublePrecisionVertices().
  Remarks:
    If double precision vertices are not present, this function
    does nothing.
  */
  void UpdateDoublePrecisionVertices();

  /*
  Description:
    The function removes all double precision vertex information.
  */
  void DestroyDoublePrecisionVertices();


  /////////////////////////////////////////////////////////////////
  // Implementation - mesh geometry

  // Vertex locations
  //   In a case where adjacent facets share a vertex
  //   location but have distinct normals or texture
  //   coordinates at that location, the vertex must
  //   be duplicated.

  /*
  Description:
    Get double precision vertices.  If they do not exist,
    they will be created and match the existing single
    precision vertices.
  Returns:
    Array of double precision vertices.  If you modify the
    values in this array, you must make the same modifications
    to the single precision vertices, or call 
    UpdateSinglePrecisonVertices().
  Example:

          // add a bunch of double precision information
          ON_3dPointArray& dv = mesh.DoublePrecisionVertices();
          for ( i = 0; i < lots; i++ )
          {
            dv[i] = ...
          }
          // This call updates the single precison values
          // in m_V[] and sets all the counts and CRCs that
          // are used in validity checking.
          mesh.UpdateSinglePrecisonVertices();
    
  Remarks:
    Avoid mulitple calls to DoublePrecisionVertices().
    It is most efficient to make one call, save a local 
    reference, and use the local reference as needed.
  */
  ON_3dPointArray& DoublePrecisionVertices();
  const ON_3dPointArray& DoublePrecisionVertices() const;

  /*
  Description:
    m_dV[] double precision vertices.
    m_V[] single precision vertices.
    
    If m_dV[] is not empty, then m_V and m_dV should have the same length
    and HasSynchronizedDoubleAndSinglePrecisionVertices() should be true.

    Otherwise a bug incorrectly modified vertex location information.

    If m_dV[] and m_V[] are in use and you modify vertex locations or count,
    then your calculation should insure both are properly updated.
  */
  ON_3dPointArray m_dV;
  ON_3fPointArray m_V;

  /*
  Returns:
    Location of the vertex.  If double precision vertices
    are present, the double precision vertex location is
    returned.  If vertex_index is out of range,
    ON_UNSET_VALUE is returned.
  */
  ON_3dPoint Vertex(int vertex_index) const;

  // m_F[] facets (triangles or quads)
  ON_SimpleArray<ON_MeshFace> m_F;

  ////////////////////////////////////////////////////////////////////////
  //
  // N-gon
  //
  //   An n-gon is a collection of faces that are grouped together.
  //   The outer boundary of the face collection must be a closed
  //   polyline.
  //

  ////////////////////////////////////////////////////////////////////////
  //
  // N-gon interface
  //

  /*
  Number of n-gons in this mesh.
  */
  int NgonCount() const;

  /*
  Number of n-gons in this mesh.
  */
  unsigned int NgonUnsignedCount() const;

  /*
  Returns:
    null - This mesh does ot have n-gon information.
    not null - a pointer to an array of ON_MeshNgon pointers.
      The array has length ON_Mesh::NgonCount().
  Remarks:
    If ON_Mesh::RemoveNgon has been called, then the array
    can contain null pointers.
  */
  const ON_MeshNgon* const * Ngons() const;

  /*
  Parameters:
    ngon_index - [in]
      Index of an ngon.
  Returns:
    A pointetr to the indexed n-gon or null if the 
    indexed ngon is null or ngon_index is out of range.
  Remarks:
    If ON_Mesh::RemoveNgon has been called, then a null
    pointer can be returned even when ngon_index >= 0
    and ngon_index < ON_Mesh.NgonCount().
  */
  const ON_MeshNgon* Ngon(
    unsigned int ngon_index
    ) const;

  /*
  Parameters:
    ngon_index - [in]
      Index of an ngon.
  Returns:
    Total number of boundary edges, including interior edges
  */
  unsigned int NgonBoundaryEdgeCount(
    unsigned int ngon_index
  ) const;

  const ON_MeshNgon* NgonFromComponentIndex(
    class ON_MeshNgonBuffer& ngon_buffer,
    ON_COMPONENT_INDEX ci
    ) const;

  /*
  Description:
    Add a new ngon to the mesh.
  Parameters:
    Vcount - number of vertices and number of sides in the n-gon
    ngon_vi[] - in
      An array of N distinct ON_Mesh.m_V[] vertex indices
    Fcount - [in]
      Number of face that make up the ngon.
    ngon_fi[]
      An array of N distinct ON_Mesh.m_F[] face indices
      The outer boundary of this group of faces should
      be the list of vertices passes as ngon_vi[]
  Returns:
    index of the new n-gon.
    -1: If input information is not valid.
  */
  int AddNgon(
    unsigned int Vcount, 
    const unsigned int* ngon_vi,
    unsigned int Fcount, 
    const unsigned int* ngon_fi
    );

  bool ModifyNgon(
    unsigned int ngon_index,
    unsigned int Vcount, 
    const unsigned int* ngon_vi,
    unsigned int Fcount, 
    const unsigned int* ngon_fi
    );

  bool ModifyNgon(
    unsigned int ngon_index,
    const ON_MeshNgon* ngon
    );

  /*
  Description:
    Insert an n-gon in the ngon list.  This is generally
    slow.  Use AddNgon or ModifyNgon.
  */
  bool InsertNgon(
    unsigned int ngon_index,
    const ON_MeshNgon* ngon
    );

  /*
  Returns:
    Average of the n-gon vertex locations.
  */
  ON_3dPoint NgonCenter(
    unsigned int ngon_index
    ) const;

  /*
  Returns:
    Average of the n-gon vertex locations.
  */
  ON_3dPoint NgonCenter(
    const ON_MeshNgon* ngon
    ) const;

  /*
  Returns:
    Bounding box of the n-gon vertex locations.
  */
  ON_BoundingBox NgonBoundaryBoundingBox(
    unsigned int ngon_index
    ) const;

  /*
  Returns:
    Bounding box of the n-gon vertex locations.
  */
  ON_BoundingBox NgonBoundaryBoundingBox(
    const ON_MeshNgon* ngon
    ) const;

  /*
  Parameters:
    ngon - [in]
    bAppendStartPoint - [in]
      If true, the initial point in the boundary will be added
      as the first point of ngon_boundary_points[] and then
      added again as the last point of ngon_boundary_points[].
      This is useful when you need a closed polyline.
    ngon_boundary_points - [out]
      An array of ngon->m_Vcount + (bAppendStartPoint ? 1 : 0)
      points.
  Returns:
    Number of points added to ngon_boundary_points[] or 0 if invalid
    input is encountered.
  */
  unsigned int GetNgonBoundaryPoints(
    const ON_MeshNgon* ngon,
    bool bAppendStartPoint,
    ON_SimpleArray<ON_3dPoint>& ngon_boundary_points
    ) const;

  /*
  Parameters:
    ngon - [in]
    bAppendStartPoint - [in]
      If true, the initial point in the boundary will be added
      as the first point of ngon_boundary_points[] and then
      added again as the last point of ngon_boundary_points[].
      This is useful when you need a closed polyline.
    ngon_boundary_points - [out]
      An array of ngon->m_Vcount + (bAppendStartPoint ? 1 : 0) points
      is returned in ngon_boundary_points[].  The caller must insure
      that ngon_boundary_points[] has room for this many elements.
  Returns:
    Number of points added to ngon_boundary_points[] or 0 if invalid
    input is encountered.
  */
  unsigned int GetNgonBoundaryPoints(
    const ON_MeshNgon* ngon,
    bool bAppendStartPoint,
    ON_3dPoint* ngon_boundary_points
    ) const;

  /*
  Description:
    If the mesh has ngons with ON_MeshNgon.Orientation() = -1, 
    the reverse the ngon's boundary orientation.
  Parameters:
    bPermitHoles - [in]
      ngons may contain holes.
  Returns:
    True if all non-empty ngons have ON_MeshNgon.Orientation()=1 after the call.
  */
  bool OrientNgons(
    bool bPermitHoles
  );

  /*
  Description:
    Remove an n-gon.
  Parameters:
    ngon_index - [in]
  Returns:
    True if ngon_index was valid and the corresponding n-gon was removed.
  Remarks:
    The mesh triangles that make up the n-gon are not deleted.
  */
  bool RemoveNgon(
    unsigned int ngon_index
    );

  unsigned int RemoveNgons(
    unsigned int ngon_index_count,
    const unsigned int* ngon_index_list
    );

  /*
  Description:
  Remove null and empty entries from the ON_Mesh n-gon list.
  */
  void RemoveEmptyNgons();

  /*
  Description:
    Remove all entries from the ON_Mesh n-gon list.
  Remarks:
    Same as SetNgonCount(0)
  */
  void RemoveAllNgons();

  /*
  Description:
    Set the n-gon count. Null n-gons are be appended
    when ngon_count > current count.  Existing n-gons are
    removed when ngon_count < current count.
  Parameters:
    ngon_count - [in]
      Number of n-gons to have.
      0: removes all ngons.
  Remarks:
    The mesh triangles that make up any removed n-gons are not deleted.
  */
  void SetNgonCount(
    unsigned int ngon_count
    );

  /*
  Parameters:
    face_index - [in]
      Mesh face ON_Mesh.m_F[] index.
  Returns:
    ON_UNSET_UINT_INDEX:
       The face is not part of an n-gon.
    Otherwise:
      Index of the n-gon the face is part of.
  */
  unsigned int NgonIndexFromFaceIndex(
    unsigned int face_index
    ) const;

  /*
  Returns:
    null: 
      The ngonMap does not exist.
    an array of length m_F.Count():
      The value of the i-th element is either the index of the n-gon
      the mesh face m_F[i] belongs to or ON_UNSET_UINT_INDEX when
      m_F[i] does not belong to an n-gon.
  */
  const unsigned int* NgonMap() const;

  const unsigned int* NgonMap(
    bool bCreateIfMissing
    );

  /*
  Returns:
    true if the n-gon information is valid for adding an n-gon to this mesh.
  Parameters:
    Vcount - [in]
       Number of vertices and sides in the n-gon.
    ngon_vi - [in]
  */
  bool IsValidNewNgonInformation(
    unsigned int Vcount, 
    const unsigned int* ngon_vi,
    unsigned int Fcount, 
    const unsigned int* ngon_fi
    ) const;

  /*
  Description:
    For each set of coplanar connected faces in the mesh that
    qualifies as an n-gon, an new ON_MeshNgon will be appended 
    to the Ngons[] array.  Faces belonging to existing ngons are 
    ignored.
  Parameters:
    vertex_face_map - [in]
      - Pass null if you don't have one.
      - See ON_MeshVertexFaceMap for details about making one.
        The only reason to pass one in is because you
        need it for other reasons or you already have one.
    planar_tolerance - [in] 
      For faces to be coplanar, all the points in the
      n-gon must be withing planar_tolerance of the plane
      defined by the first face in the n-gon.
    minimum_ngon_vertex_count - [in]
      n-gons must have at least this many sides in order
      to be added.
    minimum_ngon_face_count - [in]
      n-gons must have at least this many faces in order to
      be added.
    bAllowHoles - [in]
      If true, then the added ngons are permitted to have holes.
    bSeparateNgons - [in]
      If true, any face belonging to a new ngon, will not
      share vertices with a face that does not belong to that
      ngon and the vertex normals for all vertices in an ngon will
      be set to the plane's normal.
    bSetNgonVertexNormals - [in]
      If bSeparateNgons and bSetNgonVertexNormals are both true,
      then all vertex normals vertices in a new ngon will be
      set to the ngon's plane normal.
    bRemoveNgonInteriorPoints - [in]
      If true, the new ngons will not have interior vertices.
      This will result in the ngon being retriangluated
      when connected coplanar faces 
  Returns:
    The number of new n-gons appended to m_Ngons[]
  */
  unsigned int AddPlanarNgons(
    const unsigned int *const* vertex_face_map,
    double planar_tolerance,
    unsigned int minimum_ngon_vertex_count,
    unsigned int minimum_ngon_face_count,
    bool bAllowHoles
    );

  /*
  Description:
    For each ngon with index in the specified range,
    duplicate vertices as needed so that the ngon
    does not share any vertices with faces that do not
    belong to the ngon.
  Parameters:
    vertex_face_map - [in]
      - Pass null if you don't have one.
      - See ON_MeshVertexFaceMap for details about making one.
        The only reason to pass one in is because you
        need it for other reasons or you already have one.
      - Note that if true is returned, then the information
        in this vertex_face_map will be changed and no
        information will be added for the new vertices.
     ngon_index0 - [in]
     ngon_index1 - [in]
       ngons with indices ni satisfying 
       ngon_index0 <= ni < ngon_index1 will be separated.
       To separate every ngon in a mesh, pass
       ngon_index0 = 0 and ngon_index1 = mesh->NgonCount().    
  Returns:
    true 
      one or more vertices were duplicated to separate an ngon
      from it's neighboring faces. This changes the mesh's 
      vertex and face information and invalidates any input
      vertex_face_map.
    false
      The mesh was not modified.
  */
  bool SeparateNgons(
    unsigned int** vertex_face_map,
    unsigned int ngon_index0,
    unsigned int ngon_index1
    );

  /*
  Description:
    For each ngon with index in the specified range,
    all vertices in the ngon will have their vertex normal
    set to the normal of the first face in the ngon.
  Parameters:
     ngon_index0 - [in]
     ngon_index1 - [in]
       ngons with indices ni satisfying 
       ngon_index0 <= ni < ngon_index1 will be separated.
       To separate every ngon in a mesh, pass
       ngon_index0 = 0 and ngon_index1 = mesh->NgonCount().    
  Returns:
    true 
      one or more vertices were duplicated to separate an ngon
      from it's neighboring faces. This changes the mesh's 
      vertex and face information and invalidates any input
      vertex_face_map.
    false
      The mesh was not modified.
  */
  bool SetNgonVertexNormals(
    unsigned int ngon_index0,
    unsigned int ngon_index1
    );

  /*
  Description:
    For each ngon with index in the specified range that has
    interior vertices, remove the interior vertices and
    triangluate the ngon.
  Parameters:
    vertex_face_map - [in]
      - Pass null if you don't have one.
      - See ON_MeshVertexFaceMap for details about making one.
        The only reason to pass one in is because you
        need it for other reasons or you already have one.
      - If true is returned, then the information
        in this vertex_face_map will be invalid because
        vertices will be removed.
     ngon_index0 - [in]
     ngon_index1 - [in]
       ngons with indices ni satisfying 
       ngon_index0 <= ni < ngon_index1 will be separated.
       To separate every ngon in a mesh, pass
       ngon_index0 = 0 and ngon_index1 = mesh->NgonCount().    
  Returns:
    true 
      one or more vertices were removed and one or more ngons
      were triangluated. This changes the mesh's vertex and face
      information and invalidates any input vertex_face_map.
    false
      The mesh was not modified.
  Remarks:
    If true is returned and you are finished modify the mesh, then
    call ON_Mesh::Compact() or ON_Mesh::CullUnusedVertices() to remove
    the unreferenced interior vertices.
  */
  bool RemoveNgonInteriorVertices(
    const unsigned int *const* vertex_face_map,
    unsigned int ngon_index0,
    unsigned int ngon_index1
    );

  /*
  Descrption:
    Given a group of connected coplanar faces,
    find the n-gon boundary.
  ngon_fi_count - [in]
    number of indices in ngon_fi[]
  ngon_fi - [in]
    Indices of faces in the ON_Mesh.m_F[] array.
  ngon_vi - [out]
    An ordered list of indices of vertices in the ON_Mesh.m_V[] 
    array that for the outer boundary of the n-gon.  The natural
    counter-clockwise orientation of the first face with a 
    boundary edge determines the order of the ngon_vi[] list.
  */
  unsigned int GetNgonOuterBoundary(
    unsigned int ngon_fi_count,
    const unsigned int* ngon_fi,
    ON_SimpleArray<unsigned int>& ngon_vi
    ) const;
  
  /*
  Description:
    An expert user function that allocates an ngon from heap
    memory managed by this ON_Mesh.
  Parameters:
    N - [in] (>= 3)
    Fcount - [in]
  Returns:
    A pointer to an uninitialized ngon.
    Use the ON_Mesh::AddNgon(ngon) to add this ngon to the mesh
    or use DeallocateNgon(ngon) to deallocate the ngon.
  */
  ON_MeshNgon* AllocateNgon(
    unsigned int Vcount, 
    unsigned int Fcount
    );

  /*
  Description:
    An expert user function that deallocates an ngon
    that was created by AllocateNgon().
  Parameters:
    ngon - [in]
  */
  bool DeallocateNgon(
    ON_MeshNgon* ngon
    );

  /*
  Description:
    An expert user function that unconditionally appends the ngon
    pointer to ON_Mesh.m_Ngon[].
  Parameters:
    ngon - [in]
  Returns:
      ON_UNSET_UINT_INDEX: invalid input
    < ON_UNSET_UINT_INDEX: index of the new n-gon.
  */
  unsigned int AddNgon(
    ON_MeshNgon* ngon
    );

  /*
  Description:
    Expert user function to update n-gon map after the expert user
    does something to make the current one invalid.
  Returns:
    null: 
      The mesh does not have ngon-information.
    an array of length m_F.Count() ngon_map[]
      - If ngon_map[fi] >= 0, then ON_MeshFace.m_F[fi] belongs
        to ON_Mesh.Ngon(ngon_map[fi]).
      - Otherwise, ngon_map[fi] = -1.
  */
  const unsigned int* CreateNgonMap();
  

  /*
  Description:
    Expert user function to delete n-gon map information
    but leave n-gon definition information unchanged.
  Description:
    Removes any existing n-gon map.
    Does not remove other n-gon information.
  */
  void RemoveNgonMap();

  ////////////////////////////////////////////////////////////////////////
  //
  // N-gon implementation
  //

  // If ON_Mesh::HasNgons() is true, then the mesh has n-gons.
  // When a mesh has ngons, m_NgonMap[] is used to determine when
  // a face belongs to an n-gon.
  // If m_NgonMap[fi] < m_Ngon.UnsignedCount(), then it is the index of the N-gon in m_Ngon[] 
  // that m_F[]  belongs to.  Otherwise, m_NgonMap[fi] is ON_UNSET_UINT_INDEX.
  ON_SimpleArray<unsigned int> m_NgonMap; // invalid if m_NgonMap.Count() != m_F.Count()
  ON_SimpleArray<ON_MeshNgon*> m_Ngon;
  ON_MeshNgonAllocator m_NgonAllocator; // use this to allocate elements added to m_Ngon;

  ////////////////////////////////////////////////////////////////////////
  //
  // Vertex and Face normal implementation
  //

  // m_N[] OPTIONAL vertex unit normals
  // If m_N[] is empty or m_N.Count() != m_V.Count(), 
  // Either m_N[] has zero count or it m_N[j] is the
  // the unit vertex normal at m_V[j].
  ON_3fVectorArray m_N;

  // m_FN[] OPTIONAL face unit normals
  // If m_FN[] is empty or m_FN.Count() != m_F.Count(), 
  // then m_FN is ignored.  Otherwise m_FN[j] is the
  // unit normal for the facet m_F[j].
  ON_3fVectorArray m_FN;

  /////////////////////////////////////////////////////////////////
  // Implementation - texture coordinates
  //
  // OPTIONAL texture coordinates for each vertex

  // It would be nice if this were an ON_TextureCoordinates,
  // but that breaks lots of checked out code that assumes
  // m_T is an array of ON_2fPoints.
  ON_MappingTag m_Ttag; // OPTIONAL tag for values in m_T[]
  ON_2fPointArray m_T;  // OPTIONAL texture coordinates for each vertex

  // RUNTIME ONLY
  //   This array is used to cache texture coordinates used by
  //   rendering applications that require 1d texture coordinates,
  //   3d texture coordinates, or multiple sets of texture 
  //   coordinates (e.g. blended textures with different mappings).
  //   Users are responsible for verifying 
  //   m_TC[i].m_T.Count() = m_V.Count()
  ON_ClassArray<ON_TextureCoordinates> m_TC;  

  // If m_T.Count() == m_V.Count(), then the mesh has texture coordinates
  // and m_T[j] is the texture coordinate for vertex m_V[j].
  //
  // When opennurbs or Rhino meshes an ON_Surface or ON_Brep, the texture
  // coordinates have a "canonical" linear relationship with the surface 
  // parameters that is described in the next section.  However, various 
  // mappings, spherical, planar, cylindrical, etc., can be applied that 
  // change the values of the texture coordinates.
  //
  // If a texture mapping function was used to set the m_T[] values, 
  // then the id and serial number of the mapping function is saved
  // in m_mapping_id and m_mapping_sn. The intended use of these fields
  // is to make it easy to avoid unnecessary recalculation.  
  // If a mesh is modified, then m_mapping_id should be set to nil 
  // and m_mapping_crc should be set to 0.
  //
  /////////////////////////////////////////////////////////////////


  /////////////////////////////////////////////////////////////////
  // Implementation - surface parameters and packed texture 
  // information
  //
  // If m_S.Count() == m_V.Count(), then the mesh is a tesselation
  // of a parameteric surface and m_S[j] is the surface parameter at
  // m_V[j].  Storing values in m_S[] is OPTIONAL.
  //
  // If m_srf_scale[] has positive values, then they report
  // the world coordinate size of a rectangle that would 
  // minimize texture distortion if it were mapped to the
  // mesh using normalized surface evaluation parameters.
  // This information is used to calculate high quality 
  // packed texture coordinates.  
  ON_2dPointArray m_S;
  ON_Interval m_srf_domain[2]; // surface evaluation domain.
  double m_srf_scale[2];


  // Packed texture information.
  //
  // If either of the m_packed_tex_domain[] intervals is a 
  // proper subinterval of (0,1), then a texture packing 
  // calculation assigned this subrectangle to this mesh.

  ON_Interval m_packed_tex_domain[2];

  // The m_packed_tex_rotate setting is valid only when
  // m_S, m_srf_domain, m_packed_scale[] and 
  // m_packed_tex_domain[] are all valid and the texture
  // coordinates are based on surface evaluation parameters.
  // In this special situation, this boolean records the 
  // correspondence between the the surface parameters, (u,v),
  // and the packed texture coordinates, (s,t),
  //
  //   m_packed_tex_rotate = false:
  //     a = m_srf_domain[0].NormalizedParameterAt(u);
  //     b = m_srf_domain[1].NormalizedParameterAt(v);
  //     s = m_packed_tex_domain[0].ParameterAt(a);
  //     t = m_packed_tex_domain[1].ParameterAt(b);
  //
  //     x = m_packed_tex_domain[0].NormalizedParameterAt(s);
  //     y = m_packed_tex_domain[1].NormalizedParameterAt(t);
  //     u = m_srf_domain[0].ParameterAt(x);
  //     v = m_srf_domain[1].ParameterAt(y);
  //
  //   m_packed_tex_rotate = true:
  //     a = m_srf_domain[0].NormalizedParameterAt(u);
  //     b = m_srf_domain[1].NormalizedParameterAt(v);
  //     s = m_packed_tex_domain[0].ParameterAt(a);
  //     t = m_packed_tex_domain[1].ParameterAt(1.0-b);
  //
  //     x = m_packed_tex_domain[0].NormalizedParameterAt(s);
  //     y = m_packed_tex_domain[1].NormalizedParameterAt(t);
  //     u = m_srf_domain[0].ParameterAt(y);
  //     v = m_srf_domain[1].ParameterAt(1.0 - x);
  bool m_packed_tex_rotate;

  /*
  Returns:
    True if the m_srf_scale[] values are positive and
    the m_packed_tex_domain[] intervals are set to values
    that describe a proper subrectangle of (0,1)x(0,1).
    True does not necessarily mean the current values in
    m_T[] are packed texture coordinates.
  */
  bool HasPackedTextureRegion() const;

  /*
  Description:
    If the mesh does not have surface evaulation parameters,
    has texture coordinates, and the surface parameters can
    be set in a way so the existing texture coordinates can
    be computed from the surface parameters, then this function
    sets the surface parameters.  This is useful when meshes
    that have texture coordinates and do not have surface 
    parameters want ot set the surface parameters in a way
    so that the texture mapping
    ON_TextureMapping::SurfaceParameterTextureMapping
    will restore the texture coordinates.
  Returns:
    true - successful
    false - failure - no changes made to the mesh.
  */
  bool SetSurfaceParamtersFromTextureCoodinates();


  /////////////////////////////////////////////////////////////////
  // Implementation - curvature

  ON_SimpleArray<ON_SurfaceCurvature> m_K;  // OPTIONAL surface curvatures
                                            // Either m_K[] has zero count or it has the same
                                            // count as m_V[], in which case m_K[j] reports
                                            // the surface curvatures at m_V[j].

  /////////////////////////////////////////////////////////////////
  // Implementation - false color
  ON_MappingTag m_Ctag; // OPTIONAL tag for values in m_C[]
  ON_SimpleArray<ON_Color> m_C;  // OPTIONAL vertex color
                                 // Either m_C[] has zero count or it has the same
                                 // count as m_V[], in which case m_C[j] reports
                                 // the color assigned to m_V[j].

  /////////////////////////////////////////////////////////////////
  // Implementation - runtime vertex visibility - not saved in 3dm files.
  ON_SimpleArray<bool> m_H; // OPTIONAL vertex visibility.
                            // If m_H.Count() = m_V.Count(), then
                            // m_H[vi] is true if the vertex m_V[vi] 
                            // is hidden.  Otherwise, all vertices are visible.
  int m_hidden_count;       // number of vertices that are hidden
                            // = number of true values in m_H[] array.

  /////////////////////////////////////////////////////////////////
  // Implementation - runtime UI information
  const ON_Object* m_parent; // runtime parent geometry (use ...::Cast() to get it)

protected:

  /////////////////////////////////////////////////////////////////
  // Implementation - mesh topology
  ON_MeshTopology m_top;

  ON_MeshParameters* m_mesh_parameters; // If mesh was created from a parametric surface,
                                        // these parameters were used to create the mesh.
  int                         m_invalid_count;
  int                         m_quad_count;
  int                         m_triangle_count;

private:
  char m_mesh_is_closed;   // 0 = unset, 1 = all edges have 2 or more faces, 2 = at least one boundary edge 
  char m_mesh_is_manifold; // 0 = unset, 1 = all edges have 1 or 2 faces, 2 = not manifold
  char m_mesh_is_oriented; // 0 = unset, 1 = faces normals agree across all edges that have 2 faces, 2 = not oriented
  char m_mesh_is_solid;    // 0 = unset, 1 = solid with outward face normals, 2 = solid with inward face normals, 3 = not solid

private:
  mutable ON_BoundingBox m_vertex_bbox = ON_BoundingBox::UnsetBoundingBox;

protected:
  float m_nbox[2][3]; // 3d bounding box of all referenced unit normals 
                      // (for estimation of Gauss map bounds)
  float m_tbox[2][2]; // 2d bounding box of all referenced texture coordinates

private:
  // m_vertex_bbox = bounding box of vertex locations

  // cache of recently used tight bounding boxes
  mutable ON_BoundingBoxCache m_tight_bbox_cache;

protected:

  ON_MeshCurvatureStats* m_kstat[4]; // gaussian,mean,min,max,sectionx,sectiony,sectionz

  // sub-mesh information rendering large meshes
  ON_MeshPartition* m_partition;


private:
  bool Write_1( ON_BinaryArchive& ) const; // uncompressed 1.x format
  bool Write_2( int, ON_BinaryArchive& ) const; // compressed 2.x format
  bool Read_1( ON_BinaryArchive& );
  bool Read_2( int, ON_BinaryArchive& );
  bool WriteFaceArray( int, int, ON_BinaryArchive& ) const;
  bool ReadFaceArray( int, int, ON_BinaryArchive& );
  bool SwapEdge_Helper( int, bool );
};

//////////////////////////////////////////////////////////////////////////
//
// ON_MeshCache
//
class ON_CLASS ON_MeshCache
{
public:
  static const ON_MeshCache Empty;

  static const ON_UUID RenderMeshId;
  static const ON_UUID AnalysisMeshId;
  static const ON_UUID PreviewMeshId;
  static const ON_UUID AnyMeshId;

  // Cached mesh with the fewest faces
  static const ON_UUID CoarseMeshId;

  // Cached mesh with the most faces
  static const ON_UUID FineMeshId;

  /*
  Returns:
    The id that corresonds to the obsolete ON::mesh_type enum value.
  Remarks:
    Ids are used to allow custom meshes to be cached.
  */
  static ON_UUID MeshIdFromMeshType(
    ON::mesh_type mesh_type
    );

public:
  ON_MeshCache() = default;
  ~ON_MeshCache();
  ON_MeshCache( const ON_MeshCache& src );
  ON_MeshCache& operator=( const ON_MeshCache& src );

#if defined(ON_HAS_RVALUEREF)
  // rvalue copy constructor
  ON_MeshCache( ON_MeshCache&& ) ON_NOEXCEPT;

  ON_MeshCache& operator=( ON_MeshCache&& );
#endif

public:

  /*
  Parameters:
    mesh_id - [in]
      mesh_id cannot be nil or ON_MeshCache::AnyMeshId.
  */  
  void SetMesh(
    ON_UUID mesh_id,
    const std::shared_ptr<ON_Mesh>& mesh_sp
    );
  void SetMesh(
    ON::mesh_type mesh_type,
    const std::shared_ptr<ON_Mesh>& mesh_sp
    );
    
  /*
  Parameters:
    mesh_id - [in]
      If mesh_id is ON_MeshCache::AnyMeshId, then every cached mesh 
      will be deleted.
  */
  void ClearMesh(
    ON_UUID mesh_id
    );
  void ClearMesh(
    ON::mesh_type mesh_type
    );
  
  void ClearAllMeshes();

  /*
  Parameters:
    bDeleteMesh - [in]
      true 
        ON_Mesh will be deleted.
      false 
        ON_Mesh will not be deleted. This is typically done when the
        mesh was in the process of being created in a separate thread
        and memory pool, both of which were killed and the pointer
        to the mesh is no longer valid.
  */
  void ClearMesh(
    ON_UUID mesh_id,
    bool bDeleteMesh
    );

  /*
  Parameters:
    bDeleteMesh - [in]
      true 
        ON_Mesh will be deleted.
      false 
        ON_Mesh will not be deleted. This is typically done when the
        mesh was in the process of being created in a separate thread
        and memory pool, both of which were killed and the pointer
        to the mesh is no longer valid.
  */
  void ClearMesh(
    ON::mesh_type mesh_type,
    bool bDeleteMesh
    );
  

  /*
  Parameters:
    bDeleteMeshes - [in]
      true 
        ON_Mesh will be deleted.
      false 
        ON_Mesh will not be deleted. This is typically done when the
        mesh was in the process of being created in a separate thread
        and memory pool, both of which were killed and the pointer
        to the mesh is no longer valid.
  */
  void ClearAllMeshes(
    bool bDeleteMeshes
  );

  /*
  Parameters:
    mesh_id - [in]
      If mesh_id is ON_MeshCache::AnyMeshId, then the most recently cached mesh is returned.
  */
  const ON_Mesh* Mesh(
    ON_UUID mesh_id
    ) const;
  const ON_Mesh* Mesh(
    ON::mesh_type mesh_type
    ) const;


  /*
  Parameters:
    mesh_id - [in]
      If mesh_id is ON_MeshCache::AnyMeshId, then the most recently cached mesh is returned.
  */
  std::shared_ptr<ON_Mesh> MeshSharedPtr(
    ON_UUID mesh_id
    ) const;

  std::shared_ptr<ON_Mesh> MeshSharedPtr(
    ON::mesh_type mesh_type
    ) const;

  unsigned int MeshCount() const;

  bool Write(
    ON_BinaryArchive& archive
    ) const;

  bool Read(
    ON_BinaryArchive& archive
    );

  void Dump(
    ON_TextLog& text_log
    ) const;

  bool Transform(
    const ON_Xform& xform
    );

private:
  void Internal_CopyHelper(
    const class ON_MeshCacheItem* src_item_list
    );

  class ON_MeshCacheItem* Internal_FindHelper(
    ON_UUID mesh_type
    ) const;

  class ON_MeshCacheItem* Internal_CreateItem();
  class ON_MeshCacheItem* Internal_CopyItem(const class ON_MeshCacheItem& src_item);

  void Internal_DeleteItem(class ON_MeshCacheItem*,bool bDeleteMesh);

  class ON_MeshCacheItem* m_impl = nullptr;
};

class ON_CLASS ON_MeshNgonIterator
{
public:

  static const ON_MeshNgonIterator EmptyMeshNgonIterator;

  ON_MeshNgonIterator() = default;
  ~ON_MeshNgonIterator() = default;
  
  ON_MeshNgonIterator(
    const ON_MeshNgonIterator& src
    );

  ON_MeshNgonIterator& operator=(
    const ON_MeshNgonIterator& src
    );


  /*
  Parameters:
    mesh - [in]
      If the mesh has explicit ngons, then mesh->NgonMap() must
      return true;
  */
  ON_MeshNgonIterator(
    const class ON_Mesh* mesh
    );

  /*
  Parameters:
    mesh - [in]
      If the mesh has explicit ngons, 
    meshfdex_to_meshngondex_map - [in]
      It's generally best to pass the value of mesh->NgonMap(true).
      Expert users can specify a custom map if required.
  */
  void SetMesh(
    const class ON_Mesh* mesh,
    const unsigned int* meshfdex_to_meshngondex_map
    );

  /*
  Returns:
    The mesh being iterated.
  */
  const ON_Mesh* Mesh() const;

  /*
  Description:
    Returns the first ngon.
  Returns:
    The first ngon when iterating through the mesh 
    triangles, quads and explicitly defined ngons.
  Remarks:
    If CurrentNgonIsMeshFace() is true after calling FirstNgon().
    the the returned ngon references a triangle or
    quad that is not part of an explicitly defined
    ngon in the mesh. If you need the information 
    to persist after any subsequent calls to the iterator
    or after the destruction of the iterator, then
    you must make and manage a copy of the ngon.
  */
  const class ON_MeshNgon* FirstNgon();

  /*
  Description:
    Increments the iterator and returns the next ngon.
  Returns:
    The next ngon when iterating through the mesh 
    triangles, quads and explicitly defined ngons.
  Remarks:
    If CurrentNgonIsMeshFace() is true after calling NextNgon().
    the the returned ngon references a triangle or
    quad that is not part of an explicitly defined
    ngon in the mesh. If you need the information 
    to persist after any subsequent calls to the iterator
    or after the destruction of the iterator, then
    you must make and manage a copy of the ngon.
  */
  const class ON_MeshNgon* NextNgon();
  
  /*
  Description:
    Get the ngon most recently returned by FirstNgon()
    or NextNgon().
  Returns:
    Returns the ngon most recently returned by FirstNgon()
    or NextNgon().
  Remarks:
    If CurrentNgonIsMeshFace() is true after calling CurrentNgon().
    the the returned ngon references a triangle or
    quad that is not part of an explicitly defined
    ngon in the mesh. If you need the information 
    to persist after any subsequent calls to the iterator
    or after the destruction of the iterator, then
    you must make and manage a copy of the ngon.
  */
  const class ON_MeshNgon* CurrentNgon();

  ON_COMPONENT_INDEX CurrentNgonComponentIndex() const;
  /*
  Returns:
    If the current iterator ngon references an ON_MeshFace
    that is in m_mesh->m_F[] but is not explictly referenced
    by an ON_MeshNgon in ON_Mesh.m_Ngon[], then true is returned.
    In this case, the ngon's m_fi[] array
    has length 1 and contains the face's index, and the ngon's
    m_vi[] array is a copy of the faces's vi[] array.
    Otherwise false is returned.
  */
  bool CurrentNgonIsMeshFace() const;

  /*
  Returns:
    If the current iterator ngon references an ON_MeshNgon
    that is in m_mesh->m_Ngon[], then true is returned.
    Otherwise false is returned.
  */
  bool CurrentNgonIsMeshNgon() const;
  
  /*
  Description:
    Sets the state of the iterator to the initial state that
    exists after construction.  This is useful if the iterator
    has been used the get one or more elements and then
    the referenced mesh is modified or code wants
    to begin iteration again a used a call to NextNgon()
    to return the first element.
  */
  void Reset();

  /*
  Returns:
    Number of ngons that will be iterated over.
  Remarks:
    The count = explicit ngons + faces that are not in an ngon.
  */
  unsigned int Count() const;

private:
  const class ON_Mesh* m_mesh = nullptr;
  const unsigned int* m_facedex_to_ngondex_map = nullptr;
  ON__UINT_PTR m_current_ngon = 0;
  ON_MeshNgonBuffer m_ngon_buffer;
  ON_COMPONENT_INDEX m_current_ngon_ci = ON_COMPONENT_INDEX::UnsetComponentIndex;
  unsigned int m_mesh_face_count = 0;
  unsigned int m_mesh_ngon_count = 0;
  unsigned int m_iterator_index = 0;
};

class ON_CLASS ON_MeshComponentRef : public ON_Geometry
{
  ON_OBJECT_DECLARE(ON_MeshComponentRef);
public:
  static const ON_MeshComponentRef Unset;

  ON_MeshComponentRef();
  ON_MeshComponentRef(
    const class ON_Mesh* mesh,
    ON_COMPONENT_INDEX ci 
    );
  ~ON_MeshComponentRef();
  ON_MeshComponentRef& operator=(const ON_MeshComponentRef&);

  /*
  Description:
    Dictionary compare:
      1) Compare m_mesh pointer values as unsigned values
      2) ON_COMPONENT_INDEX::Compare() m_mesh_ci values
  */
  static int Compare(const ON_MeshComponentRef* lhs, const ON_MeshComponentRef* rhs);

  /*
  Description:
    Dictionary compare:
      1) Compare m_mesh pointer values as unsigned values
      2) ON_COMPONENT_INDEX::Compare() m_mesh_ci values
  */
  static int Compare2(const ON_MeshComponentRef* const * lhs, const ON_MeshComponentRef *const* rhs);

  /*
  Description:
    Compare m_mesh pointer values as unsigned values.
    Ignore m_mesh_ci values.
  */
  static int CompareMeshPointer(const ON_MeshComponentRef* lhs, const ON_MeshComponentRef* rhs);

private:
  // referenced mesh
  const class ON_Mesh* m_mesh;

  // component
  ON_COMPONENT_INDEX m_mesh_ci;

public:
  void Set(
    const class ON_Mesh* mesh,
    ON_COMPONENT_INDEX ci 
    );

  /*
  Returns:
    The referenced mesh.
  */
  const class ON_Mesh* Mesh() const;

  /*
  Description:
    Override of the virtual ON_Geometry::ComponentIndex().
  Returns:
    A mesh component index for the face.  The type is
    ON_COMPONENT_INDEX::mesh_face and the index is the
    index into the ON_Mesh.m_F[] array.
  */
  ON_COMPONENT_INDEX ComponentIndex() const override;

  /*
  Returns:
    If the mesh topology exists or the component references
    a mesh topology component, then this returns a pointer
    to the mesh topology.
    Otherwise null is returned.
  */
  const class ON_MeshTopology* MeshTopology() const;

  /*
  Returns:
    If the component is a vertex, this returns the vertex index.
    Otherwise ON_UNSET_UINT_INDEX is returned.
  */
  unsigned int VertexIndex() const;

  /*
  Returns:
    If the component is a mesh vertex or mesh topology vertex,
    then this returns the vertex location.
    Otherwise ON_3dPoint::UnsetPoint is returned.
  */
  ON_3dPoint VertexPoint() const;

  /*
  Parameters:
    point - [out]
      location of the vertex
  Returns:
    If the component is a vertex, this returns the vertex index.
    Otherwise ON_UNSET_UINT_INDEX is returned.
  */
  unsigned int GetVertexPoint(
    class ON_3dPoint& point
    ) const;

  /*
  Returns:
    If the component is a vertex and mesh topology exists or
    the component is a mesh topology vertex, then this returns
    a pointer to the mesh topology vertex index.
    Otherwise null is returned.
  */
  const struct ON_MeshTopologyVertex* MeshTopologyVertex() const;

  /*
  Returns:
    If the component is a vertex and mesh topology exists or
    the component is a mesh topology vertex, then this returns
    the mesh topology vertex index.
    Otherwise ON_UNSET_UINT_INDEX is returned.
  */
  unsigned int MeshTopologyVertexIndex() const;

  /*
  Returns:
    If the component is a vertex and mesh topology exists or
    the component is a mesh topology vertex, then this returns
    the mesh topology vertex index.
    Otherwise ON_UNSET_UINT_INDEX is returned.
  */
  unsigned int GetMeshTopologyVertexPoint(
    class ON_3dPoint& point
    ) const;

  /*
  Returns:
    If the component is a vertex and mesh topology exists or
    the component is a mesh topology vertex, then this returns
    the mesh topology vertex index.
    Otherwise ON_UNSET_UINT_INDEX is returned.
  */
  unsigned int GetMeshTopologyVertex(
    const struct ON_MeshTopologyVertex*& topv
    ) const;

  /*
  Returns:
    If the component is a vertex and mesh topology exists or
    the component is a mesh topology vertex, then this returns
    the mesh topology vertex index.
    Otherwise ON_UNSET_UINT_INDEX is returned.
  */
  unsigned int GetMeshTopologyVertexAndPoint(
    const struct ON_MeshTopologyVertex*& topv, 
    class ON_3dPoint& point
    ) const;

  /*
  Returns:
    If the component is a mesh topology edge, this returns
    the mesh topology edge index.
    Otherwise ON_UNSET_UINT_INDEX is returned.
  */
  unsigned int MeshTopologyEdgeIndex() const;

  /*
  Returns:
    If the component is an edge, this returns the edge.
    Otherwise null is returned.
  */
  const struct ON_MeshTopologyEdge* MeshTopologyEdge() const;
  
  unsigned int GetMeshTopologyEdge(
    const struct ON_MeshTopologyEdge*& tope
    ) const;
  
  unsigned int GetMeshTopologyEdgeLine(
    class ON_Line& line
    ) const;

  /*
  Parameters:
    line - [out]
      If the component is an edge, the 3d line is returned here.
  Returns:
    If the component is an edge, this returns the edge.
    Otherwise null is returned.
  */
  unsigned int GetMeshTopologyEdgeAndLine(
    const struct ON_MeshTopologyEdge*& tope,
    ON_Line& line 
    ) const;

  /*
  Returns:
    - If the component references to an ON_MeshNgon in the mesh, then a pointer
      to this ngon is returned.
    - If the component references an ON_MeshFace triangle or quad, then
      then a single face ON_MeshNgon is created in the memory in
      ngon_buffer. 
    - Otherwise, null is returned.
  */
  const class ON_MeshNgon* MeshNgon(
    class ON_MeshNgonBuffer& ngon_buffer
    ) const;

  /*
  Returns:
    If the component is a face or an ngon containing a single face,
    this returns the face index.
    Otherwise ON_UNSET_UINT_INDEX is returned.
  Remarks:
    The best way to write code that works with triangle, quad
    and ngons is to use the ON_MeshComponent::MeshNgon(ngon_buffer).
  */
  unsigned int MeshFaceIndex() const;

  /*
  Returns:
    If the component is a face or an ngon made of a single face,
    this returns the face.
    Otherwise null is returned.
  Remarks:
    The best way to write code that works with triangle, quad
    and ngons is to use the ON_MeshComponent::MeshNgon(ngon_buffer).
  */
  const class ON_MeshFace* MeshFace() const;

  /*
  Returns:
    If the component is a face or an ngon made of a single face,
    this returns the face.
    Otherwise null is returned.
  Remarks:
    The best way to write code that works with triangle, quad
    and ngons is to use the ON_MeshComponent::MeshNgon(ngon_buffer).
  */
  unsigned int GetMeshFace(
    const class ON_MeshFace*& mesh_face
    ) const;


  /*
  Returns:
    If the component is an ngon or a face in an ngon,
    this returns the ngon index.
    Otherwise ON_UNSET_UINT_INDEX is returned.
  Remarks:
    The best way to write code that works with triangle, quad
    and ngons is to use the ON_MeshComponent::MeshNgon(ngon_buffer).
  */
  unsigned int MeshNgonIndex() const;


  /*
  Returns:
    If the component is an ngon or a face in an ngon, this returns the ngon.
    Otherwise null is returned.
  Remarks:
    The best way to write code that works with triangle, quad
    and ngons is to use the ON_MeshComponent::MeshNgon(ngon_buffer).
  */
  const class ON_MeshNgon* MeshNgon() const;


  // overrides of virtual ON_Object functions
  bool IsValid( class ON_TextLog* text_log = nullptr ) const override;
  void Dump( ON_TextLog& ) const override;
  unsigned int SizeOf() const override;
  ON::object_type ObjectType() const override;

  // overrides of virtual ON_Geometry functions
  int Dimension() const override;

  // virtual ON_Geometry GetBBox override		
  bool GetBBox( double* boxmin, double* boxmax, bool bGrowBox = false ) const override;

  bool Transform( 
         const ON_Xform& xform
         ) override;
};


/*
Description:
  Calculate a mesh representation of the NURBS surface's control polygon.
Parameters:
  nurbs_surface - [in]
  bCleanMesh - [in] If true, then degenerate quads are cleaned
                    up to be triangles. Surfaces with singular
                    sides are a common source of degenerate qauds.
  input_mesh - [in] If nullptr, then the returned mesh is created
       by a class to new ON_Mesh().  If not null, then this 
       mesh will be used to store the conrol polygon.
Returns:
  If successful, a pointer to a mesh.
*/
ON_DECL
ON_Mesh* ON_ControlPolygonMesh( 
          const ON_NurbsSurface& nurbs_surface, 
          bool bCleanMesh,
          ON_Mesh* input_mesh = nullptr
          );


/*
Description:
  Finds the unit normal to the triangle
Parameters:
  A - [in] triangle corner
  B - [in] triangle corner
  C - [in] triangle corner
Returns:
  Unit normal
*/
ON_DECL
ON_3dVector ON_TriangleNormal(
        const ON_3dPoint& A,
        const ON_3dPoint& B,
        const ON_3dPoint& C
        );


/*
Description:
  Finds the unit normal to the triangle
Parameters:
  A - [in] triangle corner
  B - [in] triangle corner
  C - [in] triangle corner
  a - [out] must not be null
  b - [out] must not be null
  c - [out] must not be null
  d - [out] must not be null
    The equation of the plane is a*x + b*y + c*z + d = 0
  ev_tol - [out]
    If ev_tol is not null, then it is the maximum absolute
    value of the plane equation evaluated at A,B,C.  Mathematically,
    ev_tol is zero.  Since these computations are performed with
    finite precision doubles, ev_tol is generally not zero.
Returns:
  Unit normal
*/
ON_DECL
bool ON_GetTrianglePlaneEquation(
        const ON_3dPoint& A,
        const ON_3dPoint& B,
        const ON_3dPoint& C,
        double* a,
        double* b,
        double* c,
        double* d,
        double* evaluation_tol
        );


#endif
