#pragma once

#include "NativeEntity.h"
#include <vector>
namespace EntityLibrary
{
	using namespace System;
	public ref class ManagedEntity
	{
	public:
		ManagedEntity();
		~ManagedEntity();
		//Gets
		int GetInt();
		//Sets
		void SetInt(int nInt);

		void SetClrPolyData(Kitware::VTK::vtkPolyData^ pd);

		IntPtr GetPolyData();
		Kitware::VTK::vtkPolyData^ GetClrPolyData();
		Kitware::VTK::vtkPolyData^ GetCppPolyDataByCopy();
	private:
		NativeEntity* nativeObj; // Our native object is thus being wrapped
	};

}