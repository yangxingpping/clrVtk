using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading.Tasks;
using EntityLibrary;

namespace SimpleClient
{
   class Program
   {
      static void Main(string[] args)
      {
         var mypd = Kitware.VTK.vtkPolyData.New();
         var entity = new ManagedEntity();

         var pd = entity.GetPolyData();
         var bfound = false;
         var pd2 = Kitware.mummy.Runtime.Methods.CreateWrappedObject("class vtkPolyData", pd, true, out bfound);
         var pd3 = pd2 as Kitware.VTK.vtkPolyData;
         var pts = pd3.GetPoints();
         var polys = pd3.GetPolys();
         var ptsc = pts.GetNumberOfPoints();
         //var clrpd = entity.GetClrPolyData();
         //var pts = clrpd.GetPoints();
         //var polys = clrpd.GetPolys();
         //var polyc = polys.GetSize();

         var clrPolyData = Kitware.VTK.vtkPolyData.New();
         var entity2 = new ManagedEntity();
         entity2.SetClrPolyData(clrPolyData);

         var myInt = 1;
         //Test Int
         System.Console.WriteLine("C# - Value for int: {0}", myInt);
         System.Console.WriteLine("C# - C++ Value stored for the int: {0}", entity.GetInt());
         myInt = entity.GetInt();
         System.Console.WriteLine("C# - Value for int after GetInt: {0}", myInt);
         entity.SetInt(100);
         System.Console.WriteLine("C# - C++ Value stored for the int: {0} \n", entity.GetInt());
      }
   }
}