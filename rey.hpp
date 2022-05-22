#ifndef REY_HPP
#define REY_HPP

#include"Pieza.hpp"

class rey:public pieza{
private:
    int pos[16];
public:
    rey();
    rey(unsigned x, unsigned y, unsigned color);
    void dibujar();
    void borrar();
    int* posiblesmov();

};

#endif // REY_HPP

