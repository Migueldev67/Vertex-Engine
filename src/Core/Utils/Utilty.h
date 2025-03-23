



#ifndef VX_UTILITY_H
#define VX_UTILITY_H


#include <utility>
#include "Core/VxPackCore.h"


VX_BEGIN


#if defined(VX_CPLUSPLUS)


template <typename _Ty1, typename _Ty2>
struct VxPair {

	using _Firts_type = _Ty1;
	using _Second_type = _Ty2;

	_Ty1 Firts;
	_Ty2 Second;







};






















#else







#endif



VX_END







#endif