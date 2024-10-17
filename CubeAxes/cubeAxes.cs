using Kitware.VTK;
using System;
using EntityLibrary;

public class cubeAxesClass
{
    public static void InitLODActor()
    {
        fohe = vtkBYUReader.New();
        fohe.SetGeometryFileName("../../teapot.g");

        // Create a vtkPolyDataNormals filter to calculate the normals of the data set.
        normals = vtkPolyDataNormals.New();
        normals.SetInputConnection(fohe.GetOutputPort());

        // Set up the associated mapper and actor.
        foheMapper = vtkPolyDataMapper.New();
        foheMapper.SetInputConnection(normals.GetOutputPort());

        foheActor = vtkLODActor.New();
        foheActor.SetMapper(foheMapper);
    }
    public static void InitOutlineActor()
    {
        // Create a vtkOutlineFilter to draw the bounding box of the data set.  Also
        // create the associated mapper and actor.
        outline = vtkOutlineFilter.New();
        outline.SetInputConnection(normals.GetOutputPort());

        mapOutline = vtkPolyDataMapper.New();
        mapOutline.SetInputConnection(outline.GetOutputPort());

        outlineActor = vtkActor.New();
        outlineActor.SetMapper(mapOutline);
        outlineActor.GetProperty().SetColor(0, 0, 0);
    }
    public static void InitCamera()
    {
        // Create a vtkCamera, and set the camera parameters.
        camera = vtkCamera.New();
        camera.SetClippingRange(1.60187, 20.0842);
        camera.SetFocalPoint(0.21406, 1.5, 0);
        camera.SetPosition(8.3761, 4.94858, 4.12505);
        camera.SetViewUp(0.180325, 0.549245, -0.815974);
    }
    public static void InitLight()
    {
        // Create a vtkLight, and set the light parameters.
        light = vtkLight.New();
        light.SetFocalPoint(0.21406, 1.5, 0);
        light.SetPosition(8.3761, 4.94858, 4.12505);
    }
    public static void InitAxesProp()
    {
        // Create a text property for both cube axes
        tprop = vtkTextProperty.New();
        tprop.SetColor(1, 1, 1);
        tprop.ShadowOn();
    }
    public static void CreateWinLeftBottom()
    {
        ren1 = vtkRenderer.New();
        ren1.SetViewport(0, 0, 0.5, 0.5);
        ren1.SetActiveCamera(camera);
        ren1.AddLight(light);
        ren1.AddViewProp(foheActor);
        ren1.AddViewProp(outlineActor);
        ren1.SetBackground(0.1, 0.2, 0.4);
        // Create a vtkCubeAxesActor2D.  Use the outer edges of the bounding box to
        // draw the axes.  Add the actor to the renderer.
        axes = vtkCubeAxesActor2D.New();
        axes.SetInputConnection(normals.GetOutputPort());
        axes.SetCamera(ren1.GetActiveCamera());
        axes.SetLabelFormat("%6.4g");
        axes.SetFlyModeToOuterEdges();
        axes.SetFontFactor(0.8);
        axes.SetAxisTitleTextProperty(tprop);
        axes.SetAxisLabelTextProperty(tprop);
        ren1.AddViewProp(axes);

        var txtTag = vtkTextActor.New();
        txtTag.SetInput("load from file");
        ren1.AddActor(txtTag);
    }
    public static void CreateWinRightBottom()
    {
        var obj = new ManagedEntity();
        ren2 = vtkRenderer.New();
        ren2.SetViewport(0.5, 0, 1.0, 1.0);
        ren2.SetActiveCamera(camera);
        ren2.AddLight(light);
        polyDataMapper = vtkPolyDataMapper.New();
        polyDataMapper.SetInputData(obj.GetCppPolyDataByCopy());
        polyDataActor = vtkActor.New();
        polyDataActor.SetMapper(polyDataMapper);
        polyDataActor.GetProperty().SetDiffuseColor(1, 0, 0);
        polyDataActor.GetProperty().SetSpecular(0);
        polyDataActor.GetProperty().SetSpecularPower(5.0);
        ren2.AddViewProp(polyDataActor);
        //ren2.AddViewProp(foheActor);
        ren2.AddViewProp(outlineActor);
        ren2.SetBackground(0.1, 0.2, 0.4);
        // Create a vtkCubeAxesActor2D.  Use the closest vertex to the camera to
        // determine where to draw the axes.  Add the actor to the renderer.
        axes2 = vtkCubeAxesActor2D.New();
        axes2.SetViewProp(foheActor);
        axes2.SetCamera(ren2.GetActiveCamera());
        axes2.SetLabelFormat("%6.4g");
        axes2.SetFlyModeToClosestTriad();
        axes2.SetFontFactor(0.8);
        axes2.ScalingOff();
        axes2.SetAxisTitleTextProperty(tprop);
        axes2.SetAxisLabelTextProperty(tprop);
        ren2.AddViewProp(axes2);
        var txtTag = vtkTextActor.New();
        txtTag.SetInput("load vtkPolyData from cpp");
        ren2.AddActor(txtTag);
    }
    public static void CreateWinLeftTop()
    {
        var obj = new ManagedEntity();
        ren3 = vtkRenderer.New();
        ren3.SetViewport(0, 0.5, 0.5, 1.0);
        ren3.SetActiveCamera(camera);
        ren3.AddLight(light);
        polyDataMapper = vtkPolyDataMapper.New();
        polyDataMapper.SetInputData(obj.GetCppPolyDataByCopy());
        polyDataActor = vtkActor.New();
        polyDataActor.SetMapper(polyDataMapper);
        polyDataActor.GetProperty().SetDiffuseColor(1, 0, 0);
        polyDataActor.GetProperty().SetSpecular(0);
        polyDataActor.GetProperty().SetSpecularPower(5.0);
        ren3.AddViewProp(polyDataActor);
        ren3.AddViewProp(outlineActor);
        ren3.SetBackground(0.1, 0.2, 0.4);
        // Create a vtkCubeAxesActor2D.  Use the closest vertex to the camera to
        // determine where to draw the axes.  Add the actor to the renderer.
        axes3 = vtkCubeAxesActor2D.New();
        axes3.SetViewProp(foheActor);
        axes3.SetCamera(ren2.GetActiveCamera());
        axes3.SetLabelFormat("%6.4g");
        axes3.SetFlyModeToClosestTriad();
        axes3.SetFontFactor(0.8);
        axes3.ScalingOff();
        axes3.SetAxisTitleTextProperty(tprop);
        axes3.SetAxisLabelTextProperty(tprop);
        ren3.AddViewProp(axes3);
        var txtTag = vtkTextActor.New();
        txtTag.SetInput("load vtkPolyData from cpp");
        ren3.AddActor(txtTag);
    }
    public static void Main(String[] argv)
    {
        InitLODActor();
        InitOutlineActor();
        InitCamera();
        InitLight();
        InitAxesProp();

        CreateWinLeftBottom();
        CreateWinRightBottom();
        CreateWinLeftTop();
        
        // Create the RenderWindow and RenderWindowInteractor.
        renWin = vtkRenderWindow.New();
        renWin.AddRenderer(ren1);
        renWin.AddRenderer(ren2);
        renWin.AddRenderer(ren3);
        renWin.SetWindowName("VTK - Cube Axes");
        renWin.SetSize(600, 300);
        iren = vtkRenderWindowInteractor.New();
        iren.SetRenderWindow(renWin);
        vtkInteractorStyleSwitch.SafeDownCast(iren.GetInteractorStyle()).SetCurrentStyleToTrackballCamera();

        // Render
        renWin.Render();

        // Start event loop
        iren.Start();

        // Set up a check for aborting rendering.
        renWin.AbortCheckEvt += new vtkObject.vtkObjectEventHandler(TkCheckAbort);
        
        //Clean Up  
        deleteAllVTKObjects();
    }

