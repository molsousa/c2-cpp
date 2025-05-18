#ifndef ASSISTENTE_H_INCLUDED
#define ASSISTENTE_H_INCLUDED
#include "../funcionario.h"

class Assistente : public Funcionario
{
private:
    int matricula;
public:
    Assistente();

    void setMatricula(int matricula);

    int getMatricula();

    void exibeDados();
};

#endif // ASSISTENTE_H_INCLUDED
