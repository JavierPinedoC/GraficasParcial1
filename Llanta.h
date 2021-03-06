#ifndef LANTA_H
#define LANTA_H
#include "Circulo.h"
class Llanta
{
private:
    Linea l1;
    Circulo c1,c2,c3,c4,c5,c6;
    Matriz *a = new Matriz(3, 3);
    Matriz *b = new Matriz(3, 3);
    Matriz *c = new Matriz(3, 3);

public:
    Llanta(/* args */);
    ~Llanta();
    void llanta();
    void print_matrix(Matriz *m);
    void juntar(Matriz *m, Matriz *c);
    void traslacion(double, double);
    void escala(double);
    void rotation(int);
    void draw();
};
#endif