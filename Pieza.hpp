#ifndef PIEZA_HPP
#define PIEZA_HPP
#include <string>

class pieza{
protected:
    unsigned  m_valor;
    unsigned  m_x;
    unsigned  m_y;
    unsigned m_color;
    unsigned m_jugadas;
    std::string m_nombre;
    unsigned m_contador;

public:
    virtual int* posiblesmov()=0;
    virtual ~pieza();
    virtual void dibujar()=0;
    virtual void borrar()=0;
    unsigned getcolor();
    unsigned atx();
    unsigned aty();
    unsigned getjugadas();
    unsigned getcontador();
    unsigned getvalor();
    std::string getnombre();
    void repos(unsigned x,unsigned y);
    void modcont();
};





#endif // PIEZA_HPP
