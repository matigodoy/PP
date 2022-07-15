#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
using namespace std;

struct empresa{
	long int codigo;
	char descripcion[100];
	float precio;
	int tipo;
}autos, arc, v[100];

int main(){
	int i=1;
    FILE *m;
    m = fopen("autos.dat","rb");
    if (m== NULL){
        cout<<"Primero ingrese los datos de los vehiculos ";
        exit(1);
    }
    else{
    	int k=0;
    	fread(&autos, sizeof (empresa), 1, m);
        while(feof(m)==0){
            v[k].codigo=autos.codigo;
            for(int a=0; a<100; a++){
            	v[k].descripcion[a]=autos.descripcion[a];
			}
			v[k].precio=autos.precio;
            v[k].tipo=autos.tipo;
            k++;
            fread(&autos, sizeof (empresa), 1, m);
        }
        fclose(m);
    	
        for(int i=0;i<k;i++){
    		for(int j=i+1;j<k;j++){
		    	if(v[i].codigo>v[j].codigo){ 
		            arc=v[i];
		            v[i]=v[j];
		            v[j]=arc;
		        }
		    }
		}
		
		FILE *m;
	    m = fopen("autos.dat","wb");
	    if (m == NULL){
	        cout<<"Error al abrir el archivo ";
	        exit(1);
	    }
	    else{
	    	for(int i=0;i<k;i++){
				autos.codigo=v[i].codigo;
				for(int a=0; a<100; a++){
		    		autos.descripcion[a]=v[i].descripcion[a];
		    	}
		    	autos.precio=v[i].precio;
		        autos.tipo=v[i].tipo;
		        fwrite(&autos,sizeof(empresa),1,m);
		    }
	    }
	    fclose(m);
    }
    fclose(m);
    int otro;
    cout<<"Se ordenaron los vehiculos a segun su codigo "<<endl;
    do{
        cout<<"Quiere ver los vehiculos ordenados? (1. para si - 0. para no): ";
        cin>>otro;
        if(otro<0 || otro>1)cout<<"Se pide 1 o 0 "<<endl;
    }while(otro<0 || otro>1);
    if(otro==0)return 0;
    
    if(otro==1){
    	system("mostrar.exe");
	}
}
