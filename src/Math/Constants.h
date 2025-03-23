



#ifndef VX_CONSTANTS_H
#define VX_CONSTANTS_H

#include "../src/Core/VxPackCore.h"




#if defined(VX_CPLUSPLUS)



VX_CONSTEXPR20 VxFloat VX_PI		=	3.14159265f;   
VX_CONSTEXPR20 VxFloat VX_TAU		=	6.28318530f;  // 2 * PI 
VX_CONSTEXPR20 VxFloat VX_E			=	2.71828183f;  // Numero de Euler 
VX_CONSTEXPR20 VxFloat VX_PHI		=	1.61803398f;  // Proporción áurea 
VX_CONSTEXPR20 VxFloat VX_SQRT2		=	1.41421356f;  // Raíz cuadrada de 2 
VX_CONSTEXPR20 VxFloat VX_SQRT3		=	1.73205081f;  // Raíz cuadrada de 3 
VX_CONSTEXPR20 VxFloat VX_SQRT5		=	2.23606798f;  // Raíz cuadrada de 5 
VX_CONSTEXPR20 VxFloat VX_LN2		=	0.69314718f;  // Logaritmo natural de 2 
VX_CONSTEXPR20 VxFloat VX_LN10		=	2.30258509f;  // Logaritmo natural de 10 
VX_CONSTEXPR20 VxFloat VX_LOG2E		=	1.44269504f;  // Logaritmo base 2 de E 
VX_CONSTEXPR20 VxFloat VX_LOG10E	=	0.43429448f;  // Logaritmo base 10 de E 
VX_CONSTEXPR20 VxFloat VX_INV_PI	=	0.31830989f;  // 1 / PI 
VX_CONSTEXPR20 VxFloat VX_INV_SQRT2 =	0.70710678f;  // 1 / sqrt(2) 
VX_CONSTEXPR20 VxFloat VX_GAMMA		=	0.57721566f;  // Constante de Euler-Mascheroni 
VX_CONSTEXPR20 VxFloat VX_CATALAN	=	0.91596559f;  // Constante de Catalán 
VX_CONSTEXPR20 VxFloat VX_KAPPA		=	2.68545200f;  // Constante de Khinchin

#else

#ifdef VX_CPLUSPLUS
VX_EXTERN_C_BEGIN
#endif


#define VX_PI			3.14159265f
#define VX_TAU			6.28318530f       // 2 * PI
#define VX_E			2.71828183f       // Numero de Euler
#define VX_PHI			1.61803398f       // Proporción áurea
#define VX_SQRT2		1.41421356f       // Raíz cuadrada de 2
#define VX_SQRT3		1.73205081f       // Raíz cuadrada de 3
#define VX_SQRT5		2.23606798f       // Raíz cuadrada de 5
#define VX_LN2			0.69314718f       // Logaritmo natural de 2
#define VX_LN10		    2.30258509f       // Logaritmo natural de 10
#define VX_LOG2E		1.44269504f	      // Logaritmo base 2 de E
#define VX_LOG10E		0.43429448f		  // Logaritmo base 10 de E
#define VX_INV_PI		0.31830989f		  // 1 / PI
#define VX_INV_SQRT2	0.70710678f		  // 1 / sqrt(2)
#define VX_GAMMA		0.57721566f       // Constante de Euler-Mascheroni
#define VX_CATALAN		0.91596559f       // Constante de Catalán
#define VX_KAPPA		2.68545200f       // Constante de Khinchin



#ifdef VX_CPLUSPLUS
VX_EXTERN_C_END
#endif


#endif




#endif