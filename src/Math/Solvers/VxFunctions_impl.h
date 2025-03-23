


#ifndef VX_FUNCTIONS_IMPL_H
#define VX_FUNCIONS_IMPL_H


#include "Core/VxPackCore.h"


#ifndef _VX_ABS_
	#define _VX_ABS_(x) ((x) < 0 ? -(x) : (x))
#else
	#define _VX_ABS_(x) 
#endif
#define VX_ABS(x) _VX_ABS_(x)


#ifndef _VX_MIN_
	#define _VX_MIN_(x, y) ((x < y) ? (x) : (y))
#else
	#define _VX_MIN_(x)
#endif
#define VX_MIN(x) _VX_MIN_(x)


#ifndef _VX_MAX_
	#define _VX_MAX_(x) ((x > y) ? (x) : (y))
#else
	#define _VX_MAX_(x)
#endif
#define VX_MAX(x) _VX_MAX_(x)


#ifndef _VX_IS_ODD_
	#define _VX_IS_ODD_(x) ((x) % 2 != 0)
#else
	#define _VX_IS_ODD_(x)
#endif
#define VX_IS_ODD(x) _VX_IS_ODD_(x)


#ifndef _VX_IS_EVEN_
	#define _VX_IS_EVEN_(x) ((X) % 2 == 0)
#else
	#define _VX_IS_EVEN_(x)
#endif
#define VX_IS_EVEN(x) _VX_IS_EVEN_(x)


#if VX_USE_CONSTEXPR
	#define _VX_CONSTEXPR VX_CONSTEXPR20
#else
	#define _VX_CONSTEXPR 
#endif


#if VX_USE_STATIC
	#define _VX_STATIC static
#else
	#define _VX_STATIC
#endif


#if VX_USE_INLINE
	#define _VX_INLINE VX_INLINE
#else
	#define _VX_INLINE 
#endif





VX_INTERNAL_BEGIN


VX_API _VX_STATIC _VX_INLINE 
_VX_CONSTEXPR VxInt8 __vx_absi8__(
	VxInt8										_Val
);

VX_API _VX_STATIC _VX_INLINE 
_VX_CONSTEXPR VxInt16 __vx_absi16__(
	VxInt16										_Val
);

VX_API _VX_STATIC _VX_INLINE 
_VX_CONSTEXPR VxInt32 __vx_absi32__(
	VxInt32										_Val
);

VX_API _VX_STATIC _VX_INLINE 
_VX_CONSTEXPR VxInt64 __vx_absi64__(
	VxInt64										_Val
);

VX_API _VX_STATIC _VX_INLINE 
_VX_CONSTEXPR VxUint8 __vx_absui8__(
	VxUint8										_Val
);

VX_API _VX_STATIC _VX_INLINE 
_VX_CONSTEXPR VxUint16 __vx_absui16__(
	VxUint16									_Val
);

VX_API _VX_STATIC _VX_INLINE 
_VX_CONSTEXPR VxUint32 __vx_absui32__(
	VxUint32									_Val
);

VX_API _VX_STATIC _VX_INLINE 
_VX_CONSTEXPR VxUint64 __vx_absui64__(
	VxUint64									_Val
);

VX_API _VX_STATIC _VX_INLINE 
_VX_CONSTEXPR VxFloat __vx_absf32__(
	VxFloat										_Val
);

VX_API _VX_STATIC _VX_INLINE 
_VX_CONSTEXPR VxDouble __vx_absf64__(
	VxDouble									_Val
);

VX_API _VX_STATIC _VX_INLINE 
_VX_CONSTEXPR VxLdouble __vx_absf80__(
	VxLdouble									_Val
);
 	    
 	    
VX_API _VX_STATIC _VX_INLINE 
_VX_CONSTEXPR VxInt8 __vx_mini8__(
	VxInt8										_Val1, 
	VxInt8										_Val2
);

VX_API _VX_STATIC _VX_INLINE 
_VX_CONSTEXPR VxInt16 __vx_mini16__(
	VxInt16										_Val1, 
	VxInt16										_Val2
);

VX_API _VX_STATIC _VX_INLINE 
_VX_CONSTEXPR VxInt32 __vx_mini32__(
	VxInt32										_Val1, 
	VxInt32										_Val2
);

VX_API _VX_STATIC _VX_INLINE 
_VX_CONSTEXPR VxInt64 __vx_mini64__(
	VxInt64										_Val1, 
	VxInt64										_Val2
);

VX_API _VX_STATIC _VX_INLINE 
_VX_CONSTEXPR VxUint8 __vx_minui8__(
	VxUint8										_Val1, 
	VxUint8										_Val2
);

VX_API _VX_STATIC _VX_INLINE 
_VX_CONSTEXPR VxUint16 __vx_minui16__(
	VxUint16									_Val1, 
	VxUint16									_Val2
);

VX_API _VX_STATIC _VX_INLINE 
_VX_CONSTEXPR VxUint32 __vx_minui32__(
	VxUint32									_Val1, 
	VxUint32									_Val2
);

