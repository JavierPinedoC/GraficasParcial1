#ifndef TRIANGULO_H
#define TRIANGULO_H
#include "Linea.h"

class Triangulo
{
private:
Punto p1,p2,p3;
Linea l1,l2,l3;

public:
	Triangulo();
	~Triangulo();
	void setValues(int,int,int,int,int,int);
	void setValues(Punto, Punto, Punto);
	void draw();
};
#endif