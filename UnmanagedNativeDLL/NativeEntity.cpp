#include "NativeEntity.h"
#include <string>
#include <iostream>
#include <array>

#include "vtkPolyData.h"
#include "vtkFloatArray.h"

#define WIN32_LEAN_AND_MEAN		// Exclude rarely-used stuff from Windows headers
#include <windows.h>
#ifdef _MANAGED
#pragma managed(push, off)
#endif

BOOL APIENTRY DllMain(HMODULE /*hModule*/, DWORD	ul_reason_for_call, LPVOID /*lpReserved*/)
{
	switch (ul_reason_for_call)
	{
	case DLL_PROCESS_ATTACH:
	case DLL_THREAD_ATTACH:
	case DLL_THREAD_DETACH:
	case DLL_PROCESS_DETACH:
		break;
	}
	return TRUE;
}

#ifdef _MANAGED
#pragma managed(pop)
#endif

NativeEntity::NativeEntity()
{
	mPolyData = vtkPolyData::New();
}

NativeEntity::~NativeEntity()
{
	if (mPolyData != nullptr)
	{
		mPolyData->Delete();
		mPolyData = nullptr;
	}
}

bool NativeEntity::Init()
{
	std::array<std::array<double, 3>, 8> pts = { { { { 0, 0, 0 } }, { { 1, 0, 0 } }, { { 1, 1, 0 } },
	{ { 0, 1, 0 } }, { { 0, 0, 1 } }, { { 1, 0, 1 } }, { { 1, 1, 1 } }, { { 0, 1, 1 } } } };
	// The ordering of the corner points on each face.
	std::array<std::array<vtkIdType, 4>, 6> ordering = { { { { 0, 1, 2, 3 } }, { { 4, 5, 6, 7 } },
	  { { 0, 1, 5, 4 } }, { { 1, 2, 6, 5 } }, { { 2, 3, 7, 6 } }, { { 3, 0, 4, 7 } } } };

	vtkNew<vtkPoints> points;
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

	// We now assign the pieces to the vtkPolyData.
	mPolyData->SetPoints(points);
	mPolyData->SetPolys(polys);
	std::cout << "ploys count=" << polys->GetSize() << std::endl;
	//mPolyData->GetPointData()->SetScalars(scalars);
	return true;
}

int NativeEntity::GetInt()
{
	return mInt;
}

vtkPolyData* NativeEntity::GetPolyData()
{
	return mPolyData;
}


void NativeEntity::SetInt(int nInt)
{
	mInt = nInt;
}
