/* $NoKeywords: $ */
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

#if !defined(OPENNURBS_TOPOLOGY_INC_)
#define OPENNURBS_TOPOLOGY_INC_


class ON_CLASS ON_ComponentAttributes
{
public:

#pragma region RH_C_SHARED_ENUM [ON_ComponentAttributes::EdgeFlags] [Rhino.Geometry.EdgeAttributeFlags] [int]

  /// <summary>
  /// <para>ON_EdgeAttributeFlags are used to report attributes of single edge objects, like
  /// ON_SubDEdge and ON_BrepEdge, and aggregate edge demographics in objects with topology
  /// like ON_SubD, ON_Mesh and ON_Brep.</para>
  /// <seealso cref="ON_BrepEdge::ComponentAttributes"/>
  /// <seealso cref="ON_SubDEdge::ComponentAttributes"/>
  /// <seealso cref="ON_Brep::AggregateEdgeComponentAttributes"/>
  /// <seealso cref="ON_Mesh::AggregateEdgeComponentAttributes"/>
  /// <seealso cref="ON_SubD::AggregateEdgeComponentAttributes"/>
  /// </summary>
  enum EdgeFlags : unsigned int
  {
    ///<summary> 
    /// The Open bit is set when an edge has distinct start and end vertices.
    ///</summary>
    Open = 1,

    ///<summary> 
    /// The Closed bit is set when an edge begins and ends at the same vertex.
    ///</summary>
    Closed = 2,

    ///<summary> 
    /// The Wire bit when an edge has no faces.
    ///</summary>
    Wire = 4,

    ///<summary> 
    /// The Boundary bit is set when an edge has one face.
    ///</summary>
    Boundary = 8,

    ///<summary> 
    /// The Interior bit is set when an edge has two distinct faces.
    ///</summary>
    Interior = 16,

    ///<summary> 
    /// The Nonmanifold bit is set when an edge has three or more faces.
    ///</summary>
    Nonmanifold = 32,

    ///<summary> 
    /// The Oriented bit is set when an edge has two faces with compatible orientations.
    ///</summary>
    Oriented = 64,

    ///<summary> 
    /// The NotOriented bit is set when an edge has two faces with opposited orientations.
    ///</summary>
    NotOriented = 128,

    ///<summary> 
    /// The Smooth bit is set when an an edge has two faces with a guaranteed surface tangent continuity.
    ///</summary>
    Smooth = 256,

    ///<summary> 
    /// The Crease bit is set when an edge has two faces with a possible surface tangent discontinuity
    ///</summary>
    Crease = 512,

    ///<summary> 
    /// The Dart bit is set when an edge has two faces with a possible surface tangent discontinuity
    /// at one end and guaranteed surface tangent space continuity at the other end.
    ///</summary>
    Dart = 1024,

    ///<summary> 
    /// The Seam bit is set when an edge has two faces that are identical and the edge is on the parametric boundary of the face's surface.
    ///</summary>
    ///<example> 
    /// Parametric surfaces that are cylinders are an example of a situation where seam edges occur.
    ///</example>
    Seam = 2048,

    ///<summary> 
    /// The Slit bit is set when edge has two faces that are identical and the edges is not a seam.
    ///</summary>
    Slit = 4096,

    ///<summary> 
    /// The Slit bit is set when an edge has zero length.
    ///</summary>
    Degenerate = 4096,

    ///<summary> 
    /// The Damaged bit is set when an edge has a critical flaw like missing vertex information.
    ///</summary>
    Damaged = 32768,

    ///<summary> 
    /// Mask can be used to isolate EdgeFlags bits from an unsigned int bit field containing other information.
    ///</summary>
    ///<example> 
    /// Determine if two unsigned ints have identical EdgeFlags settings.
    ///<code>
    /// unsigned int combined_flags1 = ...;
    /// unsigned int combined_flags2 = ...;
    /// unsigned int edge_flags1 = (ON_ComponentAttributes::EdgeFlags::Mask &amp; combined_flags1);
    /// unsigned int edge_flags2 = (ON_ComponentAttributes::EdgeFlags::Mask &amp; combined_flags2);
    /// if ( edge_flags1 == edge_flags1)
    /// {
    ///    ... edges flags are identical ...
    /// }
    ///</code>
    ///</example>
    Mask = 0xFFFF
  };

#pragma endregion

