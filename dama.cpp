#include "dama.hpp"
#include <graphics.h>
//Constructor por defecto
dama::dama():pieza(){}
//Constructor parametrico
dama::dama(unsigned x, unsigned y, unsigned color){
    m_x=x;
    m_y=y;
    m_color=color;
    m_valor=10;
    m_nombre="dama";
    m_jugadas=56;
}
//Dibuja a la dama en el tablero a partir de las coordenadas de la casilla
//en la que se quiere dibujar y el color correspondiente
void dama::dibujar(){
    unsigned x,y;
    x=(m_x*75)+400;
    y=(m_y*75)+50;
    setcolor(m_color);
    setfillstyle(SOLID_FILL,m_color);
    int ax[28]={15,20, 28,35, 30,20, 35,37, 40,20, 45,37, 50,20, 52,35, 65,20, 55,48, 55,65, 25,65, 25,48, 15,20};
    for(int i=0;i<28;i+=2){
        ax[i]+=x;
        ax[i+1]+=y;
    }
    drawpoly(14,ax);
    rectangle(x+25,y+50,x+55,y+60);
    fillellipse(x+15,y+20,4,5);
    fillellipse(x+30,y+20,4,5);
    fillellipse(x+40,y+20,4,5);
    fillellipse(x+50,y+20,4,5);
    fillellipse(x+65,y+20,4,5);
}
//Borra la pieza, redibujandola del color de la casilla en la que se encuentra
    void dama::borrar(){
        unsigned x,y;
    x=(m_x*75)+400;
    y=(m_y*75)+50;
    unsigned color=getpixel(x+1,y+1);
    setcolor(color);
    setfillstyle(SOLID_FILL,color);
    int ax[28]={15,20, 28,35, 30,20, 35,37, 40,20, 45,37, 50,20, 52,35, 65,20, 55,48, 55,65, 25,65, 25,48, 15,20};
    for(int i=0;i<28;i+=2){
        ax[i]+=x;
        ax[i+1]+=y;
    }
    drawpoly(14,ax);
    rectangle(x+25,y+50,x+55,y+60);
    fillellipse(x+15,y+20,4,5);
    fillellipse(x+30,y+20,4,5);
    fillellipse(x+40,y+20,4,5);
    fillellipse(x+50,y+20,4,5);
    fillellipse(x+65,y+20,4,5);
    }
//Esta apuntador de tipo entero almacena los posibles movimientos de la pieza dentro de un vector
//los elementos pares del vector almacenan las coordenadas x
//los elementos impares del vector almacenan las coordenadas y
int* dama::posiblesmov(){
                      pos[0]=0;    pos[1]=1;
                      pos[2]=0;    pos[3]=2;
                      pos[4]=0;    pos[5]=3;
                      pos[6]=0;    pos[7]=4;
                      pos[8]=0;    pos[9]=5;
                      pos[10]=0;   pos[11]=6;
                      pos[12]=0;   pos[13]=7;
                      pos[14]=1;   pos[15]=0;
                      pos[16]=2;   pos[17]=0;
                      pos[18]=3;   pos[19]=0;
                      pos[20]=4;   pos[21]=0;
                      pos[22]=5;   pos[23]=0;
                      pos[24]=6;   pos[25]=0;
                      pos[26]=7;   pos[27]=0;
                      pos[28]=1;   pos[29]=1;
                      pos[30]=2;   pos[31]=2;
                      pos[32]=3;   pos[33]=3;
                      pos[34]=4;   pos[35]=4;
                      pos[36]=5;   pos[37]=5;
                      pos[38]=6;   pos[39]=6;
                      pos[40]=7;   pos[41]=7;
                      pos[42]=-1;  pos[43]=-1;
                      pos[44]=-2;  pos[45]=-2;
                      pos[46]=-3;  pos[47]=-3;
                      pos[48]=-4;  pos[49]=-4;
                      pos[50]=-5;  pos[51]=-5;
                      pos[52]=-6;  pos[53]=-6;
                      pos[54]=-7;  pos[55]=-7;
                      pos[56]=-1;  pos[57]=1;
                      pos[58]=-2;  pos[59]=2;
                      pos[60]=-3;  pos[61]=3;
                      pos[62]=-4;  pos[63]=4;
                      pos[64]=-5;  pos[65]=5;
                      pos[66]=-6;  pos[67]=6;
                      pos[68]=-7;  pos[69]=7;
                      pos[70]=1;   pos[71]=-1;
                      pos[72]=2;   pos[73]=-2;
                      pos[74]=3;   pos[75]=-3;
                      pos[76]=4;   pos[77]=-4;
                      pos[78]=5;   pos[79]=-5;
                      pos[80]=6;   pos[81]=-6;
                      pos[82]=7;   pos[83]=-7;
                      pos[84]=0;   pos[85]=-1;
                      pos[86]=0;   pos[87]=-2;
                      pos[88]=0;   pos[89]=-3;
                      pos[90]=0;   pos[91]=-4;
                      pos[92]=0;   pos[93]=-5;
                      pos[94]=0;   pos[95]=-6;
                      pos[96]=0;   pos[97]=-7;
                      pos[98]=-1;  pos[99]=0;
                      pos[100]=-2; pos[101]=0;
                      pos[102]=-3; pos[103]=0;
                      pos[104]=-4; pos[105]=0;
                      pos[106]=-5; pos[107]=0;
                      pos[108]=-6; pos[109]=0;
                      pos[110]=-7; pos[111]=0;
    return pos;
    }

