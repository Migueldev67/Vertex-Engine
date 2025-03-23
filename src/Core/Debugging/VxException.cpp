



#include "Core/Debugging/VxException.h"
#include <cstring>




VX_API void VX_CDECL __vxExceptionPtrCreate(VxVoidPtr _Ptr) noexcept {
    if (_Ptr) {
        *static_cast<VxExceptionPtrCallback*>(_Ptr) = nullptr;
    }
}

VX_API void VX_CDECL __vxExceptionPtrDestroy(VxVoidPtr _Ptr) noexcept {
    if (_Ptr) {
        *static_cast<VxExceptionPtrCallback*>(_Ptr) = nullptr;
    }
}

VX_API void VX_CDECL __vxExceptionPtrCopy(VxVoidPtr _Dest, const VxVoidPtr _Src) noexcept {
    if (_Dest && _Src) {
        *static_cast<VxExceptionPtrCallback*>(_Dest) = 
            *static_cast<VxExceptionPtrCallback const*>(_Src);
    }
}

VX_API void VX_CDECL __vxExceptionPtrAssign(VxVoidPtr _Dest, const VxVoidPtr _Src) noexcept {
    if (_Dest && _Src) {
        *static_cast<VxExceptionPtrCallback*>(_Dest) =
            *static_cast<VxExceptionPtrCallback const*>(_Src);
    }
}

VX_API bool VX_CDECL __vxExceptionPtrCompare(const VxVoidPtr _Ins1, const VxVoidPtr _Ins2) noexcept {
    return _Ins1 == _Ins2;
}

VX_API bool VX_CDECL __vxExceptionPtrToBool(const VxVoidPtr _Ptr) noexcept {
    return _Ptr != nullptr;
}

VX_API void VX_CDECL __vxExceptionPtrSwap(VxVoidPtr _Ins1, VxVoidPtr _Ins2) noexcept {
    if (_Ins1 && _Ins2) {
        VxExceptionPtrCallback _Temp = 
            *static_cast<VxExceptionPtrCallback*>(_Ins1);
        *static_cast<VxExceptionPtrCallback*>(_Ins1) 
            = *static_cast<VxExceptionPtrCallback*>(_Ins2);
        *static_cast<VxExceptionPtrCallback*>(_Ins2) = _Temp;
    }
}

VX_API void VX_CDECL __vxExceptionPtrCurrentException(VxVoidPtr _Ptr) noexcept {
    if (_Ptr) {
        *static_cast<VxExceptionPtrCallback*>(_Ptr) = nullptr;
    }
}

VX_NORETURN void VX_CDECL __vxExceptionPtrRethrow(const VxVoidPtr _Ptr) {
    if (_Ptr) {
        
    }
    while (true) {} // Bucle infinito para evitar comportamiento indefinido
}

VX_API void VX_CDECL __vxExceptionPtrCopyException(VxVoidPtr _Dest, const VxVoidPtr _Src, const VxVoidPtr _Type) noexcept {
    if (_Dest && _Src && _Type) {
        *static_cast<VxExceptionPtrCallback*>(_Dest) = 
            *static_cast<VxExceptionPtrCallback const*>(_Src);
    }
}
