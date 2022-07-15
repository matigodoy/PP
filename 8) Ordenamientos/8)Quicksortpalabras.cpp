#include <stdio.h>
#include <string.h>
#include <iostream>
#include <conio.h>
using namespace std;

//declaracion de funcion ordenamiento
void quicksort(char v[100][20],int izquierda,int derecha);

int main(){
	char v[100][20];
	int n,i,izquierda,derecha;
	
	//carga los nombres
	cout<<"Introduce la cantidad de nombres que desea ordenar: ";
	cin>>n;
	for(i=0;i<n;i++){
		cout<<"Introduzca el nombre de la persona "<<i+1<<" : ";
		fflush(stdin);
		cin.getline(v[i],20,'\n');
	}
	izquierda=0;
	derecha=n-1;
	//funcion ordenamiento
	quicksort(v,izquierda,derecha);
	
	//muestra los nombres ordenados
	cout<<"Los nombres en orden alfabetico: "<<endl;
	for(i=0;i<n;i++)cout<<" Nombre "<<i+1<<" : "<<v[i]<<endl;
	return 0;
}
//funcion ordenamiento
void quicksort(char v[100][20],int izquierda,int derecha){
	int i,j;
	char y[20],*x;
	i=izquierda;
	j=derecha;
	x=v[(izquierda+derecha)/2];
	do{
		while((strcmp(v[i],x)<0) && (i<derecha)) i++;
		while((strcmp(v[j],x)>0) && (j>izquierda)) j--;
		if(i<=j){
			strcpy(y,v[i]);
			strcpy(v[i],v[j]);
			strcpy(v[j],y);
			i++;
			j--;
		}
	}while(i<=j);
	if(izquierda<j)quicksort(v,izquierda,j);
	if(i<derecha)quicksort(v,i,derecha);
}
