#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;

struct registro{
	long int Nro;
	char Nom[30];
	short int Tipo, Categ;
	float Monto, MontoActuali;
}reg;

int main(){
	int i1=0, i2=0, i3=0, i4=0, i5=0;
	float total1=0, total2=0, total3=0, total4=0, total5=0;
    FILE *m;
    m = fopen("Maestro.dat","rb");
    if (m== NULL){
        cout<<"Error al abrir el archivo ";
        cout<<"Presione una tecla... ";
        exit(1);
    }
    else{
        fread(&reg, sizeof (registro), 1, m);
        while(feof(m)==0){
        	if(reg.Tipo==1 && reg.Categ==1){
        		i1++;
        		total1=total1+reg.MontoActuali;
			}
            if(reg.Tipo==1 && reg.Categ==2){
        		i2++;
        		total2=total2+reg.MontoActuali;
			}
            if(reg.Tipo==1 && reg.Categ==3){
        		i3++;
        		total3=total3+reg.MontoActuali;
			}
            if(reg.Tipo==2 && reg.Categ==1){
        		i4++;
        		total4=total4+reg.MontoActuali;
			}
            if(reg.Tipo==2 && reg.Categ==2){
        		i5++;
        		total5=total5+reg.MontoActuali;
			}
            fread(&reg, sizeof (registro), 1, m);
        }
        fclose(m);
        cout<<"El promedio de los montos actualizados en los depositos a corto plazo, es: $"<<total1/i1<<endl;
        cout<<"El promedio de los montos actualizados en los depositos a mediano plazo, es: $"<<total2/i2<<endl;
        cout<<"El promedio de los montos actualizados en los depositos a largo plazo, es: $"<<total3/i3<<endl;
        cout<<"El promedio de los montos actualizados en los creditos a industriales o comerciables, es: $"<<total4/i4<<endl;
        cout<<"El promedio de los montos actualizados en los creditos a particulares, es: $"<<total5/i5<<endl;
    }
}
