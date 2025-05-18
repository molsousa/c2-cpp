#include <iostream>
#include "funcionario.h"

using namespace std;

int main()
{
    Funcionario *f1 = new Assistente();

    f1->exibeDados();

    delete f1;

    return 0;
}
