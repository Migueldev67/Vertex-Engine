



#ifndef VX_TYPE_TRAITS_H
#define VX_TYPE_TRAITS_H


#include "../src/Core/VxPackCore.h"


#if defined(VX_CPLUSPLUS)

VX_BEGIN




// Constante comun en tiempo de compilacion
template <typename _Ty, _Ty _Val>
struct vx_constant {
	static VX_CONSTEXPR20 _Ty _Value = _Val;
	using value_type = _Ty;
	VX_CONSTEXPR20 operator value_type() {
		return _Value;
	}

	VX_NODISCARD VX_CONSTEXPR20 value_type operator()(){
		return _Value;
	}
};

// Constante booleana
template <VxBool _Val>
using vx_bool_constant = vx_constant<VxBool, _Val>;

// Constantes true y false
using vx_true_types = vx_bool_constant<VX_TRUE>;
using vx_false_types = vx_bool_constant<VX_FALSE>;

VX_INTERNAL_BEGIN


#define _VX_INTERNAL_MIN_(_First, _Second) ((_First < _Second) ? (_First) : (_Second))
#define _VX_INTERNAL_MAX_(_First, _Second) ((_First > _Second) ? (_First) : (_Second))
#define _VX_INTERNAL_ABS_(_Value) ((_Value) < 0 ? -(_Value) : (_Value))
#define _VX_INTERNAL_IS_ODD_(_Value) ((_Value) % 2 != 0)
#define	_VX_INTERNAL_IS_EVEN_(_Value) ((_Value) % 2 == 0)

template <typename _Ty, _Ty _Firts, _Ty _Second>
VX_CONSTEXPR20 _Ty vx_min_v = _VX_INTERNAL_MIN_(_Firts, _Second);

template <typename _Ty, _Ty _Firts, _Ty _Second>
VX_CONSTEXPR20 _Ty vx_max_v = _VX_INTERNAL_MAX_(_Firts, _Second);

template <typename _Ty, _Ty _Value>
VX_CONSTEXPR20 _Ty vx_abs_v = _VX_INTERNAL_ABS_(_Value);

template <typename _Ty, _Ty _Value>
VX_CONSTEXPR20 VxBool vx_is_odd_v = _VX_INTERNAL_IS_ODD_(_Value);

template <typename _Ty, _Ty _Value>
VX_CONSTEXPR20 VxBool vx_is_even_v = _VX_INTERNAL_IS_EVEN_(_Value);


VX_INTERNAL_END



template <typename _Ty, _Ty _First, _Ty _Second>
struct vx_min
	: vx_constant<_Ty, vertex::internal::vx_min_v<_Ty, _First, _Second>> {};

template <typename _Ty, _Ty _First, _Ty _Second>
struct vx_max 
	: vx_constant<_Ty, vertex::internal::vx_max_v<_Ty, _First, _Second>> {};


template <typename _Ty, _Ty _Value>
struct vx_abs 
	: vx_constant<_Ty, vertex::internal::vx_abs_v<_Ty, _Value>> {};

template <typename _Ty, _Ty _Value>
struct vx_is_odd 
	: vx_bool_constant<vertex::internal::vx_is_odd_v<_Ty, _Value>> {};

template <typename _Ty, _Ty _Value>
struct vx_is_even 
	: vx_bool_constant<vertex::internal::vx_is_even_v<_Ty, _Value>> {};


// Habilita caracteristicas si...
template <VxBool _Test, typename _Ty = VxVoid>
struct vx_enable_if {};

template <typename _Ty>
struct vx_enable_if<true, _Ty> {
	using _Type = _Ty;
};

template <VxBool _Test, typename _Ty = VxVoid>
using vx_enable_if_t = typename vx_enable_if<_Test, _Ty>::_Type;


// Para condiciones

template <VxBool _Test, typename _Ty1, typename _Ty2>
struct vx_conditional {
	using _Type = _Ty1;
};

template <typename _Ty1, typename _Ty2>
struct vx_conditional<false, _Ty1, _Ty2> {
	using _Type = _Ty2;
};

template <VxBool _Test, typename _Ty1, typename _Ty2>
using vx_conditional_t = typename vx_conditional<_Test, _Ty1, _Ty2>::_Type;


#if defined(VX_COMP_CLANG)

template <typename _Ty1, typename _Ty2>
static VX_CONSTEXPR20 VxBool vx_is_same_v = __is_same(_Ty1, _Ty2);

template <typename _Ty1, typename _Ty2>
struct vx_is_same : vx_bool_constant<__is_same(_Ty1, _Ty2)> {};

#endif


// Verifica si dos tipos son el mismo
template <typename, typename>
static VX_CONSTEXPR20 VxBool vx_is_same_v = VX_FALSE;

template <typename _Ty>
static VX_CONSTEXPR20 VxBool vx_is_same_v<_Ty, _Ty> = VX_TRUE;


template <typename _Ty1, typename _Ty2>
struct vx_is_same : vx_bool_constant<vx_is_same_v<_Ty1, _Ty2>> {};


// Remueve const de un tipo

template <typename _Ty>
struct vx_remove_const {
	using _Type = _Ty;
};

template <typename _Ty>
struct vx_remove_const<const _Ty> {
	using _Type = _Ty;
};

