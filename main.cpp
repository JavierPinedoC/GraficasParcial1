// #include <math.h>
// #include "Linea.h"
// #include "Triangulo.h"
// #include "Cuadrado.h"
// #include "Circulo.h"
#include "Escenario.h"
#include <unistd.h>

Escenario es;
//Variables globales
int xG = 50;

void reshape(int width, int height)
{
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-720, 720, -480, 480);
    glMatrixMode(GL_MODELVIEW);
}

void display()
{
    es.setValue();

    glFlush();
}

void init()
{
    glClearColor(0, 0, 0, 0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, 499, 0, 499);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity;
    Escenario();
}

void movimiento()
{
    glClear(GL_COLOR_BUFFER_BIT);
    Escenario es;
    es.setValue();
    Nube n1, n2;
    n1.nube();
    n1.traslacion(xG, 200);
    n1.escala(.5);
    n1.rotation(xG);
    glutSwapBuffers();

    if (xG > 499)
    {
        xG = -480;
    }
    else
        xG += 100;

    n1.draw();
    glFlush();
    usleep(50000);
}

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(50, 50);
    glutInitWindowSize(720, 480);
    glutCreateWindow("Parcial_1");
    init();
    //funcion que se llama para dibujar los objetos en pantalla
    glutDisplayFunc(display);
    //funcion que se llama para indicar que hacer cuando la pantalla cambia de tamano
    glutIdleFunc(movimiento);
    glutReshapeFunc(reshape);
    glutMainLoop();
    return 0;
}
