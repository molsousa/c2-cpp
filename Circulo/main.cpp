#include <iostream>
#include "circulo.h"

using namespace std;

int main()
{
    Circulo *circulo = new Circulo(10, 5, 4);

    circulo->mostrar();

    cout << "Area: " << circulo->getArea() << endl;

    delete circulo;

    return 0;
}
