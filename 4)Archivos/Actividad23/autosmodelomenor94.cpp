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
	int cantidad=0;
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
        	if(reg.modelo<1994){
	            cantidad++;
        	}
            fread(&reg, sizeof (registro), 1, m);
        }
        fclose(m);
        cout<<"Hay "<<cantidad<<" autos con un modelo menor a 1994 "<<endl;
    }
    return 0;
}
