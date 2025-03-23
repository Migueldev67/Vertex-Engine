

#ifndef VX_LIMITS_H
#define VX_LIMITS_H


#include "../src/Core/VxPackCore.h"



VX_BEGIN

#if defined(VX_CPLUSPLUS)


VX_INTERNAL_BEGIN

enum class VxFloatRoundStyle : VxByte {
	VX_FLOAT_ROUND_STYLE_ROUND_INDETERMINATE,
	VX_FLOAT_ROUND_STYLE_ROUND_TOWARD_ZERO,
	VX_FLOAT_ROUND_STYLE_ROUND_TO_NEAREST,
	VX_FLOAT_ROUND_STYLE_ROUND_TOWARD_INFINITY,
	VX_FLOAT_ROUND_STYLE_ROUND_TOWARD_NEG_INFINITY,


	VX_FLOAT_ROUND_STYLE_MAX_ENUM = VX_MAX_ENUM_8_BITS_UNSIGNED
};




struct __Num_base__ {
	static VX_CONSTEXPR20 VxBool _Has_quiet_NaN = VX_FALSE;
	static VX_CONSTEXPR20 VxBool _Has_infinity = VX_FALSE;
	static VX_CONSTEXPR20 VxBool _Is_exact = VX_FALSE;
	static VX_CONSTEXPR20 VxBool _Is_iec559 = VX_FALSE;
	static VX_CONSTEXPR20 VxBool _Has_signaling_NaN = VX_FALSE;
	static VX_CONSTEXPR20 VxBool _Is_bounded = VX_FALSE;
	static VX_CONSTEXPR20 VxBool _Is_integer = VX_FALSE;
	static VX_CONSTEXPR20 VxBool _Is_modulo = VX_FALSE;
	static VX_CONSTEXPR20 VxBool _Is_signed = VX_FALSE;
	static VX_CONSTEXPR20 VxBool _Tinyness_before = VX_FALSE;
	static VX_CONSTEXPR20 VxBool _Traps = VX_FALSE;
	static VX_CONSTEXPR20 VxBool _Is_specialized = VX_FALSE;
	static VX_CONSTEXPR20 VxFloatRoundStyle _Round_style = VxFloatRoundStyle::VX_FLOAT_ROUND_STYLE_ROUND_TOWARD_ZERO;
	static VX_CONSTEXPR20 VxInt32 _Digits = 0;
	static VX_CONSTEXPR20 VxInt32 _Max_digits10 = 0;
	static VX_CONSTEXPR20 VxInt32 _Digits10 = 0;
	static VX_CONSTEXPR20 VxInt32 _Max_exponent = 0;
	static VX_CONSTEXPR20 VxInt32 _Max_exponent10 = 0;
	static VX_CONSTEXPR20 VxInt32 _Min_exponent10 = 0;
	static VX_CONSTEXPR20 VxInt32 _Radix = 0;
	static VX_CONSTEXPR20 VxInt32 _Min_exponent = 0;
} _Num_base;

// Base para enteros
struct __Num_int_base__ {
	static VX_CONSTEXPR20 VxBool _Is_bounded = VX_TRUE;
	static VX_CONSTEXPR20 VxBool _Is_exact = VX_TRUE;
	static VX_CONSTEXPR20 VxBool _Is_integer = VX_TRUE;
	static VX_CONSTEXPR20 VxBool _Is_especialized = VX_TRUE;
	static VX_CONSTEXPR20 VxInt32 _Radix = 2;
};

// Base para punto flotante
struct __Num_float_base__ : __Num_base__ { 
	static VX_CONSTEXPR20 VxBool _Has_infinity = VX_TRUE;
	static VX_CONSTEXPR20 VxBool _Has_quiet_NaN = VX_TRUE;
	static VX_CONSTEXPR20 VxBool _Has_signaling_NaN = VX_TRUE;
	static VX_CONSTEXPR20 VxBool _Is_bounded = VX_TRUE;
	static VX_CONSTEXPR20 VxBool _Is_iec559 = VX_TRUE;
	static VX_CONSTEXPR20 VxBool _Is_signed = VX_TRUE;
	static VX_CONSTEXPR20 VxBool _Is_specialized = VX_TRUE;
	static VX_CONSTEXPR20 VxFloatRoundStyle _Round_style = VxFloatRoundStyle::VX_FLOAT_ROUND_STYLE_ROUND_TOWARD_ZERO;
	static VX_CONSTEXPR20 VxInt32 _Radix = VX_FLOAT_RADIX;
};







VX_INTERNAL_END


VX_BEGIN


