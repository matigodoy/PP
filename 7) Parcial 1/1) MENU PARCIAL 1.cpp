#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
using namespace std;

struct asistencias{
	long int dni;
	char apellido[30];
	char nombre[30];
	int dia;
	int mes;
	int anio;
	int causa;
	short int presente;
}alumnos;

int main(){
	int menu;
    do{
    	cout<<endl<<endl;
        cout<<"\tASISTENCIAS DE LOS ALUMNOS "<<endl;
        cout<<"1. Cargar un alumno "<<endl;
        cout<<"2. Mostrar los alumnos cargados "<<endl;
        cout<<"3. Mostrar la causa con mayor cantidad de ausentes "<<endl;
        cout<<"4. Mostrar ausentes injustificados "<<endl;
        cout<<"5. Mostrar ausentes justificados "<<endl;
        cout<<"6. Mostrar el estudiante con x dias de ausentes (x lo ingresa por teclado) "<<endl;
		cout<<"7. SALIR "<<endl;
        cout<<"Ingrese opcion: ";
        cin>>menu;
        cout<<endl<<endl;
        switch(menu){
            case 1:
            	system("cargar.exe");
                break;
            case 2:
				system("mostrar.exe");
				break;
            case 3:
                system("mayorcausa.exe");
                break;
            case 4:
                system("ausentesinjustificados.exe");
                break;
            case 5:
                system("ausentesjustificados.exe");
                break;
            case 6:
                system("diasausentes.exe");
                break;
            case 7:
                return 0;
                
            default: cout<<"Ingrese una opcion valida "<<endl;
        }
    }while(menu!=7);
    
    return 0;
}
