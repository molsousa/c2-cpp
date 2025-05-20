#include <iostream>
#include <math.h>
#include "circulo.h"

Circulo::Circulo(double x, double y, double raio)
{
    this->x = x;
    this->y = y;
    this->raio = raio;
}

void Circulo::aumentarRaio()
{
    ++raio;
}

void Circulo::diminuirRaio()
{
    --raio;
}

double Circulo::getRaio()
{
    return raio;
}

void Circulo::mostrar()
{
    Ponto::mostrar();
    std::cout << "Raio: " << raio << std::endl;
}

double Circulo::getArea()
{
    return (M_PI * raio * raio);
}

double Circulo::getPerimetro()
{
    return (M_PI * 2 * raio);
}
