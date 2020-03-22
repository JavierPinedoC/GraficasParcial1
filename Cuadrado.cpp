#include "Cuadrado.h"

Cuadrado::Cuadrado(){}

Cuadrado::~Cuadrado() {}

// void print_matrix(Matriz *m)
// {
//     for (int i = 0; i < m->getnFilas(); i++)
//     {
//         for (int j = 0; j < m->getnCol(); j++)
//         {
//             printf("%d ", m->getValue(i, j));
//         }

//         printf("\n");
//     }
// }

void Cuadrado::setValues(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4)
{
    l1.setValues(x1, y1, x2, y2);
    l2.setValues(x2, y2, x3, y3);
    l3.setValues(x3, y3, x4, y4);
    l4.setValues(x4, y4, x1, y1);
}

void Cuadrado::setValues(Punto p1, Punto p2, Punto p3, Punto p4)
{
    l1.setValues(p1, p2);
    l2.setValues(p2, p3);
    l3.setValues(p3, p4);
    l4.setValues(p4, p1);
}

void Cuadrado::calcular(int x1, int y1)
{
    p1.setValues(0, 0);
    p2.setValues(x1, p1.getY());
    p3.setValues(x1, y1);
    p4.setValues(p1.getX(), y1);
}

void Cuadrado::setValues(int x1, int y1)
{
    Cuadrado::calcular(x1, y1);
    Cuadrado::setValues(p1, p2, p3, p4);

    for (int j = 0; j < b->getnCol(); j++)
    {
        for (int i = 0; i < b->getnFilas(); i++)
        {
            if (j == 0)
            {
                if (i == 0)
                    b->setValue(i, j, p1.getX());
                else if (i == 1)
                    b->setValue(i, j, p1.getY());
                else
                    b->setValue(i, j, 1);
            }
            else if (j == 1)
            {
                if (i == 0)
                    b->setValue(i, j, p2.getX());
                else if (i == 1)
                    b->setValue(i, j, p2.getY());
                else
                    b->setValue(i, j, 1);
            }
            if (j == 2)
            {
                if (i == 0)
                    b->setValue(i, j, p3.getX());
                else if (i == 1)
                    b->setValue(i, j, p3.getY());
                else
                    b->setValue(i, j, 1);
            }
            if (j == 3)
            {
                if (i == 0)
                    b->setValue(i, j, p4.getX());
                else if (i == 1)
                    b->setValue(i, j, p4.getY());
                else
                    b->setValue(i, j, 1);
            }
        }
    }
    // print_matrix(b);
    // printf("\n");
}

void Cuadrado::traslacion(double dx, double dy)
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

    // print_matrix(a);
    // printf("Traslacion \n");

    b = a->multiplicar(b);
    // b = c;

    Cuadrado::setValues(
        b->getValue(0, 0), b->getValue(1, 0),
        b->getValue(0, 1), b->getValue(1, 1),
        b->getValue(0, 2), b->getValue(1, 2),
        b->getValue(0, 3), b->getValue(1, 3));

    // print_matrix(b);
}

void Cuadrado::escala(double dx)
{
    int x0 = b->getValue(0, 0);
    int y0 = b->getValue(1, 0);

    Cuadrado::traslacion(-b->getValue(0, 0), -b->getValue(1, 0));

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
    // printf("\n");
    // print_matrix(a);
    // printf("\n");

    // printf("Escalamiento antes de \n");

    // print_matrix(b);
    // printf("\n");
    // print_matrix(a);
    // printf("\n");

    b = a->multiplicar(b);
    // printf("matriz b con escalamiento: \n");
    // printf("\n");
    // print_matrix(b);
    // printf("\n");

    Cuadrado::traslacion(x0, y0);

    //   printf("matriz b final: \n");
    // printf("\n");
    // print_matrix(b);
    // printf("\n");

    Cuadrado::setValues(
        b->getValue(0, 0), b->getValue(1, 0),
        b->getValue(0, 1), b->getValue(1, 1),
        b->getValue(0, 2), b->getValue(1, 2),
        b->getValue(0, 3), b->getValue(1, 3));
}

void Cuadrado::rotation(int g)
{
    int x0 = b->getValue(0, 0);
    int y0 = b->getValue(1, 0);

    Cuadrado::traslacion(-b->getValue(0, 0), -b->getValue(1, 0));

    for (int i = 0; i < a->getnFilas(); i++)
    {
        for (int j = 0; j < a->getnCol(); j++)
        {
            if (i == 0 && j == 0 || i == 1 && j == 1)
            {
                a->setValue(i, j, cos(g * M_PI/180));
            }
            else if (i == 1 && j == 0)
            {
                a->setValue(i, j, sin(g * M_PI/180));
            }
            else if (i == 0 && j == 1)
            {
                a->setValue(i, j, -sin(g * M_PI/180));
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
    // printf("\n");
    // printf("Rotacion\n");
    // print_matrix(a);
    // printf("\n");

    // printf("Escalamiento antes de \n");

    // print_matrix(b);
    // printf("\n");
    // print_matrix(a);
    // printf("\n");

    b = a->multiplicar(b);
    // printf("matriz b con escalamiento: \n");
    // printf("\n");
    // print_matrix(b);
    // printf("\n");

    Cuadrado::traslacion(x0, y0);

    //   printf("matriz b final: \n");
    // printf("\n");
    // print_matrix(b);
    // printf("\n");

    Cuadrado::setValues(
        b->getValue(0, 0), b->getValue(1, 0),
        b->getValue(0, 1), b->getValue(1, 1),
        b->getValue(0, 2), b->getValue(1, 2),
        b->getValue(0, 3), b->getValue(1, 3));
}

Matriz *Cuadrado::matriz()
{
    return b;
}

void Cuadrado::draw()
{
    l1.draw();
    l2.draw();
    l3.draw();
    l4.draw();
}
