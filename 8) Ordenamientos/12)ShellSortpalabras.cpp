#include<iostream>
#include<stdlib.h>
#include<conio.h>
#include <conio.h>
using namespace std;

int main(){
	string v[100];
	int n;
	cout<<"Ingresa la cantidad de palabras que quiere cargar: ";
	cin>>n;
	cout<<endl<<"Ingrese las palabras "<<endl;
	for(int i=1;i<=n;i++){
		cout<<"Palabra "<<i<<" : ";
		cin>>v[i];
	}
	system("cls");
	int ksaltos=n/2;
	while(ksaltos>0){
		for(int i=ksaltos+1;i<=n;i++){
			int j=i-ksaltos;
			while(j>0){
				if(v[j]>v[j+ksaltos]){
					string aux=v[j];
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
	cout<<"Las palabras ordenadas son:"<<endl;
    for(int i=1;i<=n;i++){
    	cout<<"Palabra "<<i<<" : "<<v[i] << endl;
    }
    cout<<endl<<"Presione una tecla para volver al menu ";
	getch();
}


