/*
*
* Creado por Vertex Software el (19-02-2025)
*
* Este archivo fundamental es el punto de entrada de Vertex Engine
* encabezados funturos dependeran de el para configuraciones para compiladores
* gestion de versionado de C/C++, tamaños de tipos limites numericos y entre
* otras cosas de las cuales Vertex Engine va a depender.
* 
* Empezar a leer el codigo fuente de este archivo es un punto de inicio para 
* entender el codigo fuente de Vertex Engine.
* 
* 
*
*
*/


/*
* Protector de codigo en archivos de encabezado
*/
#ifndef VX_CONFIG_H
#define VX_CONFIG_H



// +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
// Compiladores                                                            +
// +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+


/*
* Esta porcion de codigo tiene como objetivo definir configuraciones o macros
* mas faciles de usar para la gestion de compiladores en tiempo de compilacion
* 
*/
#if defined(_MSC_VER) // Microsoft Visual C++ (msvc)
	/*
	* Esta macro nos ayudar a apartar en tiempo de compilacion codigo exclusivo
	* para eL compilador Microsoft Visual C++ (msvc).
	*/
	#define VX_COMP_MSVC

	/*
	* Macro util para el modo debug de Vertex Engine
	* 
	* Al llamar esta macro, en el momento de compilar el codigo
	* si hacemos uso de esta macro podemos a llegar a ver el nombre
	* del compilador de que estamos haciedno uso.
	* 
	*/
	#define VX_COMP_NAME "MSVC" 
#elif defined(__GNUC__) // GCC
	/*
	* Esta macro nos ayudar a apartar en tiempo de compilacion codigo exclusivo
	* para eL compilador GNU GCC.
	*/
	#define VX_COMP_GCC
	
	/*
	* Macro util para el modo debug de Vertex Engine
	*
	* Al llamar esta macro, en el momento de compilar el codigo
	* si hacemos uso de esta macro podemos a llegar a ver el nombre
	* del compilador de que estamos haciedno uso.
	*
	*/
	#define VX_COMP_NAME "GCC"
#elif defined(__clang__) // Clang
	/*
	* Esta macro nos ayudar a apartar en tiempo de compilacion codigo exclusivo
	* para eL compilador Clang.
	*/
	#define VX_COMP_CLANG

	/*
	* Macro util para el modo debug de Vertex Engine
	*
	* Al llamar esta macro, en el momento de compilar el codigo
	* si hacemos uso de esta macro podemos a llegar a ver el nombre
	* del compilador de que estamos haciedno uso.
	*
	*/
	#define VX_COMP_NAME "Clang"
#else
	#error "Compilador no soportado"
#endif // ^^^_MSC_VER^^^


/*
* Compatibilidad con C/C++ para codigo especifico en tiempo de compilacion.
* 
*/
#if defined(__cplusplus)
/*
* Macro para codigo exclusivo para C++ en tiempo de compilacion
* utilizando la macro predefinida __cplusplus.
* 
*/
	#define VX_CPLUSPLUS __cplusplus
#else
	/*
	* Macro para codigo exclusivo en C usando como caso contrario de la condicion.
	* 
	*/
	#define VX_STDC 
#endif // ^^^__cplusplus^^^


// Macros de versionado
#if defined(_MSC_VER)
	#define VX_CXX_VERSION _MSVC_LANG
#elif defined(__GNUC__)
	#define VX_CXX_VERSION VX_CPLUSPLUS
#elif defined(__clang__)
	#define VX_CXX_VERSION VX_CPLUSPLUS
#else
	#define VX_CXX_VERSION
#endif // ^^^_MSC_VER^^^


/*
* Macros de utilidades de versionado para C++, esto es util para poder ser
* compilado desde caulquier version de C++ hasta C++11.
* 
*/
#define _VX_CPP23 202302L // C++23
#define _VX_CPP20 202002L // C++20
#define _VX_CPP17 201703L // C++17
#define _VX_CPP14 201402L // C++14
#define _VX_CPP11 201103L // C++11



/*
* Macros helpers que ayudane a que el codigo sea mas manejable en cuanto
* al manejo de versiones de MSVC y C++.
* 
*/
#ifdef VX_CPLUSPLUS
	#if defined(_MSVC_LANG) && _MSVC_LANG > __cplusplus
		#define _VX_MSVC_LANG _MSVC_LANG
	#else  
		#define _VX_MSVC_LANG __cplusplus
	#endif // ^^^defined(_MSVC_LANG) && _MSVC_LANG > __cplusplus^^^
#else  
	#define _VX_MSVC_LANG 0L
#endif // ^^^VX_CPLUSPLUS^^^

/*
* Verificaciones en tiempo de compilacion o para codigo exclusivos para C++17
* definiendo las macros _VX_HAS_CXX17 con un valor de 1 si la condicion se cumple.
* 
*/
#ifndef _VX_HAS_CXX17
	#if _VX_MSVC_LANG > 201402L // _MSVC_LANG mayor a C++ 14 (es decir C++17)
		#define _VX_HAS_CXX17 1 // Se define en 1 para condiciones de preprocesador
	#else // De lo contrario
		#define _VX_HAS_CXX17 0 // Se define en 0 para que las condiciones sean falsas
	#endif // ^^^_VX_MSVC_LANG > 201402L^^^
#endif  // ^^^_VX_HAS_CXX17^^^

/*
* Verificaciones en tiempo de compilacion o para codigo exclusivos para C++20
* definiendo las macros _VX_HAS_CXX20 con un valor de 1 si la condicion se cumple.
*
*/
#ifndef _VX_HAS_CXX20
	#if _VX_HAS_CXX17 && _VX_MSVC_LANG > 201703L
		#define _VX_HAS_CXX20 1 // Se define en 1 para condiciones de preprocesador
	#else
		#define _VX_HAS_CXX20 0 // Se define en 0 para que las condiciones sean falsas
	#endif // ^^^_VX_HAS_CXX17 && _VX_MSVC_LANG > 201703L^^^
#endif // ^^^_VX_HAS_CXX20^^^

/*
* Verificaciones en tiempo de compilacion o para codigo exclusivos para C++23
* definiendo las macros _VX_HAS_CXX23 con un valor de 1 si la condicion se cumple
* ( 16-03-2025 -> aunque C++23 es experimental en el caso de msvc)
*
*/
#ifndef _VX_HAS_CXX23
	#if _VX_HAS_CXX20 && _VX_MSVC_LANG > 202002L
		#define _VX_HAS_CXX23 1 // Se define en 1 para condiciones de preprocesador
	#else
		#define _VX_HAS_CXX23 0 // Se define en 0 para que las condiciones sean falsas
	#endif // ^^^_VX_HAS_CXX20 && _VX_MSVC_LANG > 202002L^^^
#endif // ^^^_VX_HAS_CXX23^^^



/*
* Macros de versionado que son de utilidad (helpers) que ayudan a mantener el
* codigo multiplataforma 
*/
#define _VX_MSVC_VER22 1930 // MSVC 2022
#define _VX_MSVC_VER19 1920 // MSVC 2019
#define _VX_MSVC_VER17 1910 // MSVC 2017
#define _VX_MSVC_VER15 1900 // MSVC 2015

/*
* Si esta defrinido VX_COMP_MSVC o estamos compilando en msvc se habilitan los valores
* unicos de las macros de versionado de C++.
* 
*/
#if defined(VX_COMP_MSVC)

	/*
	* Macros de versionado para C++ exclusivas de msvc (cabe destacar que en tiempo de 
	* compilacion las macros van a ser las misma pero dependiedno del compilador
	* el valor de las macros cambiara)
	* 
	*/
	#define VX_HAS_CXX17 _VX_HAS_CXX17 // C++17
	#define VX_HAS_CXX20 _VX_HAS_CXX20 // C++20
	#define VX_HAS_CXX23 _VX_HAS_CXX23 // C++23
#else

	/*
	* Macros con valores aptos para GCC y Clang
	*/
	#define VX_HAS_CXX17 (VX_CXX_VERSION >= _VX_CPP17) // C++17
	#define VX_HAS_CXX20 (VX_CXX_VERSION >= _VX_CPP20) // C++20
	#define VX_HAS_CXX23 (VX_CXX_VERSION >= _VX_CPP23) // C++23
#endif // ^^^defineed(VX_COMP_MSVC)^^^


	/*
	* Este bloque de codigo se encarga de detectar la version del compilador MSVC
	* y definir una macro especifica segun la version detectada.
	* Esto permite adaptar el codigo segun la version de Visual Studio que se este usando.
	*
	* Es util para manejar diferencias entre versiones del compilador, ya sea
	* por soporte de funcionalidades, optimizaciones o compatibilidad.
	*/
#if _MSC_VER >= _VX_MSVC_VER22

	/*
	* Si la version del compilador es mayor o igual a _VX_MSVC_VER22,
	* significa que se esta compilando con una version de Visual Studio 2022 o superior.
	* Por lo tanto, se define la macro VX_MSVC_VERSION_2022 para indicarlo.
	*/
	#define VX_MSVC_VERSION_2022
#elif _MSC_VER >= _VX_MSVC_VER19

	/*
	* Si no se cumple la condicion anterior pero la version del compilador es mayor
	* o igual a _VX_MSVC_VER19, significa que se esta usando Visual Studio 2019.
	* Se define la macro VX_MSVC_VERSION_2019 para indicar esta version.
	*/
	#define VX_MSVC_VERSION_2019
#elif _MSC_VER >= _VX_MSVC_VER17

	/*
	* Si el compilador es mayor o igual a _VX_MSVC_VER17,
	* entonces se esta compilando con Visual Studio 2017.
	* Para identificarlo, se define la macro VX_MSVC_VERSION_2017.
	*/
	#define VX_MSVC_VERSION_2017
#elif _MSC_VER >= _VX_MSVC_VER15

	/*
	* Si la version del compilador es mayor o igual a _VX_MSVC_VER15,
	* significa que se esta usando Visual Studio 2015.
	* Se define la macro VX_MSVC_VERSION_2015 para reflejar esta version.
	*/
	#define VX_MSVC_VERSION_2015
#else

	/*
	* Si ninguna de las versiones anteriores es detectada,
	* se considera que el compilador es demasiado antiguo o no es soportado.
	* En este caso, se lanza un error en tiempo de compilacion para evitar
	* posibles incompatibilidades o problemas de ejecucion.
	*/
	#error "Version no soportada."
#endif // ^^^ _MSC_VER >= _VX_MSVC_VER22 ^^^





