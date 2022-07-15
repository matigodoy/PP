/*Ejercicio 11.) En un archivo figura la información correspondiente a las ventas realizadas en un comercio durante un mes. Cada registro contiene los siguientes campos:
	- Número del vendedor que hizo la venta (1 2 o 3)
	- Nombre del vendedor
	- Importe facturado por esa venta
	- Forma  de venta {1: contado  -  2: a crédito} 
Desarrollar un programa para crear y cargar el archivo, y luego otro para determinar:
a.	La cantidad de ventas realizadas en cada una de las formas.
b.	La cantidad total de ventas realizadas.
c.	El importe de ventas en cada una de las formas.
d.	El importe total de ventas realizadas.
e.	Sabiendo que los vendedores son tres, codificados como 1, 2, 3, indicar cual es el que efectuó mayor cantidad de ventas, y el que vendió por un importe mayor acumulado. */

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;

struct registro{
	int num_vendedor;
	char nombre_vendedor[30];
	float importe_facturado;
	int forma_venta, cant_total_ventas;
}reg;

int main(){
	int menu;
    do{
    	cout<<endl<<endl;
        cout<<"\tMENU DE OPCIONES "<<endl;
        cout<<"1. CARGAR LAS VENTAS "<<endl;
        cout<<"2. MOSTRAR VENTAS CARGADAS "<<endl;
        cout<<"3. MOSTRAR CANTIDAD DE VENTAS REALIZADAS EN CADA UNA DE LAS FORMAS "<<endl;
        cout<<"4. MOSTRAR LA CANTIDAD TOTAL DE VENTAS REALIZADAS "<<endl;
        cout<<"5. MOSTRAR EL IMPORTE DE VENTAS EN CADA UNA DE LAS FORMAS "<<endl;
        cout<<"6. MOSTRAR EL IMPORTE TOTAL DE VENTAS REALIZADAS "<<endl;
        cout<<"7. MOSTRAR CUAL FUE EL VENDEDOR QUE MAYORES VENTAS REALIZO "<<endl;
        cout<<"8. MOSTRAR CUAL ES EL VENDEDOR QUE MAYOR IMPORTE ACUMULO "<<endl;
        cout<<"9. SALIR "<<endl;
        cout<<"Ingrese opcion: ";
        cin>>menu;
        cout<<endl<<endl;
        switch(menu){
            case 1:
            	system("C:\\Users\\fedem\\Desktop\\FACU\\2doSEMESTRE\\PP\\TRABAJOS\\4)Archivos\\Actividad11\\cargar.exe");
                break;
            case 2:
                system("C:\\Users\\fedem\\Desktop\\FACU\\2doSEMESTRE\\PP\\TRABAJOS\\4)Archivos\\Actividad11\\mostrar.exe");
                break;
            case 3:
                system("C:\\Users\\fedem\\Desktop\\FACU\\2doSEMESTRE\\PP\\TRABAJOS\\4)Archivos\\Actividad11\\mostrarcantformas.exe");
                break;
            case 4:
                system("C:\\Users\\fedem\\Desktop\\FACU\\2doSEMESTRE\\PP\\TRABAJOS\\4)Archivos\\Actividad11\\cantventas.exe");
                break;
            case 5:
                system("C:\\Users\\fedem\\Desktop\\FACU\\2doSEMESTRE\\PP\\TRABAJOS\\4)Archivos\\Actividad11\\importeformas.exe");
                break;
            case 6:
            	system("C:\\Users\\fedem\\Desktop\\FACU\\2doSEMESTRE\\PP\\TRABAJOS\\4)Archivos\\Actividad11\\importetotal.exe");
                break;
            case 7:
            	system("C:\\Users\\fedem\\Desktop\\FACU\\2doSEMESTRE\\PP\\TRABAJOS\\4)Archivos\\Actividad11\\cantventasvendedores.exe");
                break;
            case 8:
            	system("C:\\Users\\fedem\\Desktop\\FACU\\2doSEMESTRE\\PP\\TRABAJOS\\4)Archivos\\Actividad11\\cantimportevendedor.exe");
                break;
            case 9:
                return 0;
                
            default: cout<<"Ingrese una opcion valida "<<endl;
        }
    }while(menu!=9);
    
    return 0;
}
