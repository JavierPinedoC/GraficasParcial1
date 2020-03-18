#ifndef CUADRADO_H
#define CUADRADO_H

#include "Linea.h"
#include "Matriz.h"


class Cuadrado
{
private:
	Punto p1, p2, p3, p4;
	Linea l1, l2, l3, l4;
	Matriz *a = new Matriz(3,3);
	Matriz *b = new Matriz(3,4);
	Matriz *c = new Matriz(3,4);


public:
	Cuadrado();
	~Cuadrado();
	void setValues(int, int, int, int, int, int, int, int);
	void setValues(int, int);
	void calcular(int, int);
	void setValues(Punto, Punto, Punto, Punto);
	void traslacion(double, double);
	void escala(double);
	void rotation(int);
	void draw();
};
#endif