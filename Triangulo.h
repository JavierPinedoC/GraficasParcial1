#ifndef TRIANGULO_H
#define TRIANGULO_H
#include "Linea.h"
#include "Matriz.h"

class Triangulo
{
private:
	Punto p1, p2, p3;
	Linea l1, l2, l3;
	Matriz *a = new Matriz(3, 3);
	Matriz *b = new Matriz(3, 3);
	Matriz *c = new Matriz(3, 3);

public:
	Triangulo();
	~Triangulo();
	void setValues(int, int, int, int, int, int);
	void setValues(Punto, Punto, Punto);
	void iniciarM(Punto, Punto, Punto);
	void traslacion(double, double);
	void escala(double);
	void rotation(int);
	void print_matrix(Matriz *m);
	Matriz *matriz();
	void draw();
};
#endif

