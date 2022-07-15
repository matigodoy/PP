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
struct ingreso{
	char nombre[50];
	char apellido[50];
	long int dni;
}ingr, *puntero_ingr = &ingr;
void escape();
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
int main(){
    FILE *m;
    m = fopen("ingreso.dat","rb");
    if (m== NULL){
    	fclose(m);
        system("cls");
        SetConsoleTextAttribute(hConsole, 12);
        cout<<endl<<endl<<"\tNo hay aulas dadas de alta "<<endl<<endl;
        SetConsoleTextAttribute(hConsole, 7);
        escape();
        return 0;
    }
    else{
    	system("cls");
    	SetConsoleTextAttribute(hConsole, 12);
        cout<<endl<<endl<<"\t        CONSULTAR INGRESO "<<endl;
        SetConsoleTextAttribute(hConsole, 7);
        fread(&ingr, sizeof (ingreso), 1, m);
        while(feof(m)==0){
            cout<<"\tDNI: "<<ingr.dni<<endl;
            cout<<"\tNombre '"<<ingr.nombre<<" "<<ingr.apellido<<"' "<<endl;
            fread(&ingr, sizeof (ingreso), 1, m);
            cout<<endl;
        }
        fclose(m);
        cout<<"\tPresione una tecla para volver al menu anterior... ";
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
