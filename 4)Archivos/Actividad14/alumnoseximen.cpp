#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;

struct registro{
	char nombre[30], materia[20];
	float prom1er, prom2do, prom3ro, promgral;
}reg;

int main(){
	int i=1;
    FILE *m;
    m = fopen("actividad14.dat","rb");
    if (m== NULL){
        cout<<"Error al abrir el archivo ";
        cout<<"Presione una tecla... ";
        exit(1);
    }
    else{
    	cout<<"Alumnos que se eximen "<<endl<<endl;
        fread(&reg, sizeof (registro), 1, m);
        while(feof(m)==0){
        	if(reg.promgral>=7){
            cout<<"Alumno numero "<<i++<<endl;
            cout<<"Nombre:"<<reg.nombre<<endl;
            cout<<"Promedio general en la materia "<<reg.materia<<" es: "<<reg.promgral<<endl;
            cout<<endl;
			}
            fread(&reg, sizeof (registro), 1, m);
        }
        fclose(m);
    }
}
