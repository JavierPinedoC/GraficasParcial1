#ifndef ARBOL_H
#define ARBOL_H
#include "Matriz.h"
#include "Cuadrado.h"
#include "Triangulo.h"
#include "Matriz.h"


class Arbol
{
private:
    Cuadrado cu;
    Linea l1;
    Triangulo tr;
    Matriz *a = new Matriz(3, 3);
	Matriz *b = new Matriz(3, 3);
    Matriz *c = new Matriz(3, 3);
    Punto p1,p2,p3,p4;
public:
    Arbol();
    ~Arbol();
    void arbol();
    void print_matrix(Matriz *m);
    void juntar(Matriz *m, Matriz *c);
    void traslacion(double, double);
	void escala(double);
	void rotation(int);
    void draw();
};
#endif

