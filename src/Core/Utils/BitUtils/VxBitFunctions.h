/*
*
* 
* 
* 
* 
* 
* 
* 
* 
* 
* 
* 
*/

#ifndef VX_BIT_IMPL_H
#define VX_BIT_IMPL_H





#define VX_BUILD_DLL
#include "../../VxPackCore.h"
#include "VxBit.h"


#if (VX_USE_INLINE && VX_USE_CONSTEXPR)
	#define _VX_INLINE VX_INLINE17
	#define _VX_CONSTEXPR VX_CONSTEXPR20
#elif ((VX_USE_CONSTEXPR == 0) && (VX_USE_INLINE == 1))
	#define _VX_INLINE VX_INLINE17
	#define _VX_CONSTEXPR 
#elif ((VX_USE_CONSTEXPR == 1) && (VX_USE_INLINE == 0))
	#define _VX_INLINE 
	#define _VX_CONSTEXPR VX_CONSTEXPR20
#else
	#define _VX_INLINE 
	#define _VX_CONSTEXPR 
#endif


//VX_API _VX_CONSTEXPR _VX_INLINE VxUint32 __vx_bit_and__();
//VX_API _VX_CONSTEXPR _VX_INLINE VxUint32 __vx_bit_or__();
//VX_API _VX_CONSTEXPR _VX_INLINE VxUint32 __vx_bit_xor__();
//VX_API _VX_CONSTEXPR _VX_INLINE VxUint32 __vx_bit_not__();
VX_API _VX_CONSTEXPR _VX_INLINE VxUint32 __vx_bit_left_shift__(VxUint32 _Val, VxUint32 _Pos);
VX_API _VX_CONSTEXPR _VX_INLINE VxUint32 __vx_bit_right_shift__(VxUint32 _Val, VxUint32 _Pos);
VX_API _VX_CONSTEXPR _VX_INLINE VxUint32 __vx_bit_set__(VxUint32 _Val, VxUint32 _Pos);
VX_API _VX_CONSTEXPR _VX_INLINE VxUint32 __vx_bit_clear__(VxUint32 _Val, VxUint32 _Pos);
VX_API _VX_CONSTEXPR _VX_INLINE VxUint32 __vx_bit_toggle__(VxUint32 _Val, VxUint32 _Pos);
VX_API _VX_CONSTEXPR _VX_INLINE VxUint32 __vx_get_bit__(VxUint32 _Val, VxUint32 _Pos);
VX_API _VX_CONSTEXPR _VX_INLINE VxUint32 __vx_bit_check__(VxUint32 _Val, VxUint32 _Pos);
VX_API _VX_CONSTEXPR _VX_INLINE VxUint32 __vx_bit_set_mask__(VxUint32 _Val, VxUint32 _Mask);
VX_API _VX_CONSTEXPR _VX_INLINE VxUint32 __vx_bit_clear_mask__(VxUint32 _Val, VxUint32 _Mask);
VX_API _VX_CONSTEXPR _VX_INLINE VxUint32 __vx_bit_rotate_left__(VxUint32 _Val, VxUint32 _Pos);
VX_API _VX_CONSTEXPR _VX_INLINE VxUint32 __vx_bit_rotate_right__(VxUint32 _Val, VxUint32 _Pos);
VX_API _VX_CONSTEXPR _VX_INLINE VxUint32 __vx_count_ones__(VxUint32 _Val);
VX_API _VX_CONSTEXPR _VX_INLINE VxUint32 __vx_find_msb__(VxUint32 _Val);
VX_API _VX_CONSTEXPR _VX_INLINE VxUint32 __vx_find_lsb__(VxUint32 _Val);



#undef VX_BUILD_DLL


#endif