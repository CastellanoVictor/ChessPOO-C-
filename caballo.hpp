#ifndef CABALLO_HPP
#define CABALLO_HPP

#include"Pieza.hpp"

class caballo:public pieza{
private:
    int pos[16];
public:
    caballo();
    caballo(unsigned x, unsigned y, unsigned color);
    void dibujar();
    void borrar();
    int* posiblesmov();

};

#endif // CABALLO_HPP

