#ifndef FUNCIONARIO_H_INCLUDED
#define FUNCIONARIO_H_INCLUDED
#include <iostream>

using namespace std;

class Funcionario{

protected:
    string nome;
    double salario;

public:
    Funcionario();

    string getNome() const;

    void setNome(string nome);

    double getSalario() const;

    void setSalario(double salario);

    void addAumento(double valor);

    double ganhoAnual();

    void exibeDados();

    ~Funcionario();
};

#endif // FUNCIONARIO_H_INCLUDED