  /// <summary> 
  /// Inspects aggregate edge demographics to determine if every edge has exactly two faces and all 
  /// the faces have a compatible orientations.
  /// </summary> 
  /// <example>  
  /// This sample shows how to determine if an ON_SubD is a solid.
  /// <code> 
  /// ON_SubD subd = ...;
  /// if (ON_ComponentAttributes::IsSolid(subd.AggregateEdgeComponentAttributes())
  /// { 
  ///   // subd is a solid
  ///   ...
  /// }
  /// </code> 
  /// </example> 
  /// <param name="aggregate_edge_component_attributes">
  ///   Value made by bitwise or of ON_ComponentAttributes::EdgeFlags values for every edge in the object.
  /// </param>
  /// <returns>True if every edge has exactly two faces.</returns>
  /// <seealso cref="ON_Brep::EdgeDemographics"/>
  /// <seealso cref="ON_SUbD::EdgeDemographics"/>
  /// <seealso cref="ON_Mesh::EdgeDemographics"/>
  /// <seealso cref="ON_ComponentAttributes::IsSolid"/>
  /// <seealso cref="ON_ComponentAttributes::IsNotSolid"/>
  /// <seealso cref="ON_ComponentAttributes::HasBoundary"/>
  /// <seealso cref="ON_ComponentAttributes::IsOriented"/>
  /// <seealso cref="ON_ComponentAttributes::IsNotOriented"/>
  /// <seealso cref="ON_ComponentAttributes::IsManifold"/>
  /// <seealso cref="ON_ComponentAttributes::IsNotManifold"/>
  static bool IsSolid(
    unsigned int aggregate_edge_component_attributes
    );

  /// <summary> 
  /// Inspects aggregate edge demographics to determine if there is a boundary edge.
  /// </summary> 
  /// <param name="aggregate_edge_component_attributes">
  ///   Value made by bitwise or of ON_ComponentAttributes::EdgeFlags values for every edge in the object.
  /// </param>
  /// <returns>True if there is at least one edge that has exactly one face.
  /// Otherwise, false is returned.
  ///</returns>
  static bool HasBoundary(
    unsigned int aggregate_edge_component_attributes
    );

  /// <summary> 
  /// Inspects aggregate edge demographics to determine if the faces have a compatible orientations.
  /// </summary> 
  /// <param name="aggregate_edge_demographics">
  ///   Value made by bitwise or of ON_ComponentAttributes::EdgeFlags values for every edge in the object.
  /// </param>
  /// <returns>If for every edge edge with exactly two faces, those two faces have compatible orientations, then true is returned.
  /// Otherwise, false is returned.
  ///</returns>
  static bool IsOriented(
    unsigned int aggregate_edge_component_attributes
    );

  /// <summary> 
  /// Inspects aggregate edge demographics to determine if the faces have a compatible orientations.
  /// </summary> 
  /// <param name="aggregate_edge_component_attributes">
  ///   Value made by bitwise or of ON_ComponentAttributes::EdgeFlags values for every edge in the object.
  /// </param>
  /// <returns>If there is an edge edge with exactly two faces and those faces have incompatible orientations,
  /// then true is returned. Otherwise, false is returned.
  ///</returns>
  static bool IsNotOriented(
    unsigned int aggregate_edge_component_attributes
    );
  
  /// <summary> 
  /// Inspects aggregate edge demographics to determine if the object is a manifold, possibly with boundary.
  /// Face orientation is ignored.
  /// </summary> 
  /// <param name="aggregate_edge_component_attributes">
  ///   Value made by bitwise or of ON_ComponentAttributes::EdgeFlags values for every edge in the object.
  /// </param>
  /// <returns>If every edge has one or two faces, then true is returned.
  /// If bAllowBoundaryEdges is true and every edge has one or two faces, then true is returned.
  /// Otherwise, false is returned.
  ///</returns>
  static bool IsManifold(
    unsigned int aggregate_edge_component_attributes
    );

  /// <summary> 
  /// Inspects aggregate edge demographics to determine if the object is a not manifold.
  /// </summary> 
  /// <param name="aggregate_edge_component_attributes">
  ///   Value made by bitwise or of ON_ComponentAttributes::EdgeFlags values for every edge in the object.
  /// </param>
  /// <returns>True if there is at least one edge with 3 or more faces or at least one wire edge.</returns>  
  static bool IsNotManifold(
    unsigned int aggregate_edge_component_attributes
    );
};

#endif