VX_API _VX_STATIC _VX_INLINE 
_VX_CONSTEXPR VxUint64 __vx_minui64__(
	VxUint64									_Val1, 
	VxUint64									_Val2
);

VX_API _VX_STATIC _VX_INLINE 
_VX_CONSTEXPR VxFloat __vx_minf32__(
	VxFloat										_Val1,
	VxFloat										_Val2
);

VX_API _VX_STATIC _VX_INLINE 
_VX_CONSTEXPR VxDouble __vx_minf64__(
	VxDouble									_Val1, 
	VxDouble									_Val2
);

VX_API _VX_STATIC _VX_INLINE 
_VX_CONSTEXPR VxLdouble __vx_minf80__(
	VxLdouble									_Val1, 
	VxLdouble									_Val2
);
 	    
 	    
VX_API _VX_STATIC _VX_INLINE 
_VX_CONSTEXPR VxInt8 __vx_maxi8__(VxInt8 _Val);

VX_API _VX_STATIC _VX_INLINE 
_VX_CONSTEXPR VxInt16 __vx_maxi16__(VxInt16 _Val);
VX_API _VX_STATIC _VX_INLINE 
_VX_CONSTEXPR VxInt32 __vx_maxi32__(VxInt32 _Val);

VX_API _VX_STATIC _VX_INLINE 
_VX_CONSTEXPR VxInt64 __vx_maxi64__(VxInt64 _Val);

VX_API _VX_STATIC _VX_INLINE 
_VX_CONSTEXPR VxUint8 __vx_maxui8__(VxUint8 _Val);

VX_API _VX_STATIC _VX_INLINE 
_VX_CONSTEXPR VxUint16 __vx_maxui16__(VxUint16 _Val);

VX_API _VX_STATIC _VX_INLINE 
_VX_CONSTEXPR VxUint32 __vx_maxui32__(VxUint32 _Val);

VX_API _VX_STATIC _VX_INLINE 
_VX_CONSTEXPR VxUint64 __vx_maxui64__(VxUint64 _Val);

VX_API _VX_STATIC _VX_INLINE 
_VX_CONSTEXPR VxFloat __vx_maxf32__(VxFloat _Val);

VX_API _VX_STATIC _VX_INLINE 
_VX_CONSTEXPR VxDouble __vx_maxf64__(VxDouble _Val);

VX_API _VX_STATIC _VX_INLINE 
_VX_CONSTEXPR VxLdouble __vx_maxf80__(VxLdouble _Val);
 	    
 	    
VX_API _VX_STATIC _VX_INLINE 
_VX_CONSTEXPR VxBool __vx_is_eveni8__(VxInt8 _Val);

VX_API _VX_STATIC _VX_INLINE 
_VX_CONSTEXPR VxBool __vx_is_eveni16__(VxInt16 _Val);

VX_API _VX_STATIC _VX_INLINE 
_VX_CONSTEXPR VxBool __vx_is_eveni32__(VxInt32 _Val);

VX_API _VX_STATIC _VX_INLINE 
_VX_CONSTEXPR VxBool __vx_is_eveni64__(VxInt64 _Val);

 	    
VX_API _VX_STATIC _VX_INLINE 
_VX_CONSTEXPR VxBool __vx_is_evenui8__(VxUint8 _Val);

VX_API _VX_STATIC _VX_INLINE 
_VX_CONSTEXPR VxBool __vx_is_evenui16__(VxUint16 _Val);

VX_API _VX_STATIC _VX_INLINE 
_VX_CONSTEXPR VxBool __vx_is_evenui32__(VxUint32 _Val);

VX_API _VX_STATIC _VX_INLINE 
_VX_CONSTEXPR VxBool __vx_is_evenui64__(VxUint64 _Val);
	    
	    
VX_API _VX_STATIC _VX_INLINE 
_VX_CONSTEXPR VxBool __vx_is_oddi8__(VxInt8 _Val);

VX_API _VX_STATIC _VX_INLINE 
_VX_CONSTEXPR VxBool __vx_is_oddi16__(VxInt16 _Val);

VX_API _VX_STATIC _VX_INLINE 
_VX_CONSTEXPR VxBool __vx_is_oddi32__(VxInt32 _Val);

VX_API _VX_STATIC _VX_INLINE 
_VX_CONSTEXPR VxBool __vx_is_oddi64__(VxInt64 _Val);
 	    
VX_API _VX_STATIC _VX_INLINE 
_VX_CONSTEXPR VxBool __vx_is_oddui8__(VxUint8 _Val);

VX_API _VX_STATIC _VX_INLINE 
_VX_CONSTEXPR VxBool __vx_is_oddui16__(VxUint16 _Val);

VX_API _VX_STATIC _VX_INLINE 
_VX_CONSTEXPR VxBool __vx_is_oddui32__(VxUint32 _Val);

VX_API _VX_STATIC _VX_INLINE 
_VX_CONSTEXPR VxBool __vx_is_oddui64__(VxUint64 _Val);



VX_INTERNAL_END




#endif