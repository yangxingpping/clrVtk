#include "NativeEntity.h"

#include <iostream>
#include <string>

void printVector(std::vector<double> &temp)
{
    for (const auto& j : temp)
    {
        std::cout << j;
        if (j != temp.back()) std::cout << ", ";
    }
    std::cout << std::endl;
}


int main()
{
    std::cout << "NativeEntity DLL Test C++ Program." <<std::endl;

    NativeEntity* nt = new NativeEntity();
    nt->Init();
    auto pd = nt->GetPolyData();

    return 0;
}