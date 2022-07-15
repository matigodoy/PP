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
        cout<<endl<<endl<<"\tCARGAR RECURSOS"<<endl<<endl;
        SetConsoleTextAttribute(hConsole, 7);
        cout<<"\t1. Cargar alumnos "<<endl;
        cout<<"\t2. Cargar profesores "<<endl;
        cout<<"\t3. Cargar aulas "<<endl;
        cout<<"\t4. Cargar libros "<<endl<<endl;
        cout<<"\t5. Volver "<<endl<<endl;
        cout<<"\tIngrese una opcion: ";
        cin>>menu;
        cout<<endl<<endl;
        switch(menu){
            case 1:
            	system("1.1)cargar_alumnos.exe");
                break;
            case 2:
				system("1.2)cargar_profesores.exe");
				break;
			case 3:
				system("1.3)cargar_aulas.exe");
				break;
            case 4:
            	system("1.4)cargar_libros.exe");
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
}
