#include "ManagedEntity.h"
#include "vtkPointData.h"
#include "vtkPolyData.h"

#include <iostream>
using std::cout;
using std::endl;

using namespace System;
using namespace System::Runtime::InteropServices;	// needed for Marshal

namespace EntityLibrary
{
	ManagedEntity::ManagedEntity()
	{
		nativeObj = new NativeEntity();
		ret = gcnew Kitware::VTK::vtkPolyData();
		pts = gcnew Kitware::VTK::vtkPoints();
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
		ret->SetPoints(pts);
		void* vpt = ret->GetCppThis().Handle.ToPointer();
		nativeObj->Reset(vpt);
		auto clrPts = ret->GetPoints();
		Console::WriteLine("point count={0}", clrPts->GetNumberOfPoints());
		return ret;
	}

	Kitware::VTK::vtkPolyData^ ManagedEntity::GetCppPolyDataByCopy(bool second)
	{
		Kitware::VTK::vtkPolyData^ ret = gcnew Kitware::VTK::vtkPolyData();
		Kitware::VTK::vtkPoints^ cpoints = gcnew Kitware::VTK::vtkPoints();
		Kitware::VTK::vtkDataArray^ cnor = gcnew Kitware::VTK::vtkFloatArray();
		Kitware::VTK::vtkDataArray^ cuvs = gcnew Kitware::VTK::vtkFloatArray();
		Kitware::VTK::vtkCellArray^ cpolys = gcnew Kitware::VTK::vtkCellArray();
		Kitware::VTK::vtkCellArray^ clines = gcnew Kitware::VTK::vtkCellArray();
		if (second)
		{
			nativeObj->Init2();
		}
		auto cppPolyData = nativeObj->GetPolyData();
		auto pts = cppPolyData->GetPoints();
		auto nor = cppPolyData->GetPointData()->GetNormals();
		auto uvs = cppPolyData->GetPointData()->GetTCoords();
		auto polys = cppPolyData->GetPolys();
		auto lines = cppPolyData->GetLines();
		if (pts)
		{
			cout << "point count=" << pts->GetNumberOfPoints() << endl;
			for (vtkIdType i = 0; i < pts->GetNumberOfPoints(); ++i)
			{
				auto pt = pts->GetPoint(i);
				cpoints->InsertPoint(i, pt[0], pt[1], pt[2]);
			}
		}
		if (nor)
		{
			cout << "normal count=" << nor->GetNumberOfTuples() << endl;
			cnor->SetNumberOfComponents(3);
			for (vtkIdType i = 0; i < nor->GetNumberOfTuples(); ++i)
			{
				auto tp = nor->GetTuple(i);
				cnor->InsertNextTuple3(tp[0], tp[1], tp[2]);
			}
		}
		if (uvs)
		{
			cout << "uv count=" << uvs->GetNumberOfTuples() << endl;
			uvs->SetNumberOfComponents(3);
			for (vtkIdType i = 0; i < uvs->GetNumberOfTuples(); ++i)
			{
				auto tp = uvs->GetTuple(i);
				cuvs->InsertNextTuple3(tp[0], tp[1], tp[2]);
			}
		}
		if (polys)
		{
			int cellIndex{ 0 };
			vtkIdList* idList = vtkIdList::New();
			while (polys->GetNextCell(idList))
			{
				Kitware::VTK::vtkIdList^ dst = gcnew Kitware::VTK::vtkIdList();
				for (vtkIdType i = 0; i < idList->GetNumberOfIds(); ++i)
				{
					dst->InsertNextId(idList->GetId(i));
				}
				cpolys->InsertNextCell(dst);
				++cellIndex;
			}
			idList->Delete();
			cout << "polys count=" << cellIndex << endl;
		}
		if (lines)
		{
			int cellIndex{ 0 };
			vtkIdList* idList = vtkIdList::New();
			while (lines->GetNextCell(idList))
			{
				Kitware::VTK::vtkIdList^ dst = gcnew Kitware::VTK::vtkIdList();
				for (vtkIdType i = 0; i < idList->GetNumberOfIds(); ++i)
				{
					dst->InsertNextId(idList->GetId(i));
				}
				clines->InsertNextCell(dst);
				++cellIndex;
			}
			idList->Delete();
			cout << "lines count=" << cellIndex << endl;
		}
		ret->SetPoints(cpoints);
		ret->SetPolys(cpolys);
		ret->SetLines(clines);
		if (cnor->GetSize() > 0)
		{
			ret->GetPointData()->SetNormals(cnor);
		}
		ret->GetPointData()->SetTCoords(cuvs);
		return ret;
	}

}
