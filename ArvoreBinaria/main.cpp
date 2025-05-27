#include "Arvore/arvore.h"

int main()
{
    Arvore* raiz = new Arvore();

    raiz->inserirElemento(4);
    raiz->inserirElemento(2);
    raiz->inserirElemento(3);
    raiz->inserirElemento(1);
    raiz->inserirElemento(6);
    raiz->inserirElemento(5);
    raiz->inserirElemento(7);

    raiz->removerElemento(4);

    raiz->imprimirArvore();

    delete raiz;

    return 0;
}
