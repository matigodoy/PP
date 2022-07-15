#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
using namespace std;

struct compania{
	long int dni;
	int provincia;
	char patente[20];
	float importe;
}aut;

int main(){
	long int xDNI;
	cout<<"Ingrese el numero de DNI del cliente que quiera buscar ";
	cin>>xDNI;
    FILE *m;
    m = fopen("auto.dat","rb");
    if (m== NULL){
        cout<<"Primero ingrese los clientes ";
        exit(1);
    }
    else{
        fread(&aut, sizeof (compania), 1, m);
        while(feof(m)==0){
        	if(xDNI==aut.dni){
        		cout<<endl;
	            cout<<"Los datos encontrados son: "<<endl<<endl;
	            cout<<"Nuemro de DNI: "<<aut.dni<<endl;
            	cout<<"Patente del auto asignado: "<<aut.patente<<endl;
            	cout<<"Importe pagado por el alquiler: $"<<aut.importe<<endl;
            	cout<<"Numero de provincia: "<<aut.provincia<<endl;
            	cout<<endl;
            	cout<<"Presione una tecla para volver al menu ";
				getch();
            	return 0;
			}
			fread(&aut, sizeof (compania), 1, m);
        }
        fclose(m);
        cout<<endl<<endl;
        cout<<"No se encontro un cliente con el numero de DNI ingresado "<<endl;
        cout<<"Presione una tecla para volver al menu ";
		getch();
        return 0;
    }
}
