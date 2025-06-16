#include <iostream>
#include "pessoa.h"

using namespace std;

int main()
{
    Pessoa* p = new Pessoa("Carlos");
    Pessoa* m = new Pessoa("Joana");
    Pessoa* n = new Pessoa("Lidia", p, m);
    Pessoa* q = new Pessoa("Joao", p, m);

    cout << q->saoIrmaos(n) << endl;
    cout << q->saoIguais(n) << endl;
    cout << p->antecessor(n) << endl;

    return 0;
}
