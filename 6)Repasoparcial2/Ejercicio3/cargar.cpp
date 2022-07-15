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
    FILE *m;
    m = fopen("alumnos.dat","ab");
    if (m == NULL){
        cout<<"Primero ingrese el alumno ";
        exit(1);
    }
    else{
        cout<<"Ingrese los datos del alumno "<<endl;
        cout<<""<<endl;
        cout<<"Ingrese el numero de legajo: ";
    	cin>>alumno.legajo;
        cout<<"Ingrese el nombre de alumno: ";
        fflush(stdin);
        cin.getline(alumno.nombre,20,'\n');
        cout<<"Ingrese el importe pagado por arancel: $";
        cin>>alumno.importe;
        do{
        	cout<<"Ingrese el anio que esta cursando el alumno (numero entre 0 y 6): ";
            cin>>alumno.anio;
            if(alumno.anio<0 || alumno.anio>6)cout<<"Se pide un numero entre 0 y 6 "<<endl;
        }while(alumno.anio<0 || alumno.anio>6);
        fwrite(&alumno,sizeof(instituto),1,m);
    }
    fclose(m);
    return 0;
}
