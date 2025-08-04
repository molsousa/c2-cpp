#include "arvore.h"

int main()
{
    Arvore<int> r;

    r.inserir(11);
    r.inserir(4);
    r.inserir(2);
    r.inserir(3);
    r.inserir(9);
    r.inserir(1);
    r.inserir(23);
    r.inserir(21);
    r.inserir(18);
    r.inserir(12);
    r.inserir(17);
    r.inserir(22);
    r.inserir(8);
    r.inserir(7);

    r.remover(11);
    r.remover(12);
    r.remover(7);

    r.inserir(10);
    r.inserir(24);
    r.inserir(25);

    r.imprimir_niveis();

    cout << r.busca(5) << endl;

    return 0;
}
