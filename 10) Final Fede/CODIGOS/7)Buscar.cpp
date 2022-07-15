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
struct aulas{
	int numero, sillas, mesas;
	short int proyector, reservado;
	char reservado_nombre[50], reservado_apellido[50];
}aul;
struct biblioteca{
	char titulo[50], reservado_nombre[50], reservado_apellido[50];
	long int codigo;
	short int reservado;
	int DNI;
}biblio;
void mostrar_alumnnos(), mostrar_profesores(), mostrar_aulas(), mostrar_libros(), escape();
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
int main(){
	int menu;
    do{
    	system("cls");
    	SetConsoleTextAttribute(hConsole, 12);
        cout<<endl<<endl<<"\tBUSCAR RECURSOS"<<endl<<endl;
        SetConsoleTextAttribute(hConsole, 7);
        cout<<"\t1. Buscar alumnos "<<endl;
        cout<<"\t2. Buscar profesores "<<endl;
        cout<<"\t3. Buscar aulas "<<endl;
        cout<<"\t4. Buscar libros "<<endl<<endl;
        cout<<"\t5. Volver "<<endl<<endl;
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
            	mostrar_aulas();
				break;
			case 4:
				mostrar_libros();
				break;
            case 5:
                return 0;
            default:
            	system("cls");
				SetConsoleTextAttribute(hConsole, 12);
				cout<<endl<<endl<<"\tIngrese una opcion valida "<<endl<<endl;
				SetConsoleTextAttribute(hConsole, 7);
				escape();
        }
    }while(menu!=5);
}
void mostrar_alumnnos(){
    FILE *m;
    m = fopen("alumnos.dat","rb");
    if (m== NULL){
    	fclose(m);
        system("cls");
        SetConsoleTextAttribute(hConsole, 12);
        cout<<endl<<endl<<"\tNo hay alumnos registrados. "<<endl<<endl;
        SetConsoleTextAttribute(hConsole, 7);
        escape();
        return;
    }
    else{
    	int dni=0;
    	short int seguridad=0;
    	system("cls");
    	SetConsoleTextAttribute(hConsole, 12);
        cout<<endl<<endl<<"\tBUSCAR ALUMNO "<<endl<<endl;
        SetConsoleTextAttribute(hConsole, 7);
    	cout<<"\tIngrese el DNI del alumno que quiere buscar: ";
    	cin>>dni;
    	system("cls");
    	SetConsoleTextAttribute(hConsole, 12);
        cout<<endl<<endl<<"\tMOSTRAR ALUMNO "<<endl<<endl;
        SetConsoleTextAttribute(hConsole, 7);
        fread(&alum, sizeof (alumnos), 1, m);
        while(feof(m)==0){
        	if(dni==alum.dni){
        		seguridad=1;
		        cout<<"\tNombre: "<<alum.nombre<<endl;
		        cout<<"\tApellido: "<<alum.apellido<<endl;
		        cout<<"\tDNI: "<<alum.dni<<endl;
		        cout<<"\tLegajo: "<<alum.legajo<<endl;
		        if(alum.reservado==1){
					cout<<"\tTiene reservado el libro '"<<alum.reservado_numero<<"'"<<endl;
		        	cout <<"\tHasta el "<< alum.reservado_dia << "/" << alum.reservado_mes<< " a las " << alum.reservado_hora << ":" << alum.reservado_minutos <<". "<< endl;
				}
			}
            fread(&alum, sizeof (alumnos), 1, m);
        }
        fclose(m);
        if(seguridad==0){
        	system("cls");
	        SetConsoleTextAttribute(hConsole, 12);
	        cout<<endl<<endl<<"\tEl DNI ingresado no corresponde a un alumno. "<<endl<<endl;
	        SetConsoleTextAttribute(hConsole, 7);
	        escape();
	        return;
		}
        cout<<endl<<"\tPresione una tecla para volver al menu anterior... ";
        getch();
    }
}
void mostrar_profesores(){
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
    	int dni=0;
    	short int seguridad=0;
    	system("cls");
    	SetConsoleTextAttribute(hConsole, 12);
        cout<<endl<<endl<<"\tBUSCAR PROFESOR "<<endl<<endl;
        SetConsoleTextAttribute(hConsole, 7);
    	cout<<"\tIngrese el DNI del profesor que quiere buscar: ";
    	cin>>dni;
    	system("cls");
    	SetConsoleTextAttribute(hConsole, 12);
        cout<<endl<<endl<<"\tMOSTRAR PROFESOR "<<endl<<endl;
        SetConsoleTextAttribute(hConsole, 7);
        fread(&prof, sizeof (profesores), 1, m);
        while(feof(m)==0){
        	if(dni==prof.dni){
        		seguridad=1;
	            cout<<"\tNombre: "<<prof.nombre<<endl;
	            cout<<"\tApellido: "<<prof.apellido<<endl;
	            cout<<"\tDNI: "<<prof.dni<<endl;
	            if(prof.reservado==1){
	            	cout<<"\tTiene reservada el aula '"<<prof.reservado_numero<<"'"<<endl;
	            	cout <<"\tHasta el "<< prof.reservado_dia << "/" << prof.reservado_mes<< " a las " << prof.reservado_hora << ":" << prof.reservado_minutos <<". "<< endl;
				}
			}
            fread(&prof, sizeof (profesores), 1, m);
        }
        fclose(m);
        if(seguridad==0){
        	system("cls");
	        SetConsoleTextAttribute(hConsole, 12);
	        cout<<endl<<endl<<"\tEl DNI ingresado no corresponde a un profesor. "<<endl<<endl;
	        SetConsoleTextAttribute(hConsole, 7);
	        escape();
	        return;
		}
        cout<<endl<<"\tPresione una tecla para volver al menu anterior... ";
        getch();
    }
}
void mostrar_aulas(){
    FILE *m;
    m = fopen("aulas.dat","rb");
    if (m== NULL){
    	fclose(m);
        system("cls");
        SetConsoleTextAttribute(hConsole, 12);
        cout<<endl<<endl<<"\tNo hay aulas registradas. "<<endl<<endl;
        SetConsoleTextAttribute(hConsole, 7);
        escape();
        return;
    }
    else{
    	int num=0;
    	short int seguridad=0;
    	system("cls");
    	SetConsoleTextAttribute(hConsole, 12);
        cout<<endl<<endl<<"\tBUSCAR AULAS "<<endl<<endl;
        SetConsoleTextAttribute(hConsole, 7);
    	cout<<"\tIngrese el NUMERO del aula que quiere buscar: ";
    	cin>>num;
    	system("cls");
    	SetConsoleTextAttribute(hConsole, 12);
        cout<<endl<<endl<<"\tMOSTRAR AULA "<<endl<<endl;
        SetConsoleTextAttribute(hConsole, 7);
        fread(&aul, sizeof (aulas), 1, m);
        while(feof(m)==0){
        	if(num==aul.numero){
        		seguridad=1;
	            cout<<"\tAula: "<<aul.numero<<endl;
	            if(aul.proyector==1)cout<<"\tTiene un televisor "<<endl;
	            if(aul.proyector==2)cout<<"\tTiene un proyector "<<endl;
	            if(aul.proyector==3)cout<<"\tNo tiene televisor / proyector "<<endl;
	            cout<<"\tCantidad de sillas: "<<aul.sillas<<endl;
	            cout<<"\tCantidad de mesas: "<<aul.mesas<<endl;
	            if(aul.reservado==1)cout<<"\tEste aula se encuentra reservada por '"<<aul.reservado_nombre<<" "<<aul.reservado_apellido<<"' "<<endl;
	        }
            fread(&aul, sizeof (aulas), 1, m);
        }
        fclose(m);
        if(seguridad==0){
        	system("cls");
	        SetConsoleTextAttribute(hConsole, 12);
	        cout<<endl<<endl<<"\tEl NUMERO ingresado no corresponde a un aula. "<<endl<<endl;
	        SetConsoleTextAttribute(hConsole, 7);
	        escape();
	        return;
		}
        cout<<endl<<"\tPresione una tecla para volver al menu anterior... ";
        getch();
    }
}
void mostrar_libros(){
    FILE *m;
    m = fopen("libros.dat","rb");
    if (m== NULL){
    	fclose(m);
        system("cls");
        SetConsoleTextAttribute(hConsole, 12);
        cout<<endl<<endl<<"\tNo hay libros registrados. "<<endl<<endl;
        SetConsoleTextAttribute(hConsole, 7);
        escape();
        return;
    }
    else{
    	int num=0;
    	short int seguridad=0;
    	system("cls");
    	SetConsoleTextAttribute(hConsole, 12);
        cout<<endl<<endl<<"\tBUSCAR LIBRO "<<endl<<endl;
        SetConsoleTextAttribute(hConsole, 7);
    	cout<<"\tIngrese el CODIGO del libro que quiere buscar: ";
    	cin>>num;
    	system("cls");
    	SetConsoleTextAttribute(hConsole, 12);
        cout<<endl<<endl<<"\tMOSTRAR LIBRO "<<endl<<endl;
        SetConsoleTextAttribute(hConsole, 7);
        fread(&biblio, sizeof (biblioteca), 1, m);
        while(feof(m)==0){
        	if(num==biblio.codigo){
        		seguridad=1;
        		cout<<"\tTitulo: "<<biblio.titulo<<endl;
	        	cout<<"\tCodigo: "<<biblio.codigo<<endl;
				if(biblio.reservado==1){
					cout<<"\tReservado a nombre de "<<biblio.reservado_nombre<<" "<<biblio.reservado_apellido<<endl;
				}
			}
            fread(&biblio, sizeof (biblioteca), 1, m);
        }
        fclose(m);
        if(seguridad==0){
        	system("cls");
	        SetConsoleTextAttribute(hConsole, 12);
	        cout<<endl<<endl<<"\tEl CODIGO ingresado no corresponde a un libro. "<<endl<<endl;
	        SetConsoleTextAttribute(hConsole, 7);
	        escape();
	        return;
		}
		cout<<endl<<"\tPresione una tecla para volver al menu anterior... ";
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
