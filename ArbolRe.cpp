#include "ArbolRe.h"

ArbolRe::ArbolRe(){}

ArbolRe::~ArbolRe(){}

void ArbolRe::arbolre()
{
    cu1.setValues(100, 250);
    b = cu1.matriz();

    c1.setValues(80, 40);
    c1.traslacion(50,320);
    c = c1.matriz();
    ArbolRe::juntar(b, c);

    c2.setValues(80, 35);
    c2.traslacion(50,320);
    c = c2.matriz();
    ArbolRe::juntar(b, c);

    c3.setValues(80, 30);
    c3.traslacion(50,320);
    c = c3.matriz();
    ArbolRe::juntar(b, c);

    c4.setValues(80, 25);
    c4.traslacion(50,320);
    c = c4.matriz();
    ArbolRe::juntar(b, c);

    c5.setValues(80, 20);
    c5.traslacion(50,320);
    c = c5.matriz();
    ArbolRe::juntar(b, c);

    c6.setValues(80, 15);
    c6.traslacion(50,320);
    c = c6.matriz();
    ArbolRe::juntar(b, c);


}

void ArbolRe::juntar(Matriz *m, Matriz *c)
{
    int contX = 0, contY = 0;
    int z = m->getnCol() + c->getnCol() + 2;
    b = new Matriz(3, z);
    for (int i = 0; i < c->getnFilas(); i++)
    {
        for (int j = 0; j < c->getnCol(); j++)
        {
            b->setValue(i, j, c->getValue(i, j));
            if (j == c->getnCol() - 1)
            {
                b->setValue(i, j + 1, c->getValue(i, 0));
            }
        }
    }

    for (int i = 0; i < c->getnFilas(); i++)
    {
        for (int j = c->getnCol() + 1; j < z; j++)
        {
            b->setValue(i, j, m->getValue(contX, contY));
            if (j == z - 1)
            {
                b->setValue(i, j++, m->getValue(contX, 0));
            }
            contY++;
        }
        contY = 0;
        contX++;
    }
}

void ArbolRe::print_matrix(Matriz *m)
{
    for (int i = 0; i < m->getnFilas(); i++)
    {
        for (int j = 0; j < m->getnCol(); j++)
        {
            printf("%d ", m->getValue(i, j));
        }

        printf("\n");
    }
}

void ArbolRe::traslacion(double dx, double dy)
{
    for (int i = 0; i < a->getnFilas(); i++)
    {
        for (int j = 0; j < a->getnCol(); j++)
        {
            if (i == 0 && j == 2)
                a->setValue(i, j, dx);
            else if (i == 1 && j == 2)
                a->setValue(i, j, dy);
            else if (i == 0 && j == 0 || i == 1 && j == 1 || i == 2 && j == 2)
                a->setValue(i, j, 1);
            else
                a->setValue(i, j, 0);
        }
    }
    b = a->multiplicar(b);

    // ArbolRe::draw();
}

void ArbolRe::escala(double dx)
{
    int x0 = b->getValue(0, 0);
    int y0 = b->getValue(1, 0);

    ArbolRe::traslacion(-b->getValue(0, 0), -b->getValue(1, 0));

    for (int i = 0; i < a->getnFilas(); i++)
    {
        for (int j = 0; j < a->getnCol(); j++)
        {
            if (i == 0 && j == 0)
            {
                a->setValue(i, j, dx);
            }
            else if (i == 1 && j == 1)
            {
                a->setValue(i, j, dx);
            }
            else if (i == 2 && j == 2)
            {
                a->setValue(i, j, 1);
            }
            else
            {
                a->setValue(i, j, 0);
            }
        }
    }

    b = a->multiplicar(b);

    ArbolRe::traslacion(x0, y0);

    //ArbolRe::draw();
}

void ArbolRe::rotation(int g)
{
    int x0 = b->getValue(0, 0);
    int y0 = b->getValue(1, 0);

    ArbolRe::traslacion(-b->getValue(0, 0), -b->getValue(1, 0));

    for (int i = 0; i < a->getnFilas(); i++)
    {
        for (int j = 0; j < a->getnCol(); j++)
        {
            if (i == 0 && j == 0 || i == 1 && j == 1)
            {
                a->setValue(i, j, cos(g * M_PI / 180));
            }
            else if (i == 1 && j == 0)
            {
                a->setValue(i, j, sin(g * M_PI / 180));
            }
            else if (i == 0 && j == 1)
            {
                a->setValue(i, j, -sin(g * M_PI / 180));
            }
            else if (i == 2 && j == 2)
            {
                a->setValue(i, j, 1);
            }
            else
            {
                a->setValue(i, j, 0);
            }
        }
    }

    b = a->multiplicar(b);

    ArbolRe::traslacion(x0, y0);
}

void ArbolRe::draw()
{

    int xip;
    int yip;
    int xp = 0;
    int yp = 0;
    // glClear(GL_COLOR_BUFFER_BIT);
    // glColor3f(1, 0.0, 0.0);
    for (int j = 0; j < b->getnCol(); j++)
    {

        for (int i = 0; i < b->getnFilas(); i++)
        {
            if (i == 0)
                xp = b->getValue(i, j);
            else if (i == 1)
                yp = b->getValue(i, j);
            else
            {
            }
        }

        l1.setValues(xip, yip, xp, yp);
        if (j > 0)
        {
            l1.draw();
        }
        xip = xp;
        yip = yp;
    }
}