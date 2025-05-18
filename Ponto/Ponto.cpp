#include <iostream>
#include "ponto.h"

using namespace std;

Ponto::Ponto()
{
    this->x = 0;
    this->y = 0;
}

void Ponto::setX(double x)
{
    this->x = x;
}

double Ponto::getX() const
{
    return x;
}

void Ponto::setY(double y)
{
    this->y = y;
}

double Ponto::getY() const
{
    return y;
}

void Ponto::imprimirPontos()
{
    cout << "Ponto x: " << x << " - " << "Ponto y: " << y << endl;
}

double Ponto::distanciaPontos()
{
    return abs(x - y);
}
