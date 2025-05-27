#include <iostream>
#include "contador.h"

using namespace std;

int main()
{
    Contador* i = new Contador();

    i->incrementar();
    i->incrementar();
    i->incrementar();
    i->incrementar();
    i->incrementar();

    cout << "Valor atual: " << i->valorAtual() << endl;

    i->zerar();

    cout << "Valor atual: " << i->valorAtual() << endl;

    delete i;

    return 0;
}
