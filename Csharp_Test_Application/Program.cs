using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using EntityLibrary;

namespace SimpleClient
{

   class Program
   {
      static void Main(string[] args)
      {
         var entity = new ManagedEntity();
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