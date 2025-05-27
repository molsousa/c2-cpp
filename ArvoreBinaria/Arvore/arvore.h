#ifndef ARVORE_BINARIA_H_INCLUDED
#define ARVORE_BINARIA_H_INCLUDED
#include "no.h"

class Arvore{
private:
    No* raiz;

    No* inserirElementoCauda(No* raiz, int info);

    No* removerElementoCauda(No* raiz, int info);

    void imprimirArvoreCauda(No* raiz);

    void liberarArvore(No* raiz);
public:
    Arvore();

    void inserirElemento(int info);

    void removerElemento(int info);

    int buscaArvore(int info);

    void imprimirArvore();

    ~Arvore();
};

#endif // ARVORE_BINARIA_H_INCLUDED
