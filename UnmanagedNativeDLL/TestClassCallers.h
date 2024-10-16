#ifndef __TestClassCallers_h__
#define __TestClassCallers_h__

#include "NativeEntity.h"		// needed for EXAMPLEUNMANAGEDDLL_API

#ifdef __cplusplus
extern "C"
{
#endif

	extern EXAMPLEUNMANAGEDDLL_API NativeEntity* CreateTestClass();
	extern EXAMPLEUNMANAGEDDLL_API void DisposeTestClass(NativeEntity* pObject);

	extern EXAMPLEUNMANAGEDDLL_API int CallGetInt(NativeEntity* pObject);
	extern EXAMPLEUNMANAGEDDLL_API void CallSetInt(NativeEntity* pObject, int nInt);

#ifdef __cplusplus
}
#endif

#endif // __TestClassCallers_h__

