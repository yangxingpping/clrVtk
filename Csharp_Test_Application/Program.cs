using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading.Tasks;
using EntityLibrary;
using Kitware.VTK;

namespace SimpleClient
{
    class Program
    {
        static void copyAllDataFromCppTest()
        {
            var entity = new ManagedEntity();
            var polyData = entity.GetCppPolyDataByCopy();
        }

        static void sendCLRPolyDataToCpp()
        {
            var entity = new ManagedEntity();
            var pd = entity.GetClrPolyData();
        }

        static void Main(string[] args)
        {
            //var mypd = Kitware.VTK.vtkPolyData.New();
            var entity = new ManagedEntity();
            Console.WriteLine("csharp vtk version: {0}.{1}.{2}", Kitware.VTK.vtkVersion.GetVTKMajorVersion(), Kitware.VTK.vtkVersion.GetVTKMinorVersion(), Kitware.VTK.vtkVersion.GetVTKBuildVersion());
            //sendCLRPolyDataToCpp();
            copyAllDataFromCppTest();
            //var pd = entity.GetPolyData();
            //var bfound = false;
            //var pd2 = Kitware.mummy.Runtime.Methods.CreateWrappedObject("class vtkPolyData", pd, true, out bfound);
            //var pd3 = pd2 as Kitware.VTK.vtkPolyData;
            //var pts = pd3.GetPoints();
            //var polys = pd3.GetPolys();
            //var ptsc = pts.GetNumberOfPoints();
            //var clrpd = entity.GetClrPolyData();
            //var pts = clrpd.GetPoints();
            //var polys = clrpd.GetPolys();
            //var polyc = polys.GetSize();


        }
    }
}