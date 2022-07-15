#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

using namespace std;

struct estudiantes{
    char apellido[30],nombre[30];
    float nota;
};
struct empleados{
    char apellido[30],nombre[30];
    float salario;
};

struct estudiantes persona1[100],aux;
struct empleados persona2[100];

void menu();
float leer_salario();
float leer_nota();
void cargar_estudiante(int cant);
void cargar_empleados(int cant);
void mostrar_reg_estudiantes(int cant);
void mostrar_reg_empleados(int cant);
void Aumento_estudiantes_empleados(int cant);
void mostrar_orden_alfabetico_estudiantes(int cant);
void mostrar_orden_alfabetico_empleados(int cant);
void mostrar_orden_apellido_estudiante(int cant);
void mostrar_orden_apellido_empleado(int cant);
void diferente_estudiantes(int cant);
void diferente_empleados(int cant);

int main(){
    int menu, cant=0;
    do{
        do{
            cout<<"_________________________________________________________"<<endl;
            cout<<"             CONSULTA DE ESTUDIANTE-EMPLEADOS "<<endl;
            cout<<"---------------------------------------------------------"<<endl;
            cout<<"1. CARGAR DATOS DE ESTUDIANTES "<<endl;
            cout<<"2. CARGAR DATOS DE EMPLEADOS "<<endl;
            cout<<"3. CONSULTAR ESTUDIANTE POR ORDEN ALFABETICO DE NOMBRES "<<endl;
            cout<<"4. CONSULTAR ESTUDIANTE POR ORDEN ALFABETICO DE APELLIDOS "<<endl;
            cout<<"5. CONSULTAR EMPLEADOS POR ORDEN ALFABETICO DE NOMBRES "<<endl;
            cout<<"6. CONSULTAR EMPLEADOS POR ORDEN ALFABETICO DE APELLIDOS "<<endl;
            cout<<"7. CONSULTAR DATOS DE AUMENTOS DE SALARIO "<<endl;
            cout<<"8. SALIR "<<endl;
            cout<<"Ingrese opcion : ";
            cin>>menu;
            if(menu<1 || menu>8)cout<<"NO ES UNA OPCION VALIDA "<<endl;
        }while(menu<1 || menu>8);
        
        switch(menu){
            case 1:
                cout<<"INGRESE LA CANTIDAD DE ARTICULOS A CARGAR: ";
                cin>>cant;
                cargar_estudiante(cant);
                diferente_estudiantes(cant);
                break;
            case 2:
                cargar_empleados(cant);
                diferente_empleados(cant);
                break;
            case 3:
                mostrar_orden_alfabetico_estudiantes(cant);
                mostrar_reg_estudiantes(cant);
                break;
            case 4:
                mostrar_orden_apellido_estudiante(cant);
                mostrar_reg_estudiantes(cant);
                break;
            case 5:
                mostrar_orden_alfabetico_empleados(cant);
                mostrar_reg_empleados(cant);
                break;
            case 6:
                mostrar_orden_apellido_empleado(cant);
                mostrar_reg_empleados(cant);
                break;
            case 7:
                Aumento_estudiantes_empleados(cant);
                break;
            case 8: return 0;
        }
        
        system("pause");
    }while(menu!=8);
}

void diferente_estudiantes(int cant){
    for(int i=0;i<cant;i++){
        for(int j=i+1;j<cant+1;i++){
            if (persona1[i].nombre!=persona1[j].nombre){
                if(persona1[i].apellido!=persona1[i].apellido){
                    cout<<"No pueden aparecer dos registros con el mismo NOMBRE y APELLIDO en el mismo arreglo"<<endl;
                    system("pause");
                }
                break;
            }
            break;
        }
    }
}

void diferente_empleados(int cant){
    for(int i=0;i<cant;i++){
        for(int j=i+1;j<cant+1;i++){
            if (persona2[i].nombre!=persona2[j].nombre){
                if (persona2[i].apellido!=persona2[i].apellido){
                    cout<<"No pueden aparecer dos registros con el mismo NOMBRE y APELLIDO en el mismo arreglo"<<endl;
                    system("pause");
                    ;
                }
                break;
            }
            break;
        }
    }
}

float leer_nota(){
    float c;
    do{
        cout<<"NOTA DE LA MATERIA (MAYOR O IGUAL A 0): ";
        cin>>c;
        if(c<0)cout<<"Se pide mayor o igual a cero " << endl;
    }
    while(c<0);
    return c;
}

float leer_salario(){
    int c;
    do{
        cout<<"SALARIO (MAYOR A CERO): ";
        cin>>c;
        if (c < 0)
            cout<<"Se pide mayor a cero "<<endl;
    }
    while(c<0);
    return c;
}

