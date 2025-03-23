


#include "__vx_exception__.h"




vertex::VxResult VX_CDECL __vx_exception_copy__(
	vertex::vertex::internal::__Exception_data__* _From,
	vertex::vertex::internal::__Exception_data__* _To
) {

    if (_From == nullptr || _To == nullptr) {
        return vertex::VxResult::VX_RESULT_ERROR_NULL_POINTER;
    }

#if VX_USE_ERROR_DATA
    // Copiar datos del error si existe
    _To->_ErrData = _From->_ErrData;
#else
    // Copiar el mensaje de la excepción
    _To->_What = _From->_What;
#endif
    // Copiar la bandera de si se debe liberar la memoria
    _To->_DoFree = _From->_DoFree;

}

vertex::VxResult VX_CDECL __vx_exception_destroy__(
	vertex::vertex::internal::__Exception_data__* _Ins
) {

#if VX_USE_ERROR_DATA
    _Ins->_ErrData._Add_data = nullptr;
    _Ins->_ErrData._Error_code = vertex::VxResult::VX_RESULT_SUCCESS;
    _Ins->_ErrData._File = '\0';
    _Ins->_ErrData._Message = '\0';
    _Ins->_ErrData._Next = nullptr;
    _Ins->_ErrData._Severity = vertex::VxSeverityLevel::VX_SEVERITY_LEVEL_INFO;
#else
    _Ins->_What = nullptr;
#endif
    _Ins->_DoFree = 0;
}