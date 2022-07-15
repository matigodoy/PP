#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <windows.h>
using namespace std;
struct profesores{
	char nombre[50], apellido[50];
	long int dni;	
	short int reservado;
	int reservado_dni, reservado_hora, reservado_minutos, reservado_dia, reservado_mes, reservado_anio, reservado_numero;
}prof;
void escape();
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
int main(){
	int otro, i=1;
    FILE *m;
    FILE *n;
    long int codigoP;
    int salir=0;
	m = fopen("profesores.dat","ab");
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
	cout<<endl<<endl<<"\tCARGAR PROFESOR "<<endl<<endl;
	SetConsoleTextAttribute(hConsole, 7);  	
	do{
	    n = fopen("profesores.dat","rb");
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
			fread(&prof, sizeof (profesores), 1, n);
    		while(feof(n)==0){
    			if(prof.dni==codigoP){
					SetConsoleTextAttribute(hConsole, 12);
					cout<<endl<<endl<<"\tEl DNI '"<<prof.dni<<"' ya existe."<<endl;
					SetConsoleTextAttribute(hConsole, 7);
					cout<<"\tPor favor, ingrese uno distinto"<<endl<<endl;
					salir=1;
				}
				fread(&prof, sizeof (profesores), 1, n);
	    	}
    		fclose(n);
		}
	}while(salir!=0);
	prof.dni=codigoP;
	cout<<"\tIngrese el nombre: ";
	fflush(stdin);
	cin.getline(prof.nombre,50,'\n');
    cout<<"\tIngrese el apellido: ";
	fflush(stdin);
	cin.getline(prof.apellido,50,'\n');
	cout<<endl;
	fwrite(&prof,sizeof(profesores),1,m);
	fclose(m);
	system("14)Ordenamiento_profesores");
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
