#include "[Device]\D3Ddevice.h"
#include "[Device]\Render.h"
#include "[Device]\[Input_Manager]\Input_Manager.h"
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>


//#include <vld.h>
// _DEBUG




D3Ddevice *g_D3Ddevice;


LRESULT WINAPI MsgProc( HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam )
{
	switch( msg )
	{
	case WM_DESTROY:
		g_D3Ddevice->Cleanup();
		PostQuitMessage( 0 );

		return 0;

	case WM_PAINT:
		ValidateRect( hWnd, NULL );
		return 0;
	}

	return DefWindowProc( hWnd, msg, wParam, lParam );
}


INT WINAPI wWinMain( HINSTANCE hInst, HINSTANCE, LPWSTR, INT )
{
	//콘솔창 띄우기
	AllocConsole();
	g_D3Ddevice = new D3Ddevice();



	// Register the window class
	WNDCLASSEX wc =
	{
		sizeof( WNDCLASSEX ), CS_CLASSDC, MsgProc, 0L, 0L,
		GetModuleHandle( NULL ), NULL, NULL, NULL, NULL,
		"D3D Tutorial", NULL
	};
	RegisterClassEx( &wc );

	// Create the application's window
	HWND hWnd = CreateWindow( "D3D Tutorial", "D3D Tutorial 01: CreateDevice",
		WS_OVERLAPPEDWINDOW, 0, 0, 640, 640,
		NULL, NULL, wc.hInstance, NULL );
	// Initialize Direct3D
	
	if( SUCCEEDED( g_D3Ddevice->InitD3D( hWnd ) ) )
	{
	
		{
			// Show the window
			ShowWindow( hWnd, SW_SHOWDEFAULT );
			UpdateWindow( hWnd );

			// Enter the message loop
			MSG msg;
			ZeroMemory( &msg, sizeof( msg ) );
			while( msg.message != WM_QUIT )
			{
				if( PeekMessage( &msg, NULL, 0U, 0U, PM_REMOVE ) )
				{
					TranslateMessage( &msg );
					DispatchMessage( &msg );
				}
				else
					g_D3Ddevice->D3D_Render();

			}

		}

		UnregisterClass( "D3D Tutorial", wc.hInstance );
		
		
		SAFE_DELETE(g_D3Ddevice);
		return 0;
	}
}