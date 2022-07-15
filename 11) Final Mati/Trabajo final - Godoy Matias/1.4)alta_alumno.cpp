#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <windows.h>
using namespace std;
struct alumnos{
	char nombre[50], apellido[50];
	long int dni, legajo;
	short int reservado;
	int numero, reservado_hora, reservado_minutos, reservado_dia, reservado_mes, reservado_anio, reservado_numero;
}alum;
void escape();
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
int main(){
	int otro, i=1;
    FILE *m;
    FILE *n;
    long int codigoP;
    int salir=0;
	m = fopen("alumnos.dat","ab");
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
	cout<<endl<<endl<<"\tCARGAR ALUMNO "<<endl<<endl;
	SetConsoleTextAttribute(hConsole, 7);
	do{
    	n = fopen("alumnos.dat","rb");
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
			fread(&alum, sizeof (alumnos), 1, n);
    		while(feof(n)==0){
    			if(alum.dni==codigoP){
					SetConsoleTextAttribute(hConsole, 12);
					cout<<endl<<endl<<"\tEl DNI '"<<alum.dni<<"' ya existe."<<endl;
					SetConsoleTextAttribute(hConsole, 7);
					cout<<"\tPor favor, ingrese uno distinto"<<endl<<endl;
					salir=1;
				}
				fread(&alum, sizeof (alumnos), 1, n);
    		}
    		fclose(n);
		}
	}while(salir!=0);
    alum.dni=codigoP;
	cout<<"\tIngrese el NOMBRE: ";
	fflush(stdin);
	cin.getline(alum.nombre,50,'\n');
    cout<<"\tIngrese el APELLIDO: ";
	fflush(stdin);
	cin.getline(alum.apellido,50,'\n');
	cout<<"\tIngrese el LEGAJO: ";
	cin>>alum.legajo;
	cout<<endl;
	fwrite(&alum,sizeof(alumnos),1,m);
	fclose(m);
	system("Ordenamiento_alumnos");
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