/*
* Este bloque de codigo verifica si se esta compilando con el compilador MSVC
* y define macros para identificar la version del estandar de C++ en uso.
*
* Esto es util para habilitar ciertas caracteristicas o escribir codigo compatible
* con diferentes versiones de C++, asegurando que el compilador soporte las
* funcionalidades necesarias.
* 
*/
#if defined(VX_COMP_MSVC)

	/*
	* Si la version de C++ es mayor o igual a _VX_CPP20, significa que se esta compilando
	* con C++20 o una version superior. Se definen macros para indicar esto.
	*/
	#if VX_CXX_VERSION >= _VX_CPP20 // C++20
		#define VX_CPP_STANDARD "C++20"
		#define VX_CPP_VERSION_20

	/*
	* Si la version de C++ es menor a C++20 pero mayor o igual a _VX_CPP17,
	* significa que el compilador esta usando C++17. Se definen macros correspondientes.
	*/
	#elif VX_CXX_VERSION >= _VX_CPP17 // C++17
		#define VX_CPP_STANDARD "C++17"
		#define VX_CPP_VERSION_17

	/*
	* Si la version de C++ es menor a C++17 pero mayor o igual a _VX_CPP14,
	* entonces el compilador esta utilizando C++14. Se establecen las macros adecuadas.
	*/
	#elif VX_CXX_VERSION >= _VX_CPP14 // C++14
		#define VX_CPP_STANDARD "C++14"
		#define VX_CPP_VERSION_14

	/*
	* Si la version de C++ es menor a C++14 pero mayor o igual a _VX_CPP11,
	* significa que se esta compilando con C++11. Se definen macros para este estandar.
	*/
	#elif VX_CXX_VERSION >= _VX_CPP11 // C++11
		#define VX_CPP_STANDARD "C++11"
		#define VX_CPP_VERSION_11

	/*
	* Si ninguna de las condiciones anteriores se cumple, se asume que la version
	* utilizada es C++03. Se definen macros para identificarlo.
	*/
	#else // De lo contrario C++03
		#define VX_CPP_STANDARD "C++03" 
		#define VX_CPP_VERSION_03
	#endif
#else

	/*
	* Si el compilador no es MSVC, se genera un error en tiempo de compilacion
	* indicando que la version no es soportada.
	*/
	#error "Version no soportada"
#endif




/*
* Este bloque de codigo verifica si se esta compilando con el compilador GCC
* y define macros para identificar la version del estandar de C++ en uso.
*
* Esto permite escribir codigo que se adapte a distintas versiones de C++,
* asegurando compatibilidad y aprovechando las caracteristicas disponibles.
*/
#if defined(VX_COMP_GCC)

	/*
	* Si la version de C++ es mayor o igual a _VX_CPP20, significa que se esta compilando
	* con C++20 o una version superior. Se definen macros para reflejar esto.
	*/
	#if VX_CXX_VERSION >= _VX_CPP20 // C++20
		#define VX_CPP_STANDARD "C++20"
		#define VX_CPP_VERSION_20
	
		/*
		* Si la version de C++ es menor a C++20 pero mayor o igual a _VX_CPP17,
		* significa que el compilador esta usando C++17. Se definen las macros adecuadas.
		*/
	#elif VX_CXX_VERSION >= _VX_CPP17 // C++17
		#define VX_CPP_STANDARD "C++17"
		#define VX_CPP_VERSION_17
	
		/*
		* Si la version de C++ es menor a C++17 pero mayor o igual a _VX_CPP14,
		* entonces el compilador esta utilizando C++14. Se establecen las macros correspondientes.
		*/
	#elif VX_CXX_VERSION >= _VX_CPP14 // C++14
		#define VX_CPP_STANDARD "C++14"
		#define VX_CPP_VERSION_14
	
		/*
		* Si la version de C++ es menor a C++14 pero mayor o igual a _VX_CPP11,
		* significa que se esta compilando con C++11. Se definen macros para este estandar.
		*/
	#elif VX_CXX_VERSION >= _VX_CPP11 // C++11
		#define VX_CPP_STANDARD "C++11"
		#define VX_CPP_VERSION_11
	
		/*
		* Si ninguna de las condiciones anteriores se cumple, se asume que la version
		* utilizada es C++03. Se definen macros para identificarlo.
		*/
	#else // De lo contrario C++03
		#define VX_CPP_STANDARD "C++03"
		#define VX_CPP_VERSION_03
	#endif
#endif // ^^^ defined(VX_COMP_GCC) ^^^





/*
* Este bloque de codigo se encarga de verificar si el compilador en uso es Clang
* y define macros que representan la version del estandar de C++ con la que se esta compilando.
*
* Esto permite adaptar el codigo a distintas versiones del lenguaje, asegurando compatibilidad
* y aprovechando las funcionalidades disponibles segun la version de C++ soportada por Clang.
*/
#if defined(VX_COMP_CLANG)

	/*
	* Si la version de C++ es al menos _VX_CPP20, significa que el compilador esta
	* utilizando C++20 o una version superior. Se definen macros para reflejar esta situacion.
	*/
	#if VX_CXX_VERSION >= _VX_CPP20 // C++20
		#define VX_CPP_STANDARD "C++20"
		#define VX_CPP_VERSION_20
	
	/*
	* Si la version de C++ es menor a C++20 pero mayor o igual a _VX_CPP17,
	* significa que se esta compilando con C++17. Se establecen las macros correspondientes.
	*/
	#elif VX_CXX_VERSION >= _VX_CPP17 // C++17
		#define VX_CPP_STANDARD "C++17"
		#define VX_CPP_VERSION_17
	
	/*
	* Si la version de C++ es menor a C++17 pero mayor o igual a _VX_CPP14,
	* entonces el compilador esta utilizando C++14. Se definen macros para esta version.
	*/
	#elif VX_CXX_VERSION >= _VX_CPP14 // C++14
		#define VX_CPP_STANDARD "C++14"
		#define VX_CPP_VERSION_14
	
	/*
	* Si la version de C++ es menor a C++14 pero mayor o igual a _VX_CPP11,
	* se asume que se esta compilando con C++11. Se definen macros adecuadas.
	*/
	#elif VX_CXX_VERSION >= _VX_CPP11 // C++11
		#define VX_CPP_STANDARD "C++11"
		#define VX_CPP_VERSION_11
	
	/*
	* Si ninguna de las condiciones anteriores se cumple, significa que se esta compilando
	* con C++03. Se definen macros para identificar esta version del estandar.
	*/
	#else // De lo contrario C++03
		#define VX_CPP_STANDARD "C++03"
		#define VX_CPP_VERSION_03
	#endif
#endif // ^^^ defined(VX_COMP_CLANG) ^^^




/*
* Este bloque de codigo verifica si la version del compilador es antigua.
* Si el compilador es GCC y su version es menor a 7, se define la macro VX_COMP_OLD_VERSION.
* Esto permite tomar decisiones en el codigo para evitar funciones no soportadas en versiones antiguas.
*/
#if defined(VX_COMP_GCC)
	#if __GNUC__ < 7
		#define VX_COMP_OLD_VERSION
	#endif
#endif


/*
* Similar al caso anterior, pero para MSVC. Si la version de MSVC es menor a _VX_MSVC_VER15
* (equivalente a Visual Studio 2015), se define la macro VX_COMP_OLD_VERSION para indicar
* que se esta usando una version antigua.
*/
#if defined(VX_COMP_MSVC)
	#if _MSC_VER < _VX_MSVC_VER15
		#define VX_COMP_OLD_VERSION
	#endif
#endif

/*
* Si ninguna de las macros VX_COMP_GCC, VX_COMP_MSVC o VX_COMP_CLANG ha sido definida,
* significa que el compilador no es compatible. Se genera un error en tiempo de compilacion
* indicando que solo se soportan MSVC, GCC y Clang.
*/
#ifndef VX_COMP_NAME
	#error "Compilador no soportado. Por favor, use MSVC, GCC o Clang."
#endif


// Asegurarse de que haya un estándar definido
#ifndef VX_CPP_STANDARD
	#define VX_CPP_STANDARD "Desconocido"
#endif

/*
* Definiciones específicas para MSVC. Este bloque de código define macros
* que son específicas del compilador MSVC. Cada macro se asocia con
* características del compilador que permiten optimizar el código y aprovechar
* las características propias de MSVC, como las convenciones de llamada y el manejo
* de excepciones. Estas macros aseguran que el código se ejecute de manera eficiente
* en este entorno específico de compilación.
*/
#if defined(VX_COMP_MSVC) 
	#define VX_FALLTHROUGH [[fallthrough]] // Indica que no hay una ruptura intencional en un switch-case
	#define VX_ALIGNOF __alignof           // Obtiene la alineación de un tipo
	#define VX_BASED __based               // Específico de MSVC para punteros basados
	#define VX_CDECL __cdecl               // Convención de llamada estándar de C
	#define VX_DECLSPEC(x) __declspec(x)   // Especificador de atributos de MSVC
	#define VX_FASTCALL __fastcall         // Convención de llamada optimizada para velocidad
	#define VX_STDCALL __stdcall           // Convención de llamada estándar de Windows
	#define VX_TRY __try                   // Bloque try de MSVC para manejo estructurado de excepciones
	#define VX_LEAVE __leave               // Salida segura de bloques try
	#define VX_UUIDOF __uuidof             // Obtiene el UUID de un tipo
	#define VX_VIRTUAL_INHERITANCE __virtual_inheritance // Herencia virtual en MSVC
	#define VX_NODISCARD [[nodiscard]]     // Indica que el valor de una función no debe ser descartado
	#define VX_NORETURN [[noreturn]]       // Indica que la función no retorna
	#define VX_ALIGN(alignment) __declspec(align(alignment)) // Especifica alineación de memoria
	#define VX_FORCE_INLINE __forceinline  // Fuerza la inlineación de una función
	#define VX_INLINE __inline           // Alternativa para inline en C++17
	#define VX_RESTRICT __restrict         // Indica exclusividad de punteros
	#define VX_NO_VTABLE __declspec(novtable) // Optimización para clases base abstractas
	#define VX_PRAGMA(x) __pragma(x)       // Manejo de pragmas en MSVC
	#define VX_WCHAR  __wchar_t            // Tipo wchar_t de MSVC
	#define VX_ALLOCATOR __declspec(allocator) // Para asignaciones
	#define VX_ASM __asm                   // Ensamblador en línea
	#define VX_INT8 __int8                 // Tipo entero de 8 bits en MSVC
	#define VX_INT16 __int16               // Tipo entero de 16 bits en MSVC
	#define VX_INT32 __int32               // Tipo entero de 32 bits en MSVC
	#define VX_INT64 __int64               // Tipo entero de 64 bits en MSVC
	#define VX_LIKELY   [[likely]]         // Indica que una condición es probable
	#define VX_UNLIKELY [[unlikely]]       // Indica que una condición es poco probable

	/*
	* [[nodiscard]] con mensaje en versiones modernas de C++. Este bloque
	* define la macro VX_NODISCARD_MSG para utilizarla en versiones de C++
	* que soporten el atributo [[nodiscard]] con mensajes, asegurando que
	* el valor retornado por una función no sea descartado, y proporcionando
	* un mensaje en las versiones que lo soporten.
	*/
	#if defined(__has_cpp_attribute) && __has_cpp_attribute(nodiscard) >= 201907L
		#define VX_NODISCARD_MSG(_Msg) [[nodiscard(_Msg)]] // Utiliza el atributo con mensaje
	#else
		#define VX_NODISCARD_MSG(_Msg) VX_NODISCARD // Si no, solo utiliza [[nodiscard]]
	#endif
	
	/*
	* Definiciones de constexpr según la versión de C++. Este bloque evalúa
	* la versión de C++ utilizada y define las macros correspondientes a
	* las versiones de C++17, C++20 y C++23 para el uso de constexpr, lo que
	* optimiza el código según la versión del compilador.
	*/
	#if VX_CPLUSPLUS
		#if _VX_HAS_CXX17 
			#define VX_CONSTEXPR17 constexpr // Define constexpr para C++17
		#else
			#define VX_CONSTEXPR17 
		#endif
		#if _VX_HAS_CXX20 
			#define VX_CONSTEXPR20 constexpr // Define constexpr para C++20
		#else 
			#define VX_CONSTEXPR20 
		#endif
		#if _HAS_CXX23 
			#define VX_CONSTEXPR23 constexpr // Define constexpr para C++23
		#else 
			#define VX_CONSTEXPR23 
		#endif
	#else
		#define VX_CONSTEXPR17
		#define VX_CONSTEXPR20
		#define VX_CONSTEXPR23
	#endif

	/*
	* [[msvc::known_semantics]] en versiones recientes de MSVC. En este bloque
	* se define la macro VX_KNOWN_SEMANTICS que utiliza el atributo [[msvc::known_semantics]]
	* en las versiones más recientes de MSVC para optimizar el comportamiento del compilador.
	*/
	#if _MSC_VER >= _VX_MSVC_VER19
		#define VX_KNOWN_SEMANTICS [[msvc::known_semantics]]
	#else
		#define VX_KNOWN_SEMANTICS 
	#endif
	
	#define VX_DEPRECATED [[deprecated]] // Marca una función o variable como obsoleta
	#define VX_DEPRECATED_MESSAGE(_Message) __declspec(deprecated(_Message)) // Mensaje de obsolescencia

