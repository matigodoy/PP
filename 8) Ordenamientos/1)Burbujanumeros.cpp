#include <iostream>
#include <string.h>
#include <stdio.h>
#include <conio.h>
using namespace std;

int main(){
	int v[100], i=0, otro, aux;
	
	//cargar los numeros
	do{
		cout<<"Ingrese los numeros que quiere ordenar "<<endl;
		cin>>v[i];
		i++;
		do{
            cout<<"Quiere cargar otro numero? (1. para si - 0. para no): ";
            cin>>otro;
            if(otro<0 || otro>1)cout<<"Se pide 1 o 0 "<<endl;
        }while(otro<0 || otro>1);
        cout<<endl;
	}while(otro!=0);
	
	//ordenamiento
	for(int j=0;j<i;j++){
		for(int k=j+1;k<i;k++){
			if(v[j]>v[k]){	//si queres que ordene de mayor a menor hay que cambiar el signo del if
				aux=v[j];
				v[j]=v[k];
				v[k]=aux;
			}
		}
	}
	
	//mostrar vector ordenado
	cout<<"Los numeros ordenados son: "<<endl;
	for(int j=0;j<i;j++){
		cout<<v[j]<<endl;
	}
	
	cout<<endl<<"Presione una tecla para volver al menu ";
	getch();
}

