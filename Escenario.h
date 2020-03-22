#ifndef ESCENARIO_H
#define ESCENARIO_H

#include "Triangulo.h"
#include "Cuadrado.h"
#include "Circulo.h"
#include "Arbol.h"
#include "Sol.h"
#include "Casa.h"

class Escenario
{
private:
	Linea l1;
	Circulo c1;
	Arbol ar, ar2, ar3, ar4, ar5, ar6;
	Sol s;
	Casa ca;

public:
	Escenario();
	~Escenario();
	void setValue();
	void arboles();
	void sol();
	void casa();
	void draw();
};
#endif