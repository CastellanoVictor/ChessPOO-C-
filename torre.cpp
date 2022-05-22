#include "torre.hpp"
#include <graphics.h>
//Constructor por defecto
torre::torre():pieza(){}
//Constructor parametrico
torre::torre(unsigned x, unsigned y, unsigned color){
    m_x=x;
    m_y=y;
    m_color=color;
    m_valor=5;
    m_nombre="torre";
    m_jugadas=28;
}
//Dibuja la torre en el tablero a partir de las coordenadas de la casilla
//en la que se quiere dibujar y el color correspondiente
void torre::dibujar(){
         unsigned x,y;
                x=(m_x*75)+400;
                y=(m_y*75)+50;
    setcolor(m_color);
    setfillstyle(SOLID_FILL,m_color);
 y-=5;
    int ax[30]={20,20, 30,20, 30,30, 35,30, 35,20, 45,20, 45,30, 50,30, 50,20, 60,20, 60,35, 50,45, 30,45, 20,35, 20,20};
    for(int i=0;i<30;i+=2){
        ax[i]+=x;
        ax[i+1]+=y;
    }
    drawpoly(15,ax);
    rectangle(x+30,y+45,x+50,y+60);
    line(x+20,y+65,x+30,y+60);
    line(x+60,y+65,x+50,y+60);
    rectangle(x+20,y+65,x+60,y+70);
}
//Borra la pieza, redibujandola del color de la casilla en la que se encuentra
    void torre::borrar(){
    unsigned x,y;
    x=(m_x*75)+400;
    y=(m_y*75)+50;
    setcolor(m_color);
    unsigned color=getpixel(x+1,y+1);
    setcolor(color);
    setfillstyle(SOLID_FILL,color);
      y-=5;
    int ax[30]={20,20, 30,20, 30,30, 35,30, 35,20, 45,20, 45,30, 50,30, 50,20, 60,20, 60,35, 50,45, 30,45, 20,35, 20,20};
    for(int i=0;i<30;i+=2){
        ax[i]+=x;
        ax[i+1]+=y;
    }
    drawpoly(15,ax);
    rectangle(x+30,y+45,x+50,y+60);
    line(x+20,y+65,x+30,y+60);
    line(x+60,y+65,x+50,y+60);
    rectangle(x+20,y+65,x+60,y+70);
    }
//Esta apuntador de tipo entero almacena los posibles movimientos de la pieza dentro de un vector
//los elementos pares del vector almacenan las coordenadas x
//los elementos impares del vector almacenan las coordenadas y
    int* torre::posiblesmov(){

                      pos[0]=0;   pos[1]=1;
                      pos[2]=0;   pos[3]=2;
                      pos[4]=0;   pos[5]=3;
                      pos[6]=0;   pos[7]=4;
                      pos[8]=0;   pos[9]=5;
                      pos[10]=0;  pos[11]=6;
                      pos[12]=0;  pos[13]=7;
                      pos[14]=1;  pos[15]=0;
                      pos[16]=2;  pos[17]=0;
                      pos[18]=3;  pos[19]=0;
                      pos[20]=4;  pos[21]=0;
                      pos[22]=5;  pos[23]=0;
                      pos[24]=6;  pos[25]=0;
                      pos[26]=7;  pos[27]=0;
                      pos[28]=0;  pos[29]=-1;
                      pos[30]=0;  pos[31]=-2;
                      pos[32]=0;  pos[33]=-3;
                      pos[34]=0;  pos[35]=-4;
                      pos[36]=0;  pos[37]=-5;
                      pos[38]=0;  pos[39]=-6;
                      pos[40]=0;  pos[41]=-7;
                      pos[42]=-1; pos[43]=0;
                      pos[44]=-2; pos[45]=0;
                      pos[46]=-3; pos[47]=0;
                      pos[48]=-4; pos[49]=0;
                      pos[50]=-5; pos[51]=0;
                      pos[52]=-6; pos[53]=0;
                      pos[54]=-7; pos[55]=0;
    return pos;
    }





