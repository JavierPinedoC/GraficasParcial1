
#ifndef MATRIZ_H
#define MATRIZ_H
#include "Punto.h"
#include <stdlib.h>
using namespace std;

class Matriz
{
private:
    int **puntero_matriz, nFilas,nCol;
public:
    Matriz(int nFilas, int nCol);
    ~Matriz();
    Matriz *multiplicar( Matriz *b);
    int getnFilas();
    int getnCol();
    int getValue(int, int);
    void setValue(int, int,int);
    
    void traslacion(int, int);
    void escala(int, int);
};
#endif