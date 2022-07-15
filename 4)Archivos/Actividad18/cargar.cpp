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
	int otro, i=1;
    FILE *m;
    m = fopen("Maestro.dat","ab");
    if (m == NULL){
        cout<<"Error al abrir el archivo ";
        cout<<"Presione una tecla... ";
        exit(1);
    }
    else{
        do{
        	cout<<"Operacion numero "<<i++<<endl;
        	
        	cout<<"Ingrese el numero de cliente: ";
        	cin>>reg.Nro;
        	
        	fflush(stdin);
            cout<<"Ingrese el nombre del cliente: ";
            cin.getline(reg.Nom,30,'\n');
            
            do{
            	fflush(stdin);
	            cout<<"Ingrese el tipo de cuenta del cliente (1. para Deposito - 2. para Credito): ";
	            cin>>reg.Tipo;
	            if(reg.Tipo>2 || reg.Tipo<1)cout<<"Solamente se pueden ingrear los numeros 1 y 2 "<<endl;
	        }while(reg.Tipo>2 || reg.Tipo<1);
	        
	        if(reg.Tipo==1){
	            do{
	            	fflush(stdin);
	            	cout<<"Ingrese la categoria de la cuenta del cliente (1. Corto Plazo - 2. Mediano Plazo - 3. Largo Plazo): ";
	            	cin>>reg.Categ;
	            	if(reg.Categ>3 || reg.Categ<1)cout<<"Solamente se pueden ingrear los numeros 1 - 2 - 3 "<<endl;
		        }while(reg.Categ>3 || reg.Categ<1);
		    }
		    if(reg.Tipo==2){
	            do{
	            	fflush(stdin);
	            	cout<<"Ingrese la categoria de la cuenta del cliente (1. Industrial o Comercial - 2. Particular): ";
	            	cin>>reg.Categ;
	            	if(reg.Categ>2 || reg.Categ<1)cout<<"Solamente se pueden ingrear los numeros 1 y 2 "<<endl;
		        }while(reg.Categ>2 || reg.Categ<1);
		    }
		    
		    fflush(stdin);
		    cout<<"Ingrese el monto depositado: $";
		    cin>>reg.Monto;
		    
		    if(reg.Tipo==1 && reg.Categ==1) reg.MontoActuali=reg.Monto*1.30;
            if(reg.Tipo==1 && reg.Categ==2) reg.MontoActuali=reg.Monto*1.35;
            if(reg.Tipo==1 && reg.Categ==3) reg.MontoActuali=reg.Monto*1.40;
            if(reg.Tipo==2 && reg.Categ==1) reg.MontoActuali=reg.Monto*0.65;
            if(reg.Tipo==2 && reg.Categ==2) reg.MontoActuali=reg.Monto*0.75;
	        
            fwrite(&reg,sizeof(registro),1,m);
            cout<<endl;
            do{
                cout<<"Quiere cargar otra operacion? (1. para si - 0. para no): ";
                cin>>otro;
                if(otro<0 || otro>1)cout<<"Se pide 1 o 0 "<<endl;
            }while(otro<0 || otro>1);
            cout<<endl;
        }while(otro!=0);
    }
    fclose(m);
    return 0;
}
