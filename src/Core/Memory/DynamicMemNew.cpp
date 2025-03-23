


#include "VxNew.h"
#include <cstdlib>  // Para malloc, free y posix_memalign

// Define la alineaci�n m�nima para cada plataforma
#if defined(_MSC_VER) // MSVC (Windows)
    #define VX_ALIGN 16
#elif defined(VX_COMP_CLANG) || defined(VX_COMP_GCC) // Clang y GCC (Android, Linux, macOS)
    #define VX_ALIGN 8
#else
    #define VX_ALIGN 8 // Alineaci�n por defecto
#endif


// Definici�n de funci�n para nueva asignaci�n de memoria
VX_NODISCARD VX_ALLOCATOR
void* operator new(VxSize _Size) {
    void* _Ptr = nullptr;

#if defined(VX_COMP_MSVC) // MSVC (Windows)
    _Ptr = ::malloc(_Size);  // Usamos malloc para la asignaci�n est�ndar en MSVC
#elif defined(VX_COMP_CLANG) || defined(VX_COMP_GCC) // Clang y GCC (Linux, macOS)
    ptr = ::malloc(_Size);  // Usamos malloc para la asignaci�n est�ndar
#else
    ptr = ::malloc(_Size);  // En otras plataformas, por defecto usamos malloc
#endif

    if (!_Ptr) {
        //throw std::bad_alloc(); // Lanza una excepci�n si no se puede asignar memoria
    }
    return _Ptr;
}

// Nueva asignaci�n sin excepciones
VX_NODISCARD VX_ALLOCATOR
void* operator new(VxSize _Size, vertex::vx_nothrow const&) noexcept {
    void* _Ptr = nullptr;

#if defined(VX_COMP_MSVC) // MSVC (Windows)
    _Ptr = ::malloc(_Size);  // Usamos malloc para la asignaci�n est�ndar en MSVC
#elif defined(VX_COMP_CLANG) || defined(VX_COMP_GCC) // Clang y GCC (Linux, macOS)
    ptr = ::malloc(_Size);  // Usamos malloc para la asignaci�n est�ndar
#else
    ptr = ::malloc(_Size);  // En otras plataformas, por defecto usamos malloc
#endif

    if (!_Ptr) {
        return nullptr; // Retorna nullptr si no se puede asignar memoria
    }
    return _Ptr;
}

// Asignaci�n para arreglos de memoria
VX_NODISCARD VX_ALLOCATOR
void* operator new[](VxSize _Size) {
    void* _Ptr = nullptr;

#if defined(_MSC_VER) // MSVC (Windows)
    _Ptr = ::malloc(_Size);  // Usamos malloc para la asignaci�n est�ndar en MSVC
#elif defined(__clang__) || defined(__GNUC__) // Clang y GCC (Linux, macOS)
    ptr = ::malloc(_Size);  // Usamos malloc para la asignaci�n est�ndar
#else
    ptr = ::malloc(_Size);  // En otras plataformas, por defecto usamos malloc
#endif

    if (!_Ptr) {
        //throw std::bad_alloc(); // Lanza una excepci�n si no se puede asignar memoria
    }
    return _Ptr;
}

// Asignaci�n para arreglos de memoria sin excepciones
VX_NODISCARD VX_ALLOCATOR
void* operator new[](VxSize _Size, vertex::vx_nothrow const&) noexcept {
    void* _Ptr = nullptr;

#if defined(VX_COMP_MSVC) // MSVC (Windows)
    _Ptr = ::malloc(_Size);  // Usamos malloc para la asignaci�n est�ndar en MSVC
#elif defined(VX_COMP_CLANG) || defined(VX_COMP_GCC) // Clang y GCC (Linux, macOS)
    ptr = ::malloc(_Size);  // Usamos malloc para la asignaci�n est�ndar
#else
    ptr = ::malloc(_Size);  // En otras plataformas, por defecto usamos malloc
#endif

    if (!_Ptr) {
        return nullptr; // Retorna nullptr si no se puede asignar memoria
    }
    return _Ptr;
}

// Funci�n para liberar memoria
void operator delete(void* _Block) noexcept {
    if (_Block) {
        ::free(_Block); // Liberamos la memoria
    }
}

// Funci�n para liberar memoria sin excepciones
void operator delete(void* _Block, vertex::vx_nothrow const&) noexcept {
    if (_Block) {
        ::free(_Block); // Liberamos la memoria
    }
}

// Funci�n para liberar memoria de un arreglo de elementos
void operator delete[](void* _Block) noexcept {
    if (_Block) {
        ::free(_Block); // Liberamos la memoria
    }
}

// Funci�n para liberar memoria de un arreglo de elementos sin excepciones
void operator delete[](void* _Block, vertex::vx_nothrow const&) noexcept {
    if (_Block) {
        ::free(_Block); // Liberamos la memoria
    }
}

