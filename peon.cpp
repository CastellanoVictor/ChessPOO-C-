#include "peon.hpp"
#include <graphics.h>
//Constructor por defecto
peon::peon():pieza(){
m_nombre="peon";
m_jugadas=8;
}
//Constructor parametrico
peon::peon(unsigned x, unsigned y, unsigned color){
    m_x=x;
    m_y=y;
    m_color=color;
    m_valor=1;
    m_contador=0;
    m_jugadas=8;
}
//Dibuja el peon en el tablero a partir de las coordenadas de la casilla
//en la que se quiere dibujar y el color correspondiente
void peon::dibujar(){
    unsigned x,y;
    x=(m_x*75)+400;
    y=(m_y*75)+50;
    setcolor(m_color);
    setfillstyle(SOLID_FILL,m_color);
    fillellipse(x+40,y+20,7,7);
    fillellipse(x+40,y+29,7,2);
    arc(x+72,y+30,180,240,30);
    arc(x+8,y+30,300,0,30);
    rectangle(x+20,y+55,x+60,y+63);
}
//Borra la pieza, redibujandola del color de la casilla en la que se encuentra
    void peon::borrar(){
    unsigned x,y;
    x=(m_x*75)+400;
    y=(m_y*75)+50;
    unsigned color=getpixel(x+1,y+1);
    setcolor(color);
    setfillstyle(SOLID_FILL,color);
    fillellipse(x+40,y+20,7,7);
    fillellipse(x+40,y+29,7,2);
    arc(x+72,y+30,180,240,30);
    arc(x+8,y+30,300,0,30);
    rectangle(x+20,y+55,x+60,y+63);
    }
//Esta apuntador de tipo entero almacena los posibles movimientos de la pieza dentro de un vector
//los elementos pares del vector almacenan las coordenadas x
//los elementos impares del vector almacenan las coordenadas y
    int* peon::posiblesmov(){
        if(m_color==2){
        pos[0]=0;   pos[1]=1;
        pos[2]=1;   pos[3]=1;
        pos[4]=-1;  pos[5]=1;
        pos[6]=0;   pos[7]=2;}
        else{
        pos[0]=0;   pos[1]=-1;
        pos[2]=1;   pos[3]=-1;
        pos[4]=-1;  pos[5]=-1;
        pos[6]=0;   pos[7]=-2;}
        return pos;
    }



