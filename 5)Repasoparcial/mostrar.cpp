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
            cout<<"Clip publicitario numero "<<i++<<endl;
            cout<<"Codigo de identificacion: "<<publi.codigo<<endl;
            cout<<"Titulo: "<<publi.titulo<<endl;
            cout<<"Monto invertido: $"<<publi.monto<<endl;
            cout<<"Tipo de clip: "<<publi.tipo<<endl;
            fread(&publi, sizeof (empresa), 1, m);
            cout<<endl;
        }
        fclose(m);
    }
}
