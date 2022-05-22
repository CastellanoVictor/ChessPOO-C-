#ifndef DAMA_HPP
#define DAMA_HPP

#include"Pieza.hpp"

class dama:public pieza{
private:
    int pos[112];
public:
    dama();
    dama(unsigned x, unsigned y, unsigned color);
    void dibujar();
    void borrar();
    int* posiblesmov();

};

#endif // DAMA_HPP