template <typename _Ty>
class VxNumericLimits : vertex::internal::_Num_base__ {
public:

	VX_NODISCARD static VX_CONSTEXPR20 _Ty(max)() noexcept {
		return _Ty();
	}

	VX_NODISCARD static VX_CONSTEXPR20 _Ty lowest() noexcept {
		return _Ty();
	}

	VX_NODISCARD static VX_CONSTEXPR20 _Ty(min)() noexcept {
		return _Ty();
	}


	VX_NODISCARD static VX_CONSTEXPR20 _Ty roundError() noexcept {
		return _Ty();
	}

	VX_NODISCARD static VX_CONSTEXPR20 _Ty epsilon() noexcept {
		return _Ty();
	}


	VX_NODISCARD static VX_CONSTEXPR20 _Ty denormMin() noexcept {
		return _Ty();
	}

	VX_NODISCARD static VX_CONSTEXPR20 _Ty quietNaN() noexcept {
		return _Ty();
	}

	VX_NODISCARD static VX_CONSTEXPR20 _Ty signalingNaN() noexcept {
		return _Ty();
	}

	VX_NODISCARD static VX_CONSTEXPR20 _Ty infinity() noexcept {
		return _Ty();
	}

};

// Para tipos const volatile
template <typename _Ty>
class VxNumericLimits<const _Ty> : public VxNumericLimits<_Ty> {};

template <typename _Ty>
class VxNumericLimits<volatile _Ty> : public VxNumericLimits<_Ty> {};

template <typename _Ty>
class VxNumericLimits<const volatile _Ty> : public VxNumericLimits<_Ty> {};


template <>
class VxNumericLimits<VxChar> : vertex::internal::__Num_int_base__ {
public:

	static VX_CONSTEXPR20 VxBool _Is_signed = VX_INT8_MIN != 0;
	static VX_CONSTEXPR20 VxBool _Is_modulo = VX_INT8_MIN == 0;
	static VX_CONSTEXPR20 VxInt32 _Digits = 8 - (VX_INT8_MIN != 0);
	static VX_CONSTEXPR20 VxInt32 _Digits10 = 2;


	VX_NODISCARD static VX_CONSTEXPR20 VxChar(min)() noexcept {
		return VX_INT8_MIN;
	}

	VX_NODISCARD static VX_CONSTEXPR20 VxChar(max)() noexcept {
		return VX_INT8_MAX;
	}

	VX_NODISCARD static VX_CONSTEXPR20 VxChar lowest() noexcept {
		return (min)();
	}

	VX_NODISCARD static VX_CONSTEXPR20 VxChar epsilon() noexcept {
		return 0;
	}

	VX_NODISCARD static VX_CONSTEXPR20 VxChar roundError() noexcept {
		return 0;
	}

	VX_NODISCARD static VX_CONSTEXPR20 VxChar denomMin() noexcept {
		return 0;
	}

	VX_NODISCARD static VX_CONSTEXPR20 VxChar infinity() noexcept {
		return 0;
	}

	VX_NODISCARD static VX_CONSTEXPR20 VxChar quietNaN() noexcept {
		return 0;
	}

	VX_NODISCARD static VX_CONSTEXPR20 VxChar signalignNaN() noexcept {
		return 0;
	}

};


template <>
class VxNumericLimits<VxUchar> : vertex::internal::__Num_int_base__ {
public:

	static VX_CONSTEXPR20 VxBool _Is_modulo = VX_TRUE;
	static VX_CONSTEXPR20 VxInt32 _Digits = 8;
	static VX_CONSTEXPR20 VxInt32 _Digits10 = 2;

	VX_NODISCARD static VX_CONSTEXPR20 VxUchar(min)() noexcept {
		return 0;
	}

	VX_NODISCARD static VX_CONSTEXPR20 VxUchar(max)() noexcept {
		return VX_UINT8_MAX;
	}

	VX_NODISCARD static VX_CONSTEXPR20 VxUchar lowest() noexcept {
		return (min)();
	}

	VX_NODISCARD static VX_CONSTEXPR20 VxUchar epsilon() noexcept {
		return 0;
	}

	VX_NODISCARD static VX_CONSTEXPR20 VxUchar roundError() noexcept {
		return 0;
	}

	VX_NODISCARD static VX_CONSTEXPR20 VxUchar denomMin() noexcept {
		return 0;
	}

	VX_NODISCARD static VX_CONSTEXPR20 VxUchar infinity() noexcept {
		return 0;
	}

	VX_NODISCARD static VX_CONSTEXPR20 VxUchar quietNaN() noexcept {
		return 0;
	}

