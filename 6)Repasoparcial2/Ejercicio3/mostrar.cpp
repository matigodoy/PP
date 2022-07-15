#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
using namespace std;

struct instituto{
	long int legajo;
	int anio;
	char nombre[20];
	float importe;
}alumno;

int main(){
	int i=1;
    FILE *m;
    m = fopen("alumnos.dat","rb");
    if (m== NULL){
        cout<<"Primero ingrese el dato alumno ";
        exit(1);
    }
    else{
        fread(&alumno, sizeof (instituto), 1, m);
        while(feof(m)==0){
            cout<<"Cliente numero "<<i++<<endl;
            cout<<"Numero de legajo: "<<alumno.legajo<<endl;
            cout<<"Nombre del alumno: "<<alumno.nombre<<endl;
            cout<<"Importe pagado por arancel: $"<<alumno.importe<<endl;
            cout<<"Anio cursando: "<<alumno.anio<<endl;
            fread(&alumno, sizeof (instituto), 1, m);
            cout<<endl;
        }
        fclose(m);
    }
    cout<<"Presione una tecla para volver al menu ";
	getch();
}
