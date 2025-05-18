#ifndef DISTANCIA_H_INCLUDED
#define DISTANCIA_H_INCLUDED
#include "ponto.h"

class Distancia{
private:
    Ponto* p1 = new Ponto();
    Ponto* p2 = new Ponto();

public:
    Distancia();

    void imprimirPontos();

    double distanciaEuclidiana();

    ~Distancia();
};

#endif // DISTANCIA_H_INCLUDED
