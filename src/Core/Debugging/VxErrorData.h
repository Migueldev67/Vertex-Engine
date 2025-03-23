

#ifndef VX_ERROR_DATA_H
#define VX_ERROR_DATA_H

#include "DebuggerCodes.h"
#include "Core/Utils/Chars/VxString.h"

#if defined(__VX_USE_ERROR_DATA__)
	#define VX_USE_ERROR_DATA 1
#else
	#define VX_USE_ERROR_DATA 1
#endif



VX_INTERNAL_BEGIN



#if defined(VX_CPLUSPLUS)



VX_DEFINE_ALIAS(__internal_vertex_severity, ::vertex::VxSeverityLevel)
VX_DEFINE_ALIAS(__internal_vertex_result, ::vertex::VxResult)
VX_DEFINE_ALIAS(__internal_vertex_math_result, ::vertex::VxMathResult)
VX_DEFINE_ALIAS(__internal_vertex_integer_result, ::vertex::VxIntegerResult)
VX_DEFINE_ALIAS(__internal_vertex_float_result, ::vertex::VxFloatPointFlags)
VX_DEFINE_ALIAS(__internal_vertex_input_error, ::vertex::VxInputResult)
VX_DEFINE_ALIAS(__internal_vertex_networking_security_error, ::vertex::VxNetworkingSecurityResult)
VX_DEFINE_ALIAS(__internal_vertex_permission_result, ::vertex::VxPermissionResult)
VX_DEFINE_ALIAS(__internal_vertex_shader_error, ::vertex::VxShaderResult)
VX_DEFINE_ALIAS(__internal_vertex_localization_error, ::vertex::VxLocalizationResult)
VX_DEFINE_ALIAS(__internal_vertex_serialization_error, ::vertex::VxSerializationResult)
VX_DEFINE_ALIAS(__internal_vertex_threading_error, ::vertex::VxThreadingResult)
VX_DEFINE_ALIAS(__internal_vertex_window_error, ::vertex::VxWindowResult)
VX_DEFINE_ALIAS(__const_voidptr, const void*)
VX_DEFINE_ALIAS(__vx_uintptr, VxUintptr)



// Estructura de errores genericos y comunes
struct __vx_error_data__ {
	__internal_vertex_severity							_Severity;
	VxResult									_Error_code;
	VxString											_Message;
	__const_voidptr										_Next;
	VxUint32											_Line;
	__const_voidptr										_Add_data;
	VxString											_File;
};


// Estructura de errores matematicos
struct __vx_math_error_data__ {
	__internal_vertex_severity							_Severity;
	__internal_vertex_math_result						_Error_code;
	VxString											_Message;
	__const_voidptr										_Next;
	VxUint32											_Line;
	__const_voidptr										_Add_data;
	VxString											_File;
};


// Estructura de errores de enumeros enteros
struct __vx_math_error_data__ {
	__internal_vertex_severity							_Severity;
	__internal_vertex_integer_result					_Error_code;
	VxString											_Message;
	__const_voidptr										_Next;
	VxUint32											_Line;
	__const_voidptr										_Add_data;
	VxString											_File;
};


// Estructura de errores de numeros de punto flotante
struct __vx_float_error_data__ {
	__internal_vertex_severity							_Severity;
	__internal_vertex_float_result						_Error_code;
	VxString											_Message;
	__const_voidptr										_Next;
	VxUint32											_Line;
	__const_voidptr										_Add_data;
	VxString											_File;
};


// Estructura de errores relacionados al input
struct __vx_input_error_data__ {
	__internal_vertex_severity							_Severity;
	__internal_vertex_input_error						_Error_code;
	VxString											_Message;
	__const_voidptr										_Next;
	VxUint32											_Line;
	__const_voidptr										_Add_data;
	VxString											_File;
};


// Estructura de errores relacionados el networking
struct __vx_networking_security_error_data__ {
	__internal_vertex_severity							_Severity;
	__internal_vertex_networking_security_error			_Error_code;
	VxString											_Message;
	__const_voidptr										_Next;
	VxUint32											_Line;
	__const_voidptr										_Add_data;
	VxString											_File;
};


// Estructura de errores relacionados el networking
struct __vx_permission_error_data__ {
	__internal_vertex_severity							_Severity;
	__internal_vertex_permission_result					_Error_code;
	VxString											_Message;
	__const_voidptr										_Next;
	VxUint32											_Line;
	__const_voidptr										_Add_data;
	VxString											_File;
};


// Estructura de errores relacionados a shaders
struct __vx_shader_error_data__ {
	__internal_vertex_severity							_Severity;
	__internal_vertex_shader_error						_Error_code;
	VxString											_Message;
	__const_voidptr										_Next;
	VxUint32											_Line;
	__const_voidptr										_Add_data;
	VxString											_File;
};


