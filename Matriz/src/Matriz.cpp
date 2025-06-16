#include "Matriz.h"
#include <iostream>
#include <exception>

using namespace std;

Matriz::Matriz(int nl, int nc) : nl(nl), nc(nc)
{
    if((nl <= 0) | (nc <= 0) | (nl > MAX) | (nc > MAX))
        throw invalid_argument("Tamanhos invalidos de matriz\n");

    for(int i = 0; i < nl; i++){
        for(int j = 0; j < nc; j++){
            m[i][j] = 0;
        }
    }
}

Matriz::Matriz(int nl, int nc, int valor) : nl(nl), nc(nc)
{
    if((nl <= 0) | (nc <= 0) | (nl > MAX) | (nc > MAX))
        throw invalid_argument("Tamanhos invalidos de matriz\n");

    for(int i = 0; i < nl; i++)
        for(int j = 0; j < nc; j++)
            m[i][j] = valor;
}

int Matriz::getXY(int x, int y) const
{
    if((x < 0) | (y < 0) | (x > nl) | (y > nc))
        throw invalid_argument("Tamanho de x e/ou y fora da faixa\n");

    return m[x][y];
}

void Matriz::setXY(int x, int y, int valor)
{
    if((x < 0) | (y < 0) | (x > nl) | (y > nc))
        throw invalid_argument("Tamanho de x e/ou y fora da faixa\n");

    m[x][y] = valor;
}

istream& operator>>(istream& in, Matriz& m)
{
    cout << "Digite os " << m.nl * m.nc << " elementos da matriz: " << "[" << m.nl << "x" << m.nc << "]" << endl;

    for(int i = 0; i < m.nl; i++)
        for(int j = 0; j < m.nc; j++)
            in >> m.m[i][j];

    return in;
}

ostream& operator<<(ostream& out, const Matriz& m)
{
    for(int i = 0; i < m.nl; i++){
        for(int j = 0; j < m.nc; j++){
            out << m.m[i][j] << " ";
        }
        out << endl;
    }
    return out;
}

bool Matriz::operator==(const Matriz &m)
{
    if(nl != m.nl && nc != m.nc)
        throw invalid_argument("Tamanho invalido de matrizes, nao eh possivel fazer comparacao semantica\n");

    bool result = true;

    for(int i = 0; i < nl; i++)
        for(int j = 0; j < nc; j++)
            if(this->m[i][j] != m.getXY(i, j))
                result = false;

    return result;
}

Matriz* Matriz::getTransposta()
{
    Matriz* transposta = new Matriz(nc, nl);

    for(int i = 0; i < nl; i++){
        for(int j = 0; j < nc; j++){
            transposta->setXY(j, i, this->m[i][j]);
        }
    }
    return transposta;
}

Matriz* Matriz::getOposta()
{
    Matriz* oposta = new Matriz(nl, nc);

    for(int i = 0; i < nl; i++){
        for(int j = 0; j < nc; j++){
            oposta->setXY(i, j, -m[i][j]);
        }
    }
    return oposta;
}

Matriz* Matriz::getNula()
{
    Matriz* nula = new Matriz(nl, nc);

    return nula;
}

bool Matriz::isIdentidade()
{
    if(nl != nc)
        return false;

    bool result = true;

    for(int i = 0; i < nl; i++){
        for(int j = 0; j < nc; j++){
            if(i == j && getXY(i, j) != 1)
                result = false;

            else if(i != j && getXY(i, j) != 0)
                result = false;
        }
    }
    return result;
}

bool Matriz::isDiagonal()
{
    if(nl != nc)
        throw invalid_argument("Tamanhos diferentes de matriz\n");

    for(int i = 0; i < nl; i++)
        for(int j = 0; j < nc; j++)
            if(i != j && m[i][j] != 0)
                return false;

    return true;
}

bool Matriz::isSimetrica()
{
    if(nl != nc)
        return false;

    for(int i = 0; i < nl; i++)
        for(int j = 0; j < nc; j++)
            if(m[i][j] != m[j][i])
                return false;

    return true;
}

bool Matriz::isAntiSimetria()
{
    if(nl != nc)
        return false;

    for(int i = 0; i < nl; i++)
        for(int j = 0; j < nc; j++)
            if(m[i][j] != -m[j][i])
                return false;

    return true;
}

Matriz* Matriz::operator+(const Matriz &m)
{
    if(nl != m.nl || nc != m.nc)
        throw invalid_argument("Tamanho diferente de matrizes, nao eh possivel fazer soma\n");

    Matriz* nova = new Matriz(nl, nc);

    for(int i = 0; i < nl; i++){
        for(int j = 0; j < nc; j++){
            nova->setXY(i, j, (this->m[i][j]+m.m[i][j]) );
        }
    }

    return nova;
}

void Matriz::operator+=(const Matriz &m)
{
    if(nl != m.nl || nc != m.nc)
        throw invalid_argument("Tamanho diferente de matrizes, nao eh possivel fazer soma\n");

    for(int i = 0; i < nl; i++)
        for(int j = 0; j < nc; j++)
            this->m[i][j] += m.m[i][j];
}

Matriz* Matriz::operator-(const Matriz &m)
{
    if(nl != m.nl || nc != m.nc)
        throw invalid_argument("Tamanho diferente de matrizes, nao eh possivel fazer soma\n");

    Matriz* nova = new Matriz(nl, nc);

    for(int i = 0; i < nl; i++)
        for(int j = 0; j < nc; j++)
            nova->setXY(i, j, (this->m[i][j]-m.m[i][j]) );

    return nova;
}

void Matriz::operator-=(const Matriz& m)
{
    if(nl != m.nl || nc != m.nc)
        throw invalid_argument("Tamanho diferente de matrizes, nao eh possivel fazer soma\n");

    for(int i = 0; i < nl; i++)
        for(int j = 0; j < nc; j++)
            this->m[i][j] -= m.m[i][j];
}

Matriz* Matriz::operator*(const Matriz& m)
{
    if(this->nc != m.nl)
        return nullptr;

    Matriz* resultado = new Matriz(this->nl, m.nc);

    for(int i = 0; i < this->nl; i++){
        for(int j = 0; j < m.nc; j++){
            int soma = 0;
            for(int k = 0; k < this->nc; k++)
                soma += this->m[i][k] * m.m[k][j];

            resultado->setXY(i, j, soma);
        }
    }
    return resultado;
}

Matriz* Matriz::multiplica(const Matriz& m)
{
    return (*this) * m;
}

Matriz* Matriz::clone()
{
    Matriz* novo = new Matriz(nl, nc);

    for(int i = 0; i < nl; i++)
        for(int j = 0; j < nc; j++)
            novo->setXY(i, j, m[i][j]);

    return novo;
}

void Matriz::mostrar()
{
    for(int i = 0; i < nl; i++){
        for(int j = 0; j < nc; j++)
            cout << m[i][j] << " ";
        cout << endl;
    }
}

Matriz::~Matriz()
{

}
