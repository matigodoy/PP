#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <windows.h>
using namespace std;
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
int main(){
	int menu;
    do{
    	system("cls");
    	SetConsoleTextAttribute(hConsole, 12);
        cout<<endl<<endl<<"\tELIMNAR LA RESERVA DE RECURSOS"<<endl<<endl;
        SetConsoleTextAttribute(hConsole, 7);
        cout<<"\t1. Eliminar reserva de aulas "<<endl;
        cout<<"\t2. Eliminar reserva de libros "<<endl<<endl;
        cout<<"\t3 Volver "<<endl<<endl;
        cout<<"\tIngrese una opcion: ";
        cin>>menu;
        cout<<endl<<endl;
        switch(menu){
			case 1:
				system("5.1)eliminar_reserva_aulas.exe");
				break;
            case 2:
            	system("5.2)eliminar_reserva_libros.exe");
				break;
            case 3:
                return 0;
            default:
            	system("cls");
				SetConsoleTextAttribute(hConsole, 12);
				cout<<endl<<endl<<"\tIngrese una opcion valida "<<endl<<endl;
				SetConsoleTextAttribute(hConsole, 7);
				int i=3;
				do{
					Sleep(200);
					cout<<"\tVolviendo al menu en "<<i<<" ..."<<endl;
					Sleep(1000);
					i--;
				}while(i!=0);
        }
    }while(menu!=3);
}
