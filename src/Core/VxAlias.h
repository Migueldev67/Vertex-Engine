/*
*
* Creado por Vertex Software el (20-02-2025)
* 
* Este encabezado tiene como objetivo principal definir aliases para mejorar
* la legibilidad del codigo y mantener la hoja de estilos del codigo.
*
* Se le sugiere que se lea el archivo "VxConfig.h" o "../Vertex-Engine/src/Core/VxConfig.h"
*
*
*/

#ifndef VX_ALIAS_h
#define VX_ALIAS_H

#include "VxConfig.h"


// Definimos alias de tipos de datos comunes para mejorar la legibilidad y portabilidad.
// Esto permite que en el futuro sea más fácil cambiar un tipo de dato sin afectar todo el código.
VX_DEFINE_ALIAS(VxVoid, void)                // Alias para el tipo void.
VX_DEFINE_ALIAS(VxVoidPtr, void*)             // Alias para el puntero a void.
VX_DEFINE_ALIAS(VxByte, unsigned char)       // Alias para unsigned char, comúnmente utilizado para bytes.
VX_DEFINE_ALIAS(VxWord, unsigned short)      // Alias para unsigned short, usado para representaciones de 16 bits.
VX_DEFINE_ALIAS(VxDword, unsigned int)       // Alias para unsigned int, usado para representaciones de 32 bits.

#if defined(VX_CPLUSPLUS)
    // En C++, definimos el alias para nullptr de forma explícita.
    VX_DEFINE_ALIAS_WITH_DECLTYPE(VxNullptr, nullptr) // Alias para nullptr, solo disponible en C++.
#endif

// Definición de alias para 64 bits y 32 bits, dependiendo de la configuración del compilador.
// Esto facilita la interoperabilidad y la adaptación del código a diferentes arquitecturas.

#if VX_USE_64_BIT_FOR_DEFINES
    // Si se utiliza una arquitectura de 64 bits, se definen los alias con tipos de 64 bits.
    VX_DEFINE_ALIAS(VxQword, VX_INT64)           // Alias para un entero de 64 bits con signo.

    // Alias para el tipo de booleano, usando la configuración predeterminada de VX_BOOL.
    VX_DEFINE_ALIAS(VxBool, VX_BOOL)             // Alias para el tipo booleano.
    VX_DEFINE_ALIAS(VxBoolean, VX_BOOL)          // Alias alternativo para booleano.

    VX_DEFINE_ALIAS(VxChar, char)                // Alias para char, un tipo de carácter.
    VX_DEFINE_ALIAS(VxUchar, unsigned char)      // Alias para unsigned char, un tipo de carácter sin signo.

    // Alias para los tipos enteros con signo de diferentes tamaños.
    VX_DEFINE_ALIAS(VxInt8, VX_INT8)             // Alias para un entero de 8 bits con signo.
    VX_DEFINE_ALIAS(VxInt16, VX_INT16)           // Alias para un entero de 16 bits con signo.
    VX_DEFINE_ALIAS(VxInt32, VX_INT32)           // Alias para un entero de 32 bits con signo.
    VX_DEFINE_ALIAS(VxInt64, VX_INT64)           // Alias para un entero de 64 bits con signo.

    // Alias para los tipos enteros sin signo de diferentes tamaños.
    VX_DEFINE_ALIAS(VxUint8, unsigned VX_INT8)   // Alias para un entero sin signo de 8 bits.
    VX_DEFINE_ALIAS(VxUint16, unsigned VX_INT16) // Alias para un entero sin signo de 16 bits.
    VX_DEFINE_ALIAS(VxUint32, unsigned VX_INT32) // Alias para un entero sin signo de 32 bits.
    VX_DEFINE_ALIAS(VxUint64, unsigned VX_INT64) // Alias para un entero sin signo de 64 bits.

    // Alias para otros tipos importantes como tamaño, bandera y máscara de muestra.
    VX_DEFINE_ALIAS(VxSize, VxUint64)           // Alias para el tipo de tamaño (generalmente 64 bits).
    VX_DEFINE_ALIAS(VxFlags, VxUint32)          // Alias para un tipo de bandera (32 bits).
    VX_DEFINE_ALIAS(VxSampleMask, VxUint32)     // Alias para la máscara de muestra (32 bits).

    // Alias para tipos de punto flotante.
    VX_DEFINE_ALIAS(VxFloat, float)             // Alias para tipo float (32 bits).
    VX_DEFINE_ALIAS(VxDouble, double)           // Alias para tipo double (64 bits).
    VX_DEFINE_ALIAS(VxLdouble, long double)     // Alias para tipo long double (mayor precisión).

    // Alias para punteros y enteros de tipo plataforma.
    VX_DEFINE_ALIAS(VxIntptr, VX_INT64)         // Alias para un puntero de 64 bits.
    VX_DEFINE_ALIAS(VxUintptr, unsigned VX_INT64) // Alias para un puntero sin signo de 64 bits.
    VX_DEFINE_ALIAS(VxPtrdiff, unsigned VX_INT64) // Alias para u tipo entero que se hace llamar puntero.
