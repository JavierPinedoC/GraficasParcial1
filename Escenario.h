#ifndef ESCENARIO_H
#define ESCENARIO_H

#include "Triangulo.h"
#include "Cuadrado.h"
#include "Circulo.h"
#include "Arbol.h"
#include "Sol.h"
#include "Casa.h"
#include "ArbolRe.h"
#include "Luna.h"
#include "Llanta.h"
#include "Nube.h"

class Escenario
{
private:
	Linea l1;
	Circulo c1;
	Arbol ar, ar2, ar3, ar4, ar5, ar6;
	Sol s;
	Casa ca;
	ArbolRe aR1,aR2,aR3,aR4,aR5,aR6;
	Luna lu;
	Llanta ll1,ll2,ll3,ll4;
	Nube n1,n2;

public:
	Escenario();
	~Escenario();
	void setValue();
	void arboles();
	void sol();
	void casa();
	void arbolre();
	void luna();
	void llanta();
	void nube();
	void draw();
};
#endif