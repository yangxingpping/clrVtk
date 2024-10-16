#pragma once

#include <vector>
#include <string>
#ifdef EXAMPLEUNMANAGEDDLL_EXPORTS
#define EXAMPLEUNMANAGEDDLL_API __declspec(dllexport)
#else
#define EXAMPLEUNMANAGEDDLL_API __declspec(dllimport)
#endif

class EXAMPLEUNMANAGEDDLL_API NativeEntity
{
public:
	NativeEntity();

	//gets
	int GetInt();

	//sets
	void SetInt(int nInt);

private:
	int mInt{ 0 };
};