template <typename _Ty>
using vx_remove_const_t = typename vx_remove_const<_Ty>::_Type;


// Remueve volatile de un tipo
template <typename _Ty>
struct vx_remove_volatile {
	using _Type = _Ty;
};

template <typename _Ty>
struct vx_remove_volatile<volatile _Ty> {
	using _Type = _Ty;
};

template <typename _Ty>
using vx_remove_volatile_t = typename vx_remove_volatile<_Ty>::_Type;


// Remueve const volatile de un tipo
template <typename _Ty>
struct vx_remove_cv {
	using _Type = _Ty;

	template <template <typename> typename _Fn>
	using _Apply = _Fn<_Ty>;
};

template <typename _Ty>
struct vx_remove_cv<const _Ty> {
	using _Type = _Ty;

	template <template <typename> typename _Fn>
	using _Apply = const _Fn<_Ty>;
};

template <typename _Ty>
struct vx_remove_cv<volatile _Ty> {
	using _Type = _Ty;

	template <template <typename> typename _Fn>
	using _Apply = volatile _Fn<_Ty>;
};

template <typename _Ty>
struct vx_remove_cv<const volatile _Ty> {
	using _Type = _Ty;

	template <template <typename> typename _Fn>
	using _Apply = const volatile _Fn<_Ty>;
};

template <typename _Ty>
using vx_remove_cv_t = typename vx_remove_cv<_Ty>::_Type;



VX_INTERNAL_BEGIN



// Disyuncion (matematicas discretas)
template <VxBool _Firts_value, typename _First, typename... _Rest>
struct __VX_DISJUNCTION__ {
	using _Type = _First;
};

template <typename _False, typename _Next, typename... _Rest>
struct __VX_DISJUNCTION__<false, _False, _Next, _Rest...> {
	using _Type = typename __VX_DISJUNCTION__<static_cast<VxBool>(_Next::_Value), _Next, _Rest...>::_Type;
};

// Verifica si varios tipos son iguales
template <typename _Ty, typename... _Types>
VX_CONSTEXPR20 VxBool __IS_ANY_OF_V__ =
#if VX_HAS_CXX17
	(vx_is_same_v<_Ty, _Types> || ...);
#else 
	vx_disjunction_v<vx_is_same<_Ty, _Types>...>;
#endif

VX_NODISCARD VX_CONSTEXPR20 VxBool __vx_is_constant_evaluated__() noexcept {
	return __builtin_is_constant_evaluated();
}


#if VX_HAS_CXX20

VX_CONSTEXPR20 VxBool __vx_is_constant_evaluated() noexcept {
	return __builtin_is_constant_evaluated();
}

#endif

VX_INTERNAL_END




// Disyuncion (matematicas discretas)
template <typename... _Traits>
struct vx_disjunction : vx_false_types {};

template <class _First, class... _Rest>
struct vx_disjunction<_First, _Rest...> : vertex::internal::__VX_DISJUNCTION__<static_cast<VxBool>(_First::_Value), _First, _Rest...>::_Type {};

template <typename... _Traits>
VX_CONSTEXPR20 VxBool vx_disjunction_v = vx_disjunction<_Traits...>::_Value;


// Verifica si es un numero entero
template <typename _Ty>
VX_CONSTEXPR20 VxBool vx_is_integral_v = vertex::internal::__IS_ANY_OF_V__<vx_remove_cv_t<_Ty>, VxBool, 
	VxChar, VxUchar, wchar_t,
#ifdef __cpp_char8_t
	char8_t,
#endif 
	char16_t, char32_t, VxInt16, VxUint16, VxInt32, VxUint32, VxInt64, VxUint64, 
	VxSize, VxFlags, VxBoolean, VxQword, VxInt8, VxUint8, VxIntptr, VxUintptr>;


template <typename _Ty>
struct vx_is_integral : vx_bool_constant<vx_is_integral_v<_Ty>> {};


// Verfifica si es de punto flotante
template <typename _Ty>
static VX_CONSTEXPR20 VxBool vx_is_floating_point_v = vertex::internal::__IS_ANY_OF_V__<vx_remove_cv_t<_Ty>, float, double, long double>;

template <typename _Ty>
struct vx_is_floating_point : vx_bool_constant<vx_is_floating_point_v<_Ty>> {};


// Verifica si es aritmetico
template <typename _Ty>
static VX_CONSTEXPR20 VxBool vx_is_arithmetic_v = 
	vx_is_integral_v<_Ty> || vx_is_floating_point_v<_Ty>;

template <typename _Ty>
struct vx_is_arithmetic : vx_bool_constant<vx_is_arithmetic_v<_Ty>> {};


// Remueve unsigned de un tipo 
template <typename _Ty>
struct vx_remove_unsigned {
	using _Type = _Ty;
};

template <>
struct vx_remove_unsigned<unsigned char> {
	using _Type = char;
};

template <>
struct vx_remove_unsigned<unsigned short> {
	using _Type = short;
};

template <>
struct vx_remove_unsigned<unsigned int> {
	using _Type = int;
};

template <>
struct vx_remove_unsigned<unsigned long> {
	using _Type = long;
};

template <>
struct vx_remove_unsigned<unsigned long long> {
	using _Type = long long;
};


template <typename _Ty>
using vx_remove_unsigned_t = typename vx_remove_unsigned<_Ty>::_Type;


