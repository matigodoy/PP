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
	int seguridad=0;
	int i=1;
    FILE *m;
    FILE *n;
    m = fopen("asistencias.dat","rb");
    n = fopen("ausentesjustificados.dat","wb");
    if (m== NULL || n==NULL){
        cout<<"Primero ingrese los alumnos ";
        exit(1);
    }
    else{
        fread(&alumnos, sizeof (asistencias), 1, m);
        while(feof(m)==0){
            if(alumnos.causa!=4 && alumnos.causa!=0){
            	alumnos.dni;
            	alumnos.nombre;
            	alumnos.apellido;
            	alumnos.dia;
            	alumnos.mes;
            	alumnos.anio;
            	alumnos.causa;
            	fwrite(&alumnos,sizeof(asistencias),1,n);
            	seguridad=1;
			}
            fread(&alumnos, sizeof (asistencias), 1, m);
        }
        fclose(m);
        fclose(n);
    }
    
    n = fopen("ausentesjustificados.dat","rb");
    if (n==NULL){
        cout<<"Error al abrir el archivo ";
        exit(1);
    }
    else{
        fread(&alumnos, sizeof (asistencias), 1, n);
        while(feof(n)==0){
	    	cout<<"Alumno numero "<<i++<<endl;
            cout<<"DNI: "<<alumnos.dni<<endl;
            cout<<"Apellido: "<<alumnos.apellido<<endl;
            cout<<"Nombre: "<<alumnos.nombre<<endl;
            if(alumnos.presente==1)cout<<"El alumno estaba presente "<<endl;
            if(alumnos.presente==0){
				cout<<"El alumno estaba ausente "<<endl;
	            cout<<"Fecha del ausente: "<<alumnos.dia<<" / "<<alumnos.mes<<" / "<<alumnos.anio<<endl;
	        }
	        if(alumnos.causa==1){
				cout<<"Causa del ausente: enfermo "<<endl;
			}
			if(alumnos.causa==2){
				cout<<"Causa del ausente: se fue de viaje "<<endl;
			}
			if(alumnos.causa==3){
				cout<<"Causa del ausente: tareas extracurriculares "<<endl;
			}
			cout<<endl;
	        fread(&alumnos, sizeof (asistencias), 1, n);
	    }
	}
    fclose(n);
    
    if(seguridad==0)cout<<"No hay alumnos con ausentes justificados "<<endl;
}
