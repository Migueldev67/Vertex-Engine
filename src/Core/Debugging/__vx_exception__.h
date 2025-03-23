

#ifndef __VX_EXCEPTION___H
#define __VX_EXCEPTION___H


#include "VxErrorData.h"
#include "Core/Utils/Chars/VxString.h"

#include <exception>
#include <stdexcept>

VX_BEGIN


VX_INTERNAL_BEGIN


struct __Exception_data__ {
#if VX_USE_ERROR_DATA
    ::vertex::internal::__vx_error_data__ _ErrData;
#else
    const char* _What = nullptr;
#endif
    VxBool _DoFree = VX_FALSE;
};


VxResult VX_CDECL __vx_exception_copy__(
    const vertex::internal::__Exception_data__* _From,
    vertex::internal::__Exception_data__* _To
) noexcept;


VxResult VX_CDECL __vx_exception_destroy__(
    vertex::internal::__Exception_data__* _Ins
) noexcept;



VX_INTERNAL_END


using VxExceptionData = vertex::internal::__Exception_data__;



class VxException {
private:
    VxExceptionData m_data_{};

public:
#if VX_USE_ERROR_DATA
    VxException() noexcept {
        m_data_._DoFree = VX_FALSE;
        m_data_._ErrData._Add_data = nullptr;
        m_data_._ErrData._Error_code = VxResult::VX_RESULT_SUCCESS;
        m_data_._ErrData._File = 0;
        m_data_._ErrData._Line = VX_LINE;
        m_data_._ErrData._Message = 0;
        m_data_._ErrData._Next = nullptr;
        m_data_._ErrData._Severity = VxSeverityLevel::VX_SEVERITY_LEVEL_INFO;
    }
#else
    VxException() noexcept = default;
#endif

#if VX_USE_ERROR_DATA
    explicit VxException(
        VxSeverityLevel                 _Severity, 
        VxResult                        _ErrorCode, 
        VxString                        _Message,
        const void*                     _Next = nullptr, 
        const void*                     _AddData = nullptr
    ) noexcept {
#else
    explicit VxException(const char* _Message) noexcept {
#endif
        VxExceptionData _InitData{};
        _InitData._DoFree = VX_TRUE;
#if VX_USE_ERROR_DATA
        _InitData._ErrData._Severity = _Severity;
        _InitData._ErrData._Error_code = _ErrorCode;
        _InitData._ErrData._Message = _Message;
        _InitData._ErrData._Next = _Next;
        _InitData._ErrData._Add_data = _AddData;
#else 
        _InitData._What = _Message;
#endif
        vertex::internal::__vx_exception_copy__(&_InitData, &m_data_);
    }

    VxException(const VxException & _Other) noexcept {
        vertex::internal::__vx_exception_copy__(&_Other.m_data_, &m_data_);
    }

    VxException& operator=(const VxException & _Other) noexcept {
        if (this != &_Other) {
            vertex::internal::__vx_exception_destroy__(&m_data_);
            vertex::internal::__vx_exception_copy__(&_Other.m_data_, &m_data_);
        }
        return *this;
    }

    virtual ~VxException() noexcept {
        vertex::internal::__vx_exception_destroy__(&m_data_);
    }

#if VX_USE_ERROR_DATA
    VX_NODISCARD virtual VxString what() const noexcept {
#else
    VX_NODISCARD virtual const char* what() const noexcept {
#endif

#if VX_USE_ERROR_DATA
        return (m_data_._ErrData._Message != 0) ? m_data_._ErrData._Message : 0;
#else
        return m_data_._What ? m_data_._What : "Unknown Exception";
#endif
    }

};

class VxBadException : public VxException {
public:
#if VX_USE_ERROR_DATA
    VxBadException(
        VxSeverityLevel                     _Severity, 
        VxResult                            _ErrorCode, 
        VxString                            _Message,
        const void*                         _Next = nullptr, 
        const void*                         _AddData = nullptr
    ) noexcept
        : VxException(_Severity, _ErrorCode, _Message, _Next, _AddData) {
    }
#else
    VxBadException() noexcept : VxException("Bad Exception.") {}
#endif

};

class VxBadAlloc : public VxException {
private:

#if VX_USE_ERROR_DATA
    VxBadAlloc(
        VxSeverityLevel                 _Severity, 
        VxResult                        _ErrorCode, 
        VxString                        _Message,
        const void*                     _Next = nullptr, 
        const void*                     _AddData = nullptr
    ) noexcept
        : VxException(_Severity, _ErrorCode, _Message, _Next, _AddData) {}
#else
    VxBadAlloc() noexcept 
        : VxException("Memory allocation failed.") {}
#endif

public:

#if !VX_USE_ERROR_DATA
    VxBasdAlloc() noexcept
        : VxException("Bad Allocation.") {}

#endif



};




VX_END





#endif 