// Remueve &-&& (L-value o R-value) de un tipo
template <typename _Ty>
struct vx_remove_reference {
	using _Type = _Ty;
	using _Const_thru_ref_type = const _Ty;
};

template <typename _Ty>
struct vx_remove_reference<_Ty&> {
	using _Type = _Ty;
	using _Const_thru_ref_type = const _Ty&;
};

template <typename _Ty>
struct vx_remove_reference<_Ty&&> {
	using _Type = _Ty;
	using _Const_thru_ref_type = const _Ty&&; // Debuelve el tipo anterior
};

template <typename _Ty>
using vx_remove_reference_t = typename vx_remove_reference<_Ty>::_Type;




VX_INTERNAL_BEGIN



template <typename _Ty>
using __VX_CONST_THRU_REF__ = typename vx_remove_reference<_Ty>::_Const_thru_ref_type;

template <typename _Ty>
using __REMOVE_CVREF_T__ = vx_remove_cv_t<vx_remove_reference_t<_Ty>>;


// Conjuncion (Matenaticas discretas)
template <VxBool _First_value, typename _First, typename... _Rest>
struct __VX_CONJUNCTION__ {
	using _Type = _First;
};

template <typename _True, typename _Next, typename... _Rest>
struct __VX_CONJUNCTION__<true, _True, _Next, _Rest...> {
	using _Type = typename __VX_CONJUNCTION__<static_cast<VxBool>(_Next::_Value), _Next, _Rest...>::_Type;
};




VX_INTERNAL_END


// Habilitado para C++20
#if VX_HAS_CXX20

template <typename _Ty>
using vx_remove_cvref_t = vertex::internal::__REMOVE_CVREF_T__<_Ty>;

template <typename _Ty>
struct vx_remove_cvref {
	using _Type = vertex::internal::__REMOVE_CVREF_T__<_Ty>;
};


#endif 

// Siempre falso
template <typename>
static VX_CONSTEXPR20 VxBool _Always_false = VX_FALSE;

// Conjuncion (Matenaticas discretas)
template <typename... _Traits>
struct vx_conjunction : vx_true_types {};

template <typename _First, typename... _Rest>
struct vx_conjunction<_First, _Rest...> {
	using _Type = typename vertex::internal::__VX_CONJUNCTION__<static_cast<VxBool>(_First::_Value), _First, _Rest...>::_Type;
};

// Variable que retorna el valor de la conjuncion
template <typename... _Rest>
static VX_CONSTEXPR20 VxBool vx_conjunction_v = vx_conjunction<_Rest...>::_Value;

// Negacion (Matematicas discretas)
template <typename _Value>
struct vx_negation : vx_bool_constant<!static_cast<VxBool>(_Value::_Value)> {};

// Variable en tiempo de compilacion que retorna el valor de la negacion
template <typename _Rest>
static VX_CONSTEXPR20 VxBool vx_negation_v = vx_negation<_Rest>::_Value;


template <typename _Ty>
static VX_CONSTEXPR20 VxBool vx_is_void_v = vx_is_same_v<vx_remove_cv_t<_Ty>, VxVoid>;

template <typename _Ty>
static VX_CONSTEXPR20 VxBool vx_is_byte_v = vx_is_same_v<vx_remove_cv_t<_Ty>, VxByte>;

template <typename _Ty>
static VX_CONSTEXPR20 VxBool vx_is_word_v = vx_is_same_v<vx_remove_cv_t<_Ty>, VxWord>;

template <typename _Ty>
static VX_CONSTEXPR20 VxBool vx_is_dword_v = vx_is_same_v<vx_remove_cv_t<_Ty>, VxDword>;

template <typename _Ty>
static VX_CONSTEXPR20 VxBool vx_is_qword_v = vx_is_same_v<vx_remove_cv_t<_Ty>, VxQword>;

template <typename _Ty>
static VX_CONSTEXPR20 VxBool vx_is_float_v = vx_is_same_v<vx_remove_cv_t<_Ty>, VxFloat>;

template <typename _Ty>
static VX_CONSTEXPR20 VxBool vx_is_double_v = vx_is_same_v<vx_remove_cv_t<_Ty>, VxDouble>;

template <typename _Ty>
static VX_CONSTEXPR20 VxBool vx_is_long_double_v = vx_is_same_v<vx_remove_cv_t<_Ty>, VxLdouble>;

template <typename _Ty>
static VX_CONSTEXPR20 VxBool vx_is_char_v = vx_is_same_v<vx_remove_cv_t<_Ty>, VxChar>;

template <typename _Ty>
static VX_CONSTEXPR20 VxBool vx_is_bool_v = vx_is_same_v<vx_remove_cv_t<_Ty>, VxBool || VxBoolean>;


// Verifica si un tipo es void
template <typename _Ty>
struct vx_is_void : vx_bool_constant<vx_is_void_v<_Ty>> {};

// Verifica si un tipo es de byte. Solo para enteros
template <typename _Ty>
struct vx_is_byte : vx_bool_constant<vx_is_byte_v<_Ty>> {};

// Verifica si un tipo es de word (2-Bytes). Solo para enteros 
template <typename _Ty>
struct vx_is_word : vx_bool_constant<vx_is_word_v<_Ty>> {};

