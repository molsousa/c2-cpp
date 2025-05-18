#include <iostream>
#include "administrativo.h"

Administrativo::Administrativo(bool noturno)
{
    this->noturno = noturno;

    if(noturno){
        double temp;
        cout << "Insira o bonus noturno: ";
        cin >> temp;

        setSalario(getSalario()+temp);
    }
}

double Administrativo::ganhoAnual()
{
    return (getSalario() * 12);
}
