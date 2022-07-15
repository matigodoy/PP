#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <windows.h>
#include <ctime>
using namespace std;
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
	    m = fopen("profesores.dat","rb");
		n = fopen("temp.dat","wb");
		o = fopen("aulas.dat","rb");
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
	        fread(&prof, sizeof (profesores), 1, m);
	        while(feof(m)==0){
	        	if(dnix==prof.dni){
			        fread(&aul, sizeof (aulas), 1, o);
			        while(feof(o)==0){
			        	if(aul.numero==prof.reservado_numero){
			        		seguridad=1;
			        		system("cls");
			        		SetConsoleTextAttribute(hConsole, 12);
					        cout<<endl<<endl<<"\tTiene reservada el aula "<<prof.reservado_numero<<endl<<endl;
					        SetConsoleTextAttribute(hConsole, 7);
			        		do{
					            cout<<"\tQuieres eliminar la reserva? (1. para si - 0. para no): ";
					            cin>>otro;
					            if(otro<0 || otro>1)cout<<"\tSe pide 1 o 0 "<<endl;
					        }while(otro<0 || otro>1);
							if(otro==1){
								aul.reservado=0;
								fwrite(&aul,sizeof(aulas),1,p);
								prof.reservado=0;
								fwrite(&prof,sizeof(profesores),1,n);
							}
						}
						if(aul.numero!=prof.reservado_numero){
							fwrite(&aul,sizeof(aulas),1,p);
						}
						fread(&aul, sizeof (aulas), 1, o);
					}
				}
				if(dnix!=prof.dni){
	        		fwrite(&prof,sizeof(profesores),1,n);
				}
	        	fread(&prof, sizeof (profesores), 1, m);
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
				remove("profesores.dat");
		    	rename("temp.dat","profesores.dat");
		    	remove("aulas.dat");
		    	rename("temp2.dat","aulas.dat");
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
    cout<<endl<<endl<<"\tELIMINAR RESERVA DE AULAS "<<endl<<endl;
    SetConsoleTextAttribute(hConsole, 7);
	cout<<"\tIngrese su DNI para continuar: ";
	cin>>dnix;
    FILE *m;
    m = fopen("profesores.dat","rb");
    if (m== NULL){
    	fclose(m);
        system("cls");
        cout<<endl<<endl<<"\tError en el archivo "<<endl<<endl;
        return;
    }
    else{
        fread(&prof, sizeof (profesores), 1, m);
        while(feof(m)==0){
        	if(dnix==prof.dni){
	        	strcpy(apellidox,prof.apellido);
				strcpy(nombrex,prof.nombre);
				seguridad0=1;
			}
            fread(&prof, sizeof (profesores), 1, m);
        }
        fclose(m);
        if(seguridad0==0){
        	system("cls");
	        SetConsoleTextAttribute(hConsole, 12);
	        cout<<endl<<endl<<"\tEl DNI ingresado no corresponde a un profesor "<<endl<<endl;
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
