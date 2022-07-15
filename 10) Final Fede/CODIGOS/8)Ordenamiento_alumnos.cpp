#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <windows.h>
using namespace std;
struct alumnos{
	char nombre[50], apellido[50];
	long int dni, legajo;
	short int reservado;
	int numero, reservado_hora, reservado_minutos, reservado_dia, reservado_mes, reservado_anio, reservado_numero;
}alum, v[1000], y;
void ordenar(int n), copiar2(int n), escape();
int copiar();
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
int main(){
	int n=copiar();
	ordenar(n);
	copiar2(n);
	return 0;
}
int copiar(){
	FILE *m;
    m = fopen("alumnos.dat","rb");
    if (m== NULL){
    	fclose(m);
        system("cls");
        SetConsoleTextAttribute(hConsole, 12);
        cout<<endl<<endl<<"\tError en el archivo "<<endl<<endl;
        SetConsoleTextAttribute(hConsole, 7);
        escape();
        return 0;
    }
    else{
    	int i=0;
    	system("cls");
        fread(&alum, sizeof (alumnos), 1, m);
        while(feof(m)==0){
            v[i]=alum;
            i++;
            fread(&alum, sizeof (alumnos), 1, m);
            cout<<endl;
        }
        fclose(m);
        return i;
    }
}
void ordenar(int n){
	for(int j=1; j<n; j++){
		y=v[j];
		int k;
		for(k=j-1; k>=0 && y.dni<v[k].dni; k--){
			v[k+1]=v[k];
		}
		v[k+1]=y;
	}
}
void copiar2(int n){
	FILE *m;
    m = fopen("alumnos.dat","wb");
    if (m== NULL){
    	fclose(m);
        system("cls");
        SetConsoleTextAttribute(hConsole, 12);
        cout<<endl<<endl<<"\tError en el archivo"<<endl<<endl;
        SetConsoleTextAttribute(hConsole, 7);
        escape();
        return;
    }
    else{
    	for(int i=0; i<n; i++){
    		alum=v[i];
    		fwrite(&alum,sizeof(alumnos),1,m);
		}
	}
}
void escape(){
	int i=3;
	do{
		Sleep(200);
		cout<<"\tVolviendo al menu en "<<i<<" ..."<<endl;
		Sleep(1000);
		i--;
	}while(i!=0);
}
