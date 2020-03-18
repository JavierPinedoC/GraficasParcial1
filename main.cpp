#include <math.h>
#include "Linea.h"
#include "Triangulo.h"
#include "Cuadrado.h"
#include "Circulo.h"

void reshape(int width, int height)
{
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-320, 320, -240, 240);
    glMatrixMode(GL_MODELVIEW);
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();
    Punto p1, p2, p3, p4;
    // Linea milinea;
    // mipunto.setValues(30, 50);
    // milinea.setValues(0, 0, 40, 50);
    // glClear(GL_COLOR_BUFFER_BIT);
    // glLoadIdentity();

    // mipunto.draw();
    // milinea.draw();

    // Triangulo tr;
    // // tr.setValues(0,0,50,50,100,0);
    // p1.setValues(0,0);
    // p2.setValues(50,50);
    // p3.setValues(100,0);
    // tr.setValues(p1,p2,p3);

    // tr.draw();

    Cuadrado cu;
    // p1.setValues(0, 0);
    // p2.setValues(0, 100);
    // p3.setValues(100, 100);
    // p4.setValues(100,0);
    cu.setValues(100, 100);
    //cu.traslacion(50, -20);
    cu.escala(2);
    cu.rotation(10);
    // cu.traslacion(50,50,0,0);
    // cu.setValues(p1,p2,p3,p4);
    // cu.traslacion(20,30);
    // glClear(GL_COLOR_BUFFER_BIT);
    // glLoadIdentity();

    cu.draw();

    Cuadrado cu2;
    // p1.setValues(0, 0);
    // p2.setValues(0, 100);
    // p3.setValues(100, 100);
    // p4.setValues(100,0);
    // cu.setValues(p1,p2,p3,p4);
    cu2.setValues(100, 100);
    cu2.traslacion(-200, -200);
    cu2.escala(2);
    //cu2.rotation(240);
    // glClear(GL_COLOR_BUFFER_BIT);
    // glLoadIdentity();

    cu2.draw();

    // Circulo ci;
    // ci.setValues(50,50);
    // // glClear(GL_COLOR_BUFFER_BIT);
    // // glLoadIdentity();
    // ci.draw();

    glFlush();
}

void init()
{
    glClearColor(0, 0, 0, 0);
}

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(50, 50);
    glutInitWindowSize(640, 480);
    glutCreateWindow("Manejo Clases");
    init();
    //funcion que se llama para dibujar los objetos en pantalla
    glutDisplayFunc(display);
    //funcion que se llama para indicar que hacer cuando la pantalla cambia de tamano
    glutReshapeFunc(reshape);
    glutMainLoop();
    return 0;
}
