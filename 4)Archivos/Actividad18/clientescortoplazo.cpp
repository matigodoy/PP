#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;

struct registro{
	long int Nro;
	char Nom[30];
	short int Tipo, Categ;
	float Monto, MontoActuali;
}reg;

int main(){
	float Montoact=0;
    FILE *m;
    m = fopen("Maestro.dat","rb");
    if (m== NULL){
        cout<<"Error al abrir el archivo ";
        cout<<"Presione una tecla... ";
        exit(1);
    }
    else{
        fread(&reg, sizeof (registro), 1, m);
        while(feof(m)==0){
        	if(reg.Tipo==1 && reg.Categ==1){
        		if(Montoact<reg.MontoActuali){
        			Montoact=reg.MontoActuali;
				}
			}
            fread(&reg, sizeof (registro), 1, m);
        }
        fclose(m);
    }
    
    m = fopen("Maestro.dat","rb");
    if (m== NULL){
        cout<<"Error al abrir el archivo ";
        cout<<"Presione una tecla... ";
        exit(1);
    }
    else{
    	fread(&reg, sizeof (registro), 1, m);
	    while(feof(m)==0){
        	if(reg.Tipo==1 && reg.Categ==1){
        		if(reg.MontoActuali==Montoact){
        			cout<<"Los datos del cliente con mayor monto actualizado en los depositos a corto plazo son: "<<endl;
        			cout<<"Numero de cliente: "<<reg.Nro<<endl;
        			cout<<"Nombre del cliente: "<<reg.Nom<<endl;
        			cout<<"El monto actualizado es: $"<<Montoact<<endl;
				}
			}
	        fread(&reg, sizeof (registro), 1, m);
	    }
	    fclose(m);
    }
}
