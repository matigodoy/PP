#include <fstream>
#include <iostream>
#include <string.h>
#include <stdlib.h>
using namespace std;

struct registro{
    short int seccion, tipo;
    float importe;
}reg;

void carga();
void mostrar_alumnos();
void mostrar();
void mostrar_importe_comision_tipo();
void mostrar_importe_comision_seccion();


int main(){
    int menu;
    do{
        cout<<"MENU DE OPCIONES "<<endl;
        cout<<"1. CARGAR LAS VENTAS "<<endl;
        cout<<"2. MOSTRAR VENTAS CARGADAS "<<endl;
        cout<<"3. MOSTRAR IMPORTE TOTAL DE LAS COMISIONES POR EL TIPO DE VENTA "<<endl;
        cout<<"4. MOSTRAR IMPORTE TOTAL DE LAS COMISIONES POR LA SECCION DE LOS EMPLEADOS "<<endl;
        cout<<"5. SALIR "<<endl;
        cout<<"Ingrese opcion: ";
        cin>>menu;
        cout<<endl<<endl;
        switch(menu){
            case 1:
                carga();
                break;
            case 2:
                mostrar();
                break;
            case 3:
                mostrar_importe_comision_tipo();
                break;
            case 4:
                mostrar_importe_comision_seccion();
                break;
            case 5:
                return 0;
                
            default: cout<<"Ingrese una opcion valida "<<endl;
        }
    }while(menu!=6);
    
    return 0;
}

void carga(){
    int otro, i=1;
    ofstream archivo;
    archivo.open("actividad9.dat",ios::out);
    if (archivo.fail()){
        cout<<"Error al abrir el archivo ";
        cout<<"Presione una tecla... ";
        exit(1);
    }
    else{
        do{
            cout<<"Envio numero "<<i++<<endl;
            do{
                cout<<"Ingrese el tipo de venta (0: menudeo - 1: por mayor): ";
                cin>>reg.tipo;
                if(reg.tipo>1 || reg.tipo<0)cout<<"Se pide 0 o 1 "<<endl;
            }while(reg.tipo>1 || reg.tipo<0);
            archivo<<reg.tipo<<endl;
            do{
                cout<<"Ingrese la seccion del empleado (0. para 'A' - 1. para 'B' - 2. para otra seccion): ";
                cin>>reg.seccion;
                if(reg.seccion>2 || reg.seccion<0)cout<<"Se pide 0, 1 o 2 "<<endl;
            }while(reg.seccion>2 || reg.seccion<0);
            archivo<<reg.seccion<<endl;
            cout<<"Ingrese el importe: $";
            cin>>reg.importe;
            archivo<<reg.importe<<endl;
            cout<<endl;
            do{
                cout<<"Quiere cargar otra venta? (1. para si - 0. para no): ";
                cin>>otro;
                if(otro>1 || otro<0)cout<<"Se pide 1 o 0 "<<endl;
            }while(otro>1 || otro<0);
            cout<<endl;
        }while(otro!=0);
    }
    archivo.close();
    return;
}

void mostrar(){
    int i=1;
    ifstream archivo;
    archivo.open("actividad9.dat",ios::in);
    if (archivo.fail()){
        cout<<"Error al abrir el archivo ";
        cout<<"Presione una tecla... ";
        exit(1);
    }
    else{
    	short int sec=0, tip=0;
    	float imp=0;
        cout<<"Las ventas cargados son: "<<endl<<endl;
       while(!archivo.eof()){
        	archivo>>tip>>sec>>imp;
            if(!archivo.eof()){
	            cout<<"Venta numero "<<i++<<endl;
	            if(tip==1)cout<<"Tipo de venta: Por mayor"<<endl;
	            if(tip==0)cout<<"Tipo de venta: Menudeo"<<endl;
	            if(sec==0)cout<<"Seccion del empleado es: 'A' "<<endl;
	            if(sec==1)cout<<"Seccion del empleado es: 'B' "<<endl;
	            if(sec==2)cout<<"Seccion del empleado es: 'otra seccion' "<<endl;
	            cout<<"Importe: "<<imp<<endl;
	            cout<<endl;
			}
        }
        archivo.close();
    }
    cout<<endl<<endl;
}

void mostrar_importe_comision_tipo(){
    float cantcomisionmayor=0, cantcomisionmenudo=0, cantventmenudo=0, cantventmayor=0;
    ifstream archivo;
    archivo.open("actividad9.dat",ios::in);
    if (archivo.fail()){
        cout<<"Error al abrir el archivo ";
        cout<<"Presione una tecla... ";
        exit(1);
    }
    else{
        short int sec=0, tip=0;
    	float imp=0;
    	while(!archivo.eof()){
        	archivo>>tip>>sec>>imp;
            if(!archivo.eof()){
	            if(tip==1){
	                cantventmayor=cantventmayor+imp;
	            }
	            if(tip==0){
	                cantventmenudo=cantventmenudo+imp;
	            }
			}
        }
        archivo.close();
        cantcomisionmayor=cantventmayor*0.02;
        cantcomisionmenudo=cantventmenudo*0.01;
        cout<<"El total de comision por la venta al menudeo es: $"<<cantcomisionmenudo<<endl;
        cout<<"El total de comision por la venta al mayor es: $"<<cantcomisionmayor<<endl;
    }
    cout<<endl<<endl;
}

void mostrar_importe_comision_seccion(){
    float totalimporteA=0, totalimporteB=0, totalimporteotro=0;
    float comisionA=0, comisionB=0, comisionotro=0;
    ifstream archivo;
    archivo.open("actividad9.dat",ios::in);
    if (archivo.fail()){
        cout<<"Error al abrir el archivo ";
        cout<<"Presione una tecla... ";
        exit(1);
    }
    else{
    	short int sec=0, tip=0;
    	float imp=0;
        while(!archivo.eof()){
        	archivo>>tip>>sec>>imp;
            if(!archivo.eof()){
	            if(sec==0){
	                totalimporteA=totalimporteA+imp;
	            }
	            if(sec==1){
	                totalimporteB=totalimporteB+imp;
	            }
	            if(sec==2){
	                totalimporteotro=totalimporteotro+imp;
	            }
			}
        }
        archivo.close();
        comisionA=totalimporteA*0.05;
        comisionB=totalimporteB*0.05;
        comisionotro=totalimporteotro*0.08;
        cout<<"El total de importe de la seccion A es: $"<<comisionA<<endl;
        cout<<"El total de importe de la seccion B es: $"<<comisionB<<endl;
        cout<<"El total de importe de las otras secciones es: $"<<comisionotro<<endl;
    }
    cout<<endl<<endl;
}
