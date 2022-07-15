#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <windows.h>
using namespace std;
struct biblioteca{
	char titulo[50], reservado_nombre[50], reservado_apellido[50];
	long int codigo;
	short int reservado;
	int DNI;
}biblio;
struct Nodo{
	long int dato;
	Nodo *siguiente;
};
void agregarPila(Nodo *&, long int), sacarPila(Nodo *&, long int &), escape();
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
int main(){
	Nodo *pila = NULL;
	long int dato;
    FILE *m;
    m = fopen("libros.dat","rb");
    if (m== NULL){
    	fclose(m);
        system("cls");
        SetConsoleTextAttribute(hConsole, 12);
        cout<<endl<<endl<<"\tNo hay libros registrados "<<endl<<endl;
        SetConsoleTextAttribute(hConsole, 7);
        escape();
        return 0;
    }
    else{
        fread(&biblio, sizeof (biblioteca), 1, m);
        while(feof(m)==0){
        	dato=biblio.codigo;
        	agregarPila(pila, dato);
            fread(&biblio, sizeof (biblioteca), 1, m);
        }
        fclose(m);
        m = fopen("libros.dat","rb");
	    if (m== NULL){
	    	fclose(m);
	        system("cls");
	        SetConsoleTextAttribute(hConsole, 12);
	        cout<<endl<<endl<<"\tNo hay libros registrados "<<endl<<endl;
	        SetConsoleTextAttribute(hConsole, 7);
	        escape();
	        return 0;
	    }
	    else{
	    	long int vector[1000];
	    	int k=0;
	    	while (pila != NULL){ //mientras no sea el final de la pila
	    		sacarPila(pila, dato);
	    		vector[k]=dato;
	    		k++;
	    	}
	    	int i=1, j=k-1;
	    	system("cls");
	    	SetConsoleTextAttribute(hConsole, 12);
	        cout<<endl<<endl<<"\tMOSTRAR LIBROS "<<endl<<endl;
	        SetConsoleTextAttribute(hConsole, 7);
	        fread(&biblio, sizeof (biblioteca), 1, m);
	        while(feof(m)==0){
        		cout<<"\tLibro "<<i++<<endl;
	        	cout<<"\tCodigo: "<<vector[j]<<endl;
	        	j--;
	            cout<<"\tTitulo: "<<biblio.titulo<<endl;
				if(biblio.reservado==1){
					cout<<"\tReservado a nombre de "<<biblio.reservado_nombre<<" "<<biblio.reservado_apellido<<endl;
				}
				fread(&biblio, sizeof (biblioteca), 1, m);
	        	cout<<endl;
	        }
	        fclose(m);
			cout<<endl<<"\tPresione una tecla para volver al menu anterior... ";
	        getch();
	    }
	}
}
void agregarPila(Nodo *&pila, long int n){ //agregar elementos a una pila
	Nodo *nuevo_nodo = new Nodo();
	nuevo_nodo->dato = n;
	nuevo_nodo->siguiente = pila;
	pila = nuevo_nodo;
}
void sacarPila(Nodo *&pila, long int &n){ //sacar elementos de una pila
	Nodo *aux = pila;
	n = aux->dato;
	pila = aux->siguiente;
	delete aux;
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
