#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
using namespace std;

struct compania{
	long int dni;
	int provincia;
	char patente[20];
	float importe;
}aut;

int main(){
	int menu;
    do{
    	cout<<endl<<endl;
        cout<<"\tALQUILER DE AUTOMOVILES "<<endl;
        cout<<"1. Cargar un cliente "<<endl;
        cout<<"2. Mostrar los clientes cargados "<<endl;
        cout<<"3. Buscar cliente por el numero de DNI "<<endl;
        cout<<"4. Mostrar clientes que hayan pagado un importe menor a un valor igresado por teclado "<<endl;
		cout<<"5. SALIR "<<endl;
        cout<<"Ingrese opcion: ";
        cin>>menu;
        cout<<endl<<endl;
        switch(menu){
            case 1:
            	system("C:\\Users\\fedem\\Desktop\\FACU\\2doSEMESTRE\\PP\\TRABAJOS\\6)Repasoparcial2\\Ejercicio1\\cargar.exe");
                break;
            case 2:
				system("C:\\Users\\fedem\\Desktop\\FACU\\2doSEMESTRE\\PP\\TRABAJOS\\6)Repasoparcial2\\Ejercicio1\\mostrar.exe");
				break;
            case 3:
                system("C:\\Users\\fedem\\Desktop\\FACU\\2doSEMESTRE\\PP\\TRABAJOS\\6)Repasoparcial2\\Ejercicio1\\buscarporDNI.exe");
                break;
            case 4:
                system("C:\\Users\\fedem\\Desktop\\FACU\\2doSEMESTRE\\PP\\TRABAJOS\\6)Repasoparcial2\\Ejercicio1\\vector.exe");
                break;
            case 5:
                return 0;
                
            default: cout<<"Ingrese una opcion valida "<<endl;
        }
    }while(menu!=5);
    
    return 0;
}
