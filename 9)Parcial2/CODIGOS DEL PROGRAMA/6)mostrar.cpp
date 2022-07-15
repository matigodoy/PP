#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <windows.h>
using namespace std;
struct alumnos{
	char nombre[50], apellido[50];
	long int dni, legajo;
	short int reservado;
	int numero, reservado_hora, reservado_minutos, reservado_dia, reservado_mes, reservado_anio, reservado_numero;
}alum;
struct profesores{
	char nombre[50], apellido[50];
	long int dni;	
	short int reservado;
	int reservado_dni, reservado_hora, reservado_minutos, reservado_dia, reservado_mes, reservado_anio, reservado_numero;
}prof;
struct pers_admin{
	char nombre[50];
	char apellido[50];
	long int dni;
}admin;
void mostrar_alumnnos(), mostrar_profesores(), mostrar_pers_admin(), escape();
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
int main(){
	int menu;
    do{
    	system("cls");
    	SetConsoleTextAttribute(hConsole, 12);
        cout<<endl<<endl<<"\tMOSTRAR RECURSOS"<<endl<<endl;
        SetConsoleTextAttribute(hConsole, 7);
        cout<<"\t1. Mostrar alumnos "<<endl;
        cout<<"\t2. Mostrar profesores "<<endl;
        cout<<"\t3. Mostrar personal administrativo "<<endl;
        cout<<"\t4. Mostrar aulas "<<endl;
        cout<<"\t5. Mostrar libros "<<endl<<endl;
        cout<<"\t6. Volver "<<endl<<endl;
        cout<<"\tIngrese una opcion: ";
        cin>>menu;
        cout<<endl<<endl;
        switch(menu){
            case 1:
            	mostrar_alumnnos();
                break;
            case 2:
				mostrar_profesores();
				break;
			case 3:
				mostrar_pers_admin();
				break;
            case 4:
            	system("7)mostrar_aulas.exe");
				break;
			case 5:
				system("8)mostrar_libros.exe");
				break;
            case 6:
                return 0;
            default:
            	system("cls");
				SetConsoleTextAttribute(hConsole, 12);
				cout<<endl<<endl<<"\tIngrese una opcion valida "<<endl<<endl;
				SetConsoleTextAttribute(hConsole, 7);
				escape();
        }
    }while(menu!=6);
}
void mostrar_alumnnos(){
	int i=1;
    FILE *m;
    m = fopen("alumnos.dat","rb");
    if (m== NULL){
    	fclose(m);
        system("cls");
        SetConsoleTextAttribute(hConsole, 12);
        cout<<endl<<endl<<"\tNo hay alumnos registrados "<<endl<<endl;
        SetConsoleTextAttribute(hConsole, 7);
        escape();
        return;
    }
    else{
    	system("cls");
    	SetConsoleTextAttribute(hConsole, 12);
        cout<<endl<<endl<<"\tMOSTRAR ALUMNOS "<<endl<<endl;
        SetConsoleTextAttribute(hConsole, 7);
        fread(&alum, sizeof (alumnos), 1, m);
        while(feof(m)==0){
        	cout<<"\tAlumno "<<i++<<endl;
            cout<<"\tNombre: "<<alum.nombre<<endl;
            cout<<"\tApellido: "<<alum.apellido<<endl;
            cout<<"\tDNI: "<<alum.dni<<endl;
            cout<<"\tLegajo: "<<alum.legajo<<endl;
            if(alum.reservado==1){
				cout<<"\tTiene reservado el libro '"<<alum.reservado_numero<<"'"<<endl;
            	cout <<"\tHasta el "<< alum.reservado_dia << "/" << alum.reservado_mes<< " a las " << alum.reservado_hora << ":" << alum.reservado_minutos <<". "<< endl;
			}
            fread(&alum, sizeof (alumnos), 1, m);
            cout<<endl;
        }
        fclose(m);
        cout<<"\tPresione una tecla para volver al menu anterior... ";
        getch();
    }
}
void mostrar_profesores(){
	int i=1;
    FILE *m;
    m = fopen("profesores.dat","rb");
    if (m== NULL){
    	fclose(m);
        system("cls");
        SetConsoleTextAttribute(hConsole, 12);
        cout<<endl<<endl<<"\tNo hay profesores registrados "<<endl<<endl;
        SetConsoleTextAttribute(hConsole, 7);
        escape();
        return;
    }
    else{
    	system("cls");
    	SetConsoleTextAttribute(hConsole, 12);
        cout<<endl<<endl<<"\tMOSTRAR PROFESORES "<<endl<<endl;
        SetConsoleTextAttribute(hConsole, 7);
        fread(&prof, sizeof (profesores), 1, m);
        while(feof(m)==0){
        	cout<<"\tProfesor "<<i++<<endl;
            cout<<"\tNombre: "<<prof.nombre<<endl;
            cout<<"\tApellido: "<<prof.apellido<<endl;
            cout<<"\tDNI: "<<prof.dni<<endl;
            if(prof.reservado==1){
            	cout<<"\tTiene reservada el aula '"<<prof.reservado_numero<<"'"<<endl;
            	cout <<"\tHasta el "<< prof.reservado_dia << "/" << prof.reservado_mes<< " a las " << prof.reservado_hora << ":" << prof.reservado_minutos <<". "<< endl;
			}
            fread(&prof, sizeof (profesores), 1, m);
            cout<<endl;
        }
        fclose(m);
        cout<<"\tPresione una tecla para volver al menu anterior... ";
        getch();
    }
}
void mostrar_pers_admin(){
	int i=1;
    FILE *m;
    m = fopen("pers_admin.dat","rb");
    if (m== NULL){
    	fclose(m);
        system("cls");
        SetConsoleTextAttribute(hConsole, 12);
        cout<<endl<<endl<<"\tNo hay personal administrativo registrados "<<endl<<endl;
        SetConsoleTextAttribute(hConsole, 7);
        escape();
        return;
    }
    else{
    	system("cls");
    	SetConsoleTextAttribute(hConsole, 12);
        cout<<endl<<endl<<"\tMOSTRAR PERSONAL ADMINISTRATIVO "<<endl<<endl;
        SetConsoleTextAttribute(hConsole, 7);
        fread(&admin, sizeof (pers_admin), 1, m);
        while(feof(m)==0){
        	cout<<"\tPersona "<<i++<<endl;
            cout<<"\tNombre: "<<admin.nombre<<endl;
            cout<<"\tApellido: "<<admin.apellido<<endl;
            cout<<"\tDNI: "<<admin.dni<<endl;
            fread(&admin, sizeof (pers_admin), 1, m);
            cout<<endl;
        }
        fclose(m);
        cout<<"\tPresione una tecla para volver al menu anterior... ";
        getch();
    }
}
void escape(){
	int i=3;
	do{
		Sleep(200);
		cout<<"\tVolviendo al menu en "<<i<<" ..."<<endl;
		Sleep(1000);
		i--;
	}while(i!=0);
}
