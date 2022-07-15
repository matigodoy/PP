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
	int causa1=0, causa2=0, causa3=0, causa4=0;
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
            if(alumnos.causa==1)causa1++;
            if(alumnos.causa==2)causa2++;
            if(alumnos.causa==3)causa3++;
            if(alumnos.causa==4)causa4++;
            fread(&alumnos, sizeof (asistencias), 1, m);
        }
        fclose(m);
        if (causa1>causa2 && causa1>causa3 && causa1>causa4)cout<<"La causa con mayor cantidad de ausentes es: Enfermo "<<endl;
        if (causa2>causa1 && causa2>causa3 && causa2>causa4)cout<<"La causa con mayor cantidad de ausentes es: Se fue de viaje "<<endl;
        if (causa3>causa2 && causa3>causa1 && causa3>causa4)cout<<"La causa con mayor cantidad de ausentes es: Tareas extracurriculares "<<endl;
        if (causa4>causa2 && causa4>causa1 && causa4>causa3)cout<<"La causa con mayor cantidad de ausentes es: Sin aclarar "<<endl;
    }
}