#else
    // Si no se utiliza una arquitectura de 64 bits, definimos los alias con tamaños estándar de 32 bits.
    VX_DEFINE_ALIAS(VxQword, int)               // Alias para un entero de 32 bits (en lugar de 64 bits).

    VX_DEFINE_ALIAS(VxBool, VX_BOOL)            // Alias para el tipo booleano.
    VX_DEFINE_ALIAS(VxBoolean, VX_BOOL)         // Alias alternativo para booleano.

    VX_DEFINE_ALIAS(VxChar, char)               // Alias para char.
    VX_DEFINE_ALIAS(VxUchar, unsigned char)     // Alias para unsigned char.

    // Alias para enteros con signo.
    VX_DEFINE_ALIAS(VxInt8, char)               // Alias para un entero de 8 bits con signo (char).
    VX_DEFINE_ALIAS(VxInt16, short)             // Alias para un entero de 16 bits con signo.
    VX_DEFINE_ALIAS(VxInt32, int)               // Alias para un entero de 32 bits con signo.
    VX_DEFINE_ALIAS(VxInt64, int)               // Alias para un entero de 32 bits (en lugar de 64 bits).

    // Alias para enteros sin signo.
    VX_DEFINE_ALIAS(VxUint8, unsigned char)    // Alias para un entero sin signo de 8 bits.
    VX_DEFINE_ALIAS(VxUint16, unsigned short)  // Alias para un entero sin signo de 16 bits.
    VX_DEFINE_ALIAS(VxUint32, unsigned int)    // Alias para un entero sin signo de 32 bits.
    VX_DEFINE_ALIAS(VxUint64, unsigned int)    // Alias para un entero sin signo de 32 bits (en lugar de 64 bits).

    // Alias para otros tipos como tamaño, bandera y máscara de muestra.
    VX_DEFINE_ALIAS(VxSize, VxUint64)          // Alias para el tipo de tamaño (64 bits).
    VX_DEFINE_ALIAS(VxFlags, VxUint32)         // Alias para un tipo de bandera (32 bits).
    VX_DEFINE_ALIAS(VxSampleMask, VxUint32)    // Alias para la máscara de muestra (32 bits).

    // Alias para tipos de punto flotante.
    VX_DEFINE_ALIAS(VxFloat, float)            // Alias para tipo float (32 bits).
    VX_DEFINE_ALIAS(VxDouble, double)          // Alias para tipo double (64 bits).
    VX_DEFINE_ALIAS(VxLdouble, long double)    // Alias para tipo long double (precisión mayor).

    // Alias para punteros y enteros de tipo plataforma.
    VX_DEFINE_ALIAS(VxIntptr, int)             // Alias para puntero de 32 bits (en lugar de 64 bits).
    VX_DEFINE_ALIAS(VxUintptr, unsigned int)   // Alias para puntero sin signo de 32 bits (en lugar de 64 bits).
    VX_DEFINE_ALIAS(VxPtrdiff, unsigned int)   // Alias para u tipo entero que se hace llamar puntero.
#endif









#endif

