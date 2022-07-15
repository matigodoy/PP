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
	int otro, i=1;
    FILE *m;
    m = fopen("autos.dat","ab");
    if (m == NULL){
        cout<<"Error al abrir el archivo ";
        cout<<"Presione una tecla... ";
        exit(1);
    }
    else{
        do{
        	cout<<"Auto numero "<<i++<<endl;
        	
        	cout<<"Ingrese el codigo del auto: ";
        	cin>>reg.codigo;
        	
        	fflush(stdin);
            cout<<"Ingrese la marca del auto: ";
            cin.getline(reg.marca,30,'\n');
            
            fflush(stdin);
            cout<<"Ingrese el color del auto: ";
            cin.getline(reg.color,20,'\n');
            
            do{
            	fflush(stdin);
	            cout<<"Ingrese el modelo del auto: ";
	            cin>>reg.modelo;
	            if(reg.modelo>2030 || reg.modelo<1800)cout<<"Ingrese el año completo "<<endl;
	        }while(reg.modelo>2030 || reg.modelo<1800);
	        
	        fflush(stdin);
		    cout<<"Ingrese el precio de contado: $";
		    cin>>reg.preciocont;
		    
		    fflush(stdin);
		    cout<<"Ingrese el precio financiado: $";
		    cin>>reg.preciofinan;
		    
            fwrite(&reg,sizeof(registro),1,m);
            cout<<endl;
            do{
                cout<<"Quiere cargar otro auto? (1. para si - 0. para no): ";
                cin>>otro;
                if(otro<0 || otro>1)cout<<"Se pide 1 o 0 "<<endl;
            }while(otro<0 || otro>1);
            cout<<endl;
        }while(otro!=0);
    }
    fclose(m);
    return 0;
}
