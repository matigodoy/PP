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
}autos;

int main(){
	int seguridad=0, i=1;
	long int codigoP=0;
	cout<<"Ingrese el codigo del vehiculo que deseas buscar: ";
	cin>>codigoP;
	
	FILE *m;
	FILE *n;
    m = fopen("autos.dat","rb");
    if (m== NULL){
        cout<<"Primero ingrese los datos de los vehiculos ";
        exit(1);
    }
    else{
    	fread(&autos, sizeof (empresa), 1, m);
    	while(feof(m)==0){
    		if(codigoP==autos.codigo){
    			cout<<endl<<"Los datos encontrados son: "<<endl;
	            cout<<"Codigo del vehiculo: "<<autos.codigo<<endl;
	            cout<<"Descripcion: "<<autos.descripcion<<endl;
	            cout<<"Precio: $"<<autos.precio<<endl;
	            cout<<"Tipo del vehiculo: "<<autos.tipo<<endl;
    			seguridad=1;
			}
			fread(&autos, sizeof (empresa), 1, m);
		}
    }
    fclose(m);
    
    if(seguridad==0){
    	cout<<endl;
    	cout<<"El codigo ingresado no corresponde a ningun vehiculo "<<endl;
	}
}
