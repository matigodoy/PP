#include <fstream>
#include <iostream>
#include <string.h>
#include <stdlib.h>
using namespace std;

struct registro{
    float sueldo;
    char nombre[20];
}reg;

void carga();
void mostrar();
void empleados_1000_2000();
void empleados_2001_3000();
void empleados_3001_5000();
void total_sueldos();

int main(){
    int menu;
    do{
        cout<<"MENU DE OPCIONES "<<endl;
        cout<<"1. CARGAR LOS EMPLEADOS "<<endl;
        cout<<"2. MOSTRAR EMPLEADOS CARGADOS "<<endl;
        cout<<"3. MOSTRAR CANTIDAD DE EMPLEADOS CON UN SUELDO ENTRE $1000 Y $2000 "<<endl;
        cout<<"4. MOSTRAR CANTIDAD DE EMPLEADOS CON UN SUELDO ENTRE $2001 Y $3000 "<<endl;
        cout<<"5. MOSTRAR CANTIDAD DE EMPLEADOS CON UN SUELDO ENTRE $3001 Y $5000 "<<endl;
        cout<<"6. MOSTRAR EL IMPORTE TOTAL DE SUELDOS "<<endl;
        cout<<"7. SALIR "<<endl;
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
                empleados_1000_2000();
                break;
            case 4:
                empleados_2001_3000();
                break;
            case 5:
                empleados_3001_5000();
                break;
            case 6:
                total_sueldos();
                break;
            case 7:
                return 0;
                
            default: cout<<"Ingrese una opcion valida "<<endl<<endl<<endl;
        }
    }while(menu!=7);
    
    return 0;
}

void carga(){
    int otro, i=1;
    ofstream archivo;
    archivo.open("actividad7.dat",ios::out);
    if (archivo.fail()){
        cout<<"Error al abrir el archivo ";
        cout<<"Presione una tecla... ";
        exit(1);
    }
    else{
        do{
            cout<<"Empleado nuemero "<<i++<<endl;
            cout<<"Ingrese el nombre: ";
            cin>>reg.nombre;
            archivo<<reg.nombre<<endl;
            do{
                cout<<"Ingrese el sueldo (Entre $1000 y $5000): $";
                cin>>reg.sueldo;
                if(reg.sueldo<1000 || reg.sueldo>5000)cout<<"Se pide entre $1000 y $5000 "<<endl;
            }while(reg.sueldo<1000 || reg.sueldo>5000);
            archivo<<reg.sueldo<<endl;
            cout<<endl;
            do{
                cout<<"Quiere cargar otro empleado? (1. para si - 0. para no): ";
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
    archivo.open("actividad7.dat",ios::in);
    if (archivo.fail()){
        cout<<"Error al abrir el archivo ";
        cout<<"Presione una tecla... ";
        exit(1);
    }
    else{
    	float sueldos=0;
    	char nombres[20];
        while(!archivo.eof()){
        	archivo>>nombres>>sueldos;
            if(!archivo.eof()){
	            cout<<"Empleado numero "<<i++<<endl;
	            cout<<"Nombre: "<<nombres<<endl;
	            cout<<"Sueldo: $"<<sueldos<<endl;
	            cout<<endl;
			}
        }
        archivo.close();
    }
    cout<<endl<<endl;
}

void empleados_1000_2000(){
	float sueldos=0;
	char nombres[20];
    float total1000_2000=0;
    int cant1000_2000=0;
    ifstream archivo;
    archivo.open("actividad7.dat",ios::in);
    if (archivo.fail()){
        cout<<"Error al abrir el archivo ";
        cout<<"Presione una tecla... ";
        exit(1);
    }
    else{
    	memset (nombres,0,20);
        while(!archivo.eof()){
        	archivo>>nombres>>sueldos;
            if(!archivo.eof()){
	            if(sueldos<=2000 && sueldos>=1000){
	                cant1000_2000++;
	                total1000_2000=total1000_2000+sueldos;
	            }
			}
        }
        archivo.close();
        cout<<"La cantidad de empleados con un sueldo entre $1000 y $2000 son: "<<cant1000_2000<<endl;
        cout<<"El monto total de sueldos de los empleados con un sueldo entre $1000 y $2000 son: $"<<total1000_2000<<endl;
    }
    cout<<endl<<endl;
}

void empleados_2001_3000(){
	float sueldos=0;
	char nombres[20];
    float total2001_3000=0;
    int cant2001_3000=0;
    ifstream archivo;
    archivo.open("actividad7.dat",ios::in);
    if (archivo.fail()){
        cout<<"Error al abrir el archivo ";
        cout<<"Presione una tecla... ";
        exit(1);
    }
    else{
    	memset (nombres,0,20);
        while(!archivo.eof()){
        	archivo>>nombres>>sueldos;
            if(!archivo.eof()){
	            if(sueldos<=3000 && sueldos>=2001){
	                cant2001_3000++;
	                total2001_3000=total2001_3000+sueldos;
	            }
			}
        }
        archivo.close();
        cout<<"La cantidad de empleados con un sueldo entre $2001 y $3000 son: "<<cant2001_3000<<endl;
        cout<<"El monto total de sueldos de los empleados con un sueldo entre $2001 y $3000 son: $"<<total2001_3000<<endl;
    }
    cout<<endl<<endl;
}

void empleados_3001_5000(){
	float sueldos=0;
	char nombres[20];
    float total3001_5000=0;
    int cant3001_5000=0;
    ifstream archivo;
    archivo.open("actividad7.dat",ios::in);
    if (archivo.fail()){
        cout<<"Error al abrir el archivo ";
        cout<<"Presione una tecla... ";
        exit(1);
    }
    else{
        memset (nombres,0,20);
        while(!archivo.eof()){
        	archivo>>nombres>>sueldos;
            if(!archivo.eof()){
	            if(sueldos<=5000 && sueldos>=3001){
	                cant3001_5000++;
	                total3001_5000=total3001_5000+sueldos;
	            }
			}
        }
        archivo.close();
        cout<<"La cantidad de empleados con un sueldo entre $3001 y $5000 son: "<<cant3001_5000<<endl;
        cout<<"El monto total de sueldos de los empleados con un sueldo entre $3001 y $5000 son: $"<<total3001_5000<<endl;
    }
    cout<<endl<<endl;
}
void total_sueldos(){
	float sueldos=0;
	char nombres[20];
    float total=0;
    ifstream archivo;
    archivo.open("actividad7.dat",ios::in);
    if (archivo.fail()){
        cout<<"Error al abrir el archivo ";
        cout<<"Presione una tecla... ";
        exit(1);
    }
    else{
        memset (nombres,0,20);
        while(!archivo.eof()){
        	archivo>>nombres>>sueldos;
            if(!archivo.eof()){
	            total=total+sueldos;
			}
        }
        archivo.close();
        cout<<"El importe total de sueldos es: $"<<total<<endl;
    }
    cout<<endl<<endl;
}
