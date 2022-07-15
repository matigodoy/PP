#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
using namespace std;

struct asistencias{
	long int dni;
	char apellido[30];
	char nombre[30];
	int dia;
	int mes;
	int anio;
	int causa;
	short int presente;
}alumnos;


int main(){
	short int b;
	char Bapellido[30];
	cout<<"Ingrese el apellido del alumno que quiera buscar ";
	fflush(stdin);
    cin.getline(Bapellido,30,'\n');
    FILE *m;
    m = fopen("asistencias.dat","rb");
    if (m== NULL){
        cout<<"Primero ingrese los alumnos ";
        exit(1);
    }
    else{
        fread(&alumnos, sizeof (asistencias), 1, m);
        while(feof(m)==0){
        	for(int a=0; a<30; a++){
        		b=0;
	        	if(Bapellido[a]==alumnos.apellido[a]){
	        		b=1;
				}
	        }
	        if(b==1){
	    		cout<<endl;
	            cout<<"Los datos encontrados son: "<<endl;
	            cout<<"DNI: "<<alumnos.dni<<endl;
	            cout<<"Apellido: "<<alumnos.apellido<<endl;
	            cout<<"Nombre: "<<alumnos.nombre<<endl;
	            if(alumnos.presente==1)cout<<"El alumno estaba presente "<<endl;
	            if(alumnos.presente==0){
					cout<<"El alumno estaba ausente "<<endl;
		            cout<<"Fecha del ausente: "<<alumnos.fecha<<endl;
		            cout<<"Causa del ausente: "<<alumnos.causa<<endl;
		        }
	        	cout<<endl;
	        	cout<<"Presione una tecla para volver al menu ";
				getch();
	        	return 0;
	        }
			fread(&alumnos, sizeof (asistencias), 1, m);
        }
        fclose(m);
        cout<<endl<<endl;
        cout<<"No se encontro un alumno con ese apellido "<<endl;
        cout<<"Presione una tecla para volver al menu ";
		getch();
        return 0;
    }
}
