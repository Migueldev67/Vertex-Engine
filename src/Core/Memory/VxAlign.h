



#ifndef VX_ALIGN_H
#define VX_ALIGN_H


#include "Core/Utils/VxTypeTraits.h"

#if defined(VX_COMP_MSVC) || defined(VX_COMP_CLANG) || defined(VX_PLATFORM_ANDROID) || defined(VX)
	#include <malloc.h>  // Incluye la cabecera para funciones de asignación de memoria en plataformas específicas.
#elif
	#include <cstdlib>  // En otras plataformas, usa la cabecera estándar para asignación de memoria.
#endif

#include <memory>  // Incluye utilidades de memoria estándar.
// #include <new>  // Comentado, se puede usar si es necesario para operadores de asignación en memoria.

VX_BEGIN

VX_INTERNAL_BEGIN

/**
 * Verifica si un valor dado es una potencia de dos, lo cual es un requisito para alineaciones de memoria.
 */
	template <VxSize _Value>
VX_CONSTEXPR20 VxBool vx_is_aligment_v = (_Value > 0) && ((_Value & (_Value - 1)) == 0);

/**
 * Estructura auxiliar utilizada para calcular el desplazamiento de un tipo de datos en memoria.
 */
template <typename _Ty>
struct __Offset__ {
	VxChar _Value;  ///< Un byte de espacio previo al objeto.
	_Ty _Object;    ///< El objeto de tipo _Ty.
};

/**
 * Obtiene el tamaño de un tipo de datos en memoria.
 */
template <typename _Ty>
struct __Size_of__ {
	static VX_CONSTEXPR20 VxSize _Size = sizeof(_Ty);  ///< Tamaño del tipo en bytes.
};

VX_INTERNAL_END

/**
 * Calcula el máximo entre dos tamaños dados.
 */
	template <VxSize _First, VxSize _Second>
using vx_max_size = vx_max<VxSize, _First, _Second>;

/**
 * Calcula el mínimo entre dos tamaños dados.
 */
template <VxSize _First, VxSize _Second>
using vx_min_size = vx_min<VxSize, _First, _Second>;

/**
 * Determina si un valor dado es una alineación válida (potencia de dos).
 */
template <VxSize _Value>
struct vx_is_alignment
	: vx_bool_constant<vertex::internal::vx_is_aligment_v<_Value>> {
};

/**
 * Obtiene la alineación de un tipo de datos, calculada en función de su tamaño mínimo y su desplazamiento en memoria.
 */
template <typename _Ty>
struct vx_alignment_of
	: vx_min_size<vertex::internal::__Size_of__<_Ty>::_Size,
	vertex::internal::__Size_of__<vertex::internal::__Offset__<_Ty>>::_Size -
	vertex::internal::__Size_of__<_Ty>::_Size> {
};

/**
 * Calcula la alineacion máxima entre dos tipos de datos.
 */
template <typename _Ty1, typename _Ty2>
struct vx_max_align
	: vx_max_size<vx_alignment_of<_Ty1>::_Value, vx_alignment_of<_Ty2>::_Value> {
};

/**
 * Determina el numero máximo de objetos de un tipo que se pueden alojar en el tamaño máximo de memoria posible.
 */
template <typename _Ty>
struct vx_max_objects
	: vx_constant<VxSize, ~static_cast<VxSize>(0) /
	vertex::internal::__Size_of__<_Ty>::_Value> {
};

/**
 * Obtiene el tipo base de un tipo compuesto, eliminando referencias, calificadores de const/volatile y dimensiones de arreglos.
 */
template<typename T>
struct vx_element_type {
	using _Type = typename vx_remove_cv<typename vx_remove_all_extents<typename
		vx_remove_reference<T>::_Type>::_Type>::_Type;
};

/**
 * Permite definir un tipo alternativo si el primer tipo no es un puntero.
 */
template<typename _Ty1, typename _Ty2>
struct vx_not_pointer {
	using _Type = _Ty2;  ///< Si _Ty1 no es un puntero, el tipo resultante es _Ty2.
};

/**
 * Especialización que evita la definición de _Type si _Ty1 es un puntero.
 */
template<typename _Ty1, typename _Ty2>
struct vx_not_pointer<_Ty1*, _Ty2> {};




/**
 * Verifica si un valor es una potencia de 2, lo que indica si es una alineacion valida.
 * La operacion (_Value & (_Value - 1)) == 0 devuelve verdadero solo si _Value es una potencia de 2.
 * Ejemplo:
 *  8 (1000 en binario) & (7 -> 0111) = 0000 -> true (es potencia de 2)
 * 10 (1010 en binario) & (9 -> 1001) = 1000 -> false (no es potencia de 2)
 */
VX_CONSTEXPR20 
VxBool vxIsAlignment(
	VxSize									_Value
) noexcept;

/**
 * Verifica si un puntero esta alineado a un valor especifico.
 * Se usa una mascara binaria para verificar si la direccion del puntero
 * es un multiplo exacto de _Alignment.
 */
inline VxBool vxIsAligned(
	const volatile VxVoidPtr _Ptr, 
	VxSize _Alignment
) noexcept;

inline VxBool vxIsAligned(
	VxSize _Alignment, 
	const volatile VxVoidPtr _Ptr
) noexcept;

/**
 * Alinea un puntero a la siguiente direccion valida basada en _Alignment.
 * La operacion usa una mascara de bits para redondear la direccion hacia arriba.
 * Ejemplo:
 *  Direccion inicial:  0000 0000 0000 0110 (6 en decimal)
 *  Alineacion:         0000 0000 0000 0100 (4 en decimal)
 *  Mascara:            1111 1111 1111 1011 (~3)
 *  Resultado:          0000 0000 0000 0100 (redondeado a 4)
 */
inline VxVoidPtr vxAlign(
	VxSize							_Alignment, 
	VxSize							_Size, 
	VxVoidPtr&						_Ptr, 
	VxSize							_Space
);

/**
 * Reserva memoria alineada segun el sistema operativo y la plataforma.
 * En Android usa memalign, en MSVC usa _aligned_malloc,
 * en Linux y macOS usa posix_memalign.
 */
inline VxVoidPtr vxAlignedAlloc(
	VxSize							_Alignment, 
	VxSize							_Size
) noexcept;

/**
 * Libera memoria alineada y borra los datos antes de liberar para mayor seguridad.
 * Usa memset para evitar datos residuales en la memoria.
 */
inline VxVoid vxAlignedFree(
	VxVoidPtr&						_Ptr
) noexcept;





VX_END


#endif