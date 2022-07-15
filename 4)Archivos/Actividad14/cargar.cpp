#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;

struct registro{
	char nombre[30], materia[20];
	float prom1er, prom2do, prom3ro, promgral;
}reg;

int main(){
	int otro, i=1;
    FILE *m;
    m = fopen("actividad14.dat","ab");
    if (m == NULL){
        cout<<"Error al abrir el archivo ";
        cout<<"Presione una tecla... ";
        exit(1);
    }
    else{
    	cout<<"Ingrese el nombre de la materia a cargar "<<endl;
    	fflush(stdin);
    	cin.getline(reg.materia,20,'\n');
        do{
        	cout<<"Alumno numero "<<i++<<endl;
        	fflush(stdin);
            cout<<"Ingrese el nombre del alumno: ";
            cin.getline(reg.nombre,30,'\n');
            do{
	            cout<<"Ingrese el promedio del primer trimestre de la materia "<<reg.materia<<" : ";
	            cin>>reg.prom1er;
	            if(reg.prom1er>10 || reg.prom1er<1)cout<<"Solamente se pueden ingrear numeros entre 1 y 10 "<<endl;
	        }while(reg.prom1er>10 || reg.prom1er<1);
            do{
            	cout<<"Ingrese el promedio del segundo trimestre de la materia "<<reg.materia<<" : ";
            	cin>>reg.prom2do;
            	if(reg.prom2do>10 || reg.prom2do<1)cout<<"Solamente se pueden ingrear numeros entre 1 y 10 "<<endl;
	        }while(reg.prom2do>10 || reg.prom2do<1);
            do{
            	cout<<"Ingrese el promedio del tercer trimestre de la materia "<<reg.materia<<" : ";
           		cin>>reg.prom3ro;
            	if(reg.prom3ro>10 || reg.prom3ro<1)cout<<"Solamente se pueden ingrear numeros entre 1 y 10 "<<endl;
	        }while(reg.prom3ro>10 || reg.prom3ro<1);
	        
	        reg.promgral=(reg.prom1er+reg.prom2do+reg.prom3ro)/3;
	        
            fwrite(&reg,sizeof(registro),1,m);
            cout<<endl;
            do{
                cout<<"Quiere cargar otro alumno? (1. para si - 0. para no): ";
                cin>>otro;
                if(otro<0 || otro>1)cout<<"Se pide 1 o 0 "<<endl;
            }while(otro<0 || otro>1);
            cout<<endl;
        }while(otro!=0);
    }
    fclose(m);
    return 0;
}
