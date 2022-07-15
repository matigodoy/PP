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
	int i=1;
    FILE *m;
    m = fopen("autos.dat","rb");
    if (m== NULL){
        cout<<"Primero ingrese los datos de los vehiculos ";
        exit(1);
    }
    else{
        fread(&autos, sizeof (empresa), 1, m);
        while(feof(m)==0){
            cout<<"Vehiculo numero "<<i++<<endl;
            cout<<"Codigo del vehiculo: "<<autos.codigo<<endl;
            cout<<"Descripcion: "<<autos.descripcion<<endl;
            cout<<"Precio: $"<<autos.precio<<endl;
            cout<<"Tipo del vehiculo: "<<autos.tipo<<endl;
            fread(&autos, sizeof (empresa), 1, m);
            cout<<endl;
        }
        fclose(m);
    }
    cout<<"Presione una tecla para volver al menu ";
	getch();
}
