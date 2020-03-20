#include "Circulo.h"

Circulo::Circulo() {}

Circulo::~Circulo() {}

void Circulo::setValues(int x1, int y1)
{
    b = new Matriz(3, x1);
    p0.setValues(x1, y1);
    Circulo::iniciarM();
}

void print_matrix(Matriz *m)
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

void Circulo::iniciarM()
{
    int xp = 0;
    int yp = 0;
    //     // glClear(GL_COLOR_BUFFER_BIT);
    //     // glColor3f(1, 0.0, 0.0);

    float r = M_PI * p0.getY();
    for (int j = 0; j <= p0.getX(); j++)
    {

        xp = round((r * cos(j * 180 / M_PI)));
        yp = round((r * sin(j * 180 / M_PI)));

        for (int i = 0; i < b->getnFilas(); i++)
        {
            if (i == 0)
                b->setValue(i, j, xp);
            else if (i == 1)
                b->setValue(i, j, yp);
            else
                b->setValue(i, j, 1);
        }
    }

    printf("B Principal\n");
    print_matrix(b);
    printf("\n");
}

void Circulo::traslacion(double dx, double dy)
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
    // printf("Traslacion \n");

    b = a->multiplicar(b);
    // b = c;
    //print_matrix(b);
}

void Circulo::escala(double dx)
{
    int x0 = b->getValue(0, 0);
    int y0 = b->getValue(1, 0);

    Circulo::traslacion(-b->getValue(0, 0), -b->getValue(1, 0));

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

    Circulo::traslacion(x0, y0);

    // printf("matriz b final: \n");
    // printf("\n");
    // print_matrix(b);
    // printf("\n");
}

//void Circulo::draw()
//{
//     int xip;
//     int yip;
//     int xp = 0;
//     int yp = 0;
//     // glClear(GL_COLOR_BUFFER_BIT);
//     // glColor3f(1, 0.0, 0.0);
//     for (int i = 0; i <= p0.getX(); i++)
//     {

//         float r = M_PI * p0.getY();

//         xp = round((r * cos(i * 180 / M_PI)));
//         yp = round((r * sin(i * 180 / M_PI)));

//         l1.setValues(xip, yip, xp, yp);

//         if (i > 0)
//         {
//             l1.draw();
//         }
//         xip = xp;
//         yip = yp;
//     }
//}

void Circulo::rotation(int g)
{
    int x0 = b->getValue(0, 0);
    int y0 = b->getValue(1, 0);

    Circulo::traslacion(-b->getValue(0, 0), -b->getValue(1, 0));

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

    Circulo::traslacion(x0, y0);

    //   printf("matriz b final: \n");
    // printf("\n");
    // print_matrix(b);
    // printf("\n");
}

void Circulo::draw()
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
            {}
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
