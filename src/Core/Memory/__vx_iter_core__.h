



#ifndef VX_ITER_CORE_H
#define VX_ITER_CORE_H



#include "Core/VxPackCore.h"
#include "Core/Utils/VxTypeTraits.h"


#include <__msvc_iter_core.hpp>




VX_BEGIN

VX_INTERNAL_BEGIN

/**
 * Template que verifica si un tipo tiene un tipo de asignador definido.
 * Esta especializacion general asume que el tipo no tiene un tipo de asignador.
 * Se hereda de vx_false_types, indicando que la verificacion es falsa por defecto.
 * 
 */
    template <typename _Ty, typename _Alloc, typename = VxVoid>
struct __Has_allocator_type : vx_false_types {};

/**
 * Especializacion del template para detectar si un tipo _Ty tiene un tipo de asignador definido.
 * Utiliza SFINAE con VxVoid_t para determinar si el tipo _Ty contiene un alias llamado __Allocator_type.
 * Si _Ty tiene __Allocator_type y _Alloc es convertible a este, entonces la evaluacion devuelve verdadero.
 * 
 */
template <typename _Ty, typename _Alloc>
struct __Has_allocator_type<_Ty, _Alloc, VxVoid_t<typename _Ty::__Allocator_type>>
    : vx_is_convertible<_Alloc, typename _Ty::__Allocator_type>::_Type {
};

VX_INTERNAL_END

/**
 * Estructura utilizada como etiqueta para indicar que se esta pasando un argumento de asignador.
 * El constructor es explicit para evitar conversiones implicitas.
 * 
 */
    struct vx_allocator_arg_t {
    explicit vx_allocator_arg_t() = default;
};

/**
 * Instancia constante global de vx_allocator_arg_t utilizada como marcador.
 * 
 */
VX_CONSTEXPR20 inline vx_allocator_arg_t _AllocatorArg{};

/**
 * Verifica si un tipo _Ty usa un asignador de tipo _Alloc.
 * Hereda de __Has_allocator_type para determinar si _Ty tiene un tipo de asignador convertible desde _Alloc.
 * 
 */
template <typename _Ty, typename _Alloc>
struct vx_uses_allocator : vertex::internal::__Has_allocator_type<_Ty, _Alloc>::_Type {};

/**
 * Variable template que almacena el resultado de vx_uses_allocator en tiempo de compilacion.
 * Devuelve un booleano que indica si _Ty usa un asignador de tipo _Alloc.
 * 
 */
template <typename _Ty, typename _Alloc>
VX_CONSTEXPR20 VxBool vx_uses_allocator_v = vx_uses_allocator<_Ty, _Alloc>::_Value;

/**
 * Tags utilizados para categorizar iteradores segun sus capacidades.
 * Estas etiquetas permiten que algoritmos genericos detecten y optimicen su comportamiento
 * segun el tipo de iterador que se les pase.
 * 
 */
struct vx_input_iterator_tag {}; // Iterador de entrada
struct vx_output_iterator_tag {}; // Iterador de salida
struct vx_forward_iterator_tag : vx_input_iterator_tag {}; // Iterador de avance
struct vx_bidirectional_iterator_tag : vx_forward_iterator_tag {}; // Iterador bidireccional
struct vx_random_access_iterator_tag : vx_bidirectional_iterator_tag {}; // Iterador de acceso aleatorio

#if VX_HAS_CXX20

/**
 * Iterador de acceso contiguo, introducido en C++20.
 * Es una extension de un iterador de acceso aleatorio, garantizando que los elementos
 * estan almacenados en una memoria contigua.
 * 
 */
struct vx_contiguous_iterator_tag : vx_random_access_iterator_tag {};

VX_INTERNAL_BEGIN

/**
 * Template alias que devuelve una referencia al tipo dado.
 * 
 */
    template <typename _Ty>
using __With_reference__ = _Ty&;

/**
 * Concepto que verifica si un tipo puede ser referenciado.
 * Se cumple si el tipo _Ty puede ser utilizado en una expresion de referencia.
 * 
 */
template <class _Ty>
concept __Can_reference__ = requires { typename __With_reference__<_Ty>; };

/**
 * Concepto que verifica si un tipo puede ser desreferenciado.
 * Se cumple si la operacion de desreferenciacion (*) produce un valor referenciable.
 * 
 */
template <class _Ty>
concept __Dereferenceable__ = requires(_Ty & __t) {
    { *__t } -> __Can_reference__;
};

/**
 * Conjunto de conceptos que verifican la existencia de miembros especificos en un tipo.
 * Estos conceptos permiten la introspeccion del tipo para determinar si cumple con los
 * requisitos de un iterador.
 * 
 */
template <class _Ty>
concept __Has_member_iterator_concept__ = requires { typename _Ty::_Iterator_concept; };

template <class _Ty>
concept __Has_member_iterator_category__ = requires { typename _Ty::_Iterator_category; };

template <class _Ty>
concept __Has_member_value_type__ = requires { typename _Ty::_Value_type; };

template <class _Ty>
concept __Has_member_element_type__ = requires { typename _Ty::_Element_type; };

template <class _Ty>
concept __Has_member_difference_type__ = requires { typename _Ty::_Difference_type; };

template <class _Ty>
concept __Has_member_pointer__ = requires { typename _Ty::_Pointer; };

template <class _Ty>
concept ___Has_member_reference__ = requires { typename _Ty::_Reference; };


VX_INTERNAL_END


template <typename>
struct vx_incrementable_traits {};

template <typename _Ty>
    requires vx_is_object_v<_Ty>
struct vx_incrementable_traits<_Ty*> {
    using _Difference_type = VxPtrdiff;
};


template <typename _Ty>
struct vx_incrementable_traits<const _Ty> : vx_incrementable_traits<_Ty> {};


template <vertex::internal::__Has_member_difference_type__ _Ty>
struct vx_incrementable_traits<_Ty> {
    using difference_type = _Ty::_Difference_type;
};

/*
template <class _Ty>
concept _Can_difference = requires(const _Ty & __a, const _Ty & __b) {
    { __a - __b } -> integral;
};*/






#else


#endif



VX_END



#endif