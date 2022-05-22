#include "alfil.hpp"
#include <graphics.h>
//Constructor por defecto
alfil::alfil():pieza(){}
//Constructor parametrico
alfil::alfil(unsigned x, unsigned y, unsigned color){
    m_x=x;
    m_y=y;
    m_color=color;
    m_valor=3;
    m_nombre="alfil";
    m_jugadas=28;
}
//Dibuja el alfil en el tablero a partir de las coordenadas de la casilla
//en la que se quiere dibujar y el color correspondiente
void alfil::dibujar(){
        unsigned x,y;
        x=(m_x*75)+400;
        y=(m_y*75)+50;
    setcolor(m_color);
    setfillstyle(SOLID_FILL,m_color);
    fillellipse(x+40,y+30,17,15);
    fillellipse(x+40,y+13,4,4);
    arc(x+70,y+25,210,270,30);
    arc(x+70,y+33,200,270,30);
    arc(x+10,y+25,270,330,30);
    arc(x+10,y+33,270,340,30);
    line(x+9,y+55,x+9,y+63);
    line(x+69,y+55,x+69,y+63);
    rectangle(x+37,y+22,x+43,y+38);
    setfillstyle(SOLID_FILL,m_color);
    rectangle(x+32,y+27,x+48,y+33);
}
//Borra la pieza, redibujandola del color de la casilla en la que se encuentra
    void alfil::borrar(){
        unsigned x,y;
        x=(m_x*75)+400;
        y=(m_y*75)+50;
    unsigned color=getpixel(x+1,y+1);
    setcolor(color);
    setfillstyle(SOLID_FILL,color);
    fillellipse(x+40,y+30,17,15);
    fillellipse(x+40,y+13,4,4);
    arc(x+70,y+25,210,270,30);
    arc(x+70,y+33,200,270,30);
    arc(x+10,y+25,270,330,30);
    arc(x+10,y+33,270,340,30);
    line(x+9,y+55,x+9,y+63);
    line(x+69,y+55,x+69,y+63);
    rectangle(x+37,y+22,x+43,y+38);
    setfillstyle(SOLID_FILL,m_color);
    rectangle(x+32,y+27,x+48,y+33);
    }
//Esta apuntador de tipo entero almacena los posibles movimientos de la pieza dentro de un vector
//los elementos pares del vector almacenan las coordenadas x
//los elementos impares del vector almacenan las coordenadas y
    int* alfil::posiblesmov(){
                      pos[0]=1;    pos[1]=1;
                      pos[2]=2;    pos[3]=2;
                      pos[4]=3;    pos[5]=3;
                      pos[6]=4;    pos[7]=4;
                      pos[8]=5;    pos[9]=5;
                      pos[10]=6;   pos[11]=6;
                      pos[12]=7;   pos[13]=7;
                      pos[14]=-1;  pos[15]=-1;
                      pos[16]=-2;  pos[17]=-2;
                      pos[18]=-3;  pos[19]=-3;
                      pos[20]=-4;  pos[21]=-4;
                      pos[22]=-5;  pos[23]=-5;
                      pos[24]=-6;  pos[25]=-6;
                      pos[26]=-7;  pos[27]=-7;
                      pos[28]=-1;  pos[29]=1;
                      pos[30]=-2;  pos[31]=2;
                      pos[32]=-3;  pos[33]=3;
                      pos[34]=-4;  pos[35]=4;
                      pos[36]=-5;  pos[37]=5;
                      pos[38]=-6;  pos[39]=6;
                      pos[40]=-7;  pos[41]=7;
                      pos[42]=1;   pos[43]=-1;
                      pos[44]=2;   pos[45]=-2;
                      pos[46]=3;   pos[47]=-3;
                      pos[48]=4;   pos[49]=-4;
                      pos[50]=5;   pos[51]=-5;
                      pos[52]=6;   pos[53]=-6;
                      pos[54]=7;   pos[55]=-7;
        return pos;
    }



