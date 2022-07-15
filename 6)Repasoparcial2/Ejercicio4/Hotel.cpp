#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
using namespace std;

struct hotel{
	long int dni;
	char nombre[30];
	float importe;
	int dias;
}huesped;

int main(){
	int menu;
    do{
    	cout<<endl<<endl;
        cout<<"\tHOTEL "<<endl;
        cout<<"1. Cargar huespedes "<<endl;
        cout<<"2. Mostrar los huespedes cargados "<<endl;
        cout<<"3. Buscar huespedes que se hayan registrados por una cantidad de dias mayor a un valor ingresado "<<endl;
		cout<<"4. SALIR "<<endl;
        cout<<"Ingrese opcion: ";
        cin>>menu;
        cout<<endl<<endl;
        switch(menu){
            case 1:
            	system("C:\\Users\\fedem\\Desktop\\FACU\\2doSEMESTRE\\PP\\TRABAJOS\\6)Repasoparcial2\\Ejercicio4\\cargar.exe");
                break;
            case 2:
				system("C:\\Users\\fedem\\Desktop\\FACU\\2doSEMESTRE\\PP\\TRABAJOS\\6)Repasoparcial2\\Ejercicio4\\mostrar.exe");
				break;
            case 3:
                system("C:\\Users\\fedem\\Desktop\\FACU\\2doSEMESTRE\\PP\\TRABAJOS\\6)Repasoparcial2\\Ejercicio4\\buscar.exe");
                break;
            case 4:
                return 0;
                
            default: cout<<"Ingrese una opcion valida "<<endl;
        }
    }while(menu!=4);
    
    return 0;
}
