

#include "VxBitFunctions.h"




_VX_CONSTEXPR _VX_INLINE VxUint32 __vx_bit_left_shift__(VxUint32 _Val, VxUint32 _Pos) {
    return VX_BIT_LEFT_SHIFT(_Val, _Pos);
}

_VX_CONSTEXPR _VX_INLINE VxUint32 __vx_bit_right_shift__(VxUint32 _Val, VxUint32 _Pos) {
    return VX_BIT_RIGHT_SHIFT(_Val, _Pos);
}

_VX_CONSTEXPR _VX_INLINE VxUint32 __vx_bit_set__(VxUint32 _Val, VxUint32 _Pos) {
    return VX_BIT_SET(_Val, _Pos);
}

_VX_CONSTEXPR _VX_INLINE VxUint32 __vx_bit_clear__(VxUint32 _Val, VxUint32 _Pos) {
    return VX_BIT_CLEAR(_Val, _Pos);
}

_VX_CONSTEXPR _VX_INLINE VxUint32 __vx_bit_toggle__(VxUint32 _Val, VxUint32 _Pos) {
    return VX_BIT_TOGGLE(_Val, _Pos);
}

_VX_CONSTEXPR _VX_INLINE VxUint32 __vx_get_bit__(VxUint32 _Val, VxUint32 _Pos) {
    return VX_BIT_GET(_Val, _Pos);
}

_VX_CONSTEXPR _VX_INLINE VxUint32 __vx_bit_check__(VxUint32 _Val, VxUint32 _Pos) {
    return VX_BIT_CHECK(_Val, _Pos);
}

_VX_CONSTEXPR _VX_INLINE VxUint32 __vx_bit_set_mask__(VxUint32 _Val, VxUint32 _Mask) {
    return VX_BIT_SET_MASK(_Val, _Mask);
}

_VX_CONSTEXPR _VX_INLINE VxUint32 __vx_bit_clear_mask__(VxUint32 _Val, VxUint32 _Mask) {
    return VX_BIT_CLEAR_MASK(_Val, _Mask);
}

_VX_CONSTEXPR _VX_INLINE VxUint32 __vx_bit_rotate_left__(VxUint32 _Val, VxUint32 _Pos) {
    return VX_BIT_ROTATE_LEFT(_Val, _Pos);
}

_VX_CONSTEXPR _VX_INLINE VxUint32 __vx_bit_rotate_right__(VxUint32 _Val, VxUint32 _Pos) {
    return VX_BIT_ROTATE_RIGHT(_Val, _Pos);
}

_VX_CONSTEXPR _VX_INLINE VxUint32 __vx_count_ones__(VxUint32 _Val) {
    VxUint32 count = 0;
    while (_Val) {
        count += _Val & 1;
        _Val >>= 1;
    }
    return count;
}

_VX_CONSTEXPR _VX_INLINE VxUint32 __vx_find_msb__(VxUint32 _Val) {
    if (_Val == 0) return 0;
    VxUint32 pos = 0;
    while (_Val >>= 1) {
        pos++;
    }
    return pos;
}

_VX_CONSTEXPR _VX_INLINE VxUint32 __vx_find_lsb__(VxUint32 _Val) {
    if (_Val == 0) return 0;
    VxUint32 pos = 0;
    while (!(_Val & 1)) {
        _Val >>= 1;
        pos++;
    }
    return pos;
}