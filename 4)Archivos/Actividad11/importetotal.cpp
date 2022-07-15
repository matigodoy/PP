#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;

struct registro{
	int importetotal=0;
	char nombre_vendedor[30];
	float importe_facturado;
	int forma_venta;
}reg;

int main(){
	int importetotal=0;
    FILE *m;
    m = fopen("actividad11.dat","rb");
    if (m== NULL){
        cout<<"Error al abrir el archivo ";
        cout<<"Presione una tecla... ";
        exit(1);
    }
    else{
        fread(&reg, sizeof (registro), 1, m);
        while(feof(m)==0){
           	importetotal=importetotal+reg.importe_facturado;
           	fread(&reg, sizeof (registro), 1, m);
        }
        fclose(m);
        cout<<"El importe total facturado es: $"<<importetotal<<endl;
    }
}
