/* Program to determine which mouse button is clicked */

#include<graphics.h>
#include<conio.h>
#include<dos.h>

union REGS i, o;

int initmouse()
{
   i.x.ax = 0;
   int86(0X33,&i,&o);
   return ( o.x.ax );
}

void showmouseptr()
{
   i.x.ax = 1;
   int86(0X33,&i,&o);
}

void getmousepos(int *button, int *x, int *y)
{
   i.x.ax = 3;
   int86(0X33,&i,&o);

   *button = o.x.bx;
   *x = o.x.cx;
   *y = o.x.dx;
}

main()
{
   int gd = DETECT, gm, status, button, x, y;
   char array[50];

   initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");
   settextstyle(DEFAULT_FONT,0,2);

   status = initmouse();

   if ( status == 0 )
      printf("Mouse support not available.\n");
   else
   {
      showmouseptr();

      getmousepos(&button,&x,&y);

      while(!kbhit())
      {
	 getmousepos(&button,&x,&y);

	 if( button == 1 )
	 {
	    button = -1;
	    cleardevice();
	    sprintf(array,"Left Button clicked x = %d y = %d",x,y);
	    outtext(array);
	 }
	 else if( button == 2 )
	 {
	    button = -1;
	    cleardevice();
	    sprintf(array,"Right Button clicked x = %d y = %d",x,y);
	    outtext(array);
	 }

      }
   }

   getch();
   return 0;
}