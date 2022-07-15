#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <ctime>
#include <math.h>
#include <stdio.h>

using namespace std;

struct personas{
	int long dni;
	char nombre[90];
}r;

struct personas_vector{
	int long dni_vec;
	char nombre_vec[90];	
}a[100];

int main(){
	FILE*m;
	m = fopen("Variedad.dat","rb");
	int contador = 0;
	int aux = 0;
	char auxi[90];	
	if (m == NULL){
		cout<<"Error interno con el archivo..."<<endl;
		exit (1);
	}
	else{
		int i=0;
		fread(&r, sizeof(personas), 1, m);
		while (feof(m) == 0){
			a[i].dni_vec = r.dni;
			strcpy(a[i].nombre_vec,r.nombre);
			i++;
			contador++;
			fread(&r, sizeof(personas), 1, m);
		}
	}
	int long k,h;
	char y[90];
	for(h=1;h<=contador/9;h=3*h+1);
	for(;h>0;h/=3){
		for(int long j=h;j<contador;j++){
			strcpy(y,a[j].nombre_vec);
			aux = a[j].dni_vec;
			for(k=j - h;k>=0 && y<a[k].nombre_vec;k-=h){
				a[k+h].dni_vec = a[k].dni_vec;
				strcpy(a[k+h].nombre_vec,a[k].nombre_vec);
			}
			a[k+h].dni_vec = aux;
			strcpy(a[k+h].nombre_vec,y);
		}
	}
	for(int i=0; i<contador; i++){
    	cout<<"DNI: "<<a[i].dni_vec<<endl;
    	cout<<"Nombre y Apellido: "<<a[i].nombre_vec<<endl;
    	cout<<".............................."<<endl;
	}
	system("pause");system("cls");
	fclose(m);
}
