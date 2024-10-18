#pragma once

#include <vector>
#include <string>
#ifdef EXAMPLEUNMANAGEDDLL_EXPORTS
#define EXAMPLEUNMANAGEDDLL_API __declspec(dllexport)
#else
#define EXAMPLEUNMANAGEDDLL_API __declspec(dllimport)
#endif

class vtkPolyData;

class EXAMPLEUNMANAGEDDLL_API NativeEntityVTK
{
public:
	NativeEntityVTK();
	NativeEntityVTK(const NativeEntityVTK& ref) = delete;
	NativeEntityVTK(const NativeEntityVTK&& ref) = delete;
	~NativeEntityVTK();
	void Reset(void* pt);
	bool Init();
	//gets
	vtkPolyData* GetPolyData();
private:
	vtkPolyData* mPolyData{ nullptr };
	
};