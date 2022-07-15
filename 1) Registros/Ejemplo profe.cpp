#include<iostream>
using namespace std;

struct huesped
{
	char nom[25];
	int origen, dias, serv;
	float imp;
};

int leer_cantidad();
int leer_origen();
int leer_dias();
float leer_importe();
int leer_servicio();
void ceros (int a[3][4], int f, int c);
void mostrar_matriz (int a[3][4], int f, int c);
void leer_vector (huesped v[50], int n);
void punto_a (huesped v[50], int n, float &p0, float &p1, float &p2);
void punto_b (huesped v[50], int n);
void punto_c (huesped v[50], int n);
float punto_d (huesped v[50], int n);

int main(){
	huesped v[50];
	float p0, p1, p2;
	int n = leer_cantidad();
	leer_vector(v, n);
	punto_a(v, n, p0, p1, p2);
	cout <<endl<<endl<<"Porcentaje de huespedes de Buenos Aires "<<p0;
	cout <<endl<<"Porsentaje de huespedes de Rosario:    "<<p1;
	cout <<endl<<"Porsentaje de huespedes de Mendoza:    "<<p2;
	punto_b(v, n);
	punto_c(v, n);
	float t=punto_d(v, n);
	cout<<endl<<endl<<"Total importes de pension completa "<<t;
	cout<<endl<<endl;
	system("pause");
	return 0;
}

int leer_cantidad(){
	int c;
	do{
		cout<<"Cantidad de huespedes a cargar (mayor y menor o igual a 50):";
		cin>>c;
		if(c<=0 || c>50){
			cout<<"Se pedia mayores a 0 y no mas de 50 "<<endl;
		}
	}
	while(c<=0 || c>50);
	return c;
}

int leer_origen(){
	int c;
	do{
		cout<<"Ciudad origen (0:Bs.As. - 1:Rosario - 2:Mendoza): ";
		cin>>c;
		if(c<=0 || c>2){
			cout<<"Se pedia 0, 1 o 2 "<<endl;
		}
	}
	while(c<=0 || c>2);
	return c;
}

int leer_dias(){
	int c;
	do{
		cout<<"Cantidad de dias de estadia(mayor a 0): ";
		cin>>c;
		if(c<=0){
			cout<<"Se pedia mayor a cero "<<endl;
		}
	}
	while(c<=0);
	return c;
}

float leer_importe(){
	float c;
	do{
		cout<<"Importe a pagar(mayor a 0): ";
		cin>>c;
		if(c<=0){
			cout<<"Se pedia mayor a cero "<<endl;
		}
	}
	while(c<=0);
	return c;
}

int leer_servicio(){
	int c;
	do{
		cout<<"Tipo de servicio(0:Completo - 1:Media - 2:Desayuno - 3:Habitacion): ";
		cin>>c;
		if(c<=0 || c>3){
			cout<<"Se pedia 0, 1, 2 o 3 "<<endl;
		}
	}
	while(c<=0 || c>3);
	return c;
}

void ceros(int a[3][4], int f, int c){
	for(int i=0; i<f; i++){
		for(int j=0; i<c; j++){
			a[i][j]=0;
		}
	}
}

void mostrar_matriz(int a[3][4], int f, int c){
	cout<<endl<<endl<<"Los resultados del conteo son: ";
	for(int i=0; i<f; i++){
		for(int j=0; j<c; j++){
			cout<<endl<<"<Ciudad origen: "<<i<<"\tServicio: "<<j<<"\tCantidad:"<<a[i][j];
		}
	}
}

void leer_vector(huesped v[50], int n){
	cout<<"Ingrese los datos de los huespedes: "<<endl;
	for(int i=0;i<n;i++){
		fflush(stdin);
		cout<<"Nombre: ";
		gets(v[i].nom);
		v[i].origen=leer_origen();
		v[i].dias=leer_dias();
		v[i].imp=leer_importe();
		v[i].serv=leer_servicio();
	}
}

void punto_a(huesped v[50],int n, float &p0, float &p1, float &p2){
	float cb=0, cm=0, cr=0;
	for(int i=0; i<n; i++){
		if(v[i].origen==0){
			cb++;
		}
		else{
			if(v[i].origen==1){
				cr++;
			}
			else{
				cm++;
			}
		}
	}
	p0=(cb*100)/n;
	p1=(cr*100)/n;
	p2=(cm*100)/n;
}

void punto_b (huesped v[50], int n){
	int ind=-1;
	for(int i=0; i<n; i++){
		if (v[i].origen==1){
			if(ind==-1){
				ind=i;
			}
			else{
				if(v[i].imp>v[ind].imp)ind=i;
			}
		}
	}
	if(ind!=-1){
		cout<<endl<<endl<<"El rosarino que mas oago fue: "<<v[ind].nom;
		cout<<endl<<"Y el monto pagado fue: "<<v[ind].imp;
	}
	else{
		cout<<endl<<"No hay huespedes de Rosario ";
	}
}

void punto_c(huesped v[50], int n){
	int a[3][4];
	ceros (a, 3, 4);
	for(int i=0; i<n; i++){
		int f= v[i].origen;
		int c = v[i].serv;
		a[f][c]++;
	}
	mostrar_matriz(a, 3, 4);
}

float pubto_d(huesped v[50], int n){
	float t=0;
	for(int i=0; i<n; i++){
		if(v[i].serv == 0) t+=v[i].imp;
	}
	return t;
}
