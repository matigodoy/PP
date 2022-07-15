#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
using namespace std;

struct empresa{
	long int codigo;
	char descripcion[100];
	float precio;
	int tipo;
}autos;

int main(){
	int menu;
    do{
    	cout<<endl<<endl;
        cout<<"\tVENTAS DE AUTOMOVILES "<<endl;
        cout<<"1. Cargar un vehiculo "<<endl;
        cout<<"2. Mostrar los vehiculos cargados "<<endl;
        cout<<"3. Eliminar vehiculos "<<endl;
        cout<<"4. Modificar datos de un vehiculo "<<endl;
        cout<<"5. Buscar vehiculo por el codigo "<<endl;
        cout<<"6. Ordenar vehiculo por el codigo "<<endl;
        cout<<"7. Mostrar vehiculos que tienen un precio mayor al precio promedio "<<endl;
		cout<<"8. SALIR "<<endl;
        cout<<"Ingrese opcion: ";
        cin>>menu;
        cout<<endl<<endl;
        switch(menu){
            case 1:
            	system("C:\\Users\\fedem\\Desktop\\FACU\\2doSEMESTRE\\PP\\TRABAJOS\\6)Repasoparcial2\\Ejercicio2\\cargar.exe");
                break;
            case 2:
				system("C:\\Users\\fedem\\Desktop\\FACU\\2doSEMESTRE\\PP\\TRABAJOS\\6)Repasoparcial2\\Ejercicio2\\mostrar.exe");
				break;
            case 3:
                system("C:\\Users\\fedem\\Desktop\\FACU\\2doSEMESTRE\\PP\\TRABAJOS\\6)Repasoparcial2\\Ejercicio2\\eliminar.exe");
                break;
            case 4:
                system("C:\\Users\\fedem\\Desktop\\FACU\\2doSEMESTRE\\PP\\TRABAJOS\\6)Repasoparcial2\\Ejercicio2\\modificar.exe");
                break;
            case 5:
                system("C:\\Users\\fedem\\Desktop\\FACU\\2doSEMESTRE\\PP\\TRABAJOS\\6)Repasoparcial2\\Ejercicio2\\buscar.exe");
                break;
            case 6:
                system("C:\\Users\\fedem\\Desktop\\FACU\\2doSEMESTRE\\PP\\TRABAJOS\\6)Repasoparcial2\\Ejercicio2\\ordenar.exe");
                break;
            case 7:
                system("C:\\Users\\fedem\\Desktop\\FACU\\2doSEMESTRE\\PP\\TRABAJOS\\6)Repasoparcial2\\Ejercicio2\\preciopromedio.exe");
                break;
            case 8:
                return 0;
                
            default: cout<<"Ingrese una opcion valida "<<endl;
        }
    }while(menu!=8);
    
    return 0;
}
