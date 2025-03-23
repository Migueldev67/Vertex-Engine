

#ifndef VX_NEW_H
#define VX_NEW_H


#include <vcruntime_new.h>
#include "Core/VxPackCore.h"
#include <memory>

VX_BEGIN

#if defined(VX_CPLUSPLUS)



enum class vx_align_val : VxQword {};


struct vx_nothrow {
	explicit vx_nothrow() = default;
};

extern vx_nothrow const _Nothrow;

 VX_NODISCARD  VX_ALLOCATOR
void* operator new(
    VxSize _Size
);

VX_NODISCARD  VX_ALLOCATOR
void*  operator new(
    VxSize _Size,
    vx_nothrow const&
) noexcept;

VX_NODISCARD  VX_ALLOCATOR
void* operator new[](
    VxSize _Size
);

VX_NODISCARD  VX_ALLOCATOR
void* operator new[](
    VxSize _Size,
    vx_nothrow const&
) noexcept;

void operator delete(
    void* _Block
) noexcept;

void operator delete(
    void* _Block,
    vx_nothrow const&
) noexcept;

void operator delete[](
    void* _Block
) noexcept;

void operator delete[](
    void* _Block,
    vx_nothrow const&
) noexcept;

void operator delete(
    void* _Block,
    VxSize _Size
) noexcept;

void operator delete[](
    void* _Block,
    VxSize _Size
) noexcept;


#ifdef __cpp_aligned_new

VX_NODISCARD VX_ALLOCATOR
void* operator new(
    VxSize            _Size,
    vx_align_val _Al
    );

VX_NODISCARD  VX_ALLOCATOR
void*  operator new(
    VxSize                _Size,
    vx_align_val      _Al,
    vx_nothrow const&
) noexcept;

void operator delete(
    void* _Block,
    vx_align_val _Al
) noexcept;

void operator delete(
    void* _Block,
    vx_align_val      _Al,
    vx_nothrow const&
) noexcept;

void operator delete[](
    void* _Block,
    vx_align_val _Al
) noexcept;

void operator delete[](
    void* _Block,
    vx_align_val      _Al,
    vx_nothrow const&
) noexcept;



#endif

VX_END

#endif


#endif