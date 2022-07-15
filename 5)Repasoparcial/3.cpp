#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;

struct empresa{
	long int codigo;
	int tipo;
	char titulo[50];
	float monto;
}publi, v[100];

int main(){
	long int codig=0;
	int confirm=0;
	cout<<"Ingrese el codigo de identificacion del clip que quiera buscar ";
	cin>>codig;
	int i=1;
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
        	if(codig==publi.codigo){
        		cout<<endl;
	            cout<<"Los datos encontrados son: "<<endl<<endl;
	            cout<<"Codigo de identificacion: "<<publi.codigo<<endl;
	            cout<<"Titulo: "<<publi.titulo<<endl;
	            cout<<"Monto invertido: $"<<publi.monto<<endl;
	            cout<<"Tipo de clip: "<<publi.tipo<<endl;
            	return 0;
			}
			fread(&publi, sizeof (empresa), 1, m);
        }
        fclose(m);
        cout<<endl<<endl;
        cout<<"No se encontro el clip con el codigo de identificacion ingresado "<<endl;
        return 0;
    }
}
