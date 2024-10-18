include_directories(
  # Native DLL header files to include
  ${NATIVEENTITY_INCLUDE_DIR}
  )
  
SET(UnmanagedNativeTest_Application_SOURCE 
   main.cpp)
   
   
add_executable(UnmanagedNativeVTKLoadSTP ${UnmanagedNativeTest_Application_SOURCE})

target_link_libraries(UnmanagedNativeVTKLoadSTP PRIVATE spdlog::spdlog  PRIVATE ${OpenCASCADE_LIBRARIES} )

#ADD_DEPENDENCIES(NativeEntity_Test_Application NativeEntity)   