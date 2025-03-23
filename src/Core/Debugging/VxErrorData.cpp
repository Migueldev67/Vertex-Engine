


#include "VxErrorData.h"



VX_API VX_CONSTEXPR20
vertex::internal::__internal_vertex_severity __vx_get_severity_error_data__(
	vertex::internal::__vx_const_error_data_ptr _Ins
) noexcept {
	return _Ins->_Severity;
}



VX_API VX_CONSTEXPR20
vertex::internal::__internal_vertex_result __vx_get_error_code_error_data__(
	vertex::internal::__vx_const_error_data_ptr	_Ins
) noexcept {
	return _Ins->_Error_code;
}


VX_API VX_CONSTEXPR20
vertex::internal::__const_voidptr __vx_get_pointer_next_error_data__(
	vertex::internal::__vx_const_error_data_ptr _Ins
) noexcept {
	return _Ins->_Next;
}


VX_API VX_CONSTEXPR20
vertex::internal::__vx_uintptr* __vx_get_addressof_next_error_data__(
	vertex::internal::__vx_const_error_data_ptr _Ins
) noexcept {
	VxUintptr* _Address = (VxUintptr*)VX_ADDRESS_OF(_Ins->_Next);
	return _Address;
}


VX_API VX_CONSTEXPR20
vertex::internal::__const_voidptr __vx_get_pointer_add_data_error_data__(
	vertex::internal::__vx_const_error_data_ptr _Ins
) noexcept {
	return _Ins->_Add_data;
}


VX_API VX_CONSTEXPR20
vertex::VxString __vx_get_file_error_data(
	vertex::internal::__vx_const_error_data_ptr	_Ins
) noexcept {
	return _Ins->_File;
}


VX_API VX_CONSTEXPR20
vertex::internal::__vx_uintptr* __vx_get_addressof_add_data_error_data__(
	vertex::internal::__vx_const_error_data_ptr _Ins
) noexcept {
	VxUintptr* _Address = (VxUintptr*)VX_ADDRESS_OF(_Ins->_Add_data);
	return _Address;
}



VX_API VX_CONSTEXPR20
void __vx_swap_error_data__(
	vertex::internal::__vx_error_data_ptr	_Ins1_from,
	vertex::internal::__vx_error_data_ptr	_Ins2_to
) noexcept {
	vertex::VxResult _TempErrorCode = _Ins1_from->_Error_code;
	vertex::VxSeverityLevel _TempSeverity = _Ins1_from->_Severity;
	vertex::VxString _TempMessage = _Ins1_from->_Message;
	vertex::internal::__const_voidptr _TempNext = _Ins1_from->_Next;
	vertex::internal::__const_voidptr _TempAddData = _Ins1_from->_Add_data;
	vertex::VxString _TempFile = _Ins1_from->_File;
	VxUint32 _TempLine = _Ins1_from->_Line;

	_Ins1_from->_Error_code = _Ins2_to->_Error_code;
	_Ins1_from->_Add_data = _Ins2_to->_Add_data;
	_Ins1_from->_Severity = _Ins2_to->_Severity;
	_Ins1_from->_File = _Ins2_to->_File;
	_Ins1_from->_Line = _Ins2_to->_Line;
	_Ins1_from->_Message = _Ins2_to->_Message;
	_Ins1_from->_Next = _Ins2_to->_Next;
	
	_Ins2_to->_Error_code = _TempErrorCode;
	_Ins2_to->_Add_data = _TempAddData;
	_Ins2_to->_File = _TempFile;
	_Ins2_to->_Line = _TempLine;
	_Ins2_to->_Message = _TempMessage;
	_Ins2_to->_Next = _TempNext;
	_Ins2_to->_Severity = _TempSeverity;
}


VX_API VX_CONSTEXPR20
void __vx_copy_error_data__(
	vertex::internal::__vx_error_data_ptr _Ins1_from,
	vertex::internal::__vx_error_data_ptr _Ins2_to
) noexcept {
	_Ins2_to->_Error_code = _Ins1_from->_Error_code;
	_Ins2_to->_Add_data = _Ins1_from->_Add_data;
	_Ins2_to->_File = _Ins1_from->_File;
	_Ins2_to->_Line = _Ins1_from->_Line;
	_Ins2_to->_Message = _Ins1_from->_Message;
	_Ins2_to->_Next = _Ins1_from->_Next;
	_Ins2_to->_Severity = _Ins1_from->_Severity;
}



VX_API 
VX_CONSTEXPR20 void __vx_set_message_error_data__(
	vertex::internal::__vx_error_data_ptr _Ins,
	vertex::VxString _NewMessage
) noexcept {
	_Ins->_Message = _NewMessage;
}


VX_API 
VX_CONSTEXPR20 void __vx_copy_message_error_data__(
	vertex::internal::__vx_error_data_ptr _Ins1_from,
	vertex::internal::__vx_error_data_ptr _Ins2_to
) noexcept {
	_Ins2_to->_Message = _Ins1_from->_Message;
}


VX_API VX_CONSTEXPR20
void __vx_swap_message_error_data__(
	vertex::internal::__vx_error_data_ptr _Ins1_from,
	vertex::internal::__vx_error_data_ptr _Ins2_to
) noexcept {
	vertex::VxString _TempMessage = _Ins1_from->_Message;
	_Ins1_from->_Message = _Ins2_to->_Message;
	_Ins2_to->_Message = _TempMessage;
}



VX_CONSTEXPR20 void __vx_emit_error_data(
	vertex::internal::__vx_error_data_ptr _Ins
) noexcept {

	if (_Ins->_Severity != vertex::VxSeverityLevel::VX_SEVERITY_LEVEL_CRITICAL) {
		VX_PRAGMA_MESSAGE("[ "
			VX_STRINGIZE(_Ins->_Severity) "] "
			"Codigo de error: " VX_STRINGIZE(_Ins->_Error_code)
			_Ins->_Message
			VX_FILE
			VX_STRINGIZE(VX_LINE)
		);
	}
	if (_Ins->_Severity == vertex::VxSeverityLevel::VX_SEVERITY_LEVEL_CRITICAL) {
		static_assert(!0,
			VX_STRINGIZE(
				_Ins->_Severity) "] "
				"Codigo de error: " VX_STRINGIZE(_Ins->_Error_code)
				VX_STRINGIZE(_Ins->_Message)
				VX_FILE
				VX_STRINGIZE(VX_LINE)
			);
	}






}