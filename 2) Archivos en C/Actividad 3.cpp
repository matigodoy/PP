// Se lee de un archivo una serie de registros con dos campos: Cod e Imp. Se quiere saber cuantos registros con Cod > 20 e Imp < 1000 hay en el archivo. Desarrolle antes un programa para crear y cargar el archivo.

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
void leer();

int main(){
    int menu;
    do{
        cout<<"MENU DE OPCIONES "<<endl;
        cout<<"1. CARGAR REGISTROS "<<endl;
        cout<<"2. MOSTRAR REGISTROS CARGADOS "<<endl;
        cout<<"3. MOSTRAR CANTIDAD DE REGISTROS CON CODIGO > 20 E IMPORTE < 1000 "<<endl;
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
                leer();
                break;
            case 4:
                return 0;
                
            default: cout<<"Ingrese una opcion valida "<<endl;
        }
    }while(menu!=4);
    
    return 0;
}

void carga(){
    int i=1, otro;
    FILE *m;
    m = fopen("actividad3.dat","wb");
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
            cout<<"Ingrese el importe: ";
            cin>>reg.imp;
            fwrite(&reg,sizeof(registro),1,m);
            cout<<endl;
            do{
                cout<<"Quiere cargar otro registro? (1. para si - 0. para no): ";
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
    m = fopen("actividad3.dat","rb");
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
            cout<<"Iporte: "<<reg.imp<<endl;
            fread(&reg, sizeof (registro), 1, m);
            cout<<endl;
        }
        fclose(m);
    }
    cout<<endl<<endl;
}

void leer(){
    int codigo=0, importe=0;
    FILE *m;
    m = fopen("actividad3.dat","rb");
    if (m== NULL){
        cout<<"Error al abrir el archivo ";
        cout<<"Presione una tecla... ";
        exit(1);
    }
    else{
        fread(&reg, sizeof (registro), 1, m);
        while(feof(m)==0){
            if(reg.cod>20){
                codigo ++;
            }
            if(reg.imp<1000){
                importe ++;
            }
            fread(&reg, sizeof (registro), 1, m);
        }
        fclose(m);
    }
    
    cout<<"La cantidad de registros con codigo mayor a 20 son: "<<codigo<<endl;
    cout<<"La cantidad de registros con importe menor a 1000 son: "<<importe<<endl;
    cout<<endl<<endl;
    return;
}
