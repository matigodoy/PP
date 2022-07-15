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
    	system("cls");
    	SetConsoleTextAttribute(hConsole, 12);
        cout<<endl<<endl<<"\t        MOSTRAR AULAS "<<endl;
        SetConsoleTextAttribute(hConsole, 7);
        cout<<"\t(Ordenados de menor a mayor)"<<endl<<endl<<endl;
        fread(&aul, sizeof (aulas), 1, m);
        while(feof(m)==0){
            cout<<"\tAula: "<<aul.numero<<endl;
            if(aul.proyector==1)cout<<"\tTiene un televisor "<<endl;
            if(aul.proyector==2)cout<<"\tTiene un proyector "<<endl;
            if(aul.proyector==3)cout<<"\tNo tiene televisor / proyector "<<endl;
            cout<<"\tCantidad de sillas: "<<aul.sillas<<endl;
            cout<<"\tCantidad de mesas: "<<aul.mesas<<endl;
            if(aul.reservado==1)cout<<"\tEste aula se encuentra reservada por '"<<aul.reservado_nombre<<" "<<aul.reservado_apellido<<"' "<<endl;
            fread(&aul, sizeof (aulas), 1, m);
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