/*
* Definiciones especificas para GCC. Este bloque de codigo define macros
* que son especificas del compilador GCC, incluyendo características como
* el manejo de atributos de las funciones, la inlineacion forzada y las
* convenciones de llamada. Estas macros están diseñadas para mejorar la
* eficiencia y garantizar la compatibilidad con GCC.
*/
#elif defined(VX_COMP_GCC)
	#if __GNUC__ >= 7 
		#define VX_NODISCARD [[nodiscard]]
	#else
		#define VX_NODISCARD 
	#endif
	#if __GNUC__ >= 4 
		#define VX_NORETURN [[noreturn]]
	#else
		#define VX_NORETURN __attribute__((noreturn))
	#endif
	#define VX_PRAGMA(x) _Pragma(x)
	#define VX_FORCE_INLINE inline __attribute__((always_inline))
	#define VX_INLINE inline
	#define VX_RESTRICT __restrict__
	#define VX_NO_VTABLE 
	#define VX_ALLOCATOR
	#define VX_KNOWN_SEMANTICS
	#define VX_ALIGNOF __alignof__
	#define VX_CDECL __attribute__((cdecl))
	#define VX_DECLSPEC(x) __attribute__((x))
	#define VX_FASTCALL __attribute__((fastcall))
	#define VX_STDCALL __attribute__((stdcall))
	#define VX_ASM __asm__
	#define VX_INT8 char
	#define VX_INT16 short
	#define VX_INT32 int
	#define VX_INT64 long long
	#define VX_LIKELY(x)   __builtin_expect(!!(x), 1)
	#define VX_UNLIKELY(x) __builtin_expect(!!(x), 0)
	#define VX_DEPRECATED
	#define VX_DEPRECATED_MESSAGE(_Message)
	#define VX_NODISCARD_MSG(_Msg)

/*
* Definiciones especificas para Clang. Este bloque de codigo define macros
* que son específicas del compilador Clang, incluyendo atributos como
* [[nodiscard]], [[noreturn]] y otros. Estas macros permiten optimizar
* el código y asegurar la compatibilidad con Clang.
*/
#elif defined(VX_COMP_CLANG)
	#if __clang_major__ >= 7
		#define VX_NODISCARD [[nodiscard]]
	#else
		#define VX_NODISCARD 
	#endif
	#if __clang_major__ >= 3
		#define VX_NORETURN [[noreturn]]
	#else
		#define VX_NORETURN __attribute__((noreturn))
	#endif
	#define VX_PRAGMA(x) _Pragma(#x)
	#define VX_FORCE_INLINE inline __attribute__((always_inline))
	#define VX_INLINE inline
	#define VX_RESTRICT __restrict__
	#define VX_NO_VTABLE 
	#define VX_KNOWN_SEMANTICS 
	#define VX_ALIGNOF __alignof__
	#define VX_CDECL __attribute__((cdecl))
	#define VX_DECLSPEC(x) __attribute__((x))
	#define VX_FASTCALL __attribute__((fastcall))
	#define VX_STDCALL __attribute__((stdcall))
	#define VX_ASM __asm__
	#define VX_INT8 char
	#define VX_INT16 short
	#define VX_INT32 int
	#define VX_INT64 long long
	#define VX_LIKELY   [[__likely__]]
	#define VX_UNLIKELY [[__unlikely__]]
	#define VX_DEPRECATED
	#define VX_DEPRECATED_MESSAGE(_Message)

/*
* Caso de compilador no soportado. Si el compilador no es reconocido como MSVC,
* GCC o Clang, se definen macros vacías o genericas para evitar errores de compilación
* y permitir que el código se ejecute de manera segura, aunque con menos optimización.
*/
#else
	#define VX_NODISCARD 
	#define VX_NORETURN 
	#define VX_FORCE_INLINE 
	#define VX_INLINE 
	#define VX_RESTRICT 
	#define VX_NO_VTABLE
	#define VX_ALLOCATOR
	#define VX_KNOWN_SEMANTICS 
	#define VX_PRAGMA(x) 
	#define VX_ALIGNOF 
	#define VX_CDECL
	#define VX_DECLSPEC(x) 
	#define VX_FASTCALL 
	#define VX_STDCALL 
	#define VX_ASM 
	#define VX_INT8 char
	#define VX_INT16 short
	#define VX_INT32 int
	#define VX_INT64 long long
	#define VX_LIKELY(x) 
	#define VX_UNLIKELY(x) 
	#define VX_DEPRECATED
	#define VX_DEPRECATED_MESSAGE(_Message)
	#define VX_NODISCARD_MSG(_Msg) 
#endif





// +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
// Arquitecturas
// +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+


/*
* Comprobacion de la arquitectura del sistema y definicion de macros
* especificas para cada tipo de arquitectura. Este bloque evalua la
* arquitectura del sistema en funcion de las macros de compilador
* definidas por los distintos compiladores y el entorno de compilacion.
*/
#if defined(_M_X64) || defined(__x86_64__) || defined(__amd64__) 
// Si el sistema es de arquitectura x86-64 (64 bits), define las macros para esa arquitectura.
#define VX_ARCH_X86_64
#define VX_ARCH_X64

// Comprobacion de las instrucciones AVX para definir la macro correspondiente.
#if defined(__AVX512F__)
		#define VX_ARCH_X86_64_AVX512 // AVX-512

	#elif defined(__AVX2__)
		#define VX_ARCH_X86_64_AVX2  // AVX2

	#elif defined(__AVX__)
		#define VX_ARCH_X86_64_AVX   // AVX

	#elif defined(__SSE4_2__)
		#define VX_ARCH_X86_64_SSE4_2 // SSE4.2

	#elif defined(__SSE4_1__)
		#define VX_ARCH_X86_64_SSE4_1 // SSE4.1

	#elif defined(__SSSE3__)
		#define VX_ARCH_X86_64_SSSE3  // SSSE3

	#elif defined(__SSE3__)
		#define VX_ARCH_X86_64_SSE3   // SSE3

	#elif defined(__SSE2__)
		#define VX_ARCH_X86_64_SSE2   // SSE2

	#elif defined(__SSE__)
		#define VX_ARCH_X86_64_SSE    // SSE
	#endif

// Si el sistema es de arquitectura x86 de 32 bits, define las macros correspondientes.
#elif defined(_M_IX86) || defined(__i386__) 
	#define VX_ARCH_X86

	// Comprobacion de las instrucciones SSE para definir la macro correspondiente.
	#if defined(__SSE4_2__)
		#define VX_ARCH_X86_SSE4_2 // SSE4.2

	#elif defined(__SSE4_1__)
		#define VX_ARCH_X86_SSE4_1 // SSE4.1

	#elif defined(__SSSE3__)
		#define VX_ARCH_X86_SSSE3  // SSSE3

	#elif defined(__SSE3__)
		#define VX_ARCH_X86_SSE3   // SSE3

	#elif defined(__SSE2__)
		#define VX_ARCH_X86_SSE2   // SSE2

	#elif defined(__SSE__)
		#define VX_ARCH_X86_SSE    // SSE
	#endif

// Si la arquitectura es ARM de 64 bits, define la macro correspondiente.
#elif defined(__aarch64__) || defined(_M_ARM64)
	#define VX_ARCH_ARM64

// Si la arquitectura es ARM de 32 bits, define la macro correspondiente.
#elif defined(__arm__) || defined(_M_ARM)
	#define VX_ARCH_ARM

// Si la arquitectura es PowerPC de 64 bits, define la macro correspondiente.
#elif defined(__powerpc64__) || defined(__ppc64__)
	#define VX_ARCH_PPC64

// Si la arquitectura es PowerPC de 32 bits, define la macro correspondiente.
#elif defined(__powerpc__) || defined(__ppc__)
	#define VX_ARCH_PPC

// Si la arquitectura es MIPS de 64 bits, define la macro correspondiente.
#elif defined(__mips64) || defined(__mips64__)
	#define VX_ARCH_MIPS64

// Si la arquitectura es MIPS de 32 bits, define la macro correspondiente.
#elif defined(__mips__) || defined(_M_MIPS)
	#define VX_ARCH_MIPS

// Si la arquitectura es RISC-V de 64 bits, define la macro correspondiente.
#elif defined(__riscv) && __riscv_xlen == 64
	#define VX_ARCH_RISCV64

// Si la arquitectura es RISC-V de 32 bits, define la macro correspondiente.
#elif defined(__riscv) && __riscv_xlen == 32
	#define VX_ARCH_RISCV32

// Si la arquitectura es SPARC, define la macro correspondiente.
#elif defined(__sparc__) || defined(__sparc)
	#define VX_ARCH_SPARC

// Si la arquitectura es SuperH, define la macro correspondiente.
#elif defined(__sh__)
	#define VX_ARCH_SUPERH

// Si la arquitectura es LoongArch de 64 bits, define la macro correspondiente.
#elif defined(__loongarch64)
	#define VX_ARCH_LOONGARCH64

// Si la arquitectura es HPPA, define la macro correspondiente.
#elif defined(__hppa__)
	#define VX_ARCH_HPPA

// Si la arquitectura es CEE (Common Language Infrastructure), define la macro correspondiente.
#elif defined(_M_CEE)
	#define VX_ARCH_CEE

// Si la arquitectura es CEE pura, define la macro correspondiente.
#elif defined(_M_CEE_PURE)
	#define VX_ARCH_CEE_PURE

// Si la arquitectura es ARM64EC, define la macro correspondiente.
#elif defined(_M_ARM64EC)
	#define VX_ARCH_ARM64EC

// Si se está usando MIDL (Microsoft Interface Definition Language), define la macro correspondiente.
#elif defined(__midl)
	#define VX_ARCH_MIDL

// Si ninguna de las arquitecturas anteriores es encontrada, se genera un error.
#else
	#error "Arquitectura no soportada"
#endif




// +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
// Plataformas                                                             +
// +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+




