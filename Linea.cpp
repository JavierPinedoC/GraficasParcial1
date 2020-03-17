#include "Linea.h"

Linea::Linea(){}
Linea::~Linea(){}

void Linea::setValues(int x1, int y1, int x2, int y2)
{
    p1.setValues(x1, y1);
    p2.setValues(x2, y2);
}

void Linea::setValues(Punto a1, Punto a2)
{
    p1.setValues(a1.getX(),a1.getY());
    p2.setValues(a2.getX(),a2.getY());
}

void Linea::draw()
{
   int dx = p2.getX()- p1.getX();
   int dy = p2.getY() - p1.getY();
   int e;
   int incx = 1;
   int incy = 1;
   int inc1;
   int inc2;

   if(dx < 0)
        dx= -dx;
   if(dy  <0)
        dy= -dy;
    if(p2.getX() < p1.getX())
        incx= -1;
    if(p2.getY() < p1.getY())
        incy= -1;
    if(dx > dy){
        e = 2* dy - dx;
        inc1 = 2 * (dy - dx);
        inc2 = 2 * dy;
        for(int i = 0; i<= dx; i++){
            if(e >= 0){
                p1.setValues(p1.getX(), p1.getY()+incy);
                e += inc1;
            }
            else
                e += inc2;
            p1.setValues(p1.getX()+incx, p1.getY());
            p1.draw();
        }
    }
    else{
        e = 2* dx - dy;
        inc1 = 2 * (dx - dy);
        inc2 = 2 * dx;
        for(int i = 0; i<= dy; i++){
            if(e >= 0){
                p1.setValues(p1.getX()+incx, p1.getY());
                e += inc1;
            }
            else
                e += inc2;
            p1.setValues(p1.getX(), p1.getY()+incy);
            p1.draw();

        }
    }

}
