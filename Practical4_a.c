#include<windows.h>
#include "helper.h"
#include<stdio.h>
#include<stdlib.h>
#define WINVER 0x0501

int flag = 0;  //First time
int init_x , init_y;
int prev_x, prev_y;
int limit = 0; //No of lines
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
void OnDestroy(HWND);
void MarkPoints(HWND, int, int);
int __stdcall WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR args, int nCmdShow)
{
   MSG m;
   InitInstance(hInstance, nCmdShow, "Title"); //Creates a new window
   while(GetMessage(&m, NULL, 0, 0)){
    DispatchMessage(&m);
   }
   return 0;
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam){

  switch(message){

     case WM_DESTROY:  OnDestroy(hWnd); break;
     case WM_LBUTTONDOWN: MarkPoints(hWnd, LOWORD(lParam), HIWORD(lParam)); break;
     //case WM_RBUTTONDOWN: flag = 0; limit=0; break;
     default : return DefWindowProc(hWnd, message, wParam, lParam);
  }

}

void OnDestroy(HWND hWnd){
  PostQuitMessage(0);
}

void MarkPoints(HWND hWnd, int x, int y)
{
    limit++;

    if(flag == 0){
        init_x = prev_x = x; //coordinates
        init_y = prev_y = y;
        flag = 1;
    }
    else if(flag==1){
        HDC hdc;
        hdc = GetDC(hWnd);
        HPEN hpen;
        HGDIOBJ holdpen;
        PAINTSTRUCT ps;                 //r   g    b
        hpen = CreatePen(PS_SOLID, 3, RGB(02, 50, 70));
        holdpen = SelectObject(hdc, hpen);
        MoveToEx(hdc, prev_x, prev_y, NULL);
        LineTo(hdc, x, y);
        prev_x = x;
        prev_y = y;
        if(limit == 5){
            MoveToEx(hdc, prev_x, prev_y, NULL);
            LineTo(hdc, init_x, init_y); flag=-1;
        }
         ReleaseDC(hWnd, hdc);
    }

}
