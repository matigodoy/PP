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
	int i=1;
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
            cout<<"Operacion numero "<<i++<<endl;
            
            cout<<"Numero de cliente: "<<reg.Nro<<endl;
            
            cout<<"Nombre del cliente: "<<reg.Nom<<endl;
            
            if(reg.Tipo==1)cout<<"Tipo de cuenta: Deposito "<<endl;
            if(reg.Tipo==2)cout<<"Tipo de cuenta: Credito "<<endl;
            
            if(reg.Tipo==1 && reg.Categ==1)cout<<"Categoria del cliente: Corto Plazo "<<endl;
            if(reg.Tipo==1 && reg.Categ==2)cout<<"Categoria del cliente: Mediano Plazo "<<endl;
            if(reg.Tipo==1 && reg.Categ==3)cout<<"Categoria del cliente: Largo Plazo "<<endl;
            if(reg.Tipo==2 && reg.Categ==1)cout<<"Categoria del cliente: Industrial o Comercial "<<endl;
            if(reg.Tipo==2 && reg.Categ==2)cout<<"Categoria del cliente: Particular "<<endl;
            
            cout<<"El monto depositado es: $"<<reg.Monto<<endl;
            
            cout<<"El monto actualizado es: $"<<reg.MontoActuali<<endl;
            
            fread(&reg, sizeof (registro), 1, m);
            cout<<endl;
        }
        fclose(m);
    }
}
