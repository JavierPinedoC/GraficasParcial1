#ifndef ARBOLRE_h
#define ARBOLRE_h
#include "Circulo.h"
#include "Triangulo.h"
#include "Cuadrado.h"
class ArbolRe
{
private:
    Linea l1;
    Circulo c1,c2,c3,c4,c5,c6;
    Cuadrado cu1, cu2, cu3, cu4;
    Matriz *a = new Matriz(3, 3);
    Matriz *b = new Matriz(3, 3);
    Matriz *c = new Matriz(3, 3);

public:
    ArbolRe(/* args */);
    ~ArbolRe();
    void arbolre();
    void print_matrix(Matriz *m);
    void juntar(Matriz *m, Matriz *c);
    void traslacion(double, double);
    void escala(double);
    void rotation(int);
    void draw();
};
#endif