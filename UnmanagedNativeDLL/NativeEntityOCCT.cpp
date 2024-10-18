#include "NativeEntityOCCT.h"
#include <string>
#include <iostream>
#include <array>
 

#include "vtkPolyData.h"
#include "vtkPointData.h"
#include "vtkFloatArray.h"
#include "vtkVersion.h"

#include "TopoDS_Face.hxx"
#include "BRepPrimAPI_MakeBox.hxx"
#include "IVtkOCC_Shape.hxx"
#include "IVtkTools_ShapeDataSource.hxx"

#define WIN32_LEAN_AND_MEAN		// Exclude rarely-used stuff from Windows headers
#include <windows.h>

class InnerShape
{

};

NativeEntityOCCT::NativeEntityOCCT()
{
	mPolyData = vtkPolyData::New();
}

NativeEntityOCCT::~NativeEntityOCCT()
{
	if (mPolyData != nullptr)
	{
		mPolyData->Delete();
		mPolyData = nullptr;
	}
}

void NativeEntityOCCT::Reset(void* pt)
{
	if (mPolyData != nullptr)
	{
		mPolyData->Delete();
	}
	mPolyData = (vtkPolyData*)(pt);
	Init();
}

bool NativeEntityOCCT::Init()
{
	auto box =  BRepPrimAPI_MakeBox(1.0, 2.0, 3.0);
	auto shape = box.Shape();
	IVtkOCC_Shape::Handle shapeImpl = new IVtkOCC_Shape(shape);
	auto ds = vtkSmartPointer<IVtkTools_ShapeDataSource>::New();
	ds->SetShape(shapeImpl);
	ds->Update();
	mPolyData = ds->GetOutput();
	return true;
}

vtkPolyData* NativeEntityOCCT::GetPolyData()
{
	return mPolyData;
}

