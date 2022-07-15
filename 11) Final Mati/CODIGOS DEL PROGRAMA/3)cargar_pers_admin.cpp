#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <windows.h>
using namespace std;
struct pers_admin{
	char nombre[50];
	char apellido[50];
	long int dni;
}admin;
void escape();
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
int main(){
	int otro, i=1;
    FILE *m;
    FILE *n;
    long int codigoP;
    int salir=0;
	m = fopen("pers_admin.dat","ab");
	if (m== NULL){
        system("cls");
        SetConsoleTextAttribute(hConsole, 12);
        cout<<endl<<endl<<"\tError al abrir el archivo "<<endl<<endl;
        SetConsoleTextAttribute(hConsole, 7);
        escape();
        return 0;
    }
	system("cls");
	SetConsoleTextAttribute(hConsole, 12);
	cout<<endl<<endl<<"\tCARGAR PERSONAL ADMINISTRATIVO "<<endl<<endl;
	SetConsoleTextAttribute(hConsole, 7);  	
	do{
	    n = fopen("pers_admin.dat","rb");
	    if (n == NULL){
	        system("cls");
	        SetConsoleTextAttribute(hConsole, 12);
	        cout<<endl<<endl<<"\tError al abrir el archivo "<<endl<<endl;
	        SetConsoleTextAttribute(hConsole, 7);
	        escape();
	        return 0;
	    }
	    else{
        	cout<<"\tIngrese el DNI: ";
        	cin>>codigoP;
			salir=0;
			fread(&admin, sizeof (pers_admin), 1, n);
    		while(feof(n)==0){
    			if(admin.dni==codigoP){
					SetConsoleTextAttribute(hConsole, 12);
					cout<<endl<<endl<<"\tEl DNI '"<<admin.dni<<"' ya existe."<<endl;
					SetConsoleTextAttribute(hConsole, 7);
					cout<<"\tPor favor, ingrese uno distinto"<<endl<<endl;
					salir=1;
				}
				fread(&admin, sizeof (pers_admin), 1, n);
	    	}
    		fclose(n);
		}
	}while(salir!=0);
	admin.dni=codigoP;
	cout<<"\tIngrese el nombre: ";
	fflush(stdin);
	cin.getline(admin.nombre,50,'\n');
    cout<<"\tIngrese el apellido: ";
	fflush(stdin);
	cin.getline(admin.apellido,50,'\n');
	cout<<endl;
	fwrite(&admin,sizeof(pers_admin),1,m);
	fclose(m);
	system("15)Ordenamiento_pers_admin");
    return 0;
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
