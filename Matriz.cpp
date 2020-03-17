#include "Matriz.h"

Matriz::Matriz(int nFilas, int nCol)
{
    this->nFilas = nFilas;
    this->nCol = nCol;
    this->puntero_matriz = new int *[nFilas];
    for (int i = 0; i < nFilas; i++)
        this->puntero_matriz[i] = new int[nCol];
}
Matriz::~Matriz()
{
    for (int i = 0; i < nFilas; i++)
        delete[] this->puntero_matriz[i];
    delete[] this->puntero_matriz;
}

int Matriz::getnFilas()
{
    return this->nFilas;
}

int Matriz::getnCol()
{
    return this->nCol;
}

int Matriz::getValue(int f, int c)
{
    return this->puntero_matriz[f][c];
}

void Matriz::setValue(int f, int c, int v)
{
    this->puntero_matriz[f][c] = v;
}

Matriz *Matriz::multiplicar( Matriz *b)
{
    Matriz *c = new Matriz(this->nFilas, b->nCol);
    int temp;

    for (int i = 0; i < this->nFilas; i++)
        for (int j = 0; j < b->nCol; j++){
            temp = 0;
            for (int k = 0; k < this->nCol; k++)
            {
                temp +=  this->puntero_matriz[i][k] *  b->puntero_matriz[k][j];
            }
            c->puntero_matriz[i][j]= temp;
        }

    return c;
}

// void Matriz::traslacion(int dx, int dy)
// {
//     int trasla[3][3] = {{1, 0, dx}, {0, 1, dy}, {0, 0, 1}};

//     for (i = 0; i < 3; i++)
//     {
//         for (j = 0; j < 3; j++)
//         {
//             res[i][j] = 0;
//             for (k = 0; k < 3; k++)
//                 res[i][j] += trasla[k][j] * matA[i][k];
//         }
//     }

//     for (i = 0; i < 3; i++)
//     {
//         for (j = 0; i < 3; i++)
//         {
//             matA[i][j] = res[i][j];
//         }
//     }
// }

// void Matriz::escala(int sx, int sy)
// {
//     int escal[3][3] = {{sx, 0, 0}, {0, sy, 0}, {0, 0, 1}};

//     for (i = 0; i < 3; i++)
//     {
//         for (j = 0; j < 3; j++)
//         {
//             res[i][j] = 0;
//             for (k = 0; k < 3; k++)
//                 res[i][j] += escal[k][j] * matA[i][k];
//         }
//     }

//     for (i = 0; i < 3; i++)
//     {
//         for (j = 0; i < 3; i++)
//         {
//             matA[i][j] = res[i][j];
//         }
//     }
// }