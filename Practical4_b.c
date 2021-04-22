
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
int x=00,y=250,z=00;
LRESULT CALLBACK WndProc(HWND hWnd,UINT message,WPARAM wParam,LPARAM IParam)
{
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

        case WM_RBUTTONDOWN ://Right button click
            OnRButtonDown ( hWnd, LOWORD ( IParam ),HIWORD ( IParam ) ) ;
            break ;

        case WM_RBUTTONUP: //releasing the right mouse button
            OnRButtonUp( ) ;
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

void OnLButtonDown ( HWND hWnd, int x1, int y1 )
{
    HDC hdc ;
    SetCapture ( hWnd ) ;
    hdc = GetDC ( hWnd ) ;
    SetTextColor(hdc,RGB(x,y,z));
    TextOut(hdc,x1,y1,"Hello",5);
}


void OnLButtonUp( )
{
 ReleaseCapture( ) ;
}

void OnRButtonDown ( HWND hWnd, int x1, int y1 )
{
    HDC hdc ;
    SetCapture ( hWnd ) ;
    hdc = GetDC ( hWnd ) ;
    x=(rand()%(256)); //0 to 256 values.
    y=(rand()%(256));
    z=(rand()%(256));
    SetTextColor(hdc,RGB(x,y,z));
    TextOut(hdc,x1,y1,"Hello",5);
}


void OnRButtonUp( )
{
 ReleaseCapture( ) ;
}