// Estructura de errores relacionados a localizacion
struct __vx_localization_error_data__ {
	__internal_vertex_severity							_Severity;
	__internal_vertex_localization_error				_Error_code;
	VxString											_Message;
	__const_voidptr										_Next;
	VxUint32											_Line;
	__const_voidptr										_Add_data;
	VxString											_File;
};


// Estructura de errores relacionados a serializacion
struct __vx_serialization_error_data__ {
	__internal_vertex_severity							_Severity;
	__internal_vertex_serialization_error				_Error_code;
	VxString											_Message;
	__const_voidptr										_Next;
	VxUint32											_Line;
	__const_voidptr										_Add_data;
	VxString											_File;
};


// Estructura de errores relacionados a threading y concurrencia
struct __vx_threading_error_data__ {
	__internal_vertex_severity							_Severity;
	__internal_vertex_threading_error					_Error_code;
	VxString											_Message;
	__const_voidptr										_Next;
	VxUint32											_Line;
	__const_voidptr										_Add_data;
	VxString											_File;
};


// Estructura de errores relacionados a las ventanas
struct __vx_window_error_data__ {
	__internal_vertex_severity							_Severity;
	__internal_vertex_window_error						_Error_code;
	VxString											_Message;
	__const_voidptr										_Next;
	VxUint32											_Line;
	__const_voidptr										_Add_data;
	VxString											_File;
};



VX_DEFINE_ALIAS(__vx_const_error_data, const __vx_error_data__)
VX_DEFINE_ALIAS(__vx_const_error_data_ptr, const __vx_error_data__*)
VX_DEFINE_ALIAS(__vx_const_error_data_ref, const __vx_error_data__&)
VX_DEFINE_ALIAS(__vx_error_data_ptr, __vx_error_data__*)
VX_DEFINE_ALIAS(__vx_error_data_ref, __vx_error_data__&)



// Obtiene el nivel de severidad de un error
VX_API VX_CONSTEXPR20
__internal_vertex_severity __vx_get_severity_error_data__(
	__vx_const_error_data_ptr								_Ins
) noexcept;


// Obtiene el codigo de error de un error en especifico
VX_API VX_CONSTEXPR20
__internal_vertex_result __vx_get_error_code_error_data__(
	__vx_const_error_data_ptr								_Ins
) noexcept;


// Obtiene el puntero al siguiente error
VX_API VX_CONSTEXPR20
__const_voidptr __vx_get_pointer_next_error_data__(
	__vx_const_error_data_ptr								_Ins
) noexcept;


// Obtiene la direccion de memoria de el puntero al siguiente error
VX_API VX_CONSTEXPR20
__vx_uintptr* __vx_get_addressof_next_error_data__(
	__vx_const_error_data_ptr								_Ins
) noexcept;


// Obtiene los datos adicionales del error 
VX_API VX_CONSTEXPR20
__const_voidptr __vx_get_pointer_add_data_error_data__(
	__vx_const_error_data_ptr								_Ins
) noexcept;


// Obtiene el nombre del archivo del error
VX_API VX_CONSTEXPR20
VxString __vx_get_file_error_data(
	__vx_const_error_data_ptr								_Ins
) noexcept;


// Obtiene la direccion de memoria de los datos adicionales del error
VX_API VX_CONSTEXPR20 
__vx_uintptr* __vx_get_addressof_add_data_error_data__(
	__vx_const_error_data_ptr								_Ins
) noexcept;


// Intercambia todos los datos de un error a otro
VX_API VX_CONSTEXPR20
void __vx_swap_error_data__(
	__vx_error_data_ptr									_Ins1_from,
	__vx_error_data_ptr									_Ins2_to
) noexcept;


// copia todos los datos de un error a otro
VX_API VX_CONSTEXPR20
void __vx_copy_error_data__(
	__vx_error_data_ptr									_Ins1_from,
	__vx_error_data_ptr									_Ins2_to
) noexcept;


// Cambia el mensaje de un error
VX_API VX_CONSTEXPR20
void __vx_set_message_error_data__(
	__vx_error_data_ptr									_Ins,
	VxString											_NewMessage
) noexcept;


// Copia el mensaje de un error
VX_API VX_CONSTEXPR20
void __vx_copy_message_error_data__(
	__vx_error_data_ptr									_Ins1_from,
	__vx_error_data_ptr									_Ins2_to
) noexcept;


// intercambia el mensaje de un error a otro
VX_API VX_CONSTEXPR20
void __vx_swap_message_error_data__(
	__vx_error_data_ptr									_Ins1_from,
	__vx_error_data_ptr									_Ins2_to
) noexcept;





// Muestra el error y dependiendo de el nivel de log
void __vx_emit_error_data(
	__vx_error_data_ptr _Ins
) noexcept;




#else




#endif

VX_INTERNAL_END



#endif