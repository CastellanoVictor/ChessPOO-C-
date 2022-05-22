#include "casilla.hpp"
#include "graphics.h"
//Constructor por defecto (sin argumentos)
//Lista de inicializacion para las variables miembro(atributos)
casilla::casilla(): m_x1(0),m_y1(0),m_color(0),m_p(nullptr){}
//Constructor parametrico
//Llama al constructor por defecto a traves de la lista de inicializacion
casilla::casilla (unsigned x1,unsigned y1,int color):casilla(){
    m_x1=x1;
    m_y1=y1;
    m_color=color;
}
//Dibuja la casilla de primer momento (blanco o negro), para hacer la parte gráfica
//ocupa las coordenadas del punto superior izquierdo e inferior derecho
void casilla::mostrar(){
    unsigned x1,x2,y1,y2;
    x1=(m_x1*75)+400;
    x2=(m_x1*75)+475;
    y1=(m_y1*75)+50;
    y2=(m_y1*75)+125;
    setcolor(m_color);
    rectangle(x1,y1,x2,y2);
    setfillstyle(SOLID_FILL,m_color);
    floodfill(x1+1,y1+1,m_color);
    //si dentro de una casilla se encuentra una pieza, esta se dibuja despues de la casilla
    if (m_p!=nullptr)
        m_p->dibujar();
}
//dibuja la casilla de color rojo si es una casilla con una pieza que se pueda comer
//o de color azul si es una casilla en la que se puede over la pieza, para hacer la parte grafica
//ocupa las coordenadas del punto superior izquierdo e inferior derecho
void casilla::mostrar(unsigned color){
    unsigned x1,x2,y1,y2;
    x1=(m_x1*75)+400;
    x2=(m_x1*75)+475;
    y1=(m_y1*75)+50;
    y2=(m_y1*75)+125;
    setcolor(color);
    rectangle(x1,y1,x2,y2);
    setfillstyle(SOLID_FILL,color);
    floodfill(x1+1,y1+1,color);
     //si dentro de una casilla se encuentra una pieza, esta se dibuja despues de la casilla
    if (m_p!=nullptr)
        m_p->dibujar();
}
//implementa la sobrecarga del operado "="
    casilla& casilla::operator=(casilla other){
    m_x1=other.m_x1;
    m_y1=other.m_y1;
    m_color=other.m_color;
    return *(this);
}
//inserta una pieza en una casilla desde la direccion de la pieza a insertar
void casilla::insertar(pieza* p){
m_p=p;
}
//regresa la direccion de memoria de la pieza
pieza* casilla::getpieza(){
        return m_p;
}
