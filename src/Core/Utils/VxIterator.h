

/*
* 
* Creado por Vertex Software el (25-02-2025)
* 
* Este archiv tiene como objetivo crear la implementacion para iteradores para 
* Vertex Engine, teniendo una utilidad para futuros contenedores o estructuras 
* de datos.
* 
* Antes de leer este archivo es recomendable leer los archivos:
* 
* 
* 
*/





#ifndef VX_ITERATOR_H
#define VX_ITERATOR_H





#include "../src/Core/VxPackCore.h"
#include "Core/Debugging/DebuggerCodes.h"



VX_BEGIN


#if defined(VX_CPLUSPLUS)




class iterator {
private:

    int var;

public:

    iterator();
    ~iterator() ;


};




#else









#endif




VX_END

#endif



