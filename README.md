#TBD
外部库依赖:
    VTK,版本(5fd6015c),从gitlab上获取
    OCCT,版本(7.8.1),从github上获取
    ActiviZ,版本(ActiViz.NET 9.3.2024 Trial Edition),从官网获取
C++,CLR项目使用CMake管理, CLR工程对ActiviZ的依赖也需要手动加入。
C#项目(CubeAxes)使用visual studio管理,在使用cmake生成vs工程之后，需要单独把CubeAxes.csproj加载到cmake生成的解决方案(.sln)中手动加入对ActiviZ库的依赖

模块说明:
    UnmanagedNativeDLL: 使用OCCT topoDS_Shape生成C++ vtkPolyData功能模块
    CLI_DLL_Bridge: 把 UnmanagedNativeDLL 模块生成对象转换成ActiviZ         vtkPolyData的功能模块
    CubeAxes: 使用ActiviZ渲染vtkPolyData，并测试部分ActiviZ功能接口demo
    UnmanagedNativeVTKLoadSTP: 使用C++导入stp文件并使用VTK渲染demo
    UnmanagedNativeTest_Application: 测试UnmanagedNativeDLL模块demo

其他说明:
    使用cmake生成c#项目的参考链接，后续可以考虑整个项目都使用CMake来管理。
    https://stackoverflow.com/questions/2074144/generate-c-sharp-project-using-cmake
    https://github.com/hepcatjk/CsharpCLICplusplusDLLExample.git