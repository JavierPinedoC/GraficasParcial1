
#ifndef MATRIZ_H
#define MATRIZ_H
#include <stdlib.h>
using namespace std;

class Matriz
{
private:
    int  nFilas, nCol;
    double **puntero_matriz;

public:
    Matriz(int nFilas, int nCol);
    ~Matriz();
    Matriz *multiplicar(Matriz *b);
    int getnFilas();
    int getnCol();
    int getValue(int, int);
    void setValue(int, int, int);
    void setValue(int, int, double);

    void traslacion(int, int);
    void escala(int, int);
};
#endif