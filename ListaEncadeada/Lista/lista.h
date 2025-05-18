#ifndef LISTA_ENCADEADA_H_INCLUDED
#define LISTA_ENCADEADA_H_INCLUDED
#include "no.h"

class Lista{
private:
    No* cabeca;

    void liberarLista(No* cabeca);
public:
    Lista();

    bool listaVazia();

    void inserirElemento(int info);

    void removerElemento(int info);

    void imprimirLista();

    ~Lista();
};

#endif // LISTA_ENCADEADA_H_INCLUDED
