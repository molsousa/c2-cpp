#include <iostream>
#include "ponto.h"

Ponto::Ponto()
{
    x = 0;
    y = 0;
}

void Ponto::setX(double x)
{
    this->x = x;
}

double Ponto::getX()
{
    return x;
}

void Ponto::setY(double y)
{
    this->y = y;
}

double Ponto::getY()
{
    return y;
}

void Ponto::mostrar()
{
    std::cout << "X: " << x << std::endl;
    std::cout << "Y: " << y << std::endl;
}

Ponto::~Ponto()
{
    std::cout << "==========" << std::endl;
    std::cout << "Obrigado!!" << std::endl;
    std::cout << "==========" << std::endl;
}
