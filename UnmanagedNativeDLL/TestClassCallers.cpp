#define WIN32_LEAN_AND_MEAN		// Exclude rarely-used stuff from Windows headers
#include <windows.h>

#include "TestClassCallers.h"


extern "C" EXAMPLEUNMANAGEDDLL_API NativeEntity* CreateTestClass()
{
	return new NativeEntity();
}

extern "C" EXAMPLEUNMANAGEDDLL_API void DisposeTestClass(NativeEntity* pObject)
{
	if (pObject != NULL)
	{
		delete pObject;
		pObject = NULL;
	}
}

extern "C"  EXAMPLEUNMANAGEDDLL_API int CallGetInt(NativeEntity* pObject)
{
	if (pObject != NULL)
	{
		return pObject->GetInt();
	}

	return NULL;
}

extern "C"  EXAMPLEUNMANAGEDDLL_API void CallSetInt(NativeEntity* pObject, int nInt)
{
	if (pObject != NULL)
	{
		pObject->SetInt(nInt);
	}
}
