#include <iostream>
#include <string.h>
#include <stdio.h>
#include <conio.h>
using namespace std;

int main(){
	char v[100][20], temp[20];
	int k=0, otro;
	
	//cargar palabras
	do{
		cout<<"Ingrese las palabras que quiere ordenar "<<endl;
		fflush(stdin);
		cin.getline(v[k],20,'\n');
		k++;
		do{
            cout<<"Quiere cargar otra palabra? (1. para si - 0. para no): ";
            cin>>otro;
            if(otro<0 || otro>1)cout<<"Se pide 1 o 0 "<<endl;
        }while(otro<0 || otro>1);
        cout<<endl;
	}while(otro!=0);
	
	//ordenamiento
	for(int i=0; i<k-1; i++){
		for(int j=i+1; j<k; j++){
			if(strcmp(v[i],v[j])>0){
				strcpy(temp,v[i]);
				strcpy(v[i],v[j]);
				strcpy(v[j],temp);
			}
		}
	}
	
	//mostrar vector ordenado
	cout<<"Las palabras ordenadas son: "<<endl;
	for(int j=0;j<k;j++){
		cout<<v[j]<<endl;
	}
	
	cout<<endl<<"Presione una tecla para volver al menu ";
	getch();
}
