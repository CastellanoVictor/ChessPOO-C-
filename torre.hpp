#ifndef TORRE_HPP
#define TORRE_HPP

#include"Pieza.hpp"

class torre:public pieza{
private:
    int pos[56];
public:
    torre ();
    torre(unsigned x, unsigned y, unsigned color);
    void dibujar();
    void borrar();
    int* posiblesmov();

};

#endif // TORRE_HPP

