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
void buscar_libro(), reservar_libro(), confirmar(), escape();
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
int num_libro,dnix,hora,minutos,dia,mes,anio,confirm;
char nombrex[50],apellidox[50];
int main(){
	int menu;
    do{
    	system("cls");
    	SetConsoleTextAttribute(hConsole, 12);
        cout<<endl<<endl<<"\tRESERVAR LIBROS "<<endl<<endl;
        SetConsoleTextAttribute(hConsole, 7);
        cout<<"\t1. Ver libros cargadas "<<endl;
        cout<<"\t2. Reservar libro "<<endl<<endl;
        cout<<"\t3. Volver "<<endl<<endl;
        cout<<"\tIngrese una opcion: ";
        cin>>menu;
        cout<<endl<<endl;
        switch(menu){
            case 1:
            	system("6.2)mostrar_libros.exe");
				break;
			case 2:
				reservar_libro();
				break;
            case 3:
                return 0;
            default:
            	system("cls");
				SetConsoleTextAttribute(hConsole, 12);
				cout<<endl<<endl<<"\tIngrese una opcion valida "<<endl<<endl;
				SetConsoleTextAttribute(hConsole, 7);
				escape();
        }
    }while(menu!=3);
}
void reservar_libro(){
	system("cls");
	SetConsoleTextAttribute(hConsole, 12);
    cout<<endl<<endl<<"\tRESERVAR LIBROS "<<endl<<endl;
    SetConsoleTextAttribute(hConsole, 7);
	cout<<"\tIngrese su DNI para continuar: ";
	cin>>dnix;
	confirm=0;
	confirmar();
	if(confirm==0){
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
	    	short int seguridad0=0;
	        fread(&alum, sizeof (alumnos), 1, m);
	        while(feof(m)==0){
	        	if(dnix==alum.dni){
	        		strcpy(nombrex,alum.nombre);
	        		strcpy(apellidox,alum.apellido);
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
			if(seguridad0==1){
				system("cls");
				int num_libro;
				SetConsoleTextAttribute(hConsole, 12);
			    cout<<endl<<endl<<"\tRESERVAR LIBROS "<<endl<<endl;
			    SetConsoleTextAttribute(hConsole, 7);
			    cout<<"\tIngrese el numero del libro que quiere reservar: ";
			    cin>>num_libro;
			    m = fopen("libros.dat","rb");
			    if (m== NULL){
			    	fclose(m);
			        system("cls");
			        SetConsoleTextAttribute(hConsole, 12);
			        cout<<endl<<endl<<"\tError en el archivo "<<endl<<endl;
			        SetConsoleTextAttribute(hConsole, 7);
			        escape();
			    	return;
			    }
			    else{
			    	short int seguridad1=0,seguri1=0;
			    	fread(&biblio, sizeof (biblioteca), 1, m);
				    while(feof(m)==0){
				    	if(biblio.codigo==num_libro){
				    		seguri1=1;
				    		if(biblio.reservado==0){
				    			seguridad1=1;
				    		}
						}
						fread(&biblio, sizeof (biblioteca), 1, m);
				    }
				    fclose(m);
				    if(seguri1==0){
				    	system("cls");
				        SetConsoleTextAttribute(hConsole, 12);
				        cout<<endl<<endl<<"\tEl numero '"<<num_libro<<"' no corresponde a un libro "<<endl<<endl;
				        SetConsoleTextAttribute(hConsole, 7);
				        escape();
				        return;
					}
				    if(seguridad1==0){
				    	system("cls");
				        SetConsoleTextAttribute(hConsole, 12);
				        cout<<endl<<endl<<"\tEl libro '"<<num_libro<<"' ya se encuentra reservado "<<endl<<endl;
				        SetConsoleTextAttribute(hConsole, 7);
				        escape();
				        return;
					}
					if(seguridad1==1){
						int continuar;
						time_t tSac = time(NULL); // instante actual
						struct tm* tmP = localtime(&tSac);
						hora=tmP->tm_hour;minutos=tmP->tm_min;  // HORA
						dia=tmP->tm_mday+1;mes=tmP->tm_mon+1;anio=tmP->tm_year+1900; // FECHA
						system("cls");
						SetConsoleTextAttribute(hConsole, 12);
						cout<<endl<<endl<<"\tSe reservara el libro '"<<num_libro<<"'"<<endl<<endl;
						SetConsoleTextAttribute(hConsole, 7);
						cout <<"\tHasta el "<< dia << "-" << mes<< " a las " << hora << ":" << minutos <<". "<< endl;
						cout<<"\tA nombre de "<<nombrex<<" "<<apellidox<<" (DNI: "<<dnix<<")"<<endl;
						do{
							cout<<endl<<"\tQuieres reservar? (1. para si - 0. para no): ";
					        cin>>continuar;
					    	if(continuar<0 || continuar>1)cout<<"\tSe pide 1 o 0 "<<endl;
					    }while(continuar<0 || continuar>1);
					    if(continuar==0){
					    	system("cls");
					        SetConsoleTextAttribute(hConsole, 12);
					        cout<<endl<<endl<<"\tCancelando reserva "<<endl<<endl;
					        SetConsoleTextAttribute(hConsole, 7);
					        escape();
					        return;
					    }
					    if(continuar==1){
					        m = fopen("libros.dat","rb");
					        FILE *n;
					        n = fopen("temp.dat","wb");
					    	if (m== NULL || n== NULL){
						    	fclose(m);
						    	fclose(n);
						    	remove("temp.dat");
						        system("cls");
						        SetConsoleTextAttribute(hConsole, 12);
						        cout<<endl<<endl<<"\tError en el archivo "<<endl<<endl;
						        SetConsoleTextAttribute(hConsole, 7);
						        escape();
					        	return;
						    }
						    else{
						    	int seguridad2=0;
						    	fread(&biblio, sizeof (biblioteca), 1, m);
						        while(feof(m)==0){
						        	if(biblio.codigo==num_libro && biblio.reservado==0){
						        		biblio.reservado=1;
						        		strcpy(biblio.reservado_nombre,nombrex);
						        		strcpy(biblio.reservado_apellido,apellidox);
						        		fwrite(&biblio,sizeof(biblioteca),1,n);
						        		seguridad2=1;
						        	}
						        	if(biblio.codigo!=num_libro){
						        		fwrite(&biblio,sizeof(biblioteca),1,n);
						        	}
						        	fread(&biblio, sizeof (biblioteca), 1, m);
						        }
						        fclose(m);
								fclose(n);
						        if(seguridad2==0){
								    remove("temp.dat");
								    system("cls");
								    cout<<endl<<endl;
						        	escape();
						        	return;
								}
								if(seguridad2==1){
								    remove("libros.dat");
								    rename("temp.dat","libros.dat");
								    m = fopen("alumnos.dat","rb");
								    n = fopen("temp2.dat","wb");
								    if (m== NULL || n== NULL){
								    	fclose(m);
								    	fclose(n);
								    	remove("temp2.dat");
								        system("cls");
								        SetConsoleTextAttribute(hConsole, 12);
								        cout<<endl<<endl<<"\tError en el archivo "<<endl<<endl;
								        SetConsoleTextAttribute(hConsole, 7);
								        return;
								    }
									else{
								    	fread(&alum, sizeof (alumnos), 1, m);
								    	while(feof(m)==0){
											if(dnix==alum.dni){
												alum.reservado_numero=num_libro;
												alum.reservado=1;
									        	alum.reservado_hora=hora;
												alum.reservado_minutos=minutos;
												alum.reservado_dia=dia;
												alum.reservado_mes=mes;
												alum.reservado_anio=anio;
												fwrite(&alum,sizeof(alumnos),1,n);
											}
											if(dnix!=alum.dni){
												fwrite(&alum,sizeof(alumnos),1,n);
											}
											fread(&alum, sizeof (alumnos), 1, m);
										}
										fclose(m);
									    fclose(n);
										remove("alumnos.dat");
										rename("temp2.dat","alumnos.dat");
									}
									system("cls");
							        SetConsoleTextAttribute(hConsole, 12);
							        cout<<endl<<endl<<"\tSe ha reservado el libro '"<<num_libro<<"' con exito "<<endl<<endl;
							        SetConsoleTextAttribute(hConsole, 7);
								    escape();
								}
						    }
						}
					}
			    }
			}
		}
	}
}
void confirmar(){
	FILE *m;
	FILE *o;
    m = fopen("alumnos.dat","rb");
	o = fopen("libros.dat","rb");
    if (m== NULL || o==NULL){
    	fclose(m);
    	fclose(o);
        system("cls");
        SetConsoleTextAttribute(hConsole, 12);
        cout<<endl<<endl<<"\tError en el archivo "<<endl<<endl;
        SetConsoleTextAttribute(hConsole, 7);
        escape();
        return;
    }
    else{
    	confirm=0;
        fread(&alum, sizeof (alumnos), 1, m);
        while(feof(m)==0){
        	if(dnix==alum.dni){
		        fread(&biblio, sizeof (biblioteca), 1, o);
		        while(feof(o)==0){
		        	if(biblio.codigo==alum.reservado_numero){
		        		confirm=1;
		        		system("cls");
		        		SetConsoleTextAttribute(hConsole, 12);
				        cout<<endl<<endl<<"\tTiene reservado el libro "<<alum.reservado_numero<<". Para continuar, elimine la reserva "<<endl;
				        SetConsoleTextAttribute(hConsole, 7);
				        Sleep(1000);
					}
					fread(&biblio, sizeof (biblioteca), 1, o);
				}
			}
        	fread(&alum, sizeof (alumnos), 1, m);
        }
        fclose(m);
    	fclose(o);
    	if(confirm==1){
    		cout<<endl;
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
