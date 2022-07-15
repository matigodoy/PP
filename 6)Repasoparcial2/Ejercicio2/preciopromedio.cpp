#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
using namespace std;


struct empresa{
	long int codigo;
	char descripcion[100];
	float precio;
	int tipo;
}autos, vector[100];

int main(){
	float precioProm=0;
	int cant=0;
	FILE *m;
    m = fopen("autos.dat","rb");
    if (m== NULL){
        cout<<"Error al abrir el archivo ";
        exit(1);
    }
    else{
    	fread(&autos, sizeof (empresa), 1, m);
        while(feof(m)==0){
	        precioProm=precioProm+autos.precio;
	        cant++;
			fread(&autos, sizeof (empresa), 1, m);
        }
        fclose(m);
    }
	precioProm/cant;
	
	int k=0;
    m = fopen("autos.dat","rb");
    if (m== NULL){
        cout<<"Error al abrir el archivo ";
        exit(1);
    }
    else{
    	fread(&autos, sizeof (empresa), 1, m);
        while(feof(m)==0){
        	if(autos.codigo>precioProm){
	            vector[k].codigo=autos.codigo;
	            for(int a=0; a<100; a++){
	            	vector[k].descripcion[a]=autos.descripcion[a];
				}
				vector[k].precio=autos.precio;
	            vector[k].tipo=autos.tipo;
	            k++;
	        }
            fread(&autos, sizeof (empresa), 1, m);
        }
        fclose(m);
    }
    
    cout<<"Los vehiculos que tienen un valor mayor al precio promedio, son: "<<endl<<endl;
    int i=1;
    for(int j=0; j<k; j++){
    	cout<<"Vehiculo numero "<<i++<<endl;
        cout<<"Codigo del vehiculo: "<<vector[j].codigo<<endl;
        cout<<"Descripcion: "<<vector[j].descripcion<<endl;
        cout<<"Precio: $"<<vector[j].precio<<endl;
        cout<<"Tipo del vehiculo: "<<vector[j].tipo<<endl;
    	cout<<endl;
	}
	
	int otro;
	do{
        cout<<"Quiere guardar los datos de los vehiculos que tienen un valor mayor al precio promedio? (1. para si - 0. para no): ";
        cin>>otro;
        if(otro<0 || otro>1)cout<<"Se pide 1 o 0 "<<endl;
    }while(otro<0 || otro>1);
	if(otro==1){
		FILE *n;
		n = fopen("vector.dat","wb");
	    if (n== NULL){
	        cout<<"Error al abrir el archivo ";
	        exit(1);
	    }
	    else{
	    	for(int j=0; j<k; j++){
			    vector[j].codigo;
			    vector[j].descripcion;
			    vector[j].precio;
			    fwrite(&vector,sizeof(empresa),1,n);
			}
			fclose(n);
		}
		
		n = fopen("vector.dat","rb");
		if (n== NULL){
	        cout<<"Error al abrir el archivo ";
	        exit(1);
	    }
	    else{
	    	cout<<"Los vehiculos que tienen un valor mayor al precio promedio, son: "<<endl<<endl;
	    	int j=0;
			fread(&vector, sizeof (empresa), 1, n);
			while(feof(n)==0){
	            cout<<"Vehiculo numero "<<i++<<endl;
		        cout<<"Codigo del vehiculo: "<<vector[j].codigo<<endl;
		        cout<<"Descripcion: "<<vector[j].descripcion<<endl;
		        cout<<"Precio: $"<<vector[j].precio<<endl;
	            fread(&vector, sizeof (empresa), 1, n);
	            j++;
	            cout<<endl;
	        }
	        fclose(n);
		}
	}
	if(otro==0){
		return 0;
	}
}
