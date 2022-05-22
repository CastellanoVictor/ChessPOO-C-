#include <iostream>
#include "Pieza.hpp"
#include "casilla.hpp"
#include "tablero.hpp"
#include "peon.hpp"
#include "caballo.hpp"
#include "dama.hpp"
#include "alfil.hpp"
#include "rey.hpp"
#include "torre.hpp"
#include<graphics.h>


unsigned getindexg(unsigned x, unsigned y)
 {
     x=(x-400)/75;
     y=(y-50)/75;
     return y*8+x;
 }

void inicia_grafico() {
    int gd = DETECT,gm;
    initgraph(&gd,&gm,"C:\\TC\\BGI");
    delay(100);
}

void checarmate (tablero A){
    for(int i=0;i<64;i+=1){
        A.checar(i);
    }
}

int main(){
     tablero A;
   inicia_grafico();
   initwindow(1200,1200);
   A.mostrar();
   int _x,_y=10,color=9;
   while ((A.getcasilla(A.indice(A.getrbl().atx(),A.getrbl().aty())).getpieza()->getnombre()=="rey") && (A.getcasilla(A.indice(A.getrgr().atx(),A.getrgr().aty())).getpieza()->getnombre()=="rey")) {
        checarmate(A);
        do{
            while (!ismouseclick(WM_LBUTTONDOWN)) {}
      getmouseclick(WM_LBUTTONDOWN,_x,_y);
    clearmouseclick(WM_LBUTTONDOWN);
    std::cout<<"while"<<std::endl;
        }
    while((A.getcasilla(getindexg(_x,_y)).getpieza()==nullptr)||(A.getcasilla(getindexg(_x,_y)).getpieza()->getcolor()!=color));
    if(color==9)color=2;
    else color=9;
   A.moverpieza(_x,_y);
}
   closegraph();
    return 0;
}