    static vtkBYUReader fohe;
    static vtkPolyDataNormals normals;
    static vtkPolyDataMapper foheMapper;
    static vtkLODActor foheActor;
    static vtkOutlineFilter outline;
    static vtkPolyDataMapper mapOutline;
    static vtkActor outlineActor;
    static vtkCamera camera;
    static vtkLight light;
    static vtkRenderer ren1;
    static vtkRenderer ren2;
    static vtkRenderer ren3;
    static vtkRenderWindow renWin;
    static vtkRenderWindowInteractor iren;
    static vtkTextProperty tprop;
    static vtkCubeAxesActor2D axes;
    static vtkCubeAxesActor2D axes2;
    static vtkCubeAxesActor2D axes3;
    static vtkPolyDataMapper polyDataMapper;
    static vtkActor polyDataActor;
    static int foo;

    /// <summary>
    /// Callback function for renWin.AbortCheckEvt
    /// </summary>
    public static void TkCheckAbort(vtkObject sender, vtkObjectEventArgs e)
    {
        foo = renWin.GetEventPending();
        if ((foo) != 0)
        {
            renWin.SetAbortRender(1);
        }
    }

    ///<summary>Deletes all static objects created</summary>
    public static void deleteAllVTKObjects()
    {
        //clean up vtk objects
        if (fohe != null) { fohe.Dispose(); }
        if (normals != null) { normals.Dispose(); }
        if (foheMapper != null) { foheMapper.Dispose(); }
        if (foheActor != null) { foheActor.Dispose(); }
        if (outline != null) { outline.Dispose(); }
        if (mapOutline != null) { mapOutline.Dispose(); }
        if (outlineActor != null) { outlineActor.Dispose(); }
        if (camera != null) { camera.Dispose(); }
        if (light != null) { light.Dispose(); }
        if (ren1 != null) { ren1.Dispose(); }
        if (ren2 != null) { ren2.Dispose(); }
        if (renWin != null) { renWin.Dispose(); }
        if (iren != null) { iren.Dispose(); }
        if (tprop != null) { tprop.Dispose(); }
        if (axes != null) { axes.Dispose(); }
        if (axes2 != null) { axes2.Dispose(); }
        if (polyDataMapper != null) { polyDataMapper.Dispose(); }
        if (polyDataActor != null) { polyDataActor.Dispose(); }
    }
}

