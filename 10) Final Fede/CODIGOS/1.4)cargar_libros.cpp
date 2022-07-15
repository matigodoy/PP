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
	int otro, i=1;
    FILE *m;
    FILE *n;
    long int codigoP;
    int salir=0;
    do{
    	m = fopen("libros.dat","ab");
    	if (m== NULL){
	    	system("cls");
	    	SetConsoleTextAttribute(hConsole, 12);
	        cout<<endl<<endl<<"\tError al abrir el archivo "<<endl<<endl;
	        SetConsoleTextAttribute(hConsole, 7);
	        escape();
	        return 0;
	    }
    	system("cls");
    	SetConsoleTextAttribute(hConsole, 12);
		cout<<endl<<endl<<"\tCARGAR LIBRO "<<i++<<endl<<endl;
    	SetConsoleTextAttribute(hConsole, 7);
    	do{
		    n = fopen("libros.dat","rb");
		    if (n == NULL){
		        system("cls");
		        SetConsoleTextAttribute(hConsole, 12);
		        cout<<endl<<endl<<"\tError al abrir el archivo "<<endl<<endl;
		        SetConsoleTextAttribute(hConsole, 7);
		        escape();
		        return 0;
		    }
		    else{
	        	cout<<"\tIngrese el codigo: ";
	        	cin>>codigoP;
				salir=0;
				fread(&biblio, sizeof (biblioteca), 1, n);
	    		while(feof(n)==0){
	    			if(biblio.codigo==codigoP){
						SetConsoleTextAttribute(hConsole, 12);
						cout<<endl<<endl<<"\tEl codigo '"<<biblio.codigo<<"' existe."<<endl;
						SetConsoleTextAttribute(hConsole, 7);
						cout<<"\tPor favor, ingrese uno distinto"<<endl<<endl;
    					salir=1;
					}
					fread(&biblio, sizeof (biblioteca), 1, n);
		    	}
	    		fclose(n);
    		}
		}while(salir!=0);
    	biblio.codigo=codigoP;
    	cout<<"\tIngrese el titulo: ";
    	fflush(stdin);
    	cin.getline(biblio.titulo,50,'\n');
    	biblio.reservado=0;
		cout<<endl;
		fwrite(&biblio,sizeof(biblioteca),1,m);
		fclose(m);
        do{
            cout<<"\tQuiere cargar otro libro? (1. para si - 0. para no): ";
            cin>>otro;
            if(otro<0 || otro>1)cout<<"\tSe pide 1 o 0 "<<endl;
        }while(otro<0 || otro>1);
        cout<<endl;
    }while(otro!=0);
    fclose(m);
    system("10)Ordenamiento_libros.exe");
    return 0;
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
