

#ifndef VX_TUPLE_H
#define VX_TUPLE_H

#include "Core/VxPackCore.h"

#if defined(VX_CPLUSPLUS)



VX_INTERNAL_BEGIN

template <typename _Ty>
struct __tuple_val__ {
	_Ty _Val;

	VX_CONSTEXPR20 __tuple_val__() 
		: _Val() {}


	/*template <typename _Other>
	VX_CONSTEXPR20 __tuple_val__(_Other&& _Arg) 
		: _Val(forward)*/

};



VX_INTERNAL_END



VX_BEGIN





template <typename _This, typename... _Rest>
class VxTuple {
private:


public:
};








#else




#endif

VX_END



#endif