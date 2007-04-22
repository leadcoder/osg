// ***************************************************************************
//
//   Generated automatically by genwrapper.
//   Please DO NOT EDIT this file!
//
// ***************************************************************************

#include <osgIntrospection/ReflectionMacros>
#include <osgIntrospection/TypedMethodInfo>
#include <osgIntrospection/StaticMethodInfo>
#include <osgIntrospection/Attributes>

#include <osg/BoundingBox>
#include <osg/CopyOp>
#include <osg/Drawable>
#include <osg/Object>
#include <osg/PrimitiveSet>
#include <osg/RenderInfo>
#include <osg/Shape>
#include <osg/ShapeDrawable>
#include <osg/Vec4>

// Must undefine IN and OUT macros defined in Windows headers
#ifdef IN
#undef IN
#endif
#ifdef OUT
#undef OUT
#endif

BEGIN_OBJECT_REFLECTOR(osg::ShapeDrawable)
	I_BaseType(osg::Drawable);
	I_Constructor0(____ShapeDrawable,
	               "",
	               "");
	I_ConstructorWithDefaults2(IN, osg::Shape *, shape, , IN, osg::TessellationHints *, hints, 0,
	                           ____ShapeDrawable__Shape_P1__TessellationHints_P1,
	                           "",
	                           "");
	I_ConstructorWithDefaults2(IN, const osg::ShapeDrawable &, pg, , IN, const osg::CopyOp &, copyop, osg::CopyOp::SHALLOW_COPY,
	                           ____ShapeDrawable__C5_ShapeDrawable_R1__C5_CopyOp_R1,
	                           "Copy constructor using CopyOp to manage deep vs shallow copy. ",
	                           "");
	I_Method0(osg::Object *, cloneType,
	          Properties::VIRTUAL,
	          __Object_P1__cloneType,
	          "Clone the type of an object, with Object* return type. ",
	          "Must be defined by derived classes. ");
	I_Method1(osg::Object *, clone, IN, const osg::CopyOp &, copyop,
	          Properties::VIRTUAL,
	          __Object_P1__clone__C5_CopyOp_R1,
	          "Clone an object, with Object* return type. ",
	          "Must be defined by derived classes. ");
	I_Method1(bool, isSameKindAs, IN, const osg::Object *, obj,
	          Properties::VIRTUAL,
	          __bool__isSameKindAs__C5_Object_P1,
	          "",
	          "");
	I_Method0(const char *, libraryName,
	          Properties::VIRTUAL,
	          __C5_char_P1__libraryName,
	          "return the name of the object's library. ",
	          "Must be defined by derived classes. The OpenSceneGraph convention is that the namespace of a library is the same as the library name. ");
	I_Method0(const char *, className,
	          Properties::VIRTUAL,
	          __C5_char_P1__className,
	          "return the name of the object's class type. ",
	          "Must be defined by derived classes. ");
	I_Method1(void, setColor, IN, const osg::Vec4 &, color,
	          Properties::NON_VIRTUAL,
	          __void__setColor__C5_Vec4_R1,
	          "Set the color of the shape. ",
	          "");
	I_Method0(const osg::Vec4 &, getColor,
	          Properties::NON_VIRTUAL,
	          __C5_Vec4_R1__getColor,
	          "Get the color of the shape. ",
	          "");
	I_Method1(void, setTessellationHints, IN, osg::TessellationHints *, hints,
	          Properties::NON_VIRTUAL,
	          __void__setTessellationHints__TessellationHints_P1,
	          "",
	          "");
	I_Method0(osg::TessellationHints *, getTessellationHints,
	          Properties::NON_VIRTUAL,
	          __TessellationHints_P1__getTessellationHints,
	          "",
	          "");
	I_Method0(const osg::TessellationHints *, getTessellationHints,
	          Properties::NON_VIRTUAL,
	          __C5_TessellationHints_P1__getTessellationHints,
	          "",
	          "");
	I_Method1(void, drawImplementation, IN, osg::RenderInfo &, renderInfo,
	          Properties::VIRTUAL,
	          __void__drawImplementation__RenderInfo_R1,
	          "Draw ShapeDrawable directly ignoring an OpenGL display list which could be attached. ",
	          "This is the internal draw method which does the drawing itself, and is the method to override when deriving from ShapeDrawable for user-drawn objects.");
	I_Method1(bool, supports, IN, const osg::Drawable::AttributeFunctor &, x,
	          Properties::VIRTUAL,
	          __bool__supports__C5_AttributeFunctor_R1,
	          "Return false, osg::ShapeDrawable does not support accept(AttributeFunctor&). ",
	          "");
	I_Method1(bool, supports, IN, const osg::Drawable::ConstAttributeFunctor &, x,
	          Properties::VIRTUAL,
	          __bool__supports__C5_Drawable_ConstAttributeFunctor_R1,
	          "Return true, osg::ShapeDrawable does support accept(Drawable::ConstAttributeFunctor&). ",
	          "");
	I_Method1(void, accept, IN, osg::Drawable::ConstAttributeFunctor &, af,
	          Properties::VIRTUAL,
	          __void__accept__Drawable_ConstAttributeFunctor_R1,
	          "Accept a Drawable::ConstAttributeFunctor and call its methods to tell it about the interal attributes that this Drawable has. ",
	          "");
	I_Method1(bool, supports, IN, const osg::PrimitiveFunctor &, x,
	          Properties::VIRTUAL,
	          __bool__supports__C5_PrimitiveFunctor_R1,
	          "Return true, osg::ShapeDrawable does support accept(PrimitiveFunctor&) . ",
	          "");
	I_Method1(void, accept, IN, osg::PrimitiveFunctor &, pf,
	          Properties::VIRTUAL,
	          __void__accept__PrimitiveFunctor_R1,
	          "Accept a PrimitiveFunctor and call its methods to tell it about the internal primitives that this Drawable has. ",
	          "");
	I_Method0(osg::BoundingBox, computeBound,
	          Properties::VIRTUAL,
	          __BoundingBox__computeBound,
	          "Compute the bounding box around Drawables's geometry. ",
	          "");
	I_SimpleProperty(const osg::Vec4 &, Color, 
	                 __C5_Vec4_R1__getColor, 
	                 __void__setColor__C5_Vec4_R1);
	I_SimpleProperty(osg::TessellationHints *, TessellationHints, 
	                 __TessellationHints_P1__getTessellationHints, 
	                 __void__setTessellationHints__TessellationHints_P1);
