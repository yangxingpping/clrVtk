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

	void ManagedEntity::SetClrPolyData(Kitware::VTK::vtkPolyData^ pd)
	{

	}

	IntPtr ManagedEntity::GetPolyData()
	{
		bool bfound{ false };
		auto typecount = Kitware::mummy::Runtime::Methods::GetTypeEntryCount();
		Console::WriteLine("typecount={0}", typecount);
		//auto clrPoly = Kitware::mummy::Runtime::Methods::CreateWrappedObject("class vtkPolyData", System::IntPtr(nativeObj->GetPolyData()), true, bfound);
		//Console::WriteLine("found c++ vtkPolyData flag={0}", bfound);
		return System::IntPtr(nativeObj->GetPolyData());
	}
	Kitware::VTK::vtkPolyData^ ManagedEntity::GetClrPolyData()
	{
		Kitware::VTK::vtkPolyData^ ret = Kitware::VTK::vtkPolyData::New();
		void* vpt = ret->GetCppThis().Handle.ToPointer();
		nativeObj->Reset(vpt);
		Console::WriteLine("point count={0}", ret->GetPoints()->GetNumberOfPoints());
		return ret;
	}
}
