#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
using namespace std;


struct instituto{
	long int legajo;
	int anio;
	char nombre[20];
	float importe;
}alumno, vector[100];

int main(){
	int i=0, z=0;
	FILE *m;
    m = fopen("alumnos.dat","rb");
    if (m== NULL){
        cout<<"Error al abrir el archivo ";
        cout<<"Presione una tecla... ";
        exit(1);
    }
    else{
        fread(&alumno, sizeof (instituto), 1, m);
        while(feof(m)==0){
	        vector[i].legajo=alumno.legajo;
	        	for(int a=0; a<20; a++){
	        		vector[i].nombre[a]=alumno.nombre[a];
	        	}
	        	vector[i].importe=alumno.importe;
	        	vector[i].anio=alumno.anio;
	        	i++;
			fread(&alumno, sizeof (instituto), 1, m);
        }
        fclose(m);
    }
    
		int y=0;
		FILE *n;
		n = fopen("vector.dat","wb");
	    if (n== NULL){
	        cout<<"Error al abrir el archivo ";
	        cout<<"Presione una tecla... ";
	        exit(1);
	    }
	    else{
	    	for(int j=0; j<i; j++){
	    		if(vector[j].anio==5 || vector[j].anio==6){
					vector[j].legajo;
			    	vector[j].nombre;
			    	vector[j].importe;
			    	vector[j].anio;
			    	fwrite(&vector,sizeof(instituto),1,n);
			    	y=1;
			    }
			}
			fclose(n);
		}
		
		if(y==1){
			n = fopen("vector.dat","rb");
			if (n== NULL){
		        cout<<"Primero ingrese los alumnos ";
		        exit(1);
	    }else{
	    	cout<<endl<<endl<<"Los alumnos que estan cursando quinto y sexto anio son: "<<endl<<endl;
	    	int j=0;
			fread(&vector, sizeof (instituto), 1, n);
			while(feof(n)==0){
	            cout<<"Alumno "<<j+1<<endl;
	    		cout<<"Numero de legajo: "<<vector[j].legajo<<endl;
	    		cout<<"Nombre del alumno: "<<vector[j].nombre<<endl;
	    		cout<<"Importe por arancel: $"<<vector[j].importe<<endl;
	    		cout<<"Anio cursando: "<<vector[j].anio<<endl;
	            fread(&vector, sizeof (instituto), 1, n);
	            j++;
	            cout<<endl;
	        }
	       fclose(n);
		}
	}
		
	if(y==0){
		cout<<"No se encontraron alumnos que esten cursando quinto y sexto anio "<<endl;
		cout<<"Presione una tecla para volver al menu ";
		getch();
	}
}
	
	
