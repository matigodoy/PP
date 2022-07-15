#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
using namespace std;

struct instituto{
	long int legajo;
	int anio;
	char nombre[20];
	float importe;
}alumno;

int main(){
	int menu;
    do{
    	cout<<endl<<endl;
        cout<<"\tINSTITUTO DE ESTUDIOS SECUNDARIOS "<<endl;
        cout<<"1. Cargar un alumno "<<endl;
        cout<<"2. Mostrar los alumnos cargados "<<endl;
        cout<<"3. Mostrar los alumnos cursando 5to y 6to año "<<endl;
		cout<<"4. SALIR "<<endl;
        cout<<"Ingrese opcion: ";
        cin>>menu;
        cout<<endl<<endl;
        switch(menu){
            case 1:
            	system("C:\\Users\\fedem\\Desktop\\FACU\\2doSEMESTRE\\PP\\TRABAJOS\\6)Repasoparcial2\\Ejercicio3\\cargar.exe");
                break;
            case 2:
				system("C:\\Users\\fedem\\Desktop\\FACU\\2doSEMESTRE\\PP\\TRABAJOS\\6)Repasoparcial2\\Ejercicio3\\mostrar.exe");
				break;
            case 3:
                system("C:\\Users\\fedem\\Desktop\\FACU\\2doSEMESTRE\\PP\\TRABAJOS\\6)Repasoparcial2\\Ejercicio3\\vector.exe");
                break;
            case 4:
                return 0;
                
            default: cout<<"Ingrese una opcion valida "<<endl;
        }
    }while(menu!=4);
    
    return 0;
}
