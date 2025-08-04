#include "listade.h"

using namespace std;

int main()
{
    Lista<char> l;

    l.inserir('f');
    l.inserir('g');
    l.inserir('a');
    l.inserir('j');
    l.inserir('q');
    l.inserir('p');
    l.inserir('e');

    l.imprimir();

    return 0;
}
