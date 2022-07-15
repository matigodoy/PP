#include<iostream>
#include<conio.h>
#include<stdlib.h>
#include <conio.h>
using namespace std;
  
int main(){
    int v[100],j,item,temp,i,k,n;
	cout<<"Ingresa la cantidad de elementos que quiere cargar: ";
    cin>>n;
    
    cout<<endl<<"Ingrese los numeros "<<endl;
	for(i=1;i<=n;i++){
		cout<<"Numero "<<i<<" : ";
		cin>>v[i];
	}
	system("cls");
    for(k=n;k>0;k--){
        for(i=1;i<=k;i++){
            item=v[i];
            j=i/2;
            while(j>0 && v[j]<item){
                v[i]=v[j];
                i=j;
                j=j/2;
            }
            v[i]=item;
        }
        temp=v[1];
        v[1]=v[k];
        v[k]=temp;
    }
	cout<<"Numeros ordenados:"<<endl;
    for(i=1;i<=n;i++){
    	cout<<"Numero "<<i<<" : "<<v[i] << endl;
    }
    
    cout<<endl<<"Presione una tecla para volver al menu ";
	getch();
}
