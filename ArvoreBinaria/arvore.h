#ifndef ARVORE_BINARIA_DE_BUSCA_H_INCLUDED
#define ARVORE_BINARIA_DE_BUSCA_H_INCLUDED

#include <iostream>
#include <queue>
using namespace std;

template <class Tipo>

class Arvore
{
    private:
    class No
    {
        Tipo info;
        No* esq;
        No* dir;

    public:
        No(Tipo info, No* esq=nullptr, No* dir=nullptr)
        {
            this->info = info;
            this->esq = esq;
            this->dir = dir;
        }

        Tipo getInfo()
        {
            return info;
        }

        void setInfo(Tipo info)
        {
            this->info = info;
        }

        No* getEsq()
        {
            return esq;
        }

        void setEsq(No* esq=nullptr)
        {
            this->esq = esq;
        }

        No* getDir()
        {
            return dir;
        }

        void setDir(No* dir=nullptr)
        {
            this->dir = dir;
        }
    };
    No* r = nullptr;
    private:
        int vazia(No* p)
        {
            return (p == nullptr);
        }

        No* inserir_aux(No* r, Tipo info)
        {
            if(vazia(r))
                r = new No(info);

            else if(r->getInfo() < info)
                r->setDir(inserir_aux(r->getDir(), info));

            else if(r->getInfo() > info)
                r->setEsq(inserir_aux(r->getEsq(), info));

            return r;
        }

        No* remover_aux(No* r, Tipo info)
        {
            if(vazia(r))
                return r;

            else if(r->getInfo() > info)
                r->setEsq(remover_aux(r->getEsq(), info));

            else if(r->getInfo() < info)
                r->setDir(remover_aux(r->getDir(), info));

            else{
                if(vazia(r->getEsq()) && vazia(r->getDir())){
                    delete r;
                    return nullptr;
                }
                else if(vazia(r->getDir())){
                    r->setInfo(maximo(r->getEsq()));
                    r->setEsq(remover_aux(r->getEsq(), r->getInfo()));
                }
                else{
                    r->setInfo(minimo(r->getDir()));
                    r->setDir(remover_aux(r->getDir(), r->getInfo()));
                }
            }
            return r;
        }

        int maximo(No* p)
        {
            while(!vazia(p->getDir()))
                p = p->getDir();

            return p->getInfo();
        }

        int minimo(No* p)
        {
            while(!vazia(p->getEsq()))
                p = p->getEsq();

            return p->getInfo();
        }

        void imprimir_aux(No* r)
        {
            if(vazia(r))
                return;

            cout << r->getInfo() << endl;

            imprimir_aux(r->getEsq());
            imprimir_aux(r->getDir());
        }

        void liberar(No* r)
        {
            if(vazia(r))
                return;

            liberar(r->getEsq());
            liberar(r->getDir());

            delete r;
        }

        int busca_aux(No* r, Tipo info)
        {
            if(vazia(r))
                return -1;

            else if(r->getInfo() > info)
                return busca_aux(r->getEsq(), info);

            else if(r->getInfo() < info)
                return busca_aux(r->getDir(), info);

            else
                return r->getInfo();
        }
    public:
        void inserir(Tipo info)
        {
            r = inserir_aux(r, info);
        }

        void imprimir()
        {
            imprimir_aux(r);
        }

        void remover(Tipo info)
        {
            r = remover_aux(r, info);
        }

        void imprimir_niveis()
        {
            if(vazia(r))
                return;

            queue<No*> q;
            q.push(r);
            q.push(nullptr);
            cout << "[";

            while(!q.empty()){
                No* atual = q.front();
                q.pop();

                if(vazia(atual)){
                    cout << "]" << endl;

                    if(!q.empty()){
                        cout << "[";
                        q.push(nullptr);
                    }
                }
                else{
                    cout << atual->getInfo();

                    if(!vazia(atual->getEsq()))
                        q.push(atual->getEsq());

                    if(!vazia(atual->getDir()))
                        q.push(atual->getDir());

                    atual = q.front();
                    if(atual != nullptr)
                        cout << ", ";
                }
            }
        }

        int busca(Tipo info)
        {
            return busca_aux(r, info);
        }

        ~Arvore()
        {
            liberar(r);
        }
};

#endif // ARVORE_BINARIA_DE_BUSCA_H_INCLUDED
