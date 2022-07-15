#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;

struct registro{
	long int codigo, preciocont, preciofinan;
	char marca[30], color[20];
	int modelo;
}reg;

int main(){
	int i=1;
    FILE *m;
    m = fopen("autos.dat","rb");
    if (m== NULL){
        cout<<"Error al abrir el archivo ";
        cout<<"Presione una tecla... ";
        exit(1);
    }
    else{
        fread(&reg, sizeof (registro), 1, m);
        while(feof(m)==0){
        	if((reg.preciofinan-reg.preciocont)<2000){
	            cout<<"Auto numero "<<i++<<endl;
	            cout<<"Codigo: "<<reg.codigo<<endl;
	            cout<<"Marca: "<<reg.marca<<endl;
	            cout<<"Color: "<<reg.color<<endl;
	            cout<<"Modelo: "<<reg.modelo<<endl;
	            cout<<"Precio de contado: $"<<reg.preciocont<<endl;
	            cout<<"Precio financiado: $"<<reg.preciofinan<<endl;
            	cout<<endl;
        	}
        	fread(&reg, sizeof (registro), 1, m);
        }
        fclose(m);
    }
}