void cargar_estudiante(int cant){
    for(int i=0;i<cant;i++){
        cout<<"ESTUDIANTE Nro: "<<i+1<<endl;
        
        fflush(stdin);
        cout<<"NOMBRE: ";
        cin>>persona1[i].nombre;
        
        fflush(stdin);
        cout<<"APELLIDO: ";
        cin>>persona1[i].apellido;
        
        fflush(stdin);
        persona1[i].nota=leer_nota();
        
    }
}

void cargar_empleados(int cant){
    for(int i=0;i<cant;i++){
        cout<<"EMPLEADO Nro: "<<i+1<<endl;
        
        fflush(stdin);
        cout<<"\nNOMBRE: ";
        cin>>persona2[i].nombre;
        
        fflush(stdin);
        cout<<"APELLIDO: ";
        cin>>persona2[i].apellido;
        
        fflush(stdin);
        persona2[i].salario=leer_salario();
    }
}

void mostrar_orden_alfabetico_estudiantes(int cant){
    int r;
    estudiantes aux;
    for(int i=1;i<cant;i++){
        for(int j=cant-1;j>=i;j--){
            r=strcmp(persona1[j-1].nombre,persona1[j].nombre);
            if(r>0){
                aux=persona1[j];
                persona1[j]=persona1[j-1];
                persona1[j-1]=aux;
            }
        }
    }
}

void mostrar_orden_alfabetico_empleados(int cant){
    int r;
    empleados aux;
    for(int i=1;i<cant;i++){
        for(int j=cant-1;j>=i;j--){
            r=strcmp(persona2[j-1].nombre,persona2[j].nombre);
            if(r>0){
                aux=persona2[j];
                persona2[j]=persona2[j-1];
                persona2[j-1]=aux;
            }
        }
    }
}

void mostrar_orden_apellido_estudiante(int cant){
    int r;
    estudiantes aux;
    for(int i=1;i<cant;i++){
        for(int j=cant-1;j>=i;j--){
            r=strcmp(persona1[j-1].apellido,persona1[j].apellido);
            if(r>0){
                aux=persona1[j];
                persona1[j]=persona1[j-1];
                persona1[j-1]=aux;
            }
        }
    }
}

void mostrar_orden_apellido_empleado(int cant){
    int r;
    empleados aux;
    for(int i=1;i<cant;i++){
        for(int j=cant-1;j>=i;j--){
            r=strcmp(persona2[j-1].apellido,persona2[j].apellido);
            if(r>0){
                aux=persona2[j];
                persona2[j]=persona2[j-1];
                persona2[j-1]=aux;
            }
        }
    }
}

void mostrar_reg_estudiantes(int cant){
    
    if(cant==0){
        cout<<"NO HAY PERSONAS REGISTRADOS "<<endl;
    }
    else{
        system("cls");
    }
    cout<<"SE REGISTRO "<<cant<<" ESTUDIANTE/S "<<endl;
    for(int i=0;i<cant;i++){
        cout<<"NOMBRE: "<<persona1[i].nombre<<endl;
        cout<<"APELLIDO: "<<persona1[i].apellido<<endl;
        cout<<"NOTA DE MATERIA: "<<persona1[i].nota<<endl;
        cout<<" "<<" ";
    }
}

void mostrar_reg_empleados(int cant){
    if(cant==0){
        cout<<"NO HAY PERSONAS REGISTRADOS "<<endl;
    }
    else{
        system("cls");
    }
    cout<<"SE REGISTRO "<<cant<<" EMPLEADO/S "<<endl;
    for (int i=0;i<cant;i++){
        cout<<"NOMBRE: "<<persona2[i].nombre<<endl;
        cout<<"APELLIDO: "<<persona2[i].apellido<<endl;
        cout<<"SALARIO: "<<persona2[i].salario<<endl;
        cout<<" "<<" ";
    }
}

void Aumento_estudiantes_empleados(int cant){
    for (int i=0;i<cant;i++){
        if(persona1[i].nombre!=persona2[i].nombre){
            if(persona1[i].apellido!=persona2[i].apellido){
                if(persona1[i].nota>=7){
                    persona2[i].salario=persona2[i].salario+(persona2[i].salario*0.10);
                    cout<<"NOMBRE: "<<persona1[i].nombre<<endl;
                    cout<<"APELLIDO: "<<persona1[i].apellido<<endl;
                    cout<<"NUEVO SALARIO: "<<persona2[i].salario<<endl;
                    break;
                }
                else{
                    cout<<"NO NAY AUMENTO PARA ESTE GRUPO "<<endl;
                }
                break;
                break;
                break;
            }
        }
    }
}
