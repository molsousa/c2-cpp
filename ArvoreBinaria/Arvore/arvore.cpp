#include <iostream>
#include "arvore.h"

using namespace std;

Arvore::Arvore()
{
    raiz = nullptr;
}

void Arvore::inserirElemento(int info)
{
    raiz = inserirElementoCauda(raiz, info);
}
No* Arvore::inserirElementoCauda(No* raiz, int info)
{
    if(raiz == nullptr){
        No* novo = new No();
        novo->info = info;
        return novo;
    }

    else if(raiz->info < info)
        raiz->dir = inserirElementoCauda(raiz->dir, info);

    else if(raiz->info > info)
        raiz->esq = inserirElementoCauda(raiz->esq, info);

    else
        cout << "Elemento repetido" << endl;

    return raiz;
}

void Arvore::removerElemento(int info)
{
    raiz = removerElementoCauda(raiz, info);
}
No* Arvore::removerElementoCauda(No* raiz, int info)
{
    if(raiz == nullptr)
        return raiz;

    else if(raiz->info > info)
        raiz->esq = removerElementoCauda(raiz->esq, info);

    else if(raiz->info < info)
        raiz->dir = removerElementoCauda(raiz->dir, info);

    else{
        No* aux = raiz;

        if(raiz->esq == nullptr && raiz->dir == nullptr){
            delete raiz;
            return nullptr;
        }

        else if(raiz->esq == nullptr){
            raiz = raiz->dir;
            delete aux;
        }

        else if(raiz->dir == nullptr){
            raiz = raiz->esq;
            delete aux;
        }
        else{
            aux = raiz->esq;

            while(aux->dir != nullptr)
                aux = aux->dir;

            raiz->info = aux->info;
            raiz->esq = removerElementoCauda(raiz->esq, aux->info);
        }

    }
    return raiz;
}

void Arvore::imprimirArvore()
{
    imprimirArvoreCauda(raiz);
}
void Arvore::imprimirArvoreCauda(No* raiz)
{
    if(raiz == nullptr)
        return;

    cout << raiz->info << endl;

    imprimirArvoreCauda(raiz->esq);
    imprimirArvoreCauda(raiz->dir);
}

Arvore::~Arvore()
{
    liberarArvore(raiz);

    cout << "Arvore liberada" << endl;
}

void Arvore::liberarArvore(No* raiz)
{
    if(raiz == nullptr)
        return;

    liberarArvore(raiz->esq);
    liberarArvore(raiz->dir);

    delete raiz;
}
