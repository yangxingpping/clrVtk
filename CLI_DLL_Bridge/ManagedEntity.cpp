#include "ManagedEntity.h"


using namespace System;
using namespace System::Runtime::InteropServices;	// needed for Marshal

namespace EntityLibrary
{
	ManagedEntity::ManagedEntity()
	{
		nativeObj = new NativeEntity();
		nativeObj->Init();
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

	IntPtr ManagedEntity::GetPolyData()
	{
		return System::IntPtr(nativeObj->GetPolyData());
	}
	Kitware::VTK::vtkPolyData^ ManagedEntity::GetClrPolyData()
	{
		Kitware::VTK::vtkPolyData^ ret = gcnew Kitware::VTK::vtkPolyData(GetPolyData(), false, true);
		return ret;
	}
}
