#include <iostream>
#include <string>
using namespace std;
class Mascota
{
public:
	Mascota(string nombre, int patas);
	virtual string hablar() = 0;
private:
	string nombre;
	int patas;
};
Mascota::Mascota(string nombre, int patas):nombre(nombre),patas(patas)
{
	cout <<"acaba de nacer"<<nombre<<"con "<<patas<<"patas"<<endl;
}
class Perro : public Mascota
{
	public:
		perro(string nombre);
		string hablar();
};
Perro::Perro(string nombre):Mascota(nombre, 4)
{
}
