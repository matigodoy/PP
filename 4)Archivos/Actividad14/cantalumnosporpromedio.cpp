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
	int i=1, canteximen=0, cantdic=0, cantmarzo=0;
    FILE *m;
    m = fopen("actividad14.dat","rb");
    if (m== NULL){
        cout<<"Error al abrir el archivo ";
        cout<<"Presione una tecla... ";
        exit(1);
    }
    else{
        fread(&reg, sizeof (registro), 1, m);
        while(feof(m)==0){
        	if(reg.promgral>=7)canteximen++;
        	if(reg.promgral>= 4 && reg.promgral< 7)cantdic++;
        	if(reg.promgral<4)cantmarzo++;
            fread(&reg, sizeof (registro), 1, m);
        }
        fclose(m);
        cout<<"La cantidad de alumnos que se eximen son: "<<canteximen<<endl;
        cout<<"La cantidad de alumnos que rinden en diciembre son: "<<cantdic<<endl;
        cout<<"La cantidad de alumnos que rinden en marzo son: "<<cantmarzo<<endl;
    }
}
