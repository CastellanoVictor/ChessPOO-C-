#ifndef CASILLA_HPP
#define CASILLA_HPP

#include"Pieza.hpp"

class casilla {
private:
    unsigned m_x1;
    unsigned m_y1;
    int m_color;
    pieza* m_p;

public:
    casilla();
    casilla (unsigned x1,unsigned y1,int color);
    void insertar(pieza* p);
    void mostrar();
    void mostrar(unsigned color);
    casilla& operator=(casilla other);
    pieza* getpieza();
    friend class tablero;
};

#endif // CASILLA_HPP
