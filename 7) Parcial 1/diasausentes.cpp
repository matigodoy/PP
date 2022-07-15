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
	long int v[100], documento;
	int vector[100];
	int x=0, i=0;
	cout<<"Ingrese el numero para determinar el estudiante con los la cantidad de ausentes: ";
	cin>>x;
	int a=0;
    FILE *m;
    m = fopen("asistencias.dat","rb");
    if (m== NULL){
        cout<<"Primero ingrese los alumnos ";
        exit(1);
    }
    else{
        fread(&alumnos, sizeof (asistencias), 1, m);
        while(feof(m)==0){
        	v[i]=alumnos.dni;
        	i++;
            fread(&alumnos, sizeof (asistencias), 1, m);
        }
        fclose(m);
    }
    
    m = fopen("asistencias.dat","rb");
    if (m== NULL){
        cout<<"Primero ingrese los alumnos ";
        exit(1);
    }
    else{
        fread(&alumnos, sizeof (asistencias), 1, m);
        while(feof(m)==0){
        	documento=alumnos.dni;
            if(alumnos.presente==0){
            	for(int j=0; j<i; j++){
	            	if(v[j]=documento){
	            		vector[j]++;
					}
				}
				vector[a]++;
				a++;
			}
            fread(&alumnos, sizeof (asistencias), 1, m);
        }
        fclose(m);
    }
    
    int h=0;
    m = fopen("asistencias.dat","rb");
    if (m== NULL){
        cout<<"Primero ingrese los alumnos ";
        exit(1);
    }
    else{
    	fread(&alumnos, sizeof (asistencias), 1, m);
        while(feof(m)==0){
		    for(int g=0; g<i; g++){
		    	if(vector[g]==x){
		    		if(v[h]==alumnos.dni){
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
						h++;
					}
				}
			}
			fread(&alumnos, sizeof (asistencias), 1, m);
		}
	}
	fclose(m);
}