#define VX_WINDOWS_32 _WIN32
#define VX_WINDOWS_64 _WIN64
#define VX_LINUX __linux__
#define VX_APPLE __APPLE__
#define VX_MACH __MACH__
#define VX_ANDROID __ANDROID__


/*
* Este bloque de codigo verifica la plataforma en la que se esta compilando el programa
* y define macros que identifican la plataforma específica para su uso posterior.
* 
*/
#if defined(VX_WINDOWS_32) || defined(VX_WINDOWS_64)

		// Si la plataforma es Windows (tanto 32 como 64 bits), se definen las macros para Windows.
	#define VX_PLATFORM_WINDOWS
	#define VX_PLATFORM_NAME "Windows" // Se define el nombre de la plataforma como "Windows"
#elif defined(VX_LINUX)

	// Si la plataforma es Linux, se definen las macros correspondientes para Linux.
	#define VX_PLATFORM_LINUX
	#define VX_PLATFORM_NAME "Linux" // Se define el nombre de la plataforma como "Linux"
#elif defined(VX_APPLE) && defined(VX_MACH)

	// Si la plataforma es macOS (basado en Mach), se definen las macros correspondientes para macOS.
	#define VX_PLATFORM_MACOS
	#define VX_PLATFORM_NAME "MachOS" // Se define el nombre de la plataforma como "MachOS"
#elif defined(VX_ANDROID) 

	#define VX_PLATFORM_ANDROID // Si la plataforma es android, se define 'VX_PLATFORM_ANDROID'
	#define VX_PLATFORM_NAME "Android" // Si la plataforma es android, se define el nombre de la plataforma "en Android".
#else

	// Si la plataforma no es reconocida, se genera un error indicando que la plataforma no es soportada.
	#error "Plataforma no soportada"
#endif


// Comprobacion de que se ha definido un nombre de plataforma.
#ifndef VX_PLATFORM_NAME
	// Si el nombre de la plataforma no ha sido definido, se genera un error.
	#error "Nombre de plataforma sin definir"
#endif



/* Aplicar en un archivo con caracterizticas experimentales

// Codigo experimental
#if VX_USE_EXPERIMENTAL
	#if defined(__ANDROID__)
		#define VX_PLATFORM_ANDROID // Disponible en un futuro
	#endif
#endif

*/

// +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
// Modos y especificaciones de engine                                      +
// +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+


/*
* Este bloque de código se encarga de habilitar y configurar diferentes modos
* (experimental, debug y release) mediante macros, permitiendo así configurar
* el comportamiento del programa durante la compilación.
*/

/* Modo experimental */

// Si la macro __VX_EXPERIMENTAL_MODE_ENABLE__ está definida (modo experimental habilitado por el desarrollador o sistema), 
// se define la macro VX_USE_EXPERIMENTAL a 1, de lo contrario se define a 0.
#if defined(__VX_EXPERIMENTAL_MODE_ENABLE__)  
	#define VX_USE_EXPERIMENTAL 1 // Habilita el modo experimental
#else
	#define VX_USE_EXPERIMENTAL 0 // Deshabilita el modo experimental
#endif


/* Modo debug */

// Si la macro __VX_DEBUG_MODE_ENABLED__ no está definida, se verifica si _DEBUG está definido
// (lo cual es común en compilaciones de debug).
#ifndef __VX_DEBUG_MODE_ENABLED__
	#ifdef _DEBUG
		// Si _DEBUG está definido, habilita el modo debug estableciendo __VX_DEBUG_MODE_ENABLED__ a 1.
		#define __VX_DEBUG_MODE_ENABLED__ 1 // Habilitado
	#else
		// Si _DEBUG no está definido, desactiva el modo debug estableciendo __VX_DEBUG_MODE_ENABLED__ a 0.
		#define __VX_DEBUG_MODE_ENABLED__ 0 // Deshabilitado
	#endif
#endif

// Si el modo debug esta habilitado (es decir, __VX_DEBUG_MODE_ENABLED__ es 1),
// se define la macro VX_USE_DEBUG a 1, y se configura la macro VX_DEBUGBREAK para provocar una interrupcion en el depurador.
#if __VX_DEBUG_MODE_ENABLED__ 

	#define VX_USE_DEBUG 1 // Habilita el modo debug
	#if defined(VX_COMP_MSVC)
		// Si se usa el compilador MSVC, se define VX_DEBUGBREAK usando __debugbreak(), lo cual detiene la ejecución del programa.
		#define VX_DEBUGBREAK __debugbreak()
	#elif defined(VX_COMP_GCC) || defined(VX_COMP_CLANG)
		// Si se usa GCC o Clang, se incluye <signal.h> y se define VX_DEBUGBREAK usando __pxcptinfoptrs(), que también detiene la ejecución.
		#include <signal.h>
		#define VX_DEBUGBREAK __pxcptinfoptrs()
	#endif
#else
	// Si el modo debug está deshabilitado, VX_DEBUGBREAK no hace nada y VX_USE_DEBUG se establece en 0.
	#define VX_DEBUGBREAK
	#define VX_USE_DEBUG 0 // Deshabilita el modo debug
#endif


/* Modo Release */

// Si la macro __VX_RELEASE_MODE_ENABLE__ no esta definida, se verifica si _DEBUG está definido.
// Si no esta definido, se habilita el modo release, de lo contrario se desactiva.
#ifndef __VX_RELEASE_MODE_ENABLED__
	#ifndef _DEBUG
		// Si _DEBUG no esta definido, habilita el modo release estableciendo __VX_RELEASE_MODE_ENABLE__ a 1.
		#define __VX_RELEASE_MODE_ENABLE__ 1      // Modo release habilitado
	#else
		// Si _DEBUG esta definido, desactiva el modo release.
		#define __VX_RELEASE_MODE_ENABLE__ 0      // Modo release deshabilitado
	#endif
#endif

// Si el modo release está habilitado (es decir, __VX_RELEASE_MODE_ENABLE__ es 1), 
// se define la macro VX_USE_RELEASE a 1. De lo contrario, se define a 0.
#if __VX_RELEASE_MODE_ENABLE__
	#define VX_USE_RELEASE 1 // Habilita el modo release
#else
	#define VX_USE_RELEASE 0	// Deshabilita el modo release	
#endif



/*
* Modos para la habilitación de DLLs.
* Esta sección gestiona la configuracion para la importación y exportación de DLLs
* en plataformas específicas, principalmente en Windows con el compilador MSVC.
*/
// Si la macro __VX_IMPORT_AND_EXPORT_DLL_ENABLED__ no está definida,
// se comprueba si la plataforma es Windows y si se esta usando el compilador MSVC.
#ifndef __VX_IMPORT_AND_EXPORT_DLL_ENABLED__
	#if defined(VX_PLATFORM_WINDOWS) && defined(VX_COMP_MSVC)
		// Si se cumplen ambas condiciones, habilita la importación y exportacion de DLLs.
		#define __VX_IMPORT_AND_EXPORT_DLL_ENABLED__ 1 // Habilitado
	#else
		// Si no se cumplen las condiciones, deshabilita la importación y exportacion de DLLs.
		#define __VX_IMPORT_AND_EXPORT_DLL_ENABLED__ 0 // Deshabilitado
	#endif
#endif


/*
* Modos para importar y exportar DLLs.
* Dependiendo de si se está construyendo una DLL o usando una,
* se configuran las macros para la importación o exportación de símbolos.
*/
// Si la macro VX_API no está definida (es decir, es la primera vez que se configura),
#ifndef VX_API

	// Se verifica si la importación y exportación de DLLs está habilitada (segun __VX_IMPORT_AND_EXPORT_DLL_ENABLED__).
	#if __VX_IMPORT_AND_EXPORT_DLL_ENABLED__ 

		// Si se esta construyendo la DLL (comprobando la macro VX_BUILD_DLL),
		// se define VX_API como __declspec(dllexport) para exportar símbolos de la DLL.
		#if defined (VX_BUILD_DLL) 
			#define VX_API __declspec(dllexport) // Exportar símbolos al compilar la DLL
		#else

			// Si no se esta construyendo la DLL (es decir, se está usando la DLL),
			// se define VX_API como __declspec(dllimport) para importar símbolos desde la DLL.
			#define VX_API __declspec(dllimport) // Importar símbolos al usar la DLL
		#endif
	#else

		// Si la importación y exportacion de DLLs no está habilitada, se deja la macro VX_API vacía.
		#define VX_API // Para otras plataformas, dejar vacío
	#endif
#else

	// Si VX_API ya está definido (posiblemente por otro codigo o configuración externa),
	// simplemente se mantiene la definición sin cambios.
	#define VX_API
#endif



/*
* Modo para punteros de 64 bits.
* Esta sección verifica si la plataforma es de 64 bits y, en base a ello, decide si se deben
* usar punteros de 64 bits.
*/
// Si la macro VX_USE_64_BIT_PTR_DEFINES no está definida,
#ifndef VX_USE_64_BIT_PTR_DEFINES

	// Se verifica si la plataforma es de 64 bits mediante diversas macros
	// de compilador/arquitectura. Se incluyen diversas arquitecturas y compiladores comunes.
	#if defined(__LP64__) || defined(VX_PLATFORM_WINDOWS) || \
	        (defined(VX_ARCH_X86_64) && !defined(__ILP32__)) || \
	        defined(__ia64) || defined(_M_IA64) || \
	        defined(__aarch64__) || defined(VX_ARCH_PPC64) || \
	        (defined(__riscv) && VX_ARCH_RISCV64)
	
		// Si alguna de las condiciones se cumple, se establece que se usen punteros de 64 bits
		#define VX_USE_64_BIT_PTR_DEFINES (1) 
	#else

		// Si ninguna de las condiciones se cumple (es una plataforma de 32 bits),
		// se establece que no se usen punteros de 64 bits.
		#define VX_USE_64_BIT_PTR_DEFINES (0)
	#endif
#endif


/*
* Tamaño de punteros de 8 y 4 bits dependiendo de la arquitectura de CPU.
* Se configura el tamaño de los punteros (en bytes) según si la plataforma es de 64 bits o no.
* 
*/
// Si la macro VX_PTR_SIZE no está definida,
#ifndef VX_PTR_SIZE

	// Si se han habilitado los punteros de 64 bits,
	#if VX_USE_64_BIT_PTR_DEFINES

		// Se define el tamaño de punteros como 8 bytes (64 bits) para plataformas de 64 bits.
		#define VX_PTR_SIZE 8
	#else
		// De lo contrario, se define el tamaño de punteros como 4 bytes (32 bits) 
		// para plataformas de 32 bits.
		#define VX_PTR_SIZE 4
	#endif
#endif


/*
* Modo para codigo de 64 bits.
* Configura la compilación para usar codigo optimizado para 64 bits,
* dependiendo de la arquitectura de la CPU.
*/
// Si la macro VX_USE_64_BIT_FOR_DEFINES no está definida,
#ifndef VX_USE_64_BIT_FOR_DEFINES

	// Se verifica si la plataforma es de 64 bits mediante las mismas condiciones 
	// utilizadas para los punteros de 64 bits.
	#if defined(__LP64__) || defined(VX_PLATFORM_WINDOWS) || \
		        (defined(VX_ARCH_X86_64) && !defined(__ILP32__)) || \
		        defined(__ia64) || defined(_M_IA64) || \
		        defined(__aarch64__) || defined(VX_ARCH_PPC64) || \
		        (defined(__riscv) && VX_ARCH_RISCV64)
	
		// Si alguna de estas condiciones se cumple, habilita la configuración para código de 64 bits.
		#define VX_USE_64_BIT_FOR_DEFINES (1)
	#else

		// Si la plataforma no es de 64 bits, deshabilita la configuración para código de 64 bits.
		#define VX_USE_64_BIT_FOR_DEFINES (0)
	#endif
