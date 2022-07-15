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
        fread(&reg, sizeof (registro), 1, m);
        cout<<"Materia: "<<reg.materia<<endl<<endl;
        while(feof(m)==0){
            cout<<"Alumno numero "<<i++<<endl;
            cout<<"Nombre:"<<reg.nombre<<endl;
            cout<<"Promedio en el primer trimestre: "<<reg.prom1er<<endl;
            cout<<"Promedio en el segundo trimestre: "<<reg.prom2do<<endl;
            cout<<"Premedio en el tercer trimestre: "<<reg.prom3ro<<endl;
            fread(&reg, sizeof (registro), 1, m);
            cout<<endl;
        }
        fclose(m);
    }
}
