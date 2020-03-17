#include "Circulo.h"
#include <cmath>

Circulo::Circulo() {}

Circulo::~Circulo() {}

void Circulo::setValues(int x1, int y1)
{
    p0.setValues(x1, y1);
}

void Circulo::setValues(int x1, int y1, int x2, int y2)
{
    l1.setValues(x1, y1, x2, y2);
}

void Circulo::draw()
{
    int xip;
    int yip;
    int xp = 0;
    int yp = 0;
    // glClear(GL_COLOR_BUFFER_BIT);
    // glColor3f(1, 0.0, 0.0);
    for (int i = 0; i <= p0.getX(); i++)
    {

        float r = M_PI * p0.getY();

        xp = round((r * cos(i * 180 / M_PI)));
        yp = round((r * sin(i * 180 / M_PI)));

        l1.setValues(xip, yip, xp, yp);

        if (i > 0)
        {
            l1.draw();
        }
        xip = xp;
        yip = yp;
    }
}
