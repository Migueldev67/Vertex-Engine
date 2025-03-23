

#ifndef VX_BIT_H
#define VX_BIT_H




// Macros de operacion a nivel de bits or
#ifndef _VX_BIT_OR_
	#define _VX_BIT_OR_(_N1, _N2)			 ((_N1) | (_N2))
	#define VX_BIT_OR(_N1, _N2) _VX_BIT_OR_(_N1, _N2)
#endif

// Macros de operacion a nivel de bits and
#ifndef _VX_BIT_AND_
	#define _VX_BIT_AND_(_N1, _N2)			 ((_N1) & (_N2))
	#define VX_BIT_AND(_N1, _N2) _VX_BIT_AND_(_N1, _N2)
#endif

// Macros de operacion a nivel de bits not
#ifndef _VX_BIT_NOT_
	#define _VX_BIT_NOT_(_X)			 (~(_X))
	#define VX_BIT_NOT(_X) _VX_BIT_NOT_(_X)
#endif

// Macros de operacion a nivel de bits xor
#ifndef _VX_BIT_XOR_
	#define _VX_BIT_XOR_(_N1, _N2)			 ((_N1) ^ (_N2))
	#define VX_BIT_XOR(_N1, _N2) _VX_BIT_XOR_(_N1, _N2)
#endif


// Macro para desplazamiento de bits a la izquierda (Multiplicación por 2^n)
#ifndef _VX_BIT_LEFT_SHIFT_
	#define _VX_BIT_LEFT_SHIFT_(x, n)    ((x) << (n))
	#define VX_BIT_LEFT_SHIFT(x, n)  _VX_BIT_LEFT_SHIFT_(x, n) 
#endif

#ifndef _VX_BIT_
	#define _VX_BIT_(n) VX_BIT_LEFT_SHIFT(1, n)
	#define VXBIT(n) _VX_BIT_(n)
#endif

// Macro para desplazamiento de bits a la derecha (Division por 2^n)
#ifndef _VX_BIT_RIGHT_SHIFT_
	#define _VX_BIT_RIGHT_SHIFT_(x, n)     ((x) >> (n))
	#define VX_BIT_RIGHT_SHIFT(x, n) _VX_BIT_RIGHT_SHIFT_(x, n)
#endif


// Macro para establecer un bit en una posicion especifica a 1
#ifndef _VX_BIT_SET_
	#define _VX_BIT_SET_(x, n)             ((x) |= (1U << (n)))
	#define VX_BIT_SET(x, n) _VX_BIT_SET_(x, n)    
#endif


// Macro para limpiar un bit en una posición específica (ponerlo en 0)
#ifndef _VX_BIT_CLEAR_
	#define _VX_BIT_CLEAR_(x, n)           ((x) &= ~(1U << (n)))
	#define VX_BIT_CLEAR(x, n) _VX_BIT_CLEAR_(x, n)  
#endif

// Macro para invertir un bit en una posición específica (de 1 a 0, o de 0 a 1)
#ifndef _VX_BIT_TOGGLE_
	#define _VX_BIT_TOGGLE_(x, n)          ((x) ^= (1U << (n)))
	#define VX_BIT_TOGGLE(x, n) _VX_BIT_TOGGLE_(x, n) 
#endif

// Macro para obtener el valor de un bit especifico (1 o 0)
#ifndef _VX_BIT_GET_
	#define _VX_BIT_GET_(x, n)             (((x) >> (n)) & 1U)
	#define VX_BIT_GET(x, n) _VX_BIT_GET_(x, n)  
#endif

// Macro para verificar si un bit específico está en 1
#ifndef _VX_BIT_CHECK_
	#define _VX_BIT_CHECK_(x, n)           (((x) & (1U << (n))) != 0)
	#define VX_BIT_CHECK(x, n) _VX_BIT_CHECK_(x, n)  
#endif

// Macro para establecer varios bits (en una máscara de bits)
#ifndef _VX_BIT_SET_MASK_
	#define _VX_BIT_SET_MASK_(x, mask)     ((x) |= (mask))
	#define VX_BIT_SET_MASK(x, mask) _VX_BIT_SET_MASK_(x, mask)
#endif

// Macro para limpiar varios bits (en una máscara de bits)
#ifndef _VX_BIT_CLEAR_MASK_
	#define _VX_BIT_CLEAR_MASK_(x, mask)   ((x) &= ~(mask))
	#define VX_BIT_CLEAR_MASK(x, mask) _VX_BIT_CLEAR_MASK_(x, mask)
#endif

// Macro para verificar si varios bits están establecidos (en una máscara de bits)
#ifndef _VX_BIT_CHECK_MASK_
	#define _VX_BIT_CHECK_MASK_(x, mask)   (((x) & (mask)) == (mask))
	#define VX_BIT_CHECK_MASK(x, mask) _VX_BIT_CHECK_MASK_(x, mask)
#endif

// Si estamos en la version la version 1.0.0 de vertex engine
#if _VX_HAS_VERTEX_VERSION_1_0_0 


	#ifndef _VX_BIT_ROTATE_LEFT_
		#define _VX_BIT_ROTATE_LEFT_(x, n)     (((x) << (n)) | ((x) >> (sizeof(x) * 8 - (n))))
		#define VX_BIT_ROTATE_LEFT(x, n) _VX_BIT_ROTATE_LEFT_(x, n)
	#endif
	
	#ifndef _VX_BIT_ROTATE_RIGHT_
		#define _VX_BIT_ROTATE_RIGHT_(x, n)    (((x) >> (n)) | ((x) << (sizeof(x) * 8 - (n))))
		#define VX_BIT_ROTATE_RIGHT(x, n) _VX_BIT_ROTATE_RIGHT_(x, n) 
	#endif




#endif










#endif