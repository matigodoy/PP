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
    FILE *m;
    m = fopen("auto.dat","ab");
    if (m == NULL){
        cout<<"Primero ingrese los clientes ";
        exit(1);
    }
    else{
        cout<<"Ingrese los datos del cliente "<<endl;
        cout<<"Ingrese el numero de DNI: ";
    	cin>>aut.dni;
        cout<<"Ingrese la patente del auto asignado: ";
        fflush(stdin);
        cin.getline(aut.patente,20,'\n');
        cout<<"Ingrese el importe pagado por el alquiler: $";
        cin>>aut.importe;
        do{
        	cout<<"Ingrese hacia que provincia se dirije el cliente (numero entre 0 y 21): ";
            cin>>aut.provincia;
            if(aut.provincia<0 || aut.provincia>21)cout<<"Se pide un numero entre 0 y 21 "<<endl;
        }while(aut.provincia<0 || aut.provincia>21);
        fwrite(&aut,sizeof(compania),1,m);
    }
    fclose(m);
    return 0;
}
