#ifndef PONTO_H_INCLUDED
#define PONTO_H_INCLUDED

class Ponto{

private:
    double x;
    double y;

public:
    Ponto();

    void setX(double x);

    double getX() const;

    void setY(double y);

    double getY() const;

    void imprimirPontos();

    double distanciaPontos();
};

#endif // PONTO_H_INCLUDED