END_REFLECTOR

BEGIN_ENUM_REFLECTOR(osg::TessellationHints::TessellationMode)
	I_EnumLabel(osg::TessellationHints::USE_SHAPE_DEFAULTS);
	I_EnumLabel(osg::TessellationHints::USE_TARGET_NUM_FACES);
END_REFLECTOR

BEGIN_OBJECT_REFLECTOR(osg::TessellationHints)
	I_BaseType(osg::Object);
	I_Constructor0(____TessellationHints,
	               "",
	               "");
	I_ConstructorWithDefaults2(IN, const osg::TessellationHints &, tess, , IN, const osg::CopyOp &, copyop, osg::CopyOp::SHALLOW_COPY,
	                           ____TessellationHints__C5_TessellationHints_R1__C5_CopyOp_R1,
	                           "",
	                           "");
	I_Method0(osg::Object *, cloneType,
	          Properties::VIRTUAL,
	          __osg_Object_P1__cloneType,
	          "Clone the type of an object, with Object* return type. ",
	          "Must be defined by derived classes. ");
	I_Method1(osg::Object *, clone, IN, const osg::CopyOp &, copyop,
	          Properties::VIRTUAL,
	          __osg_Object_P1__clone__C5_osg_CopyOp_R1,
	          "Clone an object, with Object* return type. ",
	          "Must be defined by derived classes. ");
	I_Method1(bool, isSameKindAs, IN, const osg::Object *, obj,
	          Properties::VIRTUAL,
	          __bool__isSameKindAs__C5_osg_Object_P1,
	          "",
	          "");
	I_Method0(const char *, libraryName,
	          Properties::VIRTUAL,
	          __C5_char_P1__libraryName,
	          "return the name of the object's library. ",
	          "Must be defined by derived classes. The OpenSceneGraph convention is that the namespace of a library is the same as the library name. ");
	I_Method0(const char *, className,
	          Properties::VIRTUAL,
	          __C5_char_P1__className,
	          "return the name of the object's class type. ",
	          "Must be defined by derived classes. ");
	I_Method1(void, setTessellationMode, IN, osg::TessellationHints::TessellationMode, mode,
	          Properties::NON_VIRTUAL,
	          __void__setTessellationMode__TessellationMode,
	          "",
	          "");
	I_Method0(osg::TessellationHints::TessellationMode, getTessellationMode,
	          Properties::NON_VIRTUAL,
	          __TessellationMode__getTessellationMode,
	          "",
	          "");
	I_Method1(void, setDetailRatio, IN, float, ratio,
	          Properties::NON_VIRTUAL,
	          __void__setDetailRatio__float,
	          "",
	          "");
	I_Method0(float, getDetailRatio,
	          Properties::NON_VIRTUAL,
	          __float__getDetailRatio,
	          "",
	          "");
	I_Method1(void, setTargetNumFaces, IN, unsigned int, target,
	          Properties::NON_VIRTUAL,
	          __void__setTargetNumFaces__unsigned_int,
	          "",
	          "");
	I_Method0(unsigned int, getTargetNumFaces,
	          Properties::NON_VIRTUAL,
	          __unsigned_int__getTargetNumFaces,
	          "",
	          "");
	I_Method1(void, setCreateFrontFace, IN, bool, on,
	          Properties::NON_VIRTUAL,
	          __void__setCreateFrontFace__bool,
	          "",
	          "");
	I_Method0(bool, getCreateFrontFace,
	          Properties::NON_VIRTUAL,
	          __bool__getCreateFrontFace,
	          "",
	          "");
	I_Method1(void, setCreateBackFace, IN, bool, on,
	          Properties::NON_VIRTUAL,
	          __void__setCreateBackFace__bool,
	          "",
	          "");
	I_Method0(bool, getCreateBackFace,
	          Properties::NON_VIRTUAL,
	          __bool__getCreateBackFace,
	          "",
	          "");
	I_Method1(void, setCreateNormals, IN, bool, on,
	          Properties::NON_VIRTUAL,
	          __void__setCreateNormals__bool,
	          "",
	          "");
	I_Method0(bool, getCreateNormals,
	          Properties::NON_VIRTUAL,
	          __bool__getCreateNormals,
	          "",
	          "");
	I_Method1(void, setCreateTextureCoords, IN, bool, on,
	          Properties::NON_VIRTUAL,
	          __void__setCreateTextureCoords__bool,
	          "",
	          "");
	I_Method0(bool, getCreateTextureCoords,
	          Properties::NON_VIRTUAL,
	          __bool__getCreateTextureCoords,
	          "",
	          "");
	I_Method1(void, setCreateTop, IN, bool, on,
	          Properties::NON_VIRTUAL,
	          __void__setCreateTop__bool,
	          "",
	          "");
	I_Method0(bool, getCreateTop,
	          Properties::NON_VIRTUAL,
	          __bool__getCreateTop,
	          "",
	          "");
	I_Method1(void, setCreateBody, IN, bool, on,
	          Properties::NON_VIRTUAL,
	          __void__setCreateBody__bool,
	          "",
	          "");
	I_Method0(bool, getCreateBody,
	          Properties::NON_VIRTUAL,
	          __bool__getCreateBody,
	          "",
	          "");
	I_Method1(void, setCreateBottom, IN, bool, on,
	          Properties::NON_VIRTUAL,
	          __void__setCreateBottom__bool,
	          "",
	          "");
	I_Method0(bool, getCreateBottom,
	          Properties::NON_VIRTUAL,
	          __bool__getCreateBottom,
	          "",
	          "");
	I_SimpleProperty(bool, CreateBackFace, 
	                 __bool__getCreateBackFace, 
	                 __void__setCreateBackFace__bool);
	I_SimpleProperty(bool, CreateBody, 
	                 __bool__getCreateBody, 
	                 __void__setCreateBody__bool);
	I_SimpleProperty(bool, CreateBottom, 
	                 __bool__getCreateBottom, 
	                 __void__setCreateBottom__bool);
	I_SimpleProperty(bool, CreateFrontFace, 
	                 __bool__getCreateFrontFace, 
	                 __void__setCreateFrontFace__bool);
	I_SimpleProperty(bool, CreateNormals, 
	                 __bool__getCreateNormals, 
	                 __void__setCreateNormals__bool);
	I_SimpleProperty(bool, CreateTextureCoords, 
	                 __bool__getCreateTextureCoords, 
	                 __void__setCreateTextureCoords__bool);
	I_SimpleProperty(bool, CreateTop, 
	                 __bool__getCreateTop, 
	                 __void__setCreateTop__bool);
	I_SimpleProperty(float, DetailRatio, 
	                 __float__getDetailRatio, 
	                 __void__setDetailRatio__float);
	I_SimpleProperty(unsigned int, TargetNumFaces, 
	                 __unsigned_int__getTargetNumFaces, 
	                 __void__setTargetNumFaces__unsigned_int);
	I_SimpleProperty(osg::TessellationHints::TessellationMode, TessellationMode, 
	                 __TessellationMode__getTessellationMode, 
	                 __void__setTessellationMode__TessellationMode);
END_REFLECTOR

