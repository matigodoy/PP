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
	int cantimporte1=0, cantimporte2=0, cantimporte3=0;
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
            if(reg.num_vendedor==1){
                cantimporte1=cantimporte1+reg.importe_facturado;
            }
            if(reg.num_vendedor==2){
                cantimporte2=cantimporte2+reg.importe_facturado;
            }
            if(reg.num_vendedor==3){
                cantimporte3=cantimporte3+reg.importe_facturado;
            }
            fread(&reg, sizeof (registro), 1, m);
        }
        fclose(m);
        if(cantimporte1>cantimporte2 && cantimporte1>cantimporte3)cout<<"El vendedor que mayor importe en ventas hizo fue el vendedor 1 con $"<<cantimporte1<<endl;
        if(cantimporte2>cantimporte1 && cantimporte2>cantimporte3)cout<<"El vendedor que mayor importe en ventas hizo fue el vendedor 2 con $"<<cantimporte2<<endl;
        if(cantimporte3>cantimporte2 && cantimporte3>cantimporte1)cout<<"El vendedor que mayor importe en ventas hizo fue el vendedor 3 con $"<<cantimporte3<<endl;
        if(cantimporte1==cantimporte2 && cantimporte1>cantimporte3)cout<<"Los vendedores que mayor importe hicieron en ventas fueron los vendedores 1 y 2 con $"<<cantimporte1<<endl;
        if(cantimporte1==cantimporte3 && cantimporte1>cantimporte2)cout<<"Los vendedores que mayor importe hicieron en ventas fueron los vendedores 1 y 3 con $"<<cantimporte1<<endl;
        if(cantimporte3==cantimporte2 && cantimporte3>cantimporte1)cout<<"Los vendedores que mayor importe hicieron en ventas fueron los vendedores 2 y 3 con $"<<cantimporte3<<endl;
        if(cantimporte1==cantimporte2 && cantimporte1==cantimporte3)cout<<"Los 3 vendedores hicieron un importe total a $"<<cantimporte1<<endl;
    }
}