	VX_NODISCARD static VX_CONSTEXPR20 VxUchar signalignNaN() noexcept {
		return 0;
	}

};


template <>
class VxNumericLimits<VxInt16> : vertex::internal::__Num_int_base__ {
public:

	static VX_CONSTEXPR20 VxBool _Is_signed = VX_TRUE;
	static VX_CONSTEXPR20 VxInt32 _Digits = 15;
	static VX_CONSTEXPR20 VxInt32 _Digits10 = 4;

	VX_NODISCARD static VX_CONSTEXPR20 VxInt16(min)() noexcept {
		return VX_INT16_MIN;					   
	}	

	VX_NODISCARD static VX_CONSTEXPR20 VxInt16(max)() noexcept {
		return VX_INT16_MAX;		   
	}	

	VX_NODISCARD static VX_CONSTEXPR20 VxInt16 lowest() noexcept {
		return (min)();				   
	}	

	VX_NODISCARD static VX_CONSTEXPR20 VxInt16 epsilon() noexcept {
		return 0;					  
	}	

	VX_NODISCARD static VX_CONSTEXPR20 VxInt16 roundError() noexcept {
		return 0;					   
	}								   

	VX_NODISCARD static VX_CONSTEXPR20 VxInt16 denomMin() noexcept {
		return 0;					   
	}							

	VX_NODISCARD static VX_CONSTEXPR20 VxInt16 infinity() noexcept {
		return 0;					   
	}						

	VX_NODISCARD static VX_CONSTEXPR20 VxInt16 quietNaN() noexcept {
		return 0;					  
	}					

	VX_NODISCARD static VX_CONSTEXPR20 VxInt16 signalignNaN() noexcept {
		return 0;
	}

};

template <>
class VxNumericLimits<VxInt32> : vertex::internal::__Num_int_base__ {
public:

	static VX_CONSTEXPR20 VxBool _Is_signed = VX_TRUE;
	static VX_CONSTEXPR20 VxInt32 _Digits = 31;
	static VX_CONSTEXPR20 VxInt32 _Digits10 = 9;

	VX_NODISCARD static VX_CONSTEXPR20 VxInt32(min)() noexcept {
		return VX_INT32_MIN;
	}

	VX_NODISCARD static VX_CONSTEXPR20 VxInt32(max)() noexcept {
		return VX_INT32_MAX;
	}

	VX_NODISCARD static VX_CONSTEXPR20 VxInt32 lowest() noexcept {
		return (min)();
	}

	VX_NODISCARD static VX_CONSTEXPR20 VxInt32 epsilon() noexcept {
		return 0;
	}

	VX_NODISCARD static VX_CONSTEXPR20 VxInt32 roundError() noexcept {
		return 0;
	}

	VX_NODISCARD static VX_CONSTEXPR20 VxInt32 denomMin() noexcept {
		return 0;
	}

	VX_NODISCARD static VX_CONSTEXPR20 VxInt32 infinity() noexcept {
		return 0;
	}

	VX_NODISCARD static VX_CONSTEXPR20 VxInt32 quietNaN() noexcept {
		return 0;
	}

	VX_NODISCARD static VX_CONSTEXPR20 VxInt32 signalignNaN() noexcept {
		return 0;
	}

};


template <>
class VxNumericLimits<VxInt64> : vertex::internal::__Num_int_base__ {
public:

	static VX_CONSTEXPR20 VxBool _Is_signed = VX_TRUE;
	static VX_CONSTEXPR20 VxInt32 _Digits = 31;
	static VX_CONSTEXPR20 VxInt32 _Digits10 = 9;

	VX_NODISCARD static VX_CONSTEXPR20 VxInt64(min)() noexcept {
		return VX_INT64_MIN;
	}

	VX_NODISCARD static VX_CONSTEXPR20 VxInt64(max)() noexcept {
		return VX_INT64_MAX;
	}

	VX_NODISCARD static VX_CONSTEXPR20 VxInt64 lowest() noexcept {
		return (min)();
	}

	VX_NODISCARD static VX_CONSTEXPR20 VxInt64 epsilon() noexcept {
		return 0;
	}

	VX_NODISCARD static VX_CONSTEXPR20 VxInt64 roundError() noexcept {
		return 0;
	}

	VX_NODISCARD static VX_CONSTEXPR20 VxInt64 denomMin() noexcept {
		return 0;
	}

	VX_NODISCARD static VX_CONSTEXPR20 VxInt64 infinity() noexcept {
		return 0;
	}

	VX_NODISCARD static VX_CONSTEXPR20 VxInt64 quietNaN() noexcept {
		return 0;
	}

