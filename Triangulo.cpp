#include "Triangulo.h"

Triangulo::Triangulo() {}

Triangulo::~Triangulo() {}

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

void Triangulo::setValues(int x1, int y1, int x2, int y2, int x3, int y3)
{
    l1.setValues(x1, y1, x2, y2);
    l2.setValues(x2, y2, x3, y3);
    l3.setValues(x3, y3, x1, y1);
    // Triangulo::iniciarM(p1, p2, p3);
}

void Triangulo::setValues(Punto p1, Punto p2, Punto p3)
{
    l1.setValues(p1, p2);
    l2.setValues(p2, p3);
    l3.setValues(p3, p1);

    Triangulo::iniciarM(p1, p2, p3);
    // print_matrix(b);
    // printf("\n");
}

void Triangulo::iniciarM(Punto p1, Punto p2, Punto p3)
{
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
        }
    }
}

void Triangulo::traslacion(double dx, double dy)
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
    // printf("\n");
    // print_matrix(a);
    // printf("\nTraslacion b normal\n");
    // print_matrix(b);

    b = a->multiplicar(b);
    // printf("\n");
    // printf("\n b multiplicada\n");
    // print_matrix(b);
    //b = c;

    Triangulo::setValues(
        b->getValue(0, 0), b->getValue(1, 0),
        b->getValue(0, 1), b->getValue(1, 1),
        b->getValue(0, 2), b->getValue(1, 2));
}

void Triangulo::escala(double dx)
{
    // printf("\n");
    // print_matrix(b);
    int x0 = b->getValue(0, 0);
    int y0 = b->getValue(1, 0);
    // printf("\n");
    // printf("%d",x0);
    // printf("%d",y0);

    Triangulo::traslacion(-b->getValue(0, 0), -b->getValue(1, 0));

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

    Triangulo::traslacion(x0, y0);

    //   printf("matriz b final: \n");
    // printf("\n");
    // print_matrix(b);
    // printf("\n");

    Triangulo::setValues(
        b->getValue(0, 0), b->getValue(1, 0),
        b->getValue(0, 1), b->getValue(1, 1),
        b->getValue(0, 2), b->getValue(1, 2));
}

void Triangulo::rotation(int g)
{
    int x0 = b->getValue(0, 0);
    int y0 = b->getValue(1, 0);

    Triangulo::traslacion(-b->getValue(0, 0), -b->getValue(1, 0));

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

    Triangulo::traslacion(x0, y0);

    //   printf("matriz b final: \n");
    // printf("\n");
    // print_matrix(b);
    // printf("\n");

    Triangulo::setValues(
        b->getValue(0, 0), b->getValue(1, 0),
        b->getValue(0, 1), b->getValue(1, 1),
        b->getValue(0, 2), b->getValue(1, 2));
}

void Triangulo::draw()
{
    l1.draw();
    l2.draw();
    l3.draw();
}
