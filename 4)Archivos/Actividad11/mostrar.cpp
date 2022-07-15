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
	int i=1;
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
            cout<<"Venta numero "<<i++<<endl;
            cout<<"Vendedor numero: "<<reg.num_vendedor<<endl;
            cout<<"Nombre:"<<reg.nombre_vendedor<<endl;
            cout<<"Importe facturado: $"<<reg.importe_facturado<<endl;
            if (reg.forma_venta==1)cout<<"Forma de venta: contado "<<endl;
            if (reg.forma_venta==2)cout<<"Forma de venta: a credito "<<endl;
            fread(&reg, sizeof (registro), 1, m);
            cout<<endl;
        }
        fclose(m);
    }
}
