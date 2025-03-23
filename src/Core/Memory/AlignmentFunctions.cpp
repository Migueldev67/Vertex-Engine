

#include "VxAlign.h"




/**
 * Verifica si un valor es una potencia de 2, lo que indica si es una alineacion valida.
 * La operacion (_Value & (_Value - 1)) == 0 devuelve verdadero solo si _Value es una potencia de 2.
 * Ejemplo:
 *  8 (1000 en binario) & (7 -> 0111) = 0000 -> true (es potencia de 2)
 * 10 (1010 en binario) & (9 -> 1001) = 1000 -> false (no es potencia de 2)
 */
VX_CONSTEXPR20 VxBool vxIsAlignment(VxSize _Value) noexcept {
	return (_Value > 0) && ((_Value & (_Value - 1)) == 0);
}

/**
 * Verifica si un puntero esta alineado a un valor especifico.
 * Se usa una mascara binaria para verificar si la direccion del puntero
 * es un multiplo exacto de _Alignment.
 */
inline VxBool vxIsAligned(const volatile VxVoidPtr _Ptr, VxSize _Alignment) noexcept {
	VX_ASSERT(vxIsAlignment(_Alignment));
	return (reinterpret_cast<VxSize>(_Ptr) & (_Alignment - 1)) == 0;
}

inline VxBool vxIsAligned(VxSize _Alignment, const volatile VxVoidPtr _Ptr) noexcept {
	VX_ASSERT(vxIsAlignment(_Alignment));
	return (reinterpret_cast<VxSize>(_Ptr) & (_Alignment - 1)) == 0;
}

/**
 * Alinea un puntero a la siguiente direccion valida basada en _Alignment.
 * La operacion usa una mascara de bits para redondear la direccion hacia arriba.
 * Ejemplo:
 *  Direccion inicial:  0000 0000 0000 0110 (6 en decimal)
 *  Alineacion:         0000 0000 0000 0100 (4 en decimal)
 *  Mascara:            1111 1111 1111 1011 (~3)
 *  Resultado:          0000 0000 0000 0100 (redondeado a 4)
 */
inline VxVoidPtr vxAlign(VxSize _Alignment, VxSize _Size, VxVoidPtr& _Ptr, VxSize _Space) {
	VX_ASSERT(vxIsAlignment(_Alignment));
	if (_Size <= _Space) {
		VxChar* _P = reinterpret_cast<VxChar*>(~(_Alignment - 1) &
			(reinterpret_cast<VxSize>(_Ptr) + _Alignment - 1));
		VxSize _N = _P - static_cast<VxChar*>(_Ptr);
		if (_N <= _Space - _Size) {
			_Ptr = _P;
			_Space -= _N;
			return _P;
		}
	}
	return 0;
}

/**
 * Reserva memoria alineada segun el sistema operativo y la plataforma.
 * En Android usa memalign, en MSVC usa _aligned_malloc,
 * en Linux y macOS usa posix_memalign.
 */
inline VxVoidPtr vxAlignedAlloc(VxSize _Alignment, VxSize _Size) noexcept {
	VX_ASSERT(vxIsAlignment(_Alignment));

	if (_Size == 0) {
		return nullptr;
	}

#if defined(VX_PLATFORM_ANDROID)
	return ::memalign(_Alignment, _Size);
#elif defined(VX_COMP_MSVC)
	return ::_aligned_malloc(_Size, _Alignment);
#elif defined(VX_PLATFORM_MACOS) || defined(VX_PLATFORM_LINUX)
	if (_Alignment < vertex::vertex::internal::__Size_of__<VxVoidPtr>::_Size) {
		_Alignment = vertex::vertex::internal::__Size_of__<VxVoidPtr>::_Size;
	}
	VxVoidPtr _Ptr = nullptr;
	if (::posix_memalign(&_Ptr, _Alignment, _Size) != 0) {
		_Ptr = nullptr;
	}
	return _Ptr;
#endif

#if defined(VX_USE_OPERATOR_NEW_FOR_ALLOCATIONS)
	VX_ASSERT(vxIsAlignment(_Alignment));

	enum { VX_ALIGNMENT_OF_VALUE = vx_alignment_of<VxVoidPtr>::_Value };
	if (_Alignment < VX_ALIGNMENT_OF_VALUE) {
		_Alignment = VX_ALIGNMENT_OF_VALUE;
	}

	VxSize _N = _Size + _Alignment - VX_ALIGNMENT_OF_VALUE;
	VxVoidPtr _Ptr = ::operator new(vertex::vertex::internal::__Size_of__<VxVoidPtr>::_Size + _N, std::nothrow);

	if (_Ptr) {
		VxVoidPtr _R = static_cast<VxChar*>(_Ptr) + vertex::vertex::internal::__Size_of__<VxVoidPtr>::_Size;

		if (!vxAlign(_Alignment, _Size, _R, _N)) {
			::operator delete(_Ptr);
			return nullptr;
		}

		*(static_cast<VxVoidPtr*>(_R) - 1) = _Ptr;
		_Ptr = _R;
	}
	return _Ptr;
#endif

	return nullptr;
}

/**
 * Libera memoria alineada y borra los datos antes de liberar para mayor seguridad.
 * Usa memset para evitar datos residuales en la memoria.
 */
inline VxVoid vxAlignedFree(VxVoidPtr& _Ptr) noexcept {
	if (!_Ptr) return;

#if defined(VX_USE_OPERATOR_NEW_FOR_ALLOCATIONS)
	VxVoidPtr originalPtr = *(static_cast<VxVoidPtr*>(_Ptr) - 1);
	::memset(originalPtr, 0, vertex::vertex::internal::__Size_of__<VxVoidPtr>::_Size);
	::operator delete(originalPtr);
#else
#if defined(VX_COMP_MSVC)
	::memset(_Ptr, 0, vertex::vertex::internal::__Size_of__<VxVoidPtr>::_Size);
	::_aligned_free(_Ptr);
#elif defined(VX_PLATFORM_LINUX) || defined(VX_PLATFORM_MACOS) || defined(VX_PLATFORM_ANDROID)
	::memset(_Ptr, 0, vertex::vertex::internal::__Size_of__<VxVoidPtr>::_Size);
	::free(_Ptr);
#endif
#endif

	_Ptr = nullptr;
}