// Verifica si un tipo es de dword (4-Bytes). Solo para enteros
template <typename _Ty>
struct vx_is_dword : vx_bool_constant<vx_is_dword_v<_Ty>> {};

// Verifica si un tipo es de word (8-Bytes). Solo para enteros
template <typename _Ty>
struct vx_is_qword : vx_bool_constant<vx_is_qword_v<_Ty>> {};

// Verifica si un tipo es float
template <typename _Ty>
struct vx_is_float : vx_bool_constant<vx_is_float_v<_Ty>> {};

// Verifica si un tipo es double
template <typename _Ty>
struct vx_is_double : vx_bool_constant<vx_is_double_v<_Ty>> {};

// Verifica si un tipo es long double
template <typename _Ty>
struct vx_is_long_double : vx_bool_constant<vx_is_long_double_v<_Ty>> {};

// Verifica si un tipo es char
template <typename _Ty>
struct vx_is_char : vx_bool_constant<vx_is_char_v<_Ty>> {};

// Verifica si un tipo es bool
template <typename _Ty>
struct vx_is_bool : vx_bool_constant<vx_is_bool_v<_Ty>> {};

// Agrega const a un tipo
template <typename _Ty>
struct vx_add_const {
	using _Type = const _Ty;
};

template <typename _Ty>
using vx_add_const_t = typename vx_add_const<_Ty>::_Type;

// Agrega volatile a un tipo
template <typename _Ty>
struct vx_add_volatile {
	using _Type = volatile _Ty;
};

template <typename _Ty>
using vx_add_volatile_t = typename vx_add_volatile<_Ty>::_Type;

// Agrega const volatile a un tipo
template <typename _Ty>
struct vx_add_cv {
	using _Type = const volatile _Ty;
};

template <typename _Ty>
using vx_add_cv_t = typename vx_add_cv<_Ty>::_Type;


template <typename... _Types>
VX_DEFINE_ALIAS(VxVoid_t, VxVoid)



VX_INTERNAL_BEGIN



template <typename _Ty, typename = VxVoid>
struct __VX_ADD_REFERENCE__ {
	using _Lvalue = _Ty&;
	using _Rvalue = _Ty&&;
};

template <typename _Ty>
struct __VX_ADD_REFERENCE__<_Ty, VxVoid_t<_Ty&&>> {
	using _Lvalue = _Ty&;
	using _Rvalue = _Ty&&;
};


template <typename _Ty, typename = VxVoid>
struct __VX_ADD_POINTER__ {
	using type = _Ty;
};

template <typename _Ty>
struct __VX_ADD_POINTER__<_Ty, VxVoid_t<vx_remove_reference_t<_Ty>*>> {
	using _Type = vx_remove_reference_t<_Ty>*;
};



VX_INTERNAL_END


template <typename _Ty>
using vx_add_ref_lvalue_t = typename vertex::internal::__VX_ADD_REFERENCE__<_Ty>::_Lvalue;

template <typename _Ty>
using vx_add_ref_rvalue_t = typename vertex::internal::__VX_ADD_REFERENCE__<_Ty>::_Rvalue;


// Agrega constexpr a un tipo
template <typename _Ty>
struct vx_add_constexpr {
	using _Type = VX_CONSTEXPR20 _Ty;
};

template <typename _Ty>
using vx_add_constexpr_t = typename vx_add_constexpr<_Ty>::_Type;

// Agrega static a un tipo
template <typename _Ty>
struct vx_add_static {
	using _Type = static _Ty;
};

template <typename _Ty>
using vx_add_static_t = typename vx_add_static<_Ty>::_Type;



template <typename _Ty>
struct vx_remove_extent { 
	using _Type = _Ty;
};

template <typename _Ty, size_t _Ix>
struct vx_remove_extent<_Ty[_Ix]> {
	using _Type = _Ty;
};

template <typename _Ty>
struct vx_remove_extent<_Ty[]> {
	using _Type = _Ty;
};

template <typename _Ty>
using vx_remove_extent_t = typename vx_remove_extent<_Ty>::_Type;

template <typename _Ty>
struct vx_remove_all_extents { 
	using _Type = _Ty;
};

template <typename _Ty, VxSize _Ix>
struct vx_remove_all_extents<_Ty[_Ix]> {
	using _Type = typename vx_remove_all_extents<_Ty>::_Type;
};

template <typename _Ty>
struct vx_remove_all_extents<_Ty[]> {
	using _Type = typename vx_remove_all_extents<_Ty>::_Type;
};

template <typename _Ty>
using vx_remove_all_extents_t = typename vx_remove_all_extents<_Ty>::_Type;


// Remueve el puntero de un tipo
template <typename _Ty>
struct vx_remove_pointer {
	using _Type = _Ty;
};

template <typename _Ty>
struct vx_remove_pointer<_Ty*> {
	using _Type = _Ty;
};

template <typename _Ty>
struct vx_remove_pointer<_Ty* const> {
	using _Type = _Ty;
};

template <typename _Ty>
struct vx_remove_pointer<_Ty* volatile> {
	using _Type = _Ty;
};

template <typename _Ty>
struct vx_remove_pointer<_Ty* const volatile> {
	using _Type = _Ty;
};

template <typename _Ty>
using vx_remove_pointer_t = typename vx_remove_pointer<_Ty>::_Type;


