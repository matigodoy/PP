#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <windows.h>
using namespace std;
struct aulas{
	int numero, sillas, mesas;
	short int proyector, reservado;
	char reservado_nombre[50], reservado_apellido[50];
}aul;
struct Nodo{
	int dato;
	Nodo *siguiente;
};
bool cola_vacia(Nodo *);
void insertarCola(Nodo *&, Nodo *&, int), suprimirCola(Nodo *&, Nodo *&, int &), escape();
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
int main(){
	Nodo *frente = NULL;
	Nodo *fin = NULL;
	int dato;
    FILE *m;
    m = fopen("aulas.dat","rb");
    if (m== NULL){
    	fclose(m);
        system("cls");
        SetConsoleTextAttribute(hConsole, 12);
        cout<<endl<<endl<<"\tNo hay aulas registradas "<<endl<<endl;
        SetConsoleTextAttribute(hConsole, 7);
        escape();
        return 0;
    }
    else{
        fread(&aul, sizeof (aulas), 1, m);
        while(feof(m)==0){
        	dato=aul.numero;
        	insertarCola(frente, fin, dato);
            fread(&aul, sizeof (aulas), 1, m);
        }
        fclose(m);
    }
    m = fopen("aulas.dat","rb");
    if (m== NULL){
    	fclose(m);
        system("cls");
        SetConsoleTextAttribute(hConsole, 12);
        cout<<endl<<endl<<"\tNo hay aulas registradas "<<endl<<endl;
        SetConsoleTextAttribute(hConsole, 7);
        escape();
        return 0;
    }
    else{
    	system("cls");
    	SetConsoleTextAttribute(hConsole, 12);
        cout<<endl<<endl<<"\tMOSTRAR AULAS "<<endl<<endl;
        SetConsoleTextAttribute(hConsole, 7);
        fread(&aul, sizeof (aulas), 1, m);
        while(feof(m)==0){
        	while(frente != NULL){
				suprimirCola(frente, fin, dato);
	            cout<<"\tAula: "<<dato<<endl;
	            if(aul.proyector==1)cout<<"\tTiene un televisor "<<endl;
	            if(aul.proyector==2)cout<<"\tTiene un proyector "<<endl;
	            if(aul.proyector==3)cout<<"\tNo tiene televisor / proyector "<<endl;
	            cout<<"\tCantidad de sillas: "<<aul.sillas<<endl;
	            cout<<"\tCantidad de mesas: "<<aul.mesas<<endl;
	            if(aul.reservado==1)cout<<"\tEste aula se encuentra reservada por '"<<aul.reservado_nombre<<" "<<aul.reservado_apellido<<"' "<<endl;
	            fread(&aul, sizeof (aulas), 1, m);
	            cout<<endl;
	        }
        }
        fclose(m);
        cout<<"\tPresione una tecla para volver al menu anterior... ";
        getch();
    }
}
void insertarCola(Nodo *&frente, Nodo *&fin, int n){ //agregar elementos a una cola
	Nodo *nuevo_nodo = new Nodo();
	nuevo_nodo->dato = n;
	nuevo_nodo->siguiente = NULL;
	if(cola_vacia(frente)){
		frente = nuevo_nodo;
	}
	else{
		fin->siguiente = nuevo_nodo;
	}
	fin = nuevo_nodo;
}
bool cola_vacia(Nodo *frente){//funcion para determinar si la cola esta vacia o no
	if(frente == NULL)return true;
	else return false;
}
void suprimirCola(Nodo *&frente, Nodo *&fin, int &n){ //eliminar elementos de la cola
	n = frente->dato;
	Nodo *aux = frente;
	if(frente == fin){
		frente = NULL;
		fin = NULL;
	}
	else frente = frente -> siguiente;
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
