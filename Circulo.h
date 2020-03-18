#ifndef CIRCULO_H
#define CIRCULO_H

#include "Linea.h"


class Circulo
{
private:
	Punto p1, p2, p0;
	Linea l1;

public:
	Circulo();
	~Circulo();
	void setValues(int, int);
	void setValues(int, int, int, int);
	void draw();
};
#endif