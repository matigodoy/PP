#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
using namespace std;


struct hotel{
	long int dni;
	char nombre[30];
	float importe;
	int dias;
}huesped, vector[100], aux;

int main(){
	int dia, i=0, z=0;
	cout<<"Ingrese un valor para mostrar los huespedes que tienen registrada una cantidad mayor de dias al valor ingresado: ";
	cin>>dia;
	cout<<endl;
	FILE *m;
    m = fopen("huespedes.dat","rb");
    if (m== NULL){
        cout<<"Error al abrir el archivo ";
        exit(1);
    }
    else{
        fread(&huesped, sizeof (huesped), 1, m);
        while(feof(m)==0){
	        if(huesped.dias>dia){
	        	vector[i].dni=huesped.dni;
	        	for(int a=0; a<30; a++){
	        		vector[i].nombre[a]=huesped.nombre[a];
	        	}
	        	vector[i].importe=huesped.importe;
	        	vector[i].dias=huesped.dias;
	        	i++;
	        	z=1;
			}
			fread(&huesped, sizeof (hotel), 1, m);
        }
        fclose(m);
    }
    
    if(z==1){
	    cout<<"Los huespedes con una cantidad mayor de dias respecto al valor ingresado anteriormente, son: "<<endl;
	    for(int j=0; j<i; j++){
	    	cout<<"Nuemro de DNI: "<<vector[j].dni<<endl;
            cout<<"Nombre: "<<vector[j].nombre<<endl;
            cout<<"Importe pagado por la reserva de la habitacion: $"<<vector[j].importe<<endl;
            cout<<"Cantidad de dias que se queda en el hotel: "<<vector[j].dias<<endl;
	    	cout<<endl;
		}
		
		FILE *n;
		n = fopen("vector.dat","wb");
	    if (n== NULL){
	        cout<<"Error al abrir el archivo ";
	        exit(1);
	    }
	    else{
	    	for(int j=0; j<i; j++){
				vector[j].dni;
		    	vector[j].nombre;
		    	vector[j].importe;
		    	fwrite(&vector,sizeof(hotel),1,n);
			}
			fclose(n);
		}
		
		int otro;
		n = fopen("vector.dat","rb");
		if (n== NULL){
	        cout<<"Error al abrir el archivo ";
	        exit(1);
	    }
	    else{
	    	cout<<endl<<endl<<"Se guardaron los datos en un archivo "<<endl<<endl;
	    	do{
                cout<<"Quiere ver los datos del archivo? (1. para si - 0. para no): ";
                cin>>otro;
                if(otro<0 || otro>1)cout<<"Se pide 1 o 0 "<<endl;
            }while(otro<0 || otro>1);
            cout<<endl<<endl;
            if(otro==1){
            	cout<<"Los datos del archivo gusrdado: "<<endl;
		    	int j=0;
				fread(&vector, sizeof (hotel), 1, n);
				while(feof(n)==0){
			        cout<<"Nuemro de DNI: "<<vector[j].dni<<endl;
		            cout<<"Nombre: "<<vector[j].nombre<<endl;
		            cout<<"Importe pagado por la reserva de la habitacion: $"<<vector[j].importe<<endl;
		            j++;
		            cout<<endl;
		            fread(&vector, sizeof (hotel), 1, n);
		        }
		        fclose(n);
		    }
		    if(otro==0){
		    	return 0;
			}
		}
	}
	
	if(z==0){
		cout<<"No se encontraron huespedes con una cantidad de dias mayor al ingresado "<<endl;
		cout<<"Presione una tecla para volver al menu ";
		getch();
	}
}
	
	