template <typename _Ty>
struct vx_add_pointer {
	using _Type = typename vertex::internal::__VX_ADD_POINTER__<_Ty>::_Type;
};

template <typename _Ty>
using vx_add_pointer_t = typename vertex::internal::__VX_ADD_POINTER__<_Ty>::_Type;


template <typename>
static VX_CONSTEXPR20 VxBool vx_is_array_v = VX_FALSE; // determine whether type argument is an array

template <typename _Ty, VxSize _Idx>
static VX_CONSTEXPR20 VxBool vx_is_array_v<_Ty[_Idx]> = VX_TRUE;

template <typename _Ty>
static VX_CONSTEXPR20 VxBool vx_is_array_v<_Ty[]> = VX_TRUE;

// Verifica si un tipo es un array
template <typename _Ty>
struct vx_is_array : vx_bool_constant<vx_is_array_v<_Ty>> {};

#if VX_HAS_CXX20

// Verifica si un array tiene tamaño predefinido
template <typename>
VX_CONSTEXPR20 VxBool vx_is_bounded_array_v = VX_FALSE;

template <typename _Ty, size_t _Nx>
VX_CONSTEXPR20 VxBool vx_is_bounded_array_v<_Ty[_Nx]> = VX_TRUE;

template <typename _Ty>
struct is_bounded_array : vx_bool_constant<is_bounded_array_v<_Ty>> {};

// Verfica si un array no tiene indice o no tiene tamaño predefinido
template <typename>
VX_CONSTEXPR20 VxBool vx_is_unbounded_array_v = VX_FALSE;

template <typename _Ty>
static VX_CONSTEXPR20 VxBool vx_is_unbounded_array_v<_Ty[]> = true;

template <typename _Ty>
struct is_unbounded_array : vx_bool_constant<vx_is_unbounded_array_v<_Ty>> {};


#endif 




template <typename>
static VX_CONSTEXPR20 VxBool vx_is_lvalue_reference_v = VX_FALSE; 

template <typename _Ty>
static VX_CONSTEXPR20 VxBool vx_is_lvalue_reference_v<_Ty&> = VX_TRUE;

template <typename _Ty>
struct is_lvalue_reference : vx_bool_constant<vx_is_lvalue_reference_v<_Ty>> {};

template <typename>
static VX_CONSTEXPR20 VxBool vx_is_rvalue_reference_v = VX_FALSE; 

template <class _Ty>
static VX_CONSTEXPR20 VxBool vx_is_rvalue_reference_v<_Ty&&> = VX_TRUE;

template <typename _Ty>
struct vx_is_rvalue_reference : vx_bool_constant<vx_is_rvalue_reference_v<_Ty>> {};

template <typename>
VX_CONSTEXPR20 VxBool vx_is_reference_v = VX_FALSE; 

template <typename _Ty>
VX_CONSTEXPR20 VxBool vx_is_reference_v<_Ty&> = VX_TRUE;

template <class _Ty>
static VX_CONSTEXPR20 VxBool vx_is_reference_v<_Ty&&> = VX_TRUE;

// Verifica si un tipo tiene referencia
template <class _Ty>
struct vx_is_reference : vx_bool_constant<vx_is_reference_v<_Ty>> {};


template <typename>
static VX_CONSTEXPR20 VxBool vx_is_pointer_v = VX_FALSE; 

template <typename _Ty>
static VX_CONSTEXPR20 VxBool vx_is_pointer_v<_Ty*> = VX_TRUE;

template <typename _Ty>
static VX_CONSTEXPR20 VxBool vx_is_pointer_v<_Ty* const> = VX_TRUE;

template <typename _Ty>
static VX_CONSTEXPR20 VxBool vx_is_pointer_v<_Ty* volatile> = VX_TRUE;

template <typename _Ty>
static VX_CONSTEXPR20 VxBool vx_is_pointer_v<_Ty* const volatile> = VX_TRUE;

// Verifica si es un puntero
template <typename _Ty>
struct vx_is_pointer : vx_bool_constant<vx_is_pointer_v<_Ty>> {};


template <typename _Ty>
VX_CONSTEXPR20 VxBool vx_is_null_pointer_v = vx_is_same_v<vx_remove_cv_t<_Ty>, nullptr_t>; 

// Verifica si es un puntero nulo (nullptr)
template <typename _Ty>
struct vx_is_null_pointer : vx_bool_constant<vx_is_null_pointer_v<_Ty>> {};


VX_INTERNAL_BEGIN


template <typename _Ty>
static VX_CONSTEXPR20 VxBool vx_is_union_v =
#if defined(VX_COMP_MSVC)
	__is_union(_Ty);
#elif defined(VX_COMP_GCC) || defined(VX_COMP_CLANG)

#endif


template <typename _Ty>
static VX_CONSTEXPR20 VxBool vx_is_class_v =
#if defined(VX_COMP_MSVC)
	__is_class(_Ty);
#elif defined(VX_COMP_GCC) || defined(VX_COMP_CLANG)

#endif


template <typename _Ty>
static VX_CONSTEXPR20 VxBool vx_is_enum_v =
#if defined(VX_COMP_MSVC)
	__is_enum(_Ty);
#elif defined(VX_COMP_GCC) || defined(VX_COMP_CLANG)

#endif


