#ifndef PONTO_H_INCLUDED
#define PONTO_H_INCLUDED

class Ponto
{
protected:
    double x;
    double y;
public:
    Ponto();

    void setX(double x);

    double getX();

    void setY(double y);

    double getY();

    void mostrar();

    ~Ponto();
};

#endif // PONTO_H_INCLUDED
