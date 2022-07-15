#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits>
#include<string.h>

using namespace std;

struct hora_inicio
{
    int hora_i,minutos_i,segundos_i,hora_f,minutos_f,segundos_f;
};
struct duracion_neta
{
    int horasd,minutosd,segundosd;
};
int leer_horai();
int leer_minutosi();
int leer_segundosi();
int leer_horaf();
int leer_minutosf();
int leer_segundosf();
void cargar_horai(hora_inicio v1[100],int n);
void cargar_horaf(hora_inicio v1[100],int n);
void h_m_s(hora_inicio v1[100],duracion_neta v2[200],int n);
void horas(hora_inicio v1[100],duracion_neta v2[100],int n);
void minutos(hora_inicio v1[100],duracion_neta v2[100],int n);
int main ()
{
    hora_inicio v1[100];
    duracion_neta v2[100];
    int n = 0;
    int opc;
    do
    {
        cout<<"\n\n\t\t\t\t\t.___  ___.  _______ .__   __.  __    __ "<<endl;
        cout<<"\t\t\t\t\t|   \\/   | |   ____||  \\ |  | |  |  |  | "<<endl;
        cout<<"\t\t\t\t\t|  \\  /  | |  |__   |   \\|  | |  |  |  | "<<endl;
        cout<<"\t\t\t\t\t|  |\\/|  | |   __|  |  . `  | |  |  |  | "<<endl;
        cout<<"\t\t\t\t\t|  |  |  | |  |____ |  |\\   | |  `--'  | "<<endl;
        cout<<"\t\t\t\t\t|__|  |__| |_______||__| \\__|  \\______/  "<<endl;
        cout<<"\n\n\tSELECCIONE LA ACCION A RELAIZAR:"<<endl;
        cout<<"\t\t\t\t\t 1-CARGAR HORA INICIAL Y FINAL"<<endl;
        cout<<"\t\t\t\t\t 2-CALCULAR DURACION NETA EN HORAS,MINUTOS Y SEGUNDOS"<<endl;
        cout<<"\t\t\t\t\t 3-CALCULAR DURACION NETA EN HORAS"<<endl;
        cout<<"\t\t\t\t\t 4-CALCULAR DURACION NETA EN MINUTOS"<<endl;
        cout<<"\t\t\t\t\t 5-SALIR"<<endl;
        cout<<"\t\t\t\t\t OPCION: ";
        cin>>opc;
        system("cls");
        
        switch(opc)
        {
            case 1:
                cargar_horai(v1, n);
                cargar_horaf(v1, n);
                break;
            case 2:
                h_m_s(v1,v2, n);
                break;
            case 3:
                horas(v1,v2, n);
                break;
            case 4:
                minutos(v1,v2, n);
                break;
            case 5: exit(1);
                break;
        }
    }
    while ( opc != 5 );
    cout << endl << endl;
    
    system("pause");
    
    return 0;
}
int leer_horai()
{
    int c;
    
    do
    {
        cout<<"INGRESE LA HORA INICIAL"<<endl;
        cout<<"COMIENCE INGRESANDO LAS HORAS: ";
        cin>>c;
        if (c < 0) cout << "ERROR, CARGUE UN NUMERO DISTINTO DE 0." << endl;
    }
    while (c < 0);
    return c;
}
int leer_minutosi()
{
    int c = 0;
    
    do
    {
        cout<<"MINUTOS: ";
        cin>>c;
        if (c < 0) cout << "ERROR, CARGUE UN NUMERO DISTINTO DE 0." << endl;
    }
    while (c < 0);
    return c;
}
int leer_segundosi()
{
    int c = 0;
    
    do
    {
        cout<<"SEGUNDOS: ";
        cin>>c;
        if (c < 0) cout << "ERROR, CARGUE UN NUMERO DISTINTO DE 0." << endl;
    }
    while (c < 0);
    return c;
}
int leer_horaf()
{
    int c;
    
    do
    {
        cout<<"INGRESE LA HORA FINAL"<<endl;
        cout<<"COMIENCE INGRESANDO LAS HORAS: ";
        cin>>c;
        if (c < 0) cout << "ERROR, CARGUE UN NUMERO DISTINTO DE 0." << endl;
    }
    while (c < 0);
    return c;
}
int leer_minutosf()
{
    int c = 0;
    
    do
    {
        cout<<"MINUTOS: ";
        cin>>c;
        if (c < 0) cout << "ERROR, CARGUE UN NUMERO DISTINTO DE 0." << endl;
    }
    while (c < 0);
    return c;
}
int leer_segundosf()
{
    int c = 0;
    
    do
    {
        cout<<"SEGUNDOS: ";
        cin>>c;
        if (c < 0) cout << "ERROR, CARGUE UN NUMERO DISTINTO DE 0." << endl;
    }
    while (c < 0);
    return c;
}
void cargar_horai(hora_inicio v1[100],int n)
{
    n = 1;
    for(int i=0;i<n;i++)
    {
        v1[i].hora_i = leer_horai();
        v1[i].minutos_i = leer_minutosi();
        v1[i].segundos_i = leer_segundosi();
        //cout<<v1[i].hora_i<<" - "<<v1[i].minutos_i<<" - "<<v1[i].segundos_i;
    }
    system("cls");
}
void cargar_horaf(hora_inicio v1[100],int n)
{
    n = 1;
    for(int i=0;i<n;i++)
    {
        v1[i].hora_f = leer_horaf();
        v1[i].minutos_f = leer_minutosf();
        v1[i].segundos_f = leer_segundosf();
    }
    system("cls");
}
void h_m_s(hora_inicio v1[100],duracion_neta v2[100],int n)
{
    int i=0;
    v2[i].horasd = (v1[i].hora_f - v1[i].hora_i);
    v2[i].minutosd = (v1[i].minutos_f - v1[i].minutos_i);
    v2[i].segundosd = (v1[i].segundos_f - v1[i].segundos_i);
    cout<<"\n\n\tDURACION NETA: "<<v2[i].horasd<<" horas "<<v2[i].minutosd<<" minutos "<<v2[i].segundosd<<" segundos"<<endl;
    cout<<"\n\n"<<endl;
    system("pause");
    system("cls");
}
void horas(hora_inicio v1[100],duracion_neta v2[100],int n)
{
    int i=0;
    v2[i].horasd = v1[i].hora_f - v1[i].hora_i;
    v2[i].minutosd = (v1[i].minutos_f - v1[i].minutos_i)/60;
    v2[i].segundosd = (v1[i].segundos_f - v1[i].segundos_i)/120;
    cout<<"\n\n\tDURACION NETA EN HORAS: "<<(v2[i].horasd + v2[i].minutosd + v2[i].segundosd)<<" horas "<<endl;
    cout<<"\n\n"<<endl;
    system("pause");
    system("cls");
}
void minutos(hora_inicio v1[100],duracion_neta v2[100],int n)
{
    int i=0;
    v2[i].horasd = (v1[i].hora_f - v1[i].hora_i)*60;
    v2[i].minutosd = (v1[i].minutos_f - v1[i].minutos_i);
    v2[i].segundosd = (v1[i].segundos_f - v1[i].segundos_i)/60;
    cout<<"\n\n\tDURACION NETA EN MINUTOS: "<<(v2[i].horasd + v2[i].minutosd + v2[i].segundosd)<<" minutos "<<endl;
    cout<<"\n\n"<<endl;
    system("pause");
    system("cls");
}
