#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;

struct cuenta_corriente{
    int Codigo_cliente;
    char ApellNombCliente[30];
    long int NumCta;
    float SalCta;
};

struct cuenta_corriente datos;

void menu();
void cargar_datos_cuenta_corriente();
void mostrar_ctas_gest_judicial();
void mostrar_ctas_bloqueadas();
void mostrar_ctas_cerradas();
void mostrar_ctas_normales();
void mostrar_importe_ctas_gest_judicial();

int main(){
    int menu;
    do{
        cout<<" MENU DE OPCIONES "<<endl;
        cout<<"1. INGRESAR DATOS DE CUENTA CORRIENTE"<<endl;
        cout<<"2. MOSTRAR LISTA DE CUENTAS EN GESTION JUDICIAL"<<endl;
        cout<<"3. MOSTRAR LISTA DE CUENTAS BLOQUEADAS"<<endl;
        cout<<"4. CONSULTAR CANTIDAD DE CERRADAS"<<endl;
        cout<<"5. CONSULTAR CANTIDAD DE NORMALES"<<endl;
        cout<<"6. CONSULTAR IMPORTE IMPORTE DE LAS CUENTAS EN GESTION JUDICIAL"<<endl;
        cout<<"7. SALIR"<<endl;
        cout<<"INGRESE UNA OPCION: ";
        cin>>menu;
        cout<<endl<<endl;
        switch(menu){
            case 1:
                cargar_datos_cuenta_corriente();
                break;
            case 2:
                mostrar_ctas_gest_judicial();
                break;
            case 3:
                mostrar_ctas_bloqueadas();
                break;
            case 4:
                mostrar_ctas_cerradas();
                break;
            case 5:
                mostrar_ctas_normales();
                break;
            case 6:
                mostrar_importe_ctas_gest_judicial();
                break;
            case 7:
                return 0;
                
            default:cout<<"INGRESE UNA OPCION VALIDA ";
        }
    }while(menu!=7);
    
    return 0;
}

void cargar_datos_cuenta_corriente(){
    int i=1, otro;
    FILE *m;
    m=fopen("actividad10.dat","wb");
    if(m==NULL){
        cout<<"Error de apertura.."<<endl;
        exit(1);
    }
    else{
        do{
            cout<<"REGISTRO DE CUENTA CORRIENTE NUMERO "<<i++<<endl;
            do{
                cout<<"INGRESE EL CODIGO (1. PARA A=CERRADA - 2. PARA B=BLOQUEDA - 3. PARA C=GESTION JUDICIAL - 4. PARA D=NORMAL: ";
                cin>>datos.Codigo_cliente;
                if(datos.Codigo_cliente>4 || datos.Codigo_cliente<1)cout<<"No es un codigo valido "<<endl;
            }while(datos.Codigo_cliente>4 || datos.Codigo_cliente<1);
            
            cout<<"INGRESE EL APELLIDOS Y NOMBRES DEL CLIENTE: ";
            cin.getline(datos.ApellNombCliente,30,'\n');
            cout<<"INGRESE EL NUMERO DE CUENTA: ";
            cin>>datos.NumCta;
            cout<<"INGRESE EL SALDO EN CUENTA: $";
            cin>>datos.SalCta;
            fwrite(&datos,sizeof(cuenta_corriente),1,m);
            do{
                cout<<"Quiere cargar otra cuenta? (1. para si - 0. para no): ";
                cin>>otro;
                if(otro>1 || otro<0)cout<<"Se pide 1 o 0 "<<endl;
            }while(otro>1 || otro<0);
            cout<<endl;
        }while(otro!=0);
    }
    fclose(m);
}

void mostrar_ctas_gest_judicial(){
    int cant_ges_judicial=0;
    FILE *m;
    m=fopen("actividad10.dat","rb");
    if(m==NULL){
        cout<<"Error de apertura";
        exit(1);
    }
    else{
        fread(&datos,sizeof(cuenta_corriente),1,m);
        cout<<"REPORTE DE CLIENTES CON CUENTAS CORRIENTES EN GESTION JUDICIAL "<<endl;
        while(!feof(m)){
            if(datos.Codigo_cliente==3){
                cant_ges_judicial++;
                cout<<" CODIGO: "<<datos.Codigo_cliente<<endl;
                cout<<" APELLIDOS Y NOMBRES: "<<datos.ApellNombCliente<<endl;
                cout<<" NUMERO DE CUENTA: "<<datos.NumCta<<endl;
                cout<<" SALDO DE CUENTA: $"<<datos.SalCta<<endl;
            }
            fread(&datos,sizeof(cuenta_corriente),1,m);
        }
        cout<<endl;
        cout<<"SE ENCONTRARON "<<cant_ges_judicial<<" CUENTA(s) CORRIENTE(s)"<<endl<<endl<<endl;
        fclose(m);
    }
}

