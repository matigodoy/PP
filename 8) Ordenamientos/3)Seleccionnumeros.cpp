#include <iostream>
#include <string.h>
#include <stdio.h>
#include <conio.h>
using namespace std;

int main(){
	int v[100], k=0, otro;
	
	//cargar los numeros
	do{
		cout<<"Ingrese los numeros que quiere ordenar "<<endl;
		cin>>v[k];
		k++;
		do{
            cout<<"Quiere cargar otro numero? (1. para si - 0. para no): ";
            cin>>otro;
            if(otro<0 || otro>1)cout<<"Se pide 1 o 0 "<<endl;
        }while(otro<0 || otro>1);
        cout<<endl;
	}while(otro!=0);
	
	//ordenamiento
	for(int i=0; i<k-1; i++){
		for(int j=i+1; j<k; j++){
			if(v[i]>v[j]){
				int aux=v[j];
				v[j]=v[i];
				v[i]=aux;
			}
		}
	}
	
	//mostrar vector ordenado
	cout<<"Los numeros ordenados son: "<<endl;
	for(int j=0;j<k;j++){
		cout<<v[j]<<endl;
	}
	
	cout<<endl<<"Presione una tecla para volver al menu ";
	getch();
}
