#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <windows.h>
#include <ctime>
using namespace std;
struct alumnos{
	char nombre[50], apellido[50];
	long int dni, legajo;
	short int reservado;
	int numero, reservado_hora, reservado_minutos, reservado_dia, reservado_mes, reservado_anio, reservado_numero;
}alum;
struct biblioteca{
	char titulo[50], reservado_nombre[50], reservado_apellido[50];
	long int codigo;
	short int reservado;
	int DNI;
}biblio;
void ingresar(), escape();
char nombrex[50],apellidox[50];
int dnix;
short int seguridad0=0;
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
int main(){
	ingresar();
	if(seguridad0==1){
		FILE *m;
		FILE *n;
		FILE *o;
		FILE *p;
	    m = fopen("alumnos.dat","rb");
		n = fopen("temp.dat","wb");
		o = fopen("libros.dat","rb");
		p = fopen("temp2.dat","wb");
	    if (m== NULL || n==NULL || o==NULL || p==NULL){
	    	fclose(m);
	    	fclose(n);
	    	fclose(o);
	    	fclose(p);
	        system("cls");
	        SetConsoleTextAttribute(hConsole, 12);
	        cout<<endl<<endl<<"\tError en el archivo "<<endl<<endl;
	        SetConsoleTextAttribute(hConsole, 7);
	        escape();
	        return 0;
	    }
	    else{
	    	int otro=2, seguridad=0;
	        fread(&alum, sizeof (alumnos), 1, m);
	        while(feof(m)==0){
	        	if(dnix==alum.dni){
			        fread(&biblio, sizeof (biblioteca), 1, o);
			        while(feof(o)==0){
			        	if(biblio.codigo==alum.reservado_numero){
			        		seguridad=1;
			        		system("cls");
			        		SetConsoleTextAttribute(hConsole, 12);
					        cout<<endl<<endl<<"\tTiene reservado el libro "<<alum.reservado_numero<<endl<<endl;
					        SetConsoleTextAttribute(hConsole, 7);
			        		do{
					            cout<<"\tQuieres eliminar la reserva? (1. para si - 0. para no): ";
					            cin>>otro;
					            if(otro<0 || otro>1)cout<<"\tSe pide 1 o 0 "<<endl;
					        }while(otro<0 || otro>1);
							if(otro==1){
								biblio.reservado=0;
								fwrite(&biblio,sizeof(biblioteca),1,p);
								alum.reservado=0;
								fwrite(&alum,sizeof(alumnos),1,n);
							}
						}
						if(biblio.codigo!=alum.reservado_numero){
							fwrite(&biblio,sizeof(biblioteca),1,p);
						}
						fread(&biblio, sizeof (biblioteca), 1, o);
					}
				}
				if(dnix!=alum.dni){
	        		fwrite(&alum,sizeof(alumnos),1,n);
				}
	        	fread(&alum, sizeof (alumnos), 1, m);
	        }
	        fclose(m);
			fclose(n);
	    	fclose(o);
			fclose(p);
	    	if(otro==0){
				remove("temp.dat");
				remove("temp2.dat");
				return 0;
			}
			if(otro==1){
				remove("alumnos.dat");
		    	rename("temp.dat","alumnos.dat");
		    	remove("libros.dat");
		    	rename("temp2.dat","libros.dat");
		    	system("cls");
		        SetConsoleTextAttribute(hConsole, 12);
		        cout<<endl<<endl<<"\tSe ha eliminado la reserva con exito "<<endl<<endl;
		        SetConsoleTextAttribute(hConsole, 7);
		        escape();
		        return 0;
			}
			if(seguridad==0){
				remove("temp.dat");
				remove("temp2.dat");
				system("cls");
				SetConsoleTextAttribute(hConsole, 12);
		        cout<<endl<<endl<<"\tNo se registro una reserva a su nombre "<<endl<<endl;
		        SetConsoleTextAttribute(hConsole, 7);
		        escape();
		        return 0;
			}
	    }
	}
}
void ingresar(){
	seguridad0=0;
	system("cls");
	SetConsoleTextAttribute(hConsole, 12);
    cout<<endl<<endl<<"\tELIMINAR RESERVA DE LIBROS "<<endl<<endl;
    SetConsoleTextAttribute(hConsole, 7);
	cout<<"\tIngrese su DNI para continuar: ";
	cin>>dnix;
    FILE *m;
    m = fopen("alumnos.dat","rb");
    if (m== NULL){
    	fclose(m);
        system("cls");
        cout<<endl<<endl<<"\tError en el archivo "<<endl<<endl;
        return;
    }
    else{
        fread(&alum, sizeof (alumnos), 1, m);
        while(feof(m)==0){
        	if(dnix==alum.dni){
	        	strcpy(apellidox,alum.apellido);
				strcpy(nombrex,alum.nombre);
				seguridad0=1;
			}
            fread(&alum, sizeof (alumnos), 1, m);
        }
        fclose(m);
        if(seguridad0==0){
        	system("cls");
	        SetConsoleTextAttribute(hConsole, 12);
	        cout<<endl<<endl<<"\tEl DNI ingresado no corresponde a un alumno "<<endl<<endl;
	        SetConsoleTextAttribute(hConsole, 7);
	        escape();
	        return;
		}
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
