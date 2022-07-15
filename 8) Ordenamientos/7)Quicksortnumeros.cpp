#include <iostream>
#include <string.h>
#include <stdio.h>
#include <conio.h>
using namespace std;

void ordenar(int *v, int izq, int der);

int main(){
	int v[100], n=0;
	
	cout<<"Ingresa la cantidad de elementos que quiere cargar: ";
    cin>>n;
    
	//cargar los numeros
	cout<<endl<<"Ingrese los numeros que quiere ordenar "<<endl;
	for(int i=1;i<=n;i++){
		cout<<"Numero "<<i<<" : ";
		cin>>v[i];
	}
	system("cls");
	
	//funcion de ordenamiento
	ordenar(v, 0, n);
	
	//mostrar vector ordenado
	cout<<"Los numeros ordenados son: "<<endl;
	for(int j=0;j<n;j++){
		cout<<v[j]<<endl;
	}
	
	cout<<endl<<"Presione una tecla para volver al menu ";
	getch();
}

//funcion de ordenamiento
void ordenar(int *v, int izq, int der){
	int i=izq, j=der;
	int x=v[(izq+der)/2];
	do{
		while(v[i]<x && i<der)i++;
		while(x<v[j] && j>izq)j--;
		if(i<=j){
			int y=v[i];
			v[i]=v[j];
			v[j]=y;
			i++;
			j--;
		}
	}
	while(i<=j);
	if (izq<j)ordenar(v, izq, j);
	if (i<der)ordenar(v, i, der);
}
