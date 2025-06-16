#ifndef PESSOA_H_INCLUDED
#define PESSOA_H_INCLUDED
#include <iostream>

class Pessoa{
private:
    std::string nome;
    Pessoa* mae;
    Pessoa* pai;

    bool antecessor_recursivo(Pessoa* p, std::string nome);
public:
    Pessoa(std::string nome);

    Pessoa(std::string nome, Pessoa* mae, Pessoa* pai);

    bool saoIguais(Pessoa* p);

    bool saoIrmaos(Pessoa* p);

    bool antecessor(Pessoa* p);
};

#endif // PESSOA_H_INCLUDED
