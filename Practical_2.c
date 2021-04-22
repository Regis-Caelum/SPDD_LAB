#include <stdio.h>
#include <windows.h>

int __stdcall WinMain(HINSTANCE hInstance,HINSTANCE hPravInstance,LPSTR arg,int ncmdshow){

    HWND h;
    h = CreateWindow("Button", "push", WS_OVERLAPPEDWINDOW|WS_VSCROLL|WS_HSCROLL, 100, 100, 400, 100, 0, 0, 0, 0);
    int args = atoi(arg);
    switch(args){
    case 0:
        ShowWindow(h,SW_MINIMIZE);
        break;
    case 1:
        ShowWindow(h,SW_NORMAL);
        break;
    case 2:
        ShowWindow(h,SW_MAXIMIZE);
        break;
    }

    MessageBox(0,"HELLO","Hannibal",0);


    return(0);
}