#endif



/*
* Null para punteros de 64 y 32 bits.
* Esta sección define un valor nulo para punteros, adaptándose según la arquitectura
* (64 bits o 32 bits) y la versión de C++.
*/

// Si la macro VX_DEFINE_NON_DISPATCHABLE_HANDLE no está definida,
#ifndef VX_DEFINE_NON_DISPATCHABLE_HANDLE

	// Si la macro _VX_NULL_ no está definida (se reduce el tiempo de compilación si es necesario),
	#ifndef _VX_NULL_

		// Si se usan punteros de 64 bits,
		#if VX_USE_64_BIT_PTR_DEFINES

			// Si estamos usando C++ y la versión es C++17 o superior,
			#if defined(VX_CPLUSPLUS) && (VX_CXX_VERSION >= _VX_CPP17)

				// Se define _VX_NULL_ como nullptr, que es el valor nulo en C++17.
				#define _VX_NULL_ (nullptr)
			#else
					// Si no se está usando C++17 o una versión superior, se define _VX_NULL_ 
					// como un puntero nulo en C, es decir, (void*)0.
				#define _VX_NULL_ ((void*)0)
			#endif
		#else
			// Si no se usan punteros de 64 bits (por ejemplo, plataformas de 32 bits),
			// se define _VX_NULL_ como 0ULL (un entero sin signo de 64 bits nulo).
			#define _VX_NULL_ (0ULL)
		#endif
	#else
		// Si _VX_NULL_ ya está definido, simplemente lo mantiene tal como está.
		#define _VX_NULL_
	#endif
#endif

/*
* Si no se ha definido _VX_NULL_ en ningún momento,
* se define como 0.
* 
*/
#ifndef _VX_NULL_
	#define _VX_NULL_ (0)
#endif

// Finalmente, define VX_NULL como el valor que corresponde a _VX_NULL_.
#define VX_NULL _VX_NULL_



/*
* Definición de handles y objetos.
* Este bloque define un tipo de handle o objeto según la arquitectura (64 bits o 32 bits)
* utilizando macros para facilitar el uso de punteros o enteros según la plataforma.
*/
// Si la macro VX_DEFINE_NON_DISPATCHABLE_HANDLE no está definida,
#ifndef VX_DEFINE_NON_DISPATCHABLE_HANDLE
	// Si estamos trabajando en una máquina de 64 bits (según la macro VX_USE_64_BIT_PTR_DEFINES),
	#if VX_USE_64_BIT_PTR_DEFINES

		// Se define un handle para el objeto como un puntero a una estructura.
		// El sufijo "_t" se agrega al nombre del objeto, y el puntero se define como 'struct object##_t *'.
		#define VX_DEFINE_NON_DISPATCHABLE_HANDLE(object) typedef struct object##_t *object;
	#else

		// Si no estamos trabajando en una máquina de 64 bits (por ejemplo, plataformas de 32 bits),
		// se define el objeto como un tipo entero (int).
		#define VX_DEFINE_NON_DISPATCHABLE_HANDLE(object) typedef int object;
	#endif
#endif



/*
* Modo para codigo obsoleto.
* Esta sección se activa si la macro __VX_USE_DEPRECATED_MODE_ENABLED__ está definida,
* habilitando el uso de funciones o características obsoletas.
*/
// Si la macro __VX_USE_DEPRECATED_MODE_ENABLED__ está definida (indicando que el código obsoleto está habilitado),
#if defined(__VX_USE_DEPRECATED_MODE_ENABLED__)
	// Define VX_USE_DEPRECATED como 1, habilitando el uso de código obsoleto.
	#define VX_USE_DEPRECATED 1
#else
	// Si el código obsoleto no está habilitado, define VX_USE_DEPRECATED como 0.
	#define VX_USE_DEPRECATED 0
#endif




// Permite crear variaciones de objetos usando class o struct
/*
*	La intencion de esta sección es permitir la creacion de variaciones de objetos usando `class` o `struct`,
*	según lo que esté habilitado en el proyecto. Dependiendo de qué macros estén definidas, se configura
*	una u otra opción (class o struct) para ser utilizada en el codigo.
*
*	La logica funciona de la siguiente manera:
*	1. Si __VX_USE_CLASS_FOR_XOBJECT__ está definida y __VX_USE_STRUCT_FOR_XOBJECT__ no lo esta,
*	   se define `VX_USE_CLASS_FOR_XOBJECT` con valor 1 (permitiendo el uso de `class` para los objetos)
*	   y `VX_USE_STRUCT_FOR_XOBJECT` se asigna 0 (deshabilitando el uso de `struct`).
*
*	2. Si no se cumple lo anterior, se define `VX_USE_STRUCT_FOR_XOBJECT` como 1 (permitiendo el uso de `struct`),
*	   y `VX_USE_CLASS_FOR_XOBJECT` se asigna 0 (deshabilitando el uso de `class`).
*
*	3. Si ni __VX_USE_CLASS_FOR_XOBJECT__ ni __VX_USE_STRUCT_FOR_XOBJECT__ estan definidas, ambas macros
*	   `VX_USE_CLASS_FOR_XOBJECT` y `VX_USE_STRUCT_FOR_XOBJECT` se eliminan y se definen con el valor 0,
*	   deshabilitando así ambos modos.
*
*	4. Si ambas macros (__VX_USE_CLASS_FOR_XOBJECT__ y __VX_USE_STRUCT_FOR_XOBJECT__) están definidas
*	   al mismo tiempo, también se eliminan y se les asigna 0, asegurando que solo una de las dos opciones
*	   (class o struct) se pueda habilitar a la vez.
*/
// Verificación de si la macro __VX_USE_CLASS_FOR_XOBJECT__ esta definida, y __VX_USE_STRUCT_FOR_XOBJECT__ no
#if defined(__VX_USE_CLASS_FOR_XOBJECT__) && !defined(__VX_USE_STRUCT_FOR_XOBJECT__)

	// Si se define __VX_USE_CLASS_FOR_XOBJECT__ y no __VX_USE_STRUCT_FOR_XOBJECT__,
	// habilita el uso de class y desactiva el uso de struct
	#define VX_USE_CLASS_FOR_XOBJECT (1)
	#define VX_USE_STRUCT_FOR_XOBJECT (0)
#else
	// Si no se cumple lo anterior, habilita el uso de struct y desactiva el uso de class
	#define VX_USE_CLASS_FOR_XOBJECT (0)
	#define VX_USE_STRUCT_FOR_XOBJECT (1)

	// Si ambas macros (__VX_USE_CLASS_FOR_XOBJECT__ y __VX_USE_STRUCT_FOR_XOBJECT__) no estan definidas,
	// se desactivan ambas macros VX_USE_CLASS_FOR_XOBJECT y VX_USE_STRUCT_FOR_XOBJECT.
	#if !defined(__VX_USE_CLASS_FOR_XOBJECT__) && !defined(__VX_USE_STRUCT_FOR_XOBJECT__)	
		// Elimina las macros si no están definidas y las asigna a 0
		#undef VX_USE_STRUCT_FOR_XOBJECT 
		#undef VX_USE_CLASS_FOR_XOBJECT 
	
		// Asigna 0 a ambas para indicar que no se puede usar ni class ni struct
		#define VX_USE_STRUCT_FOR_XOBJECT (0)
		#define VX_USE_CLASS_FOR_XOBJECT (0)
	#else	
		// Elimina las macros si estan definidas y las asigna a 0
		#undef VX_USE_STRUCT_FOR_XOBJECT 
		#undef VX_USE_CLASS_FOR_XOBJECT 
	
		// Asigna 0 a ambas para indicar que no se puede usar ni class ni struct
		#define VX_USE_STRUCT_FOR_XOBJECT (0)
		#define VX_USE_CLASS_FOR_XOBJECT (0)
	#endif
#endif



// Manejo de handles

// Manejo de handles

// Verifica si VX_USE_STRUCT_FOR_XOBJECT es 1 (verdadero) para usar struct en lugar de class
#if VX_USE_STRUCT_FOR_XOBJECT // Si VX_USE_STRUCT_FOR_XOBJECT es 1 o true se da:

	// Si se esta utilizando C++, se define el handle como un puntero a un struct
	#if defined(VX_CPLUSPLUS)

		// Uso unico de struct en C++ ya que no es necesario el typedef
		// Definimos el handle como un puntero al struct object_t
		#define VX_DEFINE_HANDLE(object) struct object##_t* object; 
	#else // Si no es C++, es C

		// En C, se usa typedef para definir un puntero a un struct
		#define VX_DEFINE_HANDLE(object) typedef struct object##_t* object;
	#endif
#endif

// Verifica si VX_USE_CLASS_FOR_XOBJECT es 1 (verdadero) para usar class en lugar de struct
#if VX_USE_CLASS_FOR_XOBJECT // Si VX_USE_CLASS_FOR_XOBJECT es 1 o true se da:

	// Si se esta utilizando C++, se define el handle como un puntero a un class
	#if defined(VX_CPLUSPLUS) // Si está definido VX_CPLUSPLUS se define:

		// Uso de class en C++ ya que es un lenguaje orientado a objetos
		// Definimos el handle como un puntero al class object_t
		#define VX_DEFINE_HANDLE(object) class object##_t* object; 
	#else // Si no es C++ (se asume que es C)

		// En C, se usa typedef para definir un puntero a un struct, que es el equivalente a una clase en C++
		#define VX_DEFINE_HANDLE(object) typedef struct object##_t* object;
	#endif
#endif


// Handle que nos ayuda a definir alias

// Si estamos en C++, usamos 'using' para definir alias de tipos
#if defined(VX_CPLUSPLUS)
	// Define un alias para un tipo usando 'using' en C++
	#define VX_DEFINE_ALIAS(name, type) using name = type;

	// Define un alias para un tipo usando 'decltype' en C++
	#define VX_DEFINE_ALIAS_WITH_DECLTYPE(name, type) using name = decltype(type);
#else
	// En C, usamos 'typedef' para definir alias de tipos
	#define VX_DEFINE_ALIAS(name, type) typedef type name;

	// No se necesita definir un alias con 'decltype' en C, así que lo dejamos vacío
	#define VX_DEFINE_ALIAS_WITH_DECLTYPE(name, type)
#endif

// Modo para constexpr

// Si estamos en C++, habilitamos la opcion para usar 'constexpr'
#if defined(VX_CPLUSPLUS) // Si esta definido C++ 

	// Verificamos si la macro '__VX_USE_CONSTEXPR__' está definida para activar 'constexpr'
	#if defined(__VX_USE_CONSTEXPR__) // Si está definido '__VX_USE_CONSTEXPR__'

		#define VX_USE_CONSTEXPR (1) // Habilitamos 'constexpr'
	#else
		#define VX_USE_CONSTEXPR (0) // Si no está habilitado, lo deshabilitamos
	#endif
