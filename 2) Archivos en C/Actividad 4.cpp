// De un archivo se leen una serie de registros con dos campos cada uno: Código e Importe. Se quiere saber cuantos registros tienen Código igual a 200; cuántos tienen Código diferente de 200 y cuantos registros hay en total. Desarrolle antes un programa para crear y cargar el archivo.

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
void mostrar_cant();

int main(){
    int menu;
    do{
        cout<<"MENU DE OPCIONES "<<endl;
        cout<<"1. CARGAR REGISTROS "<<endl;
        cout<<"2. MOSTRAR REGISTROS CARGADOS "<<endl;
        cout<<"3. MOSTRAR CANTIDAD DE REGISTROS CON CODIGO IGUAL O DIFETENTE A 200 Y CANTIDAD DE REGISTROS EN TOTAL "<<endl;
        cout<<"4. SALIR "<<endl;
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
                mostrar_cant();
            case 4:
                return 0;
                
            default: cout<<"Ingrese una opcion valida "<<endl;
        }
    }while(menu!=4);
    
    return 0;
}

void carga(){
    int otro, i=1;
    FILE *m;
    m = fopen("actividad4.dat","wb");
    if (m == NULL){
        cout<<"Error al abrir el archivo ";
        cout<<"Presione una tecla... ";
        exit(1);
    }
    else{
        do{
            cout<<"Registro numero "<<i++<<endl;
            cout<<"Ingrese el codigo: ";
            cin>>reg.cod;
            cout<<"Ingrese el importe: $";
            cin>>reg.imp;
            fwrite(&reg,sizeof(registro),1,m);
            cout<<endl;
            do{
                cout<<"Quiere cargar otro codigo? (1. para si - 0. para no): ";
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
    m = fopen("actividad4.dat","rb");
    if (m== NULL){
        cout<<"Error al abrir el archivo ";
        cout<<"Presione una tecla... ";
        exit(1);
    }
    else{
        fread(&reg, sizeof (registro), 1, m);
        while(feof(m)==0){
            cout<<"Registro numero "<<i++<<endl;
            cout<<"Codigo: "<<reg.cod<<endl;
            cout<<"Importe: $"<<reg.imp<<endl;
            fread(&reg, sizeof (registro), 1, m);
            cout<<endl;
        }
        fclose(m);
    }
    cout<<endl<<endl;
}

void mostrar_cant(){
    int canta200=0, cantb200=0, cant=0;
    FILE *m;
    m = fopen("actividad4.dat","rb");
    if (m== NULL){
        cout<<"Error al abrir el archivo ";
        cout<<"Presione una tecla... ";
        exit(1);
    }
    else{
        fread(&reg, sizeof (registro), 1, m);
        while(feof(m)==0){
            if(reg.cod==200)canta200++;
            if(reg.cod!=200)cantb200++;
            fread(&reg, sizeof (registro), 1, m);
        }
        fclose(m);
        cant=canta200+cantb200;
        cout<<"La cantidad de registros con un codigo igual a 200: "<<canta200<<endl;
        cout<<"La cantidad de registros con un codigo diferente a 200: "<<cantb200<<endl;
        cout<<"La cantidad de registros totales: "<<cant<<endl;
    }
    cout<<endl<<endl;
}
