#include "ManagedEntity.h"

using namespace EntityLibrary;
using namespace System;
using namespace System::Runtime::InteropServices;	// needed for Marshal


ManagedEntity::ManagedEntity()
{
	nativeObj = new NativeEntity();
}


ManagedEntity::~ManagedEntity()
{
	delete nativeObj;

}

int ManagedEntity::GetInt()
{
	int tempInt = nativeObj->GetInt();
	return tempInt;
}

void ManagedEntity::SetInt(int nInt)
{
	nativeObj->SetInt(nInt);
}
