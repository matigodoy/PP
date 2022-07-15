#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
using namespace std;

struct coordenadas{
    float a,b;
}ab;

void leer_puntos();
void mostrar_parordenado();
void mostrar_distancia_origen();
void mostrar_longitud_segmento();
void mostrar_pendiente();


int main(){
    int menu;
    do{
        do{
            cout<<endl<<endl;
            cout<<"-----------------------------------------------------------------------------"<<endl;
            cout<<"                              ARTICULOS EN STOCK "<<endl;
            cout<<"-----------------------------------------------------------------------------"<<endl;
            cout<<"1) Cargar los dos puntos "<<endl;
            cout<<"2) Mostrar los dos puntos en forma de par ordenado "<<endl;
            cout<<"3) Ver la distancia de cada uno al origen de coordenadas  "<<endl;
            cout<<"4) Ver la longitud del segmento de recta que los une "<<endl;
            cout<<"5) Ver la pendiente de la recta que los une "<<endl;
            cout<<"6) Salir "<<endl;
            cout<<"Ingrese una opcion: ";
            cin>>menu;
            if(menu<1 || menu>6)cout<<"No es una opcion valida "<<endl;
        }while(menu<1 || menu>6);
        
        if(menu==1)leer_puntos();
        
        if(menu==2)mostrar_parordenado();
        
        if(menu==3)mostrar_distancia_origen();
        
        if(menu==4)mostrar_longitud_segmento();
        
        if(menu==5)mostrar_pendiente();
    }
    while (menu!=6);
    
    system("pause");
    return 0;
}

void leer_puntos(){
    cout<<"Ingrese el punto 'a': ";
    cin>>ab.a;
    cout<<"Ingrese el punto 'b': ";
    cin>>ab.b;
}

void mostrar_parordenado(){
    cout<<"Los puntos en forma de par ordenado es: ("<<ab.a<<" , "<<ab.b<<") "<<endl;
}

void mostrar_distancia_origen(){
    float vc=0;
    float va=0;
    float vb=0;
    vc=sqrt((pow(ab.a,2))+(pow(ab.b,2)));
    
    va=sqrt((pow(vc,2))-(pow(ab.b,2)));
    
    vb=sqrt((pow(vc,2))-(pow(ab.a,2)));
    
    cout<<"La distancia del punto 'a' al origen de coordenadas es: "<<va<<endl;
    cout<<"La distancia del punto 'b' al origen de coordenadas es: "<<vb<<endl;
}

void mostrar_longitud_segmento(){
    float L;
    L=sqrt(pow(((ab.b*ab.a)-(ab.a*ab.a)),2)+(pow(((ab.b*ab.b)-(ab.a*ab.b)),2)));
    cout<<"La longitud del segmento de recta que los une es: "<<L<<endl;
}

void mostrar_pendiente(){
    float P;
    P=((ab.b*ab.b)-(ab.a*ab.b))/((ab.b*ab.a)-(ab.a*ab.a));
    cout<<"La pendiente de la recta que los une es: "<<P<<endl;
}
