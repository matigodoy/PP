#include<iostream>
#include<stdlib.h>
#include<conio.h>
#include <conio.h>
using namespace std;

int main(){
	int v[100], n;
	cout<<"Ingresa la cantidad de elementos que quiere cargar: ";
	cin>>n;
	
	cout<<endl<<"Ingrese los numeros "<<endl;
	for(int i=1;i<=n;i++){
		cout<<"Numero "<<i<<" : ";
		cin>>v[i];
	}
	system("cls");
	int ksaltos=n/2;
	while(ksaltos>0){
		for(int i=ksaltos+1;i<=n;i++){
			int j=i-ksaltos;
			while(j>0){
				if(v[j]>v[j+ksaltos]){
					int aux=v[j];
					v[j]=v[j+ksaltos];
					v[j+ksaltos]=aux;
				}
				else{
					j=0;
				}
				j=j-ksaltos;
			}
		}
		ksaltos=ksaltos/2;
	}
	
	cout<<"Numeros ordenados:"<<endl;
    for(int i=1;i<=n;i++){
    	cout<<"Numero "<<i<<" : "<<v[i] << endl;
    }
    
    cout<<endl<<"Presione una tecla para volver al menu ";
	getch();
}


