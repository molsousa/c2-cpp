#include <iostream>
#include <math.h>
#include "ponto.h"
#include "distancia.h"

using namespace std;

Distancia::Distancia()
{
    double referencia;

    cout << "Insira o valor de x1: ";
    cin >> referencia;
    this->p1->setX(referencia);

    cout << "Insira o valor de y1: ";
    cin >> referencia;
    this->p1->setY(referencia);

    cout << "Insira o valor de x2: ";
    cin >> referencia;
    this->p2->setX(referencia);

    cout << "Insira o valor de y2: ";
    cin >> referencia;
    this->p2->setY(referencia);

    system("cls");
}

double Distancia::distanciaEuclidiana()
{
    return sqrt( pow(p1->distanciaPontos(), 2) + pow(p2->distanciaPontos(), 2) );
}

void Distancia::imprimirPontos()
{
    p1->imprimirPontos();
    p2->imprimirPontos();
}

Distancia::~Distancia()
{
    delete p1;
    delete p2;

    cout << "Pontos destruidos com sucesso!!" << endl;
}
