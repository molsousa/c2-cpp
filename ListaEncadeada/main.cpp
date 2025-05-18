#include <iostream>
#include "Lista/lista.h"

using namespace std;

int main()
{
    Lista* l = new Lista();

    l->inserirElemento(5);
    l->inserirElemento(2);
    l->inserirElemento(1);
    l->inserirElemento(4);
    l->inserirElemento(3);

    l->removerElemento(4);

    l->imprimirLista();

    delete l;

    return 0;
}
