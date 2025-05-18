#ifndef ASSISTENTE_TECNICO_H_INCLUDED
#define ASSISTENTE_TECNICO_H_INCLUDED
#include "../assistente.h"

class Tecnico : public Assistente
{
private:
    double bonus;
public:
    Tecnico(double bonus);

    double ganhoAnual();
};

#endif // ASSISTENTE_TECNICO_H_INCLUDED
