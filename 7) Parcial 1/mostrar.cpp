#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
	int i=1;
    FILE *m;
    m = fopen("asistencias.dat","rb");
    if (m== NULL){
        cout<<"Primero ingrese los alumnos ";
        exit(1);
    }
    else{
        fread(&alumnos, sizeof (asistencias), 1, m);
        while(feof(m)==0){
            cout<<"Asistencia del alumno numero "<<i++<<endl;
            cout<<"DNI: "<<alumnos.dni<<endl;
            cout<<"Apellido: "<<alumnos.apellido<<endl;
            cout<<"Nombre: "<<alumnos.nombre<<endl;
            if(alumnos.presente==1)cout<<"El alumno estaba presente "<<endl;
            if(alumnos.presente==0){
				cout<<"El alumno estaba ausente "<<endl;
	            cout<<"Fecha del ausente: "<<alumnos.dia<<" / "<<alumnos.mes<<" / "<<alumnos.anio<<endl;
	            if(alumnos.causa==1){
					cout<<"Causa del ausente: enfermo "<<endl;
				}
				if(alumnos.causa==2){
					cout<<"Causa del ausente: se fue de viaje "<<endl;
				}
				if(alumnos.causa==3){
					cout<<"Causa del ausente: tareas extracurriculares "<<endl;
				}
				if(alumnos.causa==4){
					cout<<"Causa del ausente: sin aclarar "<<endl;
				}
	        }
            fread(&alumnos, sizeof (asistencias), 1, m);
            cout<<endl;
        }
        fclose(m);
    }
}
