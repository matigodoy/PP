#include <iostream>

using namespace std;

struct corredor{
    char nombre[20];
    int edad;
    int sexo;
    char club[20];
};

void leer_nombre();
void leer_edad( );
void leer_sexo( );
void leer_club( );
void asignar_categoria( );
void mostrar_datos( );

int main(){
    corredor c1[50];
    
    leer_nombre();
    leer_edad();
    leer_sexo();
    leer_club( );
    mostrar_datos( );
    asignar_categoria( );
    
    return 0;
}

void leer_nombre(){
    cout<<"ingrese el nombre de la persona: ";
    gets(c1.nombre);
}

void leer_edad( ){
    cout<<"ingrese la edad de la persona: ";
    cin>>(c1.edad);
}

void leer_sexo( ){
    cout<< "ingrese el sexo de la persona (0 para masculino) (1 para femenino): ";
    cin>>(c1.sexo);
    fflush(stdin);
}

void leer_club( ){
    cout<<"ingrese el nombre del club: ";
    gets(c1.club);
}

void mostrar_datos( ){
    cout<<"el nombre del competidor es: "<<c1.nombre<<endl;
    cout<<"la edad del corredor es: "<<c1.edad<<endl;
    if((c1.sexo) = 0)cout<<"el sexo de la persona es masculino "<<endl;
    else cout<<"el sexo de la persona es femenino "<<endl;
    cout<<"el nombre del club es: "<<c1.club<<endl;
}

void asignar_categoria( ){
    
    if((c1.edad)<= 18){
        cout<<"la categoria es juvenil "<<endl;
    }
    if(((c1.edad)<= 40) && ((c1.edad)>18)){
        cout<<"la categoria es señor "<<endl;
    }
    if((c1.edad)>40){
        cout<<"la categoria es veterano "<<endl;
    }
}
