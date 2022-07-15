#include <conio.h>
#include <graphics.h>
int main(){
	int contador=0;
	initwindow(1300,700);
	do{
		settextstyle(DEFAULT_FONT, HORIZ_DIR, 4);
		outtextxy(330,100,"PROGRAMA DE RESERVA");
		setcolor(rand() % 15);
		line(rand() % 1300,rand() % 700,rand() % 1300,rand() % 700);
		setcolor(rand() % 15);
		rectangle(rand() % 1300,rand() % 700,rand() % 1300,rand() % 700);
		setcolor(rand() % 15);
		ellipse(rand() % 1300,rand() % 700,0,360,rand() % 100,rand() % 100);
		settextstyle(DEFAULT_FONT, HORIZ_DIR, 3);
		outtextxy(220,600,"Presione una tecla para continuar...");
		contador+=4;
		if(contador%100==0)cleardevice();
		delay(100);
	}while(!kbhit());
	closegraph();
}
