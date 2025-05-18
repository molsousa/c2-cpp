#include <iostream>
#include "Funcionario/Assistente/Administrativo/Administrativo.h"

using namespace std;

int main()
{
    Administrativo* adm = new Administrativo(true);

    adm->exibeDados();
    cout << adm->ganhoAnual() << endl;

    delete adm;

    return 0;
}
