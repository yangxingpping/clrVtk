#include "NativeEntity.h"
#include "NativeEntityOCCT.h"
#include <iostream>
#include <string>

#include "spdlog/spdlog.h"


int main()
{
    SPDLOG_INFO("native library test");

    NativeEntity* nt = new NativeEntity();
    NativeEntityOCCT* occ = new NativeEntityOCCT();
    bool bret = occ->Init();
    
    return 0;
}