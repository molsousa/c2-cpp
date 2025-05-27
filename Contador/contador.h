#ifndef CONTADOR_H_INCLUDED
#define CONTADOR_H_INCLUDED

class Contador{
private:
    int contador;
public:
    Contador();

    void zerar();

    void incrementar();

    int valorAtual();

    ~Contador();
};

#endif // CONTADOR_H_INCLUDED
