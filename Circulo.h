#ifndef CIRCULO_H
#define CIRCULO_H

#include "Linea.h"
#include "Matriz.h"

class Circulo
{
private:
	Punto p1, p2, p0;
	Linea l1;
	Matriz *a = new Matriz(3, 3);
	Matriz *b = new Matriz(3, 3);
	Matriz *c = new Matriz(3, 4);

public:
	Circulo();
	~Circulo();
	void setValues(int, int);
	void setValues(int, int, int, int);
	void traslacion(double, double);
	void escala(double);
	void rotation(int);
	void iniciarM();
	void draw();
};
#endif