void mostrar_ctas_bloqueadas(){
    int cant_bloq=0;
    FILE *m;
    m=fopen("actividad10.dat","rb");
    if(m==NULL){
        cout<<"Error de apertura";
        exit(1);
    }
    else{
        fread(&datos,sizeof(cuenta_corriente),1,m);
        cout<<"REPORTE DE CLIENTES CON CUENTAS CORRIENTES BLOQUEADAS "<<endl;
        while(!feof(m)){
            if(datos.Codigo_cliente==2){
                cant_bloq++;
                cout<<" CODIGO: "<<datos.Codigo_cliente<<endl;
                cout<<" APELLIDOS Y NOMBRES: "<<datos.ApellNombCliente<<endl;
                cout<<" NUMERO DE CUENTA: "<<datos.NumCta<<endl;
                cout<<" SALDO DE CUENTA: $"<<datos.SalCta<<endl;
            }
            fread(&datos,sizeof(cuenta_corriente),1,m);
        }
        cout<<endl;
        cout<<"SE ENCONTRARON "<<cant_bloq<<" CUENTA(s) CORRIENTE(s)"<<endl<<endl<<endl;
        fclose(m);
    }
}

void mostrar_ctas_cerradas(){
    int cant_ccerradas=0;
    FILE *m;
    m=fopen("actividad10.dat","rb");
    if(m==NULL){
        cout<<"Error de apertura"<<endl;
        exit(1);
    }
    else{
        fread(&datos,sizeof(cuenta_corriente),1,m);
        cout<<"REPORTE DE CLIENTES CON CUENTAS CORRIENTES CERRADAS "<<endl;
        while(!feof(m)){
            if(datos.Codigo_cliente==1){
                cant_ccerradas++;
                cout<<" CODIGO: "<<datos.Codigo_cliente<<endl;
                cout<<" APELLIDOS Y NOMBRES: "<<datos.ApellNombCliente<<endl;
                cout<<" NUMERO DE CUENTA: "<<datos.NumCta<<endl;
                cout<<" SALDO DE CUENTA: $"<<datos.SalCta<<endl;
            }
            fread(&datos,sizeof(cuenta_corriente),1,m);
            
        }
        cout<<endl;
        cout<<"SE ENCONTRARON "<<cant_ccerradas<<" CUENTA(s) CORRIENTE(s)"<<endl<<endl<<endl;
        fclose(m);
    }
}

void mostrar_ctas_normales(){
    int cant_cnormales=0;
    FILE *m;
    m=fopen("actividad10.dat","rb");
    if(m==NULL){
        cout<<"Error de apertura"<<endl;
        exit(1);
    }
    else{
        fread(&datos,sizeof(cuenta_corriente),1,m);
        cout<<"REPORTE DE CLIENTES CON CUENTAS CORRIENTES NORMALES "<<endl;
        while(!feof(m)){
            if(datos.Codigo_cliente==4){
                cant_cnormales++;
                cout<<" CODIGO: "<<datos.Codigo_cliente<<endl;
                cout<<" APELLIDOS Y NOMBRES: "<<datos.ApellNombCliente<<endl;
                cout<<" NUMERO DE CUENTA: "<<datos.NumCta<<endl;
                cout<<" SALDO DE CUENTA: $"<<datos.SalCta<<endl;
            }
            fread(&datos,sizeof(cuenta_corriente),1,m);
            
        }
        cout<<endl;
        cout<<"SE ENCONTRO "<<cant_cnormales<<" CUENTA(s) CORRIENTE(s)"<<endl<<endl<<endl;
        fclose(m);
    }
}

void mostrar_importe_ctas_gest_judicial(){
    int cant_gjudicial=0;
    float suma_gjudicial=0;
    FILE *m;
    m=fopen("actividad10.dat","rb");
    if(m==NULL){
        cout<<"Error de apertura"<<endl;
        exit(1);
    }
    else{
        fread(&datos,sizeof(cuenta_corriente),1,m);
        cout<<"REPORTE IMPORTE DE LAS CUENTAS EN GESTION JUDICIAL "<<endl;
        while(!feof(m)){
            if(datos.Codigo_cliente==3){
                cant_gjudicial++;
                suma_gjudicial=suma_gjudicial+datos.SalCta;
                cout<<" CODIGO: "<<datos.Codigo_cliente<<endl;
                cout<<" APELLIDOS Y NOMBRES: "<<datos.ApellNombCliente<<endl;
                cout<<" NUMERO DE CUENTA: "<<datos.NumCta<<endl;
                cout<<" SALDO DE CUENTA: $."<<datos.SalCta<<endl;
            }
            fread(&datos,sizeof(cuenta_corriente),1,m);
        }
        cout<<endl;
        cout<<"SE ENCONTRO "<<cant_gjudicial<<" CUENTA(s) EN GESTION JUDICIAL"<<endl;
        cout<<"EL IMPORTE DE LA(s) CUENTA(s) ES DE: $"<<suma_gjudicial<<endl<<endl<<endl;
        fclose(m);
    }
}
