/*
* Credo por Vertex Software el (20-02-2025)
* 
* Este archivo de encabezado tiene como objetivo definir macros para la gestion
* de versiones del codigo fuente de Vertex Engine
*
*
*/

#ifndef VX_VERSION_H
#define VX_VERSION_H


#include "VxAlias.h"

#define VX_MAKE_API_VERSION(variant, major, minor, patch) \
    ((((VxUint32)(variant)) << 29U) | (((VxUint32)(major)) << 22U) | (((VxUint32)(minor)) << 12U) | ((VxUint32)(patch)))

// Version variante
#define VX_API_VERSION_VARIANT(variant) ((VxUint32)(variant) >> 29U)
// Version major
#define VX_API_VERSION_MAJOR(major) (((VxUint32)(major) >> 22U) & 0x7FU)
// Version minor
#define VX_API_VERSION_MINOR(minor) (((VxUint32)(minor) >> 12U) & 0x3FFU)
// Version patch
#define VX_API_VERSION_PATCH(patch) ((VxUint32)(patch) & 0xFFFU)

// Version 1.0.0
#define VX_API_VERSION_1_0 VX_MAKE_API_VERSION(0, 1, 0, 0)



// Aumentar la flexibilidad de el manejo de versiones 

#define _VX_VERSION_ALPHA_ 0x80000000U // versiones beta
#define _VX_VERSION_BETA_  0x40000000U // Versiones alpha
#define _VX_VERSION_STABLE_ 0x20000000U // Versiones estables y mantenibles

#define VX_VERSION_TYPE _VX_VERSION_ALPHA_

// Para alfa y beta, puedes definir algo como:
#define VX_VERSION_ALPHA_VERSION _VX_VERSION_ALPHA_ | 0x00010000U
#define VX_VERSION_BETA_VERSION _VX_VERSION_BETA_ | 0x00020000U


#define VX_MAKE_API_VERSION_WITH_TYPE(variant, major, minor, patch, type) \
    ((((VxUint32)(variant)) << 29U) | (((VxUint32)(major)) << 22U) | (((VxUint32)(minor)) << 12U) | ((VxUint32)(patch)) | (type))


// ========================================================================
// Versiones de Vertex Engine
// ========================================================================


#define VX_VERSION_MAJOR 1 // Version major
#define VX_VERSION_MINOR 0 // Version minor
#define VX_VERSION_PATCH 0 // Version patch

// Manipulacion de versiones de vertex engine
#define __VERTEX_ENGINE_MAJOR__ VX_VERSION_MAJOR
#define __VERTEX_ENGINE_MINOR__ VX_VERSION_MINOR
#define __VERTEX_ENGINE_PATCH__ VX_VERSION_PATCH

#define __VERTEX_ENGINE_VER__   \
    (VX_VERSION_MAJOR * 10000 + VX_VERSION_MINOR * 100 + VX_VERSION_PATCH)


#define VX_ACTUAL_VERSION_VERTEX_STRINGIZE \
    VX_STRINGIZE(__VERTEX_ENGINE_MAJOR__) "." \
    VX_STRINGIZE(__VERTEX_ENGINE_MINOR__) "." \
    VX_STRINGIZE(__VERTEX_ENGINE_PATCH__)     \




#define _VX_VERIFY_VERTEX_VERSION_(_Version) (__VERTEX_ENGINE_VER__ >= (_Version))
//#define _VX_VERTEX_VERSION_1_0_0_STABLE VX_MAKE_API_VERSION_WITH_TYPE(1, 0, 0, _VX_VERSION_STABLE_)


// Version 1.0.0
#if _VX_VERIFY_VERTEX_VERSION_(10000)
    #define _VX_HAS_VERTEX_VERSION_1_0_0 1
#else
    #define _VX_HAS_VERTEX_VERSION_1_0_0 0
#endif


// Version 2.0.0
#if _VX_VERIFY_VERTEX_VERSION_(20000)
    #define _VX_HAS_VERTEX_VERSION_2_0_0 1
#else
    #define _VX_HAS_VERTEX_VERSION_2_0_0 0
#endif


// Version 3.0.0
#if _VX_VERIFY_VERTEX_VERSION_(30000)
    #define _VX_HAS_VERTEX_VERSION_3_0_0 1
#else
    #define _VX_HAS_VERTEX_VERSION_3_0_0 0
#endif


// Version 4.0.0
#if _VX_VERIFY_VERTEX_VERSION_(40000)
    #define _VX_HAS_VERTEX_VERSION_4_0_0 1
#else
    #define _VX_HAS_VERTEX_VERSION_4_0_0 0
#endif


// Version 5.0.0
#if _VX_VERIFY_VERTEX_VERSION_(20000)
    #define _VX_HAS_VERTEX_VERSION_5_0_0 1
#else
    #define _VX_HAS_VERTEX_VERSION_5_0_0 0
#endif


// Caracteristicas eliminadas en la version de vertex 2.0.0
#ifndef _VX_HAS_FEATURES_REMOVED_IN_VERTEX_VERSION_2_0_0
    #define _VX_HAS_FEATURES_REMOVED_IN_VERTEX_VERSION_2_0_0 (!_VX_HAS_VERTEX_VERSION_2_0_0)
#else
    #define _VX_HAS_FEATURES_REMOVED_IN_VERTEX_VERSION_2_0_0
#endif
#define VX_HAS_FEATURES_REMOVED_IN_VERTEX_VERSION_2_0_0 _VX_HAS_FEATURES_REMOVED_IN_VERTEX_VERSION_2_0_0


// Caracteristicas eliminadas en la version de vertex 3.0.0
#ifndef _VX_HAS_FEATURES_REMOVED_IN_VERTEX_VERSION_3_0_0
    #define _VX_HAS_FEATURES_REMOVED_IN_VERTEX_VERSION_3_0_0 (!_VX_HAS_VERTEX_VERSION_3_0_0)
#else
    #define _VX_HAS_FEATURES_REMOVED_IN_VERTEX_VERSION_3_0_0
#endif
#define VX_HAS_FEATURES_REMOVED_IN_VERTEX_VERSION_3_0_0 _VX_HAS_FEATURES_REMOVED_IN_VERTEX_VERSION_2_0_0




#endif