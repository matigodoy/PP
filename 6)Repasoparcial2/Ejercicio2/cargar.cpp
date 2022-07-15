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
	int otro, i=1, salir=0;
	long int codigoP;
    FILE *m;
    FILE *n;
    m = fopen("autos.dat","ab");
    if (m == NULL){
        cout<<"Error al abrir el archivo ";
        exit(1);
    }
    else{
        do{
        	m = fopen("autos.dat","ab");
		    if (m == NULL){
		        cout<<"Error al abrir el archivo ";
		        exit(1);
		    }
        	cout<<"Vehiculo numero "<<i++<<endl;
        	do{
			    n = fopen("autos.dat","rb");
			    if (n == NULL){
			        cout<<"Error al abrir el archivo ";
			        exit(1);
			    }
			    else{
		        	cout<<"Ingrese el codigo del vehiculo: ";
					cin>>codigoP;
					salir=0;
					fread(&autos, sizeof (empresa), 1, n);
	        		while(feof(n)==0){
	        			if(autos.codigo==codigoP){
	        				cout<<"El codigo ingresado ya pertenece a un vehiculo cargado "<<endl;
	        				salir=1;
						}
						fread(&autos, sizeof (empresa), 1, n);
	        		}
	        		fclose(n);
	        	}
			}while(salir!=0);
			autos.codigo=codigoP;
			cout<<"Ingrese una descripcion del mismo: ";
        	fflush(stdin);
        	cin.getline(autos.descripcion,100,'\n');
        	fflush(stdin);
        	cout<<"Ingrese el precio: $";
        	cin>>autos.precio;
        	do{
        		fflush(stdin);
                cout<<"Ingrese el tipo de vehiculo (numero entre 0 y 29): ";
                cin>>autos.tipo;
                if(autos.tipo<0 || autos.tipo>29)cout<<"Se pide un numero entre 0 y 29 "<<endl;
            }while(autos.tipo<0 || autos.tipo>29);
            fwrite(&autos,sizeof(empresa),1,m);
            cout<<endl;
            do{
                cout<<"Quiere cargar otro vehiculo? (1. para si - 0. para no): ";
                cin>>otro;
                if(otro<0 || otro>1)cout<<"Se pide 1 o 0 "<<endl;
            }while(otro<0 || otro>1);
            cout<<endl;
            fclose(m);
        }while(otro!=0);
    }
    fclose(m);
    return 0;
}
