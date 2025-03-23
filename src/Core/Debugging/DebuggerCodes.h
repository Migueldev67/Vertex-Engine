

#ifndef VX_DEBUUGER_CODES_H
#define VX_DEBUUGER_CODES_H


#include "../src/Core/VxPackCore.h"

VX_BEGIN


// Resultados de comandos o funciones
#if defined(VX_CPLUSPLUS)
enum class VxResult : VxDword { // 32-Bits
#else
typedef enum VxResult {
#endif
    // Exito y resultados neutros
    VX_RESULT_SUCCESS                           = 0x00000000, // Operacion exitosa
    VX_RESULT_INCOMPLETE                        = 0x00000001, // Operación incompleta pero válida
    VX_RESULT_TIMEOUT                           = 0x00000002, // Tiempo de espera agotado
    VX_RESULT_INVALID                           = 0x00000003, // Resultado inválido

    // Errores generales
    VX_RESULT_FAILURE                           = 0x00010000, // Error generico
    VX_RESULT_UNKNOWN_ERROR                     = 0x00010001, // Error desconocido
    VX_RESULT_NOT_IMPLEMENTED                   = 0x00010002, // Función no implementada
    VX_RESULT_NOT_SUPPORTED                     = 0x00010003, // Función no soportada
    VX_RESULT_PERMISSION_DENIED                 = 0x00010004, // Permiso denegado

    // Errores de sistema de archivos
    VX_RESULT_ERROR_FILE_NOT_FOUND              = 0x00020000, // Archivo no encontrado
    VX_RESULT_ERROR_FILE_CORRUPTED              = 0x00020001, // Archivo dañado
    VX_RESULT_ERROR_PATH_NOT_FOUND              = 0x00020002, // Ruta no encontrada
    VX_RESULT_ERROR_DISK_FULL                   = 0x00020003, // Disco lleno

    // Errores de memoria
    VX_RESULT_ERROR_DATA_LOSS                   = 0x00030000, // Pérdida de datos
    VX_RESULT_ERROR_NULL_POINTER                = 0x00030001, // Puntero nulo
    VX_RESULT_ERROR_STACK_OVERFLOW              = 0x00030002, // Desbordamiento de pila
    VX_RESULT_ERROR_MEMORY_LEAK                 = 0x00030003, // Fuga de memoria
    VX_RESULT_ERROR_MEMORY_ALLOCATION           = 0x00030004, // Error en la asignación de memoria
    VX_RESULT_ERROR_FREE_POINTER                = 0x00030005, // Puntero liberado anteriormente
    VX_RESULT_ERROR_OUT_OF_RANGE                = 0x00030006, // Valor fuera de rango
    VX_RESULT_ERROR_UNRESERVED_MEMORY           = 0x00030007, // Memoria no reservada
    VX_RESULT_ERROR_INVALID_SIZE                = 0x00030008, // Tamaño invalido
    VX_RESULT_ERROR_INVALID_CAPACITY            = 0x00030009, // Capacidad inválida
    VX_RESULT_ERROR_INVALID_ARGUMENT            = 0x0003000A, // Argumento inválido
    VX_RESULT_ERROR_OUT_OF_RAM                  = 0x000A0000, // RAM insuficiente
    VX_RESULT_ERROR_OUT_OF_VRAM                 = 0x000A0001, // VRAM insuficiente
    VX_RESULT_ERROR_FRAGMENTATION               = 0x000A0004, // Fragmentacion de memoria
    VX_RESULT_ERROR_INVALID_ACCESS              = 0x000A0005, // Acceso invalido a memoria
    VX_RESULT_ERROR_NO_SHRINK_NEEDED            = 0x000A0006, // No necesita cambiar su tamaño al actual

    // Errores de procesamiento y ejecución
    VX_RESULT_ERROR_BUFFER_OVERFLOW             = 0x00040000, // Desbordamiento de buffer
    VX_RESULT_ERROR_DEADLOCK                    = 0x00040001, // Deadlock detectado
    VX_RESULT_ERROR_UNDERFLOW                   = 0x00040002, // Subdesbordamiento
    VX_RESULT_ERROR_INCOMPATIBLE_FORMAT         = 0x00040003, // Formato incompatible
    VX_RESULT_ERROR_CONCURRENCY_ISSUE           = 0x00040004, // Problema de concurrencia

    // Errores de red y comunicacion
    VX_RESULT_ERROR_NETWORK_FAILURE             = 0x00050000, // Error de red
    VX_RESULT_ERROR_CONNECTION_LOST             = 0x00050001, // Conexión perdida
    VX_RESULT_ERROR_PROTOCOL_ERROR              = 0x00050002, // Error de protocolo

    // Advertencias o estados especiales           
    VX_RESULT_WARNING_TRY_AGAIN                 = 0x00060000, // Reintentar la operacion
    VX_RESULT_WARNING_NO_SHRINK_NEEDED          = 0x00060001, // No se necesita reducir tamaño
    VX_RESULT_WARNING_PARTIAL_SUCCESS           = 0x00060002, // Operación parcialmente exitosa

    // Error generico para casos no definidos
    VX_RESULT_MAX_ENUM                          = VX_MAX_ENUM

#if defined(VX_CPLUSPLUS)
};
#else
} VxResult;
#endif


