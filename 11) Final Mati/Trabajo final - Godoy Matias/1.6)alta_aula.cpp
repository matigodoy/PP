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
void escape();
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
int main(){
	int otro, i=1;
    FILE *m;
    FILE *n;
    long int codigoP;
    int salir=0;
    do{
    	m = fopen("aulas.dat","ab");
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
		cout<<endl<<endl<<"\tCARGAR AULA "<<i++<<endl<<endl;
    	SetConsoleTextAttribute(hConsole, 7);  	
    	do{
		    n = fopen("aulas.dat","rb");
		    if (n == NULL){
		        system("cls");
		        SetConsoleTextAttribute(hConsole, 12);
		        cout<<endl<<endl<<"\tError al abrir el archivo "<<endl<<endl;
		        SetConsoleTextAttribute(hConsole, 7);
		        escape();
		        return 0;
		    }
		    else{
	        	cout<<"\tIngrese el numero: ";
	        	cin>>codigoP;
				salir=0;
				fread(&aul, sizeof (aulas), 1, n);
	    		while(feof(n)==0){
	    			if(aul.numero==codigoP){
						SetConsoleTextAttribute(hConsole, 12);
						cout<<endl<<endl<<"\tEl numero del aula '"<<aul.numero<<"' ya existe."<<endl;
						SetConsoleTextAttribute(hConsole, 7);
						cout<<"\tPor favor, ingrese uno distinto"<<endl<<endl;
    					salir=1;
					}
					fread(&aul, sizeof (aulas), 1, n);
		    	}
	    		fclose(n);
			}
		}while(salir!=0);
    	aul.numero=codigoP;
    	do{
            cout<<"\tIngrese si tiene (1. televisor - 2. proyector - 3. no tiene) : ";
    		cin>>aul.proyector;
            if(aul.proyector<1 || aul.proyector>3)cout<<"\tSe pide 1 - 2 - 3 "<<endl;
        }while(aul.proyector<1 || aul.proyector>3);
    	cout<<"\tIngrese la cantidad de sillas: ";
    	cin>>aul.sillas;
    	cout<<"\tIngrese la cantidad de mesas: ";
    	cin>>aul.mesas;
    	aul.reservado=0;
		cout<<endl;
		fwrite(&aul,sizeof(aulas),1,m);
		fclose(m);
        do{
            cout<<"\tQuiere cargar otra aula? (1. para si - 0. para no): ";
            cin>>otro;
            if(otro<0 || otro>1)cout<<"\tSe pide 1 o 0 "<<endl;
        }while(otro<0 || otro>1);
        cout<<endl;
    }while(otro!=0);
    fclose(m);
    system("Ordenamiento_aulas");
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
