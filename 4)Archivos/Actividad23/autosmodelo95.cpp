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

struct model95{
	long int codig;
	char marc[30];
	long int preci;
}mod;

int main(){
	int a=0;
    FILE *m;
    FILE *n;
    m = fopen("autos.dat","rb");
    n = fopen("autos95.dat","wb");
    if (m== NULL || n==NULL){
        cout<<"Error al abrir el archivo ";
        cout<<"Presione una tecla... ";
        exit(1);
    }
    else{
        fread(&reg, sizeof (registro), 1, m);
        while(feof(m)==0){
        	if(reg.modelo==1995){
	            mod.codig=reg.codigo;
	            for(int i=0; i<30; i++){
	            	mod.marc[i]=reg.marca[i];
	            }
	            mod.preci=reg.preciocont;
	            fwrite(&mod,sizeof(model95),1,n);
	            a=1;
	        }
        	fread(&reg, sizeof (registro), 1, m);
        }
        fclose(m);
        fclose(n);
    }
    
    n = fopen("autos95.dat","rb");
    if (n==NULL){
        cout<<"Error al abrir el archivo ";
        cout<<"Presione una tecla... ";
        exit(1);
    }
    else{
    	int i=1;
    	fread(&mod, sizeof (model95), 1, n);
    	while(feof(n)==0){
    		cout<<"Auto numero "<<i++<<endl;
            cout<<"Codigo: "<<mod.codig<<endl;
            cout<<"Marca: "<<mod.marc<<endl;
            cout<<"Precio de contado: $"<<mod.preci<<endl;
            fread(&mod, sizeof (model95), 1, n);
        }
        fclose(n);
    }
    if(a==0)cout<<"No se encontraron autos con modelo igual a 1995 "<<endl;
}
