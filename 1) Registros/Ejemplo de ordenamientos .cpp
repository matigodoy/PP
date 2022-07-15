#include<iostream>
#include<cstdlib>
#include<string.h>
#define max 100
#define max_char 50
 
using namespace std;
 
struct persona{
    int codigo;
    char nombres[max_char] ;
    char apellidos[max_char];
};
 
struct persona alumno[max], aux;
 
void menu();
 
void registrar_alumnos(int);
 
void mostrar_alumnos(int);
 
void mostrar_alumnos_apellido(int);
 
void mostrar_alumnos_codigo(int);
 
void ordenacion_burbuja_nombre(int);
 
void ordenacion_burbuja_apellido(int);
 
void ordenacion_burbuja(int);
 
/*--------------- Funcion Principal --------------------------*/
int main(void){
    system("color 0a");
    int opcion;
    int nro=0;
    do{
        menu();
        cin>>opcion;
 
        switch(opcion){
            case 1: cout<<"\n\nCANTIDAD DE ALUMNOS A REGISTRAR:";
                    cin>>nro;
                    registrar_alumnos(nro);
                    break;
            case 2: mostrar_alumnos(nro);
                    break;
            case 3: ordenacion_burbuja_nombre(nro);
                    mostrar_alumnos(nro);
                    break;
            case 4: ordenacion_burbuja_apellido(nro);
                    mostrar_alumnos_apellido(nro);
                    break;
            case 5: ordenacion_burbuja(nro);
                    mostrar_alumnos_codigo(nro);
                    break;
 
            case 6: return 0;
 
 
            default: cout<<"\nINGRESE UNA OPCION VALIDA...\n"; break;
 
        }
        system("pause");  system("cls");
    }while(opcion!=6);
}
 
/*--------------- Muestra el Menu  --------------------------*/
void menu(void){
    cout<<"\n\t\t[    REGISTRO DE ALUMNOS    ]\n";
    cout<<"\t\t----------------------------\n\n";
    cout<<" 1. REGISTRAR ALUMNOS                           "<<endl;
    cout<<" 2. MOSTRAR ALUMNOS                             "<<endl;
    cout<<" 3. MOSTRAR ALUMNOS POR NOMBRE                  "<<endl;
    cout<<" 4. MOSTRAR ALUMNOS POR APELLIDO                "<<endl;
    cout<<" 5. MOSTRAR ALUMNOS POR CODIGO                  "<<endl;
    cout<<" 6. SALIR                                       "<<endl;
 
    cout<<"\n Ingrese opcion : ";
}
 
/*----------------------- Funcion para Registrar Alumnos --------------------------*/
void registrar_alumnos(int nro){
    system("cls");
    for(int i=0; i<nro;i++){
 
        cout<<"\n\n\t\t[  REGISTRO  ]\n";
        cout<<"\t\t------------";
        cout<<"\n\tDATOS DEL ALUMNO #"<<i+1;
        cout<<"\n\n\tCODIGO:"; cin>>alumno[i].codigo;
        cin.ignore(); cout<<"\n\tNOMBRES:"; cin.getline(alumno[i].nombres,max_char);
        cin.ignore(); cout<<"\tAPELLIDOS:"; cin.getline(alumno[i].apellidos,max_char);
 
        system("cls");
    }
 
    cout<<"\n\n\t REGISTRO COMPLETO...\n\n";
}
 
