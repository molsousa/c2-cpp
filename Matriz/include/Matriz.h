#ifndef MATRIZ_H
#define MATRIZ_H
#define MAX 50
#include <iostream>

using namespace std;

class Matriz
{
    public:
        int m[MAX][MAX];
        int nl;
        int nc;

        Matriz(int nl, int nc);

        Matriz(int nl, int nc, int valor);

        int getXY(int x, int y) const;

        void setXY(int x, int y, int valor);

        friend istream& operator >> (istream& in, Matriz& m);

        friend ostream& operator << (istream& out, const Matriz &m);

        bool operator==(const Matriz &m);

        Matriz* getTransposta();

        Matriz* getOposta();

        Matriz* getNula();

        bool isIdentidade();

        bool isDiagonal();

        bool isSingular();

        bool isSimetrica();

        bool isAntiSimetria();

        Matriz* operator+(const Matriz &m);

        void operator+=(const Matriz &m);

        Matriz* operator-(const Matriz &m);

        void operator-=(const Matriz &m);

        Matriz* operator*(const Matriz &m);

        Matriz* multiplica(const Matriz &m);

        Matriz* clone();

        void mostrar();

        ~Matriz();
};

#endif // MATRIZ_H
