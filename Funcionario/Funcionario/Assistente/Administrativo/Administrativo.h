#ifndef ASSISTENTE_ADMNISTRATIVO_H_INCLUDED
#define ASSISTENTE_ADMNISTRATIVO_H_INCLUDED
#include "../assistente.h"

class Administrativo : public Assistente
{
private:
    bool noturno;
public:
    Administrativo(bool noturno);

    double ganhoAnual();
};

#endif // ASSISTENTE_ADMNISTRATIVO_H_INCLUDED
