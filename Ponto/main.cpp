#include <iostream>
#include "distancia.h"

using namespace std;

int main()
{
    Distancia *d = new Distancia();

    d->imprimirPontos();
    cout << "Distancia euclidiana: " << d->distanciaEuclidiana() << endl;

    delete d;

    return 0;
}
