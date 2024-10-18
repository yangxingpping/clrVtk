#pragma once
#include "NativeEntity.h"
#include "NativeEntityOCCT.h"
#include "NativeEntityVTK.h"

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

		//IntPtr GetPolyData();
		//Kitware::VTK::vtkPolyData^ GetClrPolyData();
		Kitware::VTK::vtkPolyData^ GetCppPolyDataByCopy(bool second);

		Kitware::VTK::vtkPolyData^ GetVTKPolyData();
		Kitware::VTK::vtkPolyData^ GetOCCTPolyData();
	protected:
		Kitware::VTK::vtkPolyData^ _getPolyDataFromCpp(vtkPolyData* pd);
	private:
		NativeEntity* nativeObj{ nullptr }; // Our native object is thus being wrapped
		NativeEntityOCCT* occt{ nullptr };
		NativeEntityVTK* vtk{ nullptr };
	};

}