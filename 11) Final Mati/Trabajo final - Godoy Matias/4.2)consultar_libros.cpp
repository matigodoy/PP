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
void escape();
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
int main(){
	int i=1;
    FILE *m;
    m = fopen("libros.dat","rb");
    if (m== NULL){
    	fclose(m);
        system("cls");
        SetConsoleTextAttribute(hConsole, 12);
        cout<<endl<<endl<<"\tNo hay libros dados de alta "<<endl<<endl;
        SetConsoleTextAttribute(hConsole, 7);
        escape();
        return 0;
    }
    else{
    	system("cls");
    	SetConsoleTextAttribute(hConsole, 12);
        cout<<endl<<endl<<"\t        CONSULTAR LIBROS "<<endl;
        SetConsoleTextAttribute(hConsole, 7);
        cout<<"\t(Ordenados de menor a mayor)"<<endl<<endl<<endl;
        fread(&biblio, sizeof (biblioteca), 1, m);
        while(feof(m)==0){
        	cout<<"\tLibro "<<i++<<endl;
        	cout<<"\tCodigo: "<<biblio.codigo<<endl;
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
void escape(){
	int i=3;
	do{
		Sleep(200);
		cout<<"\tVolviendo al menu en "<<i<<" ..."<<endl;
		Sleep(1000);
		i--;
	}while(i!=0);
}