template <typename _From, typename _To>
static VX_CONSTEXPR20 VxBool vx_is_convertible_v =
#if defined(VX_COMP_MSVC)
	__is_convertible_to(_From, _To);
#elif defined(VX_COMP_GCC) || defined(VX_COMP_CLANG)

#endif


VX_INTERNAL_END



// Verifica si un tipo es union
template <typename _Ty>
struct vx_is_union : vx_bool_constant<vertex::internal::vx_is_union_v<_Ty>> {};

// Verifica si un tipo es class
template <typename _Ty>
struct vx_is_class : vx_bool_constant<vertex::internal::vx_is_class_v<_Ty>> {};

// Verifica si un tipo es enum
template <typename _Ty>
struct vx_is_enum : vx_bool_constant<vertex::internal::vx_is_enum_v<_Ty>> {};


template <typename _Ty>
VX_CONSTEXPR20 VxBool vx_is_fundamental_v = vx_is_arithmetic_v<_Ty> || is_void_v<_Ty> || is_null_pointer_v<_Ty>;

template <typename _Ty>
struct vx_is_fundamental : vx_bool_constant<vx_is_fundamental_v<_Ty>> {}; 

template <class _From, class _To>
VX_CONSTEXPR20 VxBool vx_is_convertible_v = __is_convertible_to(_From, _To);


template <typename _From, typename _To>
struct vx_is_convertible : vx_bool_constant<vx_is_convertible_v<_From, _To>> {};



#if !defined(VX_COMP_CLANG) && !defined(__EDG__) 

template <typename _Ty>
struct vx_is_convertible<_Ty&, volatile _Ty&> : vx_true_types {};

template <typename _Ty>
struct vx_is_convertible<volatile _Ty&, volatile _Ty&> : vx_true_types {};

template <typename _Ty>
struct vx_is_convertible<_Ty&, const volatile _Ty&> : vx_true_types {};

template <typename _Ty>
struct vx_is_convertible<volatile _Ty&, const volatile _Ty&> : vx_true_types {};

template <typename _Ty>
static VX_CONSTEXPR20 VxBool vx_is_convertible_v<_Ty&, volatile _Ty&> = VX_TRUE;

template <typename _Ty>
static VX_CONSTEXPR20 VxBool vx_is_convertible_v<volatile _Ty&, volatile _Ty&> = VX_TRUE;

template <typename _Ty>
static VX_CONSTEXPR20 VxBool vx_is_convertible_v<_Ty&, const volatile _Ty&> = VX_TRUE;

template <typename _Ty>
static VX_CONSTEXPR20 VxBool vx_is_convertible_v<volatile _Ty&, const volatile _Ty&> = VX_TRUE;

#endif 


#if VX_HAS_CXX23

template <typename _Ty>
static VX_CONSTEXPR20 VxBool is_scoped_enum_v = vx_conjunction_v<vx_is_enum<_Ty>, vx_negation<vx_is_convertible<_Ty, VxInt32>>>;

template <typename _Ty>
struct vx_is_scoped_enum : vx_bool_constant<vx_is_scoped_enum_v<_Ty>> {};

#endif 


VX_INTERNAL_BEGIN




template <typename _Ty>
struct __VX_IS_MEMFUNPTR__ { 
	using _Bool_type = vx_false_types; 
};





VX_INTERNAL_END


#if defined(VX_COMP_MSVC)
template <typename _Ty>
static VX_CONSTEXPR20 VxBool vx_is_member_function_pointer_v = vertex::internal::__VX_IS_MEMFUNPTR__<vx_remove_cv_t<_Ty>>::_Bool_type::_Value;
#elif defined(VX_COMP_CLANG) || defined(VX_COMP_GCC)
template <typename _Ty>
static VX_CONSTEXPR20 VxBool vx_is_member_function_pointer_v = __is_member_function_pointer(_Ty);
#endif 

// Verifica si una funcion es miembro
template <typename _Ty>
struct vx_is_member_function_pointer : vx_bool_constant<vx_is_member_function_pointer_v<_Ty>> {};


template <typename>
static VX_CONSTEXPR20 VxBool vx_is_const_v = VX_FALSE;

template <typename _Ty>
static VX_CONSTEXPR20 VxBool vx_is_const_v<const _Ty> = VX_TRUE;

// Verifica si un tipo es const
template <typename _Ty>
struct vx_is_const : vx_bool_constant<vx_is_const_v<_Ty>> {};


template <typename>
static VX_CONSTEXPR20 VxBool vx_is_volatile_v = VX_FALSE;

template <typename _Ty>
static VX_CONSTEXPR20 VxBool vx_is_volatile_v<volatile _Ty> = VX_TRUE;

// Verifica si un tipo es volatile
template <typename _Ty>
struct vx_is_volatile : vx_bool_constant<vx_is_volatile_v<_Ty>> {};


template <typename>
static VX_CONSTEXPR20 VxBool vx_is_cv_v = VX_FALSE;

template <typename _Ty>
static VX_CONSTEXPR20 VxBool vx_is_cv_v<const _Ty> = VX_TRUE;

template <typename _Ty>
static VX_CONSTEXPR20 VxBool vx_is_cv_v<volatile _Ty> = VX_TRUE;

template <typename _Ty>
static VX_CONSTEXPR20 VxBool vx_is_cv_v<const volatile _Ty> = VX_TRUE;

