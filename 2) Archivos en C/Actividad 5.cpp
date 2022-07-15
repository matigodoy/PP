// En un archivo se tienen los códigos y los importes de ciertos productos en cada registro. Se desea saber cuántos tienen un código superior a 1000; y cual es el importe total acumulado de esos productos. Y por otra parte, dar la cantidad y el importe total de los productos con código inferior o igual a 1000. Imprimir dichas cantidades por fin de archivo. Desarrolle antes un programa para crear y cargar el archivo.

#include <stdio.h>
#include <iostream>
#include <string.h>
#include <stdlib.h>

using namespace std;

struct registro{
    long int cod;
    float imp;
}reg;

void carga();
void mostrar();
void mostrar_codigo_superior1000();
void mostrar_codigo_inferior1000();

int main(){
    int menu;
    do{
        cout<<"MENU DE OPCIONES "<<endl;
        cout<<"1. CARGAR LOS PRODUCTOS "<<endl;
        cout<<"2. MOSTRAR PRODUCTOS CARGADOS "<<endl;
        cout<<"3. MOSTRAR CANTIDAD DE PRODUCTOS CON UN CODIGO SUPERIOR A 1000 "<<endl;
        cout<<"4. MOSTRAR CANTIDAD DE PRODUCTOS CON UN CODIGO INFERIOR O IGUAL A 1000 "<<endl;
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
                mostrar_codigo_superior1000();
                break;
            case 4:
                mostrar_codigo_inferior1000();
                break;
            case 5:
                return 0;
                
            default: cout<<"Ingrese una opcion valida "<<endl;
        }
    }while(menu!=5);
    
    return 0;
}

void carga(){
    int otro, i=0;
    FILE *m;
    m = fopen("actividad5.dat","wb");
    if (m == NULL){
        cout<<"Error al abrir el archivo ";
        cout<<"Presione una tecla... ";
        exit(1);
    }
    else{
        do{
            i++;
            cout<<"Producto numero "<<i<<endl;
            cout<<"Ingrese el codigo ";
            cin>>reg.cod;
            cout<<"Ingrese el importe: $";
            cin>>reg.imp;
            fwrite(&reg,sizeof(registro),1,m);
            cout<<endl;
            do{
                cout<<"Quiere cargar otro producto? (1. para si - 0. para no): ";
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
    FILE *m;
    m = fopen("actividad5.dat","rb");
    if (m== NULL){
        cout<<"Error al abrir el archivo ";
        cout<<"Presione una tecla... ";
        exit(1);
    }
    else{
        int i=0;
        fread(&reg, sizeof (registro), 1, m);
        while(feof(m)==0){
            i++;
            cout<<"Producto numero "<<i<<endl;
            cout<<"Codigo: "<<reg.cod<<endl;
            cout<<"Importe: $"<<reg.imp<<endl;
            fread(&reg, sizeof (registro), 1, m);
            cout<<endl;
        }
        fclose(m);
    }
    cout<<endl<<endl;
}

void mostrar_codigo_superior1000(){
    int cantmayor=0, importemayor=0;
    FILE *m;
    m = fopen("actividad5.dat","rb");
    if (m== NULL){
        cout<<"Error al abrir el archivo ";
        cout<<"Presione una tecla... ";
        exit(1);
    }
    else{
        fread(&reg, sizeof (registro), 1, m);
        while(feof(m)==0){
            if(reg.cod>1000){
                cantmayor++;
                importemayor=importemayor+reg.imp;
            }
            fread(&reg, sizeof (registro), 1, m);
        }
        fclose(m);
        cout<<"La cantidad de productos que tienen un codigo mayor a 1000 son: "<<cantmayor<<endl;
        cout<<"El importe total de los productos que tienen un codigo mayor a 1000 es: $"<<importemayor<<endl;
    }
    cout<<endl<<endl;
}

void mostrar_codigo_inferior1000(){
    int cantmenor=0, importemenor=0;
    FILE *m;
    m = fopen("actividad5.dat","rb");
    if (m== NULL){
        cout<<"Error al abrir el archivo ";
        cout<<"Presione una tecla... ";
        exit(1);
    }
    else{
        fread(&reg, sizeof (registro), 1, m);
        while(feof(m)==0){
            if(reg.cod<=1000){
                cantmenor++;
                importemenor=importemenor+reg.imp;
            }
            fread(&reg, sizeof (registro), 1, m);
        }
        fclose(m);
        cout<<"La cantidad de productos que tienen un codigo menor o igual a 1000 son: "<<cantmenor<<endl;
        cout<<"El importe total de los productos que tienen un codigo menor o igual a 1000 es: $"<<importemenor<<endl;
    }
}
