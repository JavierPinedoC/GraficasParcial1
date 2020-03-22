// #include <math.h>
// #include "Linea.h"
// #include "Triangulo.h"
// #include "Cuadrado.h"
// #include "Circulo.h"
#include "Escenario.h"

Escenario es;

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
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity;

    es.setValue();

    //Punto p1, p2, p3, p4;
    // Linea milinea;
    // mipunto.setValues(30, 50);
    // milinea.setValues(0, 0, 40, 50);
    // glClear(GL_COLOR_BUFFER_BIT);
    // glLoadIdentity();

    // mipunto.draw();
    // milinea.draw();

    // Triangulo tr;
    // tr.setValues(0,0,50,50,100,0);
    // p1.setValues(0, 0);
    // p2.setValues(50, 50);
    // p3.setValues(100, 0);
    // tr.setValues(p1, p2, p3);
    // tr.traslacion(50, 0);
    // tr.escala(2);
    // tr.rotation(5);

    // tr.draw();

    // Triangulo tr2;
    // tr.setValues(0,0,50,50,100,0);
    // p1.setValues(0, 0);
    // p2.setValues(50, 50);
    // p3.setValues(100, 0);
    // tr2.setValues(p1, p2, p3);
    //tr2.traslacion(2,3);

    // tr2.draw();

    // Cuadrado cu;
    // p1.setValues(0, 0);
    // p2.setValues(0, 100);
    // p3.setValues(100, 100);
    // p4.setValues(100,0);
    // cu.setValues(100, 100);
    //cu.traslacion(50, -20);
    // cu.escala(2);
    // cu.rotation(10);
    // cu.traslacion(50,50,0,0);
    // cu.setValues(p1,p2,p3,p4);
    // cu.traslacion(20,30);
    // glClear(GL_COLOR_BUFFER_BIT);
    // glLoadIdentity();

    // cu.draw();

    // Cuadrado cu2;
    // p1.setValues(0, 0);
    // p2.setValues(0, 100);
    // p3.setValues(100, 100);
    // p4.setValues(100,0);
    // cu.setValues(p1,p2,p3,p4);
    // cu2.setValues(100, 100);
    // cu2.traslacion(-200, -200);
    // cu2.escala(2);
    //cu2.rotation(240);
    // glClear(GL_COLOR_BUFFER_BIT);
    // glLoadIdentity();

    // cu2.draw();

    //Circulo ci;
    //ci.setValues(360, 50);
    //ci.traslacion(50, 50);
    //ci.escala(1.5);
    //ci.rotation(0);
    // glClear(GL_COLOR_BUFFER_BIT);
    // glLoadIdentity();
    //ci.draw();

    // Circulo ci2;
    // ci2.setValues(360, 50);
    //  ci2.rotation(-90);
    //ci2.traslacion(50,50);
    //ci2.escala(1.5);
    // glClear(GL_COLOR_BUFFER_BIT);
    // glLoadIdentity();
    // ci2.draw();

    // Circulo ci3;
    // ci3.setValues(360, 50);
    // ci3.rotation(180);
    //ci3.traslacion(50,50);
    //ci3.escala(1.5);
    // glClear(GL_COLOR_BUFFER_BIT);
    // glLoadIdentity();
    // ci3.draw();

    // Circulo ci4;
    // ci4.setValues(360, 50);
    // ci4.rotation(0);
    //ci3.traslacion(50,50);
    //ci3.escala(1.5);
    // glClear(GL_COLOR_BUFFER_BIT);
    // glLoadIdentity();
    // ci4.draw();

    glFlush();
}

void init()
{
    glClearColor(0, 0, 0, 0);
    es;
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
    glutReshapeFunc(reshape);
    glutMainLoop();
    return 0;
}
