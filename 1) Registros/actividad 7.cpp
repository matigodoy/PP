#include <iostream>
#include <string.h>
#include <stdio.h>
#include <cstdlib>

using namespace std;

struct inventario{
    char descripcion[100];
    int codigo, cantstock;
    float preciounitario;
};

struct inventario v[50], aux;

void cargar(inventario v[50], int cant);
void buscar_articulo(inventario v[50], int cant);
void mostrar_art_oreden_descripcion(inventario v[50], int cant);
void mostrar_art_oreden_stock(inventario v[50], int cant);

int main() {
    inventario v[50];
    int menu,cant=0;
    do{
        do{
            cout<<"_________________________________________________________________________"<<endl;
            cout<<"                            COMERCIO DEPORTIVO "<<endl;
            cout<<"-------------------------------------------------------------------------"<<endl;
            cout<<"1) Ingresar articulo deportivo "<<endl;
            cout<<"2) Buscar articulo por el codigo "<<endl;
            cout<<"3) Visualizar inventario, ordenado alfabéticamente según la descripción "<<endl;
            cout<<"4) Visualizar el inventario, ordenado decrecientemente por cantidad en stock "<<endl;
            cout<<"5) Salir "<<endl;
            cout<<"Ingrese una opcion: ";
            cin>>menu;
            if(menu<1 || menu>5)cout<<"No es una opcion valida "<<endl;
        }while(menu<1 || menu>5);
        
        if(menu==1){
            do{
                cout<<"Ingrese la cantidad de articulos a cargar (que sea mayor a 0 y menor a 50) ";
                cin>>cant;
                if(cant<=0 || cant>50)cout<< "Se pedia mayor a 0 y menor a 50 " << endl;
            }while(cant <= 0 || cant > 50);
            cargar(v,cant);
        }
        
        if(menu==2) buscar_articulo(v,cant);
                
        if(menu==3) mostrar_art_oreden_descripcion(v, cant);
                
        if(menu==4) mostrar_art_oreden_stock(v, cant);
    }
    while (menu != 5);
    
    system("pause");
    return 0;
}

void cargar(inventario v[50], int cant){
    for(int i=0;i<cant;i++){
        cout<<"ingrese la descripcion del articulo "<<i+1<<" : ";
        cin>>v[i].descripcion;
        
        cout<<"ingrese el codigo del articulo "<<i+1<<" : ";
        cin>>v[i].codigo;
        
        fflush(stdin);
        cout<<"ingrese la cantidad de unidades en stock del articulo "<<i+1<<" : ";
        cin>>v[i].cantstock;
        
        fflush(stdin);
        cout<<"ingrese el precio unitario del articulo "<<i+1<<" : $";
        cin>>v[i].preciounitario;
        
        cout<<endl;
    }
    return;
}

void buscar_articulo(inventario v[50], int cant){
    if(cant==0)cout<<"No hay articulos ingresados "<<endl;
    else{
        int cod,eliminar,a=99;
        cout<<endl<<"Ingrese el codigo del articulo a buscar: ";
        cin>>cod;
        
        for(int i=0;i<cant;i++){
            if(cod==v[i].codigo){
                cout<<"Descripcion: "<<v[i].descripcion<<endl;
                cout<<"Codigo: "<<v[i].codigo<<endl;
                cout<<"Cantidad en stock: "<<v[i].cantstock<<endl;
                cout<<"Precio unitario: "<<v[i].preciounitario<<endl;
                do{
                    cout<<"Quiere eliminar el producto del sistema? (1. si - 2. no) "<<endl;
                    cin>>eliminar;
                    if(eliminar>2 || eliminar<1)cout<<"Se pide 1 o 2 "<<endl;
                }while(eliminar>2 || eliminar<1);
                
                switch(eliminar){
                    case 1:
                        v[i].codigo=0;
                        cout<<"Se elimino el producto "<<endl;
                        return;
                        
                    case 2:
                        cout<<"No se eliminara el producto "<<endl;
                        return;
                }
            }
            if(a==99){
                cout<<"El codigo ingresado no corresponde a un producto "<<endl;
                return;
            }
        }
    }
}

void mostrar_art_oreden_descripcion(inventario v[50], int cant){
    if(cant==0)cout<<"No hay articulos ingresados "<<endl;
    else{
        int bandera;
        int temp;
        for(int i=1;i<cant;i++){
            bandera=0;
            for(int j=cant-1;j>=i;j--){
                temp=strcmp(v[j-1].descripcion,v[j].descripcion);
                if(temp>0){
                    aux=v[j];
                    v[j]=v[j-1];
                    v[j-1]=aux;
                    bandera=1;
                }
            }
            if(bandera==0)break;
        }
        cout<<"Los articulos ordenados son: "<<endl;
        for(int i=0;i<cant;i++){
            if(v[i].codigo!=0){
                cout<<"Descripcion: "<<v[i].descripcion<<endl;
                cout<<"Codigo: "<<v[i].codigo<<endl;
                cout<<"Cantidad en stock: "<<v[i].cantstock<<endl;
                cout<<"Precio unitario: "<<v[i].preciounitario<<endl;
            }
        }
    }
}

void mostrar_art_oreden_stock(inventario v[50], int cant){
    if(cant==0)cout<<"No hay articulos ingresados "<<endl;
    else{
        int bandera;
        for(int i=1;i<cant;i++){
            bandera=0;
            for(int j=cant-1;j>=i;j--){
                if(v[j-1].cantstock>v[j].cantstock){
                    aux=v[j];
                    v[j]=v[j-1];
                    v[j-1]=aux;
                    bandera=1;
                }
            }
            if(bandera==0)break;
        }
        cout<<"Los articulos ordenados son: "<<endl;
        for(int i=0;i<cant;i++){
            if(v[i].codigo!=0){
                cout<<"Descripcion: "<<v[i].descripcion<<endl;
                cout<<"Codigo: "<<v[i].codigo<<endl;
                cout<<"Cantidad en stock: "<<v[i].cantstock<<endl;
                cout<<"Precio unitario: "<<v[i].preciounitario<<endl;
            }
        }
    }
}