// Codigos de error para ventanas
#if defined(VX_CPLUSPLUS)
enum class VxWindowResult : VxDword { // 32-Bits
#else
typedef enum VxWindowResult {
#endif
    VX_WINDOW_RESULT_SUCCESS                            = 0x00000000,
    VX_WINDOW_RESULT_ERROR_INIT_FAILED                  = 0x00070000, // Error al inicializar la ventana
    VX_WINDOW_RESULT_ERROR_INVALID_SIZE                 = 0x00070001, // Tamaño de ventana no valido
    VX_WINDOW_RESULT_ERROR_CREATION_FAILED              = 0x00070002, // Error al crear ventana
    VX_WINDOW_RESULT_ERROR_CONTEXT_LOST                 = 0x00070003, // Contexto de ventana perdido
    VX_WINDOW_RESULT_ERROR_FULLSCREEN_FAILED            = 0x00070004, // Error al activar modo fullscreen
    VX_WINDOW_RESULT_ERROR_VSYNC_FAILED                 = 0x00070005, // Error al activar VSync
    VX_WINDOW_RESULT_ERROR_INVALID_DISPLAY_MODE         = 0x00070006, // Modo de pantalla invalido

    VX_WINDOW_MAX_ENUM                                  = VX_MAX_ENUM


#if defined(VX_CPLUSPLUS)
};
#else
} VxWindowResult;
#endif


// Codisgos para entradas
#if defined(VX_CPLUSPLUS)
enum class VxInputResult : VxDword { // 32-Bits
#else
typedef enum VxInputResult {
#endif
    VX_INPUT_SUCCESS                               = 0x00000000,
    VX_INPUT_ERROR_DEVICE_NOT_FOUND                = 0x00080000, // Dispositivo de entrada no encontrado
    VX_INPUT_ERROR_MAPPING_FAILED                  = 0x00080001, // Fallo en el mapeo de controles
    VX_INPUT_ERROR_UNSUPPORTED_DEVICE              = 0x00080002, // Dispositivo no soportado
    VX_INPUT_ERROR_BUFFER_OVERFLOW                 = 0x00080003, // Desbordamiento de buffer de entrada
    VX_INPUT_ERROR_INVALID_STATE                   = 0x00080004, // Estado invalido del dispositivo
    VX_INPUT_ERROR_LOST_CONNECTION                 = 0x00080005, // Perdida de conexion del dispositivo
    VX_INPUT_ERROR_AXIS_CALIBRATION_FAILED         = 0x00080006, // Error en calibración de ejes

    VX_INPUT_MAX_ENUM                              = VX_MAX_ENUM

#if defined(VX_CPLUSPLUS)
};
#else
} VxInputResult;
#endif


