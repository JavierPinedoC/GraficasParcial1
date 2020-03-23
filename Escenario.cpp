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
    lu.luna();

    ca.casa();

    aR1.arbolre();
    aR2.arbolre();
    aR3.arbolre();
    aR4.arbolre();
    aR5.arbolre();
    aR6.arbolre();

    ll1.llanta();
    ll2.llanta();
    ll3.llanta();
    ll4.llanta();

    n1.nube();
    n2.nube();
}

Escenario::~Escenario() {}

void Escenario::setValue()
{

    Escenario::arboles();
    Escenario::sol();
    Escenario::casa();
    Escenario::arbolre();
    Escenario::luna();
    Escenario::llanta();
    Escenario::nube();

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
    s.traslacion(580, 350);
    s.rotation(45);
}

void Escenario::casa()
{
    ca.traslacion(-210, 0);
}

void Escenario::arbolre()
{
    aR1.traslacion(550, -480);

    aR2.traslacion(450, -650);
    aR2.escala(.5);

    aR3.traslacion(400, -480);

    aR4.traslacion(350, -630);
    aR4.escala(.6);
}

void Escenario::luna()
{
    lu.traslacion(-550, 300);
}

void Escenario::llanta()
{
    ll1.traslacion(50, -500);
    ll2.traslacion(300, -500);
    ll3.traslacion(400, -500);
    ll4.traslacion(200, -500);
}

void Escenario::nube()
{
    n1.traslacion(-500,100);
    n1.escala(0.5);

    n2.traslacion(-100,300);
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

    aR1.draw();
    aR2.draw();
    aR3.draw();
    aR4.draw();

    lu.draw();

    ll1.draw();
    ll2.draw();
    ll3.draw();
    ll4.draw();

    n1.draw();
    n2.draw();
}