// Verifica si un tipo es const volatile
template <typename _Ty>
struct vx_is_volatile : vx_bool_constant<vx_is_volatile_v<_Ty>> {};

// Verifica si un tipo es una funcion
template <typename _Ty>
static VX_CONSTEXPR20 VxBool vx_is_function_v = !vx_is_const_v<const _Ty> && !vx_is_reference_v<_Ty>;

template <typename _Ty>
struct vx_is_function : vx_bool_constant<vx_is_function_v<_Ty>> {};


template <typename _Ty>
static VX_CONSTEXPR20 VxBool vx_is_object_v = vx_is_const_v<const _Ty> && !vx_is_void_v<_Ty>;

// Verfica si un tipo es un objeto
template <typename _Ty>
struct is_object : vx_bool_constant<vx_is_object_v<_Ty>> {};


VX_INTERNAL_BEGIN


template <class>
struct __VX_IS_MEMBER_OBJECT_POINTER__ {
	static VX_CONSTEXPR20 VxBool _Value = VX_FALSE;
};

template <typename _Ty1, typename _Ty2>
struct __VX_IS_MEMBER_OBJECT_POINTER__<_Ty1 _Ty2::*> {
	static VX_CONSTEXPR20 VxBool _Value = !vx_is_function_v<_Ty1>;
	using _Class_type = _Ty2;
};



#if defined(VX_COMP_MSVC)

template <typename _Ty>
VX_CONSTEXPR20 VxBool vx_is_member_object_pointer_v = vertex::internal::__VX_IS_MEMBER_OBJECT_POINTER__<vx_remove_cv_t<_Ty>>::_Value;

#elif defined(VX_COMP_GCC) || defined(VX_COMP_CLANG) 

template <typename _Ty>
VX_CONSTEXPR20 VxBool vx_is_member_object_pointer_v = __is_member_object_pointer(_Ty);

#endif 


#if defined(VX_COMP_CLANG)

template <typename _Ty>
VX_CONSTEXPR20 VxBool vx_is_member_pointer_v = __is_member_pointer(_Ty);

#else 

template <typename _Ty>
VX_CONSTEXPR20 VxBool vx_is_member_pointer_v = vx_is_member_object_pointer_v<_Ty> || 
	vx_is_member_function_pointer_v<_Ty>;

#endif 


template <typename _Ty>
VX_CONSTEXPR20 VxBool vx_is_scalar_v =
vx_is_arithmetic_v<_Ty> || vx_is_enum_v<_Ty> || vx_is_pointer_v<_Ty> ||
	vx_is_member_pointer_v<_Ty> || vx_is_null_pointer_v<_Ty>;


template <typename _Ty>
VX_CONSTEXPR20 VxBool vx_is_empty_v = __is_empty(_Ty);


template <typename _Ty>
VX_CONSTEXPR20 VxBool vx_is_polymorphic_v = __is_polymorphic(_Ty);


template <typename _Ty>
VX_CONSTEXPR20 VxBool vx_is_abstract_v = __is_abstract(_Ty);

template <typename _Ty>
VX_CONSTEXPR20 VxBool vx_is_final_v = __is_final(_Ty);


template <typename _Ty>
VX_CONSTEXPR20 VxBool vx_is_trivial_v = __is_trivial(_Ty);

template <typename _Ty>
VX_CONSTEXPR20 VxBool vx_is_trivially_copyable_v = __is_trivially_copyable(_Ty);

template <typename _Ty>
VX_CONSTEXPR20 VxBool vx_has_virtual_destructor_v = __has_virtual_destructor(_Ty);


template <typename _Ty>
constexpr bool vx_has_unique_object_representations_v = __has_unique_object_representations(_Ty);


template <typename _Ty>
VX_CONSTEXPR20 VxBool vx_is_aggregate_v = __is_aggregate(_Ty);

template <typename _Ty>
struct __Is_aggregate_impl : vx_bool_constant<vx_is_aggregate<_Ty>> {};

template <typename _Ty>
VX_CONSTEXPR20 VxBool __vx_is_aggregate_v = vx_disjunction_v<vx_is_array<_Ty>, __Is_aggregate_impl<_Ty>>;


template <typename _Ty, typename... _Args>
VX_CONSTEXPR20 VxBool vx_is_constructible_v = __is_constructible(_Ty, _Args...);


template <typename _Ty>
VX_CONSTEXPR20 VxBool vx_is_default_constructible_v = __is_constructible(_Ty);


template <typename _Ty, typename = VxVoid>
struct __Is_implicitly_default_constructible__
	: vx_false_types {};

template <typename _Ty>
VxVoid __vx_implicitly_default_construct__(const _Ty&) {
	_Ty _Obj{}; // Construcción por defecto de `_Ty`
	(void)_Obj; // Evita advertencias de variable no usada
}

template <typename _Ty>
struct __Is_implicitly_default_constructible__<_Ty, VxVoid_t<decltype(__vx_implicitly_default_construct__<_Ty>({})) >> : vx_true_types {
};

template <typename _Ty>
VX_CONSTEXPR20 VxBool vx_is_move_constructible_v = __is_constructible(_Ty, _Ty);


template <typename _To, typename _From>
VX_CONSTEXPR20 VxBool vx_is_assignable_v = __is_assignable(_To, _From);

