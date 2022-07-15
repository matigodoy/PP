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
}alumnos, v[100], arc;

int main(){
	int z=0;
	int seguridad=0;
	int i=0;
    FILE *m;
    m = fopen("asistencias.dat","rb");
    if (m== NULL){
        cout<<"Primero ingrese los alumnos ";
        exit(1);
    }
    else{
        fread(&alumnos, sizeof (asistencias), 1, m);
        while(feof(m)==0){
            if(alumnos.causa==4){
            	v[i].dni=alumnos.dni;
            	for(int m=0; m<30; m++){
            		v[i].nombre[m]=alumnos.nombre[m];
            		v[i].apellido[m]=alumnos.apellido[m];
				}
            	v[i].dia=alumnos.dia;
            	v[i].mes=alumnos.mes;
            	v[i].anio=alumnos.anio;
            	v[i].causa=alumnos.causa;
            	i++;
            	seguridad=1;
            	z++;
			}
            fread(&alumnos, sizeof (asistencias), 1, m);
        }
        fclose(m);
    }
    
	for(int a=0; a<z; a++){
		for(int b=0; b<z; b++){
			if(v[a].dni<v[b].dni){ 
	            arc=v[a];
	            v[a]=v[b];
	            v[b]=arc;
	        }
		}
	}
	
	i=0;
    m = fopen("ausentesinjustificados.dat","wb");
    if (m== NULL){
        cout<<"Error al abrir el archivo ";
        exit(1);
    }
    else{
	    for(int a=0; a<z; a++){
	    	v[i].dni;
			v[i].nombre;
			v[i].apellido;
	    	v[i].dia;
	    	v[i].mes;
	    	v[i].anio;
	    	v[i].causa;
	    	i++;
	    	fwrite(&alumnos,sizeof(asistencias),1,m);
	    }
	}
	fclose(m);
    
    i=0;
    FILE *n;
    int be=1;
    n = fopen("ausentesinjustificados.dat","rb");
    if (n==NULL){
        cout<<"Error al abrir el archivo ";
        exit(1);
    }
    else{
        fread(&alumnos, sizeof (asistencias), 1, n);
        while(feof(n)==0){
	    	cout<<"Alumno numero "<<be++<<endl;
            cout<<"DNI: "<<v[i].dni<<endl;
            cout<<"Apellido: "<<v[i].apellido<<endl;
            cout<<"Nombre: "<<v[i].nombre<<endl;
            if(v[i].presente==1)cout<<"El alumno estaba presente "<<endl;
            if(v[i].presente==0){
				cout<<"El alumno estaba ausente "<<endl;
	            cout<<"Fecha del ausente: "<<v[i].dia<<" / "<<v[i].mes<<" / "<<v[i].anio<<endl;
	        }
	        i++;
	        cout<<endl;
	        fread(&alumnos, sizeof (asistencias), 1, n);
	    }
	}
    fclose(n);
    if(seguridad==0)cout<<"No hay alumnos con ausentes justificados "<<endl;
}
