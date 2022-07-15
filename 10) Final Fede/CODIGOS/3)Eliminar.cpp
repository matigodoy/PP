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
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
void eliminar_alumnnos(), eliminar_profesores(), eliminar_aulas(), eliminar_libros(), escape();
int main(){
	int menu;
    do{
    	system("cls");
    	SetConsoleTextAttribute(hConsole, 12);
        cout<<endl<<endl<<"\tELIMINAR RECURSOS"<<endl<<endl;
        SetConsoleTextAttribute(hConsole, 7);
        cout<<"\t1. Elimninar alumnos"<<endl;
        cout<<"\t2. Elimninar profesores"<<endl;
        cout<<"\t3. Elimninar libros"<<endl;
        cout<<"\t4. Elimninar aulas "<<endl<<endl;
        cout<<"\t5. Volver "<<endl<<endl;
        cout<<"\tIngrese una opcion: ";
        cin>>menu;
        cout<<endl<<endl;
        switch(menu){
            case 1:
            	eliminar_alumnnos();
                break;
            case 2:
				eliminar_profesores();
				break;
            case 3:
				eliminar_libros();
				break;
			case 4:
				eliminar_aulas();
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
void eliminar_alumnnos(){
	int seguridad=0, continuar=0;
	long int codigoP=0;
    system("cls");
	SetConsoleTextAttribute(hConsole, 12);
    cout<<endl<<endl<<"\tELIMINAR ALUMNO "<<endl<<endl;
    SetConsoleTextAttribute(hConsole, 7);
	cout<<"\tIngrese el DNI del alumno que deseas eliminar: ";
	cin>>codigoP;
	system("cls");
	FILE *m;
	FILE *n;
    m = fopen("alumnos.dat","rb");
    n = fopen("temp.dat","wb");
    if (m== NULL || n== NULL){
        fclose(m);
    	fclose(n);
    	remove("temp.dat");
        system("cls");
        SetConsoleTextAttribute(hConsole, 12);
        cout<<endl<<endl<<"\tNo hay alumnos registrados "<<endl<<endl;
        SetConsoleTextAttribute(hConsole, 7);
        escape();
        return;
    }
    else{
    	fread(&alum, sizeof (alumnos), 1, m);
    	while(feof(m)==0){
    		if(codigoP==alum.dni){
    			SetConsoleTextAttribute(hConsole, 12);
    			cout<<endl<<endl<<"\tLos datos del alumno a eliminar son: "<<endl<<endl;
    			SetConsoleTextAttribute(hConsole, 7);
	            cout<<"\tNombre: "<<alum.nombre<<endl;
	            cout<<"\tApellido: "<<alum.apellido<<endl;
	            cout<<"\tDNI: "<<alum.dni<<endl;
	            cout<<"\tLegajo: "<<alum.legajo<<endl;
    			seguridad=1;
    			do{
	    			cout<<endl<<"\tQuiere continuar? (1. para si - 0. para no): ";
	                cin>>continuar;
	                if(continuar<0 || continuar>1)cout<<"\t Se pide 1 o 0 "<<endl;
	            }while(continuar<0 || continuar>1);
            	if(continuar==0){
            		fclose(m);
    				fclose(n);
    				remove("temp.dat");
            		return;
				}
			}
			if(codigoP!=alum.dni){
    			fwrite(&alum,sizeof(alumnos),1,n);
			}
			fread(&alum, sizeof (alumnos), 1, m);
		}
    }
    fclose(m);
    fclose(n);
    if(continuar==1){
	    remove("alumnos.dat");
	    rename("temp.dat","alumnos.dat");
		system("cls");
		SetConsoleTextAttribute(hConsole, 12);
		cout<<endl<<endl<<"\tDATOS ELIMINADOS CORRECTAMENTE."<<endl<<endl;
		SetConsoleTextAttribute(hConsole, 7);
		escape();
	}
    if(seguridad==0){
		system("cls");
		SetConsoleTextAttribute(hConsole, 12);
		cout<<endl<<endl<<"\tEl DNI ingresado no corresponde a ningun alumno ."<<endl<<endl;
		SetConsoleTextAttribute(hConsole, 7);
		escape();
	}
}
void eliminar_profesores(){
	int seguridad=0, continuar=0;
	long int codigoP=0;
    system("cls");
	SetConsoleTextAttribute(hConsole, 12);
    cout<<endl<<endl<<"\tELIMINAR PROFESOR"<<endl<<endl;
    SetConsoleTextAttribute(hConsole, 7);
	cout<<"\tIngrese el DNI del profesor que deseas eliminar: ";
	cin>>codigoP;
	system("cls");
	FILE *m;
	FILE *n;
    m = fopen("profesores.dat","rb");
    n = fopen("temp.dat","wb");
    if (m== NULL || n== NULL){
        fclose(m);
    	fclose(n);
    	remove("temp.dat");
        system("cls");
        SetConsoleTextAttribute(hConsole, 12);
        cout<<endl<<endl<<"\tNo hay profesores registrados "<<endl<<endl;
        SetConsoleTextAttribute(hConsole, 7);
        escape();
        return;
    }
    else{
    	fread(&prof, sizeof (profesores), 1, m);
    	while(feof(m)==0){
    		if(codigoP==prof.dni){
    			SetConsoleTextAttribute(hConsole, 12);
    			cout<<endl<<endl<<"\tLos datos del profesor a eliminar son: "<<endl<<endl;
    			SetConsoleTextAttribute(hConsole, 7);
	            cout<<"\tNombre: "<<prof.nombre<<endl;
	            cout<<"\tApellido: "<<prof.apellido<<endl;
	            cout<<"\tDNI: "<<prof.dni<<endl;
    			seguridad=1;
    			do{
	    			cout<<endl<<"\tQuiere continuar? (1. para si - 0. para no): ";
	                cin>>continuar;
	                if(continuar<0 || continuar>1)cout<<"\t Se pide 1 o 0 "<<endl;
	            }while(continuar<0 || continuar>1);
            	if(continuar==0){
            		fclose(m);
    				fclose(n);
    				remove("temp.dat");
            		return;
				}
			}
			if(codigoP!=prof.dni){
    			fwrite(&prof,sizeof(profesores),1,n);
			}
			fread(&prof, sizeof (profesores), 1, m);
		}
    }
    fclose(m);
    fclose(n);
    if(continuar==1){
	    remove("profesores.dat");
	    rename("temp.dat","profesores.dat");
		system("cls");
		SetConsoleTextAttribute(hConsole, 12);
		cout<<endl<<endl<<"\tDATOS ELIMINADOS CORRECTAMENTE."<<endl<<endl;
		SetConsoleTextAttribute(hConsole, 7);
		escape();
	}
    if(seguridad==0){
		system("cls");
		SetConsoleTextAttribute(hConsole, 12);
		cout<<endl<<endl<<"\tEl DNI ingresado no corresponde a ningun profesor ."<<endl<<endl;
		SetConsoleTextAttribute(hConsole, 7);
		escape();
	}
}
void eliminar_libros(){
	int seguridad=0, continuar=0;
	long int codigoP=0;
    system("cls");
	SetConsoleTextAttribute(hConsole, 12);
    cout<<endl<<endl<<"\tELIMINAR LIBRO"<<endl<<endl;
    SetConsoleTextAttribute(hConsole, 7);
	cout<<"\tIngrese el codigo del libro que deseas eliminar: ";
	cin>>codigoP;
	system("cls");
	FILE *m;
	FILE *n;
    m = fopen("libros.dat","rb");
    n = fopen("temp.dat","wb");
    if (m== NULL || n== NULL){
        fclose(m);
    	fclose(n);
    	remove("temp.dat");
        system("cls");
        SetConsoleTextAttribute(hConsole, 12);
        cout<<endl<<endl<<"\tNo hay libros registrados "<<endl<<endl;
        SetConsoleTextAttribute(hConsole, 7);
        escape();
        return;
    }
    else{
    	fread(&biblio, sizeof (biblioteca), 1, m);
    	while(feof(m)==0){
    		if(codigoP==biblio.codigo){
    			SetConsoleTextAttribute(hConsole, 12);
    			cout<<endl<<endl<<"\tLos datos del libro a eliminar son: "<<endl<<endl;
    			SetConsoleTextAttribute(hConsole, 7);
	            cout<<"\tTitulo: "<<biblio.titulo<<endl;
	            cout<<"\tCodigo: "<<biblio.codigo<<endl;
    			seguridad=1;
    			do{
	    			cout<<endl<<"\tQuiere continuar? (1. para si - 0. para no): ";
	                cin>>continuar;
	                if(continuar<0 || continuar>1)cout<<"\t Se pide 1 o 0 "<<endl;
	            }while(continuar<0 || continuar>1);
            	if(continuar==0){
            		fclose(m);
    				fclose(n);
    				remove("temp.dat");
            		return;
				}
			}
    		if(codigoP!=biblio.codigo){
    			fwrite(&biblio,sizeof(biblioteca),1,n);
			}
			fread(&biblio, sizeof (biblioteca), 1, m);
		}
    }
    fclose(m);
    fclose(n);
    if(continuar==1){
	    remove("libros.dat");
	    rename("temp.dat","libros.dat");
		system("cls");
		SetConsoleTextAttribute(hConsole, 12);
		cout<<endl<<endl<<"\tDATOS ELIMINADOS CORRECTAMENTE."<<endl<<endl;
		SetConsoleTextAttribute(hConsole, 7);
		escape();
	}
    if(seguridad==0){
		system("cls");
		SetConsoleTextAttribute(hConsole, 12);
		cout<<endl<<endl<<"\tEl codigo ingresado no corresponde a ningun libro ."<<endl<<endl;
		SetConsoleTextAttribute(hConsole, 7);
		escape();
	}
}
void eliminar_aulas(){
	int seguridad=0, continuar=0;
	long int codigoP=0;
    system("cls");
	SetConsoleTextAttribute(hConsole, 12);
    cout<<endl<<endl<<"\tELIMINAR AULAS"<<endl<<endl;
    SetConsoleTextAttribute(hConsole, 7);
	cout<<"\tIngrese el NUMERO del aula que deseas eliminar: ";
	cin>>codigoP;
	system("cls");
	FILE *m;
	FILE *n;
    m = fopen("aulas.dat","rb");
    n = fopen("temp.dat","wb");
    if (m== NULL || n== NULL){
        fclose(m);
    	fclose(n);
    	remove("temp.dat");
        system("cls");
        SetConsoleTextAttribute(hConsole, 12);
        cout<<endl<<endl<<"\tNo hay aulas registradas "<<endl<<endl;
        SetConsoleTextAttribute(hConsole, 7);
        escape();
        return;
    }
    else{
    	fread(&aul, sizeof (aulas), 1, m);
    	while(feof(m)==0){
    		if(codigoP==aul.numero){
    			SetConsoleTextAttribute(hConsole, 12);
    			cout<<endl<<endl<<"\tLos datos del aula a eliminar son: "<<endl<<endl;
    			SetConsoleTextAttribute(hConsole, 7);
	            cout<<"\tNumero: "<<aul.numero<<endl;
	            if(aul.proyector==1)cout<<"\tTiene un televisor "<<endl;
	            if(aul.proyector==2)cout<<"\tTiene un proyector "<<endl;
	            if(aul.proyector==3)cout<<"\tNo tiene televisor / proyector "<<endl;
	            cout<<"\tSillas: "<<aul.sillas<<endl;
	            cout<<"\tMesas: "<<aul.mesas<<endl;
    			seguridad=1;
    			do{
	    			cout<<endl<<"\tQuiere continuar? (1. para si - 0. para no): ";
	                cin>>continuar;
	                if(continuar<0 || continuar>1)cout<<"\t Se pide 1 o 0 "<<endl;
	            }while(continuar<0 || continuar>1);
            	if(continuar==0){
            		fclose(m);
    				fclose(n);
    				remove("temp.dat");
            		return;
				}
			}
    		if(codigoP!=aul.numero){
    			fwrite(&aul,sizeof(aulas),1,n);
			}
			fread(&aul, sizeof (aulas), 1, m);
		}
    }
    fclose(m);
    fclose(n);
    int i=3;
    if(continuar==1){
	    remove("aulas.dat");
	    rename("temp.dat","aulas.dat");
		system("cls");
		SetConsoleTextAttribute(hConsole, 12);
		cout<<endl<<endl<<"\tDATOS ELIMINADOS CORRECTAMENTE."<<endl<<endl;
		SetConsoleTextAttribute(hConsole, 7);
		escape();
	}
    if(seguridad==0){
		system("cls");
		SetConsoleTextAttribute(hConsole, 12);
		cout<<endl<<endl<<"\tEl numero de aula ingresado no corresponde a ningun aula ."<<endl<<endl;
		SetConsoleTextAttribute(hConsole, 7);
		escape();  
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
