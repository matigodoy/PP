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
	int otro, i=1;
    FILE *m;
    m = fopen("clip.dat","ab");
    if (m == NULL){
        cout<<"Error al abrir el archivo ";
        cout<<"Presione una tecla... ";
        exit(1);
    }
    else{
        do{
        	cout<<"Clip publicitario numero "<<i++<<endl;
        	cout<<"Ingrese el codigo de identificacion del clip: ";
        	cin>>publi.codigo;
        	cout<<"Ingrese el titulo del clip: ";
        	fflush(stdin);
        	cin.getline(publi.titulo,50,'\n');
        	cout<<"Ingrese el monto invertido: $";
        	cin>>publi.monto;
        	do{
                cout<<"Ingrese el tipo de clip (numero entre 0 y 14): ";
                cin>>publi.tipo;
                if(publi.tipo<0 || publi.tipo>14)cout<<"Se un numero entre 0 y 14 "<<endl;
            }while(publi.tipo<0 || publi.tipo>14);
            fwrite(&publi,sizeof(empresa),1,m);
            cout<<endl;
            do{
                cout<<"Quiere cargar otro clip? (1. para si - 0. para no): ";
                cin>>otro;
                if(otro<0 || otro>1)cout<<"Se pide 1 o 0 "<<endl;
            }while(otro<0 || otro>1);
            cout<<endl;
        }while(otro!=0);
    }
    fclose(m);
    return 0;
}
