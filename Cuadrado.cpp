#include "Cuadrado.h"

Cuadrado::Cuadrado(){}

Cuadrado::~Cuadrado(){}

void Cuadrado::setValues(int x1,int y1, int x2, int y2, int x3, int y3,int x4, int y4)
{
    l1.setValues(x1,y1,x2,y2);
    l2.setValues(x2,y2,x3,y3);
    l3.setValues(x3,y3,x4,y4);
    l4.setValues(x4,y4,x1,y1);
}


void Cuadrado::setValues(Punto p1, Punto p2, Punto p3, Punto p4)
{
    l1.setValues(p1,p2);
    l2.setValues(p2,p3);
    l3.setValues(p3,p4);
    l4.setValues(p4,p1);
}

void Cuadrado::calcular(int x1, int y1)
{
    p1.setValues(0,0);
    p2.setValues(x1,p1.getY());
    p3.setValues(x1,y1);
    p4.setValues(p1.getX(),y1);
}

void Cuadrado::setValues(int x1, int y1)
{
    Cuadrado::calcular(x1,y1);
    Cuadrado::setValues(p1,p2,p3,p4);
}



void Cuadrado::draw()
{
    l1.draw();
    l2.draw();
    l3.draw();
    l4.draw();
}
