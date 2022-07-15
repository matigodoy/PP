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
	int cantventas1=0, cantventas2=0, cantventas3=0;
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
                cantventas1++;
            }
            if(reg.num_vendedor==2){
                cantventas2++;
            }
            if(reg.num_vendedor==3){
                cantventas3++;
            }
            fread(&reg, sizeof (registro), 1, m);
        }
        fclose(m);
        if(cantventas1>cantventas2 && cantventas1>cantventas3)cout<<"El vendedor que mayores ventas hizo fue el vendedor 1 con "<<cantventas1<<" ventas "<<endl;
        if(cantventas2>cantventas1 && cantventas2>cantventas3)cout<<"El vendedor que mayores ventas hizo fue el vendedor 2 con "<<cantventas2<<" ventas "<<endl;
        if(cantventas3>cantventas2 && cantventas3>cantventas1)cout<<"El vendedor que mayores ventas hizo fue el vendedor 3 con "<<cantventas3<<" ventas "<<endl;
        if(cantventas1==cantventas2 && cantventas1>cantventas3)cout<<"Los vendedores que mayores ventas hicieron fueron los vendedores 1 y 2 con "<<cantventas1<<" ventas "<<endl;
        if(cantventas1==cantventas3 && cantventas1>cantventas2)cout<<"Los vendedores que mayores ventas hicieron fueron los vendedores 1 y 3 con "<<cantventas1<<" ventas "<<endl;
        if(cantventas3==cantventas2 && cantventas3>cantventas1)cout<<"Los vendedores que mayores ventas hicieron fueron los vendedores 2 y 3 con "<<cantventas3<<" ventas "<<endl;
        if(cantventas1==cantventas2 && cantventas1==cantventas3)cout<<"Los 3 vendedores hicieron "<<cantventas1<<" ventas "<<endl;
    }
}
