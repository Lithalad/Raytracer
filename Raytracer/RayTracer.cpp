// RayTracer.cpp : Defines the entry point for the application.
//

#include "stdafx.h"
#include "RayTracer.h"
#include "PerspectiveCamera.h"
#include "Plane.h"
#include "Triangle.h"
#include "Sphere.h"
#include "AxisAlignedBox.h"
#include "World.h"
#include "SingleColourMaterial.h"
#include "LambertMaterial.h"
#include "PhongMaterial.h"
#include "PointLight.h"
#include "SpotLight.h"
#include "Tracer.h"
#include "ReflectiveMaterial.h"
#include "TransparentMaterial.h"
#include "Node.h"

#define MAX_LOADSTRING 100

	COLORREF ConvertColour(raytracer::Colour<double> colour )
	{
		int r = (int)(colour.GetRed() *255);
		int g = (int)(colour.GetGreen() *255);
		int b = (int)(colour.GetBlue() *255);

		if (r > 255)
		{
			r = 255;
		}

		if (g > 255)
		{
			g = 255;
		}

		if (b > 255)
		{
			b = 255;
		}

		return RGB(r,g,b);
	}

// Global Variables:
HINSTANCE hInst;								// current instance
TCHAR szTitle[MAX_LOADSTRING];					// The title bar text
TCHAR szWindowClass[MAX_LOADSTRING];			// the main window class name

// Forward declarations of functions included in this code module:
ATOM				MyRegisterClass(HINSTANCE hInstance);
BOOL				InitInstance(HINSTANCE, int);
LRESULT CALLBACK	WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK	About(HWND, UINT, WPARAM, LPARAM);

int APIENTRY _tWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPTSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(lpCmdLine);

 	// TODO: Place code here.
	MSG msg;
	HACCEL hAccelTable;

	// Initialize global strings
	LoadString(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
	LoadString(hInstance, IDC_RAYTRACER, szWindowClass, MAX_LOADSTRING);
	MyRegisterClass(hInstance);

	// Perform application initialization:
	if (!InitInstance (hInstance, nCmdShow))
	{
		return FALSE;
	}

	hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_RAYTRACER));

	// Main message loop:
	while (GetMessage(&msg, NULL, 0, 0))
	{
		if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}

	return (int) msg.wParam;
}



//
//  FUNCTION: MyRegisterClass()
//
//  PURPOSE: Registers the window class.
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
	WNDCLASSEX wcex;

	wcex.cbSize = sizeof(WNDCLASSEX);

	wcex.style			= CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc	= WndProc;
	wcex.cbClsExtra		= 0;
	wcex.cbWndExtra		= 0;
	wcex.hInstance		= hInstance;
	wcex.hIcon			= LoadIcon(hInstance, MAKEINTRESOURCE(IDI_RAYTRACER));
	wcex.hCursor		= LoadCursor(NULL, IDC_ARROW);
	wcex.hbrBackground	= (HBRUSH)(COLOR_WINDOW+1);
	wcex.lpszMenuName	= MAKEINTRESOURCE(IDC_RAYTRACER);
	wcex.lpszClassName	= szWindowClass;
	wcex.hIconSm		= LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

	return RegisterClassEx(&wcex);
}

//
//   FUNCTION: InitInstance(HINSTANCE, int)
//
//   PURPOSE: Saves instance handle and creates main window
//
//   COMMENTS:
//
//        In this function, we save the instance handle in a global variable and
//        create and display the main program window.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   HWND hWnd;

   hInst = hInstance; // Store instance handle in our global variable

   hWnd = CreateWindow(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
      CW_USEDEFAULT, 0, 640, 480, NULL, NULL, hInstance, NULL);

   if (!hWnd)
   {
      return FALSE;
   }

   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   return TRUE;
}

