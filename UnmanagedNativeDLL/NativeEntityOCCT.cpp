#include "NativeEntityOCCT.h"
#include <string>
#include <iostream>
#include <array>
#include <memory>
#include <map>
 
#include "vtkPolyData.h"
#include "vtkPointData.h"
#include "vtkFloatArray.h"
#include "vtkVersion.h"

#include "TopoDS_Face.hxx"
#include "BRepPrimAPI_MakeBox.hxx"
#include "IVtkOCC_Shape.hxx"
#include "IVtkTools_ShapeDataSource.hxx"

#include "spdlog/spdlog.h"

#define WIN32_LEAN_AND_MEAN		// Exclude rarely-used stuff from Windows headers
#include <windows.h>

using std::shared_ptr;
using std::make_shared;
using std::map;

class InnerShape
{
public:
	shared_ptr<BRepBuilderAPI_MakeShape> _shapeSrc;
	IVtkOCC_Shape::Handle shapeImpl;
	vtkSmartPointer<IVtkTools_ShapeDataSource> sds;
};

static map<NativeEntityOCCT*, shared_ptr<InnerShape>> _impl;

NativeEntityOCCT::NativeEntityOCCT()
{
	mPolyData = vtkPolyData::New();
	shared_ptr<InnerShape> _shape = make_shared<InnerShape>();
	_impl.insert({ this, _shape });
}

NativeEntityOCCT::~NativeEntityOCCT()
{
	if (mPolyData != nullptr)
	{
		mPolyData->Delete();
		mPolyData = nullptr;
	}
	auto ecount = _impl.erase(this);
	if (ecount == 0)
	{
		SPDLOG_WARN("something wrong TBD");
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
	auto it = _impl.find(this);
	if (it == _impl.end())
	{
		SPDLOG_WARN("init failed");
		return false;
	}
	auto _shape = it->second;
	_shape->_shapeSrc = make_shared<BRepPrimAPI_MakeBox>(1.0, 2.0, 3.0);
	auto shape = _shape->_shapeSrc->Shape();
	_shape->shapeImpl = new IVtkOCC_Shape(shape);
	_shape->sds = vtkSmartPointer<IVtkTools_ShapeDataSource>::New();
	_shape->sds->SetShape(_shape->shapeImpl);
	_shape->sds->Update();
	mPolyData = _shape->sds->GetOutput();
	return true;
}

vtkPolyData* NativeEntityOCCT::GetPolyData()
{
	return mPolyData;
}

