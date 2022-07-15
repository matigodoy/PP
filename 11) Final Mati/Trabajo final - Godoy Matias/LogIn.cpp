#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <windows.h>
using namespace std;
struct ingreso{
	char nombre[50];
	char apellido[50];
	long int dni;
}ingr, *puntero_ingr = &ingr;

void ingresar(), escape();
int num_aula;
long int dnix;
char nombrex[50],apellidox[50];
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

int main(){
	int i=1;
    FILE *m;
    m = fopen("ingreso.dat","rb");
    if (m== NULL){
    	fclose(m);
        system("cls");
        int menu;
		do{
			system("cls");
			cout<<endl<<endl;
			SetConsoleTextAttribute(hConsole, 415);
			cout<<"\t\t     ___         .______      .___  ___.      ______ "<<endl;
			cout<<"\t\t    /   \\        |   _  \\     |   \\/   |     /      |"<<endl;
			cout<<"\t\t   /  ^  \\       |  |_)  |    |  \\  /  |    |  ,----'"<<endl;
			cout<<"\t\t  /  /_\\  \\      |   _  <     |  |\\/|  |    |  |     "<<endl;
			cout<<"\t\t /  _____  \\     |  |_)  |    |  |  |  |    |  `----."<<endl;
			cout<<"\t\t/__/     \\__\\    |______/     |__|  |__|     \\______|"<<endl<<endl<<endl;
		    SetConsoleTextAttribute(hConsole, 12);
		    cout<<endl<<"\t\t1. ALTA DE USUARIO"<<endl;
		    SetConsoleTextAttribute(hConsole, 7);
		    cout<<"\t\t\t > Debes de darte de alta por primera vez. "<<endl;
		    cout<<endl<<"\t\tIngrese su DNI: ";
		    cin>>dnix;
		    cout<<endl<<"\t\tIngrese su nombre: ";
		    cin>>nombrex;
		    cout<<endl<<"\t\tIngrese su apellido: ";
		    cin>>apellidox;
		    menu=0;
		}while(menu!=0);
		
			FILE *i;
		    i = fopen("ingreso.dat","wb");
		    if (i== NULL){
		    	fclose(i);
		        system("cls");
		        SetConsoleTextAttribute(hConsole, 12);
		        cout<<endl<<endl<<"\tError en el archivo "<<endl<<endl;
		        SetConsoleTextAttribute(hConsole, 7);
		        escape();
		        return 0;
		    }
		    else{
		    	ingr.dni=dnix;
		    	strcpy(ingr.nombre,nombrex);
		    	strcpy(ingr.apellido,apellidox);
	    		fwrite(&*puntero_ingr,sizeof(ingreso),1,i);
	    	}
	    	fclose(i);
	    	system("00)Cargando.exe");
			system("0)ABMC.exe");
    }
    else
	{
    	fclose(m);
    	system("00)Cargando.exe");
        system("0)ABMC.exe");
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
