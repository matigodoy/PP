#include<iostream>
#include<conio.h>
#include<stdlib.h>
#include <conio.h>
using namespace std;
  
int main(){
    string v[100],item,temp;
	int j,i,k,n;
	cout<<"Ingresa la cantidad de palabras que quiere cargar: ";
    cin>>n;
    
    cout<<endl<<"Ingrese las palabras "<<endl;
	for(i=1;i<=n;i++){
		cout<<"Palabra "<<i<<" : ";
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
	cout<<"Las palabras ordenadas son:"<<endl;
    for(i=1;i<=n;i++){
    	cout<<"Palabra "<<i<<" : "<<v[i] << endl;
    }
    
    cout<<endl<<"Presione una tecla para volver al menu ";
	getch();
}
