#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <windows.h>
using namespace std;

void escape();
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

int main(){
	int menu;
    do{
    	system("cls");
    	cout<<endl<<endl;
    	SetConsoleTextAttribute(hConsole, 12);
    	cout<<"\tALTA DE RESERVA "<<endl<<endl;
        SetConsoleTextAttribute(hConsole, 7);
        cout<<"\t1. Alta reserva de libro "<<endl;
        cout<<"\t2. Alta reserva de aula  "<<endl<<endl;
        cout<<"\t3. Volver "<<endl<<endl;
        cout<<"\tIngrese una opcion: ";
        cin>>menu;
        cout<<endl<<endl;
        switch(menu){
            case 1:
            	system("1.2)reservar_libros.exe");
                break;
            case 2:
            	system("1.1)reservar_aulas.exe");
            	break;
            case 3:
            	return 0;
            default:
            	system("cls");
				SetConsoleTextAttribute(hConsole, 12);
				cout<<endl<<endl<<"\tIngrese una opcion valida "<<endl<<endl;
				SetConsoleTextAttribute(hConsole, 7);
				escape();
        }
    }while(menu!=3);
}
void escape(){
	int i=3;
	do{
		Sleep(200);
		cout<<"\tVolviendo al menu en "<<i<<" ..."<<endl;
		Sleep(1000);
		i--;
	}while(i!=0);
}
