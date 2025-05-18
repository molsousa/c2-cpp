#include <iostream>
#include "../assistente.h"
#include "tecnico.h"

Tecnico::Tecnico(double bonus)
{
    this->bonus = bonus;

    setSalario(getSalario()+bonus);
}

double Tecnico::ganhoAnual()
{
    return (getSalario()*12);
}
