#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <windows.h>
using namespace std;

void alta(), baja(), modificacion(), consulta(), escape();
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

int main(){
	int menu;
    do{
    	system("cls");
    	cout<<endl<<endl;
    	SetConsoleTextAttribute(hConsole, 12);
    	cout<<"\tALTA DE RECURSOS "<<endl<<endl;
        SetConsoleTextAttribute(hConsole, 7);
        cout<<"\t1. Alta de libro "<<endl;
        cout<<"\t2. Alta de aula "<<endl;
        cout<<"\t3. Alta de alumno "<<endl;
        cout<<"\t4. Alta de profesor "<<endl<<endl;
        cout<<"\t5. Volver "<<endl<<endl;
        cout<<"\tIngrese una opcion: ";
        cin>>menu;
        cout<<endl<<endl;
        switch(menu){
            case 1:
            	system("1.7)alta_libro.exe");
                break;
            case 2:
            	system("1.6)alta_aula.exe");
                break;
            case 3:
            	system("1.4)alta_alumno.exe");
                break;
            case 4:
                system("1.5)alta_profesor.exe");
                break;
            case 5:
                return 0;
                break;
            default:
            	system("cls");
				SetConsoleTextAttribute(hConsole, 12);
				cout<<endl<<endl<<"\tIngrese una opcion valida "<<endl<<endl;
				SetConsoleTextAttribute(hConsole, 7);
				escape();
        }
    }while(menu!=5);
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
