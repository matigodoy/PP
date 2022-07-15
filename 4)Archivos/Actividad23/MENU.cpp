#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;

struct registro{
	long int codigo, preciocont, preciofinan;
	char marca[30], color[20];
	int modelo;
}reg;

int main(){
	int menu;
    do{
    	cout<<endl<<endl;
        cout<<"CONCESIONARIO DE AUTOS "<<endl;
        cout<<"1. CARGAR AUTOS "<<endl;
        cout<<"2. MOSTRAR AUTOS CARGADOS "<<endl;
        cout<<"3. MOSTRAR AUTOS CON UNA DIFERENCIA MENOR A $2000 ENTRE PRECIO DE CONTADO Y PRECIO FINANCIADO "<<endl;
        cout<<"4. MOSTRAR CUANTOS AUTOS HAY CON MODELO MENOR A 94 "<<endl;
        cout<<"5. MOSTRAR LOS AUTOS QUE SEAN DEL MODELO 1995 "<<endl;
        cout<<"6. SALIR "<<endl;
        cout<<"Ingrese opcion: ";
        cin>>menu;
        cout<<endl<<endl;
        switch(menu){
            case 1:
            	system("C:\\Users\\fedem\\Desktop\\FACU\\2doSEMESTRE\\PP\\TRABAJOS\\4)Archivos\\Actividad23\\cargar.exe");
                break;
            case 2:
                system("C:\\Users\\fedem\\Desktop\\FACU\\2doSEMESTRE\\PP\\TRABAJOS\\4)Archivos\\Actividad23\\mostrar.exe");
                break;
            case 3:
            	system("C:\\Users\\fedem\\Desktop\\FACU\\2doSEMESTRE\\PP\\TRABAJOS\\4)Archivos\\Actividad23\\autoscondiferencia.exe");
            	break;
            case 4:
            	system("C:\\Users\\fedem\\Desktop\\FACU\\2doSEMESTRE\\PP\\TRABAJOS\\4)Archivos\\Actividad23\\autosmodelomenor94.exe");
            	break;
            case 5:
            	system("C:\\Users\\fedem\\Desktop\\FACU\\2doSEMESTRE\\PP\\TRABAJOS\\4)Archivos\\Actividad23\\autosmodelo95.exe");
            	break;
            case 6:
                return 0;
                
            default: cout<<"Ingrese una opcion valida "<<endl;
        }
    }while(menu!=6);
    
    return 0;
}

