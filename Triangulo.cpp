#include "Triangulo.h"

Triangulo::Triangulo(){}

Triangulo::~Triangulo(){}

void Triangulo::setValues(int x1,int y1, int x2, int y2, int x3, int y3)
{
    l1.setValues(x1,y1,x2,y2);
    l2.setValues(x2,y2,x3,y3);
    l3.setValues(x3,y3,x1,y1);
}


void Triangulo::setValues(Punto p1, Punto p2, Punto p3)
{
    l1.setValues(p1,p2);
    l2.setValues(p2,p3);
    l3.setValues(p3,p1);
}

void Triangulo::draw()
{
    l1.draw();
    l2.draw();
    l3.draw();
}