#else

	// Si no estamos en C++, deshabilitamos 'constexpr' de todos modos
	#define VX_USE_CONSTEXPR (0)
#endif 

// Modo para 'static' - control de uso de la palabra clave 'static'

// Verificamos si '__VX_USE_STATIC__' está definido para habilitar 'static'
#if defined(__VX_USE_STATIC__) // Si esta definido '__VX_USE_STATIC__'
	#define VX_USE_STATIC (1) // Habilitamos 'static'
#else
	#define VX_USE_STATIC (0) // Si no está habilitado, lo deshabilitamos
#endif

// Modo para 'inline' - control de uso de la palabra clave 'inline'

// Si '__VX_USE_INLINE__' está definido, habilitamos la opción de 'inline'
#if defined(__VX_USE_INLINE__) 
	#define VX_USE_INLINE (1) // Habilitamos 'inline'
#else
	#define VX_USE_INLINE (0) // Si no está habilitado, lo deshabilitamos
#endif


// Si 'VX_USE_DEBUG' tiene un valor de 1 se define 'VX_VERTEX_IS_ENABLE_DEBUGGING' en 1
#if VX_USE_DEBUG
	#define VX_VERTEX_IS_ENABLE_DEBUGGING 1
#else // De lo contrario 'VX_VERTEX_IS_ENABLE_DEBUGGING' en un valor 0
	#define VX_VERTEX_IS_ENABLE_DEBUGGING 0
#endif



// +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
// Limites para ciertos tipos, helpers y utilidades del encabezado         +
// +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+


// Definicion de macros para obtener el numero de línea
#ifndef _VX_LINE_ // Para reducir los tiempos de compilación si lo deseamos
	#define _VX_LINE_ __LINE__  // __LINE__ es una macro incorporada que obtiene el número de línea actual en el código fuente
#else
	#define _VX_LINE_  // Si ya está definido, no se hace nada
#endif
#define VX_LINE _VX_LINE_  // VX_LINE es un alias de _VX_LINE_


// Definicion de macros para obtener el nombre del archivo
#ifndef _VX_FILE_ // Para reducir los tiempos de compilación si lo deseamos
	#define _VX_FILE_ __FILE__  // __FILE__ es una macro incorporada que obtiene el nombre del archivo fuente actual
#else
	#define _VX_FILE_  // Si ya está definido, no se hace nada
#endif
#define VX_FILE _VX_FILE_  // VX_FILE es un alias de _VX_FILE_


// Definicion de macros para convertir a cadena de texto
#ifndef _VX_STRINGIZE_  // Para reducir los tiempos de compilacion si lo deseamos
	#define _VX_STRINGIZE_(x) #x  // #x convierte el argumento 'x' a una cadena de texto
#else
	#define _VX_STRINGIZE_(x)  // Si ya está definido, no se hace nada
#endif
#define VX_STRINGIZE(x) _VX_STRINGIZE_(x)  // VX_STRINGIZE convierte el argumento 'x' a una cadena de texto


// Definición de macros para convertir a cadena ancha (wide string)
#ifndef  _VX_WIDE_ // Para reducir los tiempos de compilación si lo deseamos
	#define _VX_WIDE_(x) L##x  // 'L' convierte el argumento 'x' a una cadena ancha (wide string) en C++
#else 
	#define _VX_WIDE_(x)  // Si ya está definido, no se hace nada
#endif 
#define VX_WIDE(x) _VX_WIDE_(x)  // VX_WIDE convierte 'x' a una cadena ancha (wide string)


// Definicion de macros para concatenar dos valores
#ifndef _VX_CONCATENATE_  // Para reducir los tiempos de compilacion si lo deseamos
	#define _VX_CONCATENATE_(a, b) a ## b  // '##' concatena los dos argumentos 'a' y 'b'
#else
	#define _VX_CONCATENATE_(a, b)  // Si ya está definido, no se hace nada
#endif
#define VX_CONCATENATE(a, b) _VX_CONCATENATE_(a, b)  // VX_CONCATENATE concatena los dos argumentos 'a' y 'b'


// Definicion de macros para deshacer el paréntesis en listas de argumentos
#ifndef _VX_UNPARENTHESIZE_
	#define _VX_UNPARENTHESIZE_(...) __VA_ARGS__  // __VA_ARGS__ toma los argumentos sin los paréntesis
#else
	#define _VX_UNPARENTHESIZE_(...)  // Si ya está definido, no se hace nada
#endif
#define VX_UNPARENTHESIZE(...)  _VX_UNPARENTHESIZE_ __VA_ARGS__  // VX_UNPARENTHESIZE elimina los paréntesis en las listas de argumentos




// Definicion de una asercion estatica
#ifndef _VX_STATIC_ASSERT_  // Para reducir los tiempos de compilacion si lo deseamos
	#if defined(VX_CPLUSPLUS) // Si esta definido C++

		// Si estamos en C++, usamos static_assert para validar condiciones en tiempo de compilacion
		#define _VX_STATIC_ASSERT_(_Cond, message) VX_DEPRECATED_MESSAGE("Es obsoleto ya que no se puede definir asertciones estaticas en tiempo de compilacion") static_assert(_Cond, message)
	#else

		// Si no estamos en C++, no hacemos nada
		#define _VX_STATIC_ASSERT_(_Cond, message) VX_DEPRECATED_MESSAGE("Es obsoleto ya que no se puede definir asertciones estaticas en tiempo de compilacion")
	#endif
#else
	#define _VX_STATIC_ASSERT_(_Cond, message) VX_DEPRECATED_MESSAGE("Es obsoleto ya que no se puede definir asertciones estaticas en tiempo de compilacion")
#endif
// Definicion de macro que ejecuta la asercion estatica
#define VX_STATIC_ASSERT(_Cond, message) _VX_STATIC_ASSERT_(_Cond, message)


// Definicion de un mensaje de pragma
#ifndef _VX_PRAGMA_MESSAGE_ // Para reducir los tiempos de compilacion si lo deseamos
	#define _VX_PRAGMA_MESSAGE_(message) VX_PRAGMA(message)  // Se pasa el mensaje a pragma
#else 
	#define _VX_PRAGMA_MESSAGE_(message)
#endif
#define VX_PRAGMA_MESSAGE(message) _VX_PRAGMA_MESSAGE_(message)  // Macro para emitir mensajes de pragma


// Emision de mensaje con la ubicacion del archivo y la linea
#ifndef _VX_EMIT_MESSAGE_ // Para reducir los tiempos de compilacion si lo deseamos
	#define _VX_EMIT_MESSAGE_(message) VX_PRAGMA_MESSAGE(VX_FILE "(" _VX_STRINGIZE_(VX_LINE) "): " message)  // Emite el mensaje con el archivo y la linea
#else
	#define _VX_EMIT_MESSAGE_(message)
#endif
#define VX_EMIT_MESSAGE(message) _VX_EMIT_MESSAGE_(message)  // Macro para emitir el mensaje con ubicacion


// Emision de mensaje de advertencia con el numero y el mensaje
#ifndef _VX_EMIT_WARNING_MESSAGE_ // Para reducir los tiempos de compilacion si lo deseamos
	#define _VX_EMIT_WARNING_MESSAGE_(number, message) VX_EMIT_MESSAGE("[Warning]: " #number ": " message)  // Emite el mensaje de advertencia
#else
	#define _VX_EMIT_WARNING_MESSAGE_(number, message)
#endif
#define VX_EMIT_WARNING_MESSAGE(number, message) _VX_EMIT_WARNING_MESSAGE_(number, message)  // Macro para emitir advertencia


// Emision de mensaje de error con el numero y el mensaje
#ifndef _VX_EMIT_ERROR_MESSAGE_ // Para reducir los tiempos de compilacion si lo deseamos
	#define _VX_EMIT_ERROR_MESSAGE_(number, message) VX_STATIC_ASSERT(false, "[Error]: " #number ": " message)  // Si hay un error, se lanza una asercion estatica
#else
	#define _VX_EMIT_ERROR_MESSAGE_(number, message)
#endif
#define VX_EMIT_ERROR_MESSAGE(number, message) _VX_EMIT_ERROR_MESSAGE_(number, message)  // Macro para emitir error



