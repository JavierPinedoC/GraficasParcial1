#ifndef CUADRADO_H
#define CUADRADO_H

#include "Linea.h"
class Cuadrado
{
private:
Punto p1,p2,p3,p4;
Linea l1,l2,l3,l4;

public:
	Cuadrado();
	~Cuadrado();
	void setValues(int,int,int,int,int,int,int,int);
	void setValues(int,int);
	void calcular(int,int);
	void setValues(Punto, Punto, Punto, Punto);
	void draw();
};
#endif