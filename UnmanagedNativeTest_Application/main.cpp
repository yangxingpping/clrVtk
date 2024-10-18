#include "NativeEntity.h"
#include "vtkPolyData.h"
#include <iostream>
#include <string>

#include "spdlog/spdlog.h"


int main()
{
    SPDLOG_INFO("native library test");

    NativeEntity* nt = new NativeEntity();
   
    return 0;
}