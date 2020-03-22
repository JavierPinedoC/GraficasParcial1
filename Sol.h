#ifndef SOL_H
#define SOL_H

#include "Circulo.h"
#include "Triangulo.h"

class Sol
{
private:
    Punto p1, p2, p3;
    Linea l1;
    Circulo c1;
    Triangulo t1, t2, t3, t4, t5, t6, t7;
    Matriz *a = new Matriz(3, 3);
    Matriz *b = new Matriz(3, 3);
    Matriz *c = new Matriz(3, 3);

public:
    Sol();
    ~Sol();
    void sol();
    void print_matrix(Matriz *m);
    void juntar(Matriz *m, Matriz *c);
    void traslacion(double, double);
    void escala(double);
    void rotation(int);
    void draw();
};
#endif
