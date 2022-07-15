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
	int i=1;
    FILE *m;
    m = fopen("auto.dat","rb");
    if (m== NULL){
        cout<<"Primero ingrese los clientes ";
        exit(1);
    }
    else{
        fread(&aut, sizeof (compania), 1, m);
        while(feof(m)==0){
            cout<<"Cliente numero "<<i++<<endl;
            cout<<"Nuemro de DNI: "<<aut.dni<<endl;
            cout<<"Patente del auto asignado: "<<aut.patente<<endl;
            cout<<"Importe pagado por el alquiler: $"<<aut.importe<<endl;
            cout<<"Numero de provincia: "<<aut.provincia<<endl;
            fread(&aut, sizeof (compania), 1, m);
            cout<<endl;
        }
        fclose(m);
    }
    cout<<"Presione una tecla para volver al menu ";
	getch();
}