template <class _To, class _From>
using __Is_assignable_no_precondition_check__ = vx_is_assignable<_To, _From>;


template <typename _Ty, VxBool = vx_is_integral_v<_Ty>>
struct __Sign_base__ { 
	using _Uty = vx_remove_cv_t<_Ty>;

	static VX_CONSTEXPR20 VxBool _Signed = static_cast<_Uty>(-1) < static_cast<_Uty>(0);
	static VX_CONSTEXPR20 VxBool _Unsigned = !_Signed;
};


template <typename _Ty>
struct __Sign_base__<_Ty, VX_FALSE> {
	static VX_CONSTEXPR20 VxBool _Signed = vx_is_floating_point_v<_Ty>;
	static VX_CONSTEXPR20 VxBool _Unsigned = VX_FALSE;
};


template <typename _Ty>
VX_CONSTEXPR20 VxBool __Is_nonbool_integral__ = 
	vx_is_integral_v<_Ty> && !vx_is_same_v<vx_remove_cv_t<_Ty>, VxBool>;


template <VxBool>
struct __Select__ {
	template <typename _Ty1, typename>
	using _Apply = _Ty1;
};

template <>
struct __Select__<VX_FALSE> {
	template <typename, typename _Ty2>
	using _Apply = _Ty2;
};


template <VxSize>
struct __Make_signed2__ {};


template <>
struct __Make_signed2__<1> {
	template <typename>
	using _Apply = signed char;
};

template <>
struct __Make_signed2__<2> {
	template <typename>
	using _Apply = signed short;
};

template <>
struct __Make_signed2__<4> {
	template <typename _Ty>
	using _Apply = 
		typename vertex::internal::__Select__<vx_is_same_v<_Ty, long> || 
		vx_is_same_v<_Ty, unsigned long>>::template _Apply<long, int>;
};

template <>
struct __Make_signed2__<8> {
	template <typename>
	using _Apply = long long;
};

template <typename _Ty>
using __Make_signed1__ = typename __Make_signed2__<sizeof(_Ty)>::template _Apply<_Ty>;





VX_INTERNAL_END


template <typename _Ty>
struct vx_is_member_pointer 
	: vx_bool_constant<vx_is_member_pointer_v<_Ty>> {};

template <typename _Ty>
struct vx_is_scalar 
	: vx_bool_constant<vx_is_scalar_v<_Ty>> {};

template <typename _Ty>
struct vx_is_empty 
	: vx_bool_constant<vx_is_empty_v<_Ty>> {};

template <typename _Ty>
struct vx_is_polymorphic 
	: vx_bool_constant<vx_is_polymorphic_v<_Ty>> {};

template <typename _Ty>
struct vx_is_abstract 
	: vx_bool_constant<vx_is_abstract_v<_Ty>> {};

template <typename _Ty>
struct vx_is_final 
	: vx_bool_constant<vx_is_final_v<_Ty>> {};

template <typename _Ty>
struct is_trivial 
	: vx_bool_constant<vx_is_trivial_v<_Ty>> {}; 

template <typename _Ty>
struct vx_is_trivially_copyable 
	: vx_bool_constant<vx_is_trivially_copyable_v<_Ty>> {};

template <typename _Ty>
struct vx_has_virtual_destructor 
	: vx_bool_constant<vx_has_virtual_destructor_v<_Ty>> {};

template <typename _Ty>
struct vx_is_member_object_pointer 
	: vx_bool_constant<vx_is_member_object_pointer_v<_Ty>> {};


#if VX_HAS_CXX17

template <typename _Ty>
struct vx_has_unique_object_representations 
	: vx_bool_constant<
		vertex::internal::vx_has_unique_object_representations_v<_Ty>
	  > {};


template <typename _Ty>
struct vx_is_aggregate 
	: vx_bool_constant<vertex::internal::__vx_is_aggregate_v<_Ty>> {};


#endif 


template <typename _Ty, typename... _Args>
struct vx_is_constructible 
	: vx_bool_constant<vertex::internal::vx_is_constructible_v<_Ty, _Args...>> {};



template <typename _Ty>
struct vx_is_copy_constructible 
	: vx_bool_constant<
		vertex::internal::vx_is_constructible_v<_Ty, 
			vx_add_ref_lvalue_t<const _Ty>>> 
	{
    };


template <typename _Ty>
struct is_default_constructible 
	: vx_bool_constant<vx_is_default_constructible_v<_Ty>> {};


template <class _Ty>
struct is_copy_assignable
	: vx_bool_constant<vertex::internal::vx_is_assignable_v<
		vx_add_ref_lvalue_t<_Ty>, vx_add_ref_lvalue_t<const _Ty>>
	  > {};


template <typename _Ty>
struct vx_is_signed 
	: vx_bool_constant<vertex::internal::__Sign_base__<_Ty>::_Signed> 
	{
	};


template <typename _Ty>
VX_CONSTEXPR20 VxBool vx_is_signed_v = 
	vertex::internal::__Sign_base__<_Ty>::_Signed;


template <typename _Ty>
struct vx_is_unsigned 
	: vx_bool_constant<vertex::internal::__Sign_base__<_Ty>::_Unsigned> 
	{
	};




VX_END





#endif

#endif