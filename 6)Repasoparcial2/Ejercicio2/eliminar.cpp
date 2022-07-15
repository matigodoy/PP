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
	int seguridad=0, continuar=0;
	long int codigoP=0;
	cout<<"Ingrese el codigo del vehiculo que deseas eliminar: ";
	cin>>codigoP;
	
	FILE *m;
	FILE *n;
    m = fopen("autos.dat","rb");
    n = fopen("temp.dat","wb");
    if (m== NULL || n== NULL){
        cout<<"Primero ingrese los datos de los vehiculos ";
        exit(1);
    }
    else{
    	fread(&autos, sizeof (empresa), 1, m);
    	while(feof(m)==0){
    		if(codigoP==autos.codigo){
    			cout<<endl<<endl<<"Los datos del vehiculo que se van a eliminar son: "<<endl;
	            cout<<"Codigo del vehiculo: "<<autos.codigo<<endl;
	            cout<<"Descripcion: "<<autos.descripcion<<endl;
	            cout<<"Precio: $"<<autos.precio<<endl;
	            cout<<"Tipo del vehiculo: "<<autos.tipo<<endl;
    			seguridad=1;
    			do{
	    			cout<<endl<<"Quiere continuar? (1. para si - 0. para no): ";
	                cin>>continuar;
	                if(continuar<0 || continuar>1)cout<<"Se pide 1 o 0 "<<endl;
	            }while(continuar<0 || continuar>1);
            
            	if(continuar==0){
            		fclose(m);
    				fclose(n);
    				remove("temp.dat");
            		return 0;
				}
			}
			if(continuar==1){
	    		if(codigoP!=autos.codigo){
	    			autos.codigo;
	    			autos.descripcion;
	    			autos.precio;
	    			autos.tipo;
	    			fwrite(&autos,sizeof(empresa),1,n);
				}
			}
			fread(&autos, sizeof (empresa), 1, m);
		}
    }
    fclose(m);
    fclose(n);
    if(continuar==1){
	    remove("autos.dat");
	    rename("temp.dat","autos.dat");
	}
    
    if(seguridad==0){
    	cout<<endl;
    	cout<<"El codigo ingresado no corresponde a ningun vehiculo "<<endl;
	}
}
