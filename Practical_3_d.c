#include<windows.h>
#include <stdio.h>
#include <stdlib.h>
#include "helper.h"
void OnPaint(HWND);
void OnDestroy(HWND);
int _stdcall WinMain(HINSTANCE hInstance,HINSTANCE hPrevInst,LPSTR lpszCmdline,int nCmdShow)
{
    MSG m;
    InitInstance(hInstance,nCmdShow,"title");
    while(GetMessage(&m,NULL,0,0))
        DispatchMessage(&m);
    return 0;
}
int x1,y1,x2,y2;
LRESULT CALLBACK WndProc(HWND hWnd,UINT message,WPARAM wParam,LPARAM IParam)
{
/* In lParam the low order 16 bits contain the current x - coordinate of
the mouse whereas the high order 16 bits contain the y -
coordinate. The LOWORD and HIWORD macros have been
used to separate out these x and y - coordinates from lParam. */
    switch(message)
    {
        case WM_DESTROY:
            OnDestroy(hWnd);
            break;

        case WM_LBUTTONDOWN ://left button click
            OnLButtonDown ( hWnd, LOWORD ( IParam ),HIWORD ( IParam ) ) ;
            break ;

        case WM_LBUTTONUP: //releasing the left mouse button
            OnLButtonUp( ) ;
            break ;

        case WM_MOUSEMOVE :// for mouse movement
            OnMouseMove ( hWnd, wParam, LOWORD ( IParam ),HIWORD ( IParam ) ) ;
            break ;

        default:
            return DefWindowProc ( hWnd, message, wParam, IParam ) ;

    }
    return 0;
}
void OnDestroy(HWND hWnd)
{
    PostQuitMessage(0);
}

void OnLButtonDown ( HWND hWnd, int x, int y )
{
    SetCapture ( hWnd ) ;
    x1 = x ;
    y1 = y ;
}

void OnMouseMove ( HWND hWnd, int flags, int x, int y )
{
    HDC hdc ;
    if ( flags == MK_LBUTTON )  /* is left mouse button depressed */
    {
        hdc = GetDC ( hWnd ) ;
        x2 = x ;
        y2 = y ;
        MoveToEx ( hdc, x1, y1, NULL ) ;
        LineTo ( hdc, x2, y2 ) ;

        ReleaseDC ( hWnd, hdc ) ;

        x1 = x2 ;
        y1 = y2 ;
 }
}
void OnLButtonUp( )
{
 ReleaseCapture( ) ;
}