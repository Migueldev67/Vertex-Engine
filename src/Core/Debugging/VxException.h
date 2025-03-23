

#ifndef VX_EXCEPTION_H
#define VX_EXCEPTION_H


#define __VX_IMPORT_AND_EXPORT_DLL_ENABLED__
#include "Core/Debugging/__vx_exception__.h"

VX_DEFINE_ALIAS(VxExceptionPtrCallback, void*)

VX_BEGIN
VX_INTERNAL_BEGIN

VX_API void VX_CDECL __vxExceptionPtrCopy(VxVoidPtr, const VxVoidPtr) noexcept;
VX_API void VX_CDECL __vxExceptionPtrCreate(VxVoidPtr) noexcept;
VX_API void VX_CDECL __vxExceptionPtrDestroy(VxVoidPtr) noexcept;
VX_API bool VX_CDECL __vxExceptionPtrCompare(const VxVoidPtr, const VxVoidPtr) noexcept;
VX_API void VX_CDECL __vxExceptionPtrAssign(VxVoidPtr, const VxVoidPtr) noexcept;
VX_API bool VX_CDECL __vxExceptionPtrToBool(const VxVoidPtr) noexcept;
VX_API void VX_CDECL __vxExceptionPtrSwap(VxVoidPtr, VxVoidPtr) noexcept;
VX_API void VX_CDECL __vxExceptionPtrCurrentException(VxVoidPtr) noexcept;
VX_API void VX_CDECL __vxExceptionPtrCopyException(VxVoidPtr, const VxVoidPtr, const VxVoidPtr) noexcept;
VX_NORETURN void VX_CDECL __vxExceptionPtrRethrow(const VxVoidPtr);

VX_INTERNAL_END


class VxExceptionPtr {
private:

	VxVoidPtr m_data1_;
	VxVoidPtr m_data2_;

private:

	VxExceptionPtr() noexcept {
		vertex::internal::__vxExceptionPtrCreate(this);
	}

	VxExceptionPtr(VxNullptr) noexcept {
		vertex::internal::__vxExceptionPtrCreate(this);
	}

	~VxExceptionPtr() noexcept {
		vertex::internal::__vxExceptionPtrDestroy(this);
	}


    VxExceptionPtr& operator=(VxNullptr) noexcept {
        VxExceptionPtr _Ptr;
        __vxExceptionPtrAssign(this, &_Ptr);
        return *this;
    }

    static VxExceptionPtr _Copy_exception(
        VxVoidPtr           _Except, 
        const VxVoidPtr     _Ptr
    ) {
        VxExceptionPtr _Retval;
        if (!_Ptr) {
            return _Retval;
        }
        __vxExceptionPtrCopyException(&_Retval, _Except, _Ptr);
        return _Retval;
    }

    friend void swap(
        VxExceptionPtr&         _Lhs, 
        VxExceptionPtr&         _Rhs
    ) noexcept {
        __vxExceptionPtrSwap(&_Lhs, &_Rhs);
    }


    
	


};








VX_END

#endif