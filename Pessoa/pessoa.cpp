#include "pessoa.h"

using namespace std;

Pessoa::Pessoa(string nome)
{
    this->nome = nome;
    mae = nullptr;
    pai = nullptr;
}

Pessoa::Pessoa(string nome, Pessoa* mae, Pessoa* pai)
{
    this->nome = nome;
    this->mae = mae;
    this->pai = pai;
}

bool Pessoa::saoIguais(Pessoa* p)
{
    return (p->mae == mae && p->nome == nome);
}

bool Pessoa::saoIrmaos(Pessoa* p)
{
    bool resultado = false;

    if(!saoIguais(p) && (p->mae == mae || p->pai == pai))
        resultado = true;

    return resultado;
}

bool Pessoa::antecessor(Pessoa* p)
{
    return antecessor_recursivo(p, nome);
}

bool Pessoa::antecessor_recursivo(Pessoa* p, string nome)
{
    if(p == nullptr)
        return false;

    if(nome == p->nome)
        return true;

    return antecessor_recursivo(p->pai, nome) || antecessor_recursivo(p->mae, nome);
}