	VX_NODISCARD static VX_CONSTEXPR20 VxInt64 signalignNaN() noexcept {
		return 0;
	}

};


template <>
class VxNumericLimits<VxUint16> : vertex::internal::__Num_int_base__ {
public:

	static VX_CONSTEXPR20 VxBool _Is_modulo = VX_TRUE;
	static VX_CONSTEXPR20 VxInt32 _Digits = 16;
	static VX_CONSTEXPR20 VxInt32 _Digits10 = 4;

	VX_NODISCARD static VX_CONSTEXPR20 VxUint16(min)() noexcept {
		return 0;
	}

	VX_NODISCARD static VX_CONSTEXPR20 VxUint16(max)() noexcept {
		return VX_UINT16_MAX;
	}

	VX_NODISCARD static VX_CONSTEXPR20 VxUint16 lowest() noexcept {
		return (min)();
	}

	VX_NODISCARD static VX_CONSTEXPR20 VxUint16 epsilon() noexcept {
		return 0;
	}

	VX_NODISCARD static VX_CONSTEXPR20 VxUint16 roundError() noexcept {
		return 0;
	}

	VX_NODISCARD static VX_CONSTEXPR20 VxUint16 denomMin() noexcept {
		return 0;
	}

	VX_NODISCARD static VX_CONSTEXPR20 VxUint16 infinity() noexcept {
		return 0;
	}

	VX_NODISCARD static VX_CONSTEXPR20 VxUint16 quietNaN() noexcept {
		return 0;
	}

	VX_NODISCARD static VX_CONSTEXPR20 VxUint16 signalignNaN() noexcept {
		return 0;
	}

};

template <>
class VxNumericLimits<VxUint32> : vertex::internal::__Num_int_base__ {
public:

	static VX_CONSTEXPR20 VxBool _Is_modulo = VX_TRUE;
	static VX_CONSTEXPR20 VxInt32 _Digits = 32;
	static VX_CONSTEXPR20 VxInt32 _Digits10 = 9;

	VX_NODISCARD static VX_CONSTEXPR20 VxUint32(min)() noexcept {
		return 0;
	}

	VX_NODISCARD static VX_CONSTEXPR20 VxUint32(max)() noexcept {
		return VX_UINT32_MAX;
	}

	VX_NODISCARD static VX_CONSTEXPR20 VxUint32 lowest() noexcept {
		return (min)();
	}

	VX_NODISCARD static VX_CONSTEXPR20 VxUint32 epsilon() noexcept {
		return 0;
	}

	VX_NODISCARD static VX_CONSTEXPR20 VxUint32 roundError() noexcept {
		return 0;
	}

	VX_NODISCARD static VX_CONSTEXPR20 VxUint32 denomMin() noexcept {
		return 0;
	}

	VX_NODISCARD static VX_CONSTEXPR20 VxUint32 infinity() noexcept {
		return 0;
	}

	VX_NODISCARD static VX_CONSTEXPR20 VxUint32 quietNaN() noexcept {
		return 0;
	}

	VX_NODISCARD static VX_CONSTEXPR20 VxUint32 signalignNaN() noexcept {
		return 0;
	}

};


template <>
class VxNumericLimits<VxUint64> : vertex::internal::__Num_int_base__ {
public:

	static VX_CONSTEXPR20 VxBool _Is_module = VX_TRUE;
	static VX_CONSTEXPR20 VxInt32 _Digits = 32;
	static VX_CONSTEXPR20 VxInt32 _Digits10 = 4;

	VX_NODISCARD static VX_CONSTEXPR20 VxUint64(min)() noexcept {
		return 0;
	}

	VX_NODISCARD static VX_CONSTEXPR20 VxUint64(max)() noexcept {
		return VX_UINT64_MAX;
	}

	VX_NODISCARD static VX_CONSTEXPR20 VxUint64 lowest() noexcept {
		return (min)();
	}

	VX_NODISCARD static VX_CONSTEXPR20 VxUint64 epsilon() noexcept {
		return 0;
	}

	VX_NODISCARD static VX_CONSTEXPR20 VxUint64 roundError() noexcept {
		return 0;
	}

	VX_NODISCARD static VX_CONSTEXPR20 VxUint64 denomMin() noexcept {
		return 0;
	}

	VX_NODISCARD static VX_CONSTEXPR20 VxUint64 infinity() noexcept {
		return 0;
	}

	VX_NODISCARD static VX_CONSTEXPR20 VxUint64 quietNaN() noexcept {
		return 0;
	}

	VX_NODISCARD static VX_CONSTEXPR20 VxUint64 signalignNaN() noexcept {
		return 0;
	}

};

