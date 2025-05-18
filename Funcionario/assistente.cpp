#include <iostream>
#include "assistente.h"

using namespace std;

Assistente::Assistente()
{
    int tempMatricula;

    cout << "Insira a matricula: ";
    cin >> tempMatricula;
    setMatricula(tempMatricula);
}

void Assistente::setMatricula(int matricula)
{
    this->matricula = matricula;
}

int Assistente::getMatricula()
{
    return matricula;
}
