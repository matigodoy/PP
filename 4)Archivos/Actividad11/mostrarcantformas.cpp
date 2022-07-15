#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;

struct registro{
	int num_vendedor;
	char nombre_vendedor[30];
	float importe_facturado;
	int forma_venta;
}reg;

int main(){
	int cantcontado=0, cantcredito=0;
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
            if(reg.forma_venta==1){
                cantcontado++;
            }
            if(reg.forma_venta==2){
                cantcredito++;
            }
            fread(&reg, sizeof (registro), 1, m);
        }
        fclose(m);
        cout<<"La cantidad de ventas a contado son: "<<cantcontado<<endl;
        cout<<"La cantidad de ventas a credito son: "<<cantcredito<<endl;
    }
}