// Codigos de error para networking
#if defined(VX_CPLUSPLUS)
enum class VxNetworkingSecurityResult : VxDword {
#else
typedef enum VxNetworkingSecurityResult {
#endif
    VX_NETWORK_SECURITY_RESULT_SUCCESS                      = 0x00000000,
    VX_NETWORK_SECURITY_RESULT_ERROR_INVALID_CERTIFICATE    = 0x00090000, // Certificado invalido
    VX_NETWORK_SECURITY_RESULT_ERROR_HANDSHAKE_FAILED       = 0x00090001, // Error en el protocolo de handshake
    VX_NETWORK_SECURITY_RESULT_ERROR_CIPHER_UNSUPPORTED     = 0x00090002, // Cifrado no soportado
    VX_NETWORK_SECURITY_RESULT_ERROR_CERT_EXPIRED           = 0x00090003, // Certificado expirado
    VX_NETWORK_SECURITY_RESULT_ERROR_INVALID_KEY            = 0x00090004, // Clave inváalida
    VX_NETWORK_SECURITY_RESULT_ERROR_AUTHENTICATION_FAILED  = 0x00090005, // Error de autenticación

    VX_NET_SEC_MAX_ENUM = VX_MAX_ENUM

#if defined(VX_CPLUSPLUS)
};
#else
} VxNetworkingSecurityResult;
#endif


// Errores de hilos, procesos y subprocesos
#if defined(VX_CPLUSPLUS)
enum class VxThreadingResult : VxDword {
#else
typedef enum VxThreadingResult {
#endif
    VX_THREADING_RESULT_SUCCESS                           = 0x00000000,
    VX_THREADING_RESULT_ERROR_CREATION_FAILED             = 0x000B0000, // Error al crear hilo
    VX_THREADING_RESULT_ERROR_INVALID_STATE               = 0x000B0001, // Estado de hilo inválido
    VX_THREADING_RESULT_ERROR_DEADLOCK                    = 0x000B0002, // Deadlock detectado
    VX_THREADING_RESULT_ERROR_TIMEOUT                     = 0x000B0003, // Tiempo de espera agotado
    VX_THREADING_RESULT_ERROR_ACCESS_DENIED               = 0x000B0004, // Acceso denegado al hilo
    VX_THREADING_RESULT_ERROR_PRIORITY_FAILED             = 0x000B0005, // Error al establecer prioridad del hilo

    VX_THREAD_MAX_ENUM                                    = VX_MAX_ENUM

#if defined(VX_CPLUSPLUS)
};
#else
} VxThreadingResult;
#endif



// Codigos de error para shaders
#if defined(VX_CPLUSPLUS)
enum class VxShaderResult : VxDword {
#else
typedef enum VxShaderResult {
#endif
    VX_SHADER_RESULT_SUCCESS                       = 0x00000000,
    VX_SHADER_RESULT_ERROR_COMPILE_FAILED          = 0x000C0000, // Fallo en la compilacion del shader
    VX_SHADER_RESULT_ERROR_LINK_FAILED             = 0x000C0001, // Error al enlazar shader
    VX_SHADER_RESULT_ERROR_INVALID_TYPE            = 0x000C0002, // Tipo de shader invalido
    VX_SHADER_RESULT_ERROR_OUT_OF_MEMORY           = 0x000C0003, // Memoria insuficiente para shader
    VX_SHADER_RESULT_ERROR_UNSUPPORTED_FEATURE     = 0x000C0004, // Caracteristica no soportada en shader
    VX_SHADER_RESULT_ERROR_REFLECTION_FAILED       = 0x000C0005, // Error en la reflexión del shader

    VX_SHADER_MAX_ENUM                             = VX_MAX_ENUM

#if defined(VX_CPLUSPLUS)
};
#else
} VxShaderResult;
#endif


