#include <iostream>
#include "no.h"
#include "lista.h"

using namespace std;

Lista::Lista()
{
    this->cabeca = nullptr;
}

bool Lista::listaVazia()
{
    return (cabeca == nullptr);
}

void Lista::inserirElemento(int info)
{
    No* novo = new No(info);
    novo->prox = cabeca;

    cabeca = novo;
}

void Lista::removerElemento(int info)
{
    if(cabeca == nullptr)
        return;

    No* aux = cabeca;
    No* anterior = cabeca;

    while(aux != nullptr && aux->info != info){
        anterior = aux;
        aux = aux->prox;
    }

    if(aux == nullptr)
        return;

    if(aux == anterior)
        this->cabeca = aux->prox;

    else
        anterior->prox = aux->prox;

    delete aux;
}

void Lista::imprimirLista()
{
    No* aux = cabeca;

    while(aux != nullptr){
        cout << "|" << aux->info << "|->";
        aux = aux->prox;
    }

    cout << "NULL" << endl;
}

Lista::~Lista()
{
    liberarLista(cabeca);
}

void Lista::liberarLista(No* cabeca)
{
    if(cabeca == nullptr)
        return;

    liberarLista(cabeca->prox);
    delete cabeca;
}
