#include <iostream>
#include "contador.h"

using namespace std;

Contador::Contador()
{
    contador = 0;
}

void Contador::incrementar()
{
    this->contador++;
}

void Contador::zerar()
{
    this->contador = 0;
}

int Contador::valorAtual()
{
    return contador;
}

Contador::~Contador()
{
    cout << "Contador finalizado" << endl;
}
