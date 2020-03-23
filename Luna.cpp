#include "Luna.h"

Luna::Luna() {}

Luna::~Luna() {}

void Luna::luna()
{
    c1.setValues(360, 40);
    b = c1.matriz();

    for (int i = 0; i < 40; i++)
    {
        c1.setValues(360, 40-i);
        c = c1.matriz();
        Luna::juntar(b,c);
    }
}

void Luna::juntar(Matriz *m, Matriz *c)
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

void Luna::print_matrix(Matriz *m)
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

void Luna::traslacion(double dx, double dy)
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

    // Luna::draw();
}

void Luna::escala(double dx)
{
    int x0 = b->getValue(0, 0);
    int y0 = b->getValue(1, 0);

    Luna::traslacion(-b->getValue(0, 0), -b->getValue(1, 0));

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

    Luna::traslacion(x0, y0);

    //Luna::draw();
}

void Luna::rotation(int g)
{
    int x0 = b->getValue(0, 0);
    int y0 = b->getValue(1, 0);

    Luna::traslacion(-b->getValue(0, 0), -b->getValue(1, 0));

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

    Luna::traslacion(x0, y0);
}

void Luna::draw()
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