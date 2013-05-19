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
#include "PointLight.h"

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
		
			raytracer::math::ColumnVector< double, 3> e( 0, 1, 0);
			raytracer::math::ColumnVector< double, 3> g( 0, 0, -1);
			raytracer::math::ColumnVector< double, 3> t( 0, 1, 0);
			double Angle = 3.1415 / 8.0;
			unsigned int uiHeight = rcClient.bottom -rcClient.top;
			unsigned int uiWidth = rcClient.right - rcClient.left;

			raytracer::PerspectiveCamera<double> cam ( uiWidth,uiHeight,e,g,t,Angle);

			raytracer::Colour<double> lightColour(1.0,1.0,1.0);
			raytracer::PointLight<double> pLight (lightColour, e);
			

			raytracer::math::ColumnVector< double, 3> a( 0, 0, 0);
			raytracer::math::ColumnVector< double, 3> n( 0, 1, 0);
			raytracer::Colour<double> colour(1.0,0.0,0.0);
			raytracer::Colour<double> backgroundColour(0.3,0.3,0.3);
			raytracer::Colour<double> ambientlight(0.0,0.0,0.0);
			raytracer::SingleColourMaterial<double> sgMat1(colour);

			raytracer::Plane<double> plane(&sgMat1, a, n);

			raytracer::World<double> world( backgroundColour, ambientlight);
			world.addGeometry(plane);
			world.addLight(pLight);

			raytracer::Colour<double> colour2(1.0,1.0,0.0);
			raytracer::LambertMaterial<double> lm (colour2);
			double r = 1;
			raytracer::math::ColumnVector< double, 3> c( 0, 0, -3);
			raytracer::Sphere<double> sphere(&lm, c, r);
			world.addGeometry(sphere);

			raytracer::Colour<double> colour3(1.0,0.0,1.0);
			raytracer::SingleColourMaterial<double> sgMat3(colour3);
			raytracer::math::ColumnVector< double, 3> One( 0, 0, -3);
			raytracer::math::ColumnVector< double, 3> Two( 0, 2, -3);
			raytracer::math::ColumnVector< double, 3> Three( 1, 1, -3);



			raytracer::Triangle<double> triangle ( &sgMat3,One,Two,Three);
			world.addGeometry(triangle);

			raytracer::Colour<double> colour4(0.5, 0.5, 0.5);
			raytracer::SingleColourMaterial<double> sgMat4(colour4);
			raytracer::math::ColumnVector< double, 3> vectorA( -1, 0, -4);
			raytracer::math::ColumnVector< double, 3> VectorB( 1, 2, -3);
			raytracer::AxisAlignedBox<double> box (&sgMat4, vectorA, VectorB);
			world.addGeometry(box);
			

			for ( int x = rcClient.left; x< rcClient.right; x++)
			{
				for ( int y = rcClient.top; y< rcClient.bottom; y++)
				{
					
					raytracer::Ray<double> ray = cam.RayFor(x, uiHeight - y);

					raytracer::ShadeRecord<double> shadeRecord;

					world.hit(ray, shadeRecord);
					
					if (shadeRecord.IsValid())
					{
						SetPixel(hdc,x,y,ConvertColour(shadeRecord.GetGeomety()->GetMaterial()->ColourAt(shadeRecord, &world)));
					}

					else
					{
						SetPixel(hdc,x,y,ConvertColour(world.GetBackgroundColour()));
					}
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
