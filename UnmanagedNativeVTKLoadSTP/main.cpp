#include <iostream>
#include <string>

#include "STEPCAFControl_Reader.hxx"
#include "TopoDS_Face.hxx"
#include "IVtkOCC_Shape.hxx"
#include "vtkPolyDataMapper.h"
#include "vtkNew.h"
#include "vtkRenderer.h"
#include "vtkRenderWindow.h"
#include "vtkRenderWindowInteractor.h"
#include "vtkActor.h"
//#include "vtkSmartPointer.hxx"
#include "IVtkTools_ShapeDataSource.hxx"

using std::cout;
using std::endl;
using std::string;


int main()
{
    string file{ "../../stp1.stp" };
    TopoDS_Shape shape;
    STEPControl_Reader reader;
    auto status = reader.ReadFile(file.c_str());
    if(status != IFSelect_RetDone)
    {
        cout << "read file " << file << " failed with error " << status << endl;
        return -1;
    }
    reader.TransferRoot();
    shape = reader.Shape();
    IVtkOCC_Shape::Handle shapeimpl = new IVtkOCC_Shape(shape);
    vtkSmartPointer<IVtkTools_ShapeDataSource> ds = vtkSmartPointer<IVtkTools_ShapeDataSource>::New();
    ds->SetShape(shapeimpl);
    ds->Update();
    vtkNew<vtkPolyDataMapper> mapper;
    mapper->SetInputConnection(ds->GetOutputPort());
    vtkNew<vtkActor> actor;
    actor->SetMapper(mapper);
    vtkNew<vtkRenderer> renderer;
    vtkNew<vtkRenderWindow> renderWindow;
    renderWindow->AddRenderer(renderer);
    vtkNew<vtkRenderWindowInteractor> iter;
    iter->SetRenderWindow(renderWindow);
    renderer->AddActor(actor);
    renderWindow->Render();
    iter->Start();

    return 0;
}