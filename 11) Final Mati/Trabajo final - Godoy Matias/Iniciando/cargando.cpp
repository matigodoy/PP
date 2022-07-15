#include<graphics.h>
#include<conio.h>
#include<dos.h>

main(){
	initwindow(900,490); // Abre una ventana gráfica
   int gd = DETECT, gm, x, y, color, angle = 0;
   struct arccoordstype a, b;
   settextstyle(GOTHIC_FONT, HORIZ_DIR, 3);//TIPO Y TAMAÑO DE LETRA
   outtextxy(350,230,"INICIANDO");                                        
   while(angle<=360)
   {
      setcolor(BLACK);
      arc(getmaxx()/2,getmaxy()/2,angle,angle+2,150);
      setcolor(WHITE);
      getarccoords(&a);
      circle(a.xstart,a.ystart,25);
      setcolor(BLACK);
      arc(getmaxx()/2,getmaxy()/2,angle,angle+2,200);
      getarccoords(&a);
      setcolor(RED);
      circle(a.xstart,a.ystart,25);
      angle = angle+5;
      delay(50);
   }
   closegraph();
   system("LogIn.exe");
	break;
}
