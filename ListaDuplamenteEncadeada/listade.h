#ifndef LISTA_DUPLAMENTE_ENCADEADA_H_INCLUDED
#define LISTA_DUPLAMENTE_ENCADEADA_H_INCLUDED

#include <iostream>
using namespace std;

template <class Tipo>

class Lista
{
private:
    class No
    {
    private:
        Tipo info;
        No* ant;
        No* prox;
    public:
        No(Tipo info, No* ant=nullptr, No* prox=nullptr)
        {
            this->info = info;
            this->ant = ant;
            this->prox = prox;
        }

        Tipo getInfo()
        {
            return info;
        }

        No* getAnt()
        {
            return ant;
        }

        void setAnt(No* ant)
        {
            this->ant = ant;
        }

        No* getProx()
        {
            return prox;
        }

        void setProx(No* prox)
        {
            this->prox = prox;
        }
    };
    No* l = nullptr;

private:
    int vazia(No* p)
    {
        return (p == nullptr);
    }
public:
    void inserir(Tipo info)
    {
        if(vazia(l))
            l = new No(info);

        else{
            No* aux = l;
            No* novo;

            while(!vazia(aux->getProx()) && aux->getInfo() <= info)
                aux = aux->getProx();

            if(l == aux && aux->getInfo() > info){
                novo = new No(info, nullptr, aux);
                aux->setAnt(novo);
                l = novo;
            }

            else{
                No* p = aux->getAnt();

                if(aux->getInfo() <= info){
                    novo = new No(info, aux, nullptr);
                    aux->setProx(novo);
                }
                else{
                    novo = new No(info, p, p->getProx());
                    p->setProx(novo);
                    aux->setAnt(novo);
                }
            }
        }
    }

    void remover(Tipo info)
    {
        if(vazia(l))
            return;

        No* aux = l;

        while(!vazia(aux) && aux->getInfo() != info)
            aux = aux->getProx();

        if(vazia(aux))
            return;

        else if(aux == l){
            l = aux->getProx();

            if(!vazia(l))
                l->setAnt(nullptr);
        }

        else{
            aux->getAnt()->setProx(aux->getProx());

            if(!vazia(aux->getProx()))
                aux->getProx()->setAnt(aux->getAnt());
        }
        delete aux;
    }

    void imprimir()
    {
        No* aux = l;

        cout << "[";
        while(!vazia(aux->getProx())){
            cout << aux->getInfo() << ", ";
            aux = aux->getProx();
        }

        cout << aux->getInfo() << "]" << endl;
        cout << "[";
        while(!vazia(aux->getAnt())){
            cout << aux->getInfo() << ", ";
            aux = aux->getAnt();
        }

        cout << aux->getInfo() << "]" << endl;
    }

    ~Lista()
    {
        No* aux = l;

        while(!vazia(aux)){
            No* proximo = aux->getProx();
            delete aux;
            aux = proximo;
        }
    }
};

#endif // LISTA_DUPLAMENTE_ENCADEADA_H_INCLUDED
