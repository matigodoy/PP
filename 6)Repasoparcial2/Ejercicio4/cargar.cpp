#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
using namespace std;

struct hotel{
	long int dni;
	char nombre[30];
	float importe;
	int dias;
}huesped;

int main(){
	int i=1;
    FILE *m;
    m = fopen("huespedes.dat","ab");
    if (m == NULL){
        cout<<"Error al abrir el archivo ";
        exit(1);
    }
    else{
        cout<<"Ingrese los datos del huesped "<<i++<<endl;
        cout<<"Ingrese el numero de DNI: ";
    	cin>>huesped.dni;
        cout<<"Ingrese el nombre del huesped: ";
        fflush(stdin);
        cin.getline(huesped.nombre,30,'\n');
        cout<<"Ingrese el importe pagado por la reserva de la habitacion: $";
        cin>>huesped.importe;
        cout<<"Ingrese la cantidad de dias que se quedara en el hotel: ";
        cin>>huesped.dias;
        fwrite(&huesped,sizeof(hotel),1,m);
    }
    fclose(m);
    return 0;
}
