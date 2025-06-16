#include <iostream>
#include "Matriz.h"

using namespace std;

int main()
{
    Matriz* m = new Matriz(2, 2, 4);
    Matriz* n = new Matriz(2, 2, 8);

    (*n) += (*m);

    n->mostrar();

    return 0;
}