// Funci�n para liberar memoria con tama�o especificado
void operator delete(void* _Block, VxSize _Size) noexcept {
    if (_Block) {
        ::free(_Block); // Liberamos la memoria
    }
}

// Funci�n para liberar memoria de un arreglo con tama�o especificado
void operator delete[](void* _Block, VxSize _Size) noexcept {
    if (_Block) {
        ::free(_Block); // Liberamos la memoria
    }
}

// Funciones de asignaci�n y liberaci�n de memoria alineada

#ifdef __cpp_aligned_new

VX_NODISCARD VX_ALLOCATOR
void* operator new(VxSize _Size, vertex::vx_align_val _Al) {
    void* _Ptr = nullptr;

#if defined(VX_COMP_MSVC) // MSVC (Windows)
   _Ptr = ::_aligned_malloc(_Size, (VxSize)_Al);  // Usamos _aligned_malloc en MSVC
#elif defined(VX_COMP_CLANG) || defined(VX_COMP_GCC) // Clang y GCC (Linux, macOS)
    if (posix_memalign(&ptr, _Al, _Size) != 0) {  // Usamos posix_memalign en Linux y macOS
        return nullptr; // Retorna nullptr si no se puede asignar memoria
    }
#else
    ptr = ::malloc(_Size);  // En otras plataformas, por defecto usamos malloc
#endif

    if (!_Ptr) {
        //throw std::bad_alloc(); // Lanza una excepci�n si no se puede asignar memoria
    }

    return _Ptr;
}

// Funci�n para asignar memoria alineada sin excepciones
VX_NODISCARD VX_ALLOCATOR
void* operator new(VxSize _Size, vertex::vx_align_val _Al, vertex::vx_nothrow const&) noexcept {
    void* _Ptr = nullptr;

#if defined(VX_COMP_MSVC) // MSVC (Windows)
    _Ptr = ::_aligned_malloc(_Size, (VxSize)_Al);  // Usamos _aligned_malloc en MSVC
#elif defined(VX_COMP_CLANG) || defined(VX_COMP_GCC) // Clang y GCC (Linux, macOS)
    if (posix_memalign(&ptr, _Al, _Size) != 0) {  // Usamos posix_memalign en Linux y macOS
        return nullptr; // Retorna nullptr si no se puede asignar memoria
    }
#else
    ptr = ::malloc(_Size);  // En otras plataformas, por defecto usamos malloc
#endif

    if (!_Ptr) {
        return nullptr; // Retorna nullptr si no se puede asignar memoria
    }

    return _Ptr;
}

// Funci�n para liberar memoria alineada
void operator delete(void* _Block, vertex::vx_align_val _Al) noexcept {
    if (_Block) {
#if defined(VX_COMP_MSVC) // MSVC (Windows)
        ::_aligned_free(_Block);  // Usamos _aligned_free en MSVC
#elif defined(VX_COMP_CLANG) || defined(VX_COMP_GCC) // Clang y GCC (Linux, macOS)
        ::free(_Block);  // Usamos free en Linux y macOS
#else
        ::free(_Block);  // En otras plataformas, por defecto usamos free
#endif
    }
}

// Funci�n para liberar memoria alineada sin excepciones
void operator delete(void* _Block, vertex::vx_align_val _Al, vertex::vx_nothrow const&) noexcept {
    if (_Block) {
#if defined(VX_COMP_MSVC) // MSVC (Windows)
        ::_aligned_free(_Block);  // Usamos _aligned_free en MSVC
#elif defined(VX_COMP_CLANG) || defined(VX_COMP_MSVC) // Clang y GCC (Linux, macOS)
        ::free(_Block);  // Usamos free en Linux y macOS
#else
        ::free(_Block);  // En otras plataformas, por defecto usamos free
#endif
    }
}

// Funci�n para liberar memoria alineada de un arreglo
void operator delete[](void* _Block, vertex::vx_align_val _Al) noexcept {
    if (_Block) {
#if defined(VX_COMP_MSVC) // MSVC (Windows)
        _aligned_free(_Block);  // Usamos _aligned_free en MSVC
#elif defined(__clang__) || defined(__GNUC__) // Clang y GCC (Linux, macOS)
        ::free(_Block);  // Usamos free en Linux y macOS
#else
        ::free(_Block);  // En otras plataformas, por defecto usamos free
#endif
    }
}

// Funci�n para liberar memoria alineada de un arreglo sin excepciones
void operator delete[](void* _Block, vertex::vx_align_val _Al, vertex::vx_nothrow const&) noexcept {
    if (_Block) {
#if defined(VX_COMP_MSVC) // MSVC (Windows)
        ::_aligned_free(_Block);  // Usamos _aligned_free en MSVC
#elif defined(VX_COMP_CLANG) || defined(VX_COMP_GCC) // Clang y GCC (Linux, macOS)
        ::free(_Block);  // Usamos free en Linux y macOS
#else
        ::free(_Block);  // En otras plataformas, por defecto usamos free
#endif
    }
}

#endif // __cpp_aligned_new