// Codigos de error para punto flotante
#if defined(VX_CPLUSPLUS)
enum VxFloatPointFlags : VxByte { // 8-Bits
#else
typedef enum VxFloatPointFlags {
#endif

	VX_FLOAT_POINT_FLAGS_DEFAULT			     =	 0x00, // 0b00000000
	VX_FLOAT_POINT_FLAGS_UNDERFLOW			     =	 0x01, // 0b00000001
	VX_FLOAT_POINT_FLAGS_INEXACT			     =	 0x02, // 0b00000010
	VX_FLOAT_POINT_FLAGS_OVERFLOW			     =	 0x04, // 0b00000100
	VX_FLOAT_POINT_FLAGS_DIVIDE_BY_ZERO		     =	 0x08, // 0b00001000
	VX_FLOAT_POINT_FLAGS_INVALID			     =	 0x10, // 0b00010000
	VX_FLOAT_POINT_FLAGS_DENORMAL			     =	 0x20, // 0b00100000
                                                 
	VX_FLOAT_POINT_FLAGS_MAX_ENUM			     = VX_MAX_ENUM_8_BITS_UNSIGNED

#if defined(VX_CPLUSPLUS)
};
#else
} VxFloatPointFlags;
#endif


// Codigos de error de serailizacion 
#if defined(VX_CPLUSPLUS)
enum class VxSerializationResult : VxDword {
#else
typedef enum VxSerializationResult {
#endif
    VX_SERIALIZATION_RESULT_SUCCESS                 = 0x00100000,
    VX_SERIALIZATION_RESULT_ERROR_WRITE_FAILED      = 0x00100001, // Fallo al escribir datos
    VX_SERIALIZATION_RESULT_ERROR_READ_FAILED       = 0x00100002, // Fallo al leer datos
    VX_SERIALIZATION_RESULT_ERROR_INVALID_FORMAT    = 0x00100003, // Formato de datos invalido
    VX_SERIALIZATION_RESULT_ERROR_CORRUPTED_DATA    = 0x00100004, // Datos corruptos
    VX_SERIALIZATION_RESULT_ERROR_VERSION_MISMATCH  = 0x00100005, // Incompatibilidad de version

    VX_SERIALIZATION_RESULT_MAX_ENUM = VX_MAX_ENUM

#if defined(VX_CPLUSPLUS)
};
#else
} VxSerializationResult;
#endif




#if defined(VX_CPLUSPLUS)
enum class VxDebuggerMode : VxByte { // 8-Bits
#else
typedef enum VxDebuggerMode {
#endif

    VX_DEBUGGER_MODE_NONE = 0x00, // Sin debugging

#if VX_USE_DEBUG
    VX_DEBUGGER_MODE_ENABLED_DEFAULT            = 0x01, // Debugging por defecto
    VX_DEBUGGER_MODE_ENABLED_AUDIO              = 0x02, // Debugging de audio
    VX_DEBUGGER_MODE_ENABLED_GRAPHICS           = 0x04, // Debugging de gráficos
    VX_DEBUGGER_MODE_ENABLED_PHYSICS            = 0x08, // Debugging de físicas
    VX_DEBUGGER_MODE_ENABLED_FILE               = 0x10, // Debugging de archivos
    VX_DEBUGGER_MODE_ENABLED_SCENE              = 0x20, // Debugging de escenas
    VX_DEBUGGER_MODE_ENABLED_ALL_SYSTEMS        = 0x3F, // Todos los sistemas (AND lógico de todos los anteriores)
#endif

    VX_DEBUGGER_MODE_MAX_ENUM                   = VX_MAX_ENUM_8_BITS_UNSIGNED

#if defined(VX_CPLUSPLUS)
};
#else
} VxDebuggerMode;
#endif
    


// Codigos de error para paremisos
#if defined(VX_CPLUSPLUS)
enum class VxPermissionResult : VxDword {
#else
typedef enum VxPermissionResult {
#endif
    VX_PERMISSION_RESULT_SUCCESS                    = 0x00110000,
    VX_PERMISSION_RESULT_ERROR_ACCESS_DENIED        = 0x00110001, // Acceso denegado
    VX_PERMISSION_RESULT_ERROR_READ_ONLY            = 0x00110002, // Archivo de solo lectura
    VX_PERMISSION_RESULT_ERROR_NO_EXECUTION         = 0x00110003, // Permiso de ejecución denegado
    VX_PERMISSION_RESULT_ERROR_INVALID_OWNER        = 0x00110004, // Propietario invalido
    VX_PERMISSION_RESULT_ERROR_NO_WRITE_PERMISSION  = 0x00110005, // Permiso de escritura denegado

    VX_PERMISSION_MAX_ENUM                          = VX_MAX_ENUM

#if defined(VX_CPLUSPLUS)
};
#else
} VxPermissionResult;
#endif
    


