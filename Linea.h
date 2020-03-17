
#ifndef LINE_H
#define LINE_H
/*
EJEMPLO DE LA DECLARACION DE CLASES EN C++
CURSO GRAFICACION POR COMPUTADORA
IVAN OLMOS PINEDA
*/

#include "Punto.h"

class Linea
{
private:
	Punto p1, p2;

public:
	Linea();
	~Linea();
	void setValues(int, int, int, int);
	void setValues(Punto, Punto);
	void draw();
};
#endif