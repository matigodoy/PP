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
	int otro, i=1;
    FILE *m;
    m = fopen("asistencias.dat","ab");
    if (m == NULL){
        cout<<"Error al abrir el archivo ";
        exit(1);
    }
    else{
        do{
        	cout<<"Asistencia del alumno numero "<<i++<<endl;
        	cout<<"Ingrese el DNI del alumno: ";
        	cin>>alumnos.dni;
        	
        	cout<<"Ingrese el apellido del alumno: ";
        	fflush(stdin);
        	cin.getline(alumnos.apellido,30,'\n');
        	
        	cout<<"Ingrese el nombre del alumno: ";
        	fflush(stdin);
        	cin.getline(alumnos.nombre,30,'\n');
        	
        	do{
                cout<<"El alumno estaba presente o ausente? (1. para presente - 0. para ausente): ";
                cin>>alumnos.presente;
                if(alumnos.presente<0 || alumnos.presente>1)cout<<"Se pide 1 o 0 "<<endl;
            }while(alumnos.presente<0 || alumnos.presente>1);
        	
        	if(alumnos.presente==0){
        		cout<<"Ingrese la fecha del ausente del alumno: "<<endl;
        		do{
	        		cout<<"Dia: ";
		        	cin>>alumnos.dia;
		        	if(alumnos.dia<1 || alumnos.dia>31)cout<<"Los meses tienen como maximo 31 dias "<<endl;
            	}while(alumnos.dia<1 || alumnos.dia>31);
            	
            	do{
	        		cout<<"Mes: ";
	        		cin>>alumnos.mes;
		        	if(alumnos.mes<1 || alumnos.mes>12)cout<<"Los años tienen como maximo 12 meses "<<endl;
            	}while(alumnos.mes<1 || alumnos.mes>12);
	        	
	        	cout<<"Anio: ";
	        	cin>>alumnos.anio;
	        	
	        	do{
	                cout<<"Ingrese la causa por el ausente del alumno (1. enfermo - 2. se fue de viaje - 3. tareas extracurriculares - 4. sin aclarar): ";
	        		cin>>alumnos.causa;
	                if(alumnos.causa<1 || alumnos.causa>4)cout<<"Se pide un numero entre 1 o 4 "<<endl;
	            }while(alumnos.causa<1 || alumnos.causa>4);
			}
        	
            fwrite(&alumnos,sizeof(asistencias),1,m);
            cout<<endl;
            do{
                cout<<"Quiere cargar otro alumno? (1. para si - 0. para no): ";
                cin>>otro;
                if(otro<0 || otro>1)cout<<"Se pide 1 o 0 "<<endl;
            }while(otro<0 || otro>1);
            cout<<endl;
        }while(otro!=0);
    }
    fclose(m);
    return 0;
}
