#ifndef TABLERO_HPP
#define TABLERO_HPP


#include "peon.hpp"
#include "caballo.hpp"
#include "dama.hpp"
#include "alfil.hpp"
#include "rey.hpp"
#include "torre.hpp"
#include "casilla.hpp"
#include <string>



class tablero{
private:
    casilla m_c[64];
    int matriz[8][8];
    peon m_pbl [8];
    peon m_pgr [8];
    rey m_rbl;
    rey m_rgr;
    dama m_dbl;
    dama m_dgr;
    caballo m_cbl[2];
    caballo m_cgr[2];
    torre m_tbl[2];
    torre m_tgr[2];
    alfil m_abl[2];
    alfil m_agr[2];


public:
    tablero();
    void mostrar();
    unsigned getindexgraf(unsigned x, unsigned y);
    unsigned indice(unsigned x,unsigned y);
    casilla getcasilla(unsigned index) const;
    void checarmov (int* pos, unsigned index);
    void checarpeon (unsigned index);
    void checarreycab(int* pos, unsigned index);
    void moverpieza(unsigned x, unsigned y);
    void mover(unsigned xold, unsigned yold, unsigned xnew, unsigned ynew);
    casilla getcasilla(unsigned index);
    void checar(unsigned index);
    rey getrgr();
    rey getrbl();
    void checarreycabl(int* pos, unsigned index);
    void checarpeonl(unsigned index);
    void checarmovl(int* pos, unsigned index);
};
#endif // TABLERO_HPP
