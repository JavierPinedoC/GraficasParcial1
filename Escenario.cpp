#include "Escenario.h"

Escenario::Escenario()
{
    ar.arbol();
    ar2.arbol();
    ar3.arbol();
    ar4.arbol();
    ar5.arbol();
    ar6.arbol();

    s.sol();

    ca.casa();
}

Escenario::~Escenario() {}

void Escenario::setValue()
{
     
    Escenario::arboles();
    Escenario::sol();
    Escenario::casa();

    Escenario::draw();
}
void Escenario::arboles()
{
    ar.traslacion(-600, -480);
    ar.escala(.5);
    ar.rotation(0);

    ar2.traslacion(-480, -480);
    ar2.escala(1);
    ar2.rotation(0);

    ar3.traslacion(-690, -480);
    ar3.escala(.6);
    ar3.rotation(0);

    ar4.traslacion(-400, -480);
    ar4.escala(.7);
    ar4.rotation(0);

    ar5.traslacion(-700, -480);
    ar5.escala(.8);
    ar5.rotation(0);

    ar6.traslacion(-600, -480);
    ar6.escala(1);
    ar6.rotation(0);

    
}

void Escenario::sol()
{
    s.traslacion(580,350);
    s.rotation(45);
}

void Escenario::casa(){

}

void Escenario::draw()
{
    ar.draw();
    ar2.draw();
    ar3.draw();
    ar4.draw();
    ar5.draw();
    ar6.draw();

    s.draw();
    
    ca.draw();

}