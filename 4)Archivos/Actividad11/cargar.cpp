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
	int otro, i=1;
    FILE *m;
    m = fopen("actividad11.dat","ab");
    if (m == NULL){
        cout<<"Error al abrir el archivo ";
        cout<<"Presione una tecla... ";
        exit(1);
    }
    else{
        do{
        	cout<<"Venta numero "<<i++<<endl;
        	do{
                cout<<"Ingrese el numero del vendedor (1 - 2 - 3): ";
                cin>>reg.num_vendedor;
                if(reg.num_vendedor<1 || reg.num_vendedor>3)cout<<"Se pide 1 - 2 - 3 "<<endl;
            }while(reg.num_vendedor<1 || reg.num_vendedor>3);
            
            cout<<"Ingrese el nombre del vendedor: ";
            cin>>reg.nombre_vendedor;
            
            cout<<"Ingrese el importe facturado por esa venta: $";
            cin>>reg.importe_facturado;
            
            do{
                cout<<"Ingrese la forma de venta (1 para contado - 2 para credito): ";
                cin>>reg.forma_venta;
                if(reg.forma_venta<1 || reg.forma_venta>2)cout<<"Se pide 1 o 2 "<<endl;
            }while(reg.forma_venta<1 || reg.forma_venta>2);
            
            fwrite(&reg,sizeof(registro),1,m);
            cout<<endl;
            do{
                cout<<"Quiere cargar otro empleado? (1. para si - 0. para no): ";
                cin>>otro;
                if(otro<0 || otro>1)cout<<"Se pide 1 o 0 "<<endl;
            }while(otro<0 || otro>1);
            cout<<endl;
        }while(otro!=0);
    }
    fclose(m);
    return 0;
}
