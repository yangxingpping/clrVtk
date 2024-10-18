#pragma once

#include <vector>
#include <string>
#ifdef EXAMPLEUNMANAGEDDLL_EXPORTS
#define EXAMPLEUNMANAGEDDLL_API __declspec(dllexport)
#else
#define EXAMPLEUNMANAGEDDLL_API __declspec(dllimport)
#endif

class vtkPolyData;

class EXAMPLEUNMANAGEDDLL_API NativeEntityOCCT
{
public:
	NativeEntityOCCT();
	NativeEntityOCCT(const NativeEntityOCCT& ref) = delete;
	NativeEntityOCCT(const NativeEntityOCCT&& ref) = delete;
	~NativeEntityOCCT();
	void Reset(void* pt);
	bool Init();
	vtkPolyData* GetPolyData();

private:
	vtkPolyData* mPolyData{ nullptr };
	
};