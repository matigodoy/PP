#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <windows.h>
using namespace std;
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
int main(){
	system("00)Cargando.exe");
	int menu;
    do{
    	system("cls");
    	cout<<endl<<endl;
    	SetConsoleTextAttribute(hConsole, 12);
    	cout<<"\tMENU ALUMNOS "<<endl<<endl;
        SetConsoleTextAttribute(hConsole, 7);
        cout<<"\t1. Reservar libro "<<endl;
        cout<<"\t2. Eliminar reserva libro "<<endl<<endl;
        cout<<"\t3. Cerrar sesion "<<endl<<endl;
        SetConsoleTextAttribute(hConsole, 7);
        cout<<"\tIngrese una opcion: ";
        cin>>menu;
        cout<<endl<<endl;
        switch(menu){
            case 1:
            	system("12)reservar_libros.exe");
				break;
			case 2:
            	system("12.1)eliminar_reserva_libros.exe");
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
    return 0;
}
