#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <windows.h>
using namespace std;
void agregar();
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
int main(){
	system("00)Cargando.exe");
	int menu;
    do{
    	system("cls");
    	cout<<endl<<endl;
    	SetConsoleTextAttribute(hConsole, 12);
    	cout<<"\tMENU PERSONAL ADMINISTRATIVO "<<endl<<endl;
        SetConsoleTextAttribute(hConsole, 7);
        cout<<"\t1. Agregar recursos "<<endl;
        cout<<"\t2. Mostrar recursos "<<endl;
        cout<<"\t3. Modificar recursos "<<endl;
        cout<<"\t4. Eliminar recursos "<<endl<<endl;
        cout<<"\t5. Cerrar sesion "<<endl<<endl;
        cout<<"\tIngrese una opcion: ";
        cin>>menu;
        cout<<endl<<endl;
        switch(menu){
            case 1:
            	agregar();
				break;
			case 2:
            	system("6)mostrar.exe");
				break;
			case 3:
            	system("9)modificar.exe");
				break;
			case 4:
            	system("10)eliminar.exe");
				break;
            case 5:
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
    }while(menu!=5);
    return 0;
}
void agregar(){
	int menu;
    do{
    	system("cls");
    	SetConsoleTextAttribute(hConsole, 12);
        cout<<endl<<endl<<"\tAGREGAR RECURSOS"<<endl<<endl;
        SetConsoleTextAttribute(hConsole, 7);
        cout<<"\t1. Agregar aulas"<<endl;
        cout<<"\t2. Agregar libros "<<endl<<endl;
        cout<<"\t3. Volver "<<endl<<endl;
        cout<<"\tIngrese una opcion: ";
        cin>>menu;
        cout<<endl<<endl;
        switch(menu){
            case 1:
            	system("4)cargar_aulas.exe");
                break;
            case 2:
				system("5)cargar_libros.exe");
				break;
            case 3:
                return;
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
