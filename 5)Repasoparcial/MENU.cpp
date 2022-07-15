#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;

struct empresa{
	long int codigo;
	int tipo;
	char titulo[50];
	float monto;
}publi, v[100];

int main(){
	int menu;
    do{
    	cout<<endl<<endl;
        cout<<"\tEMPRESA DE CLIPS PUBLICITARIOS "<<endl;
        cout<<"1. Cargar clips publicitarios "<<endl;
        cout<<"2. Mostrar los clips cargados "<<endl;
        cout<<"3. Buscar clip por el codigo de identificacion "<<endl;
        cout<<"4. Mostrar datos de los clips cuyo tipo de dato sea diferente a 5 "<<endl;
        cout<<"5. SALIR "<<endl;
        cout<<"Ingrese opcion: ";
        cin>>menu;
        cout<<endl<<endl;
        switch(menu){
            case 1:
            	system("C:\\Users\\fedem\\Desktop\\FACU\\2doSEMESTRE\\PP\\TRABAJOS\\5)Repasoparcial\\carga.exe");
                break;
            case 2:
				system("C:\\Users\\fedem\\Desktop\\FACU\\2doSEMESTRE\\PP\\TRABAJOS\\5)Repasoparcial\\mostrar.exe");
				break;
            case 3:
                system("C:\\Users\\fedem\\Desktop\\FACU\\2doSEMESTRE\\PP\\TRABAJOS\\5)Repasoparcial\\3.exe");
                break;
            case 4:
                system("C:\\Users\\fedem\\Desktop\\FACU\\2doSEMESTRE\\PP\\TRABAJOS\\5)Repasoparcial\\4.exe");
                break;
            case 5:
                return 0;
                
            default: cout<<"Ingrese una opcion valida "<<endl;
        }
    }while(menu!=5);
    
    return 0;
}