/*-------------------- Funcion que muestra a todos los alumnos registrados ------------------*/
void mostrar_alumnos(int nro){
 
    if(nro==0){
        cout<<"\n\nNO HAY ALUMNOS REGISTRADOS...\n";
    }else { system("cls");
            cout<<"\n\t|ORDEN|      NOMBRES      |      APELLIDOS        |     CODIGO   |"<<endl;
            cout<<"\n\t------------------------------------------------------------------\n";
            for(int i=0;i<nro;i++){
                cout<<"\t  "<<i<<"            "<<alumno[i].nombres<<"          "<<alumno[i].apellidos<<"              "<<alumno[i].codigo<<endl;
                cout<<"\n\t------------------------------------------------------------------\n";
            }
            cout<<endl<<endl;
    }
}
 
 
/*-------------------- Funcion que muestra a todos los alumnos para la ordenacion por apellido ------------------*/
void mostrar_alumnos_apellido(int nro){
 
    if(nro==0){
        cout<<"\n\nNO HAY ALUMNOS REGISTRADOS...\n";
    }else { system("cls");
            cout<<"\n\t|ORDEN|      APELLIDOS      |      NOMBRES        |     CODIGO   |"<<endl;
            cout<<"\n\t------------------------------------------------------------------\n";
            for(int i=0;i<nro;i++){
                cout<<"\t  "<<i<<"            "<<alumno[i].apellidos<<"             "<<alumno[i].nombres<<"            "<<alumno[i].codigo<<endl;
                cout<<"\n\t------------------------------------------------------------------\n";
            }
            cout<<endl<<endl;
    }
}
 
/*-------------------- Funcion que muestra a todos los alumnos para la ordenacion por codigo ------------------*/
void mostrar_alumnos_codigo(int nro){
 
    if(nro==0){
        cout<<"\n\nNO HAY ALUMNOS REGISTRADOS...\n";
    }else { system("cls");
            cout<<"\n\t|ORDEN|     CODIGO       |       NOMBRES      |      APELLIDOS        |"<<endl;
            cout<<"\n\t-----------------------------------------------__-------------------\n";
            for(int i=0;i<nro;i++){
                cout<<"\t  "<<i<<"              "<<alumno[i].codigo<<"            "<<alumno[i].nombres<<"          "<<alumno[i].apellidos<<endl;
                cout<<"\n\t------------------------------------------------------------------\n";
            }
            cout<<endl<<endl;
    }
}
/*-----------------Ordenacion de Burbuja para los nombres  --------------------------*/
void ordenacion_burbuja_nombre(int n){
    int i,j, bandera;
 
    int temp;
    for(i=1; i<n; i++)
    {bandera=0;         //inciamos la bandera en 0
     for(j=n-1; j>=i; j--){
            temp=strcmp(alumno[j-1].nombres,alumno[j].nombres);
            if(temp>0){
                aux=alumno[j];
                alumno[j]=alumno[j-1];
                alumno[j-1]=aux;
                bandera=1; //si hubo cambio cambiamos la bandera a 1
         }
         }
         if (bandera==0)
        break; //si no hubo cambios entonces salir del for
    }
}
 
/*-------------------Ordenacion de burbuja para los apellidos  --------------------------*/
void ordenacion_burbuja_apellido(int n){
    int i,j, bandera;
 
    int temp;
    for(i=1; i<n; i++)
    {bandera=0;         //inciamos la bandera en 0
     for(j=n-1; j>=i; j--){
            temp=strcmp(alumno[j-1].apellidos,alumno[j].apellidos);
            if(temp>0){
                aux=alumno[j];
                alumno[j]=alumno[j-1];
                alumno[j-1]=aux;
                bandera=1; //si hubo cambio cambiamos la bandera a 1
         }
         }
         if (bandera==0)
        break; //si no hubo cambios entonces salir del for
    }
}
 
/*------------------------ ordenacion de burbuja para los codigos --------------------------*/
void ordenacion_burbuja(int n){
    int i,j, bandera;
    for(i=1; i<n; i++)
    {bandera=0;         //inciamos la bandera en 0
     for(j=n-1; j>=i; j--){
        if(alumno[j-1].codigo>alumno[j].codigo){
                aux=alumno[j];
                alumno[j]=alumno[j-1];
                alumno[j-1]=aux;
                bandera=1; //si hubo cambio cambiamos la bandera a 1
         }
         }
         if (bandera==0)
        break; //si no hubo cambios entonces salir del for
    }
}
