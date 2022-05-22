#ifndef PEON_HPP
#define PEON_HPP

#include"Pieza.hpp"
#include"casilla.hpp"

class peon: public pieza {
private:
    unsigned m_c; /// Cuenta el numero de movimientos, para que en el primero se pueda mover dos casillas
    int pos[8];
public:
    peon();
    peon(unsigned x, unsigned y, unsigned color);
    void dibujar();
    void borrar();
    int* posiblesmov();

};

#endif // PEON_HPP
