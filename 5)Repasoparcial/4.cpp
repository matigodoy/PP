#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<windows.h>
using namespace std;

struct empresa{
	long int codigo;
	int tipo;
	char titulo[50];
	float monto;
}publi;

struct vect{
	long int codig;
	int tip;
	char tit[50];
	float mont;
}v[100], arc;

int main(){
	int i=0;
	FILE *m;
    m = fopen("clip.dat","rb");
    if (m== NULL){
        cout<<"Error al abrir el archivo ";
        cout<<"Presione una tecla... ";
        exit(1);
    }
    else{
        fread(&publi, sizeof (empresa), 1, m);
        while(feof(m)==0){
	        if(publi.tipo!=5){
	        	v[i].codig=publi.codigo;
	        	for(int a=0; a<50; a++){
	        		v[i].tit[a]=publi.titulo[a];
	        	}
	        	v[i].mont=publi.monto;
	        	v[i].tip=publi.tipo;
	        	i++;
			}
			fread(&publi, sizeof (empresa), 1, m);
        }
        fclose(m);
    }
    
    for(int k=0;k<i;k++){
		for(int j=k+1;j<i;j++){
	    	if(v[k].codig>v[j].codig){ 
	            arc=v[k];
	            v[k]=v[j];
	            v[j]=arc;
	        }
	    }
	}
    
    cout<<"Los datos del arreglo generado con los clips cuyo tipo es diferente a 5, son: "<<endl;
    for(int j=0; j<i; j++){
    	cout<<"Codigo de identificacion: "<<v[j].codig<<endl;
    	cout<<"Titulo: "<<v[j].tit<<endl;
    	cout<<"Monto: $"<<v[j].mont<<endl;
    	cout<<"Tipo de clip: "<<v[j].tip<<endl;
    	cout<<endl;
	}
	
	short int mostrar;
	FILE *n;
	n = fopen("vector.dat","wb");
    if (n== NULL){
        cout<<"Error al abrir el archivo ";
        cout<<"Presione una tecla... ";
        exit(1);
    }
    else{
    	for(int j=0; j<i; j++){
    	v[j].codig;
    	v[j].tit;
    	v[j].mont;
    	v[j].tip;
    	fwrite(&v,sizeof(vect),1,n);
		}
		fclose(n);
		cout<<endl;
		cout<<"Se han gudardado todos los datos del vector anterior en un archivo "<<endl<<endl;
		do{
    	    cout<<"Quere ver los datos del archivo? (1. para si - 0. para no): ";
    	    cin>>mostrar;
    	    if(mostrar<0 || mostrar>1)cout<<"Se pide 1 o 0 "<<endl;
    	}while(mostrar<0 || mostrar>1);
	}
	
	if(mostrar==0){
		return 0;
	}
	
	if(mostrar==1){
		n = fopen("vector.dat","rb");
		if (n== NULL){
	        cout<<"Error al abrir el archivo ";
	        cout<<"Presione una tecla... ";
	        exit(1);
	    }
	    else{
	    	cout<<endl;
	    	int b=0;
			fread(&v, sizeof (vect), 1, n);
	        while(feof(n)==0){
	            cout<<"Codigo: "<<v[b].codig<<endl;
	    		cout<<"Titulo "<<v[b].tit<<endl;
	    		cout<<"Monto $"<<v[b].mont<<endl;
	    		cout<<"Tipo "<<v[b].tip<<endl;
	    		b++;
	            fread(&v, sizeof (vect), 1, n);
	            cout<<endl;
	        }
	        fclose(n);
	    }
	}
}
