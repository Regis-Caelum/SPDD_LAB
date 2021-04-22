#include<stdio.h>
#include<conio.h>
#include<dos.h>
//#include<i86.h>
void main(void)
{

 int x,y;
   union REGS regs;
  clrscr();

 printf(" Enter the starting line of the cursor(0-4) - ");
 scanf("%d",&x);
 printf("  Enter the ending line of the cursor - ");
 scanf("%d",&y);
 gotoxy(40,12);
 regs.h.ah = 1;
 regs.h.ch = x;
 regs.h.cl = y;
 int86(0x10,&regs,&regs);
 getch();
}
