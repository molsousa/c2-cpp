#include <iostream>
#include "funcionario.h"

using namespace std;

Funcionario::Funcionario()
{
    string tempNome;
    double tempSalario;

    cout << "Digite o nome: ";
    cin >> tempNome;
    cout << "Digite o salario: ";
    cin >> tempSalario;

    setNome(tempNome);
    setSalario(tempSalario);
}

string Funcionario::getNome() const
{
    return nome;
}
void Funcionario::setNome(string nome)
{
    this->nome = nome;
}

double Funcionario::getSalario() const
{
    return salario;
}
void Funcionario::setSalario(double salario)
{
    this->salario = salario;
}

void Funcionario::addAumento(double valor)
{
    this->salario += valor;
}

double Funcionario::ganhoAnual()
{
    return (salario*12);
}

void Funcionario::exibeDados()
{
    cout << "======================" << endl;
    cout << "Funcionario: " << getNome() << endl;
    cout << "Salario: R$ " << getSalario() << endl;
    cout << "======================" << endl;
}

Funcionario::~Funcionario()
{
    cout << "Obrigado!!" << endl;
}
