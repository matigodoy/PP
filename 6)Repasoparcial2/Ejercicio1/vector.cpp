#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
using namespace std;


struct compania{
	long int dni;
	int provincia;
	char patente[20];
	float importe;
}aut, vector[100];

int main(){
	int i=0, z=0;
	float importeP;
	cout<<"Ingrese el valor del importe para buscar los clientes que abonaron un costo menor al ingresado: $";
	cin>>importeP;
	cout<<endl;
	FILE *m;
    m = fopen("auto.dat","rb");
    if (m== NULL){
        cout<<"Error al abrir el archivo ";
        cout<<"Presione una tecla... ";
        exit(1);
    }
    else{
        fread(&aut, sizeof (compania), 1, m);
        while(feof(m)==0){
	        if(aut.importe<importeP && aut.provincia!=0 && aut.provincia!=1){
	        	vector[i].dni=aut.dni;
	        	for(int a=0; a<20; a++){
	        		vector[i].patente[a]=aut.patente[a];
	        	}
	        	vector[i].importe=aut.importe;
	        	vector[i].provincia=aut.provincia;
	        	i++;
	        	z=1;
			}
			fread(&aut, sizeof (compania), 1, m);
        }
        fclose(m);
    }
    
    if(z==1){
	    cout<<"Los clientes con un importe menor al valor ingresado y que no van a las provincias 0 y 1. Son: "<<endl<<endl;
	    for(int j=0; j<i; j++){
	    	cout<<"Cliente "<<j+1<<endl;
	    	cout<<"Numero de DNI: "<<vector[j].dni<<endl;
	    	cout<<"Patente: "<<vector[j].patente<<endl;
	    	cout<<"Importe: $"<<vector[j].importe<<endl;
	    	cout<<"Numero de provincia: "<<vector[j].provincia<<endl;
	    	cout<<endl;
		}
		
		int y=0;
		FILE *n;
		n = fopen("vector.dat","wb");
	    if (n== NULL){
	        cout<<"Error al abrir el archivo ";
	        cout<<"Presione una tecla... ";
	        exit(1);
	    }
	    else{
	    	for(int j=0; j<i; j++){
	    		if(vector[j].provincia==8 || vector[j].provincia==10 || vector[j].provincia==13){
					vector[j].dni;
			    	vector[j].patente;
			    	vector[j].importe;
			    	vector[j].provincia;
			    	fwrite(&vector,sizeof(compania),1,n);
			    	y=1;
			    }
			}
			fclose(n);
		}
		
		if(y==1){
			n = fopen("vector.dat","rb");
			if (n== NULL){
		        cout<<"Primero ingrese los clientes ";
		        exit(1);
		    }
		    else{
		    	cout<<endl<<endl<<"Los clientes con un importe menor al valor ingresado anteriormente y que van a las provincias 8 - 10 - 13. Son: "<<endl<<endl;
		    	int j=0;
				fread(&vector, sizeof (compania), 1, n);
				while(feof(n)==0){
		            cout<<"Cliente "<<j+1<<endl;
		    		cout<<"Numero de DNI: "<<vector[j].dni<<endl;
		    		cout<<"Patente: "<<vector[j].patente<<endl;
		    		cout<<"Importe: $"<<vector[j].importe<<endl;
		    		cout<<"Numero de provincia: "<<vector[j].provincia<<endl;
		            fread(&vector, sizeof (compania), 1, n);
		            j++;
		            cout<<endl;
		        }
		        fclose(n);
			}
		}
		
		if(y==0){
			cout<<"No se encontraron clientes que vayan a las provincias 8 - 10 - 13 y que tengan que pagar una importe menor al ingresado anteriormente "<<endl;
			cout<<"Presione una tecla para volver al menu ";
			getch();
		}
	}
	
	if(z==0){
		cout<<"No se encontraron clientes con un importe menor al ingresado "<<endl;
		cout<<"Presione una tecla para volver al menu ";
		getch();
	}
}
	
	
