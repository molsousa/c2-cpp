#ifndef CIRCULO_H_INCLUDED
#define CIRCULO_H_INCLUDED

#include "ponto.h"

class Circulo : public Ponto
{
private:
    double raio;
public:
    Circulo(double x, double y, double raio);

    void aumentarRaio();

    void diminuirRaio();

    double getRaio();

    void mostrar();

    double getArea();

    double getPerimetro();
};

#endif // CIRCULO_H_INCLUDED
