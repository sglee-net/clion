#include "opennurbs.h"

#if !defined(ON_COMPILING_OPENNURBS)
// This check is included in all opennurbs source .c and .cpp files to insure
// ON_COMPILING_OPENNURBS is defined when opennurbs source is compiled.
// When opennurbs source is being compiled, ON_COMPILING_OPENNURBS is defined 
// and the opennurbs .h files alter what is declared and how it is declared.
#error ON_COMPILING_OPENNURBS must be defined when compiling opennurbs
#endif

#include "opennurbs_subd_data.h"

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

#if defined(OPENNURBS_SUBD_WIP)

void ON_SubDIncrementErrorCount()
{
  ON_SubD::ErrorCount++;
} 

ON_SubDComponentPtr::Type ON_SubDComponentPtr::ComponentPtrTypeFromUnsigned(
  unsigned int element_pointer_type_as_unsigned
  )
{
  switch (element_pointer_type_as_unsigned)
  {
  ON_ENUM_FROM_UNSIGNED_CASE(ON_SubDComponentPtr::Type::Unset);
  ON_ENUM_FROM_UNSIGNED_CASE(ON_SubDComponentPtr::Type::Vertex);
  ON_ENUM_FROM_UNSIGNED_CASE(ON_SubDComponentPtr::Type::Edge);
  ON_ENUM_FROM_UNSIGNED_CASE(ON_SubDComponentPtr::Type::Face);
  }
  return ON_SUBD_RETURN_ERROR(ON_SubDComponentPtr::Type::Unset);
}

ON_SubD::VertexTag ON_SubD::VertexTagFromUnsigned(
  unsigned int vertex_tag_as_unsigned
  )
{
  switch (vertex_tag_as_unsigned)
  {
  ON_ENUM_FROM_UNSIGNED_CASE(ON_SubD::VertexTag::Unset);
  ON_ENUM_FROM_UNSIGNED_CASE(ON_SubD::VertexTag::Smooth);
  ON_ENUM_FROM_UNSIGNED_CASE(ON_SubD::VertexTag::Crease);
  ON_ENUM_FROM_UNSIGNED_CASE(ON_SubD::VertexTag::Corner);
  ON_ENUM_FROM_UNSIGNED_CASE(ON_SubD::VertexTag::Dart);
  }
  return ON_SUBD_RETURN_ERROR(ON_SubD::VertexTag::Unset);
}


bool ON_SubD::VertexTagIsSet(
  ON_SubD::VertexTag vertex_tag
)
{
  return (
    ON_SubD::VertexTag::Smooth == vertex_tag
    || ON_SubD::VertexTag::Crease == vertex_tag
    || ON_SubD::VertexTag::Corner == vertex_tag
    || ON_SubD::VertexTag::Dart == vertex_tag
    );
}


ON_SubD::EdgeTag ON_SubD::EdgeTagFromUnsigned(
  unsigned int edge_tag_as_unsigned
  )
{
  switch (edge_tag_as_unsigned)
  {
  ON_ENUM_FROM_UNSIGNED_CASE(ON_SubD::EdgeTag::Unset);
  ON_ENUM_FROM_UNSIGNED_CASE(ON_SubD::EdgeTag::Smooth);
  ON_ENUM_FROM_UNSIGNED_CASE(ON_SubD::EdgeTag::Crease);
  ON_ENUM_FROM_UNSIGNED_CASE(ON_SubD::EdgeTag::Sharp);
  ON_ENUM_FROM_UNSIGNED_CASE(ON_SubD::EdgeTag::X);
  }
  return ON_SUBD_RETURN_ERROR(ON_SubD::EdgeTag::Unset);
}

bool ON_SubD::EdgeTagIsSet(
  ON_SubD::EdgeTag edge_tag
)
{
  return (
    ON_SubD::EdgeTag::Smooth == edge_tag
    || ON_SubD::EdgeTag::Crease == edge_tag
    || ON_SubD::EdgeTag::Sharp == edge_tag
    || ON_SubD::EdgeTag::X == edge_tag
    );
}

ON_SubD::FacetType ON_SubD::FacetTypeFromUnsigned(
  unsigned int facet_type_as_unsigned
  )
{
  switch (facet_type_as_unsigned)
  {
  ON_ENUM_FROM_UNSIGNED_CASE(ON_SubD::FacetType::Unset);
  ON_ENUM_FROM_UNSIGNED_CASE(ON_SubD::FacetType::Tri);
  ON_ENUM_FROM_UNSIGNED_CASE(ON_SubD::FacetType::Quad);
  }
  return ON_SUBD_RETURN_ERROR(ON_SubD::FacetType::Unset);
}

//ON_SubD::VertexEdgeOrder ON_SubD::VertexEdgeOrderFromUnsigned(
//  unsigned int vertex_edge_order_as_unsigned
//  )
//{
//  switch (vertex_edge_order_as_unsigned)
//  {
//  ON_ENUM_FROM_UNSIGNED_CASE(ON_SubD::VertexEdgeOrder::unset);
//  ON_ENUM_FROM_UNSIGNED_CASE(ON_SubD::VertexEdgeOrder::radial);
//  ON_ENUM_FROM_UNSIGNED_CASE(ON_SubD::VertexEdgeOrder::notradial);
//  }
//  return ON_SUBD_RETURN_ERROR(ON_SubD::VertexEdgeOrder::unset);
//}

ON_SubD::VertexFacetType ON_SubD::VertexFacetTypeFromUnsigned(
  unsigned int vertex_facet_type_as_unsigned
  )
{
  switch (vertex_facet_type_as_unsigned)
  {
  ON_ENUM_FROM_UNSIGNED_CASE(ON_SubD::VertexFacetType::Unset);
  ON_ENUM_FROM_UNSIGNED_CASE(ON_SubD::VertexFacetType::Tri);
  ON_ENUM_FROM_UNSIGNED_CASE(ON_SubD::VertexFacetType::Quad);
  ON_ENUM_FROM_UNSIGNED_CASE(ON_SubD::VertexFacetType::Ngon);
  ON_ENUM_FROM_UNSIGNED_CASE(ON_SubD::VertexFacetType::Mixed);
  }
  return ON_SUBD_RETURN_ERROR(ON_SubD::VertexFacetType::Unset);
}

ON_SubD::SubDType ON_SubD::SubDTypeFromUnsigned(
  unsigned int subd_type_as_unsigned
  )  
{
  switch (subd_type_as_unsigned)
  {
  ON_ENUM_FROM_UNSIGNED_CASE(ON_SubD::SubDType::Unset);
  ON_ENUM_FROM_UNSIGNED_CASE(ON_SubD::SubDType::Custom);
  ON_ENUM_FROM_UNSIGNED_CASE(ON_SubD::SubDType::TriLoopWarren);
  ON_ENUM_FROM_UNSIGNED_CASE(ON_SubD::SubDType::QuadCatmullClark);
  ON_ENUM_FROM_UNSIGNED_CASE(ON_SubD::SubDType::CustomTri);
  ON_ENUM_FROM_UNSIGNED_CASE(ON_SubD::SubDType::CustomQuad);
  }
  return ON_SUBD_RETURN_ERROR(ON_SubD::SubDType::Unset);
}

ON_SubD::SubDType ON_SubD::DefaultSubDType()
{
  return ON_SubD::SubDType::QuadCatmullClark;
}


unsigned int ON_SubD::FacetEdgeCount(
  ON_SubD::FacetType facet_type
  )
{
  if (ON_SubD::FacetType::Quad == facet_type)
    return 4;
  if (ON_SubD::FacetType::Tri == facet_type)
    return 3;
  return 0;
}

unsigned int ON_SubD::FacetEdgeCount(
  ON_SubD::SubDType subdivision_type
  )
{
  if (ON_SubD::SubDType::QuadCatmullClark == subdivision_type)
    return 4;
  if (ON_SubD::SubDType::TriLoopWarren == subdivision_type)
    return 3;
  return 0;

}

unsigned int ON_SubDSectorType::SectorPointRingCountFromEdgeCount(
  ON_SubD::SubDType subd_type,
  ON_SubD::VertexTag vertex_tag,
  unsigned int sector_edge_count
  )
{
  if (sector_edge_count >= ON_SubDSectorType::MinimumSectorEdgeCount(vertex_tag) && sector_edge_count <= ON_SubDVertex::MaximumEdgeCount)
  {
    if (ON_SubD::VertexTag::Smooth == vertex_tag || ON_SubD::VertexTag::Dart == vertex_tag)
    {
      // interior vertex
      if (ON_SubD::SubDType::QuadCatmullClark == subd_type)
        return (2 * sector_edge_count + 1);
      if (ON_SubD::SubDType::TriLoopWarren == subd_type)
        return (sector_edge_count + 1);
    }

    if (ON_SubD::VertexTag::Crease == vertex_tag || ON_SubD::VertexTag::Corner == vertex_tag)
    {
      // boundary vertex
      if (ON_SubD::SubDType::QuadCatmullClark == subd_type)
        return (2 * sector_edge_count);
      if (ON_SubD::SubDType::TriLoopWarren == subd_type)
        return (sector_edge_count + 1);
    }
  }
  return ON_SUBD_RETURN_ERROR(0);
}

unsigned int ON_SubDSectorType::SectorPointRingCountFromFaceCount(
  ON_SubD::SubDType subd_type,
  ON_SubD::VertexTag vertex_tag,
  unsigned int sector_face_count
  )
{
  unsigned int sector_edge_count = ON_SubDSectorType::SectorEdgeCountFromFaceCount(vertex_tag,sector_face_count);
  return (sector_edge_count > 0)
    ? ON_SubDSectorType::SectorPointRingCountFromEdgeCount(subd_type,vertex_tag,sector_edge_count)
    : ON_SUBD_RETURN_ERROR(0);
}

unsigned int ON_SubDSectorType::SectorFaceCountFromEdgeCount(
  ON_SubD::VertexTag vertex_tag,
  unsigned int sector_edge_count
  )
{
  if (sector_edge_count >= 2 && sector_edge_count <= ON_SubDVertex::MaximumEdgeCount)
  {
    unsigned int sector_face_count
      = (ON_SubD::VertexTag::Crease == vertex_tag || ON_SubD::VertexTag::Corner == vertex_tag)
      ? sector_edge_count-1
      : sector_edge_count;
    return sector_face_count;
  }
  return ON_SUBD_RETURN_ERROR(0);
}

unsigned int ON_SubDSectorType::SectorEdgeCountFromFaceCount(
  ON_SubD::VertexTag vertex_tag,
  unsigned int sector_face_count
  )
{
  if (sector_face_count > 0 && sector_face_count <= ON_SubDVertex::MaximumFaceCount)
  {
    unsigned int sector_edge_count
      = (ON_SubD::VertexTag::Crease == vertex_tag || ON_SubD::VertexTag::Corner == vertex_tag)
      ? sector_face_count+1
      : sector_face_count;
    return sector_edge_count;
  }
  return ON_SUBD_RETURN_ERROR(0);
}

unsigned int ON_SubDSectorType::MinimumSectorEdgeCount(
  ON_SubD::VertexTag vertex_tag
  )
{
  if (ON_SubD::VertexTag::Smooth == vertex_tag || ON_SubD::VertexTag::Dart == vertex_tag)
    return ON_SubDSectorType::MinimumSectorFaceCount(vertex_tag);
  if (ON_SubD::VertexTag::Corner == vertex_tag || ON_SubD::VertexTag::Crease == vertex_tag)
    return ON_SubDSectorType::MinimumSectorFaceCount(vertex_tag)+1;
  return ON_UNSET_UINT_INDEX;
}

unsigned int ON_SubDSectorType::MinimumSectorFaceCount(
  ON_SubD::VertexTag vertex_tag
  )
{
  if (ON_SubD::VertexTag::Smooth == vertex_tag || ON_SubD::VertexTag::Dart == vertex_tag)
    return 3; // can be reduced to 2 after calculating special case matrix and eigenvalues
  if (ON_SubD::VertexTag::Corner == vertex_tag)
    return 1;
  if (ON_SubD::VertexTag::Crease == vertex_tag)
    return 1;
  return ON_UNSET_UINT_INDEX;
}

bool ON_SubD::IsValidSectorEdgeCount(
  ON_SubD::VertexTag vertex_tag,
  unsigned int sector_edge_count
  )
{
  return (sector_edge_count >= ON_SubDSectorType::MinimumSectorEdgeCount(vertex_tag) && sector_edge_count <= ON_SubDVertex::MaximumEdgeCount);
}

bool ON_SubD::IsValidSectorFaceCount(
  ON_SubD::VertexTag vertex_tag,
  unsigned int sector_face_count
  )
{
  return (sector_face_count >= ON_SubDSectorType::MinimumSectorFaceCount(vertex_tag) && sector_face_count <= ON_SubDVertex::MaximumFaceCount);
}

bool ON_SubD::IsQuadOrTriFacetType(
  ON_SubD::FacetType facet_type
  )
{
  return (ON_SubD::FacetType::Quad == facet_type || ON_SubD::FacetType::Tri == facet_type);
}

bool ON_SubD::IsQuadOrTriSubDType(
  ON_SubD::SubDType subdivision_type
  )
{
  if (ON_SubD::SubDType::QuadCatmullClark == subdivision_type || ON_SubD::SubDType::CustomQuad == subdivision_type)
    return true;
  if (ON_SubD::SubDType::TriLoopWarren == subdivision_type || ON_SubD::SubDType::CustomTri == subdivision_type)
    return true;
  return false;
}

ON_SubD::FacetType ON_SubD::FacetTypeFromSubDType(
  ON_SubD::SubDType subdivision_type
  )
{
  if (ON_SubD::SubDType::QuadCatmullClark == subdivision_type || ON_SubD::SubDType::CustomQuad == subdivision_type)
    return ON_SubD::FacetType::Quad;
  if (ON_SubD::SubDType::TriLoopWarren == subdivision_type || ON_SubD::SubDType::CustomTri == subdivision_type)
    return ON_SubD::FacetType::Tri;
  return ON_SubD::FacetType::Unset;
}

bool ON_SubD::PointRingHasFacePoints(
  ON_SubD::SubDType subdivision_type
  )
{
  return (ON_SubD::SubDType::QuadCatmullClark == subdivision_type || ON_SubD::SubDType::CustomQuad == subdivision_type);
}

//////////////////////////////////////////////////////////////////////////
//
// ON_SubDVertexPtr
//
//
bool ON_SubDVertexPtr::IsNull() const
{
  return (nullptr == ON_SUBD_VERTEX_POINTER(m_ptr));
}

class ON_SubDVertex* ON_SubDVertexPtr::Vertex() const
{
  return ON_SUBD_VERTEX_POINTER(m_ptr);
}

ON__UINT_PTR ON_SubDVertexPtr::VertexPtrMark() const
{
  return ON_SUBD_VERTEX_MARK(m_ptr);
}

ON_ComponentStatus ON_SubDVertexPtr::Status() const
{
  const ON_SubDVertex* vertex = ON_SUBD_VERTEX_POINTER(m_ptr);
  return (nullptr == vertex) ? ON_ComponentStatus::NoneSet : vertex->m_status;
}

class ON_SubDVertexPtr ON_SubDVertexPtr::Create(
  const class ON_SubDVertex* vertex
  )
{
  return ON_SubDVertexPtr::Create(vertex,0);
}

class ON_SubDVertexPtr ON_SubDVertexPtr::Create(
  const class ON_SubDVertex* vertex,
  ON__UINT_PTR vertex_mark
  )
{
  ON_SubDVertexPtr vptr = { (ON__UINT_PTR)vertex | (vertex_mark & ON_SUBD_ELEMENT_MARK_MASK) };
  return vptr;
}

class ON_SubDVertexPtr ON_SubDVertexPtr::Create(
  const class ON_SubDComponentPtr& vertex_element
  )
{
  return ON_SubDVertexPtr::Create(vertex_element.Vertex(), vertex_element.ComponentMark());
}

//////////////////////////////////////////////////////////////////////////
//
// ON_SubDEdgePtr
//


bool ON_SubDEdgePtr::IsNull() const
{
  return (nullptr == ON_SUBD_EDGE_POINTER(m_ptr));
}

class ON_SubDEdge* ON_SubDEdgePtr::Edge() const
{
  return ON_SUBD_EDGE_POINTER(m_ptr);
}

ON__UINT_PTR ON_SubDEdgePtr::EdgeDirection() const
{
  return ON_SUBD_EDGE_DIRECTION(m_ptr);
}

const class ON_SubDVertex* ON_SubDEdgePtr::RelativeVertex(
  int relative_vertex_index
  ) const
{
  for (;;)
  {
    if (relative_vertex_index < 0 || relative_vertex_index>1)
      break;
    const ON_SubDEdge* edge = ON_SUBD_EDGE_POINTER(m_ptr);
    if (nullptr == edge)
      break;
    if (0 != ON_SUBD_EDGE_DIRECTION(m_ptr))
      relative_vertex_index = 1 - relative_vertex_index;
    return edge->m_vertex[relative_vertex_index];
  }
  return nullptr;
}

ON_ComponentStatus ON_SubDEdgePtr::Status() const
{
  const ON_SubDEdge* edge = ON_SUBD_EDGE_POINTER(m_ptr);
  return (nullptr == edge) ? ON_ComponentStatus::NoneSet : edge->m_status;
}

ON_SubDEdgePtr ON_SubDEdgePtr::Reversed() const
{
  return ON_SubDEdgePtr::Create(ON_SUBD_EDGE_POINTER(m_ptr), 1 - (m_ptr & 1));
}

class ON_SubDEdgePtr ON_SubDEdgePtr::Create(
  const class ON_SubDEdge* edge,
  ON__UINT_PTR direction
  )
{
  ON_SubDEdgePtr eptr = { (ON__UINT_PTR)edge | (direction & ON_SUBD_ELEMENT_MARK_MASK) };
  return eptr;
}

ON_SubDEdgePtr ON_SubDEdgePtr::Create(
  const class ON_SubDComponentPtr& edge_element
  )
{
  return ON_SubDEdgePtr::Create(edge_element.Edge(), edge_element.ComponentMark());
}

//////////////////////////////////////////////////////////////////////////
//
// ON_SubDFacePtr
//

bool ON_SubDFacePtr::IsNull() const
{
  return (nullptr == ON_SUBD_FACE_POINTER(m_ptr));
}

ON_SubDFace* ON_SubDFacePtr::Face() const
{
  return ON_SUBD_FACE_POINTER(m_ptr);
}

ON__UINT_PTR ON_SubDFacePtr::FaceDirection() const
{
  return ON_SUBD_FACE_DIRECTION(m_ptr);
}

ON_ComponentStatus ON_SubDFacePtr::Status() const
{
  const ON_SubDFace* face = ON_SUBD_FACE_POINTER(m_ptr);
  return (nullptr == face) ? ON_ComponentStatus::NoneSet : face->m_status;
}

ON_SubDFacePtr ON_SubDFacePtr::Create(
  const class ON_SubDFace* face,
  ON__UINT_PTR direction
  )
{
  ON_SubDFacePtr fptr = { (ON__UINT_PTR)face | (direction & ON_SUBD_ELEMENT_MARK_MASK) };
  return fptr;
}

ON_SubDFacePtr ON_SubDFacePtr::Create(
  const class ON_SubDComponentPtr& face_element
  )
{
  return ON_SubDFacePtr::Create(face_element.Face(), face_element.ComponentMark());
}


//////////////////////////////////////////////////////////////////////////
//
// ON_SubDComponentPtr
//

bool ON_SubDComponentPtr::IsNull() const
{
  return (0 == (ON_SUBD_ELEMENT_POINTER_MASK && m_ptr));
}

bool ON_SubDComponentPtr::IsNotNull() const
{
  if (nullptr != ON_SUBD_EDGE_POINTER(m_ptr))
  {
    switch (ON_SUBD_ELEMENT_TYPE_MASK & m_ptr)
    {
    case ON_SUBD_ELEMENT_TYPE_VERTEX:
    case ON_SUBD_ELEMENT_TYPE_EDGE:
    case ON_SUBD_ELEMENT_TYPE_FACE:
      return true;
    }
  }
  return false;
}

ON_SubDComponentPtr::Type ON_SubDComponentPtr::ComponentType() const
{
  switch (ON_SUBD_ELEMENT_TYPE_MASK & m_ptr)
  {
  case ON_SUBD_ELEMENT_TYPE_VERTEX:
    return ON_SubDComponentPtr::Type::Vertex;
  case ON_SUBD_ELEMENT_TYPE_EDGE:
    return ON_SubDComponentPtr::Type::Edge;
  case ON_SUBD_ELEMENT_TYPE_FACE:
    return ON_SubDComponentPtr::Type::Face;
  }
  return ON_SubDComponentPtr::Type::Unset;
}

ON__UINT_PTR ON_SubDComponentPtr::ComponentMark() const
{
  return ON_SUBD_ELEMENT_MARK(m_ptr);
}


ON_ComponentStatus ON_SubDComponentPtr::Status() const
{
  switch (ComponentType())
  {
  case ON_SubDComponentPtr::Type::Vertex:
    {
      const ON_SubDVertex* vertex = Vertex();
      if ( nullptr != vertex )
        return vertex->m_status;
    }
    break;
  case ON_SubDComponentPtr::Type::Edge:
    {
      const ON_SubDEdge* edge = Edge();
      if ( nullptr != edge )
        return edge->m_status;
    }
    break;
  case ON_SubDComponentPtr::Type::Face:
    {
      const ON_SubDFace* face = Face();
      if ( nullptr != face )
        return face->m_status;
    }
    break;
  }
  return ON_ComponentStatus::NoneSet;
}

unsigned int ON_SubDComponentPtr::SetStatus(
  ON_ComponentStatus status
  )
{
  switch (ComponentType())
  {
  case ON_SubDComponentPtr::Type::Vertex:
    {
      const ON_SubDVertex* vertex = Vertex();
      if (nullptr != vertex)
        return vertex->m_status.SetStatus(status);
    }
    break;
  case ON_SubDComponentPtr::Type::Edge:
    {
      const ON_SubDEdge* edge = Edge();
      if (nullptr != edge)
        return edge->m_status.SetStatus(status);
    }
    break;
  case ON_SubDComponentPtr::Type::Face:
    {
      const ON_SubDFace* face = Face();
      if (nullptr != face)
        return face->m_status.SetStatus(status);
    }
    break;
  }
  return ON_SUBD_RETURN_ERROR(0);
}


unsigned int ON_SubDComponentPtr::SetStates(
  ON_ComponentStatus states_to_set
  )
{
  switch (ComponentType())
  {
  case ON_SubDComponentPtr::Type::Vertex:
    {
      const ON_SubDVertex* vertex = Vertex();
      if (nullptr != vertex)
        return vertex->m_status.SetStates(states_to_set);
    }
    break;
  case ON_SubDComponentPtr::Type::Edge:
    {
      const ON_SubDEdge* edge = Edge();
      if (nullptr != edge)
        return edge->m_status.SetStates(states_to_set);
    }
    break;
  case ON_SubDComponentPtr::Type::Face:
    {
      const ON_SubDFace* face = Face();
      if (nullptr != face)
        return face->m_status.SetStates(states_to_set);
    }
    break;
  }
  return ON_SUBD_RETURN_ERROR(0);
}


unsigned int ON_SubDComponentPtr::ClearStates(
  ON_ComponentStatus states_to_clear
  )
{
  switch (ComponentType())
  {
  case ON_SubDComponentPtr::Type::Vertex:
    {
      const ON_SubDVertex* vertex = Vertex();
      if (nullptr != vertex)
        return vertex->m_status.ClearStates(states_to_clear);
    }
    break;
  case ON_SubDComponentPtr::Type::Edge:
    {
      const ON_SubDEdge* edge = Edge();
      if (nullptr != edge)
        return edge->m_status.ClearStates(states_to_clear);
    }
    break;
  case ON_SubDComponentPtr::Type::Face:
    {
      const ON_SubDFace* face = Face();
      if (nullptr != face)
        return face->m_status.ClearStates(states_to_clear);
    }
    break;
  }
  return ON_SUBD_RETURN_ERROR(0);
}


ON_SubDComponentPtr ON_SubDComponentPtr::ClearMark() const
{
  ON_SubDComponentPtr component_ptr = *this;
  component_ptr.m_ptr &= (ON_SUBD_ELEMENT_POINTER_MASK | ON_SUBD_ELEMENT_TYPE_MASK);
  return component_ptr;
}

ON_SubDComponentPtr ON_SubDComponentPtr::SetMark() const
{
  ON_SubDComponentPtr component_ptr = *this;
  component_ptr.m_ptr |= ON_SUBD_ELEMENT_MARK_MASK;
  return component_ptr;
}

ON_SubDComponentPtr ON_SubDComponentPtr::ToggleMark() const
{
  return (0 != (m_ptr & ON_SUBD_ELEMENT_MARK_MASK)) ? ClearMark() : SetMark();
}

const ON_SubDComponentPtr ON_SubDComponentPtr::CreateNull(
  ON_SubDComponentPtr::Type component_type,
  bool bMark
)
{
  ON_SubDComponentPtr component_ptr;
  switch (component_type)
  {
  case ON_SubDComponentPtr::Type::Unset:
    component_ptr.m_ptr = 0;
    break;
  case ON_SubDComponentPtr::Type::Vertex:
    component_ptr.m_ptr = ON_SUBD_ELEMENT_TYPE_VERTEX;
    break;
  case ON_SubDComponentPtr::Type::Edge:
    component_ptr.m_ptr = ON_SUBD_ELEMENT_TYPE_EDGE;
    break;
  case ON_SubDComponentPtr::Type::Face:
    component_ptr.m_ptr = ON_SUBD_ELEMENT_TYPE_FACE;
    break;
  default:
    component_ptr.m_ptr = 0;
    break;
  }
  if (bMark)
    component_ptr.m_ptr |= ON_SUBD_ELEMENT_MARK_MASK;
  return component_ptr;
}


class ON_SubDComponentBase* ON_SubDComponentPtr::ComponentBase() const
{
  switch ((ON_SUBD_ELEMENT_TYPE_MASK & m_ptr))
  {
  case ON_SUBD_ELEMENT_TYPE_VERTEX:
  case ON_SUBD_ELEMENT_TYPE_EDGE:
  case ON_SUBD_ELEMENT_TYPE_FACE:
    return ((class ON_SubDComponentBase*)ON_SUBD_ELEMENT_POINTER(m_ptr));
  }
  return nullptr;
}


class ON_SubDVertex* ON_SubDComponentPtr::Vertex() const
{
  if (ON_SUBD_ELEMENT_TYPE_VERTEX == (ON_SUBD_ELEMENT_TYPE_MASK & m_ptr))
    return ON_SUBD_VERTEX_POINTER(m_ptr);
  return nullptr;
}

class ON_SubDEdge* ON_SubDComponentPtr::Edge() const
{
  if (ON_SUBD_ELEMENT_TYPE_EDGE == (ON_SUBD_ELEMENT_TYPE_MASK & m_ptr))
    return ON_SUBD_EDGE_POINTER(m_ptr);
  return nullptr;
}

class ON_SubDFace* ON_SubDComponentPtr::Face() const
{
  if (ON_SUBD_ELEMENT_TYPE_FACE == (ON_SUBD_ELEMENT_TYPE_MASK & m_ptr))
    return ON_SUBD_FACE_POINTER(m_ptr);
  return nullptr;
}

ON_SubDVertexPtr ON_SubDComponentPtr::VertexPtr() const
{
  ON__UINT_PTR element_type = ON_SUBD_ELEMENT_TYPE(m_ptr);
  if ( ON_SUBD_ELEMENT_TYPE_VERTEX == element_type)
    return ON_SubDVertexPtr::Create(Vertex(), ComponentMark());

  if ( 0 == element_type )
    return ON_SubDVertexPtr::Null;

  return ON_SUBD_RETURN_ERROR(ON_SubDVertexPtr::Null);
}

ON_SubDEdgePtr ON_SubDComponentPtr::EdgePtr() const
{
  ON__UINT_PTR element_type = ON_SUBD_ELEMENT_TYPE(m_ptr);
  if ( ON_SUBD_ELEMENT_TYPE_EDGE == element_type)
    return ON_SubDEdgePtr::Create(Edge(), ComponentMark());

  if ( 0 == element_type )
    return ON_SubDEdgePtr::Null;

  return ON_SUBD_RETURN_ERROR(ON_SubDEdgePtr::Null);
}

ON_SubDFacePtr ON_SubDComponentPtr::FacePtr() const
{
  ON__UINT_PTR element_type = ON_SUBD_ELEMENT_TYPE(m_ptr);
  if ( ON_SUBD_ELEMENT_TYPE_FACE == element_type)
    return ON_SubDFacePtr::Create(Face(), ComponentMark());

  if ( 0 == element_type )
    return ON_SubDFacePtr::Null;

  return ON_SUBD_RETURN_ERROR(ON_SubDFacePtr::Null);
}

const ON_SubDComponentPtr ON_SubDComponentPtr::Create(
  const class ON_SubDVertex* vertex
  )
{
  if (nullptr != vertex)
  {
    ON_SubDComponentPtr vptr = { (ON__UINT_PTR)vertex | ON_SUBD_ELEMENT_TYPE_VERTEX };
    return vptr;
  }
  return ON_SubDComponentPtr::Null;
}

const ON_SubDComponentPtr ON_SubDComponentPtr::Create(
  const class ON_SubDEdge* edge
  )
{
  if (nullptr != edge)
  {
    ON_SubDComponentPtr eptr = { (ON__UINT_PTR)edge | ON_SUBD_ELEMENT_TYPE_EDGE };
    return eptr;
  }
  return ON_SubDComponentPtr::Null;
}


const ON_SubDComponentPtr ON_SubDComponentPtr::Create(
  const class ON_SubDFace* face
  )
{
  if (nullptr != face)
  {
    ON_SubDComponentPtr fptr = { (ON__UINT_PTR)face | ON_SUBD_ELEMENT_TYPE_FACE };
    return fptr;
  }
  return ON_SubDComponentPtr::Null;
}

const ON_SubDComponentPtr ON_SubDComponentPtr::Create(
  const class ON_SubDVertex* vertex,
  ON__UINT_PTR vertex_direction
  )
{
  if (nullptr != vertex)
  {
    ON_SubDComponentPtr vptr = { (ON__UINT_PTR)vertex | ON_SUBD_ELEMENT_TYPE_VERTEX | (vertex_direction & ON_SUBD_ELEMENT_MARK_MASK) };
    return vptr;
  }
  return ON_SubDComponentPtr::Null;
}

const ON_SubDComponentPtr ON_SubDComponentPtr::Create(
  const class ON_SubDEdge* edge,
  ON__UINT_PTR edge_direction
  )
{
  if (nullptr != edge)
  {    
    ON_SubDComponentPtr eptr = { (ON__UINT_PTR)edge | (ON_SUBD_ELEMENT_TYPE_EDGE | (edge_direction & ON_SUBD_ELEMENT_MARK_MASK)) };
    return eptr;
  }
  return ON_SubDComponentPtr::Null;
}

const ON_SubDComponentPtr ON_SubDComponentPtr::Create(
  const class ON_SubDFace* face,
  ON__UINT_PTR face_direction
  )
{
  if (nullptr != face)
  {
    ON_SubDComponentPtr fptr = { (ON__UINT_PTR)face | (ON_SUBD_ELEMENT_TYPE_FACE | (face_direction & ON_SUBD_ELEMENT_MARK_MASK)) };
    return fptr;
  }
  return ON_SubDComponentPtr::Null;
}

const ON_SubDComponentPtr ON_SubDComponentPtr::Create(
  ON_SubDVertexPtr vertexptr
  )
{
  return Create(vertexptr.Vertex(), vertexptr.VertexPtrMark());
}

const ON_SubDComponentPtr ON_SubDComponentPtr::Create(
  ON_SubDEdgePtr edgeptr
  )
{
  return Create(edgeptr.Edge(), edgeptr.EdgeDirection());
}

const ON_SubDComponentPtr ON_SubDComponentPtr::Create(
  ON_SubDFacePtr faceptr
  )
{
  return Create(faceptr.Face(), faceptr.FaceDirection());
}

int ON_SubDComponentPtr::CompareComponentPtrType(
  ON_SubDComponentPtr::Type a,
  ON_SubDComponentPtr::Type b
  )
{
  if ( a == b )
    return 0;
  switch (a)
  {
  case ON_SubDComponentPtr::Type::Vertex:
    return -1;
    break;
  case ON_SubDComponentPtr::Type::Edge:
    return (ON_SubDComponentPtr::Type::Vertex == b) ? 1 : -1;
    break;
  case ON_SubDComponentPtr::Type::Face:
    return (ON_SubDComponentPtr::Type::Vertex == b || ON_SubDComponentPtr::Type::Edge == b) ? 1 : -1;
    break;
  default:
    break;
  }
  return (((unsigned char)a) < ((unsigned char)b)) ? -1 : 1;
}

int ON_SubDComponentPtr::CompareType(
  const ON_SubDComponentPtr* a,
  const ON_SubDComponentPtr* b
  )
{
  if ( a == b )
    return 0;
  if ( nullptr == a )
    return 1;
  if ( nullptr == b )
    return -1;
  return ON_SubDComponentPtr::CompareComponentPtrType(a->ComponentType(), b->ComponentType());
}

int ON_SubDComponentPtr::Compare(
  const ON_SubDComponentPtr* a,
  const ON_SubDComponentPtr* b
  )
{
  if ( a == b )
    return 0;
  if ( nullptr == a )
    return 1;
  if ( nullptr == b )
    return -1;
  int rc = ON_SubDComponentPtr::CompareComponentPtrType(a->ComponentType(), b->ComponentType());
  if (0 == rc)
  {
    if ( a->m_ptr < b->m_ptr )
      return -1;
    if ( a->m_ptr > b->m_ptr )
      return 1;
  }
  return rc;
}


int ON_SubDComponentPoint::CompareComponentPtr(
  const ON_SubDComponentPoint* a,
  const ON_SubDComponentPoint* b
  )
{
  if ( a == b)
    return 0;
  
  if ( nullptr == a)
    return 1; // nullptr > non-null pointer.

  if ( nullptr == b)
    return -1; // nullptr > non-null pointer.

  // unset < vertex < edge < face
  ON__UINT_PTR x = (ON_SUBD_ELEMENT_TYPE_MASK & a->m_component_ptr.m_ptr);
  ON__UINT_PTR y = (ON_SUBD_ELEMENT_TYPE_MASK & b->m_component_ptr.m_ptr);
  if ( x < y )
    return -1;
  if ( x > y )
    return 1;

  if ( a->m_component_ptr.m_ptr < b->m_component_ptr.m_ptr )
    return -1;
  if ( a->m_component_ptr.m_ptr > b->m_component_ptr.m_ptr )
    return 1;

  return 0;
}

//////////////////////////////////////////////////////////////////////////
//
// ON_SubDFromMeshOptions
//

ON_SubDFromMeshOptions::ConvexCornerOption ON_SubDFromMeshOptions::ConvexCornerOptionFromUnsigned(
  unsigned int convex_corner_option_as_unsigned
  )
{
  switch (convex_corner_option_as_unsigned)
  {
	case (unsigned int)ON_SubDFromMeshOptions::ConvexCornerOption::Unset:
		return ON_SubDFromMeshOptions::ConvexCornerOption::Unset;
	case (unsigned int)ON_SubDFromMeshOptions::ConvexCornerOption::None:
		return ON_SubDFromMeshOptions::ConvexCornerOption::None;
	case (unsigned int)ON_SubDFromMeshOptions::ConvexCornerOption::AtMeshCorner:
		return ON_SubDFromMeshOptions::ConvexCornerOption::AtMeshCorner;
  default:
    break;
  }
	return ON_SubDFromMeshOptions::ConvexCornerOption::Unset;
}

void ON_SubDFromMeshOptions::SetConvexCornerOption(
  ON_SubDFromMeshOptions::ConvexCornerOption convex_corner_option
  )
{
  m_convex_corner_option = ON_SubDFromMeshOptions::ConvexCornerOptionFromUnsigned((unsigned int)convex_corner_option);
}

ON_SubDFromMeshOptions::ConvexCornerOption ON_SubDFromMeshOptions::ConvexCornerTest() const
{
  switch (m_convex_corner_option)
  {
  case ON_SubDFromMeshOptions::ConvexCornerOption::Unset:
  case ON_SubDFromMeshOptions::ConvexCornerOption::None:
    return m_convex_corner_option;

  case ON_SubDFromMeshOptions::ConvexCornerOption::AtMeshCorner:
    if ( m_maximum_convex_corner_edge_count >= 2 
         && m_maximum_convex_corner_edge_count <= ON_SubDVertex::MaximumEdgeCount
         && m_maximum_convex_corner_angle_radians >= 0.0
         && m_maximum_convex_corner_angle_radians < ON_PI
         )
         return m_convex_corner_option;
    break;
  }

  return ON_SubDFromMeshOptions::ConvexCornerOption::Unset;
}

void ON_SubDFromMeshOptions::SetMaximumConvexCornerEdgeCount(
  unsigned int maximum_convex_corner_edge_count
  )
{
  if ( maximum_convex_corner_edge_count >= 2 && maximum_convex_corner_edge_count <= ON_SubDVertex::MaximumEdgeCount)
    m_maximum_convex_corner_edge_count = (unsigned short)maximum_convex_corner_edge_count;
}

unsigned int ON_SubDFromMeshOptions::MaximumConvexCornerEdgeCount() const
{
  return m_maximum_convex_corner_edge_count;
}

void ON_SubDFromMeshOptions::SetMaximumConvexCornerAngleRadians(
  double maximum_convex_corner_angle_radians
  )
{
  if (maximum_convex_corner_angle_radians > 0.0 && maximum_convex_corner_angle_radians < ON_PI)
    m_maximum_convex_corner_angle_radians = maximum_convex_corner_angle_radians;
}

double ON_SubDFromMeshOptions::MaximumConvexCornerAngleRadians() const
{
  return m_maximum_convex_corner_angle_radians;
}

ON_SubDFromMeshOptions::ConvexCornerOption ON_SubDFromMeshOptions::CopyConvexCornerTest(
  ON_SubDFromMeshOptions source_parameters
  )
{
  SetConvexCornerOption(source_parameters.ConvexCornerTest());
  SetMaximumConvexCornerEdgeCount(source_parameters.MaximumConvexCornerEdgeCount());
  SetMaximumConvexCornerAngleRadians(source_parameters.MaximumConvexCornerAngleRadians());
  return ConvexCornerTest();
}

void ON_SubDFromMeshOptions::SetInteriorCreaseOption(
  ON_SubDFromMeshOptions::InteriorCreaseOption interior_crease_option
  )
{
  m_interior_crease_option = ON_SubDFromMeshOptions::InteriorCreaseOptionFromUnsigned((unsigned int)interior_crease_option);
}

ON_SubDFromMeshOptions::InteriorCreaseOption ON_SubDFromMeshOptions::InteriorCreaseTest() const
{
  return m_interior_crease_option;
}

void ON_SubDFromMeshOptions::SetMinimumCreaseAngleRadians(
  double minimum_crease_angle_radians
  )
{
  if (minimum_crease_angle_radians >= 0.0 && minimum_crease_angle_radians < ON_PI)
    m_minimum_crease_angle_radians = minimum_crease_angle_radians;
}


double ON_SubDFromMeshOptions::MinimumCreaseAngleRadians() const
{
  return m_minimum_crease_angle_radians;
}

ON_SubDFromMeshOptions::InteriorCreaseOption ON_SubDFromMeshOptions::CopyInteriorCreaseTest(
  ON_SubDFromMeshOptions source_parameters
  )
{
  SetInteriorCreaseOption(source_parameters.InteriorCreaseTest());
  SetMinimumCreaseAngleRadians(source_parameters.MinimumCreaseAngleRadians());
  return InteriorCreaseTest();
}

ON_SubDFromMeshOptions::InteriorCreaseOption ON_SubDFromMeshOptions::InteriorCreaseOptionFromUnsigned(
  unsigned int interior_crease_option_as_unsigned
  )
{
  switch (interior_crease_option_as_unsigned)
  {
  case (unsigned int)ON_SubDFromMeshOptions::InteriorCreaseOption::Unset:
    return ON_SubDFromMeshOptions::InteriorCreaseOption::Unset;
    break;
  case (unsigned int)ON_SubDFromMeshOptions::InteriorCreaseOption::None:
    return ON_SubDFromMeshOptions::InteriorCreaseOption::None;
    break;
  case (unsigned int)ON_SubDFromMeshOptions::InteriorCreaseOption::AtMeshCrease:
    return ON_SubDFromMeshOptions::InteriorCreaseOption::AtMeshCrease;
    break;
  case (unsigned int)ON_SubDFromMeshOptions::InteriorCreaseOption::AtMeshEdge:
    return ON_SubDFromMeshOptions::InteriorCreaseOption::AtMeshEdge;
    break;
  default:
    break;
  }

  return ON_SubDFromMeshOptions::InteriorCreaseOption::Unset;
}

ON_SubD::SubDType ON_SubDFromMeshOptions::SubDType() const
{
  return 
    (ON_SubD::SubDType::Unset == m_subd_type) 
    ? ON_SubD::DefaultSubDType()
    : m_subd_type;
}

void ON_SubDFromMeshOptions::SetSubDType(
  ON_SubD::SubDType subd_type
  )
{
  if (subd_type == ON_SubD::SubDTypeFromUnsigned((unsigned int)subd_type) )
  {
    m_subd_type = subd_type;
  }
}
//////////////////////////////////////////////////////////////////////////
//
// ON_SubDVertex
//

const ON_SubDEdgePtr ON_SubDVertex::EdgePtr(
  unsigned int i
) const
{
  return (i < m_edge_count) ? m_edges[i] : ON_SubDEdgePtr::Null;
}


const class ON_SubDEdge* ON_SubDVertex::Edge(
  unsigned int i
  ) const
{
  return (i < m_edge_count) ? ON_SUBD_EDGE_POINTER(m_edges[i].m_ptr) : nullptr;
}

ON__UINT_PTR ON_SubDVertex::EdgeDirection(
  unsigned int i
  ) const
{
  return (i < m_edge_count) ? ON_SUBD_EDGE_DIRECTION(m_edges[i].m_ptr) : 0;
}

unsigned int ON_SubDVertex::EdgeCount() const
{
  return m_edge_count;
}

unsigned int ON_SubDVertex::EdgeCount(
  ON_SubD::EdgeTag edge_tag
  ) const
{
  if (nullptr != m_edges)
  {
    unsigned int matching_edge_count = 0;
    const unsigned int edge_count = m_edge_count;
    for (unsigned int vei = 0; vei < edge_count; vei++)
    {
      const ON_SubDEdge* e = ON_SUBD_EDGE_POINTER(m_edges[vei].m_ptr);
      if (nullptr != e && edge_tag == e->m_edge_tag)
        matching_edge_count++;
    }
    return matching_edge_count;
  }
  return 0;
}

unsigned int ON_SubDVertex::EdgeArrayIndex(
  const ON_SubDEdge* edge
  ) const
{
  if ( nullptr == edge )
    return ON_UNSET_UINT_INDEX;
  const unsigned int edge_count = m_edge_count;
  if ( 0 == edge_count)
    return ON_UNSET_UINT_INDEX;
  const ON_SubDEdgePtr* eptr = m_edges;
  if ( nullptr == eptr)
    return ON_SUBD_RETURN_ERROR(ON_UNSET_UINT_INDEX);

  for ( unsigned int i = 0; i < edge_count; i++, eptr++)
  {
    if (edge == ON_SUBD_EDGE_POINTER(eptr->m_ptr))
      return i;
  }

  return ON_UNSET_UINT_INDEX;
}

unsigned int ON_SubDVertex::FaceCount() const
{
  return m_face_count;
}

const class ON_SubDFace* ON_SubDVertex::Face(
  unsigned int i
  ) const
{
  //return (i < m_face_count) ? ON_SUBD_FACE_POINTER(m_faces[i].m_ptr) : nullptr;
  return (i < m_face_count) ? m_faces[i] : nullptr;
}


unsigned int ON_SubDVertex::FaceArrayIndex(
  const ON_SubDFace* face
  ) const
{
  if ( nullptr == face )
    return ON_UNSET_UINT_INDEX;
  const unsigned int face_count = m_face_count;
  if ( 0 == face_count)
    return ON_UNSET_UINT_INDEX;
  if ( nullptr == m_faces)
    return ON_SUBD_RETURN_ERROR(ON_UNSET_UINT_INDEX);

  for ( unsigned int i = 0; i < face_count; i++)
  {
    if (face == m_faces[i] )
      return i;
  }

  return ON_UNSET_UINT_INDEX;
}


ON_SubD::FacetType ON_SubDVertex::FirstFaceFacetType() const
{
  if (0 == m_face_count)
    return ON_SubD::FacetType::Unset;

  if (nullptr == m_faces)
    return ON_SubD::FacetType::Unset;

  if (nullptr == m_faces[0])
    return ON_SubD::FacetType::Unset;

  if (3 == m_faces[0]->m_edge_count)
    return ON_SubD::FacetType::Tri;

  if (4 == m_faces[0]->m_edge_count)
    return ON_SubD::FacetType::Quad;

  return ON_SubD::FacetType::Unset;
}


bool ON_SubDVertex::IsTagged() const
{
  return (ON_SubD::VertexTag::Crease == m_vertex_tag || ON_SubD::VertexTag::Corner == m_vertex_tag || ON_SubD::VertexTag::Dart == m_vertex_tag);
}

//static bool AllFacesHaveCorrectEdgeCount(
//  unsigned short correct_edge_count,
//  unsigned int face_count,
//  const ON_SubDFace*const* vertex_faces
//  )
//{
//  if (nullptr == vertex_faces)
//    return false;
//  for (unsigned int vfi = 0; vfi < face_count; vfi++)
//  {
//    const ON_SubDFace* f = vertex_faces[vfi];
//    if (nullptr == f)
//      return false;
//    if (correct_edge_count != f->m_edge_count)
//      return false;
//  }
//  return true;
//}

//bool ON_SubDVertex::IsOrdinary(
//  ON_SubD::SubDType subdivision_type,
//  ON_SubD::VertexTag vertex_tag_filter,
//  bool bTestFaces
//  ) const
//{
//  if (ON_SubD::VertexTag::Unset == vertex_tag_filter || vertex_tag_filter == m_vertex_tag)
//  {
//    if (ON_SubD::VertexTag::Smooth == m_vertex_tag)
//    {
//      if (m_edge_count == m_face_count)
//      {
//        if (ON_SubD::SubDType::QuadCatmullClark == subdivision_type)
//        {
//          if (4 == m_edge_count)
//            return bTestFaces ? AllFacesHaveCorrectEdgeCount(4, m_face_count, m_faces) : true;
//        }
//        else if (ON_SubD::SubDType::TriLoopWarren == subdivision_type)
//        {
//          if (6 == m_edge_count)
//            return bTestFaces ? AllFacesHaveCorrectEdgeCount(3, m_face_count, m_faces) : true;
//        }
//      }
//    }
//    else if (ON_SubD::VertexTag::Crease == m_vertex_tag)
//    {
//      if (m_edge_count == m_face_count + 1)
//      {
//        if (ON_SubD::SubDType::QuadCatmullClark == subdivision_type)
//        {
//          if (3 == m_edge_count && 2 == EdgeCount(ON_SubD::EdgeTag::Crease))
//          {
//            return bTestFaces ? AllFacesHaveCorrectEdgeCount(4, m_face_count, m_faces) : true;
//          }
//        }
//        else if (ON_SubD::SubDType::TriLoopWarren == subdivision_type)
//        {
//          if (4 == m_edge_count && 2 == EdgeCount(ON_SubD::EdgeTag::Crease))
//          {
//            return bTestFaces ?  AllFacesHaveCorrectEdgeCount(3, m_face_count, m_faces) : true;
//          }
//        }
//      }
//    }
//  }
//
//  return false;
//}

bool ON_SubDVertex::IsSmooth() const
{
  return (ON_SubD::VertexTag::Smooth == m_vertex_tag);
}

bool ON_SubDVertex::IsCrease() const
{
  return (ON_SubD::VertexTag::Crease == m_vertex_tag);
}

bool ON_SubDVertex::IsCorner() const
{
  return (ON_SubD::VertexTag::Corner == m_vertex_tag);
}

bool ON_SubDVertex::IsDart() const
{
  return (ON_SubD::VertexTag::Dart == m_vertex_tag);
}

bool ON_SubDVertex::IsCreaseOrCorner() const
{
  return (ON_SubD::VertexTag::Crease == m_vertex_tag || ON_SubD::VertexTag::Corner == m_vertex_tag);
}

bool ON_SubDVertex::IsCreaseOrCornerOrDart() const
{
  return (
    ON_SubD::VertexTag::Crease == m_vertex_tag
    || ON_SubD::VertexTag::Corner == m_vertex_tag
    || ON_SubD::VertexTag::Dart == m_vertex_tag
    );
}



bool ON_SubDVertex::IsSmoothOrDart() const
{
  return (ON_SubD::VertexTag::Smooth == m_vertex_tag || ON_SubD::VertexTag::Dart == m_vertex_tag);
}

bool ON_SubDVertex::IsSmoothOrCrease() const
{
  return (ON_SubD::VertexTag::Smooth == m_vertex_tag || ON_SubD::VertexTag::Crease == m_vertex_tag);
}

bool ON_SubDEdge::IsCrease() const
{
  return (ON_SubD::EdgeTag::Crease == m_edge_tag) ? true : false;
}


bool ON_SubDEdge::IsHardCrease() const
{
  return
    (
      ON_SubD::EdgeTag::Crease == m_edge_tag
      && nullptr != m_vertex[0]
      && nullptr != m_vertex[1]
      && m_vertex[0]->IsCreaseOrCorner()
      && m_vertex[1]->IsCreaseOrCorner()
      )
    ? true
    : false;
}

bool ON_SubDEdge::IsDartCrease() const
{
  return
    (ON_SubD::EdgeTag::Crease == m_edge_tag && DartCount() > 0 )
    ? true
    : false;
}

unsigned int ON_SubDEdge::DartCount() const
{
  unsigned int dart_count = 0;
  if (nullptr != m_vertex[0] && ON_SubD::VertexTag::Dart == m_vertex[0]->m_vertex_tag)
    dart_count++;
  if (nullptr != m_vertex[1] && ON_SubD::VertexTag::Dart == m_vertex[1]->m_vertex_tag)
    dart_count++;
  return dart_count;
}

bool ON_SubDEdge::IsSmooth() const
{
  return (ON_SubD::EdgeTag::Smooth == m_edge_tag || ON_SubD::EdgeTag::X == m_edge_tag) ? true : false;
}

bool ON_SubDEdge::IsSmoothNotX() const
{
  return (ON_SubD::EdgeTag::Smooth == m_edge_tag) ? true : false;
}

bool ON_SubDEdge::IsSmoothX() const
{
  return (ON_SubD::EdgeTag::X == m_edge_tag) ? true : false;
}

bool ON_SubDVertex::IsStandard(
  ON_SubD::SubDType subdivision_type
  ) const
{
  if (nullptr == m_edges)
    return false;

  if (nullptr == m_faces)
    return false;

  const unsigned int edge_count = m_edge_count;
  if (!ON_SubD::IsValidSectorEdgeCount(m_vertex_tag,edge_count))
    return false;

  const unsigned int face_count = m_face_count;
  if (face_count != ON_SubDSectorType::SectorFaceCountFromEdgeCount(m_vertex_tag, edge_count))
    return false;

  const unsigned short f_edge_count 
    = (ON_SubD::SubDType::QuadCatmullClark == subdivision_type) 
    ? 4
    : ((ON_SubD::SubDType::TriLoopWarren == subdivision_type) ? 3 : 0);
  if (0 == f_edge_count)
    return false;

  unsigned int crease_edge_face_count = ON_UNSET_UINT_INDEX;
  bool bTaggedVertex = false;
  switch (m_vertex_tag)
  {
  case ON_SubD::VertexTag::Unset:
    return false;
    break;

  case ON_SubD::VertexTag::Smooth:
    if (edge_count != face_count)
      return false;
    break;

  case ON_SubD::VertexTag::Crease:
    if (edge_count != face_count+1)
      return false;
    crease_edge_face_count = 1;
    bTaggedVertex = true;
    break;

  case ON_SubD::VertexTag::Corner:
    if (edge_count != face_count+1)
      return false;
    crease_edge_face_count = 1;
    bTaggedVertex = true;
    break;

  case ON_SubD::VertexTag::Dart:
    if (edge_count != face_count)
      return false;
    crease_edge_face_count = 2;
    bTaggedVertex = true;
    break;

  default:
    return false;
    break;
  }
  

  for (unsigned int vfi = 0; vfi < face_count; vfi++)
  {
    const ON_SubDFace* f = m_faces[vfi];
    if (nullptr == f)
      return false;
    if (f_edge_count != f->m_edge_count)
      return false;
  }

  unsigned int creased_edge_count = 0;
  double sector_weight = 0.0;
  for (unsigned int vei = 0; vei < edge_count; vei++)
  {
    const ON_SubDEdge* e = m_edges[vei].Edge();
    if (nullptr == e)
      return false;

    unsigned int evi;
    if (this == e->m_vertex[0])
      evi = 0;
    else if (this == e->m_vertex[1])
      evi = 1;
    else
      return false;

    const ON_SubDVertex* other_vertex = e->m_vertex[1-evi];

    if (nullptr == other_vertex)
      return false;

    if (ON_SubD::EdgeTag::Smooth == e->m_edge_tag)
    {
      if (2 != e->m_face_count)
        return false;

      if (bTaggedVertex && 0 == vei)
      {
        sector_weight = e->m_sector_coefficient[evi];
        if (!(0.0 <= sector_weight && sector_weight <= 1.0))
          return false;
      }
      
      if (!(sector_weight == e->m_sector_coefficient[evi]))
        return false;

      if (ON_SubD::VertexTag::Smooth == other_vertex->m_vertex_tag)
      {
        if ( !(0.0 == e->m_sector_coefficient[1-evi]) )
          return false;
      }
      else
      {
        if ( bTaggedVertex )
          return false;
        if ( !(0.5 == e->m_sector_coefficient[1-evi]) )
          return false;
      }
    }
    else if (ON_SubD::EdgeTag::Crease == e->m_edge_tag)
    {
      if (crease_edge_face_count != e->m_face_count)
        return false;
      creased_edge_count++;
      if (creased_edge_count > 2)
        return false;
      if (false == other_vertex->IsCreaseOrCornerOrDart())
        return false;
    }
    else
    {
      return false;
    }
  }

  switch (creased_edge_count)
  {
  case 0:
    if (false == IsSmooth())
      return false;
    break;
  case 1:
    if (false == IsDart())
      return false;
    break;
  case 2:
    if (false == IsCreaseOrCorner())
      return false;
    break;
  default:
    return false;
  }

  // The standard subdivison matrix will correctly calculate
  // the subdivision location for this vertex.
  return true;
}


unsigned int ON_SubDEdge::EdgeFlags() const
{

  if (nullptr == m_vertex[0] || nullptr == m_vertex[1] || m_vertex[0] == m_vertex[1])
    return ON_ComponentAttributes::EdgeFlags::Damaged;
  
  unsigned int edge_topology_attributes = ON_ComponentAttributes::EdgeFlags::Open;

  const double* P[2] = { m_vertex[0]->m_P, m_vertex[1]->m_P };
  if (P[0][0] == P[1][0] && P[0][1] == P[1][1] && P[0][2] == P[1][2])
    edge_topology_attributes |= ON_ComponentAttributes::EdgeFlags::Degenerate;

  switch (m_face_count)
  {
  case 0:
    edge_topology_attributes |= ON_ComponentAttributes::EdgeFlags::Wire;
    break;
  case 1:
    edge_topology_attributes |= ON_ComponentAttributes::EdgeFlags::Boundary;
    break;
  case 2:
    edge_topology_attributes |= ON_ComponentAttributes::EdgeFlags::Interior;
    {
      const ON_SubDFace* face[2] = { ON_SUBD_FACE_POINTER(m_face2[0].m_ptr), ON_SUBD_FACE_POINTER(m_face2[1].m_ptr) };
      if (nullptr == face[0] || nullptr == face[1] || face[0] == face[1])
        edge_topology_attributes |= ON_ComponentAttributes::EdgeFlags::Damaged;
      else
      {
        if (IsSmooth())
          edge_topology_attributes |= ON_ComponentAttributes::EdgeFlags::Smooth;
        else if ( m_vertex[0]->IsDart() || m_vertex[1]->IsDart() )
          edge_topology_attributes |= ON_ComponentAttributes::EdgeFlags::Dart;
        else
          edge_topology_attributes |= ON_ComponentAttributes::EdgeFlags::Crease;

        ON__UINT_PTR dir[2] = { ON_SUBD_FACE_DIRECTION(m_face2[0].m_ptr), ON_SUBD_FACE_DIRECTION(m_face2[1].m_ptr) };
        if (dir[0] == dir[1])
          edge_topology_attributes |= ON_ComponentAttributes::EdgeFlags::NotOriented;
        else
          edge_topology_attributes |= ON_ComponentAttributes::EdgeFlags::Oriented;
      }
    }
    break;
  default:
    edge_topology_attributes |= ON_ComponentAttributes::EdgeFlags::Nonmanifold;
    if ( nullptr == m_facex )
      edge_topology_attributes |= ON_ComponentAttributes::EdgeFlags::Damaged;
    break;
  }

  return edge_topology_attributes;
}

static int Compare_ON__UINT_PTR(const void* a, const void* b)
{
  ON__UINT_PTR ai = *((const unsigned int*)a);
  ON__UINT_PTR bi = *((const unsigned int*)b);
  if (ai < bi)
    return -1;
  if (ai > bi)
    return 1;
  return 0;
}

static int ComparePointerArrays(
  size_t count,
  const ON__UINT_PTR* a,
  const ON__UINT_PTR* b
  )
{
  if (count <= 0)
    return 0;
  if (nullptr == a)
    return ((nullptr == b) ? 0 : -1);
  if (nullptr == b)
    return 1;
  if (1 == count)
    return Compare_ON__UINT_PTR(a, b);

  unsigned int stack_buffer[128];
  unsigned int* adex
    = (2 * count <= sizeof(stack_buffer) / sizeof(stack_buffer[0]))
    ? stack_buffer
    : new (std::nothrow) unsigned int[2 * count];  
  if (nullptr == adex)
    return 0;
  
  unsigned int* bdex = adex + count;
  ON_Sort(ON::sort_algorithm::quick_sort, adex, a, count, sizeof(a[0]), Compare_ON__UINT_PTR);
  ON_Sort(ON::sort_algorithm::quick_sort, bdex, b, count, sizeof(b[0]), Compare_ON__UINT_PTR);
  
  int rc = 0;
  for (unsigned int i = 0; 0 == rc && i < count; i++)
  {
    rc = Compare_ON__UINT_PTR(a + adex[i], b + bdex[i]);
  }

  if (adex != stack_buffer)
    delete[] adex;

  return rc;
}

int ON_SubDVertex::CompareUnorderedEdges(
  const ON_SubDVertex* a,
  const ON_SubDVertex* b
  )
{
  if (nullptr == a)
    return ((nullptr == b) ? 0 : -1);
  if (nullptr == b)
    return 1;

  if (a->m_edge_count < b->m_edge_count)
    return -1;
  if (a->m_edge_count > b->m_edge_count)
    return 1;
  return ComparePointerArrays(a->m_edge_count, (const ON__UINT_PTR*)a->m_edges, (const ON__UINT_PTR*)b->m_edges);
}

int ON_SubDVertex::CompareUnorderedFaces(
  const ON_SubDVertex* a,
  const ON_SubDVertex* b
  )
{
  if (nullptr == a)
    return ((nullptr == b) ? 0 : -1);
  if (nullptr == b)
    return 1;

  if (a->m_face_count < b->m_face_count)
    return -1;
  if (a->m_face_count > b->m_face_count)
    return 1;
  return ComparePointerArrays(a->m_face_count, (const ON__UINT_PTR*)a->m_faces, (const ON__UINT_PTR*)b->m_faces);
}

int ON_SubDVertex::CompareUnorderedEdgesAndFaces(
  const ON_SubDVertex* a,
  const ON_SubDVertex* b
  )
{
  int rc = CompareUnorderedEdges(a, b);
  if (0 == rc)
    rc = CompareUnorderedFaces(a, b);
  return rc;
}

//////////////////////////////////////////////////////////////////////////
//
// ON_SubDEdge
//

void ON_SubDComponentBase::CopyBaseFrom(
  const ON_SubDComponentBase* src
  )
{
  if ( nullptr == src )
    src = &ON_SubDComponentBase::Unset;

  *this = *src;
  m_subd_point1 = nullptr;
  ON_SUBD_CACHE_CLEAR_LIMIT_FLAG(m_saved_points_flags);
}

void ON_SubDEdge::CopyFrom(
  const ON_SubDEdge* src,
  bool bReverseEdge,
  bool bCopyVertexArray,
  bool bCopyFaceArray
  )
{
  if (nullptr == src)
    src = &ON_SubDEdge::Empty;

  CopyBaseFrom(src);

  m_next_edge = nullptr;
  
  m_edge_tag = src->m_edge_tag;

  unsigned int end0 = bReverseEdge ? 1 : 0;

  if (bCopyVertexArray)
  {
    m_vertex[0] = src->m_vertex[end0];
    m_vertex[1] = src->m_vertex[1 - end0];
  }

  m_sector_coefficient[0] = src->m_sector_coefficient[end0];
  m_sector_coefficient[1] = src->m_sector_coefficient[1 - end0];

  if (bCopyFaceArray)
  {
    if (src->m_face_count > 0 && (src->m_face_count <= 2 || (nullptr != src->m_facex && nullptr != m_facex)))
    {
      m_face2[0] = src->m_face2[0];
      m_face2[1] = src->m_face2[1];
      unsigned int face_count = src->m_face_count;
      if (face_count > 2)
      {
        face_count -= 2;
        for (unsigned int efi = 0; efi < face_count; efi++)
          m_facex[efi] = src->m_facex[efi];
      }
      m_face_count = src->m_face_count;
    }
    else
      m_face_count = 0;
  }
}

unsigned int ON_SubDEdge::TaggedEndIndex() const
{
  unsigned int tagged_end_index = 3;
  for (unsigned int evi = 0; evi < 2; evi++)
  {
    const ON_SubDVertex* v = m_vertex[evi];
    if (nullptr == v || false == v->IsTagged())
      continue;
    tagged_end_index = (3 == tagged_end_index) ? evi : 2;
  }
  return tagged_end_index;
}

ON_SubDFacePtr ON_SubDEdge::FacePtr(
  unsigned int i
  ) const
{
  return (i < 2) ? m_face2[i] : ((i < m_face_count) ? m_facex[i - 2] : ON_SubDFacePtr::Null);
  //return (i < m_face_count) ? ((i < 2) ? m_face2[i] : m_facex[i - 2]) : ON_SubDFacePtr::Null;
}

unsigned int ON_SubDEdge::FaceCount() const
{
  return m_face_count;
}

const class ON_SubDFace* ON_SubDEdge::Face(
  unsigned int i
  ) const
{
  return (i < 2) ? ON_SUBD_FACE_POINTER(m_face2[i].m_ptr) : ((i < m_face_count) ? ON_SUBD_FACE_POINTER(m_facex[i - 2].m_ptr) : nullptr);
}

ON__UINT_PTR ON_SubDEdge::FaceDirection(
  unsigned int i
  ) const
{
  return (i < 2) ? ON_SUBD_FACE_DIRECTION(m_face2[i].m_ptr) : ((i < m_face_count) ? ON_SUBD_FACE_DIRECTION(m_facex[i - 2].m_ptr) : 0);
}

ON_SubDFacePtr ON_SubDEdge::FacePtr(
  const class ON_SubDFace* f
) const
{
  if (nullptr != f)
  {
    const ON_SubDFacePtr* fptr = m_face2;
    const unsigned int edge_face_count = m_face_count;
    for (unsigned int efi = 0; efi < edge_face_count; efi++, fptr++)
    {
      if (2 == efi)
      {
        fptr = m_facex;
        if (nullptr == fptr)
          break;
      }
      if (fptr->Face() == f)
        return *fptr;
    }
  }
  return ON_SubDFacePtr::Null;
}


unsigned int ON_SubDEdge::FaceArrayIndex(
  const ON_SubDFace* f
  ) const
{
  if (nullptr == f)
    return ON_UNSET_UINT_INDEX;
  const unsigned int face_count = m_face_count;
  if (face_count > 0)
  {
    if (f == ON_SUBD_FACE_POINTER(m_face2[0].m_ptr))
      return 0;
    if (face_count >= 1)
    {
      if (f == ON_SUBD_FACE_POINTER(m_face2[1].m_ptr))
        return 1;
      if (face_count > 2 && nullptr != m_facex)
      {
        const ON_SubDFacePtr* fptr = m_facex - 2;
        for (unsigned int efi = 2; efi < face_count; efi++)
        {
          if (f == ON_SUBD_FACE_POINTER(fptr[efi].m_ptr))
            return efi;
        }
      }
    }
  }
  return ON_UNSET_UINT_INDEX;
}


const ON_SubDFace* ON_SubDEdge::NeighborFace(
  const ON_SubDFace* face,
    bool bStopAtCrease
  ) const
{
  if ( nullptr == face || 2 != m_face_count )
    return nullptr;
  // Do not stop at x tags
  if (bStopAtCrease && ON_SubD::EdgeTag::Crease == m_edge_tag)
    return nullptr;
  const ON_SubDFace* f[2] = { ON_SUBD_FACE_POINTER(m_face2[0].m_ptr), ON_SUBD_FACE_POINTER(m_face2[1].m_ptr) };
  if (nullptr == f[0] || nullptr == f[1] )
    return ON_SUBD_RETURN_ERROR(nullptr);
  if (face == f[0])
  {
    if (face == f[1] )
      return ON_SUBD_RETURN_ERROR(nullptr);
    return f[1];
  }
  if (face == f[1])
  {
    return f[0];
  }
  return ON_SUBD_RETURN_ERROR(nullptr);
}

const ON_SubDFacePtr ON_SubDEdge::NeighborFacePtr(
  const ON_SubDFace* face,
    bool bStopAtCrease
  ) const
{
  if ( nullptr == face || 2 != m_face_count )
    return ON_SubDFacePtr::Null;
  // Do not stop at x tags
  if (bStopAtCrease && ON_SubD::EdgeTag::Crease == m_edge_tag)
    return ON_SubDFacePtr::Null;
  const ON_SubDFace* f[2] = { ON_SUBD_FACE_POINTER(m_face2[0].m_ptr), ON_SUBD_FACE_POINTER(m_face2[1].m_ptr) };
  if (nullptr == f[0] || nullptr == f[1] )
    return ON_SUBD_RETURN_ERROR(ON_SubDFacePtr::Null);
  if (face == f[0])
  {
    if (face == f[1] )
      return ON_SUBD_RETURN_ERROR(ON_SubDFacePtr::Null);
    return m_face2[1];
  }
  if (face == f[1])
  {
    return m_face2[0];
  }
  return ON_SUBD_RETURN_ERROR(ON_SubDFacePtr::Null);
}


const class ON_SubDVertex* ON_SubDEdge::Vertex(
  unsigned int i
  ) const
{
  return (i <= 1) ? m_vertex[i] : nullptr;
}


const ON_SubDVertex* ON_SubDEdge::OtherEndVertex(
  const ON_SubDVertex* vertex
  ) const
{
  if (nullptr != vertex)
  {
    if (m_vertex[0] == vertex)
    {
      if (m_vertex[1] != vertex )
        return m_vertex[1];
    }
    else if (m_vertex[1] == vertex )
      return m_vertex[0];
  }
  return nullptr;
}

const ON_3dPoint ON_SubDEdge::EndPoint( unsigned int i) const
{
  if (i >= 2 || nullptr == m_vertex[i])
    return ON_3dPoint::NanPoint;
  return (ON_3dPoint(m_vertex[i]->m_P));
}

const ON_3dVector ON_SubDEdge::Direction() const
{
  if (nullptr == m_vertex[0] || nullptr == m_vertex[1])
    return ON_3dVector::NanVector;
  return (ON_3dPoint(m_vertex[1]->m_P) - ON_3dPoint(m_vertex[0]->m_P));
}


//////////////////////////////////////////////////////////////////////////
//
// ON_SubDFace
//



//bool ON_SubDFace::IsOrdinary(
//  ON_SubD::SubDType subdivision_type,
//  bool bTestFaces
//  ) const
//{
//  unsigned int ordinary_face_edge_count = 0;
//  if (ON_SubD::SubDType::QuadCatmullClark == subdivision_type)
//    ordinary_face_edge_count = 4;
//  else if (ON_SubD::SubDType::TriLoopWarren == subdivision_type)
//    ordinary_face_edge_count = 3;
//  else
//    return false;
//
//  if (ordinary_face_edge_count != m_edge_count)
//    return false;
//
//  for (unsigned int fei = 0; fei < ordinary_face_edge_count; fei++)
//  {
//    ON__UINT_PTR eptr = m_edge4[fei].m_ptr;
//    const ON_SubDEdge* e = ON_SUBD_EDGE_POINTER(eptr);
//    if (nullptr == e || 2 != e->m_face_count || ON_SubD::EdgeTag::Smooth != e->m_edge_tag)
//      return false;
//    ON__UINT_PTR edir = ON_SUBD_EDGE_DIRECTION(eptr);
//    const ON_SubDVertex* v = e->m_vertex[edir];
//    if (nullptr == v || false == v->IsOrdinary(subdivision_type,ON_SubD::VertexTag::Unset,bTestFaces))
//      return false;
//  }
//  return true;
//}

void ON_SubDFace::CopyFrom(
  const ON_SubDFace* src,
  bool bCopyEdgeArray
  )
{
  if (nullptr == src)
    src = &ON_SubDFace::Empty;

  CopyBaseFrom(src);

  m_next_face = nullptr;

  m_zero_face_id = src->m_zero_face_id;
  m_parent_face_id = src->m_parent_face_id;

  if (bCopyEdgeArray)
  {
    if (src->m_edge_count > 0 && (src->m_edge_count <= 4 || (nullptr != src->m_edgex && nullptr != m_edgex)))
    {
      m_edge4[0] = src->m_edge4[0];
      m_edge4[1] = src->m_edge4[1];
      m_edge4[2] = src->m_edge4[2];
      m_edge4[3] = src->m_edge4[3];
      unsigned int edge_count = src->m_edge_count;
      if (edge_count > 4)
      {
        edge_count -= 4;
        for (unsigned int fei = 0; fei < edge_count; fei++)
          m_edgex[fei] = src->m_edgex[fei];
      }
      m_edge_count = src->m_edge_count;
    }
    else
      m_edge_count = 0;
  }
}

ON_SubDEdgePtr ON_SubDFace::EdgePtr(
  unsigned int i
  ) const
{
  return (i < 4) ? m_edge4[i] : ((i < m_edge_count) ? m_edgex[i-4] : ON_SubDEdgePtr::Null);
}

unsigned int ON_SubDFace::EdgeCount() const
{
  return m_edge_count;
}

const class ON_SubDVertex* ON_SubDFace::Vertex(
  unsigned int i
  ) const
{
  ON_SubDEdge* e;
  const ON__UINT_PTR edge_ptr = (i < 4) ? m_edge4[i].m_ptr : ((i < m_edge_count) ? m_edgex[i - 4].m_ptr : 0);
  return (nullptr != (e = ON_SUBD_EDGE_POINTER(edge_ptr))) ? e->m_vertex[ON_SUBD_EDGE_DIRECTION(edge_ptr)] : nullptr;
}

const ON_SubDVertex* ON_SubDFace::QuadOppositeVertex(
  const ON_SubDVertex* vertex
  ) const
{
  if ( nullptr == vertex )
    return ON_SUBD_RETURN_ERROR(nullptr);
  if ( 4 != m_edge_count)
    return nullptr; // not an error
  
  ON__UINT_PTR ptr0 = m_edge4[0].m_ptr;
  const ON_SubDEdge* e0 = ON_SUBD_EDGE_POINTER(ptr0);
  if ( nullptr == e0 )
    return ON_SUBD_RETURN_ERROR(nullptr);
  ptr0 = ON_SUBD_EDGE_DIRECTION(ptr0);
  
  ON__UINT_PTR ptr2 = m_edge4[2].m_ptr;
  const ON_SubDEdge* e2 = ON_SUBD_EDGE_POINTER(ptr2);
  if ( nullptr == e2 )
    return ON_SUBD_RETURN_ERROR(nullptr);
  ptr2 = ON_SUBD_EDGE_DIRECTION(ptr2);

  if (vertex == e0->m_vertex[ptr0])
    return e2->m_vertex[ptr2];

  if (vertex == e0->m_vertex[1-ptr0])
    return e2->m_vertex[1-ptr2];

  if (vertex == e2->m_vertex[ptr2])
    return e0->m_vertex[ptr0];

  if (vertex == e2->m_vertex[1-ptr2])
    return e0->m_vertex[1-ptr0];

  return ON_SUBD_RETURN_ERROR(nullptr);
}

const ON_SubDEdge* ON_SubDFace::QuadOppositeEdge(
  const ON_SubDEdge* edge
  ) const
{
  if ( nullptr == edge )
    return ON_SUBD_RETURN_ERROR(nullptr);
  if ( 4 != m_edge_count)
    return nullptr; // not an error
  
  for (unsigned int fei = 0; fei < 4; fei++)
  {
    const ON_SubDEdge* e0 = ON_SUBD_EDGE_POINTER(m_edge4[fei].m_ptr);
    if (nullptr == e0)
      return ON_SUBD_RETURN_ERROR(nullptr);
    if (e0 == edge)
    {
      e0 = ON_SUBD_EDGE_POINTER(m_edge4[(fei + 2) % 4].m_ptr);
      if (nullptr == e0)
        return ON_SUBD_RETURN_ERROR(nullptr);
      return e0;
    }
  }

  return ON_SUBD_RETURN_ERROR(nullptr);
}


const class ON_SubDEdge* ON_SubDFace::Edge(
  unsigned int i
  ) const
{
  return (i < 4) ? ON_SUBD_EDGE_POINTER(m_edge4[i].m_ptr) : ((i < m_edge_count) ? ON_SUBD_EDGE_POINTER(m_edgex[i - 4].m_ptr) : nullptr);
}

ON__UINT_PTR ON_SubDFace::EdgeDirection(
  unsigned int i
  ) const
{
  return (i < 4) ? ON_SUBD_EDGE_DIRECTION(m_edge4[i].m_ptr) : ((i < m_edge_count) ? ON_SUBD_EDGE_DIRECTION(m_edgex[i - 4].m_ptr) : 0);
}


ON_SubDEdgePtr ON_SubDFace::EdgePtr(
  const class ON_SubDEdge* e
) const
{
  if (nullptr != e)
  {
    const ON_SubDEdgePtr* eptr = m_edge4;
    const unsigned int face_edge_count = m_edge_count;
    for (unsigned int fei = 0; fei < face_edge_count; fei++, eptr++)
    {
      if (4 == fei)
      {
        eptr = m_edgex;
        if (nullptr == eptr)
          break;
      }
      if (e == ON_SUBD_EDGE_POINTER(eptr->m_ptr))
        return *eptr;
    }
  }

  return ON_SubDEdgePtr::Null;
}


unsigned int ON_SubDFace::EdgeArrayIndex(
  const ON_SubDEdge* e
  ) const
{
  if (nullptr != e)
  {
    const ON_SubDEdgePtr* eptr = m_edge4;
    const unsigned int face_edge_count = m_edge_count;
    for (unsigned int fei = 0; fei < face_edge_count; fei++, eptr++)
    {
      if (4 == fei)
      {
        eptr = m_edgex;
        if (nullptr == eptr)
          break;
      }
      if (e == ON_SUBD_EDGE_POINTER(eptr->m_ptr))
        return fei;
    }
  }

  return ON_UNSET_UINT_INDEX;
}


const ON_SubDEdge* ON_SubDFace::PrevEdge(
  const ON_SubDEdge* edge
  ) const
{
  unsigned int edge_index = EdgeArrayIndex(edge);
  if (ON_UNSET_UINT_INDEX == edge_index)
    return nullptr;
  const unsigned int edge_count = m_edge_count;
  edge_index = (edge_index + (edge_count - 1)) % edge_count;
  return Edge(edge_index);
}

const ON_SubDEdge* ON_SubDFace::NextEdge(
  const ON_SubDEdge* edge
  ) const
{
  unsigned int edge_index = EdgeArrayIndex(edge);
  if (ON_UNSET_UINT_INDEX == edge_index)
    return nullptr;
  edge_index = (edge_index + 1) % ((unsigned int)m_edge_count);
  return Edge(edge_index);
}

unsigned int ON_SubDFace::PrevEdgeArrayIndex(
  unsigned int edge_array_index
  ) const
{
  const unsigned int edge_count = m_edge_count;
  return (edge_array_index < edge_count) ? ((edge_array_index + edge_count - 1) % edge_count) : ON_UNSET_UINT_INDEX;
}

unsigned int ON_SubDFace::NextEdgeArrayIndex(
  unsigned int edge_array_index
  ) const
{
  const unsigned int edge_count = m_edge_count;
  return (edge_array_index < edge_count) ? ((edge_array_index +  1) % edge_count) : ON_UNSET_UINT_INDEX;
}

bool ON_SubDEdge::RemoveFaceFromArray(
  const ON_SubDFace* f
  )
{
  unsigned int i;
  if (nullptr == f)
    return false;

  if (m_face_count <= 2)
  {
    for (i = 0; i < m_face_count; i++)
    {
      if (f == ON_SUBD_FACE_POINTER(m_face2[i].m_ptr))
      {
        for (i++; i < m_face_count; i++)
          m_face2[i - 1] = m_face2[i];
        m_face_count--;
        return true;
      }
    }
  }
  else
  {
    for (i = 0; i < 2; i++)
    {
      if (f == ON_SUBD_FACE_POINTER(m_face2[i].m_ptr))
      {
        for (i++; i < 2; i++)
          m_face2[i - 1] = m_face2[i];
        m_face2[1] = m_facex[0];
        for (i = 3; i < m_face_count; i++)
          m_facex[i - 3] = m_facex[i - 2];
        m_face_count--;
        return true;
      }
    }
    for (i = 2; i < m_face_count; i++)
    {
      if (f == ON_SUBD_FACE_POINTER(m_facex[i - 4].m_ptr))
      {
        for (i++; i < m_face_count; i++)
          m_facex[i - 3] = m_facex[i - 2];
        m_face_count--;
        return true;
      }
    }
  }

  return false;
}

bool ON_SubDEdge::AddFaceToArray(
  ON_SubDFacePtr face_ptr
)
{
  if (m_face_count < 2)
    m_face2[m_face_count] = face_ptr;
  else if (nullptr != m_facex && m_face_count < 2 + m_facex_capacity)
    m_facex[m_face_count - 2] = face_ptr;
  else
  {
    // not enough room in m_facex.
    // If you really are trying to make a non-manifold subd, 
    // then use ON_SubD::GrowEdgeFaceArray().
    return ON_SUBD_RETURN_ERROR(false);
  }
  m_face_count++;
  return true;
}

bool ON_SubDEdge::RemoveFaceFromArray(
  unsigned int i,
  ON_SubDFacePtr& removed_face
  )
{
  removed_face = ON_SubDFacePtr::Null;
  unsigned int count = m_face_count;
  if ( i >= count )
    return ON_SUBD_RETURN_ERROR(false);
  if (i < 2)
  {
    removed_face = m_face2[i];
  }
  if (count > 2)
  {
    if ( nullptr == m_facex || m_facex_capacity + ((unsigned short)2) < m_face_count )
      return ON_SUBD_RETURN_ERROR(false);
    if ( i >= 2 )
      removed_face = m_facex[i-2];
  }

  unsigned int j = i+1;

  while (j < 2 && j < count )
    m_face2[i++] = m_face2[j++];

  if (count > 2)
  {
    m_face2[1] = m_facex[0];
    i = 0;
    j = 1;
    count -= 2;
    while (j < count )
      m_facex[i++] = m_facex[j++];
  }

  m_face_count--;

  return true;

}

bool ON_SubDFace::ReplaceEdgeInArray(
  unsigned int fei0,
  ON_SubDEdge* edge_to_remove,
  ON_SubDEdge* edge_to_insert
)
{
  const unsigned int face_edge_count = m_edge_count;
  ON_SubDEdgePtr* eptr = m_edge4;
  for (unsigned int fei = 0; fei < face_edge_count; fei++, eptr++)
  {
    if (4 == fei)
    {
      eptr = m_edgex;
      if (nullptr == eptr)
        break;
    }
    if (fei >= fei0 && edge_to_remove == eptr->Edge() )
    {
      const ON__UINT_PTR edir = eptr->EdgeDirection();
      *eptr = ON_SubDEdgePtr::Create(edge_to_insert,edir);
      return true;
    }
  }
  return false;
}


bool ON_SubDFace::RemoveEdgeFromArray(
  unsigned int i,
  ON_SubDEdgePtr& removed_edge
  )
{
  removed_edge = ON_SubDEdgePtr::Null;
  unsigned int count = m_edge_count;
  if ( i >= count )
    return ON_SUBD_RETURN_ERROR(false);
  if (i < 4)
  {
    removed_edge = m_edge4[i];
  }
  if (count > 4)
  {
    if ( nullptr == m_edgex || m_edgex_capacity + ((unsigned short)4) < m_edge_count )
      return ON_SUBD_RETURN_ERROR(false);
    if ( i >= 4 )
      removed_edge = m_edgex[i-4];
  }

  unsigned int j = i+1;

  while (j < 4 && j < count )
    m_edge4[i++] = m_edge4[j++];

  if (count > 4)
  {
    m_edge4[3] = m_edgex[0];
    i = 0;
    j = 1;
    count -= 4;
    while (j < count )
      m_edgex[i++] = m_edgex[j++];
  }

  m_edge_count--;

  return true;
}


bool ON_SubDFace::RemoveEdgeFromArray(
  const ON_SubDEdge* e
  )
{
  unsigned int i;
  if (nullptr == e)
    return false;

  if (m_edge_count <= 4)
  {
    for (i = 0; i < m_edge_count; i++)
    {
      if (e == ON_SUBD_EDGE_POINTER(m_edge4[i].m_ptr))
      {
        for (i++; i < m_edge_count; i++)
          m_edge4[i - 1] = m_edge4[i];
        m_edge_count--;
        return true;
      }
    }
  }
  else
  {
    for (i = 0; i < 4; i++)
    {
      if (e == ON_SUBD_EDGE_POINTER(m_edge4[i].m_ptr))
      {
        for (i++; i < 4; i++)
          m_edge4[i - 1] = m_edge4[i];
        m_edge4[3] = m_edgex[0];
        for (i = 5; i < m_edge_count; i++)
          m_edgex[i - 5] = m_edgex[i - 4];
        m_edge_count--;
        return true;
      }
    }
    for (i = 4; i < m_edge_count; i++)
    {
      if (e == ON_SUBD_EDGE_POINTER(m_edgex[i - 4].m_ptr))
      {
        for (i++; i < m_edge_count; i++)
          m_edgex[i - 5] = m_edgex[i - 4];
        m_edge_count--;
        return true;
      }
    }
  }

  return false;
}

unsigned int ON_SubDFace::VertexIndex(
  const ON_SubDVertex* vertex
  ) const
{
  if (nullptr == vertex)
    return ON_UNSET_UINT_INDEX;

  const ON_SubDEdgePtr* face_edges = m_edge4;
  const unsigned int edge_count = m_edge_count;

  for (unsigned int i = 0; i < edge_count; i += 2)
  {
    if (4 == i)
    {
      face_edges = m_edgex;
      if (nullptr == face_edges)
        break;
      face_edges -= 4;
    }
    ON__UINT_PTR e_ptr = face_edges[i].m_ptr;
    const ON_SubDEdge* edge = ON_SUBD_EDGE_POINTER(e_ptr);
    if (nullptr != edge)
    {
      if (vertex == edge->m_vertex[0])
        return (0 == ON_SUBD_EDGE_DIRECTION(e_ptr)) ? i : ((i + 1) % edge_count);
      if (vertex == edge->m_vertex[1])
        return (0 == ON_SUBD_EDGE_DIRECTION(e_ptr)) ? ((i + 1) % edge_count) : i;
    }
  }

  return ON_UNSET_UINT_INDEX;
}

//////////////////////////////////////////////////////////////////////////
//
// ON_SubD
//

ON_OBJECT_IMPLEMENT(ON_SubD,ON_Geometry,"F09BA4D9-455B-42C3-BA3B-E6CCACEF853B");

ON_SubD::ON_SubD() ON_NOEXCEPT
  : ON_Geometry()
{}

ON_SubD::~ON_SubD()
{
  this->Destroy();
}


#if defined(ON_HAS_RVALUEREF)
ON_SubD::ON_SubD( ON_SubD&& src ) ON_NOEXCEPT
  : ON_Geometry(std::move(src))
  , m_subdimple_sp(std::move(src.m_subdimple_sp))
{}

ON_SubD& ON_SubD::operator=( ON_SubD&& src )
{
  if ( this != &src )
  {
    this->Destroy();
    ON_Geometry::operator=(std::move(src));
    m_subdimple_sp = std::move(src.m_subdimple_sp);
  }
  return *this;
}
#endif


ON__UINT64 ON_SubD::RuntimeSerialNumber() const
{
  ON_SubDimple* subdimple = m_subdimple_sp.get();
  return (nullptr != subdimple) ? subdimple->RuntimeSerialNumber : 0;
}



//////////////////////////////////////////////////////////////////////////
//
// ON_SubD - ON_Object overrides
//

//virtual 
void ON_SubD::MemoryRelocate()
{
}

static bool ON_SubDIsNotValid(bool bSilentError)
{
  ON_SubDIncrementErrorCount();
  return bSilentError ? false : ON_IsNotValid();
}

static bool EdgeVertexWeightIsSet(
  double edge_vertex_weight
  )
{
  return (0.0 < edge_vertex_weight && edge_vertex_weight < 1.0);
}

static bool EdgeSectorWeightIsValid(
  double edge_vertex_weight,
  ON_SubD::SubDType subdivision_type,
  const ON_SubDEdge* edge
  )
{
  if (0.0 <= edge_vertex_weight && edge_vertex_weight < 1.0)
    return true;

  if (ON_SubDSectorType::UnsetSectorWeight == edge_vertex_weight && ON_SubD::SubDType::Unset == subdivision_type && nullptr != edge && 0 == edge->m_level)
    return true;

  return false;
}

static bool IsValidVertexEdgeLink(
  const ON_SubDVertex* vertex,
  const ON_SubDEdge* edge,
  ON__UINT_PTR end_index,
  ON_SubD::SubDType subdivision_type,
  bool bSilentError
  )
{
  if (nullptr == vertex || nullptr == edge)
    return ON_SubDIsNotValid(bSilentError);

  if (end_index > 1)
    return ON_SubDIsNotValid(bSilentError);

  if (edge->m_vertex[end_index] != vertex)
    return ON_SubDIsNotValid(bSilentError);

  if (vertex->m_level != edge->m_level)
    return ON_SubDIsNotValid(bSilentError);

  if (false == EdgeSectorWeightIsValid(edge->m_sector_coefficient[end_index],subdivision_type,edge))
    return ON_SubDIsNotValid(bSilentError);

  //const ON__UINT_PTR corner_type = edge->m_vertex[end_index].CornerType();
  //if (ON_SubDVertexPtr::NoCorner != corner_type && ON_SubD::VertexTag::Corner != vertex->m_vertex_tag)
  //  return ON_SubDIsNotValid(bSilentError);

  if ( edge->IsSmooth() )
  {
    // edge->m_edge_tag is ON_SubD::EdgeTag::Smooth or ON_SubD::EdgeTag::X
    if (ON_SubD::VertexTag::Smooth == vertex->m_vertex_tag)
    {
      if (false == (0.0 == edge->m_sector_coefficient[end_index]))
        return ON_SubDIsNotValid(bSilentError);
    }
    else
    {
      const unsigned int tagged_end_index = edge->TaggedEndIndex();
      if (ON_SubD::EdgeTag::X == edge->m_edge_tag)
      {
        if (2 != tagged_end_index)
          return ON_SubDIsNotValid(bSilentError);
      }
      else
      {
        if (tagged_end_index != (unsigned int)end_index)
          return ON_SubDIsNotValid(bSilentError);
      }

      if (ON_SubD::SubDType::Unset == subdivision_type)
      {
        if (false == (ON_SubDSectorType::UnsetSectorWeight == edge->m_sector_coefficient[end_index]))
          return ON_SubDIsNotValid(bSilentError);
      }
      else
      {
        ON_SubDSectorType st = ON_SubDSectorType::Create(subdivision_type,edge,(unsigned int)end_index);
        if (!st.IsValid())
          return ON_SubDIsNotValid(bSilentError);

        const double expected_vertex_weight = st.SectorWeight();
        if (false == (expected_vertex_weight == edge->m_sector_coefficient[end_index]))
          return ON_SubDIsNotValid(bSilentError);

        if (false == EdgeVertexWeightIsSet(expected_vertex_weight))
          return ON_SubDIsNotValid(bSilentError);
      }
    }
  }
  else if(ON_SubD::EdgeTag::Crease == edge->m_edge_tag)
  {
    // crease edge
    if (!(0.0 == edge->m_sector_coefficient[end_index]))
      return ON_SubDIsNotValid(bSilentError);

    if (ON_SubD::VertexTag::Smooth == vertex->m_vertex_tag)
      return ON_SubDIsNotValid(bSilentError);

    if (ON_SubD::VertexTag::Unset == vertex->m_vertex_tag)
      return ON_SubDIsNotValid(bSilentError);
  }
  else
  {
    return ON_SubDIsNotValid(bSilentError);
  }

  return true;
}

static bool IsValidVertexFaceLink(
  const ON_SubDVertex* vertex,
  const ON_SubDFace* face,
  unsigned int vertex_face_index,
  unsigned int face_vertex_index,
  bool bSilentError
  )
{
  if (nullptr == vertex || nullptr == face)
    return ON_SubDIsNotValid(bSilentError);

  if (vertex->m_level != face->m_level)
    return ON_SubDIsNotValid(bSilentError);

  const unsigned int vertex_face_count = vertex->m_face_count;
  if (vertex_face_count <= 0)
    return ON_SubDIsNotValid(bSilentError);
  if (nullptr == vertex->m_faces)
    return ON_SubDIsNotValid(bSilentError);

  if (vertex_face_index >= vertex_face_count && ON_UNSET_UINT_INDEX != vertex_face_index)
    return ON_SubDIsNotValid(bSilentError);

  const unsigned int face_vertex_count = face->m_edge_count;
  if (face_vertex_count <= 0)
    return ON_SubDIsNotValid(bSilentError);
  if (face_vertex_count > 4 && nullptr == face->m_edgex)
    return ON_SubDIsNotValid(bSilentError);

  if (face_vertex_index >= face_vertex_count && ON_UNSET_UINT_INDEX != face_vertex_index)
    return ON_SubDIsNotValid(bSilentError);

  for (unsigned int i = 0; i < vertex_face_count; i++)
  {
    if (face == vertex->Face(i))
    {
      if (ON_UNSET_UINT_INDEX == vertex_face_index)
        vertex_face_index = i;
      else if (i != vertex_face_index)
        return ON_SubDIsNotValid(bSilentError);
    }
    else if (i == vertex_face_index)
    {
      return ON_SubDIsNotValid(bSilentError);
    }
  }

  for (unsigned int i = 0; i < face_vertex_count; i++)
  {
    if (vertex == face->Vertex(i))
    {
      if (ON_UNSET_UINT_INDEX == face_vertex_index)
        face_vertex_index = i;
      else if (i != face_vertex_index)
        return ON_SubDIsNotValid(bSilentError);
    }
    else if (i == face_vertex_index)
    {
      return ON_SubDIsNotValid(bSilentError);
    }
  }

  return true;
}


static bool IsValidEdgeFaceLink(
  const ON_SubDEdge* edge,
  const ON_SubDFace* face,
  unsigned int edge_face_index,
  unsigned int face_edge_index,
  bool bSilentError
  )
{
  if (nullptr == edge || nullptr == face)
    return ON_SubDIsNotValid(bSilentError);

  if (edge->m_level != face->m_level)
    return ON_SubDIsNotValid(bSilentError);

  const unsigned int edge_face_count = edge->m_face_count;
  if (edge_face_count <= 0)
    return ON_SubDIsNotValid(bSilentError);
  if (edge_face_count > 2 && nullptr == edge->m_facex)
    return ON_SubDIsNotValid(bSilentError);

  if (edge_face_index >= edge_face_count && ON_UNSET_UINT_INDEX != edge_face_index)
    return ON_SubDIsNotValid(bSilentError);

  const unsigned int face_edge_count = face->m_edge_count;
  if (face_edge_count <= 0)
    return ON_SubDIsNotValid(bSilentError);
  if (face_edge_count > 4 && nullptr == face->m_edgex)
    return ON_SubDIsNotValid(bSilentError);

  if (face_edge_index >= face_edge_count && ON_UNSET_UINT_INDEX != face_edge_index)
    return ON_SubDIsNotValid(bSilentError);

  for (unsigned int i = 0; i < edge_face_count; i++)
  {
    if (face == edge->Face(i))
    {
      if (ON_UNSET_UINT_INDEX == edge_face_index)
        edge_face_index = i;
      else if (i != edge_face_index)
        return ON_SubDIsNotValid(bSilentError);
    }
    else if (i == edge_face_index)
    {
      return ON_SubDIsNotValid(bSilentError);
    }
  }

  for (unsigned int i = 0; i < face_edge_count; i++)
  {
    if (edge == face->Edge(i))
    {
      if (ON_UNSET_UINT_INDEX == face_edge_index)
        face_edge_index = i;
      else if (i != face_edge_index)
        return ON_SubDIsNotValid(bSilentError);
    }
    else if (i == face_edge_index)
    {
      return ON_SubDIsNotValid(bSilentError);
    }
  }

  return true;
}


static bool IsValidSubDVertex(
  const ON_SubDVertex* vertex,
  unsigned short level,
  unsigned int* vertex_id_range,
  unsigned short ordinary_valence_count,
  bool bSilentError
  )
{
  if (nullptr == vertex)
    return ON_SubDIsNotValid(bSilentError);
  
  if (level != vertex->m_level)
    return ON_SubDIsNotValid(bSilentError);
  
  if (nullptr != vertex_id_range)
  {
    if (vertex->m_id < vertex_id_range[0])
      return ON_SubDIsNotValid(bSilentError);
    if (vertex->m_id > vertex_id_range[1])
      return ON_SubDIsNotValid(bSilentError);
  }

  if ( vertex->m_edge_count < vertex->m_face_count)
    return ON_SubDIsNotValid(bSilentError);

  if (vertex->m_edge_count > 0 && nullptr == vertex->m_edges)
    return ON_SubDIsNotValid(bSilentError);

  if (vertex->m_face_count > 0 && nullptr == vertex->m_faces)
    return ON_SubDIsNotValid(bSilentError);

  switch (vertex->m_vertex_tag)
  {
  case ON_SubD::VertexTag::Smooth: // interior vertex
    if (vertex->m_edge_count != vertex->m_face_count)
      return ON_SubDIsNotValid(bSilentError);
    break;
  case ON_SubD::VertexTag::Crease:
    if (vertex->m_face_count <= 0)
      return ON_SubDIsNotValid(bSilentError);
    break;
  case ON_SubD::VertexTag::Corner:
    break;
  case ON_SubD::VertexTag::Dart: // interior vertex
    if (level > 0 && ordinary_valence_count != vertex->m_edge_count)
      return ON_SubDIsNotValid(bSilentError);
    if (vertex->m_edge_count != vertex->m_face_count)
      return ON_SubDIsNotValid(bSilentError);
    break;
  default:
    // invalid value for this enum
    return ON_SubDIsNotValid(bSilentError);
    break;
  }

  unsigned int count = vertex->m_edge_count;
  for (unsigned int i = 0; i < count; i++)
  {
    const ON_SubDEdge* edge = vertex->Edge(i);
    if (nullptr == edge)
      return ON_SubDIsNotValid(bSilentError);
  }

  count = vertex->m_face_count;
  for (unsigned int i = 0; i < count; i++)
  {
    const ON_SubDFace* face = vertex->Face(i);
    if (nullptr == face)
      return ON_SubDIsNotValid(bSilentError);
  }

  return true;
}

static bool IsValidSubDEdge(
  const ON_SubDEdge* edge,
  unsigned short level,
  unsigned int* edge_id_range,
  bool bSilentError
  )
{
  if (nullptr == edge)
    return ON_SubDIsNotValid(bSilentError);

  if (level != edge->m_level)
    return ON_SubDIsNotValid(bSilentError);

  if (nullptr != edge_id_range)
  {
    if (edge->m_id < edge_id_range[0])
      return ON_SubDIsNotValid(bSilentError);
    if (edge->m_id > edge_id_range[1])
      return ON_SubDIsNotValid(bSilentError);
  }

  const ON_SubDVertex* edge_vertex[2] = { 0 };
  for (unsigned int i = 0; i < 2; i++)
  {
    const ON_SubDVertex* vertex = edge->Vertex(i);
    if (nullptr == vertex)
      return ON_SubDIsNotValid(bSilentError);
    edge_vertex[i] = vertex;
  }
  if (edge_vertex[0] == edge_vertex[1])
    return ON_SubDIsNotValid(bSilentError);

  if (edge->IsSmooth())
  {
    // m_edge_tag is ON_SubD::EdgeTag::Smooth or ON_SubD::EdgeTag::X
    if ( 2 != edge->m_face_count)
      return ON_SubDIsNotValid(bSilentError);
  }
  else if (ON_SubD::EdgeTag::Crease != edge->m_edge_tag)
  {
    return ON_SubDIsNotValid(bSilentError);
  }

  if (edge->m_face_count > 2 && nullptr == edge->m_facex)
    return ON_SubDIsNotValid(bSilentError);


  return true;
}

static bool IsValidSubDFace(
  const ON_SubDFace* face,
  unsigned short level,
  unsigned int* face_id_range,
  unsigned short ordinary_face_edge_count,
  bool bSilentError
  )
{
  if (nullptr == face)
    return ON_SubDIsNotValid(bSilentError);

  if (level != face->m_level)
    return ON_SubDIsNotValid(bSilentError);

  if (nullptr != face_id_range)
  {
    if (face->m_id < face_id_range[0])
      return ON_SubDIsNotValid(bSilentError);
    if (face->m_id > face_id_range[1])
      return ON_SubDIsNotValid(bSilentError);
  }

  if (face->m_edge_count < 3)
    return ON_SubDIsNotValid(bSilentError);

  if (face->m_edge_count > 4 && nullptr == face->m_edgex)
    return ON_SubDIsNotValid(bSilentError);

  if (level > 0 && ordinary_face_edge_count != face->m_edge_count)
    return ON_SubDIsNotValid(bSilentError);

  return true;
}

bool ON_SubDimple::IsValidLevel(
  const ON_SubD& subd,
  unsigned int level_index,
  bool bSilentError,
  ON_TextLog* text_log
  ) const
{
  const unsigned int level_count = m_levels.UnsignedCount();
  if (level_index >= level_count || level_index >= 0xFFFF)
    return ON_SubDIsNotValid(bSilentError);
  const ON_SubDLevel* level = m_levels[level_index];
  if ( nullptr == level)
    return ON_SubDIsNotValid(bSilentError);

  if ( level->m_level_index != level_index)
    return ON_SubDIsNotValid(bSilentError);

  const ON_SubD::SubDType subdivision_type = level->m_subdivision_type;

  if (level_index <= 0)
  {
    if (level->m_vertex_count < 3)
      return ON_SubDIsNotValid(bSilentError);
    if (level->m_edge_count < 3)
      return ON_SubDIsNotValid(bSilentError);
    if (level->m_face_count < 1)
      return ON_SubDIsNotValid(bSilentError);
  }
  else
  {
    const ON_SubDLevel* previous_level = m_levels[level_index - 1];
    if (nullptr == previous_level)
      return ON_SubDIsNotValid(bSilentError);
    if (level->m_vertex_count <= previous_level->m_vertex_count)
      return ON_SubDIsNotValid(bSilentError);
    if (level->m_edge_count <= previous_level->m_edge_count)
      return ON_SubDIsNotValid(bSilentError);
    if (level->m_face_count <= previous_level->m_face_count)
      return ON_SubDIsNotValid(bSilentError);
    if (ON_SubD::SubDType::TriLoopWarren != level->m_subdivision_type && ON_SubD::SubDType::QuadCatmullClark != level->m_subdivision_type)
      return ON_SubDIsNotValid(bSilentError);
  }

  if (nullptr == level->m_vertex[0])
    return ON_SubDIsNotValid(bSilentError);
  if (nullptr == level->m_edge[0])
    return ON_SubDIsNotValid(bSilentError);
  if (nullptr == level->m_face[0])
    return ON_SubDIsNotValid(bSilentError);

  if (nullptr == level->m_vertex[1])
    return ON_SubDIsNotValid(bSilentError);
  if (nullptr == level->m_edge[1])
    return ON_SubDIsNotValid(bSilentError);
  if (nullptr == level->m_face[1])
    return ON_SubDIsNotValid(bSilentError);


  const unsigned short expected_level = (unsigned short)level_index;
  unsigned int i;
  const ON_SubDVertex* vertex;
  const ON_SubDEdge* edge;
  const ON_SubDFace* face;

  unsigned int v_id_range[2] = { ON_UNSET_UINT_INDEX, ON_UNSET_UINT_INDEX };
  unsigned int e_id_range[2] = { ON_UNSET_UINT_INDEX, ON_UNSET_UINT_INDEX };
  unsigned int f_id_range[2] = { ON_UNSET_UINT_INDEX, ON_UNSET_UINT_INDEX };

  unsigned int point_vertex_count = 0;
  unsigned int wire_edge_count = 0;

  // simple vertex validation
  if (level_index == subd.ActiveLevelIndex())
  {
    if (subd.FirstVertex() != level->m_vertex[0])
      return ON_SubDIsNotValid(bSilentError);
    ON_SubDVertexIterator vit = subd.VertexIterator();
    if (vit.FirstVertex() != level->m_vertex[0])
      return ON_SubDIsNotValid(bSilentError);
    ON_SubDVertexArray va = subd.VertexArray();
    if (va.VertexCount() != level->m_vertex_count)
      return ON_SubDIsNotValid(bSilentError);
    if (va[0] != level->m_vertex[0])
      return ON_SubDIsNotValid(bSilentError);
    if (va[level->m_vertex_count-1] != level->m_vertex[1])
      return ON_SubDIsNotValid(bSilentError);
  }
  const ON_SubDVertex* last_vertex = nullptr;
  for (i = 0, vertex = level->m_vertex[0]; i < level->m_vertex_count && nullptr != vertex; i++, vertex = vertex->m_next_vertex)
  {
    if (false == IsValidSubDVertex(vertex, expected_level, nullptr, level->m_ordinary_vertex_valence, bSilentError))
      return false;

    if (0 == i)
    {
      v_id_range[0] = v_id_range[1] = vertex->m_id;
    }
    else if (vertex->m_id < v_id_range[0])
      v_id_range[0] = vertex->m_id;
    else if (vertex->m_id > v_id_range[1])
      v_id_range[1] = vertex->m_id;

    if (0 == vertex->m_edge_count)
    {
      point_vertex_count++;
    }
    last_vertex = vertex;
  }
  if (level->m_vertex[1] != last_vertex)
    return ON_SubDIsNotValid(bSilentError);


  if (i != level->m_vertex_count || nullptr != vertex)
    return ON_SubDIsNotValid(bSilentError);
  if (1 + v_id_range[1] - v_id_range[0] < level->m_vertex_count)
    return ON_SubDIsNotValid(bSilentError);
  if ( v_id_range[1] > m_max_vertex_id )
    return ON_SubDIsNotValid(bSilentError);

  // currently, point vertices are not permitted
  if (point_vertex_count > 0)
    return ON_SubDIsNotValid(bSilentError);

  // simple edge validation
  if (level_index == subd.ActiveLevelIndex())
  {
    if (subd.FirstEdge() != level->m_edge[0])
      return ON_SubDIsNotValid(bSilentError);
    ON_SubDEdgeIterator eit = subd.EdgeIterator();
    if (eit.FirstEdge() != level->m_edge[0])
      return ON_SubDIsNotValid(bSilentError);
    ON_SubDEdgeArray ea = subd.EdgeArray();
    if (ea.EdgeCount() != level->m_edge_count)
      return ON_SubDIsNotValid(bSilentError);
    if (ea[0] != level->m_edge[0])
      return ON_SubDIsNotValid(bSilentError);
    if (ea[level->m_edge_count-1] != level->m_edge[1])
      return ON_SubDIsNotValid(bSilentError);
  }
  const ON_SubDEdge* last_edge = nullptr;
  for (i = 0, edge = level->m_edge[0]; i < level->m_edge_count && nullptr != edge; i++, edge = edge->m_next_edge)
  {
    if (false == IsValidSubDEdge(edge, expected_level, nullptr, bSilentError))
      return false;
    if (0 == edge->m_face_count)
    {
      wire_edge_count++;
    }
    if (0 == i)
    {
      e_id_range[0] = e_id_range[1] = edge->m_id;
    }
    else if (edge->m_id < e_id_range[0])
      e_id_range[0] = edge->m_id;
    else if (edge->m_id > e_id_range[1])
      e_id_range[1] = edge->m_id;

    last_edge = edge;
  }
  if (i != level->m_edge_count || nullptr != edge)
    return ON_SubDIsNotValid(bSilentError);
  if (1 + e_id_range[1] - e_id_range[0] < level->m_edge_count)
    return ON_SubDIsNotValid(bSilentError);
  if (level->m_edge[1] != last_edge)
    return ON_SubDIsNotValid(bSilentError);
  if ( e_id_range[1] > m_max_edge_id )
    return ON_SubDIsNotValid(bSilentError);
   
  // currently, wire edges are not permitted
  if (wire_edge_count > 0)
    return ON_SubDIsNotValid(bSilentError);
   
  // simple face validation
  if (level_index == subd.ActiveLevelIndex())
  {
    if (subd.FirstFace() != level->m_face[0])
      return ON_SubDIsNotValid(bSilentError);
    ON_SubDFaceIterator fit = subd.FaceIterator();
    if (fit.FirstFace() != level->m_face[0])
      return ON_SubDIsNotValid(bSilentError);
    ON_SubDFaceArray fa = subd.FaceArray();
    if (fa.FaceCount() != level->m_face_count)
      return ON_SubDIsNotValid(bSilentError);
    if (fa[0] != level->m_face[0])
      return ON_SubDIsNotValid(bSilentError);
    if (fa[0] != level->m_face[0])
      return ON_SubDIsNotValid(bSilentError);
  }
  const ON_SubDFace* last_face = nullptr;
  for (i = 0, face = level->m_face[0]; i < level->m_face_count && nullptr != face; i++, face = face->m_next_face)
  {
    if (false == IsValidSubDFace(face, expected_level, nullptr, level->m_ordinary_face_edge_count, bSilentError))
      return false;

    if (0 == i)
    {
      f_id_range[0] = f_id_range[1] = face->m_id;
    }
    else if (face->m_id < f_id_range[0])
      f_id_range[0] = face->m_id;
    else if (face->m_id > f_id_range[1])
      f_id_range[1] = face->m_id;

    last_face = face;
  }
  if (i != level->m_face_count || nullptr != face)
    return ON_SubDIsNotValid(bSilentError);
  if (1 + f_id_range[1] - f_id_range[0] < level->m_face_count)
    return ON_SubDIsNotValid(bSilentError);  
  if (level->m_face[1] != last_face)
    return ON_SubDIsNotValid(bSilentError);
  if ( f_id_range[1] > m_max_face_id )
    return ON_SubDIsNotValid(bSilentError);


  // vertex topology validation
  for (vertex = level->m_vertex[0]; nullptr != vertex; vertex = vertex->m_next_vertex)
  {
    for (i = 0; i < vertex->m_edge_count; i++)
    {
      edge = vertex->Edge(i);
      if (false == IsValidSubDEdge(edge, expected_level, e_id_range, bSilentError))
        return false;
      if (false == IsValidVertexEdgeLink(vertex, edge, vertex->EdgeDirection(i), subdivision_type, bSilentError))
        return false;
    }

    for (i = 0; i < vertex->m_face_count; i++)
    {
      face = vertex->Face(i);
      if (false == IsValidSubDFace(face, expected_level, f_id_range, level->m_ordinary_face_edge_count, bSilentError))
        return false;
      if (false == IsValidVertexFaceLink(vertex, face, i, ON_UNSET_UINT_INDEX, bSilentError))
        return false;
    }
  }

  // edge topology validation
  for (edge = level->m_edge[0]; nullptr != edge; edge = edge->m_next_edge)
  {
    for (i = 0; i < 2; i++)
    {
      vertex = edge->m_vertex[i];
      if (false == IsValidSubDVertex(vertex, expected_level, v_id_range, level->m_ordinary_vertex_valence, bSilentError))
        return false;
      if (false == IsValidVertexEdgeLink(vertex, edge, i, subdivision_type, bSilentError))
        return false;
    }

    for (i = 0; i < edge->m_face_count; i++)
    {
      face = edge->Face(i);
      if (false == IsValidSubDFace(face, expected_level, f_id_range, level->m_ordinary_face_edge_count, bSilentError))
        return false;
      if (false == IsValidEdgeFaceLink(edge, face, i, ON_UNSET_UINT_INDEX, bSilentError))
        return false;
    }
  }

  // face topology validation
  for (face = level->m_face[0]; nullptr != face; face = face->m_next_face)
  {
    for (i = 0; i < face->m_edge_count; i++)
    {
      edge = face->Edge(i);
      if (false == IsValidSubDEdge(edge, expected_level, e_id_range, bSilentError))
        return false;
      if (false == IsValidEdgeFaceLink(edge, face, ON_UNSET_UINT_INDEX, i, bSilentError))
        return false;
    }

    for (i = 0; i < face->m_edge_count; i++)
    {
      vertex = face->Vertex(i);
      if (false == IsValidSubDVertex(vertex, expected_level, v_id_range, level->m_ordinary_vertex_valence, bSilentError))
        return false;
      if (false == IsValidVertexFaceLink(vertex, face, ON_UNSET_UINT_INDEX, i, bSilentError))
        return false;
    }
  }

  return true;
}

bool ON_SubDimple::IsValid(
  const ON_SubD& subd,
  bool bSilentError,
  ON_TextLog* text_log
  ) const
{
  const unsigned int level_count = m_levels.UnsignedCount();
  if (level_count < 1)
  {
    return ON_SubDIsNotValid(bSilentError);
  }
  for (unsigned int level_index = 0; level_index < level_count; level_index++)
  {
    if (false == IsValidLevel(subd, level_index, bSilentError, text_log))
      return false;
  }
  
  if (false == m_heap.IsValid())
  {
    // id values are not increasing in the heap blocks.
    if (nullptr != text_log)
      text_log->Print("Component ids are not set correctly. m_heap.ResetId() will fix this but may break externally stored component references.\n");
    return ON_SubDIsNotValid(bSilentError);
  }

  if (MaximumVertexId() < m_heap.MaximumVertexId())
  {
    if (nullptr != text_log)
      text_log->Print("MaximumVertexId() = %u < m_heap.MaximumVertexId() = %u\n", MaximumVertexId(), m_heap.MaximumVertexId());
    return ON_SubDIsNotValid(bSilentError);
  }

  if (MaximumEdgeId() < m_heap.MaximumEdgeId())
  {
    if (nullptr != text_log)
      text_log->Print("MaximumEdgeId() = %u < m_heap.MaximumEdgeId() = %u\n", MaximumEdgeId(), m_heap.MaximumEdgeId());
    return ON_SubDIsNotValid(bSilentError);
  }

  if (MaximumFaceId() <m_heap.MaximumFaceId())
  {
    if (nullptr != text_log)
      text_log->Print("MaximumFaceId() = %u < m_heap.MaximumFaceId() = %u\n", MaximumFaceId(), m_heap.MaximumFaceId());
    return ON_SubDIsNotValid(bSilentError);
  }

  return true;
}

//virtual
bool ON_SubD::IsValid(ON_TextLog* text_logx) const
{
  // If low bit of text_log pointer is 1, then ON_Error is not called when the
  // knot vector is invalid.
  const ON__INT_PTR lowbit = 1;
  const ON__INT_PTR hightbits = ~lowbit;
  const bool bSilentError = (0 != (lowbit & ((ON__INT_PTR)text_logx)));
  ON_TextLog* text_log = (ON_TextLog*)(((ON__INT_PTR)text_logx) & hightbits);
  
  const ON_SubDimple* subdimple = SubDimple();
  if (nullptr == subdimple)
    return ON_SubDIsNotValid(bSilentError);

  return subdimple->IsValid(*this, bSilentError, text_log);
}

//virtual
void ON_SubD::Dump(ON_TextLog& text_log) const
{
  unsigned int component_sample_count = 16; // dump the first 16 vertices, edges, faces
  ON_2udex id_range;
  id_range.i = component_sample_count;
  id_range.j = 0;
  DumpTopology(id_range,id_range,id_range,text_log);
}

unsigned int ON_SubD::DumpTopology(ON_TextLog & text_log) const
{
  return DumpTopology(ON_2udex::Zero,ON_2udex::Zero,ON_2udex::Zero,text_log);
}


unsigned int ON_SubD::DumpTopology(
  ON_2udex vertex_id_range,
  ON_2udex edge_id_range,
  ON_2udex face_id_range,
  ON_TextLog& text_log
) const
{
  const class ON_SubDimple* subdimple = SubDimple();
  if (nullptr == subdimple)
  {
    text_log.Print(L"SubD: Empty\n");
    return 0;
  }

  const unsigned int level_count = LevelCount();
  const unsigned int active_level_index = ActiveLevel().m_level_index;

  const ON__UINT64 runtime_sn = (text_log.IsTextHash()) ? 0 : RuntimeSerialNumber(); // TextHash ignores settings that don't depend on 3dm file content.

  if (level_count > 1)
    text_log.Print(L"SubD[%" PRIu64 "]: %u levels. Level %u is active.\n", runtime_sn, level_count, active_level_index);
  else
    text_log.Print(L"SubD[%" PRIu64 "]:\n", runtime_sn );

  ON_SubDLevelIterator lit(subdimple->LevelIterator());

  const ON_2udex empty_id_range(ON_UNSET_UINT_INDEX, 0);

  unsigned int error_count = 0;
  for (const ON_SubDLevel* level = lit.First(); nullptr != level; level = lit.Next())
  {
    ON_TextLogIndent indent1(text_log);
    if (nullptr == level)
      continue;
    ON_2udex level_vertex_id_range
      = (0 != vertex_id_range.j || active_level_index == level->m_level_index)
      ? vertex_id_range
      : empty_id_range;
    ON_2udex level_edge_id_range
      = (0 != edge_id_range.j || active_level_index == level->m_level_index)
      ? edge_id_range
      : empty_id_range;
    ON_2udex level_face_id_range
      = (0 != face_id_range.j || active_level_index == level->m_level_index)
      ? face_id_range
      : empty_id_range;

    error_count += level->DumpTopology(
      subdimple->MaximumVertexId(),
      subdimple->MaximumEdgeId(),
      subdimple->MaximumFaceId(),
      level_vertex_id_range,
      level_edge_id_range, 
      level_face_id_range,
      text_log);
  }

  return error_count;
}

unsigned int ON_SubDLevel::DumpTopology(
  const unsigned int validate_max_vertex_id,
  const unsigned int validate_max_edge_id,
  const unsigned int validate_max_face_id,
  ON_2udex vertex_id_range,
  ON_2udex edge_id_range,
  ON_2udex face_id_range,
  ON_TextLog& text_log
) const
{
  // NOTE WELL:
  //  This is a debugging tool.
  //  The code in this function needs to work when the topology information is corrupt.
  const unsigned short level_index = (unsigned short)m_level_index;

  const unsigned int vertex_max_dump_count 
    = (vertex_id_range.i > 0 && vertex_id_range.i != ON_UNSET_UINT_INDEX && 0 == vertex_id_range.j)
    ? vertex_id_range.i 
    : 0;
  const unsigned int edge_max_dump_count 
    = (edge_id_range.i > 0 && edge_id_range.i != ON_UNSET_UINT_INDEX && 0 == edge_id_range.j)
    ? edge_id_range.i
    : 0;
  const unsigned int face_max_dump_count 
    = (face_id_range.i > 0 && face_id_range.i != ON_UNSET_UINT_INDEX && 0 == face_id_range.j)
    ? face_id_range.i 
    : 0;

  const bool bVertexIdTest = (vertex_max_dump_count > 0) || (vertex_id_range.i < vertex_id_range.j) || (ON_UNSET_UINT_INDEX == (vertex_id_range.i));
  const bool bEdgeIdTest =  (edge_max_dump_count > 0) || (edge_id_range.i < edge_id_range.j) || (ON_UNSET_UINT_INDEX == (edge_id_range.i));
  const bool bFaceIdTest =  (face_max_dump_count > 0) || (face_id_range.i < face_id_range.j) || (ON_UNSET_UINT_INDEX == (face_id_range.i));

  const char error_code_point = '!';
  char prefix[16] = {};

  unsigned int vertex_error_count = 0;
  unsigned int edge_error_count = 0;
  unsigned int face_error_count = 0;

  text_log.Print(L"SubD level %u topology: %u vertices, %u edges, ", m_level_index, m_vertex_count, m_edge_count);

  unsigned int ngon_count[65] = {};
  unsigned int maxN = (unsigned int)(sizeof(ngon_count) / sizeof(ngon_count[0])) - 1;

  unsigned int face_count = 0;
  unsigned int uniformN = 0;
  for (const ON_SubDFace* f = m_face[0]; nullptr != f; f = f->m_next_face)
  {
    if (face_count >= m_face_count && f->m_level != level_index)
      break;
    face_count++;
    unsigned int N = f->EdgeCount();
    if (1 == face_count)
      uniformN = N;
    else if (N != uniformN)
      uniformN = 0;
    unsigned int j = (N < maxN) ? N : maxN;
    if (N < maxN)
      ngon_count[j]++;
  }

  if (face_count != m_face_count)
    face_error_count++;


  if (uniformN > 0 && face_count == m_face_count)
  {
    if (3 == uniformN)
      text_log.Print(L"%u triangles\n", m_face_count);
    else if (4 == uniformN)
      text_log.Print(L"%u quads\n", m_face_count);
    else
      text_log.Print(L"%u %u-gons\n", m_face_count, uniformN);
  }
  else
  {
    text_log.Print(L"%u faces\n", m_face_count );
    text_log.PushIndent();
    for (unsigned int N = 0; N <= maxN; N++)
    {
      if (0 == ngon_count[N])
        continue;
      if (3 == N)
        text_log.Print(L"%u triangles\n", ngon_count[N]);
      else if (4 == N)
        text_log.Print(L"%u quads\n", ngon_count[N]);
      else if (N < maxN)
        text_log.Print(L"%u %u-gons\n", ngon_count[N], N);
      else
        text_log.Print(L"%u N-gons\n", ngon_count[N]);
    }
    text_log.PopIndent();
  }

  if (IsEmpty())
    return 0;

  ///////////////////////////////////////////////////////////////////
  //
  // Vertex Topology
  // vN (x, y, z)
  //   vEdges[vertex_edge_count] = { +eA, -eB, ... }
  //   vFaces[vertex_edge_count] = { fP, fQ, fR, ... }
  //
  unsigned int vertex_count = 0;
  unsigned int vertex_dump_count = 0;
  ON_2udex skipped_vertex_id = ON_2udex::Zero;
  unsigned int max_vertex_id = 0;
  for (const ON_SubDVertex* v = m_vertex[0]; nullptr != v; v = v->m_next_vertex)
  {
    if (vertex_count >= m_vertex_count && v->m_level != level_index)
      break;
    if (v->m_id > max_vertex_id)
      max_vertex_id = v->m_id;

    vertex_count++;

    if (bVertexIdTest)
    {
      bool bSkip = true;
      for (;;)
      {
        if (ON_UNSET_UINT_INDEX == vertex_id_range.i)
          break;
        if (vertex_max_dump_count > 0)
        {
          if (vertex_count > vertex_max_dump_count)
            break;
        }
        else
        {
          if (v->m_id < vertex_id_range.i || v->m_id >= vertex_id_range.j)
            break;
        }
        bSkip = false;
        break;
      }
      if (bSkip)
      {
        if (0 == skipped_vertex_id.j)
        {
          skipped_vertex_id.i = v->m_id;
          skipped_vertex_id.j = v->m_id;
        }
        else if (v->m_id < skipped_vertex_id.i)
          skipped_vertex_id.i = v->m_id;
        else if (v->m_id > skipped_vertex_id.j)
          skipped_vertex_id.j = v->m_id;
        continue;
      }
    }

    if (0 == vertex_dump_count)
      text_log.Print(L"Vertices:\n");
    vertex_dump_count++;
    ON_TextLogIndent vindent(text_log);

    text_log.Print(
      "v%u: (%g, %g, %g)\n",
      v->m_id, v->m_P[0], v->m_P[1], v->m_P[2]
    );

    text_log.PushIndent();

    const unsigned int vertex_edge_count = v->m_edge_count;
    text_log.Print("vEdges[%u] = {", vertex_edge_count);
    prefix[0] = ON_String::Space;
    prefix[1] = error_code_point;
    prefix[2] = 'e';
    prefix[3] = 0;
    for (unsigned int vei = 0; vei < vertex_edge_count; vei++)
    {
      prefix[1] = error_code_point;
      if (1 == vei)
      {
        prefix[0] = ',';
      }
      const ON_SubDEdge* e = v->Edge(vei);
      unsigned int eid = 0;
      if (nullptr != e)
      {
        if (v == e->m_vertex[0] && v != e->m_vertex[1])
          prefix[1] = '+';
        else if (v != e->m_vertex[0] && v == e->m_vertex[1])
          prefix[1] = '-';
        eid = e->m_id;
      }
      text_log.Print("%s%u", prefix, eid);
      if (error_code_point == prefix[1])
        vertex_error_count++;
    }
    text_log.Print(" }\n");

    const unsigned int vertex_face_count = v->m_face_count;
    text_log.Print("v.Faces[%u] = {", vertex_face_count);
    prefix[0] = ON_String::Space;
    prefix[1] = ON_String::Space;
    prefix[2] = 'f';
    prefix[3] = 0;
    for (unsigned int vfi = 0; vfi < vertex_face_count; vfi++)
    {
      prefix[1] = error_code_point;
      if (1 == vfi)
      {
        prefix[0] = ',';
      }
      const ON_SubDFace* f = v->Face(vfi);
      unsigned int fid = 0;
      if (nullptr != f)
      {
        if (f->VertexIndex(v) < ON_UNSET_UINT_INDEX)
          prefix[1] = ON_String::Space;
        fid = f->m_id;
      }
      text_log.Print("%s%u", prefix, fid);
      if (error_code_point == prefix[1])
        vertex_error_count++;
    }
    text_log.Print(" }\n");
    text_log.PopIndent();
  }

  text_log.PushIndent();
  if (vertex_dump_count > 0 && vertex_dump_count < vertex_count)
  {
    text_log.Print(
      L"... %u additional vertices (v%u to v%u).\n", 
      vertex_count-vertex_dump_count,
      skipped_vertex_id.i,
      skipped_vertex_id.j
    );
  }
  text_log.Print("Maximum vertex id = %u.  ",max_vertex_id);
  if (validate_max_vertex_id >= max_vertex_id)
    text_log.Print("Next id = %u.\n", validate_max_vertex_id + 1);
  else
    text_log.Print("ERROR Next id = %u.\n", validate_max_vertex_id + 1);
  text_log.PopIndent();

  ///////////////////////////////////////////////////////////////////
  //
  // Edge Topology
  // eN (+vA, -vB)
  //   eFaces[edge_face_count] = { fP, fQ, fR, ... }
  //
  unsigned int edge_count = 0;
  unsigned int edge_dump_count = 0;
  ON_2udex skipped_edge_id = ON_2udex::Zero;
  unsigned int max_edge_id = 0;
  for (const ON_SubDEdge* e = m_edge[0]; nullptr != e; e = e->m_next_edge)
  {
    if (edge_count >= m_edge_count && e->m_level != level_index)
      break;
    if (e->m_id > max_edge_id)
      max_edge_id = e->m_id;
    edge_count++;

    if (bEdgeIdTest)
    {
      bool bSkip = true;
      for (;;)
      {
        if (ON_UNSET_UINT_INDEX == edge_id_range.i)
          break;
        if (edge_max_dump_count > 0)
        {
          if (edge_count > edge_max_dump_count)
            break;
        }
        else
        {
          if (e->m_id < edge_id_range.i || e->m_id >= edge_id_range.j)
            break;
        }
        bSkip = false;
        break;
      }
      if (bSkip)
      {
        if (0 == skipped_edge_id.j)
        {
          skipped_edge_id.i = e->m_id;
          skipped_edge_id.j = e->m_id;
        }
        else if (e->m_id < skipped_edge_id.i)
          skipped_edge_id.i = e->m_id;
        else if (e->m_id > skipped_edge_id.j)
          skipped_edge_id.j = e->m_id;
        continue;
      }
    }

    if (0 == edge_dump_count)
      text_log.Print(L"Edges:\n");
    edge_dump_count++;
    ON_TextLogIndent eindent(text_log);

    text_log.Print(
      "e%u:  (",
      e->m_id
    );

    prefix[0] = ON_String::Space;
    prefix[1] = error_code_point;
    prefix[2] = 'v';
    prefix[3] = 0;
    for (unsigned int evi = 0; evi < 2; evi++)
    {
      if (1 == evi)
        text_log.Print(" to");
      prefix[1] = error_code_point;
      const ON_SubDVertex* v = e->m_vertex[evi];
      unsigned int vid = 0;
      if (nullptr != v)
      {
        vid = v->m_id;
        if (v->EdgeArrayIndex(e) < ON_UNSET_INT_INDEX)
          prefix[1] = ON_String::Space;
      }
      if (error_code_point == prefix[1])
        edge_error_count++;
      text_log.Print("%s%u", prefix, vid);
    }
    text_log.Print(")\n");

    text_log.PushIndent();

    const unsigned int edge_face_count = e->m_face_count;
    text_log.Print("eFaces[%u] = {", edge_face_count);
    prefix[0] = ON_String::Space;
    prefix[1] = error_code_point;
    prefix[2] = 'f';
    prefix[3] = 0;
    for (unsigned int efi = 0; efi < edge_face_count; efi++)
    {
      prefix[1] = error_code_point;
      if (1 == efi)
      {
        prefix[0] = ',';
      }
      ON_SubDFacePtr fptr = e->FacePtr(efi);
      const ON_SubDFace* f = fptr.Face();
      const ON__UINT_PTR edge_fdir = fptr.FaceDirection();
      unsigned int fid = 0;
      if (nullptr != f)
      {
        fid = f->m_id;
        ON_SubDEdgePtr eptr = f->EdgePtr(e);
        if (eptr.Edge() == e && eptr.EdgeDirection() == edge_fdir)
        {
          prefix[1] = (0 == edge_fdir) ? '+' : '-';
        }
      }
      if (error_code_point == prefix[1])
        edge_error_count++;
      text_log.Print("%s%u", prefix, fid);
    }
    text_log.Print(" }\n");
    text_log.PopIndent();
  }

  text_log.PushIndent();
  if (edge_dump_count > 0 && edge_dump_count < edge_count)
  {
    text_log.Print(L"... %u additional edges (e%u to e%u).\n",
      edge_count - edge_dump_count,
      skipped_edge_id.i,
      skipped_edge_id.j
    );
  }
  text_log.Print("Maximum edge id = %u.  ",max_edge_id);
  if (validate_max_edge_id >= max_edge_id)
    text_log.Print("Next id = %u.\n", validate_max_edge_id + 1);
  else
    text_log.Print("ERROR Next id = %u.\n", validate_max_edge_id + 1);
  text_log.PopIndent();


  ///////////////////////////////////////////////////////////////////
  //
  // Face Topology
  // fN
  //   fEdges[face_edge_count] = { +eA, -eB, +eC, ...}
  //   fVertices[face_edge_count] = { vP, vQ, vR, ... }
  //
  face_count = 0;
  unsigned int face_dump_count = 0;
  ON_2udex skipped_face_id = ON_2udex::Zero;
  unsigned int max_face_id = 0;
  for (const ON_SubDFace* f = m_face[0]; nullptr != f; f = f->m_next_face)
  {
    if (face_count >= m_face_count && f->m_level != level_index)
      break;
    if (f->m_id > max_face_id)
      max_face_id = f->m_id;
    face_count++;

    if (bFaceIdTest)
    {
      bool bSkip = true;
      for (;;)
      {
        if (ON_UNSET_UINT_INDEX == face_id_range.i)
          break;
        if (face_max_dump_count > 0)
        {
          if (face_count > face_max_dump_count)
            break;
        }
        else
        {
          if (f->m_id < face_id_range.i || f->m_id >= face_id_range.j)
            break;
        }
        bSkip = false;
        break;
      }
      if (bSkip)
      {
        if (0 == skipped_face_id.j)
        {
          skipped_face_id.i = f->m_id;
          skipped_face_id.j = f->m_id;
        }
        else if (f->m_id < skipped_face_id.i)
          skipped_face_id.i = f->m_id;
        else if (f->m_id > skipped_face_id.j)
          skipped_face_id.j = f->m_id;
        continue;
      }
    }

    if (0 == face_dump_count)
      text_log.Print(L"Faces:\n");
    face_dump_count++;
    ON_TextLogIndent eindent(text_log);

    text_log.Print(
      "f%u:\n",
      f->m_id
    );

    text_log.PushIndent();

    const unsigned int face_edge_count = f->m_edge_count;
    text_log.Print("fEdges[%u] = {", face_edge_count);
    prefix[0] = ON_String::Space;
    prefix[1] = error_code_point;
    prefix[2] = 'e';
    prefix[3] = 0;
    for (unsigned int fei = 0; fei < face_edge_count; fei++)
    {
      prefix[1] = error_code_point;
      if (1 == fei)
      {
        prefix[0] = ',';
      }
      const ON_SubDEdgePtr eptr = f->EdgePtr(fei);
      const ON_SubDEdge* e = eptr.Edge();
      const ON__UINT_PTR face_edir = eptr.EdgeDirection();
      unsigned int eid = 0;
      if (nullptr != e)
      {
        eid = e->m_id;
        ON_SubDFacePtr fptr = e->FacePtr(f);
        if (fptr.Face() == f && fptr.FaceDirection() == face_edir)
        {
          prefix[1] = (0 == face_edir) ? '+' : '-';
        }
      }
      if (error_code_point == prefix[1])
        face_error_count++;
      text_log.Print("%s%u", prefix, eid);
    }
    text_log.Print(" }\n");

    const ON_SubDEdgePtr last_eptr = f->EdgePtr(face_edge_count - 1);
    const ON_SubDEdge* last_edge = last_eptr.Edge();
    const ON_SubDVertex* v1
      = (nullptr != last_edge)
      ? last_edge->m_vertex[0 == last_eptr.EdgeDirection() ? 1 : 0]
      : nullptr;

    text_log.Print("fVertices[%u] = {", face_edge_count);
    prefix[0] = ON_String::Space;
    prefix[1] = error_code_point;
    prefix[2] = 'v';
    prefix[3] = 0;
    for (unsigned int fei = 0; fei < face_edge_count; fei++)
    {
      prefix[1] = error_code_point;
      if (1 == fei)
      {
        prefix[0] = ',';
      }
      const ON_SubDEdgePtr eptr = f->EdgePtr(fei);
      const ON_SubDEdge* e = eptr.Edge();
      const ON__UINT_PTR face_edir = eptr.EdgeDirection();
      unsigned int vid = 0;
      if (nullptr == e)
      {
        v1 = nullptr;
      }
      else
      {
        const ON_SubDVertex* v0 = e->m_vertex[0 == face_edir ? 0 : 1];
        if (nullptr != v0)
        {
          vid = v0->m_id;
          if (v1 == v0)
            prefix[1] = ON_String::Space;
        }
        v1 = e->m_vertex[0 == face_edir ? 1 : 0];
      }
      if (error_code_point == prefix[1])
        face_error_count++;
      text_log.Print("%s%u", prefix, vid);
    }
    text_log.Print(" }\n");

    text_log.PopIndent();
  }

  text_log.PushIndent();
  if (face_dump_count > 0 && face_dump_count < face_count)
  {
    text_log.Print(
      L"... %u additional faces (f%u to f%u).\n",
      face_count - face_dump_count,
      skipped_face_id.i,
      skipped_face_id.j
    );
  }
  text_log.Print("Maximum face id = %u.  ",max_face_id);
  if (validate_max_face_id >= max_face_id)
    text_log.Print("Next id = %u.\n", validate_max_face_id + 1);
  else
    text_log.Print("ERROR Next id = %u.\n", validate_max_face_id + 1);
  text_log.PopIndent();

 
  const unsigned int topology_error_count
    = vertex_error_count
    + edge_error_count
    + face_error_count;

  text_log.PushIndent();
  if (0 == topology_error_count)
  {
    text_log.Print("No topology inconsistencies.\n");
  }
  else
  {
    text_log.Print(
      "ERRORS: %u vertex, %u edge, %u face topology inconsistencies marked with \"%c\".\n", 
      vertex_error_count,
      edge_error_count,
      face_error_count, 
      error_code_point
    );
  }
  text_log.PopIndent();

  return topology_error_count;
}


//virtual
unsigned int ON_SubD::SizeOf() const
{
  size_t sz = ON_Geometry::SizeOf();
  sz += sizeof(*this) - sizeof(ON_Geometry);
  const ON_SubDimple* subdimple = SubDimple();
  if ( subdimple )
    sz += subdimple->SizeOf();
  return (unsigned int)sz;
}

//virtual
ON__UINT32 ON_SubD::DataCRC(ON__UINT32 current_remainder) const
{
  return 0;
}

//virtual
ON::object_type ON_SubD::ObjectType() const
{
  return ON::subd_object;
}

//virtual
void ON_SubD::DestroyRuntimeCache( bool bDelete )
{
  const ON_SubDimple* dimple = SubDimple();
  if (nullptr != dimple)
  {
    unsigned int level_count = dimple->LevelCount();
    for (unsigned int level_index = 0; level_index < level_count; level_index++)
    {
      const ON_SubDLevel* level = dimple->SubDLevel(level_index);
      if (level)
      {
        level->ClearBoundingBox();
        level->ClearEdgeFlags();
        level->ClearSubdivisonAndLimitPoints();
        level->m_limit_mesh = ON_SubDLimitMesh::Empty;
        level->AggregateComponentStatus().MarkAsNotCurrent();
      }
    }
  }
  return;
}

//virtual 
int ON_SubD::Dimension() const
{
  return 3;
}

//virtual
bool ON_SubD::GetBBox(
        double* boxmin,
        double* boxmax,
        bool bGrowBox
        ) const
{ 
  int j;
  for ( j = 0; j < 3 && bGrowBox; j++ )
  {
    if ( !ON_IsValid(boxmin[j]) || !ON_IsValid(boxmax[j]) || boxmin[j] > boxmax[j])
      bGrowBox = false;
  }

  ON_BoundingBox bbox = ON_BoundingBox::EmptyBoundingBox;
  bool rc = false;

  bbox = ActiveLevel().BoundingBox();
  rc = bbox.IsValid();
  if (rc)
  {
    if (bGrowBox)
    {
      if (bbox.m_min.x < boxmin[0]) boxmin[0] = bbox.m_min.x;
      if (bbox.m_max.x > boxmax[0]) boxmax[0] = bbox.m_max.x;
      if (bbox.m_min.y < boxmin[1]) boxmin[1] = bbox.m_min.y;
      if (bbox.m_max.y > boxmax[1]) boxmax[1] = bbox.m_max.y;
      if (bbox.m_min.z < boxmin[2]) boxmin[2] = bbox.m_min.z;
      if (bbox.m_max.z > boxmax[2]) boxmax[2] = bbox.m_max.z;
    }
    else
    {
      boxmin[0] = bbox.m_min.x; boxmin[1] = bbox.m_min.y; boxmin[2] = bbox.m_min.z;
      boxmax[0] = bbox.m_max.x; boxmax[1] = bbox.m_max.y; boxmax[2] = bbox.m_max.z;
    }
  }

  return (rc || bGrowBox);
}

//virtual
void ON_SubD::ClearBoundingBox()
{
  // For ON_SubD, ON_SubD::ClearBoundingBox() and ON_SubD::DestroyRuntimeCache(true)

  ON_SubD::DestroyRuntimeCache(true);
}

//virtual
bool ON_SubD::Transform( 
        const ON_Xform& xform
        )
{
  if ( this == &ON_SubD::Empty)
    return true;  // transform applied to empty subd is true on purpose

  // userdata transformation, etc.
  if (!this->ON_Geometry::Transform(xform))
    return false;

  ON_SubDimple* subdimple = SubDimple(false);
  if ( 0 == subdimple )
    return true;  // transform applied to empty subd is true on purpose

  return subdimple->Transform(xform);
}

//virtual
bool ON_SubD::IsDeformable() const
{
  return true;
}

//virtual
bool ON_SubD::MakeDeformable()
{
  return true;
}

//virtual
bool ON_SubD::SwapCoordinates(
      int i,
      int j
      )
{
  return false;
}

//virtual
bool ON_SubD::HasBrepForm() const
{
  return false;
}

//virtual
ON_Brep* ON_SubD::BrepForm( ON_Brep*) const
{
  return 0;
}

//virtual
ON_COMPONENT_INDEX ON_SubD::ComponentIndex() const
{
  return ON_Geometry::ComponentIndex();
}

//virtual
bool ON_SubD::EvaluatePoint( const class ON_ObjRef& objref, ON_3dPoint& P ) const
{
  return false;
}

//////////////////////////////////////////////////////////////
//
//
//

const class ON_SubDLevel& ON_SubD::ActiveLevel() const
{
  ON_SubDimple* subdimple = m_subdimple_sp.get();
  return (nullptr != subdimple) ? subdimple->ActiveLevel() : ON_SubDLevel::Empty;
}

class ON_SubDLevel const * ON_SubD::ActiveLevelConstPointer() const
{
  ON_SubDimple* subdimple = m_subdimple_sp.get();
  return (nullptr != subdimple) ? subdimple->ActiveLevelPointer() : nullptr;
}

class ON_SubDLevel* ON_SubD::ActiveLevelPointer()
{
  ON_SubDimple* subdimple = m_subdimple_sp.get();
  return (nullptr != subdimple) ? subdimple->ActiveLevelPointer() : nullptr;
}


ON_SubDimple* ON_SubD::SubDimple(bool bCreateIfNeeded)
{
  ON_SubDimple* subdimple = m_subdimple_sp.get();
  if (nullptr == subdimple && bCreateIfNeeded)
  {
    subdimple = new ON_SubDimple();
    m_subdimple_sp = std::shared_ptr<ON_SubDimple>(subdimple);
  }
  return subdimple;
}

const class ON_SubDimple* ON_SubD::SubDimple() const
{
  return m_subdimple_sp.get();
}

unsigned int ON_SubD::SubDimpleUseCount() const
{
  return (unsigned int)m_subdimple_sp.use_count();
}

void ON_SubD::ShareDimple(const ON_SubD& other_subd)
{
  if (m_subdimple_sp.get() != other_subd.m_subdimple_sp.get())
  {
    m_subdimple_sp.reset();
    m_subdimple_sp = other_subd.m_subdimple_sp;
  }
}

void ON_SubD::ShareDimple(const class ON_SubDLimitMeshImpl& subd_limple)
{
  std::shared_ptr<ON_SubDimple> limple_sp(subd_limple.m_subdimple_wp.lock());

  const ON_SubDimple* subd_imple = m_subdimple_sp.get();

  if (nullptr == limple_sp.get())
  {
    // weak pointer is nullptr, meaning there are no known references to the
    // subd used to create this limit mesh.
    const_cast<ON_SubDLimitMeshImpl&>(subd_limple).ClearFragmentFacePointers(true);
  }

  if (subd_imple != limple_sp.get())
  {
    m_subdimple_sp.reset();
    m_subdimple_sp = limple_sp;
  }
}

void ON_SubD::SwapDimple(class ON_SubDLimitMeshImpl& subd_limple )
{
  std::shared_ptr <ON_SubDimple> limple_sp(subd_limple.m_subdimple_wp.lock());
  if (m_subdimple_sp.get() != limple_sp.get())
  {
    m_subdimple_sp.swap(limple_sp);
    subd_limple.m_subdimple_wp = limple_sp;
  }
}


void ON_SubD::SwapDimple(ON_SubD& other_subd)
{
  if (this != &other_subd)
  {
    m_subdimple_sp.swap(other_subd.m_subdimple_sp);
  }
}

void ON_SubD::Clear()
{
  ON_SubDimple* subdimple = SubDimple(false);
  if ( subdimple )
    subdimple->Clear();
}

void ON_SubD::ClearHigherSubdivisionLevels(
  unsigned int max_level_index
  )
{
  ON_SubDimple* subdimple = SubDimple(false);
  if ( subdimple )
    subdimple->ClearHigherSubdivisionLevels(max_level_index);
}

void ON_SubD::ClearLowerSubdivisionLevels(
  unsigned int min_level_index
  )
{
  ON_SubDimple* subdimple = SubDimple(false);
  if ( subdimple )
    subdimple->ClearLowerSubdivisionLevels(min_level_index);
}

void ON_SubD::Destroy()
{
  m_subdimple_sp.reset();
}

bool ON_SubD::SetSubDType(
  ON_SubD::SubDType subdivision_type
  )
{
  ON_SubDimple* subdimple = SubDimple(true);
  return (subdimple) ? subdimple->SetSubDType(subdivision_type) : ON_SUBD_RETURN_ERROR(false);
}


class ON_SubDVertex* ON_SubD::AddVertex(
  const double* P
)
{
  return AddVertex(ON_SubD::VertexTag::Unset, P);
}

class ON_SubDVertex* ON_SubD::AddVertex(
  ON_SubD::VertexTag vertex_tag,
  const double* P
  )
{
  ON_SubDimple* subdimple = SubDimple(true);
  if ( 0 == subdimple )
    return 0;
  class ON_SubDVertex* v = subdimple->AllocateVertex(vertex_tag, 0, P); // 0 = level
  subdimple->AddVertexToLevel(v);
  return v;
}


class ON_SubDEdge* ON_SubDimple::AddEdge(
  ON_SubD::EdgeTag edge_tag, 
  ON_SubDVertex* v0,
  double v0_sector_weight,
  ON_SubDVertex* v1,
  double v1_sector_weight
  )
{
  if ( false == ON_SubDSectorType::IsValidSectorWeightValue(v0_sector_weight,true) )
    return ON_SUBD_RETURN_ERROR(nullptr);

  if ( false == ON_SubDSectorType::IsValidSectorWeightValue(v1_sector_weight,true) )
    return ON_SUBD_RETURN_ERROR(nullptr);    

  const bool bEdgeTagSet = ON_SubD::EdgeTagIsSet(edge_tag);

  if ( bEdgeTagSet
    && ON_SubDSectorType::IgnoredSectorWeight != v0_sector_weight 
    && ON_SubDSectorType::UnsetSectorWeight != v0_sector_weight
    && nullptr != v0
    && ON_SubD::VertexTag::Smooth == v0->m_vertex_tag
    )
  {
    // minimizes checking when building subds because constant crease weights can be passed in
    v0_sector_weight = ON_SubDSectorType::IgnoredSectorWeight;
  }

  if ( bEdgeTagSet
    && ON_SubDSectorType::IgnoredSectorWeight != v1_sector_weight
    && ON_SubDSectorType::UnsetSectorWeight != v1_sector_weight
    && nullptr != v1
    && ON_SubD::VertexTag::Smooth == v1->m_vertex_tag
    )
  {
    // minimizes checking when building subds because constant crease weights can be passed in
    v1_sector_weight = ON_SubDSectorType::IgnoredSectorWeight;
  }

  class ON_SubDEdge* e = AllocateEdge(edge_tag);
  if ( nullptr == e)
    return ON_SUBD_RETURN_ERROR(nullptr);

  for (unsigned int i = 0; i < 2; i++)
  {
    ON_SubDVertex* v = (i ? v1 : v0);
    double vertex_weight = (i ? v1_sector_weight : v0_sector_weight);
    e->m_vertex[i] = v;
    e->m_sector_coefficient[i] = vertex_weight;
    if (nullptr != v)
    {
      if (false == m_heap.GrowVertexEdgeArrayByOne(v))
      {
        v->m_status.SetDamagedState(true);
        ReturnEdge(e);
        return ON_SUBD_RETURN_ERROR(nullptr);
      }
      v->m_edges[v->m_edge_count++] = ON_SubDEdgePtr::Create(e, i);
      if (e->m_level < v->m_level)
        e->m_level = v->m_level;
      //v->m_vertex_edge_order = ON_SubD::VertexEdgeOrder::unset;
    }
  }

  if ( nullptr == AddEdgeToLevel(e) )
    return ON_SUBD_RETURN_ERROR(nullptr);

  return e;
}

ON_SubD::EdgeTag ON_SubD::EdgeTagFromContext(
  unsigned int edge_face_count,
  const ON_SubDVertex* v0,
  const ON_SubDVertex* v1
)
{
  return
    (nullptr != v0 && nullptr != v1)
    ? ON_SubD::EdgeTagFromContext(edge_face_count, v0->m_vertex_tag, v1->m_vertex_tag)
    : ON_SubD::EdgeTag::Unset;
}

ON_SubD::EdgeTag ON_SubD::EdgeTagFromContext(
  unsigned int edge_face_count,
  const ON_SubD::VertexTag v0_tag,
  const ON_SubD::VertexTag v1_tag
)
{
  ON_SubD::EdgeTag edge_tag = ON_SubD::EdgeTag::Unset;

  for(;;)
  {
    if (edge_face_count > 0x7FFFU)
      break;

    if (1 == edge_face_count || edge_face_count >= 3 )
    {
      edge_tag = ON_SubD::EdgeTag::Crease;
      break;
    }

    const bool bSmooth0 = ON_SubD::VertexTag::Smooth == v0_tag;
    const bool bSmooth1 = ON_SubD::VertexTag::Smooth == v1_tag;

    if ( bSmooth0 || bSmooth1 )
    {
      if ( 2 == edge_face_count && bSmooth0 && bSmooth1)
        edge_tag = ON_SubD::EdgeTag::Smooth;
      break;
    }

    if ( ON_SubD::VertexTagIsSet(v0_tag) && ON_SubD::VertexTagIsSet(v1_tag) )
    {
      if (2 == edge_face_count)
        edge_tag = ON_SubD::EdgeTag::X;
      break;
    }

    break;
  }

  return edge_tag;
}


class ON_SubDEdge* ON_SubD::AddEdge(
  ON_SubDVertex* v0,
  ON_SubDVertex* v1
)
{
  return ON_SubD::AddEdge(ON_SubD::EdgeTag::Unset, v0, v1);
}

class ON_SubDEdge* ON_SubD::AddEdge(
  ON_SubD::EdgeTag edge_tag,
  ON_SubDVertex* v0,
  ON_SubDVertex* v1
  )
{
  // NO automatic setting - causes more problems than it helps.
  // Users can call ON_SubD::EdgeTagFromContext() if they want to
  // preset the edge tag based on context.

  ////if (ON_SubD::EdgeTag::Unset == edge_tag && nullptr != v0 && nullptr != v1 )
  ////{
  ////  if ( v0->IsCreaseOrCornerOrDart() && v1->IsCreaseOrCornerOrDart() )
  ////    edge_tag = ON_SubD::EdgeTag::Crease;
  ////  else if ( ON_SubD::VertexTag::Unset != v0->m_vertex_tag 
  ////    && ON_SubD::VertexTag::Unset != v1->m_vertex_tag
  ////    && (v0->IsSmooth() || v1->IsSmooth())
  ////    )
  ////    edge_tag = ON_SubD::EdgeTag::Smooth;
  ////}

  return AddEdgeWithSectorCoefficients(
    edge_tag,
    v0,
    ON_SubDSectorType::UnsetSectorWeight,
    v1,
    ON_SubDSectorType::UnsetSectorWeight
    );
}

ON_SubDEdge* ON_SubD::AddEdgeWithSectorCoefficients(
    ON_SubD::EdgeTag edge_tag,
    class ON_SubDVertex* v0,
    double v0_sector_coefficient,
    class ON_SubDVertex* v1,
    double v1_sector_coefficient
    )
{
  ON_SubDimple* subdimple = SubDimple(true);
  if (nullptr != subdimple) 
    return subdimple->AddEdge(edge_tag, v0, v0_sector_coefficient, v1, v1_sector_coefficient);
  return ON_SUBD_RETURN_ERROR(nullptr);
}

class ON_SubDFace* ON_SubDimple::AddFace(
  unsigned int edge_count,
  const ON_SubDEdgePtr* edge
  )
{
  if ( edge_count > 0 && nullptr == edge)
    return ON_SUBD_RETURN_ERROR(nullptr);

  ON_SubDFace* f = AllocateFace();
  if ( nullptr == f)
    return ON_SUBD_RETURN_ERROR(nullptr);

  if (edge_count > 0)
  {
    if (edge_count > 4)
    {
      if (false == m_heap.GrowFaceEdgeArray(f,edge_count))
      {
        ReturnFace(f);
        return ON_SUBD_RETURN_ERROR(nullptr);
      }
    }


    ON_SubDEdgePtr* f_edge = f->m_edge4;
    unsigned short f_level = 0;
    for (unsigned int i = 0; i < edge_count; i++)
    {
      if (4 == i)
        f_edge = f->m_edgex - 4;

      f_edge[i] = edge[i];
      ON__UINT_PTR eptr = edge[i].m_ptr;
      ON_SubDEdge* e = ON_SUBD_EDGE_POINTER(eptr);
      if ( nullptr == e)
        continue;

      eptr = ON_SUBD_EDGE_DIRECTION(eptr);

      ON_SubDVertex* v = const_cast<ON_SubDVertex*>(e->m_vertex[eptr]);
      if (false == m_heap.GrowVertexFaceArrayByOne(v))
      {
        v->m_status.SetDamagedState(true);
        ReturnFace(f);
        return ON_SUBD_RETURN_ERROR(nullptr);
      }
      v->m_faces[v->m_face_count++] = f;
      //if (1 == v->m_face_count)
      //{
      //  if (4 == f->m_edge_count)
      //    v->m_vertex_facet_type = ON_SubD::VertexFacetType::Quad;
      //  else if (3 == f->m_edge_count)
      //    v->m_vertex_facet_type = ON_SubD::VertexFacetType::Tri;
      //  else if ( f->m_edge_count > 4)
      //    v->m_vertex_facet_type = ON_SubD::VertexFacetType::Ngon;
      //}
      //else
      //{
      //  const ON_SubDFace* f0 = v->m_faces[0];
      //  if (nullptr == f0 || f0->m_edge_count != f->m_edge_count)
      //    v->m_vertex_facet_type = ON_SubD::VertexFacetType::Mixed;
      //}
      //v->m_vertex_edge_order = ON_SubD::VertexEdgeOrder::unset;

      ON_SubDFacePtr* e_faces;
      if (e->m_face_count < 2)
      {
        e_faces = e->m_face2;
      }
      else
      {
        if (2 == e->m_face_count)
        {
          // Getting this error in a valid situation means it is time
          // to support non-manifold subdivision objects.
          ON_SubDIncrementErrorCount();
          ON_WARNING("creating non-manifold subdivision object");
        }
        if (false == m_heap.GrowEdgeFaceArrayByOne(e))
        {
          e->m_status.SetDamagedState(true);
          continue;
        }
        e_faces = e->m_facex - 2;
      }
      e_faces[e->m_face_count++] = ON_SubDFacePtr::Create(f, eptr);
      if (f_level < e->m_level)
        f_level = e->m_level;
    }

    f->m_level = f_level;
    f->m_edge_count = (unsigned short)edge_count;
  }

  if ( nullptr == AddFaceToLevel(f))
    return ON_SUBD_RETURN_ERROR(nullptr);

  return f;
}

unsigned int ON_SubDLevel::UpdateEdgeSectorCoefficients(
  bool bUnsetEdgeSectorCoefficientsOnly
  )
{
  unsigned int changed_edge_count = 0;
  const bool bUnsetSubdivisiontType = (false == ON_SubD::IsQuadOrTriSubDType(m_subdivision_type));

  for (const ON_SubDEdge* edge = m_edge[0]; nullptr != edge; edge = edge->m_next_edge)
  {
    ON_SubDEdge* e = const_cast<ON_SubDEdge*>(edge);
    if (bUnsetEdgeSectorCoefficientsOnly)
    {
      if (    e->m_sector_coefficient[0] >= 0.0 && e->m_sector_coefficient[0] <= 1.0
           && e->m_sector_coefficient[1] >= 0.0 && e->m_sector_coefficient[1] <= 1.0
         )
        continue;
    }
    const double  m_sector_coefficient0[2] = { e->m_sector_coefficient[0], e->m_sector_coefficient[1] };
    e->m_sector_coefficient[0] = ON_SubDSectorType::IgnoredSectorWeight;
    e->m_sector_coefficient[1] = ON_SubDSectorType::IgnoredSectorWeight;
    if (ON_SubD::EdgeTag::Smooth == edge->m_edge_tag || ON_SubD::EdgeTag::X == edge->m_edge_tag)
    {
      const unsigned int tagged_end_index = edge->TaggedEndIndex();
      if (tagged_end_index < 2)
      {
        e->m_sector_coefficient[tagged_end_index]
          = bUnsetSubdivisiontType
          ? ON_SubDSectorType::UnsetSectorWeight
          : ON_SubDSectorType::Create(m_subdivision_type, edge, tagged_end_index).SectorWeight();
      }
      else if (2 == tagged_end_index)
      {
        if (ON_SubD::EdgeTag::Smooth == edge->m_edge_tag)
          e->m_edge_tag = ON_SubD::EdgeTag::Crease;
        else if (ON_SubD::EdgeTag::X == edge->m_edge_tag)
        {
          e->m_sector_coefficient[0]
            = bUnsetSubdivisiontType
            ? ON_SubDSectorType::UnsetSectorWeight
            : ON_SubDSectorType::Create(m_subdivision_type, edge, 0).SectorWeight();
          e->m_sector_coefficient[1]
            = bUnsetSubdivisiontType
            ? ON_SubDSectorType::UnsetSectorWeight
            : ON_SubDSectorType::Create(m_subdivision_type, edge, 1).SectorWeight();
        }
      }
    }
    if (!(m_sector_coefficient0[0] == e->m_sector_coefficient[0] && m_sector_coefficient0[1] == e->m_sector_coefficient[1]))
      changed_edge_count++;
  }

  return changed_edge_count;
}

bool ON_SubDLevel::SetSubDType(
  ON_SubD::SubDType subd_type
  )
{
  const bool bQuadSubD = (ON_SubD::SubDType::QuadCatmullClark == subd_type);
  const bool bTriSubD = (ON_SubD::SubDType::TriLoopWarren == subd_type);
  if (false == bQuadSubD && false == bTriSubD)
    return ON_SUBD_RETURN_ERROR(false);

  const bool bUpdateEdgeWeights = (m_subdivision_type != subd_type);

  if (bQuadSubD)
  {
    m_subdivision_type = subd_type;
    m_ordinary_vertex_valence = 4;
    m_ordinary_face_edge_count = 4;
  }
  else if (bTriSubD)
  {
    m_subdivision_type = subd_type;
    m_ordinary_vertex_valence = 6;
    m_ordinary_face_edge_count = 3;
  }

  if (bUpdateEdgeWeights)
  {
    UpdateEdgeSectorCoefficients(false);
  }

  return true;
}

bool ON_SubDimple::SetSubDType(
  ON_SubD::SubDType subd_type
  )
{
  ON_SubDLevel* subd_level = ActiveLevel(0 == m_levels.UnsignedCount());
  if (nullptr == subd_level)
    return ON_SUBD_RETURN_ERROR(false);

  return subd_level->SetSubDType(subd_type);
}

class ON_SubDFace* ON_SubD::AddTriangleFace(
  class ON_SubDEdge* edge0, bool bReverseEdge0,
  class ON_SubDEdge* edge1, bool bReverseEdge1,
  class ON_SubDEdge* edge2, bool bReverseEdge2
)
{
  return AddTriangleFace(
    ON_SubDEdgePtr::Create(edge0, bReverseEdge0 ? 1 : 0),
    ON_SubDEdgePtr::Create(edge1, bReverseEdge1 ? 1 : 0),
    ON_SubDEdgePtr::Create(edge2, bReverseEdge2 ? 1 : 0)
  );
}

class ON_SubDFace* ON_SubD::AddTriangleFace(
  ON_SubDEdgePtr edge0,
  ON_SubDEdgePtr edge1,
  ON_SubDEdgePtr edge2
)
{
  ON_SubDEdgePtr eptr3[3] = { edge0,edge1,edge2 };
  return AddFace(3, eptr3);
}

class ON_SubDFace* ON_SubD::AddQuadFace(
  class ON_SubDEdge* edge0, bool bReverseEdge0,
  class ON_SubDEdge* edge1, bool bReverseEdge1,
  class ON_SubDEdge* edge2, bool bReverseEdge2,
  class ON_SubDEdge* edge3, bool bReverseEdge3
)
{
  return AddQuadFace(
    ON_SubDEdgePtr::Create(edge0, bReverseEdge0 ? 1 : 0),
    ON_SubDEdgePtr::Create(edge1, bReverseEdge1 ? 1 : 0),
    ON_SubDEdgePtr::Create(edge2, bReverseEdge2 ? 1 : 0),
    ON_SubDEdgePtr::Create(edge3, bReverseEdge3 ? 1 : 0)
  );
}

class ON_SubDFace* ON_SubD::AddQuadFace(
  ON_SubDEdgePtr edge0,
  ON_SubDEdgePtr edge1,
  ON_SubDEdgePtr edge2,
  ON_SubDEdgePtr edge3
  )
{
  ON_SubDEdgePtr eptr4[4] = { edge0,edge1,edge2,edge3 };
  return AddFace(4, eptr4);
}

class ON_SubDFace* ON_SubD::AddFace(
  unsigned int edge_count,
  const ON_SubDEdgePtr* edge
  )
{
  ON_SubDimple* subdimple = SubDimple(true);
  return (nullptr != subdimple) ? subdimple->AddFace(edge_count, edge) : nullptr;
}

bool ON_SubD::AddFaceEdgeConnection(
  ON_SubDFace* face,
  unsigned int i,
  ON_SubDEdge* edge,
  ON__UINT_PTR edge_direction
  )
{
  return AddFaceEdgeConnection(face, i, ON_SubDEdgePtr::Create(edge, edge_direction));
}

bool ON_SubD::AddFaceEdgeConnection(
  ON_SubDFace* face,
  unsigned int i,
  ON_SubDEdgePtr eptr
  )
{
  if (nullptr == face && i >= ON_SubDFace::MaximumEdgeCount)
  {
    return ON_SUBD_RETURN_ERROR(false);
  }

  unsigned int face_edge_count = (unsigned int)face->m_edge_count + 1U;
  if ( face_edge_count <= i )
    face_edge_count = i+1;

  ON_SubDEdge* edge = eptr.Edge();
  if (nullptr != edge)
  {
    if (edge->m_face_count >= edge->m_facex_capacity + (unsigned short)2)
    {
      if (false == GrowEdgeFaceArray(edge, 0))
        return ON_SUBD_RETURN_ERROR(false);
    }

    ON_SubDFacePtr fptr = ON_SubDFacePtr::Create(face,eptr.EdgeDirection());

    unsigned short efi = edge->m_face_count;
    if ( efi < 2 )
      edge->m_face2[efi] = fptr;
    else
    {
      if ( nullptr == edge->m_facex )
        return ON_SUBD_RETURN_ERROR(false);
      edge->m_facex[efi - 2] = fptr;
    }
    edge->m_face_count++;
  }

  if (face_edge_count > ((unsigned int)face->m_edgex_capacity) + 4U)
  {
    if (false == GrowFaceEdgeArray(face,face_edge_count))
      return ON_SUBD_RETURN_ERROR(false);
  }

  if (i >= ((unsigned int)face->m_edge_count))
  {
    unsigned int j = face->m_edge_count;
    for (/*empty init*/;j < 4; j++)
      face->m_edge4[j] = ON_SubDEdgePtr::Null;
    for (/*empty init*/;j < i; j++)
      face->m_edgex[j-4] = ON_SubDEdgePtr::Null;
  }
  else
  {
    for (unsigned int j = face_edge_count - 1; j > i; j--)
    {
      if (j > 4)
        face->m_edgex[j - 4] = face->m_edgex[j - 5];
      else if (4 == j)
        face->m_edgex[0] = face->m_edge4[3];
      else
        face->m_edge4[j] = face->m_edge4[j - 1];
    }
  }

  if ( i < 4 )
    face->m_edge4[i] = eptr;
  else 
    face->m_edgex[i-4] = eptr;
  face->m_edge_count = (unsigned short)face_edge_count;

  return true;
}


bool ON_SubD::RemoveFaceEdgeConnection(
  ON_SubDFace* face,
  ON_SubDEdge* edge
  )
{
  ON_SubDEdgePtr removed_edge;
  return RemoveFaceEdgeConnection(face, face->EdgeArrayIndex(edge), removed_edge);
}

bool ON_SubD::RemoveFaceEdgeConnection(
  ON_SubDFace* face,
  unsigned int i
  )
{
  ON_SubDEdgePtr removed_edge;
  return RemoveFaceEdgeConnection(face, i, removed_edge);
}

bool ON_SubD::RemoveFaceEdgeConnection(
  ON_SubDFace* face,
  unsigned int i,
  ON_SubDEdgePtr& removed_edge
  )
{
  removed_edge = ON_SubDEdgePtr::Null;
  if ( nullptr == face && i >= (unsigned int)face->m_edge_count )
  {
    return ON_SUBD_RETURN_ERROR(false);
  }

  if ( false == face->RemoveEdgeFromArray(i,removed_edge) )
    return ON_SUBD_RETURN_ERROR(false);

  ON_SubDEdge* edge = removed_edge.Edge();
  if ( nullptr == edge )
    return ON_SUBD_RETURN_ERROR(false);

  if (false == edge->RemoveFaceFromArray(face))
    return ON_SUBD_RETURN_ERROR(false);

  return true;
}


static bool ON_SubDFace_GetSubdivisionPointError(
  const class ON_SubDFace* face,
  double face_point[3],
  bool bDamagedState
  )
{
  if (nullptr == face || nullptr == face_point)
    return ON_SUBD_RETURN_ERROR(false); // caller passed a null pointer - edge is not necessarily damaged

  face->m_status.SetDamagedState(bDamagedState);

  return ON_SUBD_RETURN_ERROR(false);
}

bool ON_SubDFace::GetSubdivisionPoint(
    ON_SubD::SubDType subd_type,
    bool bUseSavedSubdivisionPoint,
    double subdivision_point[3]
  ) const
{
  if (nullptr == subdivision_point)
    return ON_SubDFace_GetSubdivisionPointError(this,subdivision_point,false);

  if (bUseSavedSubdivisionPoint && GetSavedSubdivisionPoint(subd_type,subdivision_point))
    return true;

  const unsigned int count = m_edge_count;
  if (count < 3)
    return ON_SubDFace_GetSubdivisionPointError(this, subdivision_point, true);

  double displacementV[3] = { 0 };
  const bool bApplyDisplacement = GetDisplacement(subd_type,displacementV);

  const class ON_SubDEdgePtr* edge_ptr = m_edge4;

  ON__UINT_PTR e_ptr;
  const ON_SubDEdge* e;
  ON__UINT_PTR edir;
  const double* vertexP[4];

  // Use faster code for the case when the face is a quad.
  // Since this is a Catmull-Clark subdivision scheme, this
  // case is the most common by far and code that gives quads
  // special treatment will run noticably faster.
  e_ptr = edge_ptr[0].m_ptr;
  e = ON_SUBD_EDGE_POINTER(e_ptr);
  edir = ON_SUBD_EDGE_DIRECTION(e_ptr);
  vertexP[0] = e->m_vertex[edir]->m_P;
  vertexP[1] = e->m_vertex[1 - edir]->m_P;

  e_ptr = edge_ptr[2].m_ptr;
  e = ON_SUBD_EDGE_POINTER(e_ptr);
  edir = ON_SUBD_EDGE_DIRECTION(e_ptr);
  vertexP[2] = e->m_vertex[edir]->m_P;
  vertexP[3] = e->m_vertex[1 - edir]->m_P;

  if (4 == count)
  {
    // most common case in quad subdivision schemes
    subdivision_point[0] = (vertexP[0][0] + vertexP[1][0] + vertexP[2][0] + vertexP[3][0])*0.25;
    subdivision_point[1] = (vertexP[0][1] + vertexP[1][1] + vertexP[2][1] + vertexP[3][1])*0.25;
    subdivision_point[2] = (vertexP[0][2] + vertexP[1][2] + vertexP[2][2] + vertexP[3][2])*0.25;

    if (bApplyDisplacement)
    {
      subdivision_point[0] += displacementV[0];
      subdivision_point[1] += displacementV[1];
      subdivision_point[2] += displacementV[2];
    }

    if (bUseSavedSubdivisionPoint)
      SetSavedSubdivisionPoint(subd_type,subdivision_point);


    return true;
  }

  if (3 == count)
  {
    // most common case in triangle subdivision schemes and
    // 2nd most common case in quad subdivision schemes
    subdivision_point[0] = (vertexP[0][0] + vertexP[1][0] + vertexP[2][0]) / 3.0;
    subdivision_point[1] = (vertexP[0][1] + vertexP[1][1] + vertexP[2][1]) / 3.0;
    subdivision_point[2] = (vertexP[0][2] + vertexP[1][2] + vertexP[2][2]) / 3.0;

    if (bApplyDisplacement)
    {
      subdivision_point[0] += displacementV[0];
      subdivision_point[1] += displacementV[1];
      subdivision_point[2] += displacementV[2];
    }

    if (bUseSavedSubdivisionPoint)
      SetSavedSubdivisionPoint(subd_type,subdivision_point);

    return true;
  }

  // count > 4
  double faceP[3]
    = {
    (vertexP[0][0] + vertexP[1][0] + vertexP[2][0] + vertexP[3][0]),
    (vertexP[0][1] + vertexP[1][1] + vertexP[2][1] + vertexP[3][1]),
    (vertexP[0][2] + vertexP[1][2] + vertexP[2][2] + vertexP[3][2]) 
    };

  if (nullptr == m_edgex)
  {
    return ON_SubDFace_GetSubdivisionPointError(this, subdivision_point, true);
  }

  edge_ptr = m_edgex - 4; // -4 because index i begins at 4
  unsigned int i;
  for (i = 4; i + 1 < count; i += 2)
  {
    e_ptr = edge_ptr[i].m_ptr;
    e = ON_SUBD_EDGE_POINTER(e_ptr);
    edir = ON_SUBD_EDGE_DIRECTION(e_ptr);
    vertexP[0] = e->m_vertex[edir]->m_P;
    vertexP[1] = e->m_vertex[1 - edir]->m_P;

    faceP[0] += vertexP[0][0];
    faceP[1] += vertexP[0][1];
    faceP[2] += vertexP[0][2];

    faceP[0] += vertexP[1][0];
    faceP[1] += vertexP[1][1];
    faceP[2] += vertexP[1][2];
  }

  if (i < count)
  {
    // odd number of edges and vertices
    e_ptr = edge_ptr[count - 1].m_ptr;
    e = ON_SUBD_EDGE_POINTER(e_ptr);
    edir = ON_SUBD_EDGE_DIRECTION(e_ptr);
    vertexP[0] = e->m_vertex[edir]->m_P;
    faceP[0] += vertexP[0][0];
    faceP[1] += vertexP[0][1];
    faceP[2] += vertexP[0][2];
  }

  const double n = count;

  subdivision_point[0] = faceP[0] / n;
  subdivision_point[1] = faceP[1] / n;
  subdivision_point[2] = faceP[2] / n;

  if (bApplyDisplacement)
  {
    subdivision_point[0] += displacementV[0];
    subdivision_point[1] += displacementV[1];
    subdivision_point[2] += displacementV[2];
  }

  if (bUseSavedSubdivisionPoint)
    SetSavedSubdivisionPoint(subd_type,subdivision_point);

  return true;
}

bool ON_SubDComponentBase::SetSavedSubdivisionPoint(
  ON_SubD::SubDType subd_type,
  const double subdivision_point[3]
  ) const
{
  if (ON_SubD::SubDType::Unset == subd_type)
  {
    ClearSavedSubdivisionPoint();
    return true;
  }
  
  if ( nullptr != subdivision_point
    && ON_IsValid(subdivision_point[0])
    && ON_IsValid(subdivision_point[1])
    && ON_IsValid(subdivision_point[2])
    )
  {
    const unsigned char c = (unsigned char)subd_type;
    if ( c != ON_SUBD_CACHE_TYPE(m_saved_points_flags))
      m_saved_points_flags = 0U;
    m_saved_subd_point1[0] = subdivision_point[0];
    m_saved_subd_point1[1] = subdivision_point[1];
    m_saved_subd_point1[2] = subdivision_point[2];
    m_saved_points_flags |= (ON_SUBD_CACHE_POINT_FLAG_MASK | c);
    return true;
  }

  ClearSavedSubdivisionPoint();
  return ON_SUBD_RETURN_ERROR(false);
}

bool ON_SubDComponentBase::GetSavedSubdivisionPoint(
  ON_SubD::SubDType subd_type,
  double subdivision_point[3]
  ) const
{
  if ( 0 == (ON_SUBD_CACHE_POINT_FLAG_MASK & m_saved_points_flags) )
    return false;

  if ( subd_type != (ON_SubD::SubDType)ON_SUBD_CACHE_TYPE(m_saved_points_flags) )
    return false;

  if (nullptr != subdivision_point)
  {
    subdivision_point[0] = m_saved_subd_point1[0];
    subdivision_point[1] = m_saved_subd_point1[1];
    subdivision_point[2] = m_saved_subd_point1[2];
  }

  return true;
}


const ON_ComponentStatus ON_SubDComponentBase::Status() const
{
  return m_status;
}

const ON_ComponentStatus ON_SubDVertex::NeighborhoodStatusLogicalOr(
  bool bIncludeEdges,
  bool bIncludeFaces
) const
{
  ON_ComponentStatus s(m_status);
  if (bIncludeEdges && nullptr != m_edges)
  {
    for (unsigned short vei = 0; vei < m_edge_count; vei++)
    {
      const ON_SubDEdge* e = m_edges[vei].Edge();
      if (nullptr != e)
        s = ON_ComponentStatus::LogicalOr(s, e->m_status);
    }
  }
  if (bIncludeFaces && nullptr != m_faces)
  {
    for (unsigned short vfi = 0; vfi < m_face_count; vfi++)
    {
      const ON_SubDFace* f = m_faces[vfi];
      if (nullptr != f)
        s = ON_ComponentStatus::LogicalOr(s, f->m_status);
    }
  }
  return s;
}
  
const ON_ComponentStatus ON_SubDEdge::NeighborhoodStatusLogicalOr(
  bool bIncludeVertices,
  bool bIncludeFaces
) const
{
  ON_ComponentStatus s(m_status);
  if (bIncludeVertices)
  {
    for (unsigned int evi = 0; evi < 2; evi++)
    {
      const ON_SubDVertex* v = m_vertex[evi];
      if (nullptr != v)
        s = ON_ComponentStatus::LogicalOr(s, v->m_status);
    }
  }
  if (bIncludeFaces)
  {
    const ON_SubDFacePtr* fptr = m_face2;
    for (unsigned short vfi = 0; vfi < m_face_count; vfi++)
    {
      const ON_SubDFace* f = fptr->Face();
      if (nullptr != f)
        s = ON_ComponentStatus::LogicalOr(s, f->m_status);
      if (1 == vfi)
      {
        fptr = m_facex;
        if (nullptr == fptr)
          break;
      }
      else
        fptr++;
    }
  }
  return s;
}

const ON_ComponentStatus ON_SubDFace::NeighborhoodStatusLogicalOr(bool bIncludeVertices, bool bIncludeEdges) const
{
  ON_ComponentStatus s(m_status);
  if (bIncludeVertices || bIncludeEdges)
  {
    const ON_SubDEdgePtr* eptr = m_edge4;
    for (unsigned int fei = 0; fei < m_edge_count; fei++)
    {
      if (4 == fei)
      {
        eptr = m_edgex;
        if (nullptr == eptr)
          break;
      }
      const ON_SubDEdge* e = eptr->Edge();
      if (nullptr != e)
      {
        if (bIncludeEdges)
        {
          s = ON_ComponentStatus::LogicalOr(s, e->m_status);
        }
        if (bIncludeVertices)
        {
          const ON_SubDVertex* v = e->m_vertex[(0!=eptr->EdgeDirection())?1:0];
          if (nullptr != v)
            s = ON_ComponentStatus::LogicalOr(s, v->m_status);
        }
      }
      eptr++;
    }
  }
  return s;
}

static void Internal_ClearFaceNeighborhoodCache(const ON_SubDFace* face)
{
  // Clear cached values for every component associated with this face.
  face->ClearSavedSubdivisionPoint();
  const ON_SubDEdgePtr* eptr = face->m_edge4;
  for (unsigned int efi = 0; efi < face->m_edge_count; efi++)
  {
    if (4 == efi)
    {
      eptr = face->m_edgex;
      if ( nullptr == eptr)
        break;
    }
    const ON_SubDEdge* edge = ON_SUBD_EDGE_POINTER(eptr->m_ptr);
    if (nullptr != edge)
    {
      edge->ClearSavedSubdivisionPoint();
      edge->UnsetSectorCoefficients();
      for (unsigned int evi = 0; evi < 2; evi++)
      {
        const ON_SubDVertex* vertex = edge->m_vertex[evi];
        if (nullptr != vertex)
        {
          vertex->ClearSavedSubdivisionPoint();
          vertex->ClearSavedLimitPoints();
        }
      }
    }
    eptr++;
  }
}

void ON_SubDVertex::VertexModifiedNofification() const
{
  ClearSavedSubdivisionPoint();
  ClearSavedLimitPoints();
  if (nullptr != m_edges)
  {
    for (unsigned short vei = 0; vei < m_edge_count; vei++)
    {
      const ON_SubDEdge* edge = ON_SUBD_EDGE_POINTER(m_edges[vei].m_ptr);
      if (nullptr != edge)
      {
        edge->ClearSavedSubdivisionPoint();
        edge->UnsetSectorCoefficients();
      }
    }

    // This is needed to clear cached information in the Catmull-Clark 
    // ring that is not immediately adjacent to this vertex but whose values
    // this vertex affects.
    for (unsigned short vfi = 0; vfi < m_face_count; vfi++)
    {
      const ON_SubDFace* face = this->m_faces[vfi];
      if (nullptr != face)
        Internal_ClearFaceNeighborhoodCache(face);
    }
  }
}

void ON_SubDEdge::EdgeModifiedNofification() const
{
  ClearSavedSubdivisionPoint();
  UnsetSectorCoefficients();
  for (unsigned int evi = 0; evi < 2; evi++)
  {
    const_cast<ON_SubDEdge*>(this)->m_sector_coefficient[evi] = ON_SubDSectorType::UnsetSectorWeight;
    if (nullptr != m_vertex[evi])
      m_vertex[evi]->VertexModifiedNofification();
  }

  // If the topology pointers are complete and accurate, then the following
  // is not required. It's here because this SubD may be under construction
  // and we cannot assume the topology pointers are complete and accurate.
  const ON_SubDFacePtr* fptr = m_face2;
  for (unsigned int efi = 0; efi < 2; efi++)
  {
    if (2 == efi)
    {
      fptr = m_facex;
      if ( nullptr == fptr)
        break;
    }
    const ON_SubDFace* face = ON_SUBD_FACE_POINTER(fptr->m_ptr);
    if ( nullptr != face )
      Internal_ClearFaceNeighborhoodCache(face);
    fptr++;
  }
}

void ON_SubDEdge::UnsetSectorCoefficients() const
{
  const_cast<ON_SubDEdge*>(this)->m_sector_coefficient[0] = ON_SubDSectorType::UnsetSectorWeight;
  const_cast<ON_SubDEdge*>(this)->m_sector_coefficient[1] = ON_SubDSectorType::UnsetSectorWeight;
}


void ON_SubDFace::FaceModifiedNofification() const
{
  Internal_ClearFaceNeighborhoodCache(this);

  // This is needed to clear cached information in the Catmull-Clark 
  // ring that is not immediately adjacent to this face but whose values
  // this face affects.
  const ON_SubDEdgePtr* eptr = m_edge4;
  for (unsigned int efi = 0; efi < m_edge_count; efi++)
  {
    if (4 == efi)
    {
      eptr = m_edgex;
      if ( nullptr == eptr)
        break;
    }
    const ON_SubDEdge* edge = ON_SUBD_EDGE_POINTER(eptr->m_ptr);
    if (nullptr != edge)
    {
      const ON_SubDFacePtr* fptr = edge->m_face2;
      for (unsigned short fei = 0; fei < edge->m_face_count; fei++)
      {
        if (2 == fei)
        {
          fptr = edge->m_facex;
          if (nullptr == fptr)
            break;
        }
        const ON_SubDFace* f = ON_SUBD_FACE_POINTER(fptr->m_ptr);
        if (nullptr != f && f != this)
          Internal_ClearFaceNeighborhoodCache(f);
      }
    }
    eptr++;
  }
}

void ON_SubDComponentBase::ClearSavedSubdivisionPoint() const
{
  ON_SUBD_CACHE_CLEAR_POINT_FLAG(m_saved_points_flags);
}

ON_SubD::SubDType ON_SubDComponentBase::SavedSubdivisionPointType() const
{
  return 
    (0 != (ON_SUBD_CACHE_POINT_FLAG_MASK & m_saved_points_flags))
    ? ((ON_SubD::SubDType)(ON_SUBD_CACHE_TYPE_MASK & m_saved_points_flags))
    : ON_SubD::SubDType::Unset;
}

ON_SubD::SubDType ON_SubDComponentBase::DisplacementType() const
{
  return 
    (0 != ON_SUBD_CACHE_DISPLACEMENT_FLAG(m_saved_points_flags))
    ? ((ON_SubD::SubDType)(ON_SUBD_CACHE_TYPE_MASK & m_saved_points_flags))
    : ON_SubD::SubDType::Unset;
}

bool ON_SubDComponentBase::SetDisplacement(
    ON_SubD::SubDType subd_type,
    const double displacement[3]
    )
{
  if ( ON_SubD::SubDType::Unset != subd_type
    && nullptr != displacement
    && ON_IsValid(displacement[0]) && ON_IsValid(displacement[1]) && ON_IsValid(displacement[2])
    )
  {
    if (0.0 == displacement[0] && 0.0 == displacement[1] && 0.0 == displacement[2])
    {
      ClearDisplacement();
      return true;
    }
    ON_SubD::SubDType f = (ON_SubD::SubDType)(ON_SUBD_CACHE_TYPE_MASK & m_saved_points_flags);
    if ( subd_type != f )
      m_saved_points_flags = (unsigned char)f;
    m_saved_points_flags |= ON_SUBD_CACHE_DISPLACEMENT_FLAG_MASK;
    m_displacement_V[0] = displacement[0];
    m_displacement_V[1] = displacement[1];
    m_displacement_V[2] = displacement[2];
    return true;
  }

  if (ON_SubD::SubDType::Unset == subd_type)
  {
    ClearDisplacement();
    return true;
  }
  
  return ON_SUBD_RETURN_ERROR(false);
}

void ON_SubDComponentBase::ClearDisplacement() const
{
  if (0 != (m_saved_points_flags & ON_SUBD_CACHE_DISPLACEMENT_FLAG_MASK))
  {
    ON_SUBD_CACHE_CLEAR_POINT_FLAG(m_saved_points_flags);
    ON_SUBD_CACHE_CLEAR_DISPLACEMENT_FLAG(m_saved_points_flags);
  }
}

bool ON_SubDComponentBase::GetDisplacement(
    ON_SubD::SubDType subd_type,
    double displacement[3]
    ) const
{
  const bool rc = (0 != (ON_SUBD_CACHE_DISPLACEMENT_FLAG_MASK & m_saved_points_flags))
        && subd_type == (ON_SubD::SubDType)(ON_SUBD_CACHE_TYPE_MASK & m_saved_points_flags);
  if (nullptr != displacement)
  {
    if (rc)
    {
      displacement[0] = m_displacement_V[0];
      displacement[1] = m_displacement_V[1];
      displacement[2] = m_displacement_V[2];
    }
    else
    {
      displacement[0] = 0.0;
      displacement[1] = 0.0;
      displacement[2] = 0.0;
    }
  }
  return rc;
}


bool ON_SubDFace::ReverseEdgeList()
{
  const unsigned int edge_count = m_edge_count;
  if ( 0 == edge_count)
    return true;
  if (edge_count > 4 && nullptr == m_edgex)
  {
    return ON_SUBD_RETURN_ERROR(false);
  }

  ON_SubDEdgePtr buffer[16];
  ON_SubDEdgePtr* reversed_eptrs;
  if ( edge_count <= sizeof(buffer)/sizeof(buffer[0]) )
    reversed_eptrs = buffer;
  else
  {
    reversed_eptrs = new(std::nothrow) ON_SubDEdgePtr[edge_count];
    if ( nullptr == reversed_eptrs)
      return ON_SUBD_RETURN_ERROR(false);
  }

  ON_SubDEdgePtr* face_eptrs = m_edge4;
  for (unsigned int fei = 0; fei < edge_count; fei++, face_eptrs++)
  {
    if (4 == fei)
      face_eptrs = m_edgex;

    ON_SubDEdge* e = ON_SUBD_EDGE_POINTER(face_eptrs->m_ptr);
    if ( nullptr == e)
      continue;
    ON__UINT_PTR edir = ON_SUBD_EDGE_DIRECTION(face_eptrs->m_ptr);
    reversed_eptrs[edge_count-1-fei] = ON_SubDEdgePtr::Create(e,1-edir);

    ON_SubDFacePtr* edges_fptrs = e->m_face2;
    const unsigned int face_count = e->m_face_count;
    for (unsigned int efi = 0; efi < face_count; efi++, edges_fptrs++)
    {
      if (2 == efi)
      {
        edges_fptrs = e->m_facex;
        if ( nullptr == edges_fptrs)
          break;
      }
      if ( this != ON_SUBD_FACE_POINTER(edges_fptrs->m_ptr) )
        continue;
      *edges_fptrs = ON_SubDFacePtr::Create(this,1-ON_SUBD_FACE_DIRECTION(edges_fptrs->m_ptr));
      break;
    } 
  }

  face_eptrs = m_edge4;
  for (unsigned int fei = 0; fei < edge_count; fei++)
  {
    if (4 == fei)
      face_eptrs = m_edgex;
    *face_eptrs++ = reversed_eptrs[fei];
  }

  if ( reversed_eptrs != buffer )
    delete[] reversed_eptrs;

  return true;
}

static bool ON_SubDEdge_GetSubdivisionPointError(
  const class ON_SubDEdge* edge,
  double edge_point[3],
  const double* edgeP[2],
  bool bDamagedState
  )
{
  if (nullptr == edge || nullptr == edge_point)
    return false; // caller passed a null pointer - edge is not necessarily damaged

  ON_SubDIncrementErrorCount();
  edge->m_status.SetDamagedState(bDamagedState);

  if (nullptr != edgeP && nullptr != edgeP[0] && nullptr != edgeP[1])
  {
    const double edgePsum[3] = { edgeP[0][0] + edgeP[1][0], edgeP[0][1] + edgeP[1][1], edgeP[0][2] + edgeP[1][2] };
    edge_point[0] = 0.5*edgePsum[0];
    edge_point[1] = 0.5*edgePsum[1];
    edge_point[2] = 0.5*edgePsum[2];
  }
  return true;
}

unsigned int ON_SubDEdge::GetFacePointSum(
  const ON_SubDFace* face,
  const ON_SubDEdge* edge,
  double* facePsum
  )
{
  const ON_SubDEdge* e;
  ON__UINT_PTR e_ptr, edir;
  const double* vertexP[2];

  if (nullptr == face)
    return 0;
  
  const unsigned int n = face->m_edge_count;

  if (3 == n)
  {
    if (edge == ON_SUBD_EDGE_POINTER(face->m_edge4[0].m_ptr))
      e_ptr = face->m_edge4[1].m_ptr;
    else if (edge == ON_SUBD_EDGE_POINTER(face->m_edge4[1].m_ptr))
      e_ptr = face->m_edge4[2].m_ptr;
    else if (edge == ON_SUBD_EDGE_POINTER(face->m_edge4[2].m_ptr))
      e_ptr = face->m_edge4[0].m_ptr;
    else
      return 0;
      e = ON_SUBD_EDGE_POINTER(e_ptr);
      if (nullptr == e)
        return 0;
      if (nullptr == e->m_vertex[0] || nullptr == e->m_vertex[1])
        return 0;
      edir = ON_SUBD_EDGE_DIRECTION(e_ptr);
      if (edge->m_vertex[0] != e->m_vertex[edir] && edge->m_vertex[1] != e->m_vertex[edir])
        return 0;
      vertexP[0] = e->m_vertex[1 - edir]->m_P;
      facePsum[0] = vertexP[0][0];
      facePsum[1] = vertexP[0][1];
      facePsum[2] = vertexP[0][2];

      return n;
  }

  if (4 == n)
  {
    if (edge == ON_SUBD_EDGE_POINTER(face->m_edge4[0].m_ptr))
      e_ptr = face->m_edge4[2].m_ptr;
    else if (edge == ON_SUBD_EDGE_POINTER(face->m_edge4[1].m_ptr))
      e_ptr = face->m_edge4[3].m_ptr;
    else if (edge == ON_SUBD_EDGE_POINTER(face->m_edge4[2].m_ptr))
      e_ptr = face->m_edge4[0].m_ptr;
    else if (edge == ON_SUBD_EDGE_POINTER(face->m_edge4[3].m_ptr))
      e_ptr = face->m_edge4[1].m_ptr;
    else
      return 0;
    e = ON_SUBD_EDGE_POINTER(e_ptr);
    if (nullptr == e)
      return 0;
    if (nullptr == e->m_vertex[0] || nullptr == e->m_vertex[1])
      return 0;
    edir = ON_SUBD_EDGE_DIRECTION(e_ptr);
    vertexP[0] = e->m_vertex[edir]->m_P;
    vertexP[1] = e->m_vertex[1 - edir]->m_P;
    facePsum[0] = vertexP[0][0] + vertexP[1][0];
    facePsum[1] = vertexP[0][1] + vertexP[1][1];
    facePsum[2] = vertexP[0][2] + vertexP[1][2];

    return n;
  }

  if (n < 3)
    return 0;

  const ON_SubDEdgePtr* edgeptr = face->m_edge4;
  const ON_SubDVertex* edge_vertex[2] = { edge->m_vertex[0], edge->m_vertex[1] };
  facePsum[0] = 0.0;
  facePsum[1] = 0.0;
  facePsum[2] = 0.0;
  for (unsigned i = 0; i < n; i++)
  {
    if (4 == i)
      edgeptr = face->m_edgex - 4;
    e = ON_SUBD_EDGE_POINTER(edgeptr[i].m_ptr);
    if (nullptr == e)
      return 0;
    if (edge == e)
      continue;
    edir = ON_SUBD_EDGE_DIRECTION(edgeptr[i].m_ptr);
    const ON_SubDVertex* e_vertex[2] = { e->m_vertex[edir], e->m_vertex[1 - edir] };
    if (nullptr == e_vertex[0] || nullptr == e_vertex[1])
      return 0;
    if (edge_vertex[0] != e_vertex[0] && edge_vertex[1] != e_vertex[0])
    {
      vertexP[0] = e_vertex[0]->m_P;
      facePsum[0] += vertexP[0][0];
      facePsum[1] += vertexP[0][1];
      facePsum[2] += vertexP[0][2];
    }
    if (i + 1 < n)
    {
      // start of next edge = end of this edge
      if (edge_vertex[0] != e_vertex[1] && edge_vertex[1] != e_vertex[1])
      {
        vertexP[0] = e_vertex[1]->m_P;
        facePsum[0] += vertexP[0][0];
        facePsum[1] += vertexP[0][1];
        facePsum[2] += vertexP[0][2];
      }
      i++;
      if (4 == i && n > 4)
        edgeptr = face->m_edgex - 4;
    }
  }

  return n;
}

bool ON_SubDEdge::GetSubdivisionPoint(
    ON_SubD::SubDType subd_type,
    bool bUseSavedSubdivisionPoint,
    double subdivision_point[3]
  ) const
{
  if (nullptr == subdivision_point)
    return ON_SubDEdge_GetSubdivisionPointError(this, subdivision_point, nullptr, false);

  if (bUseSavedSubdivisionPoint && GetSavedSubdivisionPoint(subd_type, subdivision_point))
    return true;

  const ON_SubDVertex* edge_vertex[2] = { m_vertex[0], m_vertex[1] };
  if (nullptr == edge_vertex[0] || nullptr == edge_vertex[1])
    return ON_SubDEdge_GetSubdivisionPointError(this, subdivision_point, nullptr, true);

  double displacementV[3] = { 0 };
  const bool bApplyDisplacement = GetDisplacement(subd_type,displacementV);

  const double* edgeP[2] = { edge_vertex[0]->m_P, edge_vertex[1]->m_P };

  if ( IsSmooth() )
  {
    // A smooth edge must have exactly two neighboring faces and
    // at most one end vertex can be tagged.

    if (2 != m_face_count)
      return ON_SubDEdge_GetSubdivisionPointError(this, subdivision_point, edgeP, true);

    const ON_SubDFace* faces[2] = { ON_SUBD_FACE_POINTER(m_face2[0].m_ptr), ON_SUBD_FACE_POINTER(m_face2[1].m_ptr) };
    if (nullptr == faces[0] || nullptr == faces[1])
      return ON_SubDEdge_GetSubdivisionPointError(this, subdivision_point, edgeP, true);

    // for each neighbor face, sum the vertex locations that are not on this edge
    double facePsum[2][3];
    const unsigned int face_edge_count[2]
      = { ON_SubDEdge::GetFacePointSum(faces[0], this, facePsum[0]),
      ON_SubDEdge::GetFacePointSum(faces[1], this, facePsum[1])
    };
    if (0 == face_edge_count[0] || 0 == face_edge_count[1])
      return ON_SubDEdge_GetSubdivisionPointError(this, subdivision_point, edgeP, true);

    const unsigned int tagged_end
      = (ON_SubD::VertexTag::Smooth != edge_vertex[0]->m_vertex_tag)
      ? 0
      : ((ON_SubD::VertexTag::Smooth != edge_vertex[1]->m_vertex_tag) ? 1 : ON_UNSET_UINT_INDEX);
    double edgePsum[3];
    if (
      ON_UNSET_UINT_INDEX == tagged_end
      || 0.5 == m_sector_coefficient[tagged_end]
      || (ON_SubD::EdgeTag::X == m_edge_tag)
      )
    {
      // ignore edge weights
      edgePsum[0] = 0.375*(edgeP[0][0] + edgeP[1][0]);
      edgePsum[1] = 0.375*(edgeP[0][1] + edgeP[1][1]);
      edgePsum[2] = 0.375*(edgeP[0][2] + edgeP[1][2]);
    }
    else if (ON_SubD::VertexTag::Smooth == edge_vertex[1 - tagged_end]->m_vertex_tag
      && m_sector_coefficient[tagged_end] > 0.0
      && m_sector_coefficient[tagged_end] < 1.0
      )
    {
      double w[2];
      w[tagged_end] = m_sector_coefficient[tagged_end];
      w[1 - tagged_end] = 1.0 - w[tagged_end];
      edgePsum[0] = 0.75*(w[0] * edgeP[0][0] + w[1] * edgeP[1][0]);
      edgePsum[1] = 0.75*(w[0] * edgeP[0][1] + w[1] * edgeP[1][1]);
      edgePsum[2] = 0.75*(w[0] * edgeP[0][2] + w[1] * edgeP[1][2]);
    }
    else
    {
      // error:
      //   Both ends of a smooth vertex are tagged
      //   or weights are incorrectly set
      //   or ...
      return ON_SubDEdge_GetSubdivisionPointError(this, subdivision_point, edgeP, true);
    }

    if (4 == face_edge_count[0] && 4 == face_edge_count[1])
    {
      // common case when both neighboring faces are quads
      subdivision_point[0] = edgePsum[0] + 0.0625*(facePsum[0][0] + facePsum[1][0]);
      subdivision_point[1] = edgePsum[1] + 0.0625*(facePsum[0][1] + facePsum[1][1]);
      subdivision_point[2] = edgePsum[2] + 0.0625*(facePsum[0][2] + facePsum[1][2]);

      if (bApplyDisplacement)
      {
        subdivision_point[0] += displacementV[0];
        subdivision_point[1] += displacementV[1];
        subdivision_point[2] += displacementV[2];
      }

      if (bUseSavedSubdivisionPoint)
        SetSavedSubdivisionPoint(subd_type,subdivision_point);

      return true;
    }
    
    if (3 == face_edge_count[0] && 3 == face_edge_count[1])
    {
      // common case when both neighboring faces are triangles
      subdivision_point[0] = edgePsum[0] + 0.125*(facePsum[0][0] + facePsum[1][0]);
      subdivision_point[1] = edgePsum[1] + 0.125*(facePsum[0][1] + facePsum[1][1]);
      subdivision_point[2] = edgePsum[2] + 0.125*(facePsum[0][2] + facePsum[1][2]);

      if (bApplyDisplacement)
      {
        subdivision_point[0] += displacementV[0];
        subdivision_point[1] += displacementV[1];
        subdivision_point[2] += displacementV[2];
      }

      if (bUseSavedSubdivisionPoint)
        SetSavedSubdivisionPoint(subd_type,subdivision_point);

      return true;
    }

    // general formula works for all cases including face_edge_count[0] != face_count[2]
    const double f0 = 0.125 / ((double)(face_edge_count[0]-2));
    const double f1 = 0.125 / ((double)(face_edge_count[1]-2));
    subdivision_point[0] = edgePsum[0] + f0 * facePsum[0][0] + f1 * facePsum[1][0];
    subdivision_point[1] = edgePsum[1] + f0 * facePsum[0][1] + f1 * facePsum[1][1];
    subdivision_point[2] = edgePsum[2] + f0 * facePsum[0][2] + f1 * facePsum[1][2];

    if (bApplyDisplacement)
    {
      subdivision_point[0] += displacementV[0];
      subdivision_point[1] += displacementV[1];
      subdivision_point[2] += displacementV[2];
    }

    if (bUseSavedSubdivisionPoint)
      SetSavedSubdivisionPoint(subd_type,subdivision_point);

    return true;
  }

  if ( IsCrease() )
  {
    subdivision_point[0] = 0.5*(edgeP[0][0] + edgeP[1][0]);
    subdivision_point[1] = 0.5*(edgeP[0][1] + edgeP[1][1]);
    subdivision_point[2] = 0.5*(edgeP[0][2] + edgeP[1][2]);

    if (bApplyDisplacement)
    {
      subdivision_point[0] += displacementV[0];
      subdivision_point[1] += displacementV[1];
      subdivision_point[2] += displacementV[2];
    }

    if (bUseSavedSubdivisionPoint)
      SetSavedSubdivisionPoint(subd_type,subdivision_point);

    return true;
  }

  // invalid edge->m_edge_tag
  return ON_SubDEdge_GetSubdivisionPointError(this, subdivision_point, edgeP, true);
}











static unsigned int GetSectorBoundaryEdgesError()
{
  return ON_SUBD_RETURN_ERROR(0);
}

unsigned int ON_SubDEdge::GetSectorBoundaryEdges(
  unsigned int edge_vertex_index,
  ON_SubDEdgePtr* edge_ptr0,
  ON_SubDEdgePtr* edge_ptr1
  ) const
{
  if (nullptr != edge_ptr0)
    *edge_ptr0 = ON_SubDEdgePtr::Null;
  if (nullptr != edge_ptr1)
    *edge_ptr1 = ON_SubDEdgePtr::Null;

  const unsigned int edge_face_count = m_face_count;
  if (edge_face_count <= 0 || edge_face_count > 2)
    return GetSectorBoundaryEdgesError();

  if (2 == edge_face_count && ON_SubD::EdgeTag::Crease == m_edge_tag)
    return GetSectorBoundaryEdgesError();

  if (0 != edge_vertex_index && 1 != edge_vertex_index)
    return GetSectorBoundaryEdgesError();

  const ON_SubDVertex* vertex = m_vertex[edge_vertex_index];
  if (nullptr == vertex || vertex->m_face_count <= 0)
    return GetSectorBoundaryEdgesError();

  const unsigned int vertex_face_count = vertex->m_face_count;
  unsigned int sector_face_count = 0;
  ON_SubDEdgePtr sector_boundary[2] = {};
  for (unsigned int edge_face_index = 0; edge_face_index < edge_face_count; edge_face_index++)
  {
    const ON_SubDEdge* edge0 = this;
    unsigned int edge0_end_index = edge_vertex_index;
    unsigned int edge0_face_index = edge_face_index;
    ON_SubDFacePtr face_ptr = edge0->m_face2[edge0_face_index];
    while (sector_face_count < vertex_face_count)
    {
      const ON_SubDFace* face = ON_SUBD_FACE_POINTER(face_ptr.m_ptr);
      if (0 == face)
        return GetSectorBoundaryEdgesError();
      ON__UINT_PTR face_dir = ON_SUBD_FACE_DIRECTION(face_ptr.m_ptr);

      sector_face_count++;

      unsigned int face_edge0_index = face->EdgeArrayIndex(edge0);
      if (ON_UNSET_UINT_INDEX == face_edge0_index)
        return 0;

      unsigned int face_edge1_index
        = face_edge0_index;
      face_edge1_index +=
        (1 == (edge0_end_index + face_dir))
        ? 1
        : (face->m_edge_count - 1);
      face_edge1_index %= face->m_edge_count;

      ON_SubDEdgePtr edge1_ptr = face->EdgePtr(face_edge1_index);
      const ON_SubDEdge* edge1 = ON_SUBD_EDGE_POINTER(edge1_ptr.m_ptr);
      if (nullptr == edge1)
        return GetSectorBoundaryEdgesError();

      unsigned int edge1_end_index = (0 == face_dir) ? (1 - edge0_end_index) : edge0_end_index;
      if (1 == ON_SUBD_EDGE_DIRECTION(edge1_ptr.m_ptr))
        edge1_end_index = 1 - edge1_end_index;
      if (vertex != edge1->m_vertex[edge1_end_index])
        return GetSectorBoundaryEdgesError();

      if ( edge1->IsSmooth() && 2 == edge1->m_face_count )
      {
        const ON_SubDFace* edge1_faces[2] = { ON_SUBD_FACE_POINTER(edge1->m_face2[0].m_ptr), ON_SUBD_FACE_POINTER(edge1->m_face2[1].m_ptr) };
        unsigned int edge1_face_index = (face == edge1_faces[0] ? 1 : 0);
        if (nullptr == edge1_faces[edge1_face_index] || face == edge1_faces[edge1_face_index])
          return GetSectorBoundaryEdgesError();
        face_ptr = edge1->m_face2[edge1_face_index];
        edge0 = edge1;
        edge0_face_index = edge1_face_index;
        edge0_end_index = edge1_end_index;
        continue;
      }

      sector_boundary[edge_face_index] = ON_SubDEdgePtr::Create(edge1, edge1_end_index);
      break;
    }
  }
  
  if (sector_face_count <= 0 || sector_boundary[0].IsNull())
    return GetSectorBoundaryEdgesError();
  if (1 == edge_face_count)
    sector_boundary[1] = ON_SubDEdgePtr::Create(this, edge_vertex_index);
  else if (sector_boundary[1].IsNull())
    return GetSectorBoundaryEdgesError();

  if (nullptr != edge_ptr0)
    *edge_ptr0 = sector_boundary[0];
  if (nullptr != edge_ptr1)
    *edge_ptr1 = sector_boundary[1];

  return sector_face_count;
}

class ON_ScratchBuffer
{
public:
  ON_ScratchBuffer(
    size_t sizeof_buffer,
    void* stack_buffer,
    size_t sizeof_stack_buffer
    )
    : m_buffer(nullptr)
    , m_heap_buffer(nullptr)
  {
    m_buffer
      = (sizeof_buffer > sizeof_stack_buffer || nullptr == stack_buffer)
      ? stack_buffer
      : (m_heap_buffer = new (std::nothrow) double[1 + sizeof_buffer / sizeof(double)]);
  }

  void* Buffer()
  {
    return m_buffer;
  }

  ~ON_ScratchBuffer()
  {
    if (nullptr != m_heap_buffer)
    {
      double* p = m_heap_buffer;
      m_heap_buffer = nullptr;
      delete[] p;
    }
  }

private:
  void* m_buffer;
  double* m_heap_buffer;

private:
  // prohibit use - no implementation
  ON_ScratchBuffer(const ON_ScratchBuffer&);
  ON_ScratchBuffer& operator-(const ON_ScratchBuffer&);
};

////static bool IsSmoothManifoldEdge(const ON_SubDEdge* edge)
////{
////  return (nullptr != edge && (ON_SubD::EdgeTag::Smooth == edge->m_edge_tag || ON_SubD::EdgeTag::X == edge->m_edge_tag) && 2 == edge->m_face_count);
////}

////unsigned int ON_SubDimple::GetSector(
////  const ON_SubDFace* starting_face,
////  ON__UINT_PTR face_vertex_index,
////  ON_SubDVertex& sector
////  ) const
////{
////  sector.m_edge_count = 0;
////  sector.m_face_count = 0;
////
////  if (nullptr == starting_face || face_vertex_index >= starting_face->m_edge_count)
////    return GetSectorError(sector);
////
////  unsigned short face_edge_index = (unsigned short)face_vertex_index;
////  ON__UINT_PTR edge0_ptr = starting_face->EdgePtr(face_edge_index > 0 ? (face_edge_index - 1) : (starting_face->m_edge_count - 1)).m_ptr;
////  ON__UINT_PTR edge1_ptr = starting_face->EdgePtr(face_edge_index).m_ptr;
////  const ON_SubDEdge* edge0 = ON_SUBD_EDGE_POINTER(edge0_ptr);
////  const ON_SubDEdge* edge1 = ON_SUBD_EDGE_POINTER(edge1_ptr);
////  if (nullptr == edge0 || nullptr == edge1)
////    return GetSectorError(sector);
////  ON__UINT_PTR edge0_end = 1 - ON_SUBD_EDGE_DIRECTION(edge0_ptr);
////  ON__UINT_PTR edge1_end = ON_SUBD_EDGE_DIRECTION(edge1_ptr);
////
////  const ON_SubDVertex* vertex = edge0->m_vertex[edge0_end];
////  if ( nullptr == vertex || vertex->m_face_count < 1 || vertex->m_edge_count < 2)
////    return GetSectorError(sector);
////  if (vertex != edge1->m_vertex[edge1_end])
////    return GetSectorError(sector);
////
////  const unsigned int sector_capacity = vertex->m_face_count;
////  const size_t buffer_capacity = (size_t)(3*sector_capacity + 2);
////  ON__UINT_PTR stack_buffer[3 * 16 + 2];
////  ON_ScratchBuffer buffer(buffer_capacity*sizeof(stack_buffer[0]), stack_buffer, sizeof(stack_buffer));
////  if (nullptr == buffer.Buffer())
////    return GetSectorError(sector);
////
////  const ON_SubDFace** sector_faces = (const ON_SubDFace**)buffer.Buffer();
////  const ON_SubDEdge** sector_edges = (const ON_SubDEdge**)(sector_faces + sector_capacity);
////  ON__UINT_PTR* sector_edge_ends = (ON__UINT_PTR*)(sector_edges + (sector_capacity + 1));
////
////  const ON_SubDFace* face0 = starting_face;
////  sector_faces[0] = face0;
////  sector_edges[0] = edge0;
////  sector_edge_ends[0] = edge0_end;
////  sector_edges[1] = edge1;
////  sector_edge_ends[1] = edge1_end;
////  unsigned int sector_index = 1;
////  unsigned int right_side_sector_count = 1;
////
////  if (false == IsSmoothManifoldEdge(edge0) && false == IsSmoothManifoldEdge(edge1))
////  {
////    // both edges act as creases
////    sector_edges[sector_capacity] = edge1;
////    sector_edge_ends[sector_capacity] = edge1_end;
////  }
////  else
////  {
////    // at least one input edge is a smooth manifold edge (2 faces)
////    for (unsigned int sector_side = 0; sector_side < 2; sector_side++)
////    {
////      const ON_SubDFace* face1 = nullptr;
////      while (sector_index < sector_capacity)
////      {
////        if (false == IsSmoothManifoldEdge(edge1))
////          break;
////
////        face1 = edge1->NeighborFace(face0,true);
////        if (sector_faces[0] == face1)
////        {
////          // circled around vertex back where we started.
////          // Since the edge trap at the end of the for loop
////          // did not break, this is an error condition.
////          return GetSectorError(sector);
////        }
////
////        if (nullptr == face1 || face0 == face1)
////          return GetSectorError(sector);
////
////        unsigned int face1_edge_count = face1->m_edge_count;
////        if (face1_edge_count < 2)
////          return GetSectorError(sector);
////
////        unsigned int face1_edge0_index = face1->EdgeArrayIndex(edge1);
////        if (ON_UNSET_UINT_INDEX == face1_edge0_index)
////          return GetSectorError(sector);
////        edge0_ptr = face1->EdgePtr(face1_edge0_index).m_ptr;
////        edge0 = ON_SUBD_EDGE_POINTER(edge0_ptr);
////        if (edge0 != edge1)
////          return GetSectorError(sector);
////        ON__UINT_PTR edge0_dir = ON_SUBD_EDGE_DIRECTION(edge0_ptr); // edge0 - face1 natural orientation relationship
////        edge0_end = edge1_end;
////
////        // If 1 == (edge0_end + edge0_dir), then face0 and face1 have same natural 
////        // orientations across shared edge and new edge1 = next edge on face1.
////        // If 1 != edge0_to_edge1_index_delta, then face0 and face1 opposite same natural 
////        // orientations across shared edge and new edge1 = prev edge on face1.
////        unsigned int face1_edge1_index
////          = (1 == (edge0_end + edge0_dir))
////          ? (face1_edge0_index + 1)
////          : (face1_edge0_index + (face1_edge_count - 1));
////        face1_edge1_index %= face1_edge_count;
////
////        edge1_ptr = face1->EdgePtr(face1_edge1_index).m_ptr;
////        edge1 = ON_SUBD_EDGE_POINTER(edge1_ptr);
////        if (nullptr == edge1)
////          return GetSectorError(sector);
////        ON__UINT_PTR edge1_dir = ON_SUBD_EDGE_DIRECTION(edge1_ptr); // edge1 - face1 natural orientation relationship
////        edge1_end = (1 == ((edge0_end + edge0_dir + edge1_dir) % 2)) ? 0 : 1;
////        if (vertex != edge1->m_vertex[edge1_end])
////          return GetSectorError(sector);
////        if (vertex == edge1->m_vertex[1 - edge1_end])
////          return GetSectorError(sector);
////
////        face0 = face1;
////        sector_faces[sector_index] = face0;
////        if (0 == sector_side)
////        {
////          sector_edges[sector_index] = edge0;
////          sector_edge_ends[sector_index] = edge0_end;
////          sector_index++;
////          if (edge1 == sector_edges[0])
////          {
////            // circled around back to where we started
////            break;
////          }
////        }
////        else
////        {
////          sector_edges[sector_index] = edge1;
////          sector_edge_ends[sector_index] = edge1_end;
////          sector_index++;
////        }
////      }
////
////      if (0 == sector_side)
////      {
////        // finished first side
////
////        // Mark where the first side information ends.
////        right_side_sector_count = sector_index;
////
////        // Save the final boundary information in a place where 
////        // the 2nd pass will not write over it.
////        sector_edges[sector_capacity] = edge1;
////        sector_edge_ends[sector_capacity] = edge1_end;
////
////        if (sector_edges[0] == sector_edges[sector_capacity])
////        {
////          // If sector_edge_ends[0] is a smooth 2-faced edge, then
////          // we circled around the vertex through smooth 2-faced edges
////          // until we got back to the starting vertex.
////          //
////          // If sector_edge_ends[0] is a crease, then the vertex is a dart.
////          //
////          // If sector_edge_ends[0] has more than 2 faces, then we've gone
////          // around a manifold sector that "begins/ends" at sector_edge_ends[0]
////          break;
////        }
////
////        // prepare for second side
////        face0 = sector_faces[0];
////        edge1 = sector_edges[0];
////        edge1_end = sector_edge_ends[0];
////      }
////      else
////      {
////        // finished second side
////        if (sector_faces[0] == face1)
////          return GetSectorError(sector);
////
////        break;
////      }
////    }
////  }
////
////  if (0 == sector_index)
////    return GetSectorError(sector);
////
////  if (nullptr == sector_edges[0] || nullptr == sector_edges[sector_index - 1] || nullptr == sector_edges[sector_capacity])
////    return GetSectorError(sector);
////
////  if (IsSmoothManifoldEdge(sector_edges[sector_capacity]))
////  {
////    if (right_side_sector_count < 2)
////      return GetSectorError(sector);
////    if (sector_index > right_side_sector_count)
////      return GetSectorError(sector);
////    if (sector_edges[0] != sector_edges[sector_capacity])
////      return GetSectorError(sector);
////  }
////  else if (sector_index > right_side_sector_count)
////  {
////    if (IsSmoothManifoldEdge(sector_edges[sector_index-1]))
////      return GetSectorError(sector);
////  }
////
////  if (!InitializeSector(vertex, sector))
////    return GetSectorError(sector);
////
////  if (false == const_cast<ON_SubDimple*>(this)->m_heap.GrowVertexEdgeArray(&sector, sector_index + 1))
////    return GetSectorError(sector);
////  if (false == const_cast<ON_SubDimple*>(this)->m_heap.GrowVertexFaceArray(&sector, sector_index))
////    return GetSectorError(sector);
////  unsigned int sector_face_count = 0;
////  while (sector_index > right_side_sector_count)
////  {
////    sector_index--;
////    sector.m_edges[sector_face_count] = ON_SubDEdgePtr::Create(sector_edges[sector_index], sector_edge_ends[sector_index]);
////    sector.m_faces[sector_face_count] = sector_faces[sector_index];
////    sector_face_count++;
////  }
////  for (sector_index = 0; sector_index < right_side_sector_count; sector_index++)
////  {
////    sector.m_edges[sector_face_count] = ON_SubDEdgePtr::Create(sector_edges[sector_index], sector_edge_ends[sector_index]);
////    sector.m_faces[sector_face_count] = sector_faces[sector_index];
////    sector_face_count++;
////  }
////
////  sector.m_edges[sector_face_count] = ON_SubDEdgePtr::Create(sector_edges[sector_capacity], sector_edge_ends[sector_capacity]);
////  sector.m_face_count = (unsigned short)sector_face_count;
////  sector.m_edge_count = sector.m_face_count+1;
////
////  return sector_face_count;
////}

////unsigned int ON_SubDimple::GetSector(
////  const ON_SubDVertex* vertex,
////  const ON_SubDFace* face,
////  ON_SubDVertex& sector
////  ) const
////{
////  unsigned int face_vertex_index = (nullptr != face) ? face->VertexIndex(vertex) : ON_UNSET_UINT_INDEX;
////  if (ON_UNSET_UINT_INDEX == face_vertex_index)
////    return GetSectorError(sector);
////  return GetSector(face, face_vertex_index, sector);
////}
////
////unsigned int ON_SubDimple::GetSector(
////  const ON_SubDVertex* vertex,
////  ON_SubDFacePtr face_ptr,
////  ON_SubDVertex& sector
////  ) const
////{
////  if (nullptr == vertex)
////    return GetSectorError(sector);
////  return GetSector(vertex, ON_SUBD_FACE_POINTER(face_ptr.m_ptr), sector);
////}
////
////unsigned int ON_SubDimple::GetSector(
////  const ON_SubDEdge* smooth_edge,
////  ON__UINT_PTR smooth_edge_end_index,
////  ON_SubDVertex& sector
////  ) const
////{
////  if (nullptr == smooth_edge || smooth_edge_end_index > 1)
////    return GetSectorError(sector);
////  const ON_SubDVertex* vertex = smooth_edge->m_vertex[smooth_edge_end_index];
////  if (nullptr == vertex)
////    return GetSectorError(sector);
////
////  switch (smooth_edge->m_face_count)
////  {
////  case 0:
////    if (!InitializeSector(vertex, sector))
////      break;
////    sector.m_edges = (ON_SubDEdgePtr*)const_cast<ON_SubDimple*>(this)->m_heap.GrowArrayByOneElement(sector.m_edge_count, (ON__UINT_PTR*)sector.m_edges);
////    sector.m_edges[sector.m_edge_count++] = ON_SubDEdgePtr::Create(smooth_edge, smooth_edge_end_index);
////    return true;
////    break;
////
////  case 1:
////    return GetSector(vertex, ON_SUBD_FACE_POINTER(smooth_edge->m_face2[0].m_ptr), sector);
////    break;
////
////  case 2:
////    if (ON_SubD::EdgeTag::Smooth == smooth_edge->m_edge_tag)
////      return GetSector(vertex, ON_SUBD_FACE_POINTER(smooth_edge->m_face2[0].m_ptr), sector);
////    break;
////  }
////
////  return GetSectorError(sector);
////}
////
////unsigned int ON_SubDimple::GetSector(
////  const ON_SubDVertex* vertex,
////  const ON_SubDEdge* smooth_edge,
////  ON_SubDVertex& sector
////  ) const
////{
////  if (nullptr == vertex || nullptr == smooth_edge)
////    return GetSectorError(sector);
////  unsigned int smooth_edge_end_index
////    = (vertex == smooth_edge->m_vertex[0])
////    ? 0
////    : ((vertex == smooth_edge->m_vertex[1]) ? 1 : ON_UNSET_UINT_INDEX);
////  if (ON_UNSET_UINT_INDEX == smooth_edge_end_index)
////    return GetSectorError(sector);
////  return GetSector(smooth_edge, smooth_edge_end_index, sector);
////}
////
////
////unsigned int ON_SubDimple::GetSector(
////  ON_SubDEdgePtr smooth_edge_ptr,
////  ON_SubDVertex& sector
////  ) const
////{
////  return GetSector(ON_SUBD_EDGE_POINTER(smooth_edge_ptr.m_ptr), ON_SUBD_EDGE_DIRECTION(smooth_edge_ptr.m_ptr), sector);
////}
////
////unsigned int ON_SubD::GetSector(
////  const ON_SubDFace* face,
////  ON__UINT_PTR face_vertex_index,
////  ON_SubDVertex& sector
////  ) const
////{
////  const ON_SubDimple* subdimple = SubDimple();
////  return (nullptr != subdimple) ? subdimple->GetSector(face, face_vertex_index, sector) : GetSectorError(sector);
////}
////
////unsigned int ON_SubD::GetSector(
////  const ON_SubDVertex* vertex,
////  const ON_SubDFace* face,
////  ON_SubDVertex& sector
////  ) const
////{
////  const ON_SubDimple* subdimple = SubDimple();
////  return (nullptr != subdimple) ? subdimple->GetSector(vertex, face, sector) : GetSectorError(sector);
////}
////
////unsigned int ON_SubD::GetSector(
////  const ON_SubDVertex* vertex,
////  ON_SubDFacePtr face_ptr,
////  ON_SubDVertex& sector
////  ) const
////{
////  const ON_SubDimple* subdimple = SubDimple();
////  return (nullptr != subdimple) ? subdimple->GetSector(vertex, face_ptr, sector) : GetSectorError(sector);
////}
////
////unsigned int ON_SubD::GetSector(
////  const ON_SubDVertex* vertex,
////  const ON_SubDEdge* smooth_edge,
////  ON_SubDVertex& sector
////  ) const
////{
////  const ON_SubDimple* subdimple = SubDimple();
////  return (nullptr != subdimple) ? subdimple->GetSector(vertex, smooth_edge, sector) : GetSectorError(sector);
////}
////
////unsigned int ON_SubD::GetSector(
////  const ON_SubDEdge* smooth_edge,
////  ON__UINT_PTR smooth_edge_end_index,
////  ON_SubDVertex& sector
////  ) const
////{
////  const ON_SubDimple* subdimple = SubDimple();
////  return (nullptr != subdimple) ? subdimple->GetSector(smooth_edge, smooth_edge_end_index, sector) : GetSectorError(sector);
////}
////
////unsigned int ON_SubD::GetSector(
////  ON_SubDEdgePtr smooth_edge_ptr,
////  ON_SubDVertex& sector
////  ) const
////{
////  const ON_SubDimple* subdimple = SubDimple();
////  return (nullptr != subdimple) ? subdimple->GetSector(smooth_edge_ptr, sector) : GetSectorError(sector);
////}



class FACE_AND_FACE_POINT
{
public:
  const ON_SubDFace* m_face;
  double m_faceP[3];
  static int CompareFacePointer(const void* a, const void* b);
};

int FACE_AND_FACE_POINT::CompareFacePointer(const void* a, const void* b)
{
  ON__UINT_PTR fa = (ON__UINT_PTR)(((const FACE_AND_FACE_POINT*)a)->m_face);
  ON__UINT_PTR fb = (ON__UINT_PTR)(((const FACE_AND_FACE_POINT*)b)->m_face);
  if (fa < fb)
    return -1;
  if (fa > fb)
    return 1;
  return 0;
}

bool ON_SubDSectorLimitPoint::IsUnset() const
{
  return (m_limitP[0] == ON_UNSET_VALUE);
}

bool ON_SubDSectorLimitPoint::IsNan() const
{
  return !(m_limitP[0] == m_limitP[0]);
}

bool ON_SubDSectorLimitPoint::IsZero() const
{
  const double* p = m_limitP;
  const double* p1 = p+12;
  while (p < p1)
  {
    if (!(0.0 == *p++))
      return false;
  }
  return true;
}

bool ON_SubDSectorLimitPoint::IsSet() const
{
  double x, y;
  const double* p = m_limitP;
  const double* p1 = p+3;
  while (p < p1)
  {
    x = *p++;
    if (ON_UNSET_VALUE == x || !(x == x))
      return false;
  }

  p = m_limitT1;
  p1 = p+6;
  while (p < p1)
  {
    const double* p2 = p+3;
    y = 0.0;
    while (p < p2)
    {
      x = *p++;
      if (ON_UNSET_VALUE == x || !(x == x))
        return false;
      if ( 0.0 != x )
       y = x;
    }
    if (!(y != 0.0))
      return false;
  }

  p = m_limitN;
  p1 = p+3;
  y = 0.0;
  while (p < p1)
  {
    x = *p++;
    if (ON_UNSET_VALUE == x || !(x == x))
      return false;
    y += x*x;
  }
  if (!(fabs(y - 1.0) <= 1e-4))
    return false;

  return true;
}

void ON_SubDVertex::CopyFrom(
  const ON_SubDVertex* src,
  bool bCopyEdgeArray,
  bool bCopyFaceArray,
  bool bCopyLimitPointList
  )
{
  if (nullptr == src)
    src = &ON_SubDVertex::Empty;

  ClearSavedLimitPoints();
  CopyBaseFrom(src);

  m_vertex_tag = src->m_vertex_tag;
  //m_vertex_edge_order = src->m_vertex_edge_order;
  //m_vertex_facet_type = src->m_vertex_facet_type;

  m_P[0] = src->m_P[0];
  m_P[1] = src->m_P[1];
  m_P[2] = src->m_P[2];


  if (bCopyLimitPointList)
  {
    ON_SubD::SubDType limit_point_subd_type = src->SavedLimitPointType();
    if (ON_SubD::SubDType::Unset != limit_point_subd_type)
    {
      for (const ON_SubDSectorLimitPoint* p = &src->m_limit_point; nullptr != p; p = p->m_next_sector_limit_point)
      {
        ON_SubDSectorLimitPoint limit_point = *p;
        limit_point.m_next_sector_limit_point = (ON_SubDSectorLimitPoint*)1; // disable checks
        SetSavedLimitPoint(limit_point_subd_type, limit_point);
      }
    }
  }

  if (bCopyEdgeArray)
  {
    if (src->m_edge_count > 0 && nullptr != src->m_edges && nullptr != m_edges && src->m_edge_count <= m_edge_capacity)
    {
      m_edge_count = src->m_edge_count;
      const unsigned int edge_count = src->m_edge_count;
      for (unsigned int vei = 0; vei < edge_count; vei++)
        m_edges[vei] = src->m_edges[vei];
    }
    else
      m_edge_count = 0;
  }

  if (bCopyFaceArray)
  {
    if (src->m_face_count > 0 && nullptr != src->m_faces && nullptr != m_faces && src->m_face_count <= m_face_capacity)
    {
      m_face_count = src->m_face_count;
      const unsigned int face_count = src->m_face_count;
      for (unsigned int vfi = 0; vfi < face_count; vfi++)
        m_faces[vfi] = src->m_faces[vfi];
    }
    else
      m_face_count = 0;
  }
}


static bool ON_SubDVertex_GetSubdivisionPointError(
  const class ON_SubDVertex* vertex,
  double vertex_point[3],
  const double* vertexP,
  bool bDamagedState
  )
{
  if (nullptr == vertex || nullptr == vertex_point)
    return false; // caller passed a null pointer - vertex is not necessarily damaged

  ON_SubDIncrementErrorCount();
  vertex->m_status.SetDamagedState(bDamagedState);

  vertex->ClearSavedSubdivisionPoint();

  if (nullptr != vertexP)
  {
    vertex_point[0] = vertexP[0];
    vertex_point[1] = vertexP[1];
    vertex_point[2] = vertexP[2];
  }

  return true;
}

bool ON_SubDVertex::GetGeneralQuadSubdivisionPoint(
  const class ON_SubDVertex* vertex,
  bool bUseSavedSubdivisionPoint,
  double vertex_point[3]
  )
{
  const ON_SubD::SubDType subdivision_type = ON_SubD::SubDType::QuadCatmullClark;

  const double* vertexP = vertex->m_P;

  const unsigned int n = vertex->m_face_count;

  // It is critical to use the centroids of the neighboring faces
  // in this step because the number of edges in each face's
  // boundary may not be constant.
  double facePsum[3] = { 0 };
  const ON_SubDFace*const* vertex_faces = vertex->m_faces;
  for (unsigned int i = 0; i < n; i++)
  {
    const ON_SubDFace* face = vertex_faces[i];
    if (nullptr != face)
    {
      double faceC[3];
      if (face->GetSubdivisionPoint(subdivision_type, bUseSavedSubdivisionPoint, faceC))
      {
        facePsum[0] += faceC[0];
        facePsum[1] += faceC[1];
        facePsum[2] += faceC[2];
        continue;
      }
    }
    // treat missing or damaged face as infinitesimally small
    facePsum[0] += vertexP[0];
    facePsum[1] += vertexP[1];
    facePsum[2] += vertexP[2];
  }

  double edgePsum[3] = { 0 };
  class ON_SubDEdgePtr* edges = vertex->m_edges;
  for (unsigned int i = 0; i < n; i++)
  {
    const ON_SubDEdge* edge = ON_SUBD_EDGE_POINTER(edges[i].m_ptr);
    if (nullptr != edge)
    {
      const ON_SubDVertex* edge_vertex = edge->OtherEndVertex(vertex);
      if (nullptr != edge_vertex)
      {
        const double* edgeP = edge_vertex->m_P;
        edgePsum[0] += edgeP[0];
        edgePsum[1] += edgeP[1];
        edgePsum[2] += edgeP[2];
        continue;
      }
    }
    // treat missing or damaged edge as infinitesimally small
    edgePsum[0] += vertexP[0];
    edgePsum[1] += vertexP[1];
    edgePsum[2] += vertexP[2];
  }

  const double v_weight = 1.0 - 2.0 / ((double)n);
  const double ef_weight = 1.0 / ((double)(n*n));
  vertex_point[0] = v_weight*vertexP[0] + ef_weight*(edgePsum[0] + facePsum[0]);
  vertex_point[1] = v_weight*vertexP[1] + ef_weight*(edgePsum[1] + facePsum[1]);
  vertex_point[2] = v_weight*vertexP[2] + ef_weight*(edgePsum[2] + facePsum[2]);

  if (bUseSavedSubdivisionPoint)
    vertex->SetSavedSubdivisionPoint(ON_SubD::SubDType::QuadCatmullClark,vertex_point);

  return true;
}

bool ON_SubDVertex::GetQuadPoint(
  const class ON_SubDVertex* vertex,
  bool bUseSavedSubdivisionPoint,
  double vertex_point[3]
  )
{
  // This function is used to convert an arbitrary control polygon into the
  // "level 1" quad subD.  It cannot use the faster sub-D formulas because
  // a face can have an arbitrary number of edges.
  if (nullptr == vertex || nullptr == vertex_point)
    return ON_SubDVertex_GetSubdivisionPointError(vertex,vertex_point,nullptr,false);

  const double* vertexP = vertex->m_P;

  const unsigned int n = (nullptr != vertex->m_edges ? vertex->m_edge_count : 0);
  if (ON_SubD::VertexTag::Smooth == vertex->m_vertex_tag || ON_SubD::VertexTag::Dart == vertex->m_vertex_tag)
  {
    if (n < 3 || n != vertex->m_face_count || nullptr == vertex->m_faces)
      return ON_SubDVertex_GetSubdivisionPointError(vertex, vertex_point, vertexP, true);
    
    double facePsum[3] = { 0 };
    const ON_SubDFace*const* vertex_faces = vertex->m_faces;

    const ON_SubDFace* face = vertex_faces[0];
    if (nullptr == face)
      return ON_SubDVertex_GetSubdivisionPointError(vertex, vertex_point, vertexP, true);

    ////// for debugging code below, uncomment this line
    ////// and look for differences in results.
    ////return GetGeneralQuadSubdivisionPoint(vertex, vertex_point);

    const unsigned int k = (nullptr == face) ? 0U : face->m_edge_count;
    if (4 == k)
    {
      // possibly (probably?) every face is a quad
      double sum[3];
      for (unsigned int i = 0; i < n; i++)
      {
        const ON_SubDFace* vface = vertex_faces[i];
        const unsigned int face_n = ON_SubDVertex::GetFacePointSum(vface, vertex, sum);
        if (4 != face_n)
        {
          // The first face is a quadrangle and this face is not a quadrangle.
          //
          // It is critical to use the centroids of the neighboring faces
          // for this vertex subdivision point because the number of edges
          // in each face's boundary is not constant.
          return ON_SubDVertex::GetGeneralQuadSubdivisionPoint(vertex, bUseSavedSubdivisionPoint, vertex_point);
        }
        facePsum[0] += sum[0];
        facePsum[1] += sum[1];
        facePsum[2] += sum[2];
      }
    }
    else if (3 == k)
    {
      // possibly (probably?) every face is a triangle
      for (unsigned int i = 0; i < n; i++)
      {
        const ON_SubDFace* vface = vertex_faces[i];
        if (k != ((nullptr == vface) ? 0U : vface->m_edge_count))
        {
          // The first face is a triangle and this face is not a triangle.
          //
          // It is critical to use the centroids of the neighboring faces
          // for this vertex subdivision point because the number of edges
          // in each face's boundary is not constant.
          return ON_SubDVertex::GetGeneralQuadSubdivisionPoint(vertex, bUseSavedSubdivisionPoint, vertex_point);
        }
      }
    }
    else
    {
      // The first face has 5 or more edges.  
      // It is likely this is the initial subdivision being applied
      // to the level zero SubD control polygon.
      //
      // It may be critical to use the centroids of the neighboring faces
      // for this vertex subdivision point because the number of edges
      // in each face's boundary may not constant.  In any case, this
      // situation is not common and typically happens only on the
      // first subdivision step.
      return ON_SubDVertex::GetGeneralQuadSubdivisionPoint(vertex, bUseSavedSubdivisionPoint, vertex_point);
    }

    double edgePsum[3] = { 0 };
    class ON_SubDEdgePtr* edges = vertex->m_edges;
    for (unsigned int i = 0; i < n; i++)
    {
      const ON_SubDEdge* edge = ON_SUBD_EDGE_POINTER(edges[i].m_ptr);
      if (nullptr != edge)
      {
        const ON_SubDVertex* edge_vertex = edge->OtherEndVertex(vertex);
        if (nullptr != edge_vertex)
        {
          const double* edgeP = edge_vertex->m_P;
          edgePsum[0] += edgeP[0];
          edgePsum[1] += edgeP[1];
          edgePsum[2] += edgeP[2];
          continue;
        }
      }
      // treat missing or damaged edge as infinitesimally small
      edgePsum[0] += vertexP[0];
      edgePsum[1] += vertexP[1];
      edgePsum[2] += vertexP[2];
    }

    if (4 == k)
    {
      // all faces were quads
      const double v_weight = 1.0 - 1.75 / ((double)n);
      const double e_weight = 1.5 / ((double)(n*n));
      const double f_weight = 0.25 / ((double)(n*n));
      vertex_point[0] = v_weight*vertexP[0] + e_weight*edgePsum[0] + f_weight*facePsum[0];
      vertex_point[1] = v_weight*vertexP[1] + e_weight*edgePsum[1] + f_weight*facePsum[1];
      vertex_point[2] = v_weight*vertexP[2] + e_weight*edgePsum[2] + f_weight*facePsum[2];
    }
    else
    {
      // all faces were triangles
      const double v_weight = 1.0 - 5.0 / ((double)(3 * n));
      const double e_weight = 5.0 / ((double)(3*n*n));
      vertex_point[0] = v_weight*vertexP[0] + e_weight*edgePsum[0];
      vertex_point[1] = v_weight*vertexP[1] + e_weight*edgePsum[1];
      vertex_point[2] = v_weight*vertexP[2] + e_weight*edgePsum[2];
    }

    if (bUseSavedSubdivisionPoint)
      vertex->SetSavedSubdivisionPoint(ON_SubD::SubDType::QuadCatmullClark,vertex_point);

    return true;
  }

  // vertex->m_vertex_tag is damaged
  return ON_SubDVertex_GetSubdivisionPointError(vertex, vertex_point, vertexP, true);
}


bool ON_SubDVertex::GetSubdivisionPoint(
  ON_SubD::SubDType subd_type,
    bool bUseSavedSubdivisionPoint,
    double subdivision_point[3]
  ) const
{
  // This function is used to convert an arbitrary control polygon into the
  // "level 1" subD.  It cannot use the faster sub-D formulas because
  // a face can have an arbitrary number of edges.
  if (nullptr == subdivision_point 
    || (ON_SubD::SubDType::TriLoopWarren != subd_type && ON_SubD::SubDType::QuadCatmullClark != subd_type))
    return ON_SubDVertex_GetSubdivisionPointError(this, subdivision_point, nullptr, false);

  if ( bUseSavedSubdivisionPoint && GetSavedSubdivisionPoint(subd_type,subdivision_point) )
    return true;

  double displacementV[3] = { 0 };
  const bool bApplyDisplacement = GetDisplacement(subd_type,displacementV);

  const double* vertexP = m_P;

  const unsigned int n = (nullptr != m_edges ? m_edge_count : 0);
  if (n < 2)
    return ON_SubDVertex_GetSubdivisionPointError(this, subdivision_point, vertexP, true);

  if (ON_SubD::VertexTag::Smooth == m_vertex_tag || ON_SubD::VertexTag::Dart == m_vertex_tag)
  {
    if (ON_SubD::SubDType::QuadCatmullClark == subd_type)
      return ON_SubDVertex::GetQuadPoint(this, bUseSavedSubdivisionPoint, subdivision_point);
    else if (ON_SubD::SubDType::TriLoopWarren == subd_type)
      return ON_SubDVertex::GetTriPoint(this, bUseSavedSubdivisionPoint, subdivision_point);
  }

  if (ON_SubD::VertexTag::Crease == m_vertex_tag)
  {
    class ON_SubDEdgePtr* edges = m_edges;
    const ON_SubDVertex* edge0_vertex = nullptr;

    for (unsigned int i = 0; i < n; i++)
    {
      const ON_SubDEdge* edge = ON_SUBD_EDGE_POINTER(edges[i].m_ptr);
      if (nullptr == edge)
      {
        ON_SubDVertex_GetSubdivisionPointError(this, subdivision_point, vertexP, true);
        continue;
      }

      if (ON_SubD::EdgeTag::Crease != edge->m_edge_tag)
        continue;
      const ON_SubDVertex* edge_vertex = edge->OtherEndVertex(this);

      if (nullptr == edge_vertex)
      {
        ON_SubDVertex_GetSubdivisionPointError(this, subdivision_point, vertexP, true);
        continue;
      }

      if (nullptr == edge0_vertex)
      {
        edge0_vertex = edge_vertex;
        continue;
      }

      if (edge0_vertex == edge_vertex)
      {
        ON_SubDVertex_GetSubdivisionPointError(this, subdivision_point, vertexP, true);
        continue;
      }

      // We found the two crease edges that share this crease vertex.
      // (The parenthesis around the edgeP sum is to insure this result 
      // is independent of the order of the edges.)
      vertexP = m_P;
      const double* edgeP[2] = { edge0_vertex->m_P, edge_vertex->m_P };
      subdivision_point[0] = (vertexP[0] * 6.0 + (edgeP[0][0] + edgeP[1][0]))*0.125;
      subdivision_point[1] = (vertexP[1] * 6.0 + (edgeP[0][1] + edgeP[1][1]))*0.125;
      subdivision_point[2] = (vertexP[2] * 6.0 + (edgeP[0][2] + edgeP[1][2]))*0.125;

      if (bApplyDisplacement)
      {
        subdivision_point[0] += displacementV[0];
        subdivision_point[1] += displacementV[1];
        subdivision_point[2] += displacementV[2];
      }

      if (bUseSavedSubdivisionPoint)
        SetSavedSubdivisionPoint(subd_type,subdivision_point);

      return true;
    }

    return ON_SubDVertex_GetSubdivisionPointError(this, subdivision_point, vertexP, true);
  }

  if (ON_SubD::VertexTag::Corner == m_vertex_tag)
  {
    vertexP = m_P;
    subdivision_point[0] = vertexP[0];
    subdivision_point[1] = vertexP[1];
    subdivision_point[2] = vertexP[2];

    if (bApplyDisplacement)
    {
      subdivision_point[0] += displacementV[0];
      subdivision_point[1] += displacementV[1];
      subdivision_point[2] += displacementV[2];
    }

    if (bUseSavedSubdivisionPoint)
      SetSavedSubdivisionPoint(subd_type,subdivision_point);

    return true;
  }

  // vertex is damaged
  return ON_SubDVertex_GetSubdivisionPointError(this, subdivision_point, vertexP, true);
}

unsigned int ON_SubDVertex::GetFacePointSum(
  const ON_SubDFace* face,
  const ON_SubDVertex* vertex,
  double* facePsum
  )
{
  const ON_SubDEdge* e;
  ON__UINT_PTR e_ptr, edir;
  const double* faceP;

  if (nullptr == face)
    return 0;

  const unsigned int n = face->m_edge_count;

  facePsum[0] = 0.0;
  facePsum[1] = 0.0;
  facePsum[2] = 0.0;

  if (3 == n)
  {
    return n;
  }

  if (4 == n)
  {
    for (unsigned int i = 0; i < 4; i++)
    {
      e_ptr = face->m_edge4[i].m_ptr;
      e = ON_SUBD_EDGE_POINTER(e_ptr);
      if (nullptr != e && (vertex == e->m_vertex[0] || vertex == e->m_vertex[1]))
      {
        edir = ON_SUBD_EDGE_DIRECTION(e_ptr);
        e_ptr = face->m_edge4[(i + ((vertex == e->m_vertex[edir]) ? 2 : 3)) % 4].m_ptr;
        e = ON_SUBD_EDGE_POINTER(e_ptr);
        edir = ON_SUBD_EDGE_DIRECTION(e_ptr);
        if (nullptr == e || nullptr == e->m_vertex[edir])
          return 0;
        faceP = e->m_vertex[edir]->m_P;
        facePsum[0] = faceP[0];
        facePsum[1] = faceP[1];
        facePsum[2] = faceP[2];
        return n;
      }
    }
    return 0;
  }

  if (n <= 4 || nullptr == face->m_edgex)
    return 0;

  e_ptr = face->m_edgex[n-5].m_ptr;
  e = ON_SUBD_EDGE_POINTER(e_ptr);
  if (nullptr == e)
    return 0;
  edir = ON_SUBD_EDGE_DIRECTION(e_ptr);
  unsigned int skipped_edge_count = (vertex == e->m_vertex[edir]) ? 1 : 0;
  unsigned int facePcount = 0;
  const ON_SubDEdgePtr* edge_ptrs = face->m_edge4;
  for (unsigned int i = skipped_edge_count; i < n; i++)
  {
    if (4 == i)
      edge_ptrs = face->m_edgex - 4;
    e_ptr = edge_ptrs[i].m_ptr;
    e = ON_SUBD_EDGE_POINTER(e_ptr);
    if (nullptr == e)
      return 0;
    edir = ON_SUBD_EDGE_DIRECTION(e_ptr);
    if (vertex == e->m_vertex[0] || vertex == e->m_vertex[1])
    {
      skipped_edge_count++;
      if (skipped_edge_count > 2)
      {
        facePsum[0] = 0.0;
        facePsum[1] = 0.0;
        facePsum[2] = 0.0;
        return 0;
      }
      if (vertex == e->m_vertex[edir])
      {
        i++;
        if (4 == i)
          edge_ptrs = face->m_edgex - 4;
      }
      continue;
    }
    faceP = e->m_vertex[edir]->m_P;
    facePsum[0] += faceP[0];
    facePsum[1] += faceP[1];
    facePsum[2] += faceP[2];
    facePcount++;
  }

  if (n == facePcount + 3)
    return n;

  facePsum[0] = 0.0;
  facePsum[1] = 0.0;
  facePsum[2] = 0.0;
  return 0;
}

bool ON_SubDVertex::GetTriPoint(
  const class ON_SubDVertex* vertex,
  bool bUseSavedSubdivisionPoint,
  double vertex_point[3]
  )
{
  if (nullptr == vertex || nullptr == vertex_point)
    return ON_SubDVertex_GetSubdivisionPointError(vertex, vertex_point, nullptr, false);

  const double* vertexP = vertex->m_P;

  const unsigned int n = (nullptr != vertex->m_edges ? vertex->m_edge_count : 0);
  if (ON_SubD::VertexTag::Smooth == vertex->m_vertex_tag || ON_SubD::VertexTag::Dart == vertex->m_vertex_tag)
  {
    if (n < 3)
      return ON_SubDVertex_GetSubdivisionPointError(vertex, vertex_point, vertexP, true);

    double edgePsum[3] = { 0 };
    const ON_SubDEdgePtr* edges = vertex->m_edges;
    ON__UINT_PTR e_ptr;
    for (unsigned int i = 0; i < n; i++)
    {
      e_ptr = edges[i].m_ptr;
      const ON_SubDEdge* edge = ON_SUBD_EDGE_POINTER(e_ptr);
      if (nullptr != edge)
      {
        const ON_SubDVertex* edge_vertex = (vertex != edge->m_vertex[0]) ? edge->m_vertex[0] : edge->m_vertex[1];
        if (nullptr != edge_vertex)
        {
          const double* edgeP = edge_vertex->m_P;
          edgePsum[0] += edgeP[0];
          edgePsum[1] += edgeP[1];
          edgePsum[2] += edgeP[2];
          continue;
        }
      }
      // treat missing or damaged face as infinitesimally small
      edgePsum[0] += vertexP[0];
      edgePsum[1] += vertexP[1];
      edgePsum[2] += vertexP[2];
    }

    double v_weight, e_weight;
    if (3 == n)
    {
      v_weight = 0.4375;  // 7/16
      e_weight = 0.1875;  // 3/16 = (9/16) / 3
    }
    else
    {
      v_weight = 0.625; // 5/8
      e_weight = 0.375/((double)n); // = (3/8)/n
    }
    vertex_point[0] = v_weight*vertexP[0] + e_weight*edgePsum[0];
    vertex_point[1] = v_weight*vertexP[1] + e_weight*edgePsum[1];
    vertex_point[2] = v_weight*vertexP[2] + e_weight*edgePsum[2];

    if (bUseSavedSubdivisionPoint)
      vertex->SetSavedSubdivisionPoint(ON_SubD::SubDType::TriLoopWarren,vertex_point);

    return true;
  }

  // vertex->m_vertex_tag is damaged
  return ON_SubDVertex_GetSubdivisionPointError(vertex, vertex_point, vertexP, true);
}


unsigned int ON_SubDimple::GlobalSubdivide(
  ON_SubD::SubDType subdivision_type,
  bool bUseSavedSubdivisionPoints
  )
{
  const bool bQuadSubD = (ON_SubD::SubDType::QuadCatmullClark == subdivision_type);
  const bool bTriSubD = (ON_SubD::SubDType::TriLoopWarren == subdivision_type);

  if (false == bQuadSubD && false == bTriSubD)
    return ON_SUBD_RETURN_ERROR(0);

  if (m_levels.UnsignedCount() <= 0)
    return ON_SUBD_RETURN_ERROR(0U);
  const unsigned int level0_index = m_levels.UnsignedCount()-1;

  if ( nullptr == m_levels[level0_index])
    return ON_SUBD_RETURN_ERROR(0U);

  const ON_SubDLevel& level0 = *m_levels[level0_index];
  if (level0.IsEmpty())
    return ON_SUBD_RETURN_ERROR(0U);
  if ( level0.m_edge_count <= 0U )
    return ON_SUBD_RETURN_ERROR(0U);

  const unsigned int level1_index = level0_index+1;
  
  if (0 == level0_index && subdivision_type != level0.m_subdivision_type )
  {
    if (false == m_levels[level0_index]->SetSubDType(subdivision_type))
      return ON_SUBD_RETURN_ERROR(0);
  }

  ON_SubDLevel* level1 = SubDLevel(level1_index,true);
  if ( nullptr == level1 )
    return ON_SUBD_RETURN_ERROR(0);
  if (false == level1->SetSubDType(subdivision_type))
    return ON_SUBD_RETURN_ERROR(0);

  double P[3];
  ON_SubDVertex* v;

  if (bQuadSubD)
  {
    // Add face points
    for (const ON_SubDFace* f0 = level0.m_face[0]; nullptr != f0; f0 = f0->m_next_face)
    {
      if (false == f0->GetSubdivisionPoint(subdivision_type, bUseSavedSubdivisionPoints, P))
        continue;
      if (nullptr == f0->m_subd_point1)
      {
        const_cast<ON_SubDFace*>(f0)->m_subd_point1 = v = AllocateVertex(ON_SubD::VertexTag::Smooth, level1_index, P);
        AddVertexToLevel(v);
      }
      else
      {
        v = const_cast<ON_SubDVertex*>(f0->m_subd_point1);
        v->m_P[0] = P[0];
        v->m_P[1] = P[1];
        v->m_P[2] = P[2];
      }
    }
  }

  // Add edge points
  for (const ON_SubDEdge* e0 = level0.m_edge[0]; nullptr != e0; e0 = e0->m_next_edge)
  {
    if (false == e0->GetSubdivisionPoint(subdivision_type, bUseSavedSubdivisionPoints, P))
      continue;
    // (the subdivision point of an edge tagged as ON_SubD::EdgeTag::X is a smooth vertex.)
    const ON_SubD::VertexTag vertex_tag
      = ON_SubD::EdgeTag::Crease == e0->m_edge_tag
      ? ON_SubD::VertexTag::Crease
      : ON_SubD::VertexTag::Smooth;
    if (nullptr == e0->m_subd_point1)
    {
      const_cast<ON_SubDEdge*>(e0)->m_subd_point1 = v = AllocateVertex(vertex_tag, level1_index, P );
      AddVertexToLevel(v);
    }
    else
    {
      v = const_cast<ON_SubDVertex*>(e0->m_subd_point1);
      v->m_vertex_tag = vertex_tag;
      v->m_P[0] = P[0];
      v->m_P[1] = P[1];
      v->m_P[2] = P[2];
    }
  }

  // Add vertex points
  for (const ON_SubDVertex* v0 = level0.m_vertex[0]; nullptr != v0; v0 = v0->m_next_vertex)
  {
    if (false == v0->GetSubdivisionPoint(subdivision_type, bUseSavedSubdivisionPoints, P))
      continue;
    if (nullptr == v0->m_subd_point1)
    {
      const_cast<ON_SubDVertex*>(v0)->m_subd_point1 = v = AllocateVertex(v0->m_vertex_tag, level1_index, P);
      AddVertexToLevel(v);
    }
    else
    {
      v = const_cast<ON_SubDVertex*>(v0->m_subd_point1);
      v->m_vertex_tag = v0->m_vertex_tag;
      v->m_P[0] = P[0];
      v->m_P[1] = P[1];
      v->m_P[2] = P[2];
    }
    
  }

  bool bUpdateEdgeWeights = false;

  // subdivide edges
  for (const ON_SubDEdge* e0 = level0.m_edge[0]; nullptr != e0; e0 = e0->m_next_edge)
  {
    if (nullptr == e0->m_subd_point1)
      continue;
    ON_SubDVertex* end_vertex[2] = { const_cast<ON_SubDVertex*>(e0->m_vertex[0]->m_subd_point1), const_cast<ON_SubDVertex*>(e0->m_vertex[1]->m_subd_point1) };
    ON_SubDVertex* mid_vertex = const_cast<ON_SubDVertex*>(e0->m_subd_point1);
    double w[2] = { e0->m_sector_coefficient[0], e0->m_sector_coefficient[1] };
    if (bTriSubD && ON_SubD::EdgeTag::Smooth == e0->m_edge_tag && !(0.0 == w[0] && 0.0 == w[1]))
    {
      // If a neighboring face is not a triangle, the weight will need to be recalculated.
      for (unsigned int i = 0; i < e0->m_face_count; i++)
      {
        const ON_SubDFace* f = e0->Face(i);
        if (nullptr != f && 3 != f->m_edge_count)
        {
          bUpdateEdgeWeights = true;
          if (!(0.0 == w[0]))
            w[0] = ON_SubDSectorType::UnsetSectorWeight;
          if (!(0.0 == w[1]))
            w[1] = ON_SubDSectorType::UnsetSectorWeight;
          break;
        }
      }
    }
    ON_SubD::EdgeTag edge_tag = e0->m_edge_tag;
    if (ON_SubD::EdgeTag::X == edge_tag && 2 == e0->m_face_count)
    {
      if ( nullptr != mid_vertex && ON_SubD::VertexTag::Smooth == mid_vertex->m_vertex_tag )
        edge_tag = ON_SubD::EdgeTag::Smooth;
    }
    AddEdge(edge_tag, end_vertex[0], w[0], mid_vertex, 0.0);
    AddEdge(edge_tag, mid_vertex, 0.0, end_vertex[1], w[1]);
  }

  // subdivide faces
  if (bTriSubD)
  {
    for (const ON_SubDFace* f0 = level0.m_face[0]; nullptr != f0; f0 = f0->m_next_face)
    {
      bool bUnsetEdgeWeight = false;
      GlobalTriSubdivideFace(f0, bUseSavedSubdivisionPoints, &bUnsetEdgeWeight);
      if (bUnsetEdgeWeight)
        bUpdateEdgeWeights = true;
    }

    if (bUpdateEdgeWeights)
    {
      for (const ON_SubDEdge* e1 = level1->m_edge[0]; nullptr != e1; e1 = e1->m_next_edge)
      {
        if (ON_SubD::EdgeTag::Smooth != e1->m_edge_tag)
          continue;
        for (unsigned int i = 0; i < 2; i++)
        {
          if (ON_SubDSectorType::UnsetSectorWeight == e1->m_sector_coefficient[i])
          {
            const double w = ON_SubDSectorType::Create(subdivision_type, e1, i).SectorWeight();
            const_cast<ON_SubDEdge*>(e1)->m_sector_coefficient[i] = w;
          }
        }
      }
    }
  }

  if (bQuadSubD)
  {
    for (const ON_SubDFace* f0 = level0.m_face[0]; nullptr != f0; f0 = f0->m_next_face)
    {
      GlobalQuadSubdivideFace(bUseSavedSubdivisionPoints,f0);
    }
  }

  return level1_index;
}

unsigned int ON_SubDimple::GlobalQuadSubdivideFace(
  bool bUseSavedSubdivisionPoint,
  const ON_SubDFace* f0
  )
{
  // This is a private member function.  
  // The caller insures f0 != nullptr.

  const ON_SubD::SubDType subdivision_type = ON_SubD::SubDType::QuadCatmullClark;

  const unsigned int f0_edge_count = f0->m_edge_count;
  if (f0_edge_count < 3)
    return 0;

  const unsigned int parent_face_id = f0->m_id;
  const unsigned int zero_face_id = (0 == f0->m_level) ? parent_face_id : f0->m_zero_face_id;

  if (nullptr == f0->m_subd_point1)
  {
    // add face centroid
    double faceC[3];
    if (false == f0->GetSubdivisionPoint(subdivision_type, bUseSavedSubdivisionPoint, faceC))
      return 0;
    f0->SetSavedSubdivisionPoint(subdivision_type,faceC);
    unsigned int level1_index = f0->m_level + 1;
    ON_SubDVertex* v = AllocateVertex(ON_SubD::VertexTag::Smooth, level1_index, faceC );
    AddVertexToLevel(v);
    const_cast<ON_SubDFace*>(f0)->m_subd_point1 = v;
  }


  ON_SubDEdge* E0[2];
  ON__UINT_PTR E0dir[2];
  ON_SubDEdge* E1[4];
  ON__UINT_PTR E1dir[4];
  ON_SubDEdgePtr f1edges[4];
  ON__UINT_PTR e_ptr;
  ON_SubDEdge* FirstE1(nullptr);
  double w;

  e_ptr = f0->EdgePtr(f0_edge_count - 1).m_ptr;
  E0[1] = ON_SUBD_EDGE_POINTER(e_ptr);
  E0dir[1] = ON_SUBD_EDGE_DIRECTION(e_ptr);
  E1[2] = nullptr;

  unsigned int f1_count = 0;

  const double w_2facesector = ON_SubDSectorType::CreaseSectorWeight(subdivision_type, 2);

  for (unsigned int i = 0; i < f0_edge_count; i++)
  {
    E0[0] = E0[1];
    E0dir[0] = E0dir[1];
    e_ptr = f0->EdgePtr(i).m_ptr;
    E0[1] = ON_SUBD_EDGE_POINTER(e_ptr);
    E0dir[1] = ON_SUBD_EDGE_DIRECTION(e_ptr);

    if (nullptr == E0[0] || nullptr == E0[1])
      continue;
    if (nullptr == E0[0]->m_subd_point1 || nullptr == E0[1]->m_subd_point1)
      continue;

    e_ptr = E0[0]->m_subd_point1->m_edges[0 == E0dir[0] ? 1 : 0].m_ptr;
    E1[0] = ON_SUBD_EDGE_POINTER(e_ptr);
    E1dir[0] = E0dir[0];

    e_ptr = E0[1]->m_subd_point1->m_edges[0 == E0dir[1] ? 0 : 1].m_ptr;
    E1[1] = ON_SUBD_EDGE_POINTER(e_ptr);
    E1dir[1] = E0dir[1];

    E1[3] = E1[2];
    if (nullptr == E1[3])
    {
      //  The value of E0[0]->m_subd_point1->m_vertex_tag should be either 
      //  ON_SubD::VertexTag::Smooth or ON_SubD::VertexTag::Crease. In the
      //  case when it's value is "crease", the resulting edge end weight
      //  will be 0.5 because the edge has two adjacent faces and "theta"
      //  will be pi/2.  
      //  The resulting quad edge weight is 0.5 = 1/2 + 1/3*cos(pi/2).
      w = (ON_SubD::VertexTag::Crease == E0[0]->m_subd_point1->m_vertex_tag) ? w_2facesector : 0.0;
      E1[3] = AddEdge(ON_SubD::EdgeTag::Smooth, const_cast<ON_SubDVertex*>(f0->m_subd_point1), 0.0, const_cast<ON_SubDVertex*>(E0[0]->m_subd_point1), w);
      if (nullptr == FirstE1)
        FirstE1 = E1[3];
    }
    E1dir[3] = 0;

    if (i + 1 < f0_edge_count || nullptr == FirstE1)
    {
      //  The value of E0[0]->m_subd_point1->m_vertex_tag should be either 
      //  ON_SubD::VertexTag::Smooth or ON_SubD::VertexTag::Crease. In the
      //  case when it's value is "crease", the resulting edge end weight
      //  will be zero because the edge has two adjacent faces and "theta"
      //  will be pi/2.  The resulting edge weight is 0.5.
      w = (ON_SubD::VertexTag::Crease == E0[1]->m_subd_point1->m_vertex_tag) ? w_2facesector : 0.0;
      E1[2] = AddEdge(ON_SubD::EdgeTag::Smooth, const_cast<ON_SubDVertex*>(f0->m_subd_point1), 0.0, const_cast<ON_SubDVertex*>(E0[1]->m_subd_point1), w);
    }
    else
    {
      E1[2] = FirstE1;
    }
    E1dir[2] = 1;

    f1edges[0] = ON_SubDEdgePtr::Create(E1[0], E1dir[0]);
    f1edges[1] = ON_SubDEdgePtr::Create(E1[1], E1dir[1]);
    f1edges[2] = ON_SubDEdgePtr::Create(E1[2], E1dir[2]);
    f1edges[3] = ON_SubDEdgePtr::Create(E1[3], E1dir[3]);

    ON_SubDFace* f1 = AddFace(4, f1edges);
    if (nullptr != f1)
    {
      f1->m_zero_face_id = zero_face_id;
      f1->m_parent_face_id = parent_face_id;
      f1_count++;
    }
  }

  // return number of new faces
  return f1_count;
}


static double TriCornerSectorWeight(
  ON_SubDEdgePtr e0_ptr,
  ON_SubDEdgePtr e1_ptr,
  ON_SubD::VertexTag vertex_tag
  )
{
  const ON_SubD::SubDType subdivision_type = ON_SubD::SubDType::TriLoopWarren;

  if (ON_SubD::VertexTag::Smooth == vertex_tag)
    return 0.0;

  if (ON_SubD::VertexTag::Unset == vertex_tag)
    return ON_SUBD_RETURN_ERROR(ON_SubDSectorType::ErrorSectorWeight);

  const ON_SubDEdge* e0 = ON_SUBD_EDGE_POINTER(e0_ptr.m_ptr);
  if (nullptr == e0)
    return ON_SUBD_RETURN_ERROR(ON_SubDSectorType::ErrorSectorWeight);
  ON__INT_PTR e0dir = ON_SUBD_EDGE_DIRECTION(e0_ptr.m_ptr);

  const ON_SubDEdge* e1 = ON_SUBD_EDGE_POINTER(e1_ptr.m_ptr);
  if (nullptr == e1)
    return ON_SUBD_RETURN_ERROR(ON_SubDSectorType::ErrorSectorWeight);
  ON__INT_PTR e1dir = ON_SUBD_EDGE_DIRECTION(e1_ptr.m_ptr);

  // flip direction of e0 so that both edges are leaving the vertex
  e0dir = 1 - e0dir;
    
  if (ON_SubD::EdgeTag::Crease == e0->m_edge_tag && ON_SubD::EdgeTag::Crease == e1->m_edge_tag)
  {
    // The radial edge we are about to add has two faces in its sector between the
    // creased edges e0 and e1.
    unsigned int sector_face_count = 2;      
    if (ON_SubD::VertexTag::Crease == vertex_tag)
    {
      return ON_SubDSectorType::CreaseSectorWeight(subdivision_type, sector_face_count);
    }
    
    if (ON_SubD::VertexTag::Corner == vertex_tag)
    {
      const double corner_sector_angle_radians 
        = ON_SubDSectorType::CornerSectorAngleRadiansFromEdges(ON_SubDEdgePtr::Create(e0, e0dir), ON_SubDEdgePtr::Create(e1, e1dir));
      return ON_SubDSectorType::CreateCornerSectorType(subdivision_type, sector_face_count, corner_sector_angle_radians).SectorWeight();
    }
    
    return ON_SUBD_RETURN_ERROR(ON_SubDSectorType::ErrorSectorWeight);
  }

  if (ON_SubD::VertexTag::Crease == vertex_tag || ON_SubD::VertexTag::Corner == vertex_tag || ON_SubD::VertexTag::Dart == vertex_tag)
  {
    // The weight calculation requires all edges in the sector exist
    // and has to be delayed until the subdivision topology is complete.
    return ON_SubDSectorType::UnsetSectorWeight;
  }
    
  double w0
    = (ON_SubD::EdgeTag::Smooth == e0->m_edge_tag)
    ? e0->m_sector_coefficient[e0dir]
    : ON_SubDSectorType::UnsetSectorWeight;

  double w1
    = (ON_SubD::EdgeTag::Smooth == e1->m_edge_tag)
    ? e1->m_sector_coefficient[e1dir]
    : ON_SubDSectorType::UnsetSectorWeight;

  double w = (w0 == w1) ? w0 : ((ON_SubDSectorType::UnsetSectorWeight != w0) ? w0 : w1);
  if (w == w && ON_SubDSectorType::UnsetSectorWeight != w)
    return w;

  return ON_SUBD_RETURN_ERROR(ON_SubDSectorType::ErrorSectorWeight);
}

unsigned int ON_SubDimple::GlobalTriSubdivideFace(
  const ON_SubDFace* f0,
  bool bUseSavedSubdivisionPoint,
  bool* bUnsetEdgeWeight
  )
{
  const ON_SubD::SubDType subdivision_type = ON_SubD::SubDType::TriLoopWarren;

  // This is a private member function.  
  // The caller insures f0 != nullptr and bUnsetEdgeWeight != nullptr.

  *bUnsetEdgeWeight = false;

  const unsigned int f0_edge_count = f0->m_edge_count;
  if (f0_edge_count < 3)
    return 0;

  const unsigned int parent_face_id = f0->m_id;
  const unsigned int zero_face_id = (0 == f0->m_level) ? parent_face_id : f0->m_zero_face_id;


  ON_SubDEdge* E0[3];
  ON__UINT_PTR E0dir[3];
  ON_SubDEdge* E1[9];
  ON_SubDEdgePtr f1edges[3];
  ON__UINT_PTR e_ptr;
  ON_SubDFace* f1;

  e_ptr = f0->EdgePtr(f0_edge_count - 1).m_ptr;
  E0[1] = ON_SUBD_EDGE_POINTER(e_ptr);
  E0dir[1] = ON_SUBD_EDGE_DIRECTION(e_ptr);
  E1[2] = nullptr;

  unsigned int f1_count = 0;

  if (3 == f0_edge_count)
  {
    unsigned int j = 0;
    for (unsigned int i = 0; i < 3; i++)
    {
      e_ptr = f0->m_edge4[i].m_ptr;
      E0[i] = ON_SUBD_EDGE_POINTER(e_ptr);
      if (nullptr == E0[i] || nullptr == E0[i]->m_subd_point1)
        break;
      E0dir[i] = ON_SUBD_EDGE_DIRECTION(e_ptr);

      e_ptr = E0[i]->m_subd_point1->m_edges[E0dir[i]].m_ptr;
      E1[j] = ON_SUBD_EDGE_POINTER(e_ptr);
      if (nullptr == E1[j])
        break;
      j++;

      e_ptr = E0[i]->m_subd_point1->m_edges[1 - E0dir[i]].m_ptr;
      E1[j] = ON_SUBD_EDGE_POINTER(e_ptr);
      if (nullptr == E1[j])
        break;
      j++;
    }
    if (6 != j)
      return 0;

    //  The value of E0[0]->m_subd_point1->m_vertex_tag should be either 
    //  ON_SubD::VertexTag::Smooth or ON_SubD::VertexTag::Crease. In the
    //  case when it's value is "crease", the resulting edge end weight
    //  will be 0.5 because the edge has three adjacent faces and "theta"
    //  will be pi/3.  
    //  The resulting tri edge weight is 0.5 = 1/3 + 1/3*cos(pi/3).
    const double w_3facesector = ON_SubDSectorType::CreaseSectorWeight(subdivision_type, 3);

    double w0 = (ON_SubD::VertexTag::Crease == E0[0]->m_subd_point1->m_vertex_tag) ? w_3facesector : 0.0;
    double w1 = (ON_SubD::VertexTag::Crease == E0[2]->m_subd_point1->m_vertex_tag) ? w_3facesector : 0.0;
    E1[6] = AddEdge(ON_SubD::EdgeTag::Smooth, const_cast<ON_SubDVertex*>(E0[0]->m_subd_point1), w0, const_cast<ON_SubDVertex*>(E0[2]->m_subd_point1), w1);
    w0 = w1;
    w1 = (ON_SubD::VertexTag::Crease == E0[1]->m_subd_point1->m_vertex_tag) ? w_3facesector : 0.0;
    E1[7] = AddEdge(ON_SubD::EdgeTag::Smooth, const_cast<ON_SubDVertex*>(E0[2]->m_subd_point1), w0, const_cast<ON_SubDVertex*>(E0[1]->m_subd_point1), w1);
    w0 = w1;
    w1 = (ON_SubD::VertexTag::Crease == E0[0]->m_subd_point1->m_vertex_tag) ? w_3facesector : 0.0;
    E1[8] = AddEdge(ON_SubD::EdgeTag::Smooth, const_cast<ON_SubDVertex*>(E0[1]->m_subd_point1), w0, const_cast<ON_SubDVertex*>(E0[0]->m_subd_point1), w1);

    f1edges[0] = ON_SubDEdgePtr::Create(E1[0], E0dir[0]);
    f1edges[1] = ON_SubDEdgePtr::Create(E1[6], 0);
    f1edges[2] = ON_SubDEdgePtr::Create(E1[5], E0dir[2]);
    f1 = AddFace(3, f1edges);
    if (nullptr != f1)
    {
      f1->m_zero_face_id = zero_face_id;
      f1->m_parent_face_id = parent_face_id;
      f1_count++;
    }

    f1edges[0] = ON_SubDEdgePtr::Create(E1[4], E0dir[2]);
    f1edges[1] = ON_SubDEdgePtr::Create(E1[7], 0);
    f1edges[2] = ON_SubDEdgePtr::Create(E1[3], E0dir[1]);
    f1 = AddFace(3, f1edges);
    if (nullptr != f1)
    {
      f1->m_zero_face_id = zero_face_id;
      f1->m_parent_face_id = parent_face_id;
      f1_count++;
    }

    f1edges[0] = ON_SubDEdgePtr::Create(E1[2], E0dir[1]);
    f1edges[1] = ON_SubDEdgePtr::Create(E1[8], 0);
    f1edges[2] = ON_SubDEdgePtr::Create(E1[1], E0dir[0]);
    f1 = AddFace(3, f1edges);
    if (nullptr != f1)
    {
      f1->m_zero_face_id = zero_face_id;
      f1->m_parent_face_id = parent_face_id;
      f1_count++;
    }

    f1edges[0] = ON_SubDEdgePtr::Create(E1[6], 1);
    f1edges[1] = ON_SubDEdgePtr::Create(E1[8], 1);
    f1edges[2] = ON_SubDEdgePtr::Create(E1[7], 1);
    f1 = AddFace(3, f1edges);
    if (nullptr != f1)
    {
      f1->m_zero_face_id = zero_face_id;
      f1->m_parent_face_id = parent_face_id;
      f1_count++;
    }

    // return number of new faces
    return f1_count;
  }

  if (f0_edge_count < 2)
    return 0;

  // This code  builds triangles from the subdivided edges to the face's centroid.
  //
  // In general, there is no single robust way to deal with polygons with lots of sides.
  // In particular, the code below is not approprite for non-convex polygons and is
  // of limited use for polygons that are not close to regular.
  //
  // The basic issue is that if a SubD control net makes it to this point,
  // higher level code and, ultimately, the user, must be responsible
  // for creating a "reasonable" input control net.
  //
  // This code is here so something happens in trianglular subd when
  // a non-triangle is subdivided.
  //
  // This code is "reasonable" when a user wants to apply a triangular
  // subdivision to a "nice" quad mesh SubD control polygon.

  ON_SubDVertex* center_vertex = const_cast<ON_SubDVertex*>(f0->m_subd_point1);
  if (nullptr == center_vertex)
  {
    // add face centroid
    double faceC[3];
    if (false == f0->GetSubdivisionPoint(subdivision_type, bUseSavedSubdivisionPoint, faceC))
      return 0;
    f0->SetSavedSubdivisionPoint(subdivision_type, faceC);
    unsigned int level1_index = f0->m_level + 1;
    center_vertex = AllocateVertex(ON_SubD::VertexTag::Smooth, level1_index, faceC);
    if (nullptr == center_vertex)
      return 0;
    AddVertexToLevel(center_vertex);
    const_cast<ON_SubDFace*>(f0)->m_subd_point1 = center_vertex;
  }

  E1[4] = nullptr; // radial edge from end of previous vertex to this vertex
  E1[8] = nullptr; // used to save pointer to first radial edge.
  const ON_SubDVertex* edge1_vertex;
  ON_SubDVertex* right_vertex = nullptr;
  for (unsigned int i = 0; i < f0_edge_count; i++)
  {
    // This case is a special case and it will be called on control 
    // polygons created by inexperienced programmers,
    // It is important that all information be validated.  
    // When invalid information is detected, that edge/triangle
    // is simply skipped and there will be a "smooth sided hole"
    // in the resulting mesh.
    //
    ON_SubDVertex* left_vertex = right_vertex;
    right_vertex = nullptr;

    // E1[4] = previous "right" radial
    // E1[2] = current "left" radial from left_vertex to center_vertex
    E1[2] = E1[4];
    E1[4] = nullptr;

    const ON_SubDEdgePtr ei_ptr = f0->EdgePtr(i);

    E0[0] = ON_SUBD_EDGE_POINTER(ei_ptr.m_ptr);
    E0dir[0] = ON_SUBD_EDGE_DIRECTION(ei_ptr.m_ptr);
    if (nullptr == E0[0])
      continue;

    ON_SubDVertex* mid_vertex = const_cast<ON_SubDVertex*>(E0[0]->m_subd_point1);
    if (nullptr == mid_vertex || mid_vertex->m_edge_count < 2 || nullptr == mid_vertex->m_edges)
      continue;

    // E1[0] = "left" side of E0[0]
    e_ptr = mid_vertex->m_edges[E0dir[0]].m_ptr;
    E1[0] = ON_SUBD_EDGE_POINTER(e_ptr);
    if (nullptr == E1[0])
      continue;

    if (mid_vertex != E1[0]->m_vertex[1 - E0dir[0]])
      continue;

    // E1[1] = "right" side of E0[0]
    e_ptr = mid_vertex->m_edges[1 - E0dir[0]].m_ptr;
    E1[1] = ON_SUBD_EDGE_POINTER(e_ptr);
    if (nullptr == E1[1])
      continue;

    if (mid_vertex != E1[1]->m_vertex[E0dir[0]])
      continue;

    // If E0[0] is a crease:
    //  Then mid_vertex should be tagged as a crease vertex and both
    //  E1[0] and E1[1] should also be tagged as creased edges.
    //  The new edge from mid_vertex to center_vertex
    //  the "sector_face_count" will be 2 and the "theta" used to calculate the
    //  edge weight will be pi/2.
    //  mid_weight = 1/3 + 1/3*cos(pi/2) = 1/3  ( cos(pi/2) = zero )
    bool bValidTags;
    if (ON_SubD::EdgeTag::Smooth == E0[0]->m_edge_tag || ON_SubD::EdgeTag::X == E0[0]->m_edge_tag)
    {
      bValidTags 
        = ON_SubD::VertexTag::Smooth == mid_vertex->m_vertex_tag 
        && ON_SubD::EdgeTag::Smooth == E1[0]->m_edge_tag 
        && ON_SubD::EdgeTag::Smooth == E1[1]->m_edge_tag;
    }
    else if (ON_SubD::EdgeTag::Crease == E0[0]->m_edge_tag)
    {
      bValidTags 
        = ON_SubD::VertexTag::Crease == mid_vertex->m_vertex_tag 
        && ON_SubD::EdgeTag::Crease == E1[0]->m_edge_tag 
        && ON_SubD::EdgeTag::Crease == E1[1]->m_edge_tag;
    }
    else
      bValidTags = false;

    if (false == bValidTags)
    {
      ON_SubDIncrementErrorCount();
      continue;
    }

    const double mid_weight
      = (ON_SubD::EdgeTag::Crease == E0[0]->m_edge_tag)
      ? ON_SubDSectorType::CreaseSectorWeight(subdivision_type, 2)
      : ON_SubDSectorType::IgnoredSectorWeight;

    // E1[2] = radial from "start" of E1[0] to face centroid.
    edge1_vertex = E1[0]->m_vertex[E0dir[0]];
    if (nullptr == left_vertex || nullptr == E1[2] || left_vertex != E1[2]->m_vertex[0] || left_vertex != edge1_vertex)
    {      
      // when input is valid, this clause is executed when i = 0.
      left_vertex = const_cast<ON_SubDVertex*>(edge1_vertex);
      if (nullptr != left_vertex)
      {
        const double left_w = TriCornerSectorWeight(f0->EdgePtr((i + (f0_edge_count-1)) % f0_edge_count), ei_ptr, left_vertex->m_vertex_tag);
        if (ON_SubDSectorType::UnsetSectorWeight == left_w)
          *bUnsetEdgeWeight = true;
        E1[2] = AddEdge(ON_SubD::EdgeTag::Smooth, left_vertex, left_w, center_vertex, 0.0);
        if (0 == i)
        {
          // E1[8] = first radial edge
          E1[8] = E1[2];
        }
      }
      else
        E1[2] = nullptr;
    }

     // E1[3] = radial from E0[0]->m_subd_point1 to face centroid.
    E1[3] = AddEdge(ON_SubD::EdgeTag::Smooth, mid_vertex, mid_weight, center_vertex, 0.0);
    if (nullptr == E1[3])
      continue;

    // E1[4] = radial from "end" of E1[1] to face centroid.
    if (i + 1 < f0_edge_count)
    {
      right_vertex = const_cast<ON_SubDVertex*>(E1[1]->m_vertex[1 - E0dir[0]]);
      if (nullptr != right_vertex)
      {
        const double right_w = TriCornerSectorWeight(ei_ptr, f0->EdgePtr((i + 1) % f0_edge_count), right_vertex->m_vertex_tag);
        if (ON_SubDSectorType::UnsetSectorWeight == right_w)
          *bUnsetEdgeWeight = true;
        E1[4] = AddEdge(ON_SubD::EdgeTag::Smooth, right_vertex, right_w, center_vertex, 0.0);
      }
      else
        E1[4] = nullptr;
    }
    else
    {
      // E1[8] = first radial edge
      E1[4] = E1[8];
    }

    if (nullptr != E1[0] && nullptr != E1[2])
    {
      // "left" triangle with "base" E1[0] and apex at face centroid
      // the "base" ON_SubDEdgePtr::Create(E1[0], E0dir[0]) runs from V1[0] to E0[0]->m_subd_point1.
      f1edges[0] = ON_SubDEdgePtr::Create(E1[0], E0dir[0]); // V1[0] to E0[0]->m_subd_point1
      f1edges[1] = ON_SubDEdgePtr::Create(E1[3], 0); // E0[0]->m_subd_point1 to center_vertex
      f1edges[2] = ON_SubDEdgePtr::Create(E1[2], 1); // center_vertex to V1[0]
      f1 = AddFace(3, f1edges);
      if (nullptr != f1)
      {
        f1->m_zero_face_id = zero_face_id;
        f1->m_parent_face_id = parent_face_id;
        f1_count++;
      }
    }

    if (nullptr != E1[1] && nullptr != E1[4] )
    {
      // "right" triangle with "base" E1[1] and apex at face centroid
      // The "base" ON_SubDEdgePtr::Create(E1[1], E0dir[0]) runs from E0[0]->m_subd_point1 to V1[1].
      f1edges[0] = ON_SubDEdgePtr::Create(E1[1], E0dir[0]); // E0[0]->m_subd_point1 to V1[1]
      f1edges[1] = ON_SubDEdgePtr::Create(E1[4], 0); // V1[1] to center_vertex
      f1edges[2] = ON_SubDEdgePtr::Create(E1[3], 1); // center_vertex to E0[0]->m_subd_point1
      f1 = AddFace(3, f1edges);
      if (nullptr != f1)
      {
        f1->m_zero_face_id = zero_face_id;
        f1->m_parent_face_id = parent_face_id;
        f1_count++;
      }
    }
  }

  // return number of faces added
  return f1_count;
}

bool ON_SubD::Subdivide(
  ON_SubD::SubDType subd_type,
  unsigned int level_index,
  unsigned int count
  )
{
  ON_SubDimple* subdimple = SubDimple(false);
  if (nullptr == subdimple)
    return ON_SUBD_RETURN_ERROR(false);
  return subdimple->Subdivide(subd_type,level_index,count);
}


bool ON_SubDimple::Subdivide(
  ON_SubD::SubDType subd_type,
  unsigned int level_index,
  unsigned int count
  )
{
  if (level_index >= m_levels.UnsignedCount() || nullptr == m_levels[level_index])
    return ON_SUBD_RETURN_ERROR(false);

  if (count <= 0)
    return ON_SUBD_RETURN_ERROR(false);

  if (level_index+count > ON_SubD::maximum_subd_level)
    return ON_SUBD_RETURN_ERROR(false);


  if (ON_SubD::SubDType::Unset == subd_type)
  {
    subd_type = m_levels[level_index]->m_subdivision_type;
    if ( ON_SubD::SubDType::Unset == subd_type )
      subd_type = ON_SubD::DefaultSubDType();
  }

  if (false == ON_SubD::IsQuadOrTriSubDType(subd_type))
    return ON_SUBD_RETURN_ERROR(false);

  if (subd_type != m_levels[level_index]->m_subdivision_type)
  {
    if (false == m_levels[level_index]->SetSubDType(subd_type))
      return ON_SUBD_RETURN_ERROR(false);
  }

  ClearHigherSubdivisionLevels(level_index + 1);
  if ( level_index + 1 != m_levels.UnsignedCount() )
    return ON_SUBD_RETURN_ERROR(false);

  m_active_level = m_levels[level_index];
 
  const bool bUseSavedSubdivisionPoints = true;
  for (unsigned int i = level_index+1; i <= level_index+count; i++)
  {
    unsigned int rc = GlobalSubdivide(subd_type,bUseSavedSubdivisionPoints);
    if (i != rc)
      return ON_SUBD_RETURN_ERROR(false);
    m_active_level = m_levels[i];
  }
  return true;
}

ON_SubDEdgePtr ON_SubDimple::MergeEdges(
  ON_SubDEdgePtr eptr0,
  ON_SubDEdgePtr eptr1
  )
{
  if ( false == ON_SubD::EdgesCanBeMerged(eptr0,eptr1) )
    return ON_SUBD_RETURN_ERROR(ON_SubDEdgePtr::Null);

  ON_SubDEdge* e[2] = { ON_SUBD_EDGE_POINTER(eptr0.m_ptr), ON_SUBD_EDGE_POINTER(eptr1.m_ptr) };
  ON__UINT_PTR edir[2] = { ON_SUBD_EDGE_DIRECTION(eptr0.m_ptr), ON_SUBD_EDGE_DIRECTION(eptr1.m_ptr) };
  const ON_SubDVertex* end_v[2] = {e[0]->m_vertex[edir[0]], e[1]->m_vertex[1 - edir[1]]};
  if (nullptr == end_v[0] || nullptr == end_v[1] || end_v[0] == end_v[1] )
    return ON_SUBD_RETURN_ERROR(ON_SubDEdgePtr::Null);

  ON_SubD::EdgeTag merged_edge_tag 
    = (e[0]->IsSmooth() || e[1]->IsSmooth())
    ? ON_SubD::EdgeTag::Smooth
    : ON_SubD::EdgeTag::Crease;

  for (unsigned int j = 0; j < e[1]->m_face_count; j++)
  {
    ON_SubDFace* f = const_cast<ON_SubDFace*>(e[1]->Face(j));
    if (nullptr == f)
      continue;
    f->RemoveEdgeFromArray(e[1]);
  }
  
  // remove middle vertex
  ON_SubDVertex* middle_v = const_cast< ON_SubDVertex* >(e[1]->m_vertex[edir[1]]);
  if (nullptr != middle_v && middle_v != end_v[0] && middle_v != end_v[1] )
  {
    if (middle_v->m_edge_count > 0 && nullptr != middle_v->m_edges)
    {
      unsigned int vei0 = middle_v->EdgeArrayIndex(e[0]);
      unsigned int vei1 = middle_v->EdgeArrayIndex(e[1]);      
      unsigned int vei_count = middle_v->m_edge_count;
      middle_v->m_edge_count = 0;
      for (unsigned int vei = 0; vei < vei_count; vei++)
      {
        if ( vei == vei0 || vei == vei1 )
          continue;

        // happens when middle_v is a multiple sector corner, non-manifold, or other rare cases
        if (vei > middle_v->m_edge_count)
          middle_v->m_edges[middle_v->m_edge_count] = middle_v->m_edges[vei];
        middle_v->m_edge_count++;
      }
    }
    if (0 == middle_v->m_edge_count || nullptr == middle_v->m_edges)
    {
      ReturnVertex(middle_v);
      middle_v = nullptr;
    }
  }

  e[0]->m_vertex[1-edir[0]] = nullptr;
  e[1]->m_vertex[edir[1]] = nullptr;
  e[1]->m_vertex[1-edir[1]] = nullptr;

  for (unsigned int i = 0; i < end_v[1]->m_edge_count; i++)
  {
    if (e[1] == ON_SUBD_EDGE_POINTER(end_v[1]->m_edges[i].m_ptr))
    {
      const_cast< ON_SubDVertex* >(end_v[1])->m_edges[i] = ON_SubDEdgePtr::Create(e[0], 1 - edir[0]);
      e[0]->m_vertex[1 - edir[0]] = end_v[1];
      break;
    }
  }

  e[0]->m_sector_coefficient[1 - edir[0]] = e[1]->m_sector_coefficient[1 - edir[1]];

  const bool bTagged[2] = { end_v[0]->IsCreaseOrCorner(), end_v[1]->IsCreaseOrCorner() };
  if (ON_SubD::EdgeTag::Smooth == merged_edge_tag || false == bTagged[0] || false == bTagged[1])
  {
    e[0]->m_edge_tag
      = (bTagged[0] && bTagged[1])
      ? ON_SubD::EdgeTag::X
      : ON_SubD::EdgeTag::Smooth;
    if ( false == bTagged[0])
      e[0]->m_sector_coefficient[0] = ON_SubDSectorType::IgnoredSectorWeight;
    else if (!(e[0]->m_sector_coefficient[0] > 0.0 && e[0]->m_sector_coefficient[0] < 1.0))
      e[0]->m_sector_coefficient[0] = ON_SubDSectorType::UnsetSectorWeight;
    if ( false == bTagged[1])
      e[0]->m_sector_coefficient[1] = ON_SubDSectorType::IgnoredSectorWeight;
    else if (!(e[0]->m_sector_coefficient[1] > 0.0 && e[0]->m_sector_coefficient[1] < 1.0))
      e[0]->m_sector_coefficient[1] = ON_SubDSectorType::UnsetSectorWeight;
  }
  else
  {
    e[0]->m_edge_tag = ON_SubD::EdgeTag::Crease;
    e[0]->m_sector_coefficient[0] = ON_SubDSectorType::IgnoredSectorWeight;
    e[0]->m_sector_coefficient[1] = ON_SubDSectorType::IgnoredSectorWeight;
  }

  ReturnEdge(e[1]);

  return eptr0;
}

ON_SubDEdgePtr ON_SubD::MergeEdges(
  ON_SubDEdgePtr eptr0,
  ON_SubDEdgePtr eptr1
  )
{
  ON_SubDimple* subdimple = SubDimple(false);
  return (nullptr != subdimple) ? subdimple->MergeEdges(eptr0, eptr1) : ON_SubDEdgePtr::Null;
}

static bool EdgesAreMergableTest(
  ON_SubDEdge* e[2],
  ON__UINT_PTR edir[2],
  bool bTestColinearity,
  double distance_tolerance,
  double maximum_aspect,
  double sin_angle_tolerance
  )
{
  if (
    nullptr == e[0] || nullptr == e[1] 
    || e[0] == e[1]
    || edir[0] > 1 || edir[1] > 1
    || e[0]->m_face_count != e[1]->m_face_count
    //|| e[0]->m_edge_tag != e[1]->m_edge_tag
    )
  {
    return false;
  }

  if ( nullptr == e[1]->m_vertex[0] || nullptr == e[1]->m_vertex[1] )
  {
    // Setting e[1] = nullptr used in edge merging code and doesn't hurt other uses of this static function
    e[1] = nullptr;
    return false;
  }

  // v[0] = start
  // v[1] = end
  // v[2] = middle (will be removed)
  const ON_SubDVertex* v[4] = { e[0]->m_vertex[edir[0]], e[1]->m_vertex[1 - edir[1]], e[0]->m_vertex[1 - edir[0]], e[1]->m_vertex[edir[1]] };

  if (nullptr == v[0] || nullptr == v[1] || nullptr == v[2] || v[0] == v[1] || v[2] != v[3])
  {
    return false;
  }

  if (bTestColinearity)
  {
    if (ON_UNSET_UINT_INDEX == v[2]->EdgeArrayIndex(e[0]) || ON_UNSET_UINT_INDEX == v[2]->EdgeArrayIndex(e[1]))
      bTestColinearity = false;
  }

  // edges must have the same faces
  switch (e[0]->m_face_count)
  {
  case 0:
    break;

  case 1:
    if (ON_SUBD_FACE_POINTER(e[0]->m_face2[0].m_ptr) == ON_SUBD_FACE_POINTER(e[1]->m_face2[0].m_ptr))
      break;

    return false;

  case 2:
    if (ON_SUBD_FACE_POINTER(e[0]->m_face2[0].m_ptr) == ON_SUBD_FACE_POINTER(e[1]->m_face2[0].m_ptr)
      && ON_SUBD_FACE_POINTER(e[0]->m_face2[1].m_ptr) == ON_SUBD_FACE_POINTER(e[1]->m_face2[1].m_ptr))
      break;

    if (ON_SUBD_FACE_POINTER(e[0]->m_face2[0].m_ptr) == ON_SUBD_FACE_POINTER(e[1]->m_face2[1].m_ptr)
      && ON_SUBD_FACE_POINTER(e[0]->m_face2[1].m_ptr) == ON_SUBD_FACE_POINTER(e[1]->m_face2[0].m_ptr))
      break;

    return false;

  default:
    // non-manifold edge
    {
      unsigned int j, k;
      for (j = 0; j < e[0]->m_face_count; j++)
      {
        const ON_SubDFace* f = e[0]->Face(j);
        for (k = 0; k < e[1]->m_face_count; k++)
        {
          if (f == e[1]->Face(k))
            break;
        }
        if (k < e[1]->m_face_count)
          continue;
        break;
      }
      if (j != e[0]->m_face_count)
        return false;
    }
    break;
  }

  if (bTestColinearity)
  {
    const ON_3dPoint* P[3] = { (const ON_3dPoint*)v[0]->m_P, (const ON_3dPoint*)v[2]->m_P, (const ON_3dPoint*)v[1]->m_P };

    ON_3dVector D(*P[2] - *P[0]);
    const double d = D.Length();
    if (!(d > 0.0))
      return false;
    const ON_3dVector V(*P[1] - *P[0]);
    const double t = (V*D) / (d*d);
    if (!(t > ON_EPSILON && t < 1.0 - ON_EPSILON))
      return false;

    const ON_3dPoint M = (1.0 - t)*(*P[0]) + t*(*P[2]);
    const double h = P[1]->DistanceTo(M);

    if (0.0 == h)
      return true;

    if (!(h > 0.0))
      return false;

    const double miniscule_distance_tolerance = ON_ZERO_TOLERANCE;
    if (h <= miniscule_distance_tolerance && !(distance_tolerance >= 0.0 && distance_tolerance < miniscule_distance_tolerance))
    {
      // skip parameter tests for miniscule h.
      return true;
    }

    const double miniscule_maximum_aspect = 1e-4;
    if (h <= miniscule_maximum_aspect * d && !(maximum_aspect >= 0.0 && maximum_aspect < miniscule_maximum_aspect))
    {
      // skip parameter tests for miniscule h/d.
      return true;
    }

    if (distance_tolerance >= 0.0 && !(h <= distance_tolerance))
      return false; // failed distance to chord test

    if (maximum_aspect >= 0.0 && !(h <= maximum_aspect * d))
      return false; // failed maximum aspect test

    if (sin_angle_tolerance >= 0.0 && sin_angle_tolerance < 1.0 && !(ON_CrossProduct(V, (*P[1] - *P[2])).Length() <= sin_angle_tolerance))
      return false; // failed minimum angle test
  }
  return true;
}

bool ON_SubD::EdgesCanBeMerged(
  ON_SubDEdgePtr eptr0,
  ON_SubDEdgePtr eptr1
  )
{
  ON_SubDEdge* e[2] = { ON_SUBD_EDGE_POINTER(eptr0.m_ptr), ON_SUBD_EDGE_POINTER(eptr1.m_ptr) };
  ON__UINT_PTR edir[2] = { ON_SUBD_EDGE_DIRECTION(eptr0.m_ptr), ON_SUBD_EDGE_DIRECTION(eptr1.m_ptr) };
  return EdgesAreMergableTest(e,edir,false,ON_DBL_QNAN,ON_DBL_QNAN,ON_DBL_QNAN);
}

unsigned int ON_SubDimple::MergeColinearEdges(
  double distance_tolerance,
  double maximum_aspect,
  double sin_angle_tolerance
  )
{
  if (1 != m_levels.UnsignedCount())
    return false;

  unsigned int removed_edge_count = 0;

  for (const ON_SubDFace* f = ActiveLevel().m_face[0]; nullptr != f; f = f->m_next_face)
  {
    unsigned int edge_count = f->m_edge_count;
    if (edge_count < 3)
      continue;
    ON_SubDEdge* e[2] = { 0 };
    ON__UINT_PTR edir[2] = { 0 };
    unsigned int i0 = ON_UNSET_UINT_INDEX;
    for (unsigned int i = 0; i <= edge_count; i++)
    {
      e[0] = e[1];
      edir[0] = edir[1];
      ON__UINT_PTR eptr = f->EdgePtr(i%edge_count).m_ptr;
      e[1] = ON_SUBD_EDGE_POINTER(eptr);
      edir[1] = ON_SUBD_EDGE_DIRECTION(eptr);
      if (0 == i)
        continue;

      if (EdgesAreMergableTest(e, edir, true, distance_tolerance, maximum_aspect, sin_angle_tolerance))
      {
        if (ON_UNSET_UINT_INDEX == i0)
        {
          i0 = i;
        }
        if (i < edge_count)
          continue;
      }

      if (ON_UNSET_UINT_INDEX != i0)
      {
        const ON_SubDEdgePtr e0 = f->EdgePtr(i0 - 1);
        while(i0 < i)
        {
          if (e0.m_ptr != MergeEdges(e0, f->EdgePtr(i0)).m_ptr)
          {
            ON_ERROR("Bug in edge merging.");
            break;
          }
          removed_edge_count++;
          i--;
          edge_count--;
        }
        i0 = ON_UNSET_UINT_INDEX;
      }
    }
  }

  return removed_edge_count;
}

unsigned int ON_SubD::MergeColinearEdges(
  double distance_tolerance,
  double maximum_aspect,
  double sin_angle_tolerance
  )
{
  ON_SubDimple* subdimple = SubDimple(false);
  return (nullptr != subdimple) ? subdimple->MergeColinearEdges(distance_tolerance, maximum_aspect, sin_angle_tolerance) : 0;
}

ON_SubD::SubDType ON_SubD::ActiveLevelSubDType() const
{
  return ActiveLevel().m_subdivision_type;
}

unsigned int ON_SubD::LevelCount() const
{
  const ON_SubDimple* subdimple = SubDimple();
  return (0 != subdimple ? subdimple->LevelCount() : 0);
}


unsigned int ON_SubD::ActiveLevelIndex() const
{
  return ActiveLevel().m_level_index;
}

bool ON_SubD::IsEmpty() const
{
  return (nullptr == SubDimple());
}

bool ON_SubD::IsNotEmpty() const
{
  return (nullptr != SubDimple());
}

/////////////////////////////////////////////////////////
//
// Element (Vertex, Edge, Face) access
//
ON_COMPONENT_INDEX ON_SubDComponentPtr::ComponentIndex() const
{
  switch (ComponentType())
  {
  case ON_SubDComponentPtr::Type::Vertex:
    {
      const ON_SubDVertex* vertex = ON_SUBD_VERTEX_POINTER(m_ptr);
      if ( nullptr != vertex)
        return ON_COMPONENT_INDEX(ON_COMPONENT_INDEX::TYPE::subd_vertex,vertex->m_id);
    }
    break;
  case ON_SubDComponentPtr::Type::Edge:
    {
      const ON_SubDEdge* edge = ON_SUBD_EDGE_POINTER(m_ptr);
      if ( nullptr != edge)
        return ON_COMPONENT_INDEX(ON_COMPONENT_INDEX::TYPE::subd_edge,edge->m_id);
    }
    break;
  case ON_SubDComponentPtr::Type::Face:
    {
      const ON_SubDFace* face = ON_SUBD_FACE_POINTER(m_ptr);
      if ( nullptr != face)
        return ON_COMPONENT_INDEX(ON_COMPONENT_INDEX::TYPE::subd_face,face->m_id);
    }
    break;
  default:
    if (IsNull() )
      return ON_COMPONENT_INDEX::UnsetComponentIndex;
    break;
  }
  return ON_SUBD_RETURN_ERROR(ON_COMPONENT_INDEX::UnsetComponentIndex);
}

ON_SubDComponentPtr ON_SubD::ComponentPtrFromComponentIndex(
  ON_COMPONENT_INDEX component_index
  ) const
{
  if (0 != component_index.m_index && -1 != component_index.m_index)
  {
    switch (component_index.m_type)
    {
    case ON_COMPONENT_INDEX::TYPE::subd_vertex:
      return ON_SubDComponentPtr::Create(VertexFromId(component_index.m_index));
    case ON_COMPONENT_INDEX::TYPE::subd_edge:
      return ON_SubDComponentPtr::Create(EdgeFromId(component_index.m_index));
    case ON_COMPONENT_INDEX::TYPE::subd_face:
      return ON_SubDComponentPtr::Create(FaceFromId(component_index.m_index));
    default:
      break;
    }
  }
  else if (ON_COMPONENT_INDEX::TYPE::invalid_type == component_index.m_type)
  {
    return ON_SubDComponentPtr::Null;
  }

  return ON_SUBD_RETURN_ERROR(ON_SubDComponentPtr::Null);
}

/////////////////////////////////////////////////////////
//
// Vertex access
//

unsigned int ON_SubD::VertexCount() const
{
  return ActiveLevel().m_vertex_count;
}

const ON_SubDVertex* ON_SubD::FirstVertex() const
{
  return ActiveLevel().m_vertex[0];
}

ON_SubDVertexIterator ON_SubD::VertexIterator() const
{
  return ON_SubDVertexIterator(*this);
}

ON_SubDVertexIterator ON_SubDRef::VertexIterator() const
{
  return ON_SubDVertexIterator(*this);
}

ON_SubDVertexArray ON_SubD::VertexArray() const
{
  return ON_SubDVertexArray(*this);
}

const class ON_SubDVertex* ON_SubD::VertexFromId(
  unsigned int vertex_id
  ) const
{
  for (;;)
  {
    if (0 == vertex_id || ON_UNSET_UINT_INDEX == vertex_id )
      break;
    const ON_SubDimple* subdimple = SubDimple();
    if (nullptr == subdimple)
      break;
    return subdimple->VertexFromId(vertex_id);
  }
  return nullptr;
}

ON_COMPONENT_INDEX ON_SubDVertex::ComponentIndex() const
{
  return ON_COMPONENT_INDEX(ON_COMPONENT_INDEX::TYPE::subd_vertex,m_id);
}

ON_SubDComponentPtr ON_SubDVertex::ComponentPtr() const
{
  return ON_SubDComponentPtr::Create(this);
}

/////////////////////////////////////////////////////////
//
// Edge access
//

unsigned int ON_SubD::EdgeCount() const
{
  return ActiveLevel().m_edge_count;
}

const ON_SubDEdge* ON_SubD::FirstEdge() const
{
  return ActiveLevel().m_edge[0];
}

ON_SubDEdgeIterator ON_SubD::EdgeIterator() const
{
  return ON_SubDEdgeIterator(*this);
}

ON_SubDEdgeIterator ON_SubDRef::EdgeIterator() const
{
  return ON_SubDEdgeIterator(*this);
}

ON_SubDEdgeArray ON_SubD::EdgeArray() const
{
  return ON_SubDEdgeArray(*this);
}

const class ON_SubDEdge* ON_SubD::EdgeFromId(
  unsigned int edge_id
  ) const
{
  for (;;)
  {
    if (0 == edge_id || ON_UNSET_UINT_INDEX == edge_id )
      break;
    const ON_SubDimple* subdimple = SubDimple();
    if (nullptr == subdimple)
      break;
    return subdimple->EdgeFromId(edge_id);
  }
  return nullptr;
}

ON_COMPONENT_INDEX ON_SubDEdge::ComponentIndex() const
{
  return ON_COMPONENT_INDEX(ON_COMPONENT_INDEX::TYPE::subd_edge,m_id);
}

ON_SubDComponentPtr ON_SubDEdge::ComponentPtr() const
{
  return ON_SubDComponentPtr::Create(this);
}

/////////////////////////////////////////////////////////
//
// Face access
//

unsigned int ON_SubD::FaceCount() const
{
  return ActiveLevel().m_face_count;
}

const ON_SubDFace* ON_SubD::FirstFace() const
{
  return ActiveLevel().m_face[0];
}

ON_SubDFaceIterator ON_SubD::FaceIterator() const
{
  return ON_SubDFaceIterator(*this);
}

ON_SubDFaceIterator ON_SubDRef::FaceIterator() const
{
  return ON_SubDFaceIterator(*this);
}


ON_SubDFaceArray ON_SubD::FaceArray() const
{
  return ON_SubDFaceArray(*this);
}

const class ON_SubDFace* ON_SubD::FaceFromId(
  unsigned int face_id
  ) const
{
  for (;;)
  {
    if (0 == face_id || ON_UNSET_UINT_INDEX == face_id )
      break;
    const ON_SubDimple* subdimple = SubDimple();
    if (nullptr == subdimple)
      break;
    return subdimple->FaceFromId(face_id);
  }
  return nullptr;
}


ON_COMPONENT_INDEX ON_SubDFace::ComponentIndex() const
{
  return ON_COMPONENT_INDEX(ON_COMPONENT_INDEX::TYPE::subd_face,m_id);
}

ON_SubDComponentPtr ON_SubDFace::ComponentPtr() const
{
  return ON_SubDComponentPtr::Create(this);
}

/////////////////////////////////////////////////////////
//
// ON_SubD properties
//

bool ON_SubD::IsOriented(
  unsigned int level_index
  ) const
{
  for (const ON_SubDEdge* edge = FirstEdge(); nullptr != edge; edge = edge->m_next_edge)
  {
    if ( 2 != edge->m_face_count )
      continue;
    if (nullptr == ON_SUBD_FACE_POINTER(edge->m_face2[0].m_ptr) || nullptr == ON_SUBD_FACE_POINTER(edge->m_face2[1].m_ptr) )
      continue;
    if ( ON_SUBD_FACE_DIRECTION(edge->m_face2[0].m_ptr) == ON_SUBD_FACE_DIRECTION(edge->m_face2[1].m_ptr) )
      return false;
  }
  return true;
}

// reverses the orientation of all facets
bool ON_SubD::ReverseOrientation(
  unsigned int level_index
  ) const
{
  for (const ON_SubDFace* face = FirstFace(); nullptr != face; face = face->m_next_face)
    const_cast<ON_SubDFace*>(face)->ReverseEdgeList();
  return true;
}

// Attempts to orient all facet to match the first facet.

static unsigned int OrientFaceNeighbors(
  unsigned int recursion_level,
  const ON_SubDFace** face_list,
  unsigned int id0,
  const ON_SubDFace* face
  )
{
  ON_SubDFace* next_set[4];
  const unsigned int next_set_capacity = (unsigned int)(sizeof(next_set) / sizeof(next_set[0]));
  unsigned int next_set_count = 0;

  const unsigned int edge_count = face->m_edge_count;
  const ON_SubDEdgePtr* face_eptr = face->m_edge4;
  const ON_SubDEdge* e;
  ON_SubDFace* neighbor_face;

  if (nullptr != face_list[face->m_id - id0])
  {
    // search for an oriented neighbor
    neighbor_face = nullptr;
    for (unsigned int fei = 0; fei < edge_count; fei++, face_eptr++)
    {
      if (4 == fei)
      {
        face_eptr = face->m_edgex;
        if (nullptr == face_eptr)
          break;
      }
      e = ON_SUBD_EDGE_POINTER(face_eptr->m_ptr);
      if (nullptr == e || 2 != e->m_face_count)
        continue;
      neighbor_face = ON_SUBD_FACE_POINTER(e->m_face2[0].m_ptr);
      if (face == neighbor_face)
        neighbor_face = ON_SUBD_FACE_POINTER(e->m_face2[1].m_ptr);
      else if (face != ON_SUBD_FACE_POINTER(e->m_face2[1].m_ptr))
        continue;
      if (nullptr == neighbor_face)
        continue;

      if (nullptr == face_list[neighbor_face->m_id - id0])
        return OrientFaceNeighbors(recursion_level,face_list,id0,neighbor_face);
    }

    // nothing near face is oriented. 
    return 0;
  }

  unsigned int orient_count = 0;
  for (unsigned int fei = 0; fei < edge_count; fei++, face_eptr++)
  {
    if (4 == fei)
    {
      face_eptr = face->m_edgex;
      if ( nullptr == face_eptr)
        break;
    }
    e = ON_SUBD_EDGE_POINTER(face_eptr->m_ptr);
    if (nullptr == e || 2 != e->m_face_count)
      continue;
    neighbor_face = ON_SUBD_FACE_POINTER(e->m_face2[0].m_ptr);
    if (face == neighbor_face)
      neighbor_face = ON_SUBD_FACE_POINTER(e->m_face2[1].m_ptr);
    else if (face != ON_SUBD_FACE_POINTER(e->m_face2[1].m_ptr))
      continue;
    if (nullptr == neighbor_face)
      continue;

    if (nullptr == face_list[neighbor_face->m_id - id0])
      continue;

    if (ON_SUBD_FACE_DIRECTION(e->m_face2[0].m_ptr) == ON_SUBD_FACE_DIRECTION(e->m_face2[1].m_ptr))
      neighbor_face->ReverseEdgeList();
    face_list[neighbor_face->m_id - id0] = nullptr;
    orient_count++;

    if (recursion_level < 12)
    {
      if (next_set_count >= next_set_capacity)
      {
        for (unsigned i = 0; i < next_set_capacity; i++)
          orient_count += OrientFaceNeighbors(recursion_level + 1, face_list, id0, next_set[i]);
        next_set_count = 0;
      }
      next_set[next_set_count++] = neighbor_face;
    }
  }

  for ( unsigned i = 0; i < next_set_count; i++)
    orient_count += OrientFaceNeighbors(recursion_level+1,face_list,id0,next_set[i]);

  return orient_count;
}

bool ON_SubD::Orient(
  unsigned int level_index
  ) const
{
  const ON_SubDFace* first_face = FirstFace();
  if ( nullptr == first_face || nullptr == first_face->m_next_face)
    return true;

  unsigned int nonzero_face_count = 0;
  ON_SimpleArray< const ON_SubDFace* > faces_array(FaceCount());
  unsigned int face_id0 = first_face->m_id;
  unsigned int face_id1 = first_face->m_id;
  for (const ON_SubDFace* face = FirstFace(); nullptr != face; face = face->m_next_face)
  {
    faces_array.Append(face);
    if (face->m_id > face_id1)
      face_id1 = face->m_id;
    else if (face->m_id < face_id1)
      face_id0 = face->m_id;
    nonzero_face_count++;
  }

  const unsigned int face_count = faces_array.UnsignedCount();
  if (face_count <= 1)
    return true;

  const ON_SubDFace** faces = faces_array.Array();
  if (face_id1 - face_id0 > faces_array.UnsignedCount())
  {
    faces_array.Reserve(face_id1 - face_id0);
    faces_array.SetCount(face_id1 - face_id0);
    faces_array.Zero();
    for (const ON_SubDFace* face = FirstFace(); nullptr != face; face = face->m_next_face)
    {
      faces[face->m_id-face_id0] = face;
    }
  }

  unsigned int orient_count = 0;
  unsigned int connected_region_count = 0;
  bool bSearchForNewComponent = true;
  unsigned int first_face_index = 0;

  for (;;)
  {
    unsigned int orient_count0 = orient_count;
    while (first_face_index < face_count && nullptr == faces[first_face_index])
      first_face_index++;

    if ( first_face_index >= face_count)
      break;

    for (unsigned int i = first_face_index; i < face_count && orient_count < nonzero_face_count; i++)
    {
      const ON_SubDFace* face = faces[i];
      if (nullptr == face)
        continue;
      if (bSearchForNewComponent)
      {
        // first face in new connected component
        orient_count++;
        connected_region_count++;
        faces[i] = nullptr;
        bSearchForNewComponent = false;
        first_face_index = i+1;
      }
      orient_count += OrientFaceNeighbors(0, faces, face_id0, face);
    }
    
    if ( orient_count >= nonzero_face_count)
      break;

    if (orient_count0 >= orient_count)
    {
      if (bSearchForNewComponent)
        break;
      bSearchForNewComponent = true;
    }
  }

  return (connected_region_count > 0 && orient_count > 0);
}

const ON_SubDVertex* ON_SubD::TriangulateFace(
  ON_SubDFace* face
  )
{
  // TODO add  implementation
  return ON_SUBD_RETURN_ERROR(nullptr);
}

const ON_SubDFace* ON_SubD::MergeFaces(
  ON_SubDEdge* edge
  )
{
  // TODO add  implementation
  return ON_SUBD_RETURN_ERROR(nullptr);
}

const ON_SubDEdge* ON_SubDimple::SplitEdge(
  ON_SubDEdge* edge,
  ON_3dPoint vertex_location
  )
{
  if ( nullptr == edge )
    return ON_SUBD_RETURN_ERROR(nullptr);
  if (nullptr == edge->m_vertex[0] || nullptr == edge->m_vertex[1] )
    return ON_SUBD_RETURN_ERROR(nullptr);
  if (nullptr == edge->m_vertex[0]->m_edges || edge->m_vertex[0]->m_edge_count <= 0 || edge->m_vertex[0]->m_edge_capacity < edge->m_vertex[0]->m_edge_count )
    return ON_SUBD_RETURN_ERROR(nullptr);
  if (nullptr == edge->m_vertex[1]->m_edges || edge->m_vertex[1]->m_edge_count <= 0 || edge->m_vertex[1]->m_edge_capacity < edge->m_vertex[1]->m_edge_count )
    return ON_SUBD_RETURN_ERROR(nullptr);

  if (ON_3dPoint::UnsetPoint == vertex_location)
  {
    ON_Line L;
    L.from = ON_3dPoint(edge->m_vertex[0]->m_P);
    L.to = ON_3dPoint(edge->m_vertex[1]->m_P);
    vertex_location = L.PointAt(0.5);
  }
  if ( false == vertex_location.IsValid() )
    return ON_SUBD_RETURN_ERROR(nullptr);

  if ( vertex_location == ON_3dPoint(edge->m_vertex[0]->m_P) || vertex_location == ON_3dPoint(edge->m_vertex[1]->m_P) )
    return ON_SUBD_RETURN_ERROR(nullptr);

  ON_SubD::EdgeTag edge_tag = edge->m_edge_tag;
  ON_SubD::VertexTag vertex_tag;
  switch (edge->m_edge_tag)
  {
  case ON_SubD::EdgeTag::Smooth:
    vertex_tag = ON_SubD::VertexTag::Smooth;
    break;
  case ON_SubD::EdgeTag::Crease:
    vertex_tag = ON_SubD::VertexTag::Crease;
    break;
  case ON_SubD::EdgeTag::X:
    vertex_tag = ON_SubD::VertexTag::Smooth;
    edge_tag = ON_SubD::EdgeTag::Smooth;
    break;
  default:
    return ON_SUBD_RETURN_ERROR(nullptr);
    break;
  }

  ON_SubDVertex* end_vertex[2] = { const_cast<ON_SubDVertex*>(edge->m_vertex[0]), const_cast<ON_SubDVertex*>(edge->m_vertex[1]) };

  ON_SubDVertex* new_vertex = nullptr;
  ON_SubDEdge* new_edge = nullptr;  
  for (;;)
  {
    new_vertex = AllocateVertex(vertex_tag, edge->m_level, static_cast<const double*>(vertex_location), 2, edge->m_face_count);
    if (nullptr == new_vertex)
     break;

    new_edge = AllocateEdge(edge_tag, edge->m_level, edge->m_face_count);
    if (nullptr == new_edge)
      break;

    // change end_vertex[1] edge reference from edge to new_edge
    bool bConnectedNewEdgeToEndVertex = false;
    const ON_SubDEdgePtr old_edge_reference = ON_SubDEdgePtr::Create(edge,1);
    for (unsigned short vei = 0; vei < end_vertex[1]->m_edge_count; vei++)
    {
      if (old_edge_reference.m_ptr == end_vertex[1]->m_edges[vei].m_ptr)
      {
        // change end_vertex[1]->m_edges[vei] reference
        // from "edge" to "new_edge".
        bConnectedNewEdgeToEndVertex = true;
        end_vertex[1]->m_edges[vei] = ON_SubDEdgePtr::Create(new_edge,1);
        break;
      }
    }

    if (false == bConnectedNewEdgeToEndVertex)
    {
      // end_vertex[1]->m_edges[] does not reference edge
      break;
    }

    // finish setting new_vertex and end_vertex[] <-> new_edge connections
    new_edge->m_vertex[0] = new_vertex;
    new_edge->m_vertex[1] = end_vertex[1];
    new_vertex->m_edges[new_vertex->m_edge_count++] = ON_SubDEdgePtr::Create(new_edge,0);

    // finish setting new_vertex <-> input edge and connections
    edge->m_edge_tag = edge_tag; // changes "X" to "Smooth" if required
    edge->m_vertex[1] = new_vertex;
    new_vertex->m_edges[new_vertex->m_edge_count++] = ON_SubDEdgePtr::Create(edge,1);
       
    // add new_vertex and new_edge <-> edge->m_face[] connections.
    const ON_SubDFacePtr* fptr0 = edge->m_face2;
    ON_SubDFacePtr* fptr1 = new_edge->m_face2;
    for (unsigned short efi = 0; efi < edge->m_face_count; efi++)
    {
      if (2 == efi)
      {
        fptr0 = edge->m_facex;
        fptr1 = new_edge->m_facex;
      }

      ON_SubDFace* face = ON_SUBD_FACE_POINTER(fptr0->m_ptr);

      if (nullptr != face)
      {
        face->FaceModifiedNofification();

        // add new_vertex reference to face
        new_vertex->m_faces[new_vertex->m_face_count++] = face;

        // insert new_edge into face->m_edge[] list after "edge"
        if (GrowFaceEdgeArray(face, face->m_edge_count + 1))
        {
          if ( face->m_edge_count < 4 )
            face->m_edge4[face->m_edge_count] = ON_SubDEdgePtr::Null;
          else
            face->m_edgex[face->m_edge_count-4] = ON_SubDEdgePtr::Null;
          face->m_edge_count++;
          ON_SubDEdgePtr* face_edge = face->m_edge4;
          for (unsigned short fei = 0; fei < face->m_edge_count; fei++)
          {
            if (4 == fei)
              face_edge = face->m_edgex;
            if (edge == ON_SUBD_EDGE_POINTER(face_edge->m_ptr))
            {
              ON__UINT_PTR edir = ON_SUBD_EDGE_DIRECTION(face_edge->m_ptr);
              ON_SubDEdgePtr eptr = ON_SubDEdgePtr::Create(new_edge,edir);
              if (0 == edir)
              {
                fei++;
                face_edge++;
              }
              for (/*empty init*/; fei < face->m_edge_count; fei++)
              {
                if (4 == fei)
                  face_edge = face->m_edgex;
                const ON_SubDEdgePtr tmp = *face_edge;
                *face_edge = eptr;
                eptr = tmp;
                face_edge++;
              }
              break;
            }
            face_edge++;
          }
        }
      }

      *fptr1++ = *fptr0++;
      new_edge->m_face_count++;
    }

    // original ending vertex
    new_edge->m_sector_coefficient[1] = edge->m_sector_coefficient[1];

    // Either edge was a crease, new_edge is a crease, and sector weights do not applie
    // or edge was X or Smooth, edge is smooth, new_edge is smooth, new_vertex is smooth,
    // and the sector weights at this vertex do not apply.
    edge->m_sector_coefficient[1] = ON_SubDSectorType::IgnoredSectorWeight;
    new_edge->m_sector_coefficient[0] = ON_SubDSectorType::IgnoredSectorWeight;

    AddVertexToLevel(new_vertex);
    AddEdgeToLevel(new_edge);

    end_vertex[0]->VertexModifiedNofification();
    end_vertex[1]->VertexModifiedNofification();

    // TODO
    //   Delete any levels greater than this level.
    return new_edge;
  }

  if ( nullptr != new_vertex)
    ReturnVertex(new_vertex);
  if ( nullptr != new_edge)
    ReturnEdge(new_edge);
  return ON_SUBD_RETURN_ERROR(nullptr);
}

const ON_SubDEdge* ON_SubDimple::SplitFace(
  ON_SubDFace* face,
  unsigned int fvi0,
  unsigned int fvi1
  )
{
  if ( nullptr == face || face->m_edge_count < 4)
    return ON_SUBD_RETURN_ERROR(nullptr);

  if (face->m_level >= m_levels.UnsignedCount())
    return ON_SUBD_RETURN_ERROR(nullptr);
  ON_SubDLevel* level = m_levels[face->m_level];
  if ( nullptr == level)
    return ON_SUBD_RETURN_ERROR(nullptr);

  const unsigned int edge_count = face->m_edge_count;
  if ( edge_count < 4 || fvi0 == fvi1 || fvi0 >= edge_count || fvi1 >= edge_count || (edge_count > 4 && nullptr == face->m_edgex) )
    return ON_SUBD_RETURN_ERROR(nullptr);

  ON_SubDVertex* v[2] = { const_cast<ON_SubDVertex*>(face->Vertex(fvi0)), const_cast<ON_SubDVertex*>(face->Vertex(fvi1)) };

  if (nullptr == v[0] || v[0]->m_face_count <= 0 || nullptr == v[0]->m_faces || v[0]->m_edge_count < 2 || nullptr == v[0]->m_edges )
    return ON_SUBD_RETURN_ERROR(nullptr);

  if (nullptr == v[1] || v[1]->m_face_count <= 0 || nullptr == v[1]->m_faces || v[1]->m_edge_count < 2 || nullptr == v[1]->m_edges)
    return ON_SUBD_RETURN_ERROR(nullptr);

  if (v[0] == v[1])
    return ON_SUBD_RETURN_ERROR(nullptr);

  // make sure each side is at least a triangle
  const bool bReverseEdge = (fvi0 > fvi1);
  if ( bReverseEdge )
  {
    unsigned int i = fvi0;
    fvi0 = fvi1;
    fvi1 = i;
  }

  // edge_count0 = number of edges remaining on first face
  const unsigned int edge_count0 = (0 == fvi0) ? (fvi1+1) : (edge_count + 1 + fvi0 - fvi1);
  if ( edge_count0 < 3 || edge_count0 >= edge_count)
    return ON_SUBD_RETURN_ERROR(nullptr);

  // edge_count1 = number of edges on new face
  const unsigned int edge_count1 = edge_count + 2 - edge_count0;
  if ( edge_count1 < 3 || edge_count1 >= edge_count)
    return ON_SUBD_RETURN_ERROR(nullptr);


  // make sure face topology is valid
  ON_SubDEdgePtr* face_eptr = face->m_edge4;
  for (unsigned int fei = 0; fei < edge_count; fei++, face_eptr++)
  {
    if (4 == fei)
      face_eptr = face->m_edgex;
    const ON_SubDEdge* face_e = ON_SUBD_EDGE_POINTER(face_eptr->m_ptr);
    if (nullptr == face_e)
      return ON_SUBD_RETURN_ERROR(nullptr);
    if (ON_UNSET_UINT_INDEX == face_e->FaceArrayIndex(face) )
      return ON_SUBD_RETURN_ERROR(nullptr);
    const ON_SubDVertex* face_v = face_e->m_vertex[ON_SUBD_EDGE_DIRECTION(face_eptr->m_ptr)];
    if ( nullptr == face_v)
      return ON_SUBD_RETURN_ERROR(nullptr);
    if (ON_UNSET_UINT_INDEX == face_v->FaceArrayIndex(face) )
      return ON_SUBD_RETURN_ERROR(nullptr);
  }

  // create diagonal edge
  ON_SubD::EdgeTag etag = ON_SubD::EdgeTag::Unset;
  const bool bSmoothVertex[2] = {ON_SubD::VertexTag::Smooth == v[0]->m_vertex_tag,ON_SubD::VertexTag::Smooth == v[1]->m_vertex_tag};
  double sector_weight[2] = {
    bSmoothVertex[0] ? ON_SubDSectorType::IgnoredSectorWeight : ON_SubDSectorType::UnsetSectorWeight,
    bSmoothVertex[1] ? ON_SubDSectorType::IgnoredSectorWeight : ON_SubDSectorType::UnsetSectorWeight
  };

  if (bSmoothVertex[0] || bSmoothVertex[1])
    etag = ON_SubD::EdgeTag::Smooth;
  else
    etag = ON_SubD::EdgeTag::X;

  ON_SubDEdge* e = nullptr;
  ON_SubDFace* f = nullptr;
  for (;;)
  {
    f = AllocateFace();
    if (nullptr == f)
      break;
    f->m_level = face->m_level;
    AddFaceToLevel(f);

    if (edge_count1 > 4)
    {
      if ( false == m_heap.GrowFaceEdgeArray(f,edge_count1) )
        break;
    }

    if (false == m_heap.GrowVertexFaceArrayByOne(v[0]))
      break;
    if (false == m_heap.GrowVertexFaceArrayByOne(v[1]))
      break;

    e = AddEdge(etag, v[0], sector_weight[0], v[1], sector_weight[1]);
    if (nullptr == e)
      return ON_SUBD_RETURN_ERROR(nullptr);

    unsigned int fvi_limits[2];
    if (0 == fvi0)
    {
      fvi_limits[0] = fvi1;
      fvi_limits[1] = edge_count;
    }
    else
    {
      fvi_limits[0] = fvi0;
      fvi_limits[1] = fvi1;
    }

    face_eptr = (fvi_limits[0] < 4) ? (face->m_edge4 + fvi_limits[0]) : (face->m_edgex + (fvi_limits[0]-4));

    ON_SubDEdgePtr* face1_eptr = f->m_edge4;
    *face1_eptr++ = ON_SubDEdgePtr::Create(e,bReverseEdge?0:1);
    f->m_edge_count++;

    for (unsigned fvi = fvi_limits[0]; fvi < fvi_limits[1]; fvi++)
    {
      if ( 4 == fvi)
        face_eptr = face->m_edgex;

      if ( 4 == f->m_edge_count)
        face1_eptr = f->m_edgex;

      // topology validation above checked that face_e is not null
      ON_SubDEdge* face_e = ON_SUBD_EDGE_POINTER(face_eptr->m_ptr);
      ON__UINT_PTR face_edir = ON_SUBD_EDGE_DIRECTION(face_eptr->m_ptr);
      // topology validation above checked that face_edex is valid.
      unsigned int face_edex = face_e->FaceArrayIndex(face);

      // topology validation above checked that face_v is not null
      ON_SubDVertex* face_v = const_cast<ON_SubDVertex*>(face_e->m_vertex[face_edir]);

      if (v[0] != face_v && v[1] != face_v)
      {
        // topology validation above checked that face_vdex is valid.
        unsigned int face_vdex = face_v->FaceArrayIndex(face);

        // change face_v reference from "face" to "f"
        face_v->m_faces[face_vdex] = f;
      }

      // change face_e reference from "face" to "f"
      ON_SubDFacePtr* e_fptr = (face_edex < 2) ? (face_e->m_face2 + face_edex) : (face_e->m_facex + (face_edex-2));
      *e_fptr = ON_SubDFacePtr::Create(f,face_edir);

      // add edge to new face "f"
      *face1_eptr++ = ON_SubDEdgePtr::Create(face_e,face_edir);
      f->m_edge_count++;

      // remove edge from original face "face"
      *face_eptr++ = ON_SubDEdgePtr::Null;
    }

    if ( edge_count1 != f->m_edge_count )
      break;

    if (0 == fvi0)
    {
      face->m_edge_count = (unsigned short)(edge_count0-1);
      face_eptr = (face->m_edge_count < 4) ? (face->m_edge4 + face->m_edge_count) : (face->m_edgex + (face->m_edge_count-4));
      *face_eptr = ON_SubDEdgePtr::Create(e,bReverseEdge?1:0);
      face->m_edge_count++;
    }
    else
    {
      face->m_edge_count = (unsigned short)fvi0;
      face1_eptr = (face->m_edge_count < 4) ? (face->m_edge4 + face->m_edge_count) : (face->m_edgex + (face->m_edge_count-4));
      *face1_eptr++ = ON_SubDEdgePtr::Create(e,bReverseEdge?1:0);
      face->m_edge_count++;
      face_eptr = (fvi1 < 4) ? (face->m_edge4 + fvi1) : (face->m_edgex + (fvi1-4));
      for (unsigned int fvi = fvi1; fvi < edge_count; fvi++)
      {
        if (4 == fvi)
          face_eptr = face->m_edgex;
        if ( 4 == face->m_edge_count)
          face1_eptr = face->m_edgex;
        *face1_eptr++ = *face_eptr++;
        face->m_edge_count++;
      }
    }
    if ( edge_count0 != face->m_edge_count )
      break;

    face_eptr = (face->m_edge_count < 4) ? (face->m_edge4 + face->m_edge_count) : (face->m_edgex + (face->m_edge_count-4));
    for (unsigned int fvi = face->m_edge_count; fvi < edge_count; fvi++)
    {
      if ( 4 == fvi )
        face_eptr = face->m_edgex;
      *face_eptr++ = ON_SubDEdgePtr::Null;
    }

    e->m_face2[0] = ON_SubDFacePtr::Create(face,bReverseEdge?1:0);
    e->m_face2[1] = ON_SubDFacePtr::Create(f,bReverseEdge?0:1);
    e->m_face_count = 2;

    v[0]->m_faces[v[0]->m_face_count++] = f;
    //v[0]->m_vertex_edge_order = ON_SubD::VertexEdgeOrder::unset;
    v[1]->m_faces[v[1]->m_face_count++] = f;
    //v[1]->m_vertex_edge_order = ON_SubD::VertexEdgeOrder::unset;

    if (face->m_edge_count <= 4 && nullptr != face->m_edgex)
      m_heap.ReturnFaceExtraArray(face);

    if ( false == bSmoothVertex[0] || false == bSmoothVertex[1])
    {
      // update sector weights because they depend on the number of edges
      ON_SubD::SubDType subd_type = level->m_subdivision_type;
      if (ON_SubD::IsQuadOrTriSubDType(subd_type))
      {
        for (unsigned int vi = 0; vi < 2; vi++)
        {
          if ( bSmoothVertex[vi] )
            continue;
          ON_SubDSectorIterator sit;
          sit.Initialize(face, 0, v[vi]);
          sit.IncrementToCrease(-1);
          sit.InitializeToCurrentFace();
          if (v[vi]->IsCreaseOrCorner() || ON_SubD::VertexTag::Dart == v[vi]->m_vertex_tag)
          {
            const ON_SubDSectorType sector_type = ON_SubDSectorType::Create(subd_type, sit);
            sector_weight[vi] = sector_type.SectorWeight();
          }
          for (;;)
          {
            const ON_SubDEdge* edge = sit.CurrentEdge(0);
            if (nullptr == edge)
              break;
            unsigned int evi;
            if (v[vi] == edge->m_vertex[0])
              evi = 0;
            else if (v[vi] == edge->m_vertex[1])
              evi = 1;
            else
              evi = 2;
            if (evi < 2)
              const_cast<ON_SubDEdge*>(edge)->m_sector_coefficient[vi] = sector_weight[vi];
            if (nullptr == sit.CurrentFace() || sit.InitialFace() == sit.NextFace(ON_SubDSectorIterator::StopAt::AnyCrease))
              break;
          }
        }
      }
    }

    return e;
  }

  if ( nullptr != f  )
   ReturnFace(f);

  if (nullptr != e)
  {
    v[0]->m_edge_count--;
    v[1]->m_edge_count--;
    ReturnEdge(e);
  }

  return ON_SUBD_RETURN_ERROR(nullptr);
}



const ON_SubDEdge* ON_SubD::SplitEdge(
  ON_SubDEdge* edge,
  ON_3dPoint vertex_location
  )
{
  ON_SubDimple* subdimple = SubDimple(false);
  if ( nullptr == subdimple )
    return ON_SUBD_RETURN_ERROR(nullptr);
  return subdimple->SplitEdge(edge,vertex_location);
}


const ON_SubDEdge* ON_SubD::SplitFace(
  ON_SubDFace* face,
  unsigned int fvi0,
  unsigned int fvi1
  )
{
  ON_SubDimple* subdimple = SubDimple(false);
  if ( 0 == subdimple )
    return ON_SUBD_RETURN_ERROR(nullptr);
  return subdimple->SplitFace(face,fvi0,fvi1);
}

static unsigned int OppositeCornerIndex(
  const ON_SubDFace* face,
  unsigned int fvi0
  )
{
  if ( nullptr == face)
    return ON_SUBD_RETURN_ERROR(ON_UNSET_UINT_INDEX);

  const unsigned int edge_count = face->m_edge_count;

  if ( edge_count < 3 )
    return ON_SUBD_RETURN_ERROR(ON_UNSET_UINT_INDEX);
    
  if ( edge_count > 4 && nullptr == face->m_edgex )
    return ON_SUBD_RETURN_ERROR(ON_UNSET_UINT_INDEX);

  if ( 3 == face->m_edge_count )
    return ON_UNSET_UINT_INDEX; // not an error

  const ON_SubDVertex* face_v = face->Vertex(fvi0);
  if (nullptr == face_v)
    return ON_SUBD_RETURN_ERROR(ON_UNSET_UINT_INDEX);

  const ON_3dPoint P0(face_v->m_P);

  const ON_SubDVertex* best_v = nullptr;
  unsigned int best_fvi = ON_UNSET_UINT_INDEX;
  double best_d = 0.0;

  const unsigned int i0 = (fvi0 + 2) % edge_count;
  const unsigned int i1 = (fvi0 + edge_count - 1) % edge_count;
  const ON_SubDEdgePtr* eptr = i0 < 4 ? (face->m_edge4 + i0) : (face->m_edgex + (i0-4));
  for (unsigned int i = i0; i != i1; i = (i + 1) % edge_count, eptr++)
  {
    if ( i == 0 )
      eptr = face->m_edge4;
    else if ( i == 4 )
      eptr = face->m_edgex;
    const ON_SubDEdge* face_e = ON_SUBD_EDGE_POINTER(eptr->m_ptr);
    if ( nullptr == face_e )
      return ON_SUBD_RETURN_ERROR(ON_UNSET_UINT_INDEX);
    ON__UINT_PTR face_edir = ON_SUBD_EDGE_DIRECTION(eptr->m_ptr);
    face_v = face_e->m_vertex[face_edir];
    if ( nullptr == face_v )
      return ON_SUBD_RETURN_ERROR(ON_UNSET_UINT_INDEX);
    const ON_3dPoint P1(face_v->m_P);
    double d = P0.DistanceTo(P1);
    if (nullptr == best_v || (face_v->IsSmoothOrDart() && best_v->IsCreaseOrCorner()) )
    {
      best_v = face_v;
      best_d = d;
      best_fvi = i;
      continue;
    }   

    if (d > best_d && (face_v->IsSmoothOrDart() || best_v->IsCreaseOrCorner()))
    {
      best_v = face_v;
      best_d = d;
      best_fvi = i;
      continue;
    }
  }

  if ( best_fvi < edge_count )
    return best_fvi;

  return ON_SUBD_RETURN_ERROR(ON_UNSET_UINT_INDEX);
}



bool ON_SubD::RepairInvalidSectors(
  unsigned int level_index
  )
{
  bool rc = true;
  for (const ON_SubDVertex* vertex = FirstVertex(); nullptr != vertex; vertex = vertex->m_next_vertex)
  {
    if (vertex->IsSmoothOrDart()
      && 2 == vertex->m_edge_count && 2 == vertex->m_face_count
      && nullptr != vertex->m_edges && nullptr != vertex->m_faces
      )
    {
      const unsigned int fvi0[2] = {
        nullptr == vertex->m_faces[0] ? ON_UNSET_UINT_INDEX : vertex->m_faces[0]->VertexIndex(vertex),
        nullptr == vertex->m_faces[1] ? ON_UNSET_UINT_INDEX : vertex->m_faces[1]->VertexIndex(vertex)};
      const unsigned int fvi1[2] = {
        OppositeCornerIndex(vertex->m_faces[0],fvi0[0]),
        OppositeCornerIndex(vertex->m_faces[1],fvi0[1])
      };
      // split adjacent faces
      for (unsigned int pass = 0; pass < 2; pass++)
      {
        if ( 2 != vertex->m_edge_count || 2 != vertex->m_face_count)
          break;
        for (unsigned int vfi = 0; vfi < 2; vfi++)
        {
          if (ON_UNSET_UINT_INDEX == fvi0[vfi] || ON_UNSET_UINT_INDEX == fvi1[vfi])
            continue;
          const ON_SubDFace* face = vertex->m_faces[vfi];
          if (nullptr == face)
            continue;
          const ON_SubDVertex* face_v = face->Vertex(fvi1[vfi]);
          if (nullptr == face_v)
            continue;
          // first pass splits corner vertices.
          // If no corners are found during the first pass, then
          // second pass splits any neighbor quad.
          if (0 == pass && face_v->IsCreaseOrCorner())
            continue;
          SplitFace(const_cast<ON_SubDFace*>(face), fvi0[vfi], fvi1[vfi]);
        }
      }
      if (2 == vertex->m_edge_count && 2 == vertex->m_face_count)
      {
        TriangulateFace(const_cast<ON_SubDFace*>(vertex->m_faces[0]));
        TriangulateFace(const_cast<ON_SubDFace*>(vertex->m_faces[1]));
        if (2 == vertex->m_edge_count && 2 == vertex->m_face_count)
        {
          // cannot fix this vertex
          ON_SubDIncrementErrorCount();
          rc = false;
        }
      }
    }
  }

  return rc;
}

void ON_SubD::MarkAggregateComponentStatusAsNotCurrent() const
{
  const ON_SubDLevel* level = ActiveLevelConstPointer();
  if ( level )
    level->MarkAggregateComponentStatusAsNotCurrent();
}

unsigned int ON_SubDLevel::ClearStates(
  ON_ComponentStatus states_to_clear
  ) const
{
  unsigned int rc = 0;
  m_aggregates.m_aggregate_status.ClearAggregateStatus(states_to_clear);
  for (const ON_SubDVertex* vertex = m_vertex[0]; nullptr != vertex; vertex = vertex->m_next_vertex)
    rc += vertex->m_status.ClearStates(states_to_clear);
  for (const ON_SubDEdge* edge = m_edge[0]; nullptr != edge; edge = edge->m_next_edge)
    rc += edge->m_status.ClearStates(states_to_clear);
  for (const ON_SubDFace* face = m_face[0]; nullptr != face; face = face->m_next_face)
    rc += face->m_status.ClearStates(states_to_clear);
  return rc;
}

unsigned int ON_SubD::ClearComponentStates(
  ON_ComponentStatus states_to_clear
  ) const
{
  const ON_SubDLevel* level = ActiveLevelConstPointer();
  if ( level )
    return level->ClearStates(states_to_clear);
  return ON_SUBD_RETURN_ERROR(0);
}

ON_AggregateComponentStatus ON_SubD::AggregateComponentStatus() const
{  
  return ActiveLevel().AggregateComponentStatus();
}

unsigned int ON_SubDLevel::GetComponentsWithSetStates(
  ON_ComponentStatus states_filter,
  bool bAllEqualStates,
  ON_SimpleArray< ON_SubDComponentPtr >& components_with_set_states
  ) const
{
  components_with_set_states.SetCount(0);
  if (states_filter.IsClear())
    return 0;

  ON_AggregateComponentStatus acs = AggregateComponentStatus();

  ON_ComponentStatus as = acs.AggregateStatus();
  if (bAllEqualStates)
  {
    if ( false == as.AllEqualStates(states_filter, states_filter) )
      return 0;
  }
  else
  {
    if ( false == as.SomeEqualStates(states_filter, states_filter) )
      return 0;
  }

  unsigned int c = 0;
  if ( states_filter.IsSelected() && c < m_aggregates.m_aggregate_status.SelectedCount() )
    c = m_aggregates.m_aggregate_status.SelectedCount();
  if ( states_filter.IsHighlighted() && c < m_aggregates.m_aggregate_status.HighlightedCount() )
    c = m_aggregates.m_aggregate_status.HighlightedCount();
  if ( states_filter.IsHidden() && c < m_aggregates.m_aggregate_status.HiddenCount() )
    c = m_aggregates.m_aggregate_status.HiddenCount();
  if ( states_filter.IsLocked() && c < m_aggregates.m_aggregate_status.LockedCount() )
    c = m_aggregates.m_aggregate_status.LockedCount();
  if ( states_filter.IsDamaged() && c < m_aggregates.m_aggregate_status.DamagedCount() )
    c = m_aggregates.m_aggregate_status.DamagedCount();
  if ( states_filter.IsSelected() && c < m_aggregates.m_aggregate_status.SelectedCount() )
    c = m_aggregates.m_aggregate_status.SelectedCount();
  components_with_set_states.Reserve(c);

  if (bAllEqualStates)
  {
    for (const ON_SubDVertex* vertex = m_vertex[0]; nullptr != vertex; vertex = vertex->m_next_vertex)
    {
      if (vertex->m_status.AllEqualStates(states_filter, states_filter))
        components_with_set_states.Append(ON_SubDComponentPtr::Create(vertex));
    }
    for (const ON_SubDEdge* edge = m_edge[0]; nullptr != edge; edge = edge->m_next_edge)
    {
      if (edge->m_status.AllEqualStates(states_filter, states_filter))
        components_with_set_states.Append(ON_SubDComponentPtr::Create(edge));
    }
    for (const ON_SubDFace* face = m_face[0]; nullptr != face; face = face->m_next_face)
    {
      if (face->m_status.AllEqualStates(states_filter, states_filter))
        components_with_set_states.Append(ON_SubDComponentPtr::Create(face));
    }
  }
  else
  {
    for (const ON_SubDVertex* vertex = m_vertex[0]; nullptr != vertex; vertex = vertex->m_next_vertex)
    {
      if (vertex->m_status.SomeEqualStates(states_filter, states_filter))
        components_with_set_states.Append(ON_SubDComponentPtr::Create(vertex));
    }
    for (const ON_SubDEdge* edge = m_edge[0]; nullptr != edge; edge = edge->m_next_edge)
    {
      if (edge->m_status.SomeEqualStates(states_filter, states_filter))
        components_with_set_states.Append(ON_SubDComponentPtr::Create(edge));
    }
    for (const ON_SubDFace* face = m_face[0]; nullptr != face; face = face->m_next_face)
    {
      if (face->m_status.SomeEqualStates(states_filter, states_filter))
        components_with_set_states.Append(ON_SubDComponentPtr::Create(face));
    }
  }

  return components_with_set_states.UnsignedCount();
}


unsigned int ON_SubD::GetComponentsWithSetStates(
  ON_ComponentStatus states_filter,
  bool bAllEqualStates,
  ON_SimpleArray< ON_SubDComponentPtr >& components_with_set_states
  ) const
{
  return ActiveLevel().GetComponentsWithSetStates(
    states_filter,
    bAllEqualStates,
    components_with_set_states
    );
}


unsigned int ON_SubD::GetComponentsWithSetStates(
  ON_ComponentStatus states_filter,
  bool bAllEqualStates,
  ON_SimpleArray< ON_COMPONENT_INDEX >& components_with_set_states
  ) const
{
  components_with_set_states.SetCount(0);
  ON_SimpleArray< ON_SubDComponentPtr > cptr;
  GetComponentsWithSetStates(
    states_filter,
    bAllEqualStates,
    cptr
    );
  unsigned int count = cptr.UnsignedCount();
  if (count > 0)
  {
    components_with_set_states.Reserve(count);
    components_with_set_states.SetCount(count);
    const ON_SubDComponentPtr* cp = cptr.Array();
    ON_COMPONENT_INDEX* ci = components_with_set_states.Array();
    for ( const ON_SubDComponentPtr* cp1 = cp+count; cp < cp1; cp++ )
      *ci++ = cp->ComponentIndex();
  }
  return count;
}

unsigned int ON_SubDLevel::SetStates(
  ON_SubDComponentPtr component_ptr,
  ON_ComponentStatus states_to_set
  ) const
{
  if (0 != component_ptr.SetStates(states_to_set))
  {
    m_aggregates.m_aggregate_status.MarkAsNotCurrent();
    return 1;
  }
  return 0;
}

unsigned int ON_SubDLevel::ClearStates(
  ON_SubDComponentPtr component_ptr,
  ON_ComponentStatus states_to_clear
  ) const
{
  if (0 != component_ptr.ClearStates(states_to_clear))
  {
    m_aggregates.m_aggregate_status.MarkAsNotCurrent();
    return 1;
  }
  return 0;
}

unsigned int ON_SubDLevel::SetStatus(
  ON_SubDComponentPtr component_ptr,
  ON_ComponentStatus status_to_copy
  ) const
{
  if (0 != component_ptr.SetStatus(status_to_copy))
  {
    m_aggregates.m_aggregate_status.MarkAsNotCurrent();
    return 1;
  }
  return 0;
}

unsigned int ON_SubD::SetComponentStates(
  ON_COMPONENT_INDEX component_index,
  ON_ComponentStatus states_to_set
  ) const
{
  return SetComponentStates(ComponentPtrFromComponentIndex(component_index),states_to_set);
}

unsigned int ON_SubD::SetComponentStates(
  ON_SubDComponentPtr component_ptr,
  ON_ComponentStatus states_to_set
  ) const
{
  const ON_SubDLevel* level = ActiveLevelConstPointer();
  if ( nullptr != level )
    return level->SetStates(component_ptr,states_to_set);
  return ON_SUBD_RETURN_ERROR(0);
}

unsigned int ON_SubD::ClearComponentStates(
  ON_COMPONENT_INDEX component_index,
  ON_ComponentStatus states_to_clear
  ) const
{
  return ClearComponentStates(ComponentPtrFromComponentIndex(component_index),states_to_clear);
}

unsigned int ON_SubD::ClearComponentStates(
  ON_SubDComponentPtr component_ptr,
  ON_ComponentStatus states_to_clear
  ) const
{
  const ON_SubDLevel* level = ActiveLevelConstPointer();
  if ( nullptr != level )
    return level->ClearStates(component_ptr,states_to_clear);
  return ON_SUBD_RETURN_ERROR(0);
}

unsigned int ON_SubD::SetComponentStatus(
  ON_COMPONENT_INDEX component_index,
  ON_ComponentStatus status_to_copy
  ) const
{
  return ClearComponentStates(ComponentPtrFromComponentIndex(component_index),status_to_copy);
}

unsigned int ON_SubD::SetComponentStatus(
  ON_SubDComponentPtr component_ptr,
  ON_ComponentStatus status_to_copy
  ) const
{
  const ON_SubDLevel* level = ActiveLevelConstPointer();
  if ( nullptr != level )
    return level->SetStatus(component_ptr,status_to_copy);
  return ON_SUBD_RETURN_ERROR(0);
}

void ON_SubDLevel::ClearSubdivisonAndLimitPoints() const
{
  for (const ON_SubDVertex* vertex = m_vertex[0]; nullptr != vertex; vertex = vertex->m_next_vertex)
  {
    vertex->ClearSavedSubdivisionPoint();
    vertex->ClearSavedLimitPoints();
  }
  for (const ON_SubDEdge* edge = m_edge[0]; nullptr != edge; edge = edge->m_next_edge)
  {
    edge->ClearSavedSubdivisionPoint();
    // NO // Leave these set - they are not "cached" values // edge->UnsetSectorCoefficients();
  }
  for (const ON_SubDFace* face = m_face[0]; nullptr != face; face = face->m_next_face)
  {
    face->ClearSavedSubdivisionPoint();
  }
  m_aggregates.m_bDirtyBoundingBox = true;
}

unsigned int ON_SubD::ComponentPtrFromComponentIndex(
  const ON_COMPONENT_INDEX* ci_list,
  size_t ci_count,
  bool bIncludeVertices,
  bool bIncludeEdges,
  bool bIncludeFaces,
  ON_SimpleArray<ON_SubDComponentPtr>& cptr_list
) const
{
  if ( ci_count <= 0 )
    return 0;

  if (
    false == bIncludeVertices
    && false == bIncludeEdges
    && false == bIncludeFaces
    )
    return 0;

  if ( nullptr == ci_list )
    return ON_SUBD_RETURN_ERROR(0);

  const unsigned int count0 = cptr_list.UnsignedCount();

  cptr_list.Reserve(count0 + ci_count);

  const bool bFilter
    = false == bIncludeVertices
    || false == bIncludeEdges
    || false == bIncludeFaces;



  for (size_t i = 0; i < ci_count; i++)
  {
    const ON_COMPONENT_INDEX ci = ci_list[i];
    if (bFilter)
    {
      if (false == bIncludeVertices || ON_COMPONENT_INDEX::TYPE::subd_vertex == ci.m_type)
        continue;
      if (false == bIncludeEdges || ON_COMPONENT_INDEX::TYPE::subd_edge == ci.m_type)
        continue;
      if (false == bIncludeFaces || ON_COMPONENT_INDEX::TYPE::subd_face == ci.m_type)
        continue;
    }
    ON_SubDComponentPtr cptr = ComponentPtrFromComponentIndex(ci_list[i]);
    if (cptr.IsNull())
      continue;
    cptr_list.Append(cptr);
  }

  return (cptr_list.UnsignedCount() - count0);
}

unsigned int ON_SubD::ComponentPtrFromComponentIndex(
  const ON_COMPONENT_INDEX* ci_list,
  size_t ci_count,
  ON_SimpleArray<ON_SubDComponentPtr>& cptr_list
) const
{
  return ComponentPtrFromComponentIndex(ci_list, ci_count, true, true, true, cptr_list);
}



bool ON_SubD::DeleteComponents(
  const ON_COMPONENT_INDEX* ci_list,
  size_t ci_count
  )
{
  ON_SimpleArray<ON_SubDComponentPtr> cptr_list;
  if (ComponentPtrFromComponentIndex(ci_list,ci_count,cptr_list) <= 0)
    return true; // nothing to delete

  return DeleteComponents(cptr_list.Array(),cptr_list.UnsignedCount());
}

bool ON_SubD::DeleteComponents(
  const ON_SubDComponentPtr* cptr_list,
  size_t cptr_count
  )
{
  if ( cptr_count <= 0 )
    return true;

  if ( nullptr == cptr_list )
    return ON_SUBD_RETURN_ERROR(false);

  ON_SubDimple* subdimple = SubDimple(false);
  if ( nullptr == subdimple )
    return ON_SUBD_RETURN_ERROR(false);

  const unsigned int level_count = subdimple->LevelCount();
  if (level_count <= 0)
    return ON_SUBD_RETURN_ERROR(false);
  
  unsigned int level_index = level_count;
  for (size_t i = 0; i < cptr_count; i++)
  {
    const ON_SubDComponentBase* c = cptr_list[i].ComponentBase();
    if ( nullptr == c)
      continue;
    if ( c->m_level < level_index )
      level_index = c->m_level;
  }
  if ( level_index == level_count )
    return ON_SUBD_RETURN_ERROR(false);

  if ( false == subdimple->SetActiveLevel(level_index) )
    return ON_SUBD_RETURN_ERROR(false);

  subdimple->ClearHigherSubdivisionLevels(level_index);
  const ON_SubDLevel* level = subdimple->ActiveLevelPointer();
  if ( nullptr == level || level->m_level_index != level_index)
    return ON_SUBD_RETURN_ERROR(false);

  // Make sure no components have a status = ON_ComponentStatus::AllSet
  // because this uncommon status value is used to mark components that will be be deleted.
  ON_SubDComponentIterator cit(*this);
  for (ON_SubDComponentPtr cptr = cit.FirstComponent(); cptr.IsNotNull(); cptr = cit.NextComponent())
  {
    if ( ON_ComponentStatus::AllSet == cptr.Status() )
      cptr.ClearStates(ON_ComponentStatus::Damaged);
  }

  // Set the status of every compoent in cptr_list[] to ON_ComponentStatus::AllSet.
  // If that component is a vertex, set the status of every edge and face that
  // touch the vertex to ON_ComponentStatus::AllSet.
  // If that component is an edge, set the status of every face that
  // touches the edge to ON_ComponentStatus::AllSet.
  for (size_t i = 0; i < cptr_count; i++)
  {
    ON_SubDComponentPtr cptr = cptr_list[i];
    const ON_SubDComponentBase* c = cptr.ComponentBase();
    if (nullptr == c)
      continue;
    if (c->m_level != level_index)
      continue;
    c->m_status = ON_ComponentStatus::AllSet;
    switch (cptr.ComponentType())
    {
    case ON_SubDComponentPtr::Type::Vertex:
    {
      const ON_SubDVertex* vertex = cptr.Vertex();
      if (nullptr == vertex)
        continue;
      for (unsigned short vei = 0; vei < vertex->m_edge_count; vei++)
      {
        const ON_SubDEdge* edge = vertex->Edge(vei);
        if (nullptr == edge)
          continue;
        edge->m_status = ON_ComponentStatus::AllSet;
      }
      for (unsigned short vfi = 0; vfi < vertex->m_face_count; vfi++)
      {
        const ON_SubDFace* face = vertex->Face(vfi);
        if (nullptr == face)
          continue;
        face->m_status = ON_ComponentStatus::AllSet;
      }
    }
    break;
    case ON_SubDComponentPtr::Type::Edge:
    {
      const ON_SubDEdge* edge = cptr.Edge();
      if (nullptr == edge)
        continue;
      for (unsigned short efi = 0; efi < edge->m_face_count; efi++)
      {
        const ON_SubDFace* face = edge->Face(efi);
        if (nullptr == face)
          continue;
        face->m_status = ON_ComponentStatus::AllSet;
      }
    }
    break;
    }
  }

  // Minimum count of what will be deleted. (
  unsigned int deleted_vertex_count = 0;
  unsigned int deleted_edge_count = 0;
  unsigned int deleted_face_count = 0;
  for (ON_SubDComponentPtr cptr = cit.FirstComponent(); cptr.IsNotNull(); cptr = cit.NextComponent())
  {
    if (ON_ComponentStatus::AllSet == cptr.Status())
    {
      switch (cptr.ComponentType())
      {
      case ON_SubDComponentPtr::Type::Vertex:
        deleted_vertex_count++;
        break;

      case ON_SubDComponentPtr::Type::Edge:
        deleted_edge_count++;
        break;

      case ON_SubDComponentPtr::Type::Face:
        deleted_face_count++;
        break;
      }
      continue;
    }
  }

  if ( 0 == deleted_vertex_count && 0 == deleted_edge_count && 0 ==  deleted_face_count )
    return false;

  if (deleted_vertex_count >= level->m_vertex_count || deleted_edge_count >= level->m_edge_count || deleted_face_count >= level->m_face_count)
  {
    Destroy();
    return true;
  }

  unsigned int deleted_component_count = subdimple->DeleteComponents(level_index);

  if (0 == subdimple->LevelCount())
  {
    Destroy();
    return true;
  }

  if (deleted_component_count > 0 || level_index > 0)
  {
    // remove lower levels
    subdimple->ClearLowerSubdivisionLevels(level_index);
  }

  return (deleted_component_count > 0);
}

unsigned int ON_SubDLevel::UpdateEdgeTags(
  bool bUnsetEdgeTagsOnly
  )
{
  // Update edge flags and sector weights.
  unsigned int edge_change_count = 0;
  ON_SubDEdge* next_edge = m_edge[0];
  for (ON_SubDEdge* edge = next_edge; nullptr != edge; edge = next_edge)
  {
    next_edge = const_cast<ON_SubDEdge*>(edge->m_next_edge);

    const ON_SubD::EdgeTag edge_tag0 = edge->m_edge_tag;
    if (bUnsetEdgeTagsOnly && ON_SubD::EdgeTag::Unset != edge_tag0 )
    {
      continue;
    }

    if (nullptr == edge->m_vertex[0] || nullptr == edge->m_vertex[1])
    {
      ON_SUBD_ERROR("nullptr edge->m_vertex[] values");
      continue;
    }

    const double edge_sector_coefficient0[2] = { edge->m_sector_coefficient[0], edge->m_sector_coefficient[1] };

    if (2 != edge->m_face_count)
    {
      edge->m_edge_tag = ON_SubD::EdgeTag::Crease;
      edge->m_sector_coefficient[0] = ON_SubDSectorType::IgnoredSectorWeight;
      edge->m_sector_coefficient[1] = ON_SubDSectorType::IgnoredSectorWeight;
    }
    else
    {
      edge->m_sector_coefficient[0] = ON_SubDSectorType::UnsetSectorWeight;
      edge->m_sector_coefficient[1] = ON_SubDSectorType::UnsetSectorWeight;
      const bool bBothVertexTagsAreSet
        =  ON_SubD::VertexTag::Unset != edge->m_vertex[0]->m_vertex_tag
        && ON_SubD::VertexTag::Unset != edge->m_vertex[1]->m_vertex_tag
        ;
      const unsigned int tagged_end_index = edge->TaggedEndIndex();
      if (0 == tagged_end_index || 1 == tagged_end_index)
        edge->m_sector_coefficient[tagged_end_index] = ON_SubDSectorType::IgnoredSectorWeight;

      switch (edge_tag0)
      {
      case ON_SubD::EdgeTag::Unset:
        if (2 == tagged_end_index)
        {
          edge->m_edge_tag = ON_SubD::EdgeTag::X;
        }
        else if ( bBothVertexTagsAreSet )
        {
          edge->m_edge_tag = ON_SubD::EdgeTag::Smooth;
          if (3 == tagged_end_index)
          {
            edge->m_sector_coefficient[0] = ON_SubDSectorType::IgnoredSectorWeight;
            edge->m_sector_coefficient[1] = ON_SubDSectorType::IgnoredSectorWeight;
          }
        }
        break;

      case ON_SubD::EdgeTag::Smooth:
        if (2 == tagged_end_index)
        {
          edge->m_edge_tag = ON_SubD::EdgeTag::X;
        }
        else if (3 == tagged_end_index && bBothVertexTagsAreSet)
        {
          edge->m_sector_coefficient[0] = ON_SubDSectorType::IgnoredSectorWeight;
          edge->m_sector_coefficient[1] = ON_SubDSectorType::IgnoredSectorWeight;
        }
        break;

      case ON_SubD::EdgeTag::Crease:
        edge->m_sector_coefficient[0] = ON_SubDSectorType::IgnoredSectorWeight;
        edge->m_sector_coefficient[1] = ON_SubDSectorType::IgnoredSectorWeight;
        break;

      case ON_SubD::EdgeTag::Sharp:
        ON_SUBD_ERROR("ON_SubD::EdgeTag::Sharp not handled.");
        break;

      case ON_SubD::EdgeTag::X:
        if ( 2 != tagged_end_index && bBothVertexTagsAreSet)
          edge->m_edge_tag = ON_SubD::EdgeTag::Smooth;
        break;

      default:
        break;
      }
    }

    if (!(edge_tag0 == edge->m_edge_tag
      && edge_sector_coefficient0[0] == edge->m_sector_coefficient[0]
      && edge_sector_coefficient0[1] == edge->m_sector_coefficient[1]))
      edge_change_count++;
  }

  return edge_change_count;
}


unsigned int ON_SubDLevel::UpdateVertexTags(
  bool bUnsetVertexTagsOnly
  )
{
  // Update edge flags and sector weights.
  unsigned int vertex_change_count = 0;
 

  ON_SubDVertex* next_vertex = m_vertex[0];
  for (ON_SubDVertex* vertex = next_vertex; nullptr != vertex; vertex = next_vertex)
  {
    next_vertex = const_cast<ON_SubDVertex*>(vertex->m_next_vertex);

    const ON_SubD::VertexTag vertex_tag0 = vertex->m_vertex_tag;
    if (bUnsetVertexTagsOnly && ON_SubD::VertexTag::Unset != vertex_tag0 )
    {
      continue;
    }

    const unsigned int edge_count = vertex->m_edge_count;
    unsigned int creased_edge_count = 0;
    unsigned int sharp_edge_count = 0;
    for (unsigned int vei = 0; vei < edge_count; vei++)
    {
      const ON_SubDEdge* edge = ON_SUBD_EDGE_POINTER(vertex->m_edges[vei].m_ptr);
      if (nullptr == edge)
      {
        ON_SUBD_ERROR("nullptr vertex->m_edges[] values");
        continue;
      }
      if (ON_SubD::EdgeTag::Sharp == edge->m_edge_tag)
      {
        ON_SUBD_ERROR("ON_SubD::EdgeTag::Sharp is not supported yet.");
        continue;
      }
      if ( ON_SubD::EdgeTag::Crease == edge->m_edge_tag
        || 2 != edge->m_face_count 
        )
        creased_edge_count++;
      else if ( ON_SubD::EdgeTag::Sharp == edge->m_edge_tag )
        sharp_edge_count++;

      // NOTE: 
      //  edges tagged as ON_SubD::EdgeTag::Unset with two faces
      //  ending at a vertex with 3 or more edges
      //  will eventually be tagged as smooth once this vertex
      //  is tagged as smooth.
    }


    ON_SubD::VertexTag vertex_tag1 = vertex_tag0;
    if (edge_count <= 2 || (creased_edge_count+sharp_edge_count) >= 2)
    {
      if ( ON_SubD::VertexTag::Corner != vertex_tag0 )
        vertex_tag1 = ON_SubD::VertexTag::Crease;
    }
    else
    {
      if ( 1 == creased_edge_count && 0 == sharp_edge_count )
        vertex_tag1 = ON_SubD::VertexTag::Dart;
      else
        vertex_tag1 = ON_SubD::VertexTag::Smooth;
    }

    if (vertex_tag0 != vertex_tag1)
    {
      vertex->m_vertex_tag = vertex_tag1;
      vertex_change_count++;
    }
  }

  return vertex_change_count;
}


unsigned int ON_SubDLevel::UpdateAllTagsAndSectorCoefficients(
  bool bUnsetValuesOnly
)
{
  unsigned int change_count = 0;

  bool bUpdateEdges = true;
  bool bUpdateVertices = true;
  for ( unsigned int it_count = 0; it_count < 8; it_count++)
  {
    const unsigned int edge_change_count 
      = bUpdateEdges
      ? UpdateEdgeTags(bUnsetValuesOnly)
      : 0;
    bUpdateVertices = (edge_change_count > 0 || 0 == it_count);
    change_count += edge_change_count;

    const unsigned int vertex_change_count 
      = bUpdateVertices
      ? UpdateVertexTags(bUnsetValuesOnly)
      : 0;
    bUpdateEdges = (vertex_change_count > 0);    
    change_count += vertex_change_count;

    bUpdateVertices = false;
    if ( false == bUpdateEdges)
      break;
  }

  if (bUpdateVertices && bUpdateEdges)
  {
    ON_SUBD_ERROR("Recursion limit exceeded.");
  }

  change_count += UpdateEdgeSectorCoefficients(false);

  if ( change_count > 0 )
    m_limit_mesh = ON_SubDLimitMesh::Empty;
    

  return change_count;
}



unsigned int ON_SubD::UpdateVertexTags(
    bool bUnsetVertexTagsOnly
    )
{
  ON_SubDLevel* level = ActiveLevelPointer();
  if ( nullptr == level )
    return ON_SUBD_RETURN_ERROR(0);

  return level->UpdateVertexTags(bUnsetVertexTagsOnly);
}

unsigned int ON_SubD::UpdateEdgeTags(
  bool bUnsetEdgeTagsOnly
  )
{
  ON_SubDLevel* level = ActiveLevelPointer();
  if ( nullptr == level )
    return ON_SUBD_RETURN_ERROR(0);

  return level->UpdateEdgeTags(bUnsetEdgeTagsOnly);
}


unsigned int ON_SubD::UpdateEdgeSectorCoefficients(
    bool bUnsetSectorCoefficientsOnly
    )
{
  ON_SubDLevel* level = ActiveLevelPointer();
  if ( nullptr == level )
    return ON_SUBD_RETURN_ERROR(0);

  return level->UpdateEdgeSectorCoefficients(bUnsetSectorCoefficientsOnly);
}

void ON_SubD::SubDModifiedNofification()
{
  ClearLimitSurfaceMesh();
  UpdateAllTagsAndSectorCoefficients(false);
}

unsigned int ON_SubD::UpdateAllTagsAndSectorCoefficients(
  bool bUnsetValuesOnly
)
{
  ON_SubDLevel* level = ActiveLevelPointer();
  if ( nullptr == level )
    return ON_SUBD_RETURN_ERROR(0);

  return level->UpdateAllTagsAndSectorCoefficients(bUnsetValuesOnly);
}

unsigned int ON_SubDimple::DeleteComponents(
  unsigned int level_index
  )
{
  unsigned int deleted_component_count = 0;

  if (level_index >= m_levels.UnsignedCount())
    return ON_SUBD_RETURN_ERROR(0);

  ON_SubDLevel* level = m_levels[level_index];
  if (nullptr == level)
    return ON_SUBD_RETURN_ERROR(0);

  ON_SubDFace* next_face = level->m_face[0];
  for (ON_SubDFace* face = next_face; nullptr != face; face = next_face)
  {
    next_face = const_cast< ON_SubDFace* >(face->m_next_face);
    bool bDelete = (ON_ComponentStatus::AllSet == face->m_status || 0 == face->m_edge_count);
    if (false == bDelete)
    {
      for (unsigned short fei = 0; fei < face->m_edge_count && false == bDelete; fei++)
      {
        const ON_SubDEdge* edge = face->Edge(fei);
        if (nullptr == edge
          || nullptr == edge->m_vertex[0]
          || nullptr == edge->m_vertex[1]
          || ON_ComponentStatus::AllSet == edge->m_status
          || ON_ComponentStatus::AllSet == edge->m_vertex[0]->m_status
          || ON_ComponentStatus::AllSet == edge->m_vertex[1]->m_status
          )
        {
          bDelete = true;
          if (nullptr != edge && ON_ComponentStatus::AllSet != edge->m_status)
            edge->m_status = ON_ComponentStatus::AllSet;
        }
      }
      if (false == bDelete)
        continue;
    }
    level->RemoveFace(face);
    m_heap.ReturnFace(face);
    deleted_component_count++;
  }

  ON_SubDEdge* next_edge = level->m_edge[0];
  for (ON_SubDEdge* edge = next_edge; nullptr != edge; edge = next_edge)
  {
    next_edge = const_cast< ON_SubDEdge* >(edge->m_next_edge);
    bool bDelete = (ON_ComponentStatus::AllSet == edge->m_status || 0 == edge->m_face_count );
    if (false == bDelete)
    {
      for (unsigned short evi = 0; evi < 2 && false == bDelete; evi++)
      {
        if (nullptr == edge->m_vertex[0]
          || nullptr == edge->m_vertex[1]
          || ON_ComponentStatus::AllSet == edge->m_vertex[0]->m_status
          || ON_ComponentStatus::AllSet == edge->m_vertex[1]->m_status
          )
          bDelete = true;
      }
      if (false == bDelete)
        continue;
    }

    level->RemoveEdge(edge);
    m_heap.ReturnEdge(edge);
    deleted_component_count++;
  }

  ON_SubDVertex* next_vertex = level->m_vertex[0];
  for (ON_SubDVertex* vertex = next_vertex; nullptr != vertex; vertex = next_vertex)
  {
    next_vertex = const_cast<ON_SubDVertex*>(vertex->m_next_vertex);
    bool bDelete = (ON_ComponentStatus::AllSet == vertex->m_status || 0 == vertex->m_face_count || 0 == vertex->m_edge_count );
    if ( false == bDelete )
      continue;

    level->RemoveVertex(vertex);
    m_heap.ReturnVertex(vertex);
    deleted_component_count++;
  }

  if ( 0 == deleted_component_count )
    return 0;

  // Remove edge references to deleted faces
  next_edge = level->m_edge[0];
  for (ON_SubDEdge* edge = next_edge; nullptr != edge; edge = next_edge)
  {
    next_edge = const_cast<ON_SubDEdge*>(edge->m_next_edge);
    ON_SubDFacePtr* fptr0 = edge->m_face2;
    ON_SubDFacePtr* fptr1 = edge->m_face2;
    const unsigned short edge_face_count = edge->m_face_count;
    edge->m_face_count = 0;
    for (unsigned short efi = 0; efi < edge_face_count; efi++, fptr0++)
    {
      if (2 == efi)
        fptr0 = edge->m_face2;
      const ON_SubDFace* face = fptr0->Face();
      if (nullptr == face || ON_UNSET_UINT_INDEX == face->ArchiveId())
        continue;
      *fptr1++ = *fptr0;
      edge->m_face_count++;
      if (2 == edge->m_face_count)
        fptr1 = edge->m_facex;
    }

    if (0 == edge->m_face_count)
    {
      level->RemoveEdge(edge);
      m_heap.ReturnEdge(edge);
      deleted_component_count++;
      continue;
    }
    
    if (edge->m_face_count <= 2 && nullptr != edge->m_facex)
      m_heap.ReturnEdgeExtraArray(edge);

    if ( edge->m_face_count != 2 )
      edge->m_edge_tag = ON_SubD::EdgeTag::Crease;

    edge->m_sector_coefficient[0] = ON_SubDSectorType::UnsetSectorWeight;
    edge->m_sector_coefficient[1] = ON_SubDSectorType::UnsetSectorWeight;
  }

  // Remove vertex references to deleted edges and faces
  next_vertex = level->m_vertex[0];
  for (ON_SubDVertex* vertex = next_vertex; nullptr != vertex; vertex = next_vertex)
  {
    next_vertex = const_cast<ON_SubDVertex*>(vertex->m_next_vertex);

    unsigned int count = vertex->m_edge_count;
    vertex->m_edge_count = 0;

    bool bInteriorVertex = true;
    unsigned int crease_count = 0;
    for (unsigned short vei = 0; vei < count; vei++)
    {
      const ON_SubDEdge* edge = vertex->m_edges[vei].Edge();
      if (nullptr == edge || ON_UNSET_UINT_INDEX == edge->ArchiveId())
      {
        bInteriorVertex = false;
        continue;
      }
      if (edge->IsCrease())
        crease_count++;
      if (2 != edge->m_face_count)
        bInteriorVertex = false;
      vertex->m_edges[vertex->m_edge_count++] = vertex->m_edges[vei];
    }

    if ( crease_count > 2 )
      vertex->m_vertex_tag = ON_SubD::VertexTag::Corner;
    else if (false == bInteriorVertex || crease_count > 1)
    {
      if (false == vertex->IsCreaseOrCorner())
        vertex->m_vertex_tag = ON_SubD::VertexTag::Crease;
    }

    count = vertex->m_face_count;
    vertex->m_face_count = 0;
    for (unsigned short vfi = 0; vfi < count; vfi++)
    {
      const ON_SubDFace* face = vertex->m_faces[vfi];
      if (nullptr == face || ON_UNSET_UINT_INDEX == face->ArchiveId()) 
        continue;
      vertex->m_faces[vertex->m_face_count++] = vertex->m_faces[vfi];
    }

    if (0 == vertex->m_face_count && 0 == vertex->m_edge_count )
    {
      level->RemoveVertex(vertex);
      m_heap.ReturnVertex(vertex);
      deleted_component_count++;
    }
  }

  if (0 == level->m_edge_count || 0 == level->m_edge_count || 0 == level->m_face_count)
  {
    Destroy();
  }
  else
  {
    // remove all information that is no longer valid
    level->m_limit_mesh.Clear();
    level->MarkAggregateComponentStatusAsNotCurrent();
    level->ClearSubdivisonAndLimitPoints();
    level->ClearBoundingBox();
    level->ClearEdgeFlags();

    ClearHigherSubdivisionLevels(level_index);

    // Update vertex tags, edge tags, and sector weights.
    level->UpdateAllTagsAndSectorCoefficients(false);
  }

  return deleted_component_count;
}


/*
Descripiton:
  Clears the ON_ComponentState
*/
unsigned int ON_SubD::ClearComponentMarks(
  bool bClearVertexMarks,
  bool bClearEdgeMarks,
  bool bClearFaceMarks,
  ON_SimpleArray< const ON_SubDComponentBase* >* marked_component_list
) const
{
  unsigned int clear_count = 0;

  if (bClearVertexMarks)
  {
    ON_SubDVertexIterator vit(*this);
    for (const ON_SubDVertex* v = vit.FirstVertex(); nullptr != v; v = vit.NextVertex())
    {
      if (v->m_status.ClearRuntimeMark())
      {
        if (nullptr != marked_component_list)
          marked_component_list->Append(v);
        clear_count++;
      }
    }
  }

  if (bClearEdgeMarks)
  {
    ON_SubDEdgeIterator eit(*this);
    for (const ON_SubDEdge* e = eit.FirstEdge(); nullptr != e; e = eit.NextEdge())
    {
      if (e->m_status.ClearRuntimeMark())
      {
        if (nullptr != marked_component_list)
          marked_component_list->Append(e);
        clear_count++;
      }
    }
  }

  if (bClearFaceMarks)
  {
    ON_SubDFaceIterator fit(*this);
    for (const ON_SubDFace* f = fit.FirstFace(); nullptr != f; f = fit.NextFace())
    {
      if (f->m_status.ClearRuntimeMark())
      {
        if (nullptr != marked_component_list)
          marked_component_list->Append(f);
        clear_count++;
      }
    }
  }

  return clear_count;
}

unsigned int ON_SubD::SetComponentMarks(
  bool bClearBeforeSet,
  const ON_SimpleArray< const ON_SubDComponentBase* >& marked_component_list
) const
{
  unsigned int set_count = 0;

  if (bClearBeforeSet)
    ClearComponentMarks(true, true, true, nullptr);

  const unsigned count = marked_component_list.Count();
  if (count <= 0)
    return 0;
  const ON_SubDComponentBase*const* a = marked_component_list.Array();
  if (nullptr == a)
    return 0;

  for (const ON_SubDComponentBase*const* a1 = a; a < a1; a++)
  {
    const ON_SubDComponentBase* c = *a;
    if (nullptr == c)
      continue;
    if (c->m_status.SetRuntimeMark())
      set_count++;
  }

  return set_count;
}



unsigned int ON_SubD::GetMarkedComponents(
    bool bIncludeVertices,
    bool bIncludeEdges,
    bool bIncludeFaces,
  ON_SimpleArray< const ON_SubDComponentBase* >& marked_component_list
) const
{
  unsigned int mark_count = 0;

  if (bIncludeVertices)
  {
    ON_SubDVertexIterator vit(*this);
    for (const ON_SubDVertex* v = vit.FirstVertex(); nullptr != v; v = vit.NextVertex())
    {
      if (v->m_status.RuntimeMark())
      {
        if (nullptr != marked_component_list)
          marked_component_list.Append(v);
        mark_count++;
      }
    }
  }

  if (bIncludeEdges)
  {
    ON_SubDEdgeIterator eit(*this);
    for (const ON_SubDEdge* e = eit.FirstEdge(); nullptr != e; e = eit.NextEdge())
    {
      if (e->m_status.RuntimeMark())
      {
        if (nullptr != marked_component_list)
          marked_component_list.Append(e);
        mark_count++;
      }
    }
  }

  if (bIncludeFaces)
  {
    ON_SubDFaceIterator fit(*this);
    for (const ON_SubDFace* f = fit.FirstFace(); nullptr != f; f = fit.NextFace())
    {
      if (f->m_status.RuntimeMark())
      {
        if (nullptr != marked_component_list)
          marked_component_list.Append(f);
        mark_count++;
      }
    }
  }

  return mark_count;
}

ON_SubDComponentMarksClearAndRestore::ON_SubDComponentMarksClearAndRestore(
  ON_SubD& subd
)  
{
  m_subd.ShareContentsFrom(subd);
  m_subd.ClearComponentMarks(true, true, true, &m_saved_marked_component_list);
}

ON_SubDComponentMarksClearAndRestore::~ON_SubDComponentMarksClearAndRestore()
{
  Restore(true);
}

const ON_SimpleArray<const class ON_SubDComponentBase*>& ON_SubDComponentMarksClearAndRestore::SavedMarkedComponentList() const
{
  return m_saved_marked_component_list;
}

bool ON_SubDComponentMarksClearAndRestore::Restore(
  bool bDisableFutureRestore )
{
  const bool rc = m_bRestore;
  if (rc)
  {
    if ( bDisableFutureRestore)
      m_bRestore = false;
    if (m_saved_marked_component_list.UnsignedCount() > 0)
      m_subd.SetComponentMarks(true, m_saved_marked_component_list);
    else
      m_subd.ClearComponentMarks(true, true, true, nullptr);
    m_saved_marked_component_list.Destroy();
  }
  return rc;
}

void ON_SubDComponentMarksClearAndRestore::DisableRestore()
{
  m_bRestore = false;
}

unsigned int ON_SubD::TransformComponents(
  const ON_Xform& xform,
  const ON_COMPONENT_INDEX* ci_list,
  size_t ci_count
)
{
  if (
    false ==  xform.IsValidAndNotZeroAndNotIdentity()
    || ci_count <= 0
    || nullptr == ci_list
    )
    return 0;

  ON_SimpleArray<ON_SubDComponentPtr> cptr_list;
  if (ComponentPtrFromComponentIndex(ci_list,ci_count,cptr_list) <= 0)
    return true; // nothing to delete

  return TransformComponents(xform,cptr_list.Array(),cptr_list.UnsignedCount());
}


static unsigned int Internal_MarkVertices(
  const ON_SubD& subd,
  const ON_SubDComponentPtr* cptr_list,
  size_t cptr_count,
  const ON_Xform& xform
)
{
  unsigned int v_mark_count = 0;

  const bool bTransform = xform.IsValidAndNotZeroAndNotIdentity();

  for (size_t i = 0; i < cptr_count; i++)
  {
    switch (cptr_list[i].ComponentType())
    {
    case ON_SubDComponentPtr::Type::Vertex:
      {
        const ON_SubDVertex* v = cptr_list[i].Vertex();
        if (nullptr != v && false == v->m_status.RuntimeMark())
        {
          v->m_status.SetRuntimeMark();
          if ( bTransform)
            const_cast<ON_SubDVertex*>(v)->Transform(false, xform);
          v_mark_count++;
        }
      }
      break;

    case ON_SubDComponentPtr::Type::Edge:
      {
        const ON_SubDEdge* e = cptr_list[i].Edge();
        if (nullptr != e)
        {
          for (unsigned int evi = 0; evi < 2; evi++)
          {
            const ON_SubDVertex* v = e->m_vertex[evi];
            if (nullptr != v && false == v->m_status.RuntimeMark())
            {
              v->m_status.SetRuntimeMark();
              if ( bTransform)
                const_cast<ON_SubDVertex*>(v)->Transform(false, xform);
              v_mark_count++;
            }
          }
        }
      }
      break;

    case ON_SubDComponentPtr::Type::Face:
      {
        const ON_SubDFace* f = cptr_list[i].Face();
        if (nullptr != f)
        {
          const unsigned int face_vertex_count = f->m_edge_count;
          for (unsigned int fvi = 0; fvi < face_vertex_count; fvi++)
          {
            const ON_SubDVertex* v = f->Vertex(fvi);
            if (nullptr != v && false == v->m_status.RuntimeMark())
            {
              v->m_status.SetRuntimeMark();
              if ( bTransform)
                const_cast<ON_SubDVertex*>(v)->Transform(false, xform);
              v_mark_count++;
            }
          }
        }
      }
      break;
    }
  }

  return v_mark_count;
}

unsigned int ON_SubD::TransformComponents(
  const ON_Xform& xform,
  const ON_SubDComponentPtr* cptr_list,
  size_t cptr_count
)
{
  if ( 
    false == xform.IsValidAndNotZeroAndNotIdentity()
    || cptr_count <= 0
    || nullptr == cptr_list
    )
    return 0;

  ON_SimpleArray<const ON_SubDComponentBase*> marked_components;
  const bool bRestoreMarks = ClearComponentMarks(true, true, true, &marked_components) > 0;

  const unsigned int v_count = Internal_MarkVertices(*this, cptr_list, cptr_count, xform);

  if (v_count > 0)
  {
    this->ClearEvaluationCache();
  }

  if (bRestoreMarks)
    SetComponentMarks(true, marked_components);

  return (v_count > 0);
}

unsigned int ON_SubD::ExtrudeComponents(
  const ON_Xform& xform,
  const ON_COMPONENT_INDEX* ci_list,
  size_t ci_count,
  bool bPermitNonManifoldEdgeCreation,
  ON_SubD::EdgeTag original_edge_tag,
  ON_SubD::EdgeTag moved_edge_tag
)
{
  if ( 
    false == xform.IsValidAndNotZeroAndNotIdentity()
    || xform.IsIdentity()
    || ci_count <= 0
    || nullptr == ci_list
    )
    return 0;

  ON_SimpleArray<ON_SubDComponentPtr> cptr_list;
  if (ComponentPtrFromComponentIndex(ci_list,ci_count,cptr_list) <= 0)
    return true; // nothing to extrude

  return ExtrudeComponents(
    xform,
    cptr_list.Array(),
    cptr_list.UnsignedCount(),
    bPermitNonManifoldEdgeCreation,
    original_edge_tag,
    moved_edge_tag
    );
}

class ON_Internal_ExtrudedVertexPair
{
public:
  ON_Internal_ExtrudedVertexPair() = default;
  ~ON_Internal_ExtrudedVertexPair() = default;
  ON_Internal_ExtrudedVertexPair(const ON_Internal_ExtrudedVertexPair&) = default;
  ON_Internal_ExtrudedVertexPair& operator=(const ON_Internal_ExtrudedVertexPair&) = default;

  static const ON_Internal_ExtrudedVertexPair Unset;

  // the marked vertex was in the original subd and will be moved.
  ON_SubDVertex* m_marked_vertex = nullptr;

  // the unmarked vertex replaces the marked vertex at the original location.
  ON_SubDVertex* m_unmarked_vertex = nullptr;

  // from new vertex to original vertex
  ON_SubDEdge* m_new_side = nullptr;

  static int CompareMarkedVertexId(
    const ON_Internal_ExtrudedVertexPair* lhs,
    const ON_Internal_ExtrudedVertexPair* rhs
  );
};

const ON_Internal_ExtrudedVertexPair ON_Internal_ExtrudedVertexPair::Unset ON_CLANG_CONSTRUCTOR_BUG_INIT(ON_Internal_ExtrudedVertexPair);


class ON_Internal_ExtrudedSide
{
public:
  ON_Internal_ExtrudedSide() = default;
  ~ON_Internal_ExtrudedSide() = default;
  ON_Internal_ExtrudedSide(const ON_Internal_ExtrudedSide&) = default;
  ON_Internal_ExtrudedSide& operator=(const ON_Internal_ExtrudedSide&) = default;

  static const ON_Internal_ExtrudedSide Unset;

  // the marked edge was in the original object and will be moved.
  ON_SubDEdge* m_marked_edge = nullptr;

  // the unmarked edge replaces the marked edge at the original location.
  ON_SubDEdge* m_unmarked_edge = nullptr;

  // start at new vertex and end at original vertex;
  ON_SubDEdge* m_new_side0 = nullptr;
  ON_SubDEdge* m_new_side1 = nullptr;

  ON_SubDFace* m_new_face = nullptr;
};

const ON_Internal_ExtrudedSide ON_Internal_ExtrudedSide::Unset ON_CLANG_CONSTRUCTOR_BUG_INIT(ON_Internal_ExtrudedSide);

int ON_Internal_ExtrudedVertexPair::CompareMarkedVertexId(
  const ON_Internal_ExtrudedVertexPair* lhs,
  const ON_Internal_ExtrudedVertexPair* rhs
)
{
  const unsigned int lhs_id = lhs->m_marked_vertex->m_id;
  const unsigned int rhs_id = rhs->m_marked_vertex->m_id;
  if (lhs_id < rhs_id)
    return -1;
  if (lhs_id > rhs_id)
    return 1;
  return 0;
}

static  ON_SubD::EdgeTag Internal_AdjustedEdgeTag(const ON_SubDEdge* edge)
{
  if (nullptr == edge || nullptr == edge->m_vertex[0] || nullptr == edge->m_vertex[1])
    return ON_SubD::EdgeTag::Unset;


  // adjust moved edge tag because vertex tags can change when they get moved.
  const ON_SubD::VertexTag evtag[2] = { edge->m_vertex[0]->m_vertex_tag ,edge->m_vertex[1]->m_vertex_tag };
  
  if (ON_SubD::VertexTag::Unset == evtag[0] || ON_SubD::VertexTag::Unset == evtag[1])
    return ON_SubD::EdgeTag::Unset;

  if (ON_SubD::VertexTag::Smooth == evtag[0] || ON_SubD::VertexTag::Smooth == evtag[1])
    return ON_SubD::EdgeTag::Smooth;
  
  const ON_SubD::EdgeTag etag = edge->m_edge_tag;
  if (ON_SubD::EdgeTag::Smooth == etag || ON_SubD::EdgeTag::X == etag )
    return ON_SubD::EdgeTag::X;

  return etag;
}

static void Internal_SetEdgeVertices(
  ON_SubD& subd,
  ON_Internal_ExtrudedVertexPair& vertex_pair
  )
{
  // marked edges use the marked vertex.
  ON_SubDVertex* marked_vertex = vertex_pair.m_marked_vertex;
  ON_SubDVertex* unmarked_vertex =  vertex_pair.m_unmarked_vertex;
  const unsigned int vertex_edge_count = marked_vertex->EdgeCount();
  unsigned int marked_edge_count = 0;
  unsigned int unmarked_edge_count = 0;
  unsigned int new_edge_count = 0;
  for (unsigned int vei = 0; vei < vertex_edge_count; vei++)
  {
    ON_SubDEdgePtr eptr = marked_vertex->m_edges[vei];
    const ON_SubDEdge* e = eptr.Edge();
    if (nullptr == e)
      continue;
    if (vertex_pair.m_new_side == e)
      new_edge_count++;
    else if (e->m_status.RuntimeMark())
      marked_edge_count++;
    else
      unmarked_edge_count++;
  }

  if (unmarked_edge_count <= 0)
    return;

  unmarked_edge_count += unmarked_vertex->m_edge_count;

  if ( unmarked_vertex->m_edge_capacity < (unmarked_edge_count+new_edge_count) )
  {
    subd.GrowVertexEdgeArray(unmarked_vertex, unmarked_edge_count);    
  }

  marked_vertex->m_edge_count = 0;
  for (unsigned int vei = 0; vei < vertex_edge_count; vei++)
  {
    ON_SubDEdgePtr eptr = marked_vertex->m_edges[vei];
    ON_SubDEdge* e = eptr.Edge();
    if (nullptr == e)
      continue;
    if (vertex_pair.m_new_side == e || e->m_status.RuntimeMark())
    {
      marked_vertex->m_edges[marked_vertex->m_edge_count] = eptr;
      marked_vertex->m_edge_count++;
    }
    else
    {
      if (e->m_vertex[0] == marked_vertex)
        e->m_vertex[0] = unmarked_vertex;
      else if (e->m_vertex[1] == marked_vertex)
        e->m_vertex[1] = unmarked_vertex;
      unmarked_vertex->m_edges[unmarked_vertex->m_edge_count] = eptr;
      unmarked_vertex->m_edge_count++;
    }
  }
}

static ON_SubDFace* Internal_AddNewFace(
  ON_SubD& subd,
  ON_Internal_ExtrudedSide& side
)
{
  // All components that will be moved have the runtime mark set.
  // All other components have a clear runtime mark.
  // The original_edge will be moved.
  // The new_edge will not be moved.
  // new edge and original edge go the same direction.
  // new_side_edges[2] run from new to original edges.
  
  // change edges of unmarked faces to use the new edge
  ON__UINT_PTR edir = 0;
  ON_SubDEdge* marked_edge = side.m_marked_edge; // will be moved
  ON_SubDEdge* unmarked_edge = side.m_unmarked_edge; // fixed
  unsigned int marked_edge_face_count0 = marked_edge->m_face_count;
  ON_SubDFacePtr* marked_edge_fptr1 = marked_edge->m_face2;
  const ON_SubDFacePtr* marked_edge_fptr0 = marked_edge_fptr1;
  unsigned int marked_edge_face_count1 = 0;
  subd.GrowEdgeFaceArray(unmarked_edge, marked_edge_face_count0);
  for (unsigned int efi = 0; efi < marked_edge_face_count0; efi++, marked_edge_fptr0++)
  {
    if (2 == efi)
      marked_edge_fptr0 = marked_edge->m_facex;

    if (2 == marked_edge_face_count1)
      marked_edge_fptr1 = marked_edge->m_facex;

    ON_SubDFace* f = marked_edge_fptr0->Face();
    if (nullptr == f)
    {
      ON_SUBD_ERROR("null face pointer");
      continue;
    }

    if (f->m_status.RuntimeMark())
    {
      edir = marked_edge_fptr0->FaceDirection();
      marked_edge_face_count1++;
      *marked_edge_fptr1 = *marked_edge_fptr0;
      marked_edge_fptr1++;
      continue; // this face will be moved and keeps edge e1
    }

    // f is unmarked.
    // change referenced edge from marked_edge to unmarked_edge.
    f->ReplaceEdgeInArray(0, marked_edge, unmarked_edge);

    unmarked_edge->AddFaceToArray(*marked_edge_fptr0);
  }

  // When marked_edge is a manifold edge, face_count goes from 2 to 1.
  marked_edge->m_face_count = static_cast<unsigned short>(marked_edge_face_count1);

  ON_SubDEdge* side0 = (0 == edir) ? side.m_new_side0 : side.m_new_side1;
  ON_SubDEdge* side1 = (0 == edir) ? side.m_new_side1 : side.m_new_side0;
  ON_SubDEdgePtr new_face_eptr[4];
  new_face_eptr[0] = ON_SubDEdgePtr::Create(side.m_marked_edge, 1-edir);
  new_face_eptr[1] = ON_SubDEdgePtr::Create(side0, 1);
  new_face_eptr[2] = ON_SubDEdgePtr::Create(side.m_unmarked_edge, edir);
  new_face_eptr[3] = ON_SubDEdgePtr::Create(side1, 0);

  side.m_new_face = subd.AddFace(4, new_face_eptr);

  return side.m_new_face;
}

static ON_SubD::EdgeTag Internal_ConnectingEdgeTagAtVertex(
  const ON_SubDVertex* v,
  ON_SubD::VertexTag& moved_vertex_tag,
  ON_SubD::VertexTag& stationary_vertex_tag
)
{
  moved_vertex_tag = v->m_vertex_tag;
  stationary_vertex_tag = v->m_vertex_tag;
  if (ON_SubD::VertexTag::Crease != v->m_vertex_tag && ON_SubD::VertexTag::Dart != v->m_vertex_tag)
  {
    ON_SUBD_ERROR("This function requires a crease or dart vertex as input.");
    return ON_SubD::EdgeTag::Unset;
  }

  unsigned int expected_crease_count = ON_UNSET_UINT_INDEX;
  switch (v->m_vertex_tag)
  {
  case ON_SubD::VertexTag::Smooth:
    expected_crease_count = 0;
    break;
  case ON_SubD::VertexTag::Dart:
    expected_crease_count = 1;
    break;
  case ON_SubD::VertexTag::Crease:
    expected_crease_count = 2;
    break;
  case ON_SubD::VertexTag::Corner:
    break;
  default:
    break;
  }

/*

    = (ON_SubD::VertexTag::Dart == v->m_vertex_tag)
    ? 1
    : ((ON_SubD::VertexTag::CDart == v->m_vertex_tag) ? 2 : 0;
*/

  const unsigned int vertex_edge_count = v->m_edge_count;
  unsigned int sep_crease_count = 0;
  unsigned int moved_crease_count = 0;
  unsigned int stationary_crease_count = 0;
  for (unsigned int vei = 0; vei < vertex_edge_count; vei++)
  {
    const ON_SubDEdge* e = ON_SUBD_EDGE_POINTER(v->m_edges[vei].m_ptr);
    if (nullptr == e)
      continue;

    if (ON_SubD::EdgeTag::Crease != e->m_edge_tag)
      continue;

    if (e->m_status.RuntimeMark())
    {
      sep_crease_count++;
      continue;
    }

    bool bThisEdgeMoves = false;
    for (unsigned short evi = 0; evi < e->m_face_count; evi++)
    {
      const ON_SubDFace* f = e->Face(evi);
      if (f->m_status.RuntimeMark())
      {
        bThisEdgeMoves = true;
        break;
      }
    }
    if (bThisEdgeMoves)
      ++moved_crease_count;
    else
      ++stationary_crease_count;
  }

 
  if (ON_SubD::VertexTag::Corner == v->m_vertex_tag && (sep_crease_count + moved_crease_count + stationary_crease_count) >= 2)
    expected_crease_count = (sep_crease_count + moved_crease_count + stationary_crease_count);

  if (expected_crease_count != (sep_crease_count + moved_crease_count + stationary_crease_count))
    ON_SUBD_ERROR("Unexpected tags - input is probably invalid.");

  ON_SubD::EdgeTag connecting_edge_tag;
  if (0 == stationary_crease_count || 0 == moved_crease_count)
  {
    if (sep_crease_count >= 2 && ON_SubD::VertexTag::Corner == v->m_vertex_tag)
    {
      stationary_vertex_tag = ON_SubD::VertexTag::Corner;
      moved_vertex_tag = ON_SubD::VertexTag::Corner;
    }
    else
    {
      switch (sep_crease_count + stationary_crease_count)
      {
      case 0:
        stationary_vertex_tag = ON_SubD::VertexTag::Smooth;
        break;
      case 1:
        stationary_vertex_tag = ON_SubD::VertexTag::Dart;
        break;
      case 2:
        stationary_vertex_tag = ON_SubD::VertexTag::Crease;
        break;
      default:
        stationary_vertex_tag = ON_SubD::VertexTag::Corner;
        break;
      }

      switch (sep_crease_count + moved_crease_count)
      {
      case 0:
        moved_vertex_tag = ON_SubD::VertexTag::Smooth;
        break;
      case 1:
        moved_vertex_tag = ON_SubD::VertexTag::Dart;
        break;
      case 2:
        moved_vertex_tag = ON_SubD::VertexTag::Crease;
        break;
      default:
        moved_vertex_tag = ON_SubD::VertexTag::Corner;
        break;
      }
    }

    if ( 
      (0 == stationary_crease_count && 0 == moved_crease_count)
      || ON_SubD::VertexTag::Smooth == stationary_vertex_tag
      || ON_SubD::VertexTag::Dart == stationary_vertex_tag
      || ON_SubD::VertexTag::Smooth == moved_vertex_tag
      || ON_SubD::VertexTag::Dart == moved_vertex_tag
      )
      connecting_edge_tag = ON_SubD::EdgeTag::Smooth;
    else
      connecting_edge_tag = ON_SubD::EdgeTag::Crease;
  }
  else
  {
    // Corner "upgrade" check is below.
    stationary_vertex_tag = ON_SubD::VertexTag::Crease;
    moved_vertex_tag = ON_SubD::VertexTag::Crease;
    connecting_edge_tag = ON_SubD::EdgeTag::Crease;
  }


  if (ON_SubD::EdgeTag::Smooth == connecting_edge_tag)
  {
    if (ON_SubD::VertexTag::Smooth != stationary_vertex_tag && ON_SubD::VertexTag::Smooth!= moved_vertex_tag)
      connecting_edge_tag = ON_SubD::EdgeTag::X; // at level 0, both ends are tagged.
  }
  else
  {
    // connecting edge is crease
    if (sep_crease_count + stationary_crease_count + 1 > 2)
      stationary_vertex_tag = ON_SubD::VertexTag::Corner;
    if (sep_crease_count + moved_crease_count + 1 > 2)
      moved_vertex_tag = ON_SubD::VertexTag::Corner;
  }

  return connecting_edge_tag;
}

static bool Internal_NonManifoldEdgeWillBeCreated( const ON_SubDVertex* v )
{
  if (nullptr == v || false == v->m_status.RuntimeMark())
    return false;
  v->m_status.ClearRuntimeMark();

  const unsigned int vertex_edge_count = v->m_edge_count;
  unsigned int boundary_count = 0;
  for (unsigned int vei = 0; vei < vertex_edge_count; vei++)
  {
    const ON_SubDEdge* e = v->Edge(vei);
    if (nullptr == e || 0 == e->m_face_count)
      continue;
    if (e->m_face_count > 2)
      return true;
    const ON_SubDFace* f = e->Face(0);
    const bool b0 = (nullptr != f) ? f->m_status.RuntimeMark() : false;
    f = (e->m_face_count > 1) ? e->Face(1) : nullptr;
    const bool b1 = (nullptr != f) ? f->m_status.RuntimeMark() : false;
    if (b0 == b1)
      continue;
    boundary_count++;
    if (boundary_count > 2)
      return true;
  }
  return false;
}

unsigned int ON_SubD::ExtrudeComponents(
  const ON_Xform& xform,
  const ON_SubDComponentPtr* cptr_list,
  size_t cptr_count,
  bool bPermitNonManifoldEdgeCreation,
  ON_SubD::EdgeTag original_edge_tag,
  ON_SubD::EdgeTag moved_edge_tag
)
{
  if (
    false == xform.IsValidAndNotZeroAndNotIdentity()
    || cptr_count <= 0
    || nullptr == cptr_list
    )
    return 0;

  if (ON_SubD::EdgeTag::Crease != original_edge_tag && ON_SubD::EdgeTag::Smooth != original_edge_tag)
    original_edge_tag = ON_SubD::EdgeTag::Unset;

  if (ON_SubD::EdgeTag::Crease != moved_edge_tag && ON_SubD::EdgeTag::Smooth != moved_edge_tag)
    moved_edge_tag = ON_SubD::EdgeTag::Unset;
  
  ON_SubDComponentMarksClearAndRestore mark_guard(*this);

  // Marks very vertex touching a component in the cptr_list.
  // Skips applying the transform because it is the identity.
  const unsigned int v_count = Internal_MarkVertices(*this, cptr_list, cptr_count, ON_Xform::IdentityTransformation);

  if (false == bPermitNonManifoldEdgeCreation)
  {
  }

  unsigned int f_count = 0;
  for (;;)
  {
    if (0 == v_count)
      break;

    // Mark the faces that will be moved.
    ON_SimpleArray<const ON_SubDFace*> marked_faces(128);
    ON_SubDFaceIterator fit(*this);
    for (const ON_SubDFace* f = fit.FirstFace(); nullptr != f; f = fit.NextFace())
    {
      const unsigned int face_vertex_count = f->m_edge_count;
      if (face_vertex_count < 3)
        continue;
      for ( unsigned int fvi = 0; fvi < face_vertex_count; fvi++)
      {
        const ON_SubDVertex* v = f->Vertex(fvi);
        if (nullptr != v && v->m_status.RuntimeMark())
          continue;
        f = nullptr;
        break;
      }
      if (nullptr != f)
      {
        f->m_status.SetRuntimeMark();
        marked_faces.Append(f);
      }
    }

    f_count = marked_faces.UnsignedCount();

    if (0 == f_count)
    {
      // No faces are moving.
      break;
    }

    if (f_count == FaceCount())
    {
      // Every face is moving.
      Transform(xform);
      break;
    }

    // Mark edges on the boundary of the moved subset.
    ON_SimpleArray<ON_Internal_ExtrudedSide> new_sides(64);
    ON_SubDEdgeIterator eit(*this);
    for (const ON_SubDEdge* e = eit.FirstEdge(); nullptr != e; e = eit.NextEdge())
    {
      bool bMarkedFace = false;
      bool bUnmarkedFace = false;
      const unsigned int edge_face_count = e->m_face_count;
      for (unsigned int efi = 0; efi < edge_face_count; efi++)
      {
        const ON_SubDFace* f = e->Face(efi);
        if (nullptr == f)
          continue;
        if (f->m_status.RuntimeMark())
          bMarkedFace = true; // f is in the subset of moved faces.
        else
          bUnmarkedFace = true; // f is in the subset of stationary faces.

        if (bMarkedFace && bUnmarkedFace)
        {
          // e is on the boundary between the subset of moved faces and stationary faces.
          e->m_status.SetRuntimeMark();
          new_sides.AppendNew().m_marked_edge = const_cast<ON_SubDEdge*>(e);
          break;
        }
      }
    }

    const unsigned int e_count = new_sides.UnsignedCount();
    if (e_count <= 0)
    {
      // no edges between moved and stationary faces
      Transform(xform);
      break;
    }

    if (false == bPermitNonManifoldEdgeCreation)
    {
      bool bPermitNonManifoldEdgeWillBeCreated = false;
      for (unsigned int fi = 0; fi < f_count; fi++)
      {
        const ON_SubDFace* f = marked_faces[fi];
        const unsigned int face_vertex_count = f->m_edge_count;
        for (unsigned int fvi = 0; fvi < face_vertex_count; fvi++)
        {
          bPermitNonManifoldEdgeWillBeCreated = Internal_NonManifoldEdgeWillBeCreated(f->Vertex(fvi));
          if (bPermitNonManifoldEdgeWillBeCreated)
            break;
        }
        if (bPermitNonManifoldEdgeWillBeCreated)
          break;
      }

      if (bPermitNonManifoldEdgeWillBeCreated)
        break;
    }

    // clear vertex  marks.
    ClearComponentMarks(true, false, false, nullptr);    

    // Duplicate vertices that are on a edge between a marked and unmarked face.
    ON_SimpleArray<ON_Internal_ExtrudedVertexPair> vertex_pairs(e_count+8);
    for (unsigned int i = 0; i < e_count; i++)
    {
      const ON_SubDEdge* e = new_sides[i].m_marked_edge;
      for (unsigned int evi = 0; evi < 2; evi++)
      {
        ON_SubDVertex* v = const_cast<ON_SubDVertex*>(e->m_vertex[evi]);
        if (nullptr == v)
          continue;
        if (v->m_status.RuntimeMark())
          continue;

        // Mark this vertex. It will eventually get moved
        v->m_status.SetRuntimeMark();
        ON_Internal_ExtrudedVertexPair& vpair = vertex_pairs.AppendNew();
        vpair.m_marked_vertex = v;

        ON_SubD::VertexTag moved_vertex_tag; // the original vertex gets moved
        ON_SubD::VertexTag stationary_vertex_tag; // (this one get allocated)
        ON_SubD::EdgeTag connecting_edge_tag; // from stationary to moved vertex
        switch (v->m_vertex_tag)
        {
        case ON_SubD::VertexTag::Dart:
          connecting_edge_tag = Internal_ConnectingEdgeTagAtVertex(v, moved_vertex_tag, stationary_vertex_tag);
          break;
        case ON_SubD::VertexTag::Crease:
          connecting_edge_tag = Internal_ConnectingEdgeTagAtVertex(v, moved_vertex_tag, stationary_vertex_tag);
          break;
        case ON_SubD::VertexTag::Corner:
          moved_vertex_tag = v->m_vertex_tag;
          stationary_vertex_tag = v->m_vertex_tag;
          connecting_edge_tag = ON_SubD::EdgeTag::Crease;
          break;
        case ON_SubD::VertexTag::Smooth:
          moved_vertex_tag = ON_SubD::VertexTag::Smooth;
          stationary_vertex_tag = ON_SubD::VertexTag::Smooth;
          connecting_edge_tag = ON_SubD::EdgeTag::Smooth;
          break;
        default:
          moved_vertex_tag = ON_SubD::VertexTag::Unset;
          stationary_vertex_tag = ON_SubD::VertexTag::Unset;
          connecting_edge_tag = ON_SubD::EdgeTag::Unset;
          break;
        }

        // original vertex will eventually be moved.
        v->m_vertex_tag = moved_vertex_tag;

        // new vertex will become part of the stationary subset.
        // It is not marked.
        vpair.m_unmarked_vertex = this->AddVertex(stationary_vertex_tag, v->m_P);

        // transform the marked boundary vertex
        v->Transform(false, xform);

        // edge from stationary subset to moved subset.
        ON_SubDEdge* connecting_edge = this->AddEdge(connecting_edge_tag, vpair.m_unmarked_vertex, vpair.m_marked_vertex);
        vpair.m_new_side = connecting_edge;
      }
    }

    // sort vertex pairs so they can be located by the original vertex id.
    vertex_pairs.QuickSort(ON_Internal_ExtrudedVertexPair::CompareMarkedVertexId);

    // remove unmarked faces from marked vertices
    for (unsigned int i = 0; i < vertex_pairs.UnsignedCount(); i++)
    {
      ON_SubDVertex* marked_vertex = vertex_pairs[i].m_marked_vertex;
      ON_SubDVertex* unmarked_vertex = vertex_pairs[i].m_unmarked_vertex;
      const unsigned int vertex_face_count0 = marked_vertex->m_face_count;
      GrowVertexFaceArray(unmarked_vertex, vertex_face_count0);
      marked_vertex->m_face_count = 0;
      for (unsigned int vfi = 0; vfi < vertex_face_count0; vfi++)
      {
        const ON_SubDFace* f = marked_vertex->m_faces[vfi];
        if (nullptr == f )
          continue;
        ON_SubDVertex* v
          = (f->m_status.RuntimeMark())
          ? marked_vertex
          : unmarked_vertex;
        v->m_faces[v->m_face_count] = f;
        v->m_face_count++;
      }
    }

    // build new side edges
    ON_Internal_ExtrudedVertexPair key[2];
    for (unsigned int i = 0; i < e_count; i++)
    {
      const ON_SubDEdge* e = new_sides[i].m_marked_edge;
      for (unsigned int evi = 0; evi < 2; evi++)
      {
        key[evi].m_marked_vertex = const_cast<ON_SubDVertex*>(e->m_vertex[evi]);
        const int i0 =
          (nullptr != key[evi].m_marked_vertex)
          ? vertex_pairs.BinarySearch(&key[evi], ON_Internal_ExtrudedVertexPair::CompareMarkedVertexId)
          : -1;
        if (i0 < 0)
        {
          key[evi] = ON_Internal_ExtrudedVertexPair::Unset;
          continue;
        }
        key[evi] = vertex_pairs[i0];
      } 

      const ON_SubD::EdgeTag unmoved_edge_tag
        = (ON_SubD::EdgeTag::Crease == e->m_edge_tag)
        ? ON_SubD::EdgeTag::Crease
        : ON_SubD::EdgeTag::Unset;
      new_sides[i].m_unmarked_edge = this->AddEdge(unmoved_edge_tag, key[0].m_unmarked_vertex, key[1].m_unmarked_vertex);
      new_sides[i].m_new_side0 = key[0].m_new_side;
      new_sides[i].m_new_side1 = key[1].m_new_side;
    }

    // Mark everything a moved face touches
    // including interior edges and vertices.
    // Transform any vertices that are not already marked.
    for (unsigned int i = 0; i < f_count; i++)
    {
      const ON_SubDFace* f = marked_faces[i];
      const unsigned int face_edge_count = f->m_edge_count;
      for (unsigned int fei = 0; fei < face_edge_count; fei++)
      {
        const ON_SubDEdge* e = f->Edge(fei);
        if (nullptr == e)
          continue;
        e->m_status.SetRuntimeMark();
        for (unsigned int evi = 0; evi < 2; evi++)
        {
          ON_SubDVertex* v = const_cast<ON_SubDVertex*>(e->m_vertex[evi]);
          if (nullptr !=v && false == v->m_status.RuntimeMark())
          {
            v->Transform(false, xform);
            v->m_status.SetRuntimeMark();
          }
        }
      }
    }

    // For the original boundary vertrex, move unmarked edges to use the new vertex.
    for (unsigned int i = 0; i < vertex_pairs.UnsignedCount(); i++)
    {
      Internal_SetEdgeVertices(*this, vertex_pairs[i]);
    }

    // build new side faces
    for (unsigned int i = 0; i < e_count; i++)
    {
      Internal_AddNewFace(*this, new_sides[i]);
    }

    // Any edge touching the vertices in vertex_pairs[] may need its tag adjusted
    // because those vertices may have had their tags adjusted.
    // Some edges get checked twice, but adding code to check just once
    // takes more time than checking twice.
    for (unsigned int i = 0; i < vertex_pairs.UnsignedCount(); i++)
    {
      for (unsigned int j = 0; j < 2; j++)
      {
        const ON_SubDVertex* v = (0 == j) ? vertex_pairs[i].m_marked_vertex : vertex_pairs[i].m_unmarked_vertex;
        if (nullptr == v || nullptr == v->m_edges)
          continue;
        for (unsigned int vei = 0; vei < v->m_edge_count; vei++)
        {
          ON_SubDEdge* e = ON_SUBD_EDGE_POINTER(v->m_edges[vei].m_ptr);
          if (nullptr == e)
            continue;
          const ON_SubD::EdgeTag adjusted_etag = Internal_AdjustedEdgeTag(e);
          if (ON_SubD::EdgeTag::Unset != adjusted_etag && e->m_edge_tag != adjusted_etag)
            e->m_edge_tag = adjusted_etag;
        }
      }
    }

    // remove cached subdivision calculations
    ClearEvaluationCache();

    // Calculate vertex tags, edge tags, edge sector weights.
    this->UpdateAllTagsAndSectorCoefficients(true);
    break;
  }

#if defined(ON_DEBUG)
  IsValid();
#endif

  return f_count;
}

unsigned int ON_SubD::SetVertexTags(
  const ON_COMPONENT_INDEX* ci_list,
  size_t ci_count,
  ON_SubD::VertexTag vertex_tag
)
{
  if (
    ON_SubD::VertexTag::Smooth != vertex_tag
    && ON_SubD::VertexTag::Crease != vertex_tag
    && ON_SubD::VertexTag::Corner != vertex_tag
    )
    return 0;

  if (
    ci_count <= 0
    || nullptr == ci_list
    || VertexCount() <= 0
    )
    return 0;

  ON_SimpleArray<ON_SubDComponentPtr> cptr_list;
  if (ComponentPtrFromComponentIndex(ci_list,ci_count,cptr_list) <= 0)
    return 0; // nothing to change

  return SetVertexTags(
    cptr_list.Array(),
    cptr_list.UnsignedCount(),
    vertex_tag
    );
}

unsigned int ON_SubD::SetVertexTags(
  const ON_SubDComponentPtr* cptr_list,
  size_t cptr_count,
  ON_SubD::VertexTag vertex_tag
)
{
  if (
    ON_SubD::VertexTag::Smooth != vertex_tag
    && ON_SubD::VertexTag::Crease != vertex_tag
    && ON_SubD::VertexTag::Corner != vertex_tag
    )
    return 0;

  if (cptr_count <= 0 || nullptr == cptr_list)
    return 0;

  ON_SubDComponentMarksClearAndRestore mark_guard(*this);

  const bool bNewVertexTagIsSmooth = (ON_SubD::VertexTag::Smooth == vertex_tag);

  // count and mark vertex candidates
  // mark edges that may need to have their tag changed
  unsigned int candidate_count = 0;
  for (size_t i = 0; i < cptr_count; i++)
  {
    ON_SubDVertex* vertex = cptr_list[i].Vertex();
    if (nullptr == vertex)
      continue;
    if (vertex->m_vertex_tag == vertex_tag)
      continue;

    if (ON_SubD::VertexTag::Corner != vertex_tag)
    {
      // new vertex_tag is Smooth or Crease
      if (nullptr == vertex->m_edges || vertex->m_edge_count < 2)
        continue;

      unsigned short min_face_count = 0xFFFFU;
      unsigned short max_face_count = 0xFFFEU;
      for (unsigned short vei = 0; vei < vertex->m_edge_count; vei++)
      {
        const ON_SubDEdge* edge = ON_SUBD_EDGE_POINTER(vertex->m_edges[vei].m_ptr);
        if (nullptr == edge)
          continue;
#pragma ON_PRAGMA_WARNING_PUSH
#pragma ON_PRAGMA_WARNING_DISABLE_CLANG("-Wtautological-compare")
#pragma ON_PRAGMA_WARNING_DISABLE_GNU("-Wtautological-compare")
        // The next if (min_face_count > min_face_count) should be if (min_face_count > max_face_count)
        // and is a bug that will not be fixed in 6.x because it exposes other bugs below.
        // Without the fix, max_face_count is always 0xFFFEU and the continue always occurs.
        // It will be fixed in 7.x. See RH-51598.
        if (min_face_count > min_face_count)
        {
          min_face_count = edge->m_face_count;
          max_face_count = edge->m_face_count;
        }
        else if (edge->m_face_count < min_face_count)
          min_face_count = edge->m_face_count;
        else if (edge->m_face_count > max_face_count)
          max_face_count = edge->m_face_count;
#pragma ON_PRAGMA_WARNING_POP
      }

      if (max_face_count > 2)
        continue;

      if (bNewVertexTagIsSmooth && 2 != min_face_count )
        continue;
    }

    candidate_count++;
    vertex->m_status.SetRuntimeMark();
    if (nullptr != vertex->m_edges)
    {
      if (ON_SubD::VertexTag::Corner == vertex_tag)
      {
        const unsigned int crease_count = vertex->EdgeCount(ON_SubD::EdgeTag::Crease);
        if (2 == crease_count)
          continue; // do not crease additional edges
      }

      for (unsigned short vei = 0; vei < vertex->m_edge_count; vei++)
      {
        const ON_SubDEdge* edge = ON_SUBD_EDGE_POINTER(vertex->m_edges[vei].m_ptr);
        if (nullptr == edge)
          continue;
        if (bNewVertexTagIsSmooth)
        {
          // new vertex_tag is Smooth
          if (edge->IsSmoothNotX())
            continue;
        }
        else
        {
          // new vertex_tag is Crease or Corner
          if (edge->IsCrease())
            continue;
        }

        // This edge tag will need to be changed
        edge->m_status.SetRuntimeMark();
      }
    }
  }

  if (0 == candidate_count)
    return 0;

  bool bUpdateTags = (ON_SubD::VertexTag::Crease != vertex_tag);

  // This for loop is used when new vertex_tag is ON_SubD::VertexTag::Crease.
  for (int pass = 0; pass < 2 && false == bUpdateTags; pass++)
  {
    // More careful analysis is neeeded to accurately mark smooth edges that will become creases
    ON_SubDEdgeIterator eit(*this);
    for (const ON_SubDEdge* edge = eit.FirstEdge(); nullptr != edge; edge = eit.NextEdge())
    {
      if (false == edge->m_status.RuntimeMark())
        continue;
      
      edge->m_status.ClearRuntimeMark();
      if (false == edge->IsSmooth())
        continue;

      const ON_SubDVertex* v[2] = { edge->m_vertex[0], edge->m_vertex[1] };
      if (nullptr == v[0] || nullptr == v[1])
        continue;

      const ON_SubD::VertexTag vtag[2] = {
        (v[0]->m_status.RuntimeMark() ? vertex_tag : v[0]->m_vertex_tag),
        (v[1]->m_status.RuntimeMark() ? vertex_tag : v[1]->m_vertex_tag)
      };

      // At least one of v[0] and v[1] had m_vertex_tag changed.

      ON_SubD::EdgeTag edge_tag;
      for (;;)
      {
        if (2 != edge->m_face_count)
        {
          edge_tag = ON_SubD::EdgeTag::Crease;
          break;
        }

        if (2 == v[0]->m_edge_count && (ON_SubD::VertexTag::Crease == vtag[0] || ON_SubD::VertexTag::Corner == vtag[0]))
        {
          edge_tag = ON_SubD::EdgeTag::Crease;
          break;
        }

        if (2 == v[1]->m_edge_count && (ON_SubD::VertexTag::Crease == vtag[1] || ON_SubD::VertexTag::Corner == vtag[1]))
        {
          edge_tag = ON_SubD::EdgeTag::Crease;
          break;
        }

        if (
          (ON_SubD::VertexTag::Crease == vtag[0] || ON_SubD::VertexTag::Corner == vtag[0] || ON_SubD::VertexTag::Dart == vtag[0])
          &&
          (ON_SubD::VertexTag::Crease == vtag[1] || ON_SubD::VertexTag::Corner == vtag[1] || ON_SubD::VertexTag::Dart == vtag[1])
          )
        {
          edge_tag = ON_SubD::EdgeTag::Crease;
          break;
        }

        edge_tag = ON_SubD::EdgeTag::Smooth;
        break;
      }

      if (ON_SubD::EdgeTag::Crease == edge_tag)
        edge->m_status.SetRuntimeMark();
    }

    // make sure new crease vertices will have the right number of creased edges
    bUpdateTags = true;
    for (size_t i = 0; i < cptr_count; i++)
    {
      ON_SubDVertex* vertex = cptr_list[i].Vertex();
      if (nullptr == vertex)
        continue;
      if (false == vertex->m_status.RuntimeMark())
        continue;
      unsigned int crease_count = 0;
      unsigned int marked_count = 0;
      for (unsigned short vei = 0; vei < vertex->m_edge_count; vei++)
      {
        const ON_SubDEdge* edge = ON_SUBD_EDGE_POINTER(vertex->m_edges[vei].m_ptr);
        if (nullptr == edge)
          continue;
        if (edge->IsCrease())
          ++crease_count;
        else if (edge->m_status.RuntimeMark())
          ++marked_count;
      }
      if (crease_count + marked_count <= 2 && (0 != crease_count || 0 != marked_count))
        continue;

      if (pass > 0)
        return 0;
      bUpdateTags = false;
      if (2 == crease_count)
      {
        for (unsigned short vei = 0; vei < vertex->m_edge_count; vei++)
        {
          const ON_SubDEdge* edge = ON_SUBD_EDGE_POINTER(vertex->m_edges[vei].m_ptr);
          if (nullptr != edge)
            edge->m_status.ClearRuntimeMark();
        }
      }
      else
      {
        vertex->m_status.ClearRuntimeMark();
        candidate_count--;
      }
    }

    if (0 == candidate_count)
      return 0;
  }

  if (false == bUpdateTags)
    return 0;

  unsigned int changed_vertex_count = 0;
  for (size_t i = 0; i < cptr_count; i++)
  {
    ON_SubDVertex* vertex = cptr_list[i].Vertex();
    if (nullptr == vertex)
      continue;
    if (false == vertex->m_status.RuntimeMark())
      continue;
    changed_vertex_count++;
    vertex->m_vertex_tag = vertex_tag;
    vertex->VertexModifiedNofification();
    for (unsigned short vei = 0; vei < vertex->m_edge_count; vei++)
    {
      const ON_SubDEdge* edge = ON_SUBD_EDGE_POINTER(vertex->m_edges[vei].m_ptr);
      if (nullptr == edge)
        continue;
      if ( false == bNewVertexTagIsSmooth
        && edge->m_status.RuntimeMark() 
        && false == edge->IsCrease()
        )
      {
        const_cast<ON_SubDEdge*>(edge)->m_edge_tag = ON_SubD::EdgeTag::Crease;
        edge->EdgeModifiedNofification();
      }
      edge->m_status.SetRuntimeMark();

      const ON_SubDVertex* other_vertex = edge->OtherEndVertex(vertex);
      other_vertex->m_status.SetRuntimeMark();

      if ( false == bNewVertexTagIsSmooth
        && ON_SubD::EdgeTag::Crease == edge->m_edge_tag
        && other_vertex->IsSmooth()
        )
      {
        const_cast<ON_SubDVertex*>(other_vertex)->m_vertex_tag = ON_SubD::VertexTag::Dart;
        other_vertex->VertexModifiedNofification();
      }
    }
  }

  if (0 == changed_vertex_count)
    return 0;

  ON_SubDEdgeIterator eit(*this);
  for (const ON_SubDEdge* edge = eit.FirstEdge(); nullptr != edge; edge = eit.NextEdge())
  {
    if (false == edge->m_status.RuntimeMark())
      continue;
    const ON_SubDVertex* v[2] = { edge->m_vertex[0], edge->m_vertex[1] };
    if (nullptr == v[0] || nullptr == v[1])
      continue;

    ON_SubD::EdgeTag edge_tag;
    if (v[0]->IsCreaseOrCornerOrDart() && v[1]->IsCreaseOrCornerOrDart())
      edge_tag = ON_SubD::EdgeTag::Crease;
    else
      edge_tag = ON_SubD::EdgeTag::Smooth;

    if (edge->m_edge_tag == edge_tag)
      continue;
    const_cast<ON_SubDEdge*>(edge)->m_edge_tag = edge_tag;
    edge->EdgeModifiedNofification();
  }

  ON_SubDVertexIterator vit(*this);
  for (const ON_SubDVertex* vertex = vit.FirstVertex(); nullptr != vertex; vertex = vit.NextVertex())
  {
    if (false == vertex->m_status.RuntimeMark())
      continue;
    const unsigned int crease_count = vertex->EdgeCount(ON_SubD::EdgeTag::Crease);
    ON_SubD::VertexTag vtag = vertex->m_vertex_tag;
    if (2 == crease_count)
    {
      if ( false == vertex->IsCreaseOrCorner() )
        vtag = ON_SubD::VertexTag::Crease;
    }
    else if (1 == crease_count)
      vtag = ON_SubD::VertexTag::Dart;
    else if (crease_count > 2)
      vtag = ON_SubD::VertexTag::Corner;
    else
      vtag = ON_SubD::VertexTag::Smooth;
    if (vertex->m_vertex_tag == vtag)
      continue;
    const_cast<ON_SubDVertex*>(vertex)->m_vertex_tag = vtag;
  }

  ClearLimitSurfaceMesh();
  UpdateAllTagsAndSectorCoefficients(false);

  return changed_vertex_count;
}

unsigned int ON_SubD::SetEdgeTags(
  const ON_COMPONENT_INDEX* ci_list,
  size_t ci_count,
  ON_SubD::EdgeTag edge_tag
)
{
  if (ON_SubD::EdgeTag::Smooth != edge_tag && ON_SubD::EdgeTag::Crease != edge_tag)
    return 0;

  if (
    ci_count <= 0
    || nullptr == ci_list
    || EdgeCount() <= 0
    )
    return 0;

  ON_SimpleArray<ON_SubDComponentPtr> cptr_list;
  if (ComponentPtrFromComponentIndex(ci_list,ci_count,cptr_list) <= 0)
    return 0; // nothing to change

  return SetEdgeTags(
    cptr_list.Array(),
    cptr_list.UnsignedCount(),
    edge_tag
    );
}

unsigned int ON_SubD::SetEdgeTags(
  const ON_SubDComponentPtr* cptr_list,
  size_t cptr_count,
  ON_SubD::EdgeTag edge_tag
)
{
  if (ON_SubD::EdgeTag::Smooth != edge_tag && ON_SubD::EdgeTag::Crease != edge_tag)
    return 0;

  if (
    cptr_count <= 0
    || nullptr == cptr_list
    || EdgeCount() <= 0
    )
    return 0;

  unsigned int changed_edge_count = 0;

  const bool bChangeToSmooth = (ON_SubD::EdgeTag::Smooth == edge_tag) ? true : false;

  for (size_t i = 0; i < cptr_count; i++)
  {
    ON_SubDEdge* edge = cptr_list[i].Edge();
    if (nullptr == edge)
      continue;
    if (bChangeToSmooth == edge->IsSmooth())
      continue;
    if (bChangeToSmooth && 2 != edge->FaceCount())
      continue;

    edge->EdgeModifiedNofification();

    changed_edge_count++;
    edge->m_edge_tag = edge_tag;
    edge->UnsetSectorCoefficients();
    for (int evi = 0; evi < 2; evi++)
    {
      ON_SubDVertex* v = const_cast<ON_SubDVertex*>(edge->m_vertex[evi]);
      if (nullptr == v)
        continue;
      v->m_vertex_tag = ON_SubD::VertexTag::Unset;
    }
  }

  if (0 == changed_edge_count)
    return 0;

  ClearLimitSurfaceMesh();

  ON_SubDVertexIterator vit(*this);
  for (const ON_SubDVertex* v = vit.FirstVertex(); nullptr != v; v = vit.NextVertex())
  {
    if (ON_SubD::VertexTag::Unset != v->m_vertex_tag)
      continue;
    unsigned crease_count = 0;
    const unsigned vertex_edge_count = v->EdgeCount();
    for (unsigned vei = 0; vei < vertex_edge_count; vei++)
    {
      const ON_SubDEdge* e = v->Edge(vei);
      if (nullptr == e)
        continue;
      if (e->IsCrease())
      {
        crease_count++;
        if (crease_count > 2)
          break;
      }
    }
    ON_SubD::VertexTag vertex_tag;
    switch (crease_count)
    {
    case 0:
      vertex_tag = ON_SubD::VertexTag::Smooth;
      break;
    case 1:
      vertex_tag = ON_SubD::VertexTag::Dart;
      break;
    case 2:
      vertex_tag = ON_SubD::VertexTag::Crease;
      break;
    default:
      vertex_tag = ON_SubD::VertexTag::Corner;
      break;
    }
    if (v->m_vertex_tag != vertex_tag)
    {
      const_cast<ON_SubDVertex*>(v)->m_vertex_tag = vertex_tag;
    }
  }

  ON_SubDEdgeIterator eit(*this);
  for (const ON_SubDEdge* e = eit.FirstEdge(); nullptr != e; e = eit.NextEdge())
  {
    ON_SubD::EdgeTag e_tag = e->m_edge_tag;
    if (nullptr == e->m_vertex[0] || nullptr == e->m_vertex[1])
      e_tag = ON_SubD::EdgeTag::Unset;
    else if (ON_SubD::EdgeTag::Smooth == e_tag
      && ON_SubD::VertexTag::Smooth != e->m_vertex[0]->m_vertex_tag
      && ON_SubD::VertexTag::Smooth != e->m_vertex[1]->m_vertex_tag)
      e_tag = ON_SubD::EdgeTag::Unset;
    if (e_tag != e->m_edge_tag)
    {
      const_cast<ON_SubDEdge*>(e)->m_edge_tag = e_tag;
      e->UnsetSectorCoefficients();
    }
  }

  UpdateAllTagsAndSectorCoefficients(false);
  return changed_edge_count;
}


const ON_SubDEdgePtr ON_SubDEdgeChain::EdgeChainNeighbor(
    ON_SubDEdgePtr starting_edge,
    ON_ChainDirection search_direction,
    bool bStopAtBreak,
    bool bEnableStatusCheck,
    ON_ComponentStatus status_pass,
    ON_ComponentStatus status_fail
  )
{
  for (;;)
  {
    if (ON_ChainDirection::Previous != search_direction && ON_ChainDirection::Next != search_direction)
      break;
    const ON_SubDEdge* edge = ON_SUBD_EDGE_POINTER(starting_edge.m_ptr);
    if (nullptr == edge)
      break;
    bool bReverse = (ON_ChainDirection::Previous == search_direction);    
    if (0 != ON_SUBD_EDGE_DIRECTION(starting_edge.m_ptr))
      bReverse = !bReverse;
    const ON_SubDVertex* v = edge->m_vertex[bReverse ? 0 : 1];
    if (nullptr == v)
      break;
    if (v->m_edge_count <= 1 || nullptr == v->m_edges)
      break;
    
    const bool bIsSmooth = edge->IsSmooth();
    const bool bIsCrease = edge->IsCrease();
    if (bIsSmooth != (bIsCrease?false:true))
      break;

    if (bStopAtBreak)    
    {
      if (bIsSmooth)
      {
        if (ON_SubD::VertexTag::Smooth != v->m_vertex_tag)
          break;
      }
      else
      {
        if (ON_SubD::VertexTag::Crease != v->m_vertex_tag)
          break;
      }
    }

    // Look for a single neighbor with same crease/smooth property and same face count
    // This lets chains turn the right way when there are both creases and smooth
    // edges.
    const ON_SubDEdge* nxt = nullptr;
    for (unsigned short vei = 0; vei < v->m_edge_count; vei++)
    {
      const ON_SubDEdge* e = ON_SUBD_EDGE_POINTER(v->m_edges[vei].m_ptr);
      if (edge == e)
        continue;
      if (bIsSmooth != e->IsSmooth())
        continue;
      if (bIsCrease != e->IsCrease())
        continue;
      if (e->m_face_count != edge->m_face_count)
        continue;
      if (e->m_vertex[0] != v && e->m_vertex[1] != v)
        continue; // bogus edge
      if (nullptr == nxt)
      {
        nxt = e;
        continue;
      }
      // ambiguous options here
      nxt = nullptr;
      break;
    }
    const int nxt_connecting_vertex_index = (ON_ChainDirection::Next == search_direction) ? 0 : 1;
    if (nullptr != nxt)
    {
      if (false == bEnableStatusCheck || ON_ComponentStatus::StatusCheck(nxt->m_status, status_pass, status_fail))
        return ON_SubDEdgePtr::Create(nxt, (v == nxt->m_vertex[nxt_connecting_vertex_index]) ? 0 : 1);
    }

    if (2 != edge->m_face_count || 4 != v->m_edge_count)
      break;
    const ON_SubDFace* f[2] = { ON_SUBD_FACE_POINTER(edge->m_face2[0].m_ptr),ON_SUBD_FACE_POINTER(edge->m_face2[1].m_ptr) };
    if (nullptr == f[0] || nullptr == f[1] || f[0] == f[1])
      break;
    for (unsigned short vei = 0; vei < v->m_edge_count; vei++)
    {
      const ON_SubDEdge* e = ON_SUBD_EDGE_POINTER(v->m_edges[vei].m_ptr);
      if (edge == e)
        continue;
      if (2 != e->m_face_count)
        continue;
      if (e->m_vertex[0] != v && e->m_vertex[1] != v)
        continue; // bogus edge
      const ON_SubDFace* nxtf[2] = { ON_SUBD_FACE_POINTER(e->m_face2[0].m_ptr),ON_SUBD_FACE_POINTER(e->m_face2[1].m_ptr) };
      if (nullptr == nxtf[0] || nullptr == nxtf[1] || nxtf[0] == nxtf[1])
        continue;
      if (f[0] == nxtf[0] || f[1] == nxtf[0])
        continue;
      if (f[0] == nxtf[1] || f[1] == nxtf[1])
        continue;
      if (nullptr == nxt)
      {
        nxt = e;
        continue;
      }
      // ambiguous options here
      nxt = nullptr;
      break;
    }
    if (nullptr != nxt)
    {
      if (bStopAtBreak && bIsSmooth != nxt->IsSmooth())
        break;
      if (false == bEnableStatusCheck || ON_ComponentStatus::StatusCheck(nxt->m_status, status_pass, status_fail))
        return ON_SubDEdgePtr::Create(nxt, (v == nxt->m_vertex[nxt_connecting_vertex_index]) ? 0 : 1);
    }

    break;
  }

  return ON_SubDEdgePtr::Null;
}

void ON_UniqueTester::Block::DeleteBlock(Block* blk)
{
  if (nullptr != blk)
    onfree(blk);
}

ON_UniqueTester::Block* ON_UniqueTester::Block::NewBlock()
{
  size_t sz1 = sizeof(Block);
  while (0 != sz1 % 8)
    sz1++;
  size_t sz2 = ON_UniqueTester::Block::BlockCapacity * sizeof(m_a[0]);
  void* p = onmalloc(sz1 + sz2);
  Block* blk = new (p) Block();
  blk->m_a = (ON__UINT_PTR*)((char*)(p)) + sz1;
  return blk;
}

int ON_UniqueTester::Block::Compare(ON__UINT_PTR* lhs, ON__UINT_PTR* rhs)
{
  if (*lhs < *rhs)
    return -1;
  if (*lhs > *rhs)
    return 1;
  return 0;
}

bool ON_UniqueTester::Block::InBlock(size_t sorted_count,ON__UINT_PTR x) const
{
  if (nullptr != m_a && m_count > 0)
  {
    if ( sorted_count > 0 && x >= m_a[0] && x <= m_a[sorted_count - 1])
    {
      if (nullptr != bsearch(&x, m_a, sorted_count, sizeof(m_a[0]), (int(*)(const void*, const void*))ON_UniqueTester::Block::Compare))
        return true;
    }
    if (sorted_count < m_count)
    {
      const ON__UINT_PTR* p = m_a + sorted_count;
      const ON__UINT_PTR* p1 = m_a + m_count;
      while (p < p1)
      {
        if (x == *p++)
          return true;
      }
    }
  }
  return false;
}

void ON_UniqueTester::Block::SortBlock()
{
  ON_qsort(m_a, m_count, sizeof(m_a[0]), (int(*)(const void*, const void*))ON_UniqueTester::Block::Compare);
}

void ON_UniqueTester::Internal_CopyFrom(
  const ON_UniqueTester & src
)
{
  m_block_list = nullptr;
  m_sorted_count = 0;
 
  Block* first_blk = nullptr;

  for ( Block* src_blk = src.m_block_list; nullptr != src_blk; src_blk = src_blk->m_next)
  {
    Block* blk = Block::NewBlock();
    memcpy( blk->m_a, src_blk->m_a, src_blk->m_count * sizeof(blk->m_a[0]) );
    blk->m_count = src_blk->m_count;
    if (nullptr == first_blk)
    {
      first_blk = blk;
    }
    else
    {
      blk->m_next = m_block_list;
      m_block_list = blk;
    }
  }  

  if (nullptr != first_blk)
  {
    if (src.m_sorted_count != first_blk->m_count)
      first_blk->SortBlock();
    first_blk->m_next = m_block_list;
    m_block_list = first_blk;
    m_sorted_count = first_blk->m_count;
  }
}

void ON_UniqueTester::Internal_Destroy()
{
  Block* nxt = m_block_list;
  m_block_list = nullptr;
  m_sorted_count = 0;
  for ( Block* blk = nxt; nullptr != blk; blk = nxt)
  {
    nxt = blk->m_next;
    Block::DeleteBlock(blk);
  }  
}

ON_UniqueTester::~ON_UniqueTester()
{
  Internal_Destroy();
}

ON_UniqueTester::ON_UniqueTester(const ON_UniqueTester& src)
{
  Internal_CopyFrom(src);
}

ON_UniqueTester& ON_UniqueTester::operator=(const ON_UniqueTester& src)
{
  if (this != &src)
  {
    Internal_Destroy();
    Internal_CopyFrom(src);
  }
  return *this;
}

bool ON_UniqueTester::InList(ON__UINT_PTR x) const
{
  size_t sorted_count = m_sorted_count;
  for ( const Block* blk = m_block_list; nullptr != blk; blk = blk->m_next)
  {
    if (blk->InBlock(sorted_count, x))
      return true;
    sorted_count = ON_UniqueTester::Block::BlockCapacity;
  }  
  return false;
}

bool ON_UniqueTester::AddToList(ON__UINT_PTR x)
{
  if (nullptr != m_block_list && m_sorted_count + 50 == m_block_list->m_count)
  {
    m_block_list->SortBlock();
    m_sorted_count = m_block_list->m_count;
  }
  if (InList(x))
    return false;
  Internal_AddValue(x);
  return true;
}


void ON_UniqueTester::ExpertAddNewToList(ON__UINT_PTR x)
{
  Internal_AddValue(x);
}

void ON_UniqueTester::Internal_AddValue(ON__UINT_PTR x)
{
  if (nullptr == m_block_list || ON_UniqueTester::Block::BlockCapacity == m_block_list->m_count)
  {
    if (nullptr != m_block_list && m_sorted_count < ON_UniqueTester::Block::BlockCapacity)
      m_block_list->SortBlock();
    ON_UniqueTester::Block* blk = ON_UniqueTester::Block::NewBlock();
    blk->m_next = m_block_list;
    m_block_list = blk;
    m_sorted_count = 0;
  }
  m_block_list->m_a[m_block_list->m_count++] = x;
  if ( 1 == m_block_list->m_count
    || (m_sorted_count+1 == m_block_list->m_count && x > m_block_list->m_a[m_sorted_count-1])
    )
    ++m_sorted_count;
}

void ON_UniqueTester::ClearList()
{
  Internal_Destroy();
}

unsigned int ON_UniqueTester::Count() const
{
  size_t count = 0;
  for ( const Block* blk = m_block_list; nullptr != blk; blk = blk->m_next)
  {
    count += blk->m_count;
  }
  return (unsigned int)count;
}


const ON_SimpleArray<ON_SubDEdgePtr>& ON_SubDEdgeChain::EdgeChain() const
{
  return m_edge_chain;
}

const ON_SubD& ON_SubDEdgeChain::SubD() const
{
  return m_subd_ref.SubD();
}

const ON_SubDRef ON_SubDEdgeChain::SubDRef() const
{
  return m_subd_ref;
}

bool ON_SubDEdgeChain::InChain(
  const ON_SubDEdgePtr edge_ptr
) const
{
  return InChain(ON_SUBD_EDGE_POINTER(edge_ptr.m_ptr));
}

bool ON_SubDEdgeChain::InChain(
  const ON_SubDEdge* edge
) const
{
  return (nullptr == edge) ? false : m_unique_tester.InList((ON__UINT_PTR)edge);
}

bool ON_SubDEdgeChain::InChain(
  const ON_SubDVertex* vertex
) const
{
  return (nullptr == vertex) ? false : m_unique_tester.InList((ON__UINT_PTR)vertex);
}

bool ON_SubDEdgeChain::IsClosedLoop() const
{
  const unsigned int count = m_edge_chain.UnsignedCount();
  return (count >= 2 && m_edge_chain[0].RelativeVertex(0) == m_edge_chain[count - 1].RelativeVertex(1));
}


unsigned int ON_SubDEdgeChain::BeginEdgeChain(
  ON_SubDRef subd_ref,
  const ON_SubDEdge* initial_edge
)
{
  return ON_SubDEdgeChain::BeginEdgeChain(subd_ref, ON_SubDEdgePtr::Create(initial_edge, 0));
}

unsigned int ON_SubDEdgeChain::BeginEdgeChain(
  ON_SubDRef subd_ref,
  const ON_SimpleArray<const ON_SubDEdge* >& initial_edge_chain
)
{
  return BeginEdgeChain(subd_ref, initial_edge_chain.UnsignedCount(), initial_edge_chain.Array());
}

unsigned int ON_SubDEdgeChain::BeginEdgeChain(
  ON_SubDRef subd_ref,
  size_t edge_count,
  const ON_SubDEdge*const* initial_edge_chain
)
{
  ClearEdgeChain();

  if (
    edge_count <= 0 
    || subd_ref.SubD().IsEmpty() 
    || subd_ref.SubD().EdgeCount() < (unsigned int)edge_count
    )
    return 0;

  if ( 1 == edge_count)
    return ON_SubDEdgeChain::BeginEdgeChain(subd_ref, ON_SubDEdgePtr::Create(initial_edge_chain[0], 0));

  const ON_SubDEdge* e0 = initial_edge_chain[0];
  if (nullptr == e0 || nullptr == e0->m_vertex[0] || nullptr == e0->m_vertex[1] )
    return 0;
  const ON_SubDEdge* e1 = initial_edge_chain[1];
  if (nullptr == e1 || nullptr == e1->m_vertex[0] || nullptr == e1->m_vertex[1] )
    return 0;


  ON_SubDEdgePtr eptr = ON_SubDEdgePtr::Create(e0, (e0->m_vertex[1] == e1->m_vertex[0] || e0->m_vertex[1] == e1->m_vertex[1]) ? 0 : 1);

  ON_SimpleArray<ON_SubDEdgePtr> eptr_chain(edge_count);
  eptr_chain.Append(eptr);
  const ON_SubDVertex* v = eptr.RelativeVertex(1);
  for (unsigned int i = 1; i < edge_count; i++)
  {
    e1 = initial_edge_chain[i];
    if (nullptr == e1 || nullptr == e1->m_vertex[0] || nullptr == e1->m_vertex[1] )
      return 0;
    if (v != e1->m_vertex[0] && v != e1->m_vertex[1])
      return 0;
    eptr = ON_SubDEdgePtr::Create(e1, (v == e1->m_vertex[0]) ? 0 : 1);
    eptr_chain.Append(eptr);
  }

  return ON_SubDEdgeChain::BeginEdgeChain(subd_ref,eptr_chain);
}

unsigned int ON_SubDEdgeChain::BeginEdgeChain(
  ON_SubDRef subd_ref,
  ON_SubDEdgePtr eptr
)
{
  return ON_SubDEdgeChain::BeginEdgeChain(subd_ref, 1, &eptr);
}

unsigned int ON_SubDEdgeChain::BeginEdgeChain(
  ON_SubDRef subd_ref,
  const ON_SimpleArray<ON_SubDEdgePtr>& initial_edge_chain
)
{
  return ON_SubDEdgeChain::BeginEdgeChain(subd_ref, initial_edge_chain.UnsignedCount(), initial_edge_chain.Array() );
}

unsigned int ON_SubDEdgeChain::BeginEdgeChain(
  ON_SubDRef subd_ref,
  size_t edge_count,
  const ON_SubDEdgePtr* initial_edge_chain
)
{
  ClearEdgeChain();

  m_subd_ref = subd_ref;

  if (edge_count <= 0 || m_subd_ref.SubD().IsEmpty())
    return 0;

  if ( ((size_t)subd_ref.SubD().EdgeCount()) < edge_count )
    return 0;

  m_edge_chain.Reserve(edge_count + 128);
  const ON_SubDVertex* first_vertex = nullptr;
  const ON_SubDVertex* last_vertex = nullptr;
  for (size_t i = 0; i < edge_count; i++)
  {
    const ON_SubDEdgePtr eptr = initial_edge_chain[i];
    const ON_SubDEdge* e = ON_SUBD_EDGE_POINTER(eptr.m_ptr);
    if (nullptr == e)
      continue;
    if (m_unique_tester.InList((ON__UINT_PTR)e))
      continue;
    const ON__UINT_PTR edir = ON_SUBD_EDGE_DIRECTION(eptr.m_ptr);
    const ON_SubDVertex* v[2] = { e->m_vertex[edir], e->m_vertex[1 - edir] };
    if (nullptr == v[0] || nullptr == v[1] || v[0] == v[1] )
      continue;
    if (nullptr == first_vertex)
    {
      first_vertex = v[0];
      last_vertex = v[1];
      m_unique_tester.ExpertAddNewToList((ON__UINT_PTR)first_vertex);
      m_unique_tester.ExpertAddNewToList((ON__UINT_PTR)last_vertex);
    }
    else 
    {
      if (last_vertex != v[0])
        continue;
      if (v[1] != first_vertex)
      {
        if (m_unique_tester.AddToList((ON__UINT_PTR)v[1]))
          continue;
      }
    }
    m_edge_chain.Append(eptr);
    m_unique_tester.ExpertAddNewToList((ON__UINT_PTR)e);
    last_vertex = v[1];
    if (last_vertex == first_vertex)
      break;
  };

  return m_edge_chain.UnsignedCount();
}

void ON_SubDEdgeChain::ClearEdgeChain()
{
  m_edge_chain.SetCount(0);
  m_unique_tester.ClearList();
}

unsigned int ON_SubDEdgeChain::EdgeCount() const
{
  return m_edge_chain.UnsignedCount();
}

void ON_SubDEdgeChain::SetStatusCheck(
  bool bEnableStatusCheck,
  ON_ComponentStatus status_check_pass,
  ON_ComponentStatus status_check_fail
)
{
  m_bEnableStatusCheck = bEnableStatusCheck ? true : false;
  m_status_check_pass = status_check_pass;
  m_status_check_fail = status_check_fail;  
}

bool ON_SubDEdgeChain::StatusCheckEnabled() const
{
  return m_bEnableStatusCheck;
}

void ON_SubDEdgeChain::Reverse()
{
  ON_SubDEdgeChain::ReverseEdgeChain(m_edge_chain);
}

const ON_SubDEdgePtr ON_SubDEdgeChain::FirstEdgePtr() const
{
  return m_edge_chain.UnsignedCount() > 0 ? m_edge_chain[0] : ON_SubDEdgePtr::Null;
}
const ON_SubDEdgePtr ON_SubDEdgeChain::LastEdgePtr() const
{
  return m_edge_chain.UnsignedCount() > 0 ? *(m_edge_chain.Last()) : ON_SubDEdgePtr::Null;
}

const ON_SubDEdgePtr ON_SubDEdgeChain::EdgePtr(int edge_index) const
{
  return (edge_index >= 0 && edge_index < m_edge_chain.Count()) ? m_edge_chain[edge_index] : ON_SubDEdgePtr::Null;
}

const ON_SubDEdge* ON_SubDEdgeChain::FirstEdge() const
{
  return FirstEdgePtr().Edge();
}

const ON_SubDEdge* ON_SubDEdgeChain::LastEdge() const
{
  return LastEdgePtr().Edge();
}

const ON_SubDEdge* ON_SubDEdgeChain::Edge(int edge_index) const
{
  return EdgePtr(edge_index).Edge();
}

const ON_SubDVertex* ON_SubDEdgeChain::FirstVertex() const
{
  return Vertex(0);
}

const ON_SubDVertex* ON_SubDEdgeChain::LastVertex() const
{
  return Vertex(m_edge_chain.Count());
}

const ON_SubDVertex* ON_SubDEdgeChain::Vertex(int vertex_index) const
{
  const int edge_count = m_edge_chain.Count();
  if ( vertex_index >= 0 && vertex_index <= edge_count && edge_count > 0 )
  {
    return 
      (vertex_index == edge_count)
      ? m_edge_chain[edge_count - 1].RelativeVertex(1)
      : m_edge_chain[vertex_index].RelativeVertex(0);
  }
  return nullptr;
}


unsigned int ON_SubDEdgeChain::AddOneNeighbor(
  ON_ChainDirection direction,
  bool bStopAtTagChange
)
{
  const unsigned int count0 = m_edge_chain.UnsignedCount();
  if (count0 <= 0 || IsClosedLoop() )
    return 0;

  ON_SubDEdgePtr eptr;
  const ON_SubDEdge* e;
  const ON_SubDVertex* v;

  const ON_SubDVertex* chain_ends[2] = { FirstVertex() ,LastVertex() };

  eptr
    = (ON_ChainDirection::Previous != direction)
    ? ON_SubDEdgeChain::EdgeChainNeighbor(LastEdgePtr(), ON_ChainDirection::Next, bStopAtTagChange, m_bEnableStatusCheck, m_status_check_pass, m_status_check_fail)
    : ON_SubDEdgePtr::Null;
  e = eptr.Edge();
  v = eptr.RelativeVertex(0);
  if ( nullptr != v && v == chain_ends[1] && false == InChain(e) )
  {
    v = eptr.RelativeVertex(1);
    if (v == chain_ends[0] || m_unique_tester.AddToList((ON__UINT_PTR)v))
    {
      m_unique_tester.ExpertAddNewToList((ON__UINT_PTR)e);
      m_edge_chain.Append(eptr);
    }
  }

  eptr
    = (ON_ChainDirection::Next != direction)
    ? ON_SubDEdgeChain::EdgeChainNeighbor(FirstEdgePtr(), ON_ChainDirection::Previous, bStopAtTagChange, m_bEnableStatusCheck, m_status_check_pass, m_status_check_fail)
    : ON_SubDEdgePtr::Null;
  e = eptr.Edge();
  v = eptr.RelativeVertex(1);
  if ( nullptr != v && v == chain_ends[0] && false == InChain(e) )
  {
    v = eptr.RelativeVertex(0);
    if (v == chain_ends[1] || m_unique_tester.AddToList((ON__UINT_PTR)v))
    {
      m_unique_tester.ExpertAddNewToList((ON__UINT_PTR)e);
      m_edge_chain.Insert(0, eptr);
    }
  }

  return m_edge_chain.UnsignedCount() - count0;
}

unsigned int ON_SubDEdgeChain::AddAllNeighbors(
  ON_ChainDirection direction,
  bool bStopAtTagChange
)
{
  const unsigned int count0 = m_edge_chain.UnsignedCount();
  if (count0 <= 0 || IsClosedLoop())
    return 0;

  if (ON_ChainDirection::Previous != direction)
    while (1 == AddOneNeighbor(ON_ChainDirection::Next, bStopAtTagChange)) {}      
  if (ON_ChainDirection::Next != direction)
    while (1 == AddOneNeighbor(ON_ChainDirection::Previous, bStopAtTagChange)) {}      

  return m_edge_chain.UnsignedCount() - count0;
}

unsigned int ON_SubDEdgeChain::AddEdge(
  const ON_SubDEdge* edge
) 
{
  const unsigned int count0 = m_edge_chain.UnsignedCount();
  if (count0 <= 0)
    return 0;

  if (
    nullptr == edge 
    || nullptr == edge->m_vertex[0]
    || nullptr == edge->m_vertex[1] 
    || edge->m_vertex[0] == edge->m_vertex[1]
    )
    return 0;

  const ON_SubDVertex* v[2] = { FirstVertex(),LastVertex() };
  if (v[0] == v[1])
    return 0;

  if ( m_bEnableStatusCheck && false == ON_ComponentStatus::StatusCheck(edge->m_status, m_status_check_pass, m_status_check_fail))
    return 0;

  ON_SubDEdgePtr eptr = ON_SubDEdgePtr::Null;

  if (v[1] == edge->m_vertex[0])
    eptr = ON_SubDEdgePtr::Create(edge, 0);
  else if (v[1] == edge->m_vertex[1])
    eptr = ON_SubDEdgePtr::Create(edge, 1);
  else if (v[0] == edge->m_vertex[1])
    eptr = ON_SubDEdgePtr::Create(edge, 0);
  else if (v[0] == edge->m_vertex[0])
    eptr = ON_SubDEdgePtr::Create(edge, 1);
  else
    return 0;

  if (m_unique_tester.InList((ON__UINT_PTR)edge))
    return 0;

  if (v[1] == eptr.RelativeVertex(0) )
  {
    if (v[0] == eptr.RelativeVertex(1) || m_unique_tester.AddToList((ON__UINT_PTR)eptr.RelativeVertex(1)))
    {
      m_edge_chain.Append(eptr);
      m_unique_tester.ExpertAddNewToList((ON__UINT_PTR)edge);
    }
  }
  else if (v[0] == eptr.RelativeVertex(1) )
  {
    if (v[1] == eptr.RelativeVertex(0) || m_unique_tester.AddToList((ON__UINT_PTR)eptr.RelativeVertex(0)))
    {
      m_edge_chain.Insert(0, eptr);
      m_unique_tester.ExpertAddNewToList((ON__UINT_PTR)edge);
    }
  }

  return m_edge_chain.UnsignedCount() - count0;
}

unsigned int ON_SubDEdgeChain::RemoveEdges(
  const ON_SubDEdge* first_edge,
  const ON_SubDEdge* last_edge
) 
{
  unsigned int count0 = m_edge_chain.UnsignedCount();
  unsigned int i0 = 0;
  unsigned int i1 = count0;
  if (nullptr != first_edge)
  {
    while (i0 < count0 && first_edge != m_edge_chain[i0].Edge())
      ++i0;
  }
  if (nullptr != last_edge)
  {
    while (i1 > i0 && last_edge != m_edge_chain[i1 - 1].Edge())
      --i1;
  }

  const unsigned int count1 = i1 - i0;
  if (count1 >= count0)
    return 0;

  if (i0 > 0)
  {
    for (unsigned int i = i0; i < i1; i++)
      m_edge_chain[i - i0] = m_edge_chain[i];
  }

  m_edge_chain.SetCount(count1);
  m_unique_tester.ClearList();
  for (unsigned int i = 0; i < count1; i++)
  {
    m_unique_tester.AddToList((ON__UINT_PTR)m_edge_chain[i].Edge());
    m_unique_tester.AddToList((ON__UINT_PTR)m_edge_chain[i].RelativeVertex(0));
  }
  if ( FirstVertex() != LastVertex() )
    m_unique_tester.AddToList((ON__UINT_PTR)LastVertex());

  return count0 - count1;
}


void ON_SubDEdgeChain::ReverseEdgeChain(
  ON_SimpleArray< ON_SubDEdgePtr >& edge_chain
)
{
  ON_SubDEdgeChain::ReverseEdgeChain(edge_chain.UnsignedCount(), edge_chain.Array());
}

void ON_SubDEdgeChain::ReverseEdgeChain(
  size_t edge_count,
  ON_SubDEdgePtr* edge_chain
)
{
  if (edge_count <= 0 || nullptr == edge_chain)
    return;
  ON_SubDEdgePtr* p0 = edge_chain;
  ON_SubDEdgePtr* p1 = p0 + (edge_count - 1);
  while ( p0 < p1)
  {
    ON_SubDEdgePtr eptr = p0->Reversed();
    *p0 = p1->Reversed();
    *p1 = eptr;
    ++p0;
    --p1;
  }
  if (p0 == p1)
    *p0 = p0->Reversed();
}

bool ON_SubDEdgeChain::IsValidEdgeChain(
  const ON_SimpleArray< ON_SubDEdgePtr >& edge_chain,
  bool bCheckForDuplicateEdges
)
{
  return ON_SubDEdgeChain::IsValidEdgeChain(edge_chain.UnsignedCount(), edge_chain.Array(), bCheckForDuplicateEdges);
}

bool ON_SubDEdgeChain::IsValidEdgeChain(
  size_t edge_count,
  const ON_SubDEdgePtr* edge_chain,
  bool bCheckForDuplicateEdges
)
{
  if (edge_count <= 0)
    return true;
  if (nullptr == edge_chain)
    return false;

  const ON_SubDVertex* first_vertex = edge_chain->RelativeVertex(0);
  if (nullptr == first_vertex)
    return false;

  const ON_SubDVertex* v = first_vertex;
  const ON_SubDEdgePtr* p0 = edge_chain;
  const ON_SubDEdgePtr* p1 = edge_chain+1;

  for (const ON_SubDEdgePtr* p = p0; p < p1; ++p)
  {
    const ON_SubDEdge* e = ON_SUBD_EDGE_POINTER(p->m_ptr);
    if (nullptr == e || nullptr == e->m_vertex[0] || nullptr == e->m_vertex[1])
      return false;
    ON__UINT_PTR edir = ON_SUBD_EDGE_DIRECTION(p->m_ptr);
    const ON_SubDVertex* v0 = e->m_vertex[edir];
    const ON_SubDVertex* v1 = e->m_vertex[1 - edir];
    if (v0 != v || nullptr == v1 || v0 == v1)
      return false;
    v = v1;
  }

  if (bCheckForDuplicateEdges)
  {
    const ON_SubDVertex* last_vertex = v;
    ON_UniqueTester tester;
    for (const ON_SubDEdgePtr* p = p0; p < p1; ++p)
    {
      const ON_SubDEdge* e = ON_SUBD_EDGE_POINTER(p->m_ptr);
      if (false == tester.AddToList((ON__UINT_PTR)e))
        return false; // duplicate edge
      if (false == tester.AddToList((ON__UINT_PTR)e->m_vertex[ON_SUBD_EDGE_DIRECTION(p->m_ptr)]))
        return false; // duplicate vertex
    }    
    if (first_vertex != last_vertex)
    {
      if (false == tester.AddToList((ON__UINT_PTR)last_vertex))
        return false; // duplicate vertex
    }
  }

  return true;
}

class ON_SubDLimitMeshImpl* ON_SubDLimitMesh::SubLimple() const
{
  return m_impl_sp.get();
}

unsigned int ON_SubDLimitMesh::SubLimpleUseCount() const
{
  return (unsigned int)(m_impl_sp.use_count());
}


#if defined(ON_SUBD_CENSUS)
//////////////////////////////////////////////////////////////////////////
//
// ON_CensusCounter
//


class ON_PointerHashElement
{
public:
  ON__UINT_PTR m_sn = 0;
  ON__UINT_PTR m_ptr = 0;
  ON_PointerHashElement* m_next = nullptr;
};

class ON_PointerHashTable
{
public:

  void Add(ON_CensusCounter::Class c, ON__UINT_PTR ptr);
  void Remove(ON_CensusCounter::Class c, ON__UINT_PTR ptr);

  ON__UINT_PTR SerialNumber(ON_CensusCounter::Class c, ON__UINT_PTR ptr) const;
  
  enum 
  {
    hash_count = 1024
  };
  ON_PointerHashElement* m_table[(unsigned int)ON_CensusCounter::Class::count][hash_count];


  unsigned int m_count = 0;


  static bool TheOneExists();
  static ON_PointerHashTable* TheOne();
  static void DestroyTheOne();

private:
  ON_PointerHashTable();
  ~ON_PointerHashTable();
  ON_PointerHashTable(const ON_PointerHashTable&) = delete;
  ON_PointerHashTable& operator=(const ON_PointerHashTable&) = delete;

  static unsigned int PointerHash(ON__UINT_PTR ptr);
  ON_FixedSizePool m_fsp;
  static ON_PointerHashTable* m_the_one;
};

ON_PointerHashTable* ON_PointerHashTable::m_the_one = nullptr;

ON_PointerHashTable::ON_PointerHashTable()
{
  memset(m_table,0,sizeof(m_table));
  m_fsp.Create(sizeof(ON_PointerHashElement),0,0);
}

ON_PointerHashTable::~ON_PointerHashTable()
{
  memset(m_table,0,sizeof(m_table));
  m_count = 0;
  m_fsp.Destroy();
}

bool ON_PointerHashTable::TheOneExists()
{
  return (nullptr != ON_PointerHashTable::m_the_one);
}

ON_PointerHashTable* ON_PointerHashTable::TheOne()
{
  if (nullptr == ON_PointerHashTable::m_the_one)
  {
    ON_PointerHashTable::m_the_one = new ON_PointerHashTable();
  }
  return ON_PointerHashTable::m_the_one;
}

void ON_PointerHashTable::DestroyTheOne()
{
  if (nullptr != ON_PointerHashTable::m_the_one)
  {
    delete ON_PointerHashTable::m_the_one;
    ON_PointerHashTable::m_the_one = nullptr;
  }
}

unsigned int ON_PointerHashTable::PointerHash(ON__UINT_PTR ptr)
{
  return (ON_CRC32(0, sizeof(ptr),&ptr) % ON_PointerHashTable::hash_count);
}

void ON_PointerHashTable::Add(ON_CensusCounter::Class c, ON__UINT_PTR ptr)
{
  static ON__UINT_PTR sn = 0;
  // not thread safe - a crude debugging tool
  ON_PointerHashElement* phe = (ON_PointerHashElement*)m_fsp.AllocateDirtyElement();
  phe->m_sn = ++sn;
  phe->m_ptr = ptr;
  const unsigned int hash_dex = ON_PointerHashTable::PointerHash(ptr);
  phe->m_next = m_table[(unsigned int)c][hash_dex];
  m_table[(unsigned int)c][hash_dex] = phe;
  m_count++;
}

void ON_PointerHashTable::Remove(ON_CensusCounter::Class c, ON__UINT_PTR ptr)
{
  const unsigned int hash_dex = ON_PointerHashTable::PointerHash(ptr);
  ON_PointerHashElement* phe = m_table[(unsigned int)c][hash_dex];
  for (ON_PointerHashElement* phe0 = nullptr; nullptr != phe; phe = phe->m_next)
  {
    if (ptr == phe->m_ptr)
    {
      if ( nullptr == phe0 )
        m_table[(unsigned int)c][hash_dex] = phe->m_next;
      else
        phe0 = phe->m_next;
      m_fsp.ReturnElement(phe);
      m_count--;
      return;
    }
    phe0 = phe;
  }
  // pointer not in the table
  ON_SubDIncrementErrorCount();
  return;
}


ON__UINT_PTR ON_PointerHashTable::SerialNumber(ON_CensusCounter::Class c, ON__UINT_PTR ptr) const
{
  const unsigned int hash_dex = ON_PointerHashTable::PointerHash(ptr);
  for ( ON_PointerHashElement* phe = m_table[(unsigned int)c][hash_dex]; nullptr != phe; phe = phe->m_next)
  {
    if (ptr == phe->m_ptr)
      return phe->m_sn;
  }
  // pointer not in the table
  return 0;
}

void ON_CensusCounter::RegisterBirth(ON_CensusCounter::Class c, ON__UINT_PTR ptr)
{
  ON_PointerHashTable::TheOne()->Add(c,ptr);
}

void ON_CensusCounter::RegisterDeath(ON_CensusCounter::Class c, ON__UINT_PTR ptr)
{
  ON_PointerHashTable::TheOne()->Remove(c,ptr);
}


void ON_CensusCounter::Clear()
{
  ON_PointerHashTable::DestroyTheOne();
}

void ON_CensusCounter::CensusReport(
  class ON_TextLog& text_log
  )
{
  ON_PointerHashTable* ht = ON_PointerHashTable::TheOneExists() ? ON_PointerHashTable::TheOne() : nullptr;
  if ( nullptr == ht )
  {
    text_log.Print("No class census information exists.\n");
    return;
  }

  text_log.Print("%d items exist.\n",ht->m_count);
  for (unsigned int i = 0; i < (unsigned int)ON_CensusCounter::Class::count; i++)
  {
    bool bPrintClassName = true;
    const char* sClassName = nullptr;
    const ON_CensusCounter::Class c = (ON_CensusCounter::Class)i;
    switch (c)
    {
    case ON_CensusCounter::Class::subd:
      sClassName = "ON_SubD";
      break;
    case ON_CensusCounter::Class::subd_impl:
      sClassName = "ON_SubDimple";
      break;
    case ON_CensusCounter::Class::subd_limit_mesh:
      sClassName = "ON_SubDLimitMesh";
      break;
    case ON_CensusCounter::Class::subd_limit_mesh_impl:
      sClassName = "ON_SubDLimitMeshImpl";
      break;
    case ON_CensusCounter::Class::subd_ref:
      sClassName = "ON_SubDef";
      break;
    default:
      sClassName = "Bug in ON_CensusCounter";
      break;
    }

    for (unsigned int j = 0; j < ON_PointerHashTable::hash_count; j++)
    {
      for (ON_PointerHashElement* e = ht->m_table[i][j]; nullptr != e; e = e->m_next)
      {
        const unsigned int sn = (unsigned int)e->m_sn;

        if (bPrintClassName)
        {
          text_log.Print("\n\n%s census:\n",sClassName);
          bPrintClassName = false;
        }

        switch (c)
        {
        case ON_CensusCounter::Class::subd:
          {
            const ON_SubD* subd = (const ON_SubD*)e->m_ptr;
            if ( subd == &ON_SubD::Empty )
              text_log.Print("ON_SubD::Empty (%u) ", sn);
            else
              text_log.Print("ON_SubD(%u) ", sn);
            const ON_SubDimple* dimple = subd->SubDimple();
            if ( nullptr == dimple )
              text_log.Print(" ON_SubDimple(nullptr)\n");
            else
            {
              unsigned int dimple_sn = (unsigned int)ht->SerialNumber(ON_CensusCounter::Class::subd_impl, (ON__UINT_PTR)dimple);
              text_log.Print(" ON_SubDimple(%u)x%u\n", dimple_sn, subd->SubDimpleUseCount());
            }            
          }
          break;

        case ON_CensusCounter::Class::subd_impl:
          {
           text_log.Print("ON_SubDimple(%u)\n", sn);
          }
          break;

        case ON_CensusCounter::Class::subd_limit_mesh:
          {
            const ON_SubDLimitMesh* subd_limit_mesh = (const ON_SubDLimitMesh*)e->m_ptr;
            if ( subd_limit_mesh == &ON_SubDLimitMesh::Empty )
              text_log.Print("ON_SubDLimitMesh::Empty (%u) ", sn);
            else
              text_log.Print("ON_SubDLimitMesh(%u) ", sn);
            const class ON_SubDLimitMeshImpl* limple = subd_limit_mesh->SubLimple();
            if ( nullptr == limple )
              text_log.Print(" ON_SubDLimitMeshImpl(nullptr)\n");
            else
            {
              unsigned int limple_sn = (unsigned int)ht->SerialNumber(ON_CensusCounter::Class::subd_limit_mesh_impl, (ON__UINT_PTR)limple);
              text_log.Print(" ON_SubDLimitMeshImpl(%u)x%u\n", limple_sn, subd_limit_mesh->SubLimpleUseCount());
            }            
          }
          break;

        case ON_CensusCounter::Class::subd_limit_mesh_impl:
          {
            const ON_SubDLimitMeshImpl* subd_limple = (const ON_SubDLimitMeshImpl*)e->m_ptr;
            text_log.Print("ON_SubDLimitMeshImpl(%u)", sn);

            std::shared_ptr<ON_SubDimple> limple_sp(subd_limple->m_subdimple_wp.lock());
            const ON_SubDimple* dimple = limple_sp.get();
            if ( nullptr == dimple )
              text_log.Print(" ON_SubDimple(nullpr)\n");
            else
            {
              unsigned int dimple_sn = (unsigned int)ht->SerialNumber(ON_CensusCounter::Class::subd_impl, (ON__UINT_PTR)dimple);
              text_log.Print(" ON_SubDimple(%u)x%u+1\n", dimple_sn, (unsigned int)(limple_sp.use_count()-1));
            }            

          }
          break;

        case ON_CensusCounter::Class::subd_ref:
          {
            const ON_SubDRef* subd_ref = (const ON_SubDRef*)e->m_ptr;
            const ON_SubD* subd = &subd_ref->SubD();
            ON__UINT_PTR subd_sn = ht->SerialNumber(ON_CensusCounter::Class::subd, (ON__UINT_PTR)subd);
            text_log.Print("ON_SubDRef(%u) ON_SubD(%u)x%u\n", sn, subd_sn, subd_ref->ReferenceCount());
          }
          break;
        }
      }
    }
  }
}


static ON__UINT_PTR ON_SubDCensusCounter_This(ON_SubDCensusCounter* p)
{
  const ON_SubD* pSubD = (const ON_SubD*)((unsigned char*)p - sizeof(ON_Geometry));
  return (ON__UINT_PTR)pSubD;
}

ON_SubDCensusCounter::ON_SubDCensusCounter() ON_NOEXCEPT
{
  ON_CensusCounter::RegisterBirth(ON_CensusCounter::Class::subd,ON_SubDCensusCounter_This(this));
}

ON_SubDCensusCounter::~ON_SubDCensusCounter() ON_NOEXCEPT
{
  ON_CensusCounter::RegisterDeath(ON_CensusCounter::Class::subd,ON_SubDCensusCounter_This(this));
}

ON_SubDCensusCounter::ON_SubDCensusCounter(const ON_SubDCensusCounter&) ON_NOEXCEPT
{
  ON_CensusCounter::RegisterBirth(ON_CensusCounter::Class::subd,ON_SubDCensusCounter_This(this));
}

ON_SubDRefCensusCounter::ON_SubDRefCensusCounter() ON_NOEXCEPT
{
  ON_CensusCounter::RegisterBirth(ON_CensusCounter::Class::subd_ref,(ON__UINT_PTR)this);
}

ON_SubDRefCensusCounter::~ON_SubDRefCensusCounter() ON_NOEXCEPT
{
  ON_CensusCounter::RegisterDeath(ON_CensusCounter::Class::subd_ref,(ON__UINT_PTR)this);
}

ON_SubDRefCensusCounter::ON_SubDRefCensusCounter(const ON_SubDRefCensusCounter&) ON_NOEXCEPT
{
  ON_CensusCounter::RegisterBirth(ON_CensusCounter::Class::subd_ref,(ON__UINT_PTR)this);
}


ON_SubDImpleCensusCounter::ON_SubDImpleCensusCounter() ON_NOEXCEPT
{
  ON_CensusCounter::RegisterBirth(ON_CensusCounter::Class::subd_impl,(ON__UINT_PTR)this);
}

ON_SubDImpleCensusCounter::~ON_SubDImpleCensusCounter() ON_NOEXCEPT
{
  ON_CensusCounter::RegisterDeath(ON_CensusCounter::Class::subd_impl,(ON__UINT_PTR)this);
}

ON_SubDImpleCensusCounter::ON_SubDImpleCensusCounter(const ON_SubDImpleCensusCounter&) ON_NOEXCEPT
{
  ON_CensusCounter::RegisterBirth(ON_CensusCounter::Class::subd_impl,(ON__UINT_PTR)this);
}



ON_SubDLimitMeshCensusCounter::ON_SubDLimitMeshCensusCounter() ON_NOEXCEPT
{
  ON_CensusCounter::RegisterBirth(ON_CensusCounter::Class::subd_limit_mesh,(ON__UINT_PTR)this);
}

ON_SubDLimitMeshCensusCounter::~ON_SubDLimitMeshCensusCounter() ON_NOEXCEPT
{
  ON_CensusCounter::RegisterDeath(ON_CensusCounter::Class::subd_limit_mesh,(ON__UINT_PTR)this);
}

ON_SubDLimitMeshCensusCounter::ON_SubDLimitMeshCensusCounter(const ON_SubDLimitMeshCensusCounter&) ON_NOEXCEPT
{
  ON_CensusCounter::RegisterBirth(ON_CensusCounter::Class::subd_limit_mesh,(ON__UINT_PTR)this);
}




ON_SubDLimitMeshImplCensusCounter::ON_SubDLimitMeshImplCensusCounter() ON_NOEXCEPT
{
  ON_CensusCounter::RegisterBirth(ON_CensusCounter::Class::subd_limit_mesh_impl,(ON__UINT_PTR)this);
}

ON_SubDLimitMeshImplCensusCounter::~ON_SubDLimitMeshImplCensusCounter() ON_NOEXCEPT
{
  ON_CensusCounter::RegisterDeath(ON_CensusCounter::Class::subd_limit_mesh_impl,(ON__UINT_PTR)this);
}

ON_SubDLimitMeshImplCensusCounter::ON_SubDLimitMeshImplCensusCounter(const ON_SubDLimitMeshImplCensusCounter&) ON_NOEXCEPT
{
  ON_CensusCounter::RegisterBirth(ON_CensusCounter::Class::subd_limit_mesh_impl,(ON__UINT_PTR)this);
}

#endif

#endif
