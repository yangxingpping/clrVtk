#pragma once

#include <vector>
#include <string>
#ifdef EXAMPLEUNMANAGEDDLL_EXPORTS
#define EXAMPLEUNMANAGEDDLL_API __declspec(dllexport)
#else
#define EXAMPLEUNMANAGEDDLL_API __declspec(dllimport)
#endif

class vtkPolyData;

class EXAMPLEUNMANAGEDDLL_API NativeEntity
{
public:
	NativeEntity();
	NativeEntity(const NativeEntity& ref) = delete;
	NativeEntity(const NativeEntity&& ref) = delete;
	~NativeEntity();
	//gets
	int GetInt();

	//sets
	void SetInt(int nInt);

private:
	int mInt{ 0 };
	
};