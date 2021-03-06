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
LRESULT CALLBACK WndProc(HWND hWnd,UINT message,WPARAM wParam,LPARAM IParam)
{
    switch(message)
    {
        case WM_DESTROY:
            OnDestroy(hWnd);
            break;
        case WM_PAINT :
            OnPaint(hWnd);
            break ;

        default:
            return DefWindowProc(hWnd,message,wParam,IParam);
    }
    return 0;
}
void OnDestroy(HWND hWnd)
{
    PostQuitMessage(0);
}
void OnPaint(HWND hWnd)
{
    HDC hdc;
    PAINTSTRUCT ps;
    HBRUSH hbr;
    HGDIOBJ holdbr;
    POINT pt[]={250,150,250,300,300,350,400,300,320,190};
    hdc=BeginPaint(hWnd,&ps);

    hbr=CreateSolidBrush(RGB(255,0,0));
    holdbr=SelectObject(hdc,hbr);

    MoveToEx(hdc,10,10,NULL);
    LineTo(hdc,200,10);

    Rectangle(hdc,10,20,200,100);

    RoundRect(hdc,10,120,200,220,20,20);

    Ellipse(hdc,10,240,200,340);

    Pie(hdc,250,10,350,110,350,110,350,10);

    Polygon(hdc,pt,5);

    SelectObject(hdc,holdbr);
    DeleteObject(hbr);



        EndPaint(hWnd,&ps);
}