// ​En una empresa donde los sueldos básicos oscilan entre los 1000 y los 5000 pesos, se desea saber cuántos empleados hay entre 1000 y 2000 pesos; cuantos entre 2001 y 3000; y cuantos en más de esa cantidad, así como el monto que insume cada categoría y el total general de la empresa. Para ello, se supone que los datos de cada empleado están en un archivo, a razón de un registro por cada empleado, y cada registro contiene campos para el nombre y para el sueldo básico de cada empleado. Desarrolle antes un programa para crear y cargar el archivo.

#include <stdio.h>
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
                
            default: cout<<"Ingrese una opcion valida "<<endl;
        }
    }while(menu!=7);
    
    return 0;
}

void carga(){
    int otro, i=1;
    FILE *m;
    m = fopen("actividad7.dat","wb");
    if (m == NULL){
        cout<<"Error al abrir el archivo ";
        cout<<"Presione una tecla... ";
        exit(1);
    }
    else{
        do{
            cout<<"Empleado nuemero "<<i++<<endl;
            cout<<"Ingrese el nombre: ";
            cin>>reg.nombre;
            do{
                cout<<"Ingrese el sueldo (Entre $1000 y $5000): $";
                cin>>reg.sueldo;
                if(reg.sueldo<1000 || reg.sueldo>5000)cout<<"Se pide entre $1000 y $5000 "<<endl;
            }while(reg.sueldo<1000 || reg.sueldo>5000);
            fwrite(&reg,sizeof(registro),1,m);
            cout<<endl;
            do{
                cout<<"Quiere cargar otro empleado? (1. para si - 0. para no): ";
                cin>>otro;
                if(otro>1 || otro<0)cout<<"Se pide 1 o 0 "<<endl;
            }while(otro>1 || otro<0);
            cout<<endl;
        }while(otro!=0);
    }
    fclose(m);
    return;
}

void mostrar(){
    int i=1;
    FILE *m;
    m = fopen("actividad7.dat","rb");
    if (m== NULL){
        cout<<"Error al abrir el archivo ";
        cout<<"Presione una tecla... ";
        exit(1);
    }
    else{
        fread(&reg, sizeof (registro), 1, m);
        while(feof(m)==0){
            cout<<"Empleado numero "<<i++<<endl;
            cout<<"Nombre: "<<reg.nombre<<endl;
            cout<<"Sueldo: $"<<reg.sueldo<<endl;
            fread(&reg, sizeof (registro), 1, m);
            cout<<endl;
        }
        fclose(m);
    }
    cout<<endl<<endl;
}

void empleados_1000_2000(){
    float total1000_2000=0;
    int cant1000_2000=0;
    FILE *m;
    m = fopen("actividad7.dat","rb");
    if (m== NULL){
        cout<<"Error al abrir el archivo ";
        cout<<"Presione una tecla... ";
        exit(1);
    }
    else{
        fread(&reg, sizeof (registro), 1, m);
        while(feof(m)==0){
            if(reg.sueldo<=2000 && reg.sueldo>=1000){
                cant1000_2000++;
                total1000_2000=total1000_2000+reg.sueldo;
            }
            fread(&reg, sizeof (registro), 1, m);
        }
        fclose(m);
        cout<<"La cantidad de empleados con un sueldo entre $1000 y $2000 son: "<<cant1000_2000<<endl;
        cout<<"El monto total de sueldos de los empleados con un sueldo entre $1000 y $2000 son: $"<<total1000_2000<<endl;
    }
    cout<<endl<<endl;
}

void empleados_2001_3000(){
    float total2001_3000=0;
    int cant2001_3000=0;
    FILE *m;
    m = fopen("actividad7.dat","rb");
    if (m== NULL){
        cout<<"Error al abrir el archivo ";
        cout<<"Presione una tecla... ";
        exit(1);
    }
    else{
        fread(&reg, sizeof (registro), 1, m);
        while(feof(m)==0){
            if(reg.sueldo<=3000 && reg.sueldo>=2001){
                cant2001_3000++;
                total2001_3000=total2001_3000+reg.sueldo;
            }
            fread(&reg, sizeof (registro), 1, m);
        }
        fclose(m);
        cout<<"La cantidad de empleados con un sueldo entre $2001 y $3000 son: "<<cant2001_3000<<endl;
        cout<<"El monto total de sueldos de los empleados con un sueldo entre $2001 y $3000 son: $"<<total2001_3000<<endl;
    }
    cout<<endl<<endl;
}

void empleados_3001_5000(){
    float total3001_5000=0;
    int cant3001_5000=0;
    FILE *m;
    m = fopen("actividad7.dat","rb");
    if (m== NULL){
        cout<<"Error al abrir el archivo ";
        cout<<"Presione una tecla... ";
        exit(1);
    }
    else{
        fread(&reg, sizeof (registro), 1, m);
        while(feof(m)==0){
            if(reg.sueldo<=5000 && reg.sueldo>=3001){
                cant3001_5000++;
                total3001_5000=total3001_5000+reg.sueldo;
            }
            fread(&reg, sizeof (registro), 1, m);
        }
        fclose(m);
        cout<<"La cantidad de empleados con un sueldo entre $3001 y $5000 son: "<<cant3001_5000<<endl;
        cout<<"El monto total de sueldos de los empleados con un sueldo entre $3001 y $5000 son: $"<<total3001_5000<<endl;
    }
    cout<<endl<<endl;
}
void total_sueldos(){
    float total=0;
    FILE *m;
    m = fopen("actividad7.dat","rb");
    if (m== NULL){
        cout<<"Error al abrir el archivo ";
        cout<<"Presione una tecla... ";
        exit(1);
    }
    else{
        fread(&reg, sizeof (registro), 1, m);
        while(feof(m)==0){
            total=total+reg.sueldo;
            fread(&reg, sizeof (registro), 1, m);
        }
        fclose(m);
        cout<<"El importe total de sueldos es: $"<<total<<endl;
    }
    cout<<endl<<endl;
}