//
//  FUNCTION: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  PURPOSE:  Processes messages for the main window.
//
//  WM_COMMAND	- process the application menu
//  WM_PAINT	- Paint the main window
//  WM_DESTROY	- post a quit message and return
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	int wmId, wmEvent;
	PAINTSTRUCT ps;
	HDC hdc;

	switch (message)
	{
	case WM_COMMAND:
		wmId    = LOWORD(wParam);
		wmEvent = HIWORD(wParam);
		// Parse the menu selections:
		switch (wmId)
		{
		case IDM_ABOUT:
			DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
			break;
		case IDM_EXIT:
			DestroyWindow(hWnd);
			break;
		default:
			return DefWindowProc(hWnd, message, wParam, lParam);
		}
		break;
	case WM_PAINT:
		{
			hdc = BeginPaint(hWnd, &ps);
			// TODO: Add any drawing code here...
			RECT rcClient;
			GetClientRect(hWnd, &rcClient);
		
			raytracer::math::ColumnVector< double, 3> e( 8, 8, 0);
			raytracer::math::ColumnVector< double, 3> g( -1, -1, -1);
			raytracer::math::ColumnVector< double, 3> t( 0, 1, 0);
			double Angle = 3.1415 / 8.0;
			unsigned int uiHeight = rcClient.bottom -rcClient.top;
			unsigned int uiWidth = rcClient.right - rcClient.left;

			raytracer::PerspectiveCamera<double> cam ( uiWidth,uiHeight,e,g,t,Angle);


			raytracer::math::ColumnVector< double, 3> pl( 0, 10, 0);
			raytracer::Colour<double> lightColour(1.0,1.0,1.0);
			//raytracer::SpotLight<double> SpotLight(lightColour, e, g, 3.1415/16);
			raytracer::PointLight<double> PointLight(lightColour, pl);

			raytracer::math::ColumnVector< double, 3> n( 0, 1, 0);
			raytracer::Colour<double> dColour(0.0,1.0,0.0);
			raytracer::Colour<double> sColour(0.0,0.0,0.0);
			raytracer::Colour<double> rColour(1.0,1.0,1.0);
			raytracer::Colour<double> backgroundColour(0.3,0.3,0.3);
			raytracer::Colour<double> ambientlight(0.0,0.0,0.0);
			raytracer::ReflectiveMaterial<double> ReflectionMaterial(dColour, sColour, rColour, 4);
			raytracer::LambertMaterial<double> Lam (dColour);

			raytracer::Plane<double> plane(&Lam);

			raytracer::World<double> world( backgroundColour, ambientlight, 1.003);
			world.addGeometry(plane);
			world.addLight(PointLight);



			raytracer::Colour<double> diffuseColour(1.0,0.0,0.0);
			raytracer::Colour<double> specularColour(0.5, 0.5, 0.5);

			raytracer::PhongMaterial<double> Phong1 (diffuseColour, specularColour, 4);
			raytracer::TransparentMaterial<double> Glass (1.5);

			raytracer::LambertMaterial<double> lm (diffuseColour);

			raytracer::Sphere<double> sphere(&Glass);
			//world.addGeometry(sphere);

			raytracer::Colour<double> colour3(1.0,0.0,1.0);
			raytracer::LambertMaterial<double> Lambert2(colour3);
			raytracer::math::ColumnVector< double, 3> One( 0, 0, -10);
			raytracer::math::ColumnVector< double, 3> Two( 0, 2, -10);
			raytracer::math::ColumnVector< double, 3> Three( 1, 1, -10);
			raytracer::math::ColumnVector< double, 3> nT( 0, 0, 1);


			raytracer::Triangle<double> triangle ( &Lambert2,One,Two,Three, nT, nT, nT);
			world.addGeometry(triangle);

			raytracer::Colour<double> colour4(0.5, 0.5, 0.5);
			raytracer::LambertMaterial<double> Lambert3(colour4);
			raytracer::math::ColumnVector< double, 3> vectorA( 0, 0, -6);
			raytracer::math::ColumnVector< double, 3> VectorB( 2, 2, -5);
			//raytracer::AxisAlignedBox<double> box (&Lambert3, vectorA, VectorB);
			//world.addGeometry(box);
			raytracer::Tracer<double> tracer;

			raytracer::Transform<double> transformation;
			transformation.Scale(1.5,1,1);
			transformation.Translate(0, 1, -3);
			raytracer::Node<double> node (transformation);
			node.addGeometry(sphere);
			world.addGeometry(node);

			for ( int x = rcClient.left; x< rcClient.right; x++)
			{
				for ( int y = rcClient.top; y< rcClient.bottom; y++)
				{
					
					raytracer::Ray<double> ray = cam.RayFor(x, uiHeight - y);
					SetPixel(hdc,x,y,ConvertColour(tracer.Trace(ray, world)));

				
				}
			}
			EndPaint(hWnd, &ps);
		}
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
}

// Message handler for about box.
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
	UNREFERENCED_PARAMETER(lParam);
	switch (message)
	{
	case WM_INITDIALOG:
		return (INT_PTR)TRUE;

	case WM_COMMAND:
		if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
		{
			EndDialog(hDlg, LOWORD(wParam));
			return (INT_PTR)TRUE;
		}
		break;
	}
	return (INT_PTR)FALSE;
}
