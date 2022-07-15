#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
using namespace std;

struct articulos{
    int codigo, cantactual, cantminima;
    char descripcion[100];
    float precio, valorstock;
};

void leer_datos(articulos v[50], int cant);
void mostrar_articulos(articulos v[50], int cant);
void cuantos_inferior_stock(articulos v[50], int cant);
void mostrar_inferior_stock(articulos v[50], int cant);
void cambiar_precio(articulos v[50], int cant);
void nuevo_registro(articulos v[50], articulos v1[50], int cant);


int main() {
    articulos v[50], v1[50];
    int menu,cant=0;
    do{
        do{
            cout<<endl<<endl;
            cout<<"-----------------------------------------------------------------------------"<<endl;
            cout<<"                              ARTICULOS EN STOCK "<<endl;
            cout<<"-----------------------------------------------------------------------------"<<endl;
            cout<<"1) Ingresar datos de los articulos "<<endl;
            cout<<"2) Mostrar articulos cargados "<<endl;
            cout<<"3) Articulos que tienen una cantidad en stock inferior a la cantidad minima "<<endl;
            cout<<"4) Buscar articulos segun su codigo "<<endl;
            cout<<"5) Cargar nuevo registro "<<endl;
            cout<<"6) Salir "<<endl;
            cout<<"Ingrese una opcion: ";
            cin>>menu;
            if(menu<1 || menu>6)cout<<"No es una opcion valida "<<endl;
        }while(menu<1 || menu>6);
        
        if(menu==1){
            do{
                cout<<"Ingrese la cantidad de articulos a cargar (que sea mayor a 0 y menor a 50) ";
                cin>>cant;
                if(cant<=0 || cant>50)cout<< "Se pedia mayor a 0 y menor a 50 " << endl;
            }while(cant <= 0 || cant > 50);
            leer_datos(v,cant);
        }
        
        if(menu==2)mostrar_articulos(v, cant);
        
        if(menu==3)cuantos_inferior_stock(v,cant);
        
        if(menu==4)cambiar_precio(v,cant);
        
        if(menu==5)nuevo_registro(v,v1,cant);
    }
    while (menu!=6);
    
    system("pause");
    return 0;
}

void leer_datos(articulos v[50], int cant){
    for(int i=0;i<cant;i++){
        cout<<"Articulo "<<i+1<<endl;
        cout<<"Ingrese el codigo: ";
        cin>>v[i].codigo;
        
        fflush(stdin);
        cout<<"Ingrese la descripcion: ";
        cin>>v[i].descripcion;
        
        cout<<"Ingrese la cantidad actual en stock: ";
        cin>>v[i].cantactual;
        
        cout<<"Ingrese la cantidad minima requerida: ";
        cin>>v[i].cantminima;
        
        cout<<"Ingrese el precio unitario del articulo: $";
        cin>>v[i].precio;
        
        cout<<endl;
    }
    return;
}

void mostrar_articulos(articulos v[50], int cant){
    if(cant==0)cout<<"No hay articulos ingresados "<<endl;
    else{
        cout<<"Los articulos cargados son: "<<endl;
        for(int i=0;i<cant;i++){
            cout<<"Articulo "<<i+1<<endl;
            cout<<"Codigo: "<<v[i].codigo<<endl;
            cout<<"Descripcion: "<<v[i].descripcion<<endl;
            cout<<"Cantidad actual en stock: "<<v[i].cantactual<<endl;
            cout<<"Cantidad requerida "<<v[i].cantminima<<endl;
            cout<<"Precio unidario: $"<<v[i].precio<<endl;
            cout<<endl;
        }
        return;
    }
}

void cuantos_inferior_stock(articulos v[50], int cant){
    if(cant==0)cout<<"No hay articulos ingresados "<<endl;
    else{
        int a=0,b;
        for(int i=0;i<cant;i++){
            if(v[i].cantminima>v[i].cantactual){
                a++;
            }
        }
        cout<<"La cantidad de articulos que tienen una cantidad inferior en stock a la cantidad minima son: "<<a<<endl;
        do{
            cout<<"Quieres ver dicho/s elemento/s (1. Para si - 0. Para no) ";
            cin>>b;
            if(b>1 || b<0)cout<<"Se pide 1 o 0 "<<endl;
        }while(b>1 || b<0);
    
        if(b==1){
            mostrar_inferior_stock(v,cant);
        }
        if (b==0){
            return;
        }
    }
}

void mostrar_inferior_stock(articulos v[50], int cant){
    cout<<"Los elementos que tienen una cantidad inferior en stock a la cantidad minima son: "<<endl;
    for(int i=0;i<cant;i++){
        if(v[i].cantminima>v[i].cantactual){
            cout<<"Codigo: "<<v[i].codigo<<endl;
            cout<<"Descripcion: "<<v[i].descripcion<<endl;
            cout<<"Cantidad actual en stock: "<<v[i].cantactual<<endl;
            cout<<"Cantidad requerida "<<v[i].cantminima<<endl;
            cout<<"Precio unidario: $"<<v[i].precio<<endl;
            cout<<endl;
        }
    }
    return;
}

void cambiar_precio(articulos v[50], int cant){
    if(cant==0)cout<<"No hay articulos ingresados "<<endl;
    else{
        int x,a,b=99;
        float pr;
        cout<<"Ingrese el codigo del articulo a buscar: ";
        cin>>x;
        for(int i=0;i<cant;i++){
            if(x==v[i].codigo){
                b=0;
                cout<<"Se encontro el articulo: "<<endl;
                cout<<"Codigo: "<<v[i].codigo<<endl;
                cout<<"Descripcion: "<<v[i].descripcion<<endl<<endl;
                do{
                    cout<<"Quieres cambiar el precio de dicho articulo? (1. para si - 0. para no) ";
                    cin>>a;
                    if(a>1 || a<0)cout<<"Se pide 1 o 0 "<<endl;
                }while(a>1 || a<0);
                switch(a){
                    case 1:
                        cout<<"ingrese el nuevo precio ";
                        cin>>pr;
                        v[i].precio=pr;
                        cout<<"Se cambio el precio "<<endl;
                        
                    case 2:
                        return;
                }
            }
        }
        if(b==99){
            cout<<"El codigo ingresado no corresponde a un articulo cargado "<<endl;
        }
        return;
    }
}

void nuevo_registro(articulos v[50], articulos v1[50], int cant){
    if(cant==0)cout<<"No hay articulos ingresados "<<endl;
    else{
        float m=0;
        cout<<"Ingrese el valor de stock: ";
        cin>>m;
        for(int i=0;i<cant;i++){
            float m2=v[i].cantactual * v1[i].precio;
            if(m2>m){
                v1[i].codigo=v[i].codigo;
                strcpy(v1[i].descripcion, v[i].descripcion);
                v[i].valorstock=v[i].cantactual * v1[i].precio;
                
                cout<<"El nuevo registro es: "<<endl;
                for(int i=0;i<cant;i++){
                    cout<<"Codigo: "<<v1[i].codigo<<endl;
                    cout<<"Descripcion: "<<v1[i].descripcion<<endl;
                    cout<<"Precio: "<<v1[i].valorstock<<endl;
                }
            }
            else{
                cout<<"No existe el valor ingresado en el stock "<<endl;
            }
        }
    }
}
