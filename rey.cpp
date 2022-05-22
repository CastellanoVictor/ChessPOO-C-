#include "rey.hpp"
#include <graphics.h>
//Constructor por defecto
rey::rey():pieza(){}
//Constructor parametrico
rey::rey(unsigned x, unsigned y, unsigned color){
    m_x=x;
    m_y=y;
    m_color=color;
    m_valor=3;
    m_nombre="rey";
    m_jugadas=8;
}
//Dibuja al rey en el tablero a partir de las coordenadas de la casilla
//en la que se quiere dibujar y el color correspondiente
void rey::dibujar(){
    unsigned x,y;
    x=(m_x*75)+400;
    y=(m_y*75)+50;
    setcolor(m_color);
    setfillstyle(SOLID_FILL,m_color);
    y+=5;
    int ax[24]={40,50, 42,40, 45,30, 51,22, 60,20, 67,22, 70,30, 68,35, 64,40, 60,45, 58,50, 40,50};
    int ay[24];
    for(int i=0;i<24;i+=2){
        ay[i]=x+80-ax[i];
        ay[i+1]=y+ax[i+1];
        ax[i]+=x;
        ax[i+1]+=y;
    }
    drawpoly(12,ax);
    drawpoly(12,ay);
    rectangle(x+20,y+50,x+60,y+60);
    int az[14]={45,30, 42,24, 41,21, 40,20, 39,21, 38,24, 35,30};
    for(int i=0;i<14;i+=2){
        az[i]+=x;
        az[i+1]+=y;
    }
    drawpoly(7,az);
    bar(x+38,y+6,x+42,y+24);
    bar(x+33,y+10,x+47,y+14);
}
//Borra la pieza, redibujandola del color de la casilla en la que se encuentra
void rey::borrar(){
    unsigned x,y;
    x=(m_x*75)+400;
    y=(m_y*75)+50;
    unsigned color=getpixel(x+1,y+1);
    setcolor(color);
    setfillstyle(SOLID_FILL,color);
    y+=5;
    int ax[24]={40,50, 42,40, 45,30, 51,22, 60,20, 67,22, 70,30, 68,35, 64,40, 60,45, 58,50, 40,50};
    int ay[24];
    for(int i=0;i<24;i+=2){
        ay[i]=x+80-ax[i];
        ay[i+1]=y+ax[i+1];
        ax[i]+=x;
        ax[i+1]+=y;
    }
    drawpoly(12,ax);
    drawpoly(12,ay);
    rectangle(x+20,y+50,x+60,y+60);
    int az[14]={45,30, 42,24, 41,21, 40,20, 39,21, 38,24, 35,30};
    for(int i=0;i<14;i+=2){
        az[i]+=x;
        az[i+1]+=y;
    }
    drawpoly(7,az);
    bar(x+38,y+6,x+42,y+24);
    bar(x+33,y+10,x+47,y+14);
}
//Esta apuntador de tipo entero almacena los posibles movimientos de la pieza dentro de un vector
//los elementos pares del vector almacenan las coordenadas x
//los elementos impares del vector almacenan las coordenadas y
int* rey::posiblesmov(){

    pos[0]=0;   pos[1]=1;
    pos[2]=0;   pos[3]=-1;
    pos[4]=1;   pos[5]=0;
    pos[6]=1;   pos[7]=1;
    pos[8]=1;   pos[9]=-1;
    pos[10]=-1; pos[11]=0;
    pos[12]=-1; pos[13]=1;
    pos[14]=-1; pos[15]=-1;

    return pos;
}