// Codigos de error relacionados a la localizacion
#if defined(VX_CPLUSPLUS)
enum class VxLocalizationResult : VxDword {
#else
typedef enum VxLocalizationResult {
#endif
    VX_LOCALIZATION_RESULT_SUCCESS                  = 0x000E0000,
    VX_LOCALIZATION_RESULT_ERROR_MISSING_FILE       = 0x000E0001, // Archivo de localización no encontrado
    VX_LOCALIZATION_RESULT_ERROR_UNSUPPORTED_LANG   = 0x000E0002, // Idioma no soportado    
    VX_LOCALIZATION_RESULT_ERROR_INVALID_FORMAT     = 0x000E0003, // Formato de archivo inválido
    VX_LOCALIZATION_RESULT_ERROR_ENCODING_FAILED    = 0x000E0004, // Fallo en la codificación de texto
    VX_LOCALIZATION_RESULT_ERROR_MISSING_KEY        = 0x000E0005, // Clave de traducción faltante

    VX_LOCALIZATION_RESULT_MAX_ENUM                 = VX_MAX_ENUM

#if defined(VX_CPLUSPLUS)
};
#else
} VxLocalizationResult;
#endif



// Codigos de error relacionados a el sistema de audio
#if defined(VX_CPLUSPLUS)
enum class VxAudioResult : VxDword {
#else
typedef enum VxAudioResult {
#endif
    VX_AUDIO_RESULT_SUCCESS                         = 0x000F0000,
    VX_AUDIO_RESULT_ERROR_DEVICE_NOT_FOUND          = 0x000F0001, // Dispositivo de audio no encontrado
    VX_AUDIO_RESULT_ERROR_INIT_FAILED               = 0x000F0002, // Error en la inicializacion del sistema de audio
    VX_AUDIO_RESULT_ERROR_UNSUPPORTED_FORMAT        = 0x000F0003, // Formato de audio no soportado
    VX_AUDIO_RESULT_ERROR_BUFFER_OVERFLOW           = 0x000F0004, // Desbordamiento de buffer de audio
    VX_AUDIO_RESULT_ERROR_PLAYBACK_FAILED           = 0x000F0005, // Error en la reproducción de audio
    VX_AUDIO_RESULT_ERROR_LATENCY_TOO_HIGH          = 0x000F0006, // Latencia de audio muy alta

    VX_AUDIO_MAX_ENUM                               = VX_MAX_ENUM


#if defined(VX_CPLUSPLUS)
};
#else
} VxAudioResult;
#endif


// Errores para matematicas
#if defined(VX_CPLUSPLUS)
enum class VxMathResult : VxDword {
#else
typedef enum VxMathResult {
#endif
    VX_MATH_RESULT_SUCCESS                     = 0x00200000,
    VX_MATH_RESULT_ERROR_DIVISION_BY_ZERO      = 0x00200001, // Division por cero
    VX_MATH_RESULT_ERROR_OVERFLOW              = 0x00200002, // Desbordamiento (overflow)
    VX_MATH_RESULT_ERROR_UNDERFLOW             = 0x00200003, // Subdesbordamiento (underflow)
    VX_MATH_RESULT_ERROR_INVALID_OPERATION     = 0x00200004, // Operacion invalida
    VX_MATH_RESULT_ERROR_LOSS_OF_PRECISION     = 0x00200005, // Perdida de precisión
    VX_MATH_RESULT_ERROR_DOMAIN_ERROR          = 0x00200006, // Error de dominio (sqrt(-1))
    VX_MATH_RESULT_ERROR_NAN_RESULT            = 0x00200007, // Resultado NaN

    VX_MATH_RESULT_MAX_ENUM                    = VX_MAX_ENUM

#if defined(VX_CPLUSPLUS)
};
#else
} VxMathResult;
#endif


