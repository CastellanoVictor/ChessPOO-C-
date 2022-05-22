#ifndef ALFIL_HPP
#define ALFIL_HPP

#include"Pieza.hpp"

class alfil:public pieza{
private:
    int pos[56];
public:
    alfil();
    alfil(unsigned x, unsigned y, unsigned color);
    void dibujar();
    void borrar();
    int* posiblesmov();

};

#endif // ALFIL_HPP
