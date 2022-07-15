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
    m = fopen("huespedes.dat","rb");
    if (m== NULL){
        cout<<"Primero ingrese los huespedes ";
        exit(1);
    }
    else{
        fread(&huesped, sizeof (hotel), 1, m);
        while(feof(m)==0){
            cout<<"Huesped numero "<<i++<<endl;
            cout<<"Nuemro de DNI: "<<huesped.dni<<endl;
            cout<<"Nombre: "<<huesped.nombre<<endl;
            cout<<"Importe pagado por la reserva de la habitacion: $"<<huesped.importe<<endl;
            cout<<"Cantidad de dias que se queda en el hotel: "<<huesped.dias<<endl;
            fread(&huesped, sizeof (hotel), 1, m);
            cout<<endl;
        }
        fclose(m);
    }
    cout<<"Presione una tecla para volver al menu ";
	getch();
}
