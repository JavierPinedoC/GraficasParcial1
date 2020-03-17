#include <GL/glut.h>
#include <stdlib.h>

/*
EJEMPLO DE LA DECLARACION DE CLASES EN C++
CURSO GRAFICACION POR COMPUTADORA
IVAN OLMOS PINEDA
*/

class Punto
{
private:
	int coord[2];

public:
	Punto();
	~Punto();
	void setValues(int, int);
	int getX();
	int getY();
	int *getValues();
	void draw();
};
