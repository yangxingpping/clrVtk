#include "NativeEntityVTK.h"
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

NativeEntityVTK::NativeEntityVTK()
{
	mPolyData = vtkPolyData::New();
}

NativeEntityVTK::~NativeEntityVTK()
{
	if (mPolyData != nullptr)
	{
		mPolyData->Delete();
		mPolyData = nullptr;
	}
}

void NativeEntityVTK::Reset(void* pt)
{
	if (mPolyData != nullptr)
	{
		mPolyData->Delete();
	}
	mPolyData = (vtkPolyData*)(pt);
	Init();
}

bool NativeEntityVTK::Init()
{
	std::array<std::array<double, 3>, 8> pts = { { { { 0, 0, 0 } }, { { 1, 0, 0 } }, { { 1, 1, 0 } },
	{ { 0, 1, 0 } }, { { 0, 0, 1 } }, { { 1, 0, 1 } }, { { 1, 1, 1 } }, { { 0, 1, 1 } } } };
	// The ordering of the corner points on each face.
	std::array<std::array<vtkIdType, 4>, 6> ordering = { { { { 0, 1, 2, 3 } }, { { 4, 5, 6, 7 } },
	  { { 0, 1, 5, 4 } }, { { 1, 2, 6, 5 } }, { { 2, 3, 7, 6 } }, { { 3, 0, 4, 7 } } } };
	vtkPoints* points{ nullptr };
	if (mPolyData->GetPoints())
	{
		std::cout << "polyData points is not empty" << std::endl;
		points = mPolyData->GetPoints();
	}
	else
	{
		points = vtkPoints::New();
		mPolyData->SetPoints(points);
	}
	//vtkNew<vtkPoints> points;
	vtkNew<vtkCellArray> polys;
	vtkNew<vtkFloatArray> scalars;

	// Load the point, cell, and data attributes.
	for (auto i = 0ul; i < pts.size(); ++i)
	{
		points->InsertPoint(i, pts[i].data());
		scalars->InsertTuple1(i, i);
	}
	for (auto&& i : ordering)
	{
		polys->InsertNextCell(vtkIdType(i.size()), i.data());
	}
	mPolyData->SetPolys(polys);
	std::cout << "ploys count=" << polys->GetSize() << " points count=" << mPolyData->GetPoints()->GetNumberOfPoints() << std::endl;
	mPolyData->GetPointData()->SetScalars(scalars);
	return true;
}

vtkPolyData* NativeEntityVTK::GetPolyData()
{
	return mPolyData;
}

