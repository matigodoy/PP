#include <iostream>
using namespace std;
#include <ctime>
#include <windows.h>

int main() { // ===============
char* dS[7] = {"Domingo","Lunes","Martes","Miercoles","Jueves","Viernes","Sabado"};


for(int i=0;i<1000;i++){

	system("cls");
time_t tSac = time(NULL); // instante actual
struct tm* tmP = localtime(&tSac);

cout << "hh:mm:ss " << tmP->tm_hour << ":" << tmP->tm_min << ":"
<< tmP->tm_sec << endl;
cout << "dd-mm-aaaa: " << tmP->tm_mday << "-" << tmP->tm_mon+1 << "-"
<< tmP->tm_year+1900 << endl;
cout << "Dia de semana: " << dS[tmP->tm_wday] << endl;
cout << "Dia del año: " << tmP->tm_yday << endl;
cout << "Horario de verano: " << (tmP->tm_isdst ? "Si" : "No") << endl;
}


}
