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
	int impcontado=0, impcredito=0;
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
                impcontado=impcontado+reg.importe_facturado;
            }
            if(reg.forma_venta==2){
                impcredito=impcredito+reg.importe_facturado;
            }
            fread(&reg, sizeof (registro), 1, m);
        }
        fclose(m);
        cout<<"El importe total del tipo de venta a contado es: $"<<impcontado<<endl;
        cout<<"El importe total del tipo de venta a credito es: $"<<impcredito<<endl;
    }
}
