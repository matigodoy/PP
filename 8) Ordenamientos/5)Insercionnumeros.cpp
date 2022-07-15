#include <iostream>
#include <string.h>
#include <stdio.h>
#include <conio.h>
using namespace std;

int main(){
	int v[100], n=0, otro;
	
	//cargar los numeros
	do{
		cout<<"Ingrese los numeros que quiere ordenar "<<endl;
		cin>>v[n];
		n++;
		do{
            cout<<"Quiere cargar otro numero? (1. para si - 0. para no): ";
            cin>>otro;
            if(otro<0 || otro>1)cout<<"Se pide 1 o 0 "<<endl;
        }while(otro<0 || otro>1);
        cout<<endl;
	}while(otro!=0);
	
	//ordenamiento
	for(int j=1; j<n; j++){
		int y=v[j];
		int k;
		for(k=j-1; k>=0 && y<v[k]; k--){
			v[k+1]=v[k];
		}
		v[k+1]=y;
	}
	
	//mostrar vector ordenado
	cout<<"Los numeros ordenados son: "<<endl;
	for(int j=0;j<n;j++){
		cout<<v[j]<<endl;
	}
	
	cout<<endl<<"Presione una tecla para volver al menu ";
	getch();
}