template <>
class VxNumericLimits<VxFloat> : public vertex::internal::__Num_float_base__ {
public:

	static VX_CONSTEXPR20 VxInt32 _Digits = 24;
	static VX_CONSTEXPR20 VxInt32 _Digits10 = 6;
	static VX_CONSTEXPR20 VxInt32 _Max_digits10 = 9;
	static VX_CONSTEXPR20 VxInt32 _Max_exponent = 128;
	static VX_CONSTEXPR20 VxInt32 _Max_exponent10 = 38;
	static VX_CONSTEXPR20 VxInt32 _Min_exponent = -125;
	static VX_CONSTEXPR20 VxInt32 _Min_exponent10 = -37;

	VX_NODISCARD static VX_CONSTEXPR20 VxFloat(min)() noexcept {
		return VX_FLOAT_MIN;
	}

	VX_NODISCARD static VX_CONSTEXPR20 VxFloat(max)() noexcept {
		return VX_FLOAT_MAX;
	}

	VX_NODISCARD static VX_CONSTEXPR20 VxFloat lowest() noexcept {
		return -(max)();
	}

	VX_NODISCARD static constexpr VxFloat epsilon() noexcept {
		return VX_FLOAT_EPSILON;
	}

	VX_NODISCARD static constexpr VxFloat roundError() noexcept {
		return 0.5F;
	}

	VX_NODISCARD static VX_CONSTEXPR20 VxFloat denormMin() noexcept {
		return VX_FLOAT_MIN;
	}

	VX_NODISCARD static VX_CONSTEXPR20 VxFloat infinity() noexcept {
#if defined(VX_COMP_MSVC)
		return __builtin_huge_valf();
#elif defined(VX_COMP_GCC)

#endif
	}

	VX_NODISCARD static VX_CONSTEXPR20 VxFloat quietNaN() noexcept {
#if defined(VX_COMP_MSVC)
		return __builtin_nansf("0");
#elif defined(VX_COMP_GCC)

#endif
	}

	VX_NODISCARD static VX_CONSTEXPR20 VxFloat signalingNaN() noexcept {
#if defined(VX_COMP_MSVC)
		return __builtin_nansf("1");
#elif defined(VX_COMP_GCC)

#endif
	}

};


template <>
class VxNumericLimits<VxDouble> : public vertex::internal::__Num_float_base__ {
public:

	static VX_CONSTEXPR20 VxInt32 _Digits = 53;
	static VX_CONSTEXPR20 VxInt32 _Digits10 = 15;
	static VX_CONSTEXPR20 VxInt32 _Max_digits10 = 17;
	static VX_CONSTEXPR20 VxInt32 _Max_exponent = 1024;
	static VX_CONSTEXPR20 VxInt32 _Max_exponent10 = 3080;
	static VX_CONSTEXPR20 VxInt32 _Min_exponent = 1021;
	static VX_CONSTEXPR20 VxInt32 _Min_exponent10 = -307;


	VX_NODISCARD static VX_CONSTEXPR20 VxDouble(min)() noexcept {
		return VX_DOUBLE_MIN;
	}

	VX_NODISCARD static VX_CONSTEXPR20 VxDouble(max)() noexcept {
		return VX_DOUBLE_MAX;
	}

	VX_NODISCARD static VX_CONSTEXPR20 VxDouble lowest() noexcept {
		return -(max)();
	}

	VX_NODISCARD static VX_CONSTEXPR20 VxDouble epsilon() noexcept {
		return VX_DOUBLE_EPSILON;
	}

	VX_NODISCARD static VX_CONSTEXPR20 VxDouble roundError() noexcept {
		return 0.5;
	}

	VX_NODISCARD static VX_CONSTEXPR20 VxDouble denormMin() noexcept {
		return VX_DOUBLE_TRUE_MIN;
	}

	VX_NODISCARD static VX_CONSTEXPR20 VxDouble infinity() noexcept {
#if defined(VX_COMP_MSVC)
		return __builtin_huge_val();
#elif defined(VX_COMP_GCC)

#endif
	}

	VX_NODISCARD static VX_CONSTEXPR20 VxDouble quietNaN() noexcept {
#if defined(VX_COMP_MSVC)
		return __builtin_nan("0");
#elif defined(VX_COMP_GCC)

#endif
	}

	VX_NODISCARD static VX_CONSTEXPR20 VxDouble signalingNaN() noexcept {
#if defined(VX_COMP_MSVC)
		return __builtin_nans("1");
#elif defined(VX_COMP_GCC)

#endif
	}

	
};



#endif

VX_END



#endif