// Codigos de error para enteros
#if defined(VX_CPLUSPLUS)
enum class VxIntegerResult : VxDword {
#else
typedef enum VxIntegerResult {
#endif
    VX_INTEGER_RESULT_SUCCESS                      = 0x00220000,
    VX_INTEGER_RESULT_ERROR_OVERFLOW               = 0x00220001, // Desbordamiento de entero
    VX_INTEGER_RESULT_ERROR_UNDERFLOW              = 0x00220002, // Subdesbordamiento de entero
    VX_INTEGER_RESULT_ERROR_DIVISION_BY_ZERO       = 0x00220003, // Division por cero
    VX_INTEGER_RESULT_ERROR_OUT_OF_BOUNDS          = 0x00220004, // Índice fuera de los límites
    VX_INTEGER_RESULT_ERROR_CONVERSION_FAILED      = 0x00220005, // Fallo en la conversion de tipo

    VX_INTEGER_RESULT_MAX_ENUM                     = VX_MAX_ENUM

#if defined(VX_CPLUSPLUS)
};
#else
} VxIntegerResult;
#endif



// Nivel de los mensajes de debugging
#if defined(VX_CPLUSPLUS)
enum class VxSeverityLevel : VxByte { // 8-Bits
#else
typedef enum VxSeverityLevel {
#endif
	VX_SEVERITY_LEVEL_MESSAGE				= 0x00,		// Mensaje normal, sin impacto
	VX_SEVERITY_LEVEL_INFO					= 0x01,		// Información general
	VX_SEVERITY_LEVEL_WARNING				= 0x02,		// Advertencia de posible problema
	VX_SEVERITY_LEVEL_ERROR					= 0x03,		// Error que afecta el comportamiento
	VX_SEVERITY_LEVEL_CRITICAL				= 0x04,		// Error critico, requiere acción inmediata

	VX_SEVERITY_MAX_ENUM				    = VX_MAX_ENUM_8_BITS_UNSIGNED // Para validación y límites


#if defined(VX_CPLUSPLUS)
};
#else
} VxSeverityLevel;
#endif




// Verifica si una expresion es null pointer 
#ifndef _VX_VERIFY_NULL_POINTER_
    #if defined(VX_CPLUSPLUS)

        #define _VX_VERIFY_NULL_POINTER_(_Expr, _Error)         \
        if(_Expr == VxResult::VX_RESULT_ERROR_NULL_POINTER) {   \
            VX_ASSERT(_Error);                                  \
        }  

    #else

        #define _VX_VERIFY_NULL_POINTER_(_Expr, _Error)         \
        if(_Expr == VX_RESULT_ERROR_NULL_POINTER) {             \
            VX_ASSERT(_Error);                                  \
        }     

    #endif
#endif

// Verifica si una exprecion es ZERO 
#ifndef _VX_VERIFY_ZERO_
    #if defined(VX_CPLUSPLUS)

        #define _VX_VERIFY_ZERO_(_Expr, _Error)         \
            if(_Expr == VxMathResult::VX_MATH_RESULT_ERROR_DIVISION_BY_ZERO) {   \
                VX_ASSERT(_Error);                                  \
            }  
    
    #else
    
        #define _VX_VERIFY_ZERO_(_Expr, _Error)         \
            if(_Expr == VX_MATH_RESULT_ERROR_DIVISION_BY_ZERO) {             \
                VX_ASSERT(_Error);                                  \
            }     
    
    #endif
#endif


/*

// Datos del error
typedef struct VxErrorData {
	VxResult			Result;				// Codigo de error del resultado
	const char*			Message;			// Mensaje del error
	const void*			Next;				// Puntero al siguiente error
	VxUint32			AdditionalData;		// Datos relacionados al error
	VxUint32			Line;               // Linea en la que ocurrio el error
	const char*			File;               // Arachivo en la que ocurrio el error
	//time_t timeStamp
	VxSeverityLevel		Severity;
} VxErrorData;

*/




VX_END




#endif