// Assert para vertex engine
#ifndef _VX_ASSERT_ // Para reducir los tiempos de compilacion si lo deseamos
	// Si estamos usando el compilador MSVC
	#if defined(VX_COMP_MSVC)
	
		#include <assert.h>
		/* Definicion del assert para MSVC
		* La expresion se verifica, si es falsa se ejecuta _wassert, lo que
		* muestra un mensaje de error con la expresion, el archivo y la linea.
		* 
		*/
	#define _VX_ASSERT_(expression) (void)(                                                       \
            (!!(expression)) ||                                                              \
            (_wassert(VX_WIDE(#expression), VX_WIDE(__FILE__), (unsigned)(__LINE__)), 0) \
        )
	#endif
#else
	#define _VX_ASSERT_(expression)  // Si no estamos en MSVC, no hacemos nada
#endif
// Macro para usar el assert
#define VX_ASSERT(expression) _VX_ASSERT_(expression)



// Obtener la direccion de memoria de un objeto
#ifndef _VX_ADDRESSOF_ // Para reducir los tiempos de compilacion si lo deseamos

	// Si estamos utilizando C++, se define el comportamiento de la macro
	// El objetivo es obtener la direccion de memoria de un objeto de manera compatible con C++
	#if defined(VX_CPLUSPLUS)

		/**
		 * _VX_ADDRESSOF_:
		 * En C++, se usa reinterpret_cast para convertir la direccion de un objeto
		 * a un puntero de tipo const volatile char*. Esto se hace para garantizar que la direccion
		 * obtenida no sea optimizada ni modificada por el compilador y se pueda utilizar
		 * como un puntero a tipo char para representarla de manera uniforme.
		 *
		 * El const_cast se usa para quitar cualquier tipo de constancia en el puntero,
		 * lo que permite la manipulación de la direccion sin restricciones.
		 */
		#define _VX_ADDRESSOF_(x) (const_cast<char*>(reinterpret_cast<const volatile char*>(&x)))
	#else

		// Si no estamos en C++, es decir, en C, simplemente obtenemos la direccion de memoria de x
		/**
		 * _VX_ADDRESSOF_:
		 * En C, obtenemos la direccion de memoria del objeto directamente con el operador '&'.
		 * Esta es una forma tradicional y sencilla de obtener la direccion de memoria en C.
		 */
		#define _VX_ADDRESSOF_(x) (&(x))
	#endif
#else

	// Si la macro _VX_ADDRESSOF_ ya esta definida, no la volvemos a definir
	/**
	 * Si ya esta definida _VX_ADDRESSOF_, no realizamos ninguna operacion.
	 * Esto es parte del control de compilacion para evitar definiciones repetidas
	 * que puedan afectar los tiempos de compilacion.
	 */
	#define _VX_ADDRESSOF_(x)
#endif

// Definicion publica de la macro que los usuarios pueden utilizar
/**
 * VX_ADDRESS_OF:
 * Esta es la interfaz publica que se utiliza para obtener la direccion de memoria de cualquier objeto.
 * Internamente llama a _VX_ADDRESSOF_, que se comporta de manera diferente dependiendo de si el codigo
 * esta siendo compilado con C++ o C.
 *
 * El uso de esta macro permite obtener la direccion de memoria sin tener que preocuparse por la
 * implementacion interna del lenguaje o las particularidades de cada compilador.
 */
#define VX_ADDRESS_OF(x) _VX_ADDRESSOF_(x)


// Compatibilidad con bool tanto para C++ como para C
#ifndef _VX_BOOL_ // Para reducir los tiempos de compilacion si lo deseamos

	// Si estamos utilizando C++, definimos VX_BOOL como 'bool' nativo de C++
	/**
	 * _VX_BOOL_:
	 * En C++, el tipo 'bool' es nativo y forma parte del lenguaje desde C++98.
	 * Al definir 'VX_BOOL' como 'bool', garantizamos que los programas C++ usen este tipo para booleanos,
	 * lo cual es más intuitivo y se ajusta a los estándares del lenguaje.
	 */
	#if defined(VX_CPLUSPLUS)
		#define VX_BOOL bool
	#else
		 // En C, no existe un tipo 'bool' nativo, por lo que usamos 'unsigned char'
		 /**
		  * _VX_BOOL_:
		  * En C, el tipo 'bool' no existe de forma nativa, por lo que se utiliza 'unsigned char' como equivalente.
		  * Esto permite representar valores booleanos (0 para falso, 1 para verdadero) de manera eficiente
		  * en un tipo de dato que es compatible con los operadores booleanos, aunque no sea estrictamente un 'bool'.
		  */
		#define VX_BOOL unsigned char
	#endif
#else

	// Si la macro _VX_BOOL_ ya esta definida, no la volvemos a definir
	/**
	 * Si ya esta definida _VX_BOOL_, no la volvemos a definir.
	 * Esto forma parte del control de compilacion para evitar definiciones redundantes y mejorar los tiempos de compilacion.
	 */
	#define VX_BOOL
#endif



// Definicion de nombres de espacio en C++
// Si estamos en C++, se define el inicio de un espacio de nombres
#if defined(VX_CPLUSPLUS) 

	/**
	 * VX_BEGIN:
	 * Si el codigo esta siendo compilado en C++, definimos un espacio de nombres llamado 'vertex'.
	 * Los espacios de nombres son una característica de C++ que permite organizar el código y evitar colisiones de nombres.
	 */
	#define VX_BEGIN namespace vertex {
#else

	// Si no estamos en C++, no definimos ningun espacio de nombres
	/**
	 * VX_BEGIN:
	 * En C, no existen espacios de nombres, por lo que simplemente dejamos vacio este bloque.
	 * De esta forma, el código C y C++ pueden coexistir sin problemas, y el bloque no tiene efecto en C.
	 */
	#define VX_BEGIN
#endif

// Definicion de fin del espacio de nombres en C++
// Similar a VX_BEGIN, si estamos en C++ cerramos el espacio de nombres 'vertex'
#if defined(VX_CPLUSPLUS) 

	/**
	 * VX_END:
	 * Si el código está siendo compilado en C++, cerramos el espacio de nombres 'vertex'.
	 * Esto permite que todo el código relacionado esté dentro de ese espacio de nombres, evitando colisiones de nombres.
	 */
	#define VX_END }
#else
	// Si no estamos en C++, no cerramos ningún espacio de nombres
	/**
	 * VX_END:
	 * Al igual que con VX_BEGIN, en C no se usan espacios de nombres, por lo que este bloque queda vacío en código C.
	 */
	#define VX_END
#endif




// Define para valores invalidos
/**
 * VX_INVALID:
 * Define el valor -1 como un valor estándar para representar una condición de "invalidación".
 * Este valor puede ser utilizado para indicar que una operación o resultado es inválido o no tiene sentido,
 * por ejemplo, al devolver índices o punteros no válidos.
 * Se usa comúnmente en estructuras y funciones para verificar si los datos son válidos o no.
 */
#define VX_INVALID (-1)


 
// Solo define 0 para enteros (no tiene el mismo uso que VX_NULL)
#ifndef _VX_NONE_  // Si no está definida la macro _VX_NONE_

	/**
	 * _VX_NONE_:
	 * Se define 0 como un valor para representar "ninguno" o "vacío" para enteros.
	 * Este valor se utiliza como un valor estándar para representar la ausencia de algo,
	 * pero no debe confundirse con un puntero nulo (VX_NULL) ya que su uso es solo para enteros.
	 */
	#define _VX_NONE_ 0
#else 

	// Si ya está definida la macro _VX_NONE_, no se vuelve a definir
	/**
	 * Si _VX_NONE_ ya está definida, no se vuelve a definir para evitar redefinir la macro.
	 */
	#define _VX_NONE_ 
#endif 
#define VX_NONE _VX_NONE_  // Asigna el valor de _VX_NONE_ a VX_NONE para facilitar su uso



// Definición para el valor booleano verdadero (1)
#ifndef _VX_TRUE_

	/**
	 * _VX_TRUE_:
	 * Se define como el valor 1 para representar "verdadero" en condiciones booleanas.
	 * Este valor se utiliza en expresiones condicionales y lógicas para indicar que una condición es verdadera.
	 * 
	 */
	#define _VX_TRUE_ (1)
#else

	/**
	 * Si ya esta definida la macro _VX_TRUE_, no se vuelve a definir.
	 * Esto previene la redefinición redundante y mejora los tiempos de compilacion.
	 */
	#define _VX_TRUE_
#endif
#define VX_TRUE _VX_TRUE_  // Asigna el valor de _VX_TRUE_ a VX_TRUE para facilitar su uso




// Definicion para el valor booleano falso (0)
#ifndef _VX_FALSE_
	/**
	 * _VX_FALSE_:
	 * Se define como el valor 0 para representar "falso" en condiciones booleanas.
	 * Este valor se utiliza en expresiones condicionales y lógicas para indicar que una condición es falsa.
	 */
	#define _VX_FALSE_ (0)
#else

	/**
	 * Si ya esta definida la macro _VX_FALSE_, no se vuelve a definir.
	 * Esto previene la redefinición redundante y mejora los tiempos de compilación.
	 */
	#define _VX_FALSE_
#endif
#define VX_FALSE _VX_FALSE_  // Asigna el valor de _VX_FALSE_ a VX_FALSE para facilitar su uso



// Definicion de valores minimos para enteros con signo
/**
 * VX_INT8_MIN:
 * Define el valor mínimo para un tipo de 8 bits con signo.
 * Este valor es -128, ya que el rango de los enteros con signo de 8 bits es de -128 a 127.
 */
#define VX_INT8_MIN         (-127 - 1) // Valor minimo para un tipo de 8 bits


/**
 * VX_INT16_MIN:
 * Define el valor minimo para un tipo de 16 bits con signo.
 * Este valor es -32768, ya que el rango de los enteros con signo de 16 bits es de -32768 a 32767.
 */
#define VX_INT16_MIN        (-32767 - 1) // Valor minimo para un tipo de 16 bits



/**
* VX_INT32_MIN:
* Define el valor minimo para un tipo de 32 bits con signo.
* Este valor es -2147483648, ya que el rango de los enteros con signo de 32 bits es de -2147483648 a 2147483647.
*/
#define VX_INT32_MIN        (-2147483647 - 1) // Valor minimo para un tipo de 32 bits



/**
 * VX_INT64_MIN:
 * Define el valor minimo para un tipo de 64 bits con signo.
 * Este valor es -9223372036854775808, ya que el rango de los enteros con signo de 64 bits es de -9223372036854775808 a 9223372036854775807.
 */
#define VX_INT64_MIN        (-9223372036854775807 - 1) // Valor minimo para un tipo de 64 bits



// Definicion de valores maximos para enteros con signo
/**
 * VX_INT8_MAX:
 * Define el valor máximo para un tipo de 8 bits con signo.
 * Este valor es 127, ya que el rango de los enteros con signo de 8 bits es de -128 a 127.
 */
#define VX_INT8_MAX         (0x7F) // Valor maximo para un tipo de 8 bits



/**
 * VX_INT16_MAX:
 * Define el valor maximo para un tipo de 16 bits con signo.
 * Este valor es 32767, ya que el rango de los enteros con signo de 16 bits es de -32768 a 32767.
 */
#define VX_INT16_MAX        (0x7FFF) // Valor maximo para un tipo de 16 bits


/**
* VX_INT32_MAX:
* Define el valor maximo para un tipo de 32 bits con signo.
* Este valor es 2147483647, ya que el rango de los enteros con signo de 32 bits es de -2147483648 a 2147483647.
*/
#define VX_INT32_MAX        (0x7FFFFFFF) // Valor maximo para un tipo de 32 bits


// Definicion de valores maximos para enteros sin signo
/**
 * VX_UINT8_MAX:
 * Define el valor maximo para un tipo de 8 bits sin signo.
 * Este valor es 255, ya que el rango de los enteros sin signo de 8 bits es de 0 a 255.
 */
#define VX_UINT8_MAX        (0xFFU) // Valor maximo para un tipo de 8 bits sin signo



/**
 * VX_UINT16_MAX:
 * Define el valor maximo para un tipo de 16 bits sin signo.
 * Este valor es 65535, ya que el rango de los enteros sin signo de 16 bits es de 0 a 65535.
 */
#define VX_UINT16_MAX       (0xFFFFU) // Valor maximo para un tipo de 16 bits sin signo

/**
 * VX_UINT32_MAX:
 * Define el valor maximo para un tipo de 32 bits sin signo.
 * Este valor es 4294967295, ya que el rango de los enteros sin signo de 32 bits es de 0 a 4294967295.
 */
#define VX_UINT32_MAX       (0xFFFFFFFFU) // Valor maximo para un tipo de 32 bits sin signo


// Definicion de codigos de éxito y fracaso
/**
* VX_SUCCESS:
* Define el valor 0 como el codigo de éxito.
* Este valor es utilizado para indicar que una operación o función se ha completado correctamente.
*/
#define VX_SUCCESS (0)

/**
* VX_FAILURE:
* Define el valor 1 como el código de fracaso.
* Este valor es utilizado para indicar que una operación o función ha fallado.
*/
#define VX_FAILURE (1)


/**
 * __VX_INITIAL_CAPACITY__:
 * Define la capacidad inicial para una estructura de datos que puede expandirse.
 * Si no está definida previamente, la capacidad inicial se establece en 4.
 * Esto es útil en colecciones o estructuras dinámicas como listas o vectores donde se define un valor inicial de capacidad antes de que la colección crezca.
 */
#ifndef __VX_INITIAL_CAPACITY__
	#define __VX_INITIAL_CAPACITY__ 4
#else

	/**
	 * Si __VX_INITIAL_CAPACITY__ ya esta definida, no se vuelve a definir para evitar redefinición innecesaria.
	 */
	#define __VX_INITIAL_CAPACITY__ 0
#endif



// Si estamos en una CPU de 64 bits se define VX_UINT64_MAX con su valor correspondiente
/**
 * VX_UINT64_MAX:
 * Si la opción VX_USE_64_BIT_FOR_DEFINES está habilitada (indicando que estamos en una CPU de 64 bits),
 * se define VX_UINT64_MAX con el valor máximo posible para un entero sin signo de 64 bits. Este valor es
 * `0xFFFFFFFFFFFFFFFFU`, que es 18446744073709551615 en decimal.
 *
 * Si no estamos en una CPU de 64 bits, entonces se define VX_UINT64_MAX con el valor maximo de un entero
 * sin signo de 32 bits (`VX_UINT32_MAX`), que es 4294967295 (0xFFFFFFFF).
 */
#if VX_USE_64_BIT_FOR_DEFINES
	#define VX_UINT64_MAX (0xFFFFFFFFFFFFFFFFU) // Valor maximo para un entero sin signo de 64 bits
#else // De lo contrario
	#define VX_UINT64_MAX VX_UINT32_MAX // Valor maximo para un entero sin signo de 32 bits
#endif



// Definicion del valor maximo para un entero con signo de 64 bits
/**
 * VX_INT64_MAX:
 * Si la opción VX_USE_64_BIT_FOR_DEFINES está habilitada (indicando que estamos en una CPU de 64 bits),
 * se define VX_INT64_MAX con el valor máximo posible para un entero con signo de 64 bits. Este valor es
 * `0x7FFFFFFFFFFFFFFF`, que es 9223372036854775807 en decimal.
 *
 * Si no estamos en una CPU de 64 bits, entonces se define VX_INT64_MAX con el valor maximo de un entero
 * con signo de 32 bits (`VX_INT32_MAX`), que es 2147483647 (0x7FFFFFFF).
 */
#if VX_USE_64_BIT_FOR_DEFINES
	#define VX_INT64_MAX (0x7FFFFFFFFFFFFFFF) // Valor maximo para un entero con signo de 64 bits
#else // De lo contrario
	#define VX_INT64_MAX VX_INT32_MAX // Valor maximo para un entero con signo de 32 bits
#endif



#if defined(VX_CPLUSPLUS)
	/**
	 * Si estamos en C++, definimos el valor máximo para un enumerado en diferentes tamaños de bits.
	 * En C++, los valores de los enumerados pueden tener un tamaño de 8, 16, 32 y 64 bits, por lo tanto,
	 * se definen los valores máximos posibles para cada uno de esos tamaños.
	 */
	
	 // Definicion del valor maximo para un enumerado de 8 bits con signo
	#define VX_MAX_ENUM_8_BITS (0x7F) // 127, valor maximo para un entero de 8 bits con signo
	
	// Definicion del valor maximo para un enumerado de 16 bits con signo
	#define VX_MAX_ENUM_16_BITS (0x7FFF) // 32767, valor maximo para un entero de 16 bits con signo
	
	// Definicion del valor maximo para un enumerado de 32 bits con signo
	#define VX_MAX_ENUM_32_BITS (0x7FFFFFFF) // 2147483647, valor maximo para un entero de 32 bits con signo
	
	// Definicion del valor maximo para un enumerado de 64 bits con signo
	#define VX_MAX_ENUM_64_BITS (0x7FFFFFFFFFFFFFFF) // 9223372036854775807, valor maximo para un entero de 64 bits con signo
	
	// Definiciones de los valores maximos para enumerados sin signo
	#define VX_MAX_ENUM_8_BITS_UNSIGNED (VX_UINT8_MAX) // Valor maximo para un entero sin signo de 8 bits
	#define VX_MAX_ENUM_16_BITS_UNSIGNED (VX_UINT16_MAX) // Valor maximo para un entero sin signo de 16 bits
	#define VX_MAX_ENUM_32_BITS_UNSIGNED (VX_UINT32_MAX) // Valor maximo para un entero sin signo de 32 bits
	#define VX_MAX_ENUM_64_BITS_UNSIGNED (VX_UINT64_MAX) // Valor maximo para un entero sin signo de 64 bits
	
	// Definicion del valor maximo general para los enumerados, que será el valor maximo para un entero con signo de 32 bits
	#define VX_MAX_ENUM (VX_INT32_MAX)

#else
	/**
	 * Si estamos en C, el tamaño maximo para un enumerado está limitado a 32 bits y no puede ser mayor.
	 * Debido a esta restricción, todos los valores de los enumerados en C serán el valor máximo de un entero de 32 bits.
	 * Ademas, los valores máximos de los enumerados sin signo siguen siendo los mismos que para los enteros sin signo de 8, 16, 32 y 64 bits.
	 */
	
	  // En C, los enumerados siempre son de 32 bits, por lo que todos los valores máximos se definen con VX_INT32_MAX
	#define VX_MAX_ENUM_8_BITS (VX_INT32_MAX) // 2147483647, valor maximo para un entero con signo de 32 bits
	#define VX_MAX_ENUM_16_BITS (VX_INT32_MAX) // 2147483647, valor maximo para un entero con signo de 32 bits
	#define VX_MAX_ENUM_32_BITS (VX_INT32_MAX) // 2147483647, valor maximo para un entero con signo de 32 bits
	#define VX_MAX_ENUM_64_BITS (VX_INT32_MAX) // 2147483647, valor maximo para un entero con signo de 32 bits
	
	// Los valores maximos de los enumerados sin signo se definen con los valores máximos de los enteros sin signo de 8, 16, 32 y 64 bits
	#define VX_MAX_ENUM (VX_INT32_MAX) // El valor maximo general es igual al de un entero con signo de 32 bits
	#define VX_MAX_ENUM_8_BITS_UNSIGNED (VX_UINT8_MAX) // 255, valor maximo para un entero sin signo de 8 bits
	#define VX_MAX_ENUM_16_BITS_UNSIGNED (VX_UINT16_MAX) // 65535, valor maximo para un entero sin signo de 16 bits
	#define VX_MAX_ENUM_32_BITS_UNSIGNED (VX_UINT32_MAX) // 4294967295, valor maximo para un entero sin signo de 32 bits
	#define VX_MAX_ENUM_64_BITS_UNSIGNED (VX_UINT64_MAX) // 18446744073709551615, valor maximo para un entero sin signo de 64 bits
#endif


// Numero maximo de un entero de 64 bits sin signo
#ifndef _VX_SIZE_MAX_ // Verificamos si no se ha definido previamente _VX_SIZE_MAX_

	/**
	 * Si _VX_SIZE_MAX_ no está definido, lo definimos con el valor maximo
	 * para un entero de 64 bits sin signo (VX_UINT64_MAX), que es 18446744073709551615.
	 */
	#define _VX_SIZE_MAX_  VX_UINT64_MAX
#else 

	/**
	 * Si _VX_SIZE_MAX_ ya esta definido previamente, no realizamos cambios.
	 * Esto permite que la constante ya definida en otro lugar se utilice.
	 */
	#define _VX_SIZE_MAX_
#endif
// Definimos VX_SIZE_MAX con el valor de _VX_SIZE_MAX_
#define VX_SIZE_MAX _VX_SIZE_MAX_ 


// Definicion de constantes para el tipo de datos flotante (float)

// Valor minimo representable para un tipo float (32 bits), es el valor más pequeño distinto de 0
#define VX_FLOAT_MIN          1.175494351e-38F 

// Valor máximo representable para un tipo float (32 bits), es el valor más grande que puede almacenar
#define VX_FLOAT_MAX          3.402823466e+38F 

// La diferencia más pequeña entre 1.0 y el siguiente valor representable para un tipo float (32 bits)
#define VX_FLOAT_EPSILON      1.192092896e-07F

// El exponente más pequeño que un tipo float puede representar, se corresponde con la menor potencia de 10
#define VX_FLOAT_MIN_10_EXP   (-37)                   

// El exponente mínimo en base 2 que un tipo float puede representar
#define VX_FLOAT_MIN_EXP      (-125)   

// El radix de los números flotantes, es decir, la base del sistema numérico utilizado (en este caso base 2 para los flotantes de IEEE-754)
#define VX_FLOAT_RADIX        2


// Definicion de constantes para el tipo de datos doble (double)

// Valor minimo representable para un tipo double (64 bits), es el valor mas pequeño distinto de 0
#define VX_DOUBLE_MIN         2.2250738585072014e-308

// Valor máximo representable para un tipo double (64 bits), es el valor más grande que puede almacenar
#define VX_DOUBLE_MAX         1.7976931348623158e+308

// La diferencia mas pequeña entre 1.0 y el siguiente valor representable para un tipo double (64 bits)
#define VX_DOUBLE_EPSILON     2.2204460492503131e-016

// El valor mas pequeño representable para un tipo double, distinto de cero
#define VX_DOUBLE_TRUE_MIN    4.9406564584124654e-324

// Valor mínimo representable para un tipo double, igual que el anterior pero explícitamente reiterado
#define VX_DOUBLE_MIN         2.2250738585072014e-308 

// El exponente mas pequeño que un tipo double puede representar, se corresponde con la menor potencia de 10
#define VX_DOUBLE_MIN_10_EXP  (-307)   

// El radix de los numeros flotantes de tipo double, igual que en float, en este caso también es base 2
#define VX_DOUBLE_RADIX       2  




/*
* Estas definiciones ayudan a obtener el tamaño maximo de un array
*/
#ifndef _VX_ARRAY_SIZE_ // Optimizacion en tiempo de compilacion
	#define _VX_ARRAY_SIZE_(arr) (sizeof(arr) / sizeof(arr[0]))
#else // De lo contrario
	#define _VX_ARRAY_SIZE_(arr)
#endif // ^^^_VX_ARRAY_SIZE_^^^
/*
* Macro de alto nivel abstraida (util para seguridad)
*/
#define VX_ARRAY_SIZE(arr) _VX_ARRAY_SIZE_(arr)



// Define el bloque extern "C" para indicar que el código siguiente es de enlace C
// Esto permite que las funciones y variables sean accesibles desde otros lenguajes o programas escritos en C
#define VX_EXTERN_C_BEGIN extern "C" { // Define extern "C" en tiempo de compilacion

// Cierra el bloque de definicion de extern "C" iniciado previamente por VX_EXTERN_C_BEGIN
#define VX_EXTERN_C_END } // Cierra la definicion de VX_EXTERN_C_BEGIN


// Si estamos compilando con un compilador de C++, definimos el espacio de nombres "vertex::internal".
// Esto se usa para organizar el código y definir una separación clara entre las funcionalidades
// públicas de Vertex Engine y su implementación interna o privada.
#if defined(VX_CPLUSPLUS)

	/*
	* Espacio de nombres para código fuente relativamente interno o privado
	* de Vertex Engine.
	*
	* El uso de espacios de nombres permite evitar conflictos de nombres y
	* organizar mejor el código. En este caso, "vertex::internal" indica que
	* el código que sigue es parte de la implementación interna de Vertex Engine,
	* lo cual ayuda a gestionar el acceso y evitar que el código externo
	* (usuarios o clientes) interactúe con él directamente.
	*/
	#define VX_INTERNAL_BEGIN namespace vertex::internal { 

	// Si no estamos compilando con un compilador de C++, no utilizamos espacios de nombres
	// en el codigo, por lo que no es necesario definir nada aquí.
#else
	#define VX_INTERNAL_BEGIN
#endif // ^^^defined(VX_CPLUSPLUS)^^^


// Al igual que VX_INTERNAL_BEGIN, si estamos compilando con C++, definimos el cierre del espacio de nombres
#if defined(VX_CPLUSPLUS)
	#define VX_INTERNAL_END }
#else
	// Si no estamos usando C++, no definimos un espacio de nombres y no necesitamos cerrar nada.
	#define VX_INTERNAL_END
#endif







#endif 











