#include "Sol.h"

Sol::Sol() {}

Sol::~Sol() {}

void Sol::sol()
{
    c1.setValues(360, 30);
    b = c1.matriz();

    p1.setValues(-50, 120);
    p2.setValues(0, 200);
    p3.setValues(50, 120);
    t1.setValues(p1, p2, p3);
    c = t1.matriz();

    Sol::juntar(b, c);

    t1.traslacion(160, -70);
    t1.rotation(270);
    c = t1.matriz();
    Sol::juntar(b, c);

    t1.traslacion(-220, -100);
    t1.rotation(180);
    c = t1.matriz();
    Sol::juntar(b, c);

    t1.traslacion(160, -60);
    t1.rotation(90);
    c = t1.matriz();
    Sol::juntar(b, c);
}

void Sol::juntar(Matriz *m, Matriz *c)
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

void Sol::print_matrix(Matriz *m)
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

void Sol::traslacion(double dx, double dy)
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

    // Sol::draw();
}

void Sol::escala(double dx)
{
    int x0 = b->getValue(0, 0);
    int y0 = b->getValue(1, 0);

    Sol::traslacion(-b->getValue(0, 0), -b->getValue(1, 0));

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

    Sol::traslacion(x0, y0);

    //Sol::draw();
}

void Sol::rotation(int g)
{
    int x0 = b->getValue(0, 0);
    int y0 = b->getValue(1, 0);

    Sol::traslacion(-b->getValue(0, 0), -b->getValue(1, 0));

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

    Sol::traslacion(x0, y0);
}

void Sol::draw()
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