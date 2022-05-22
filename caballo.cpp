#include "caballo.hpp"
#include <graphics.h>
#include <iostream>
//Constructor por defecto
caballo::caballo():pieza(){}
//Constructor parametrico
caballo::caballo(unsigned x, unsigned y, unsigned color){
    m_x=x;
    m_y=y;
    m_color=color;
    m_valor=3;
    m_nombre="caballo";
    m_jugadas=8;
}
//Dibuja al caballo en el tablero a partir de las coordenadas de la casilla
//en la que se quiere dibujar y el color correspondiente
void caballo::dibujar(){
    unsigned x,y;
    x=(m_x*75)+400;
    y=(m_y*75)+50;
    y+=8;
    setcolor(m_color);
    setfillstyle(SOLID_FILL,m_color);
    line(x+15,y+15,x+40,y+0);
    line(x+40,y+0,x+40,y-5);
    line(x+40,y-5,x+45,y+0);
    line(x+45,y+0,x+60,y+5);
    line(x+60,y+5,x+55,y+35);
    line(x+55,y+35,x+45,y+45);
    line(x+30,y+45,x+25,y+35);
    line(x+25,y+35,x+45,y+20);
    line(x+45,y+20,x+20,y+25);
    line(x+20,y+25,x+15,y+15);
    rectangle(x+25,y+45,x+45,y+50);
    rectangle(x+15,y+50,x+55,y+60);
    setfillstyle(SOLID_FILL,m_color);
    fillellipse(x+43,y+7,4,4);
    fillellipse(x+20,y+18,2,2);
}
//Borra la pieza, redibujandola del color de la casilla en la que se encuentra
    void caballo::borrar(){
       unsigned x,y;
    x=(m_x*75)+400;
    y=(m_y*75)+50;
    y+=8;
    unsigned color=getpixel(x+1,y+1);
    setcolor(color);
    setfillstyle(SOLID_FILL,color);
    line(x+15,y+15,x+40,y+0);
    line(x+40,y+0,x+40,y-5);
    line(x+40,y-5,x+45,y+0);
    line(x+45,y+0,x+60,y+5);
    line(x+60,y+5,x+55,y+35);
    line(x+55,y+35,x+45,y+45);
    line(x+30,y+45,x+25,y+35);
    line(x+25,y+35,x+45,y+20);
    line(x+45,y+20,x+20,y+25);
    line(x+20,y+25,x+15,y+15);
    rectangle(x+25,y+45,x+45,y+50);
    rectangle(x+15,y+50,x+55,y+60);
    setfillstyle(SOLID_FILL,color);
    fillellipse(x+43,y+7,4,4);
    fillellipse(x+20,y+18,2,2);
    }
//Esta apuntador de tipo entero almacena los posibles movimientos de la pieza dentro de un vector
//los elementos pares del vector almacenan las coordenadas x
//los elementos impares del vector almacenan las coordenadas y
    int* caballo::posiblesmov(){
        pos[0]=2;   pos[1]=1;
        pos[2]=2;   pos[3]=-1;
        pos[4]=-2;  pos[5]=1;
        pos[6]=-2;  pos[7]=-1;
        pos[8]=1;   pos[9]=2;
        pos[10]=1;  pos[11]=-2;
        pos[12]=-1; pos[13]=2;
        pos[14]=-1; pos[15]=-2;
        return pos;
    }



