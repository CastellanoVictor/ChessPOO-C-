 #include "tablero.hpp"
 #include "graphics.h"
 #include <iostream>
 #include <string>
//Constructor por defecto
 tablero::tablero(){
//inicializa las piezas en sus lugares correspondientes
     m_rbl=rey(4,7,9);
     m_rgr=rey(4,0,2);

     m_dbl=dama(3,7,9);
     m_dgr=dama(3,0,2);

     m_cbl[0]=caballo(1,7,9);
     m_cbl[1]=caballo(6,7,9);
     m_cgr[0]=caballo(1,0,2);
     m_cgr[1]=caballo(6,0,2);

     m_tbl[0]=torre(0,7,9);
     m_tbl[1]=torre(7,7,9);
     m_tgr[0]=torre(0,0,2);
     m_tgr[1]=torre(7,0,2);

     m_abl[0]=alfil(2,7,9);
     m_abl[1]=alfil(5,7,9);
     m_agr[0]=alfil(2,0,2);
     m_agr[1]=alfil(5,0,2);

     m_pgr [0]= peon(0,1,2);
     m_pgr [1]= peon(1,1,2);
     m_pgr [2]= peon(2,1,2);
     m_pgr [3]= peon(3,1,2);
     m_pgr [4]= peon(4,1,2);
     m_pgr [5]= peon(5,1,2);
     m_pgr [6]= peon(6,1,2);
     m_pgr [7]= peon(7,1,2);

    for (unsigned i=0;i<8;i+=1)
    {
        for (unsigned j=0;j<8;j+=1)
        {
           m_c[i*8+j]=casilla(j,i,((i+j)&1) ? 0 : 15);
        }
    }
    for (int i=0;i<8;i+=1){
         m_pbl [i]= peon (i,6,9);
         m_c[i+48].insertar(&m_pbl[i]);
    }
//Inserta las direcciones de memoria de las piezas creadas en las casillas
    m_c[0].insertar(&m_tgr[0]);
    m_c[1].insertar(&m_cgr[0]);
    m_c[2].insertar(&m_agr[0]);
    m_c[3].insertar(&m_dgr);
    m_c[4].insertar(&m_rgr);
    m_c[5].insertar(&m_agr[1]);
    m_c[6].insertar(&m_cgr[1]);
    m_c[7].insertar(&m_tgr[1]);
    m_c[8].insertar(&m_pgr[0]);
    m_c[9].insertar(&m_pgr[1]);
    m_c[10].insertar(&m_pgr[2]);
    m_c[11].insertar(&m_pgr[3]);
    m_c[12].insertar(&m_pgr[4]);
    m_c[13].insertar(&m_pgr[5]);
    m_c[14].insertar(&m_pgr[6]);
    m_c[15].insertar(&m_pgr[7]);

    m_c[56].insertar(&m_tbl[0]);
    m_c[57].insertar(&m_cbl[0]);
    m_c[58].insertar(&m_abl[0]);
    m_c[59].insertar(&m_dbl);
    m_c[60].insertar(&m_rbl);
    m_c[61].insertar(&m_abl[1]);
    m_c[62].insertar(&m_cbl[1]);
    m_c[63].insertar(&m_tbl[1]);
 }
//Dibuja el tablero
 void tablero::mostrar(){
    for (unsigned i=0;i<8;i+=1)
    {
        for (unsigned j=0;j<8;j+=1)
        {
           m_c[i*8+j].mostrar();
        }
    }
 }
//Convierte una coordenada logica en un indice para el vector de casillas
 unsigned tablero::indice(unsigned x, unsigned y){
    return y*8+x;
 }
//regresa la casilla del indice seleccionado
 casilla tablero::getcasilla(unsigned index) const{
    return m_c[index];
 }
//Convierte una coordenada grafica en un indice para el vector de casillas
 unsigned tablero::getindexgraf(unsigned x, unsigned y){
     x=(x-400)/75;
     y=(y-50)/75;
     return y*8+x;
 }
//Esta función ayudará a comprobar los posibles movimientos de la pieza seleccionada dentro de una casilla.
//Para poder plantear los posibles movimientos de las piezas es necesario verificar que los movimientos se
// encuentran dentro del tablero. Además, una vez verificado lo anterior es necesario plantear las posibles
//opciones graficas del movimiento, para esto es necesario verificar si la casilla se encuentra vacía con lo
//que se pintará de color azul y si se no es el caso debe comprobarse que la pieza que ocupa esa casilla es de
// diferente color a la pieza que quiere moverse, si son diferentes la casilla se pintará de color rojo, marcando
// así la opción de comer.
 void tablero::checarmov(int* pos, unsigned index){
    unsigned tam=m_c[index].getpieza()->getjugadas();
    int x[tam],y[tam];
    for(unsigned i=0;i<tam;i+=1){
        x[i]=(pos[i*2]);
        y[i]=(pos[i*2+1]);
    }
    int bandera=0;
    for(unsigned i=0;i<tam;i+=1){
    //Esta bandera sirve para que una vez que se encuentre la pieza que se va a mover con otra deje de seguir comprobando
    // los posibles movimientos en la direccion del movimienot actual
        if((i)%7==0) bandera=0;
        if(bandera==0){
        if(m_c[index].m_x1+x[i]>=0 && m_c[index].m_x1+x[i]<8)
        {
             if(m_c[index].m_y1+y[i]>=0 && m_c[index].m_y1+y[i]<8)
             {
        //verifica que la casilla se encuentre vacia dado el movimiento de avance
                 if (m_c[indice(m_c[index].m_x1+x[i],m_c[index].m_y1+y[i])].getpieza()==nullptr){
                    ///pintarazul;
                    if(m_c[indice(m_c[index].m_x1+x[i],m_c[index].m_y1+y[i])].m_color==0)
                    m_c[indice(m_c[index].m_x1+x[i],m_c[index].m_y1+y[i])].mostrar(3);
                    else
                    m_c[indice(m_c[index].m_x1+x[i],m_c[index].m_y1+y[i])].mostrar(11);
                 }
                 else{
                         bandera=1;
                    if(m_c[indice(m_c[index].m_x1+x[i],m_c[index].m_y1+y[i])].getpieza()->getcolor()!=m_c[index].getpieza()->getcolor()){
                        ///pintarrojo;

                        if(m_c[indice(m_c[index].m_x1+x[i],m_c[index].m_y1+y[i])].m_color==0){
                   m_c[indice(m_c[index].m_x1+x[i],m_c[index].m_y1+y[i])].mostrar(4);  }
                        else{
                      m_c[indice(m_c[index].m_x1+x[i],m_c[index].m_y1+y[i])].mostrar(12);
                    }
                 }
             }
        }
     }
   }
 }
 }
//verifica los posibles movimientos del peon
 void tablero::checarpeon(unsigned index){
    int signo=(m_c[index].getpieza()->getcolor()&1)? -1:1;
   //se verifica que el movimiento a la casilla tenga una pieza, y que sea de diferente color a la pieza movida
    if(m_c[indice(m_c[index].m_x1+1,m_c[index].m_y1+signo)].getpieza()!=nullptr){
    if(m_c[indice(m_c[index].m_x1+1,m_c[index].m_y1+signo)].getpieza()->getcolor()!=m_c[index].getpieza()->getcolor()){
        ///pintarrojo
        if(m_c[indice(m_c[index].m_x1+1,m_c[index].m_y1+signo)].m_color==0)
              m_c[indice(m_c[index].m_x1+1,m_c[index].m_y1+signo)].mostrar(4);
              else
                m_c[indice(m_c[index].m_x1+1,m_c[index].m_y1+signo)].mostrar(12);
    }
    }
    if(m_c[indice(m_c[index].m_x1-1,m_c[index].m_y1+signo)].getpieza()!=nullptr){
    if(m_c[indice(m_c[index].m_x1-1,m_c[index].m_y1+signo)].getpieza()->getcolor()!=m_c[index].getpieza()->getcolor()){
        ///pintarrrojo
            if(m_c[indice(m_c[index].m_x1-1,m_c[index].m_y1+signo)].m_color==0)
                m_c[indice(m_c[index].m_x1-1,m_c[index].m_y1+signo)].mostrar(4);
                    else
                      m_c[indice(m_c[index].m_x1-1,m_c[index].m_y1+signo)].mostrar(12);
          }}
    //verifica que la casilla se encuentre vacia dado el movimiento de avance
    if(m_c[indice(m_c[index].m_x1,m_c[index].m_y1+signo)].getpieza()==nullptr){
            ///pintar azul
        if(m_c[indice(m_c[index].m_x1+1,m_c[index].m_y1+signo)].m_color==0)
              m_c[indice(m_c[index].m_x1,m_c[index].m_y1+signo)].mostrar(3);
              else
                m_c[indice(m_c[index].m_x1,m_c[index].m_y1+signo)].mostrar(11);
    }
        //esto solo lo hace en el primer movimiento dadas las caracteristicas de movimiento del peon
     if((m_c[indice(m_c[index].m_x1,m_c[index].m_y1+signo+signo)].getpieza()==nullptr)&&(m_c[index].getpieza()->getcontador()==0)&&(m_c[indice(m_c[index].m_x1,m_c[index].m_y1+signo)].getpieza()==nullptr))
        {

        if(m_c[indice(m_c[index].m_x1+1,m_c[index].m_y1+signo+signo)].m_color==0)
              m_c[indice(m_c[index].m_x1,m_c[index].m_y1+signo+signo)].mostrar(3);
              else
                m_c[indice(m_c[index].m_x1,m_c[index].m_y1+signo+signo)].mostrar(11);
    }


}
//verifica los posibles movimientos del rey y caballo
 void tablero::checarreycab(int* pos, unsigned index){
    unsigned tam=m_c[index].getpieza()->getjugadas();
    int x[tam],y[tam];
    for(unsigned i=0;i<tam;i+=1){
        x[i]=(pos[i*2]);
        y[i]=(pos[i*2+1]);
    }

    for(unsigned i=0;i<tam;i+=1){
//Verifica que los movimientos se encuentren dentro del tablero
        if(m_c[index].m_x1+x[i]>=0 && m_c[index].m_x1+x[i]<8)
        {
             if(m_c[index].m_y1+y[i]>=0 && m_c[index].m_y1+y[i]<8)
             {
//Verifica si la casilla se encuentra vacia, pintando las casillas de color azul
                 if (m_c[indice(m_c[index].m_x1+x[i],m_c[index].m_y1+y[i])].getpieza()==nullptr){
                    ///pintarazul;
                    if(m_c[indice(m_c[index].m_x1+x[i],m_c[index].m_y1+y[i])].m_color==0)
                    m_c[indice(m_c[index].m_x1+x[i],m_c[index].m_y1+y[i])].mostrar(3);
                    else
                     m_c[indice(m_c[index].m_x1+x[i],m_c[index].m_y1+y[i])].mostrar(11);
                 }
                 else{
//Verificar que la pieza que ocupa la casilla es de diferente color a la pieza que quiere moverse
                    if(m_c[indice(m_c[index].m_x1+x[i],m_c[index].m_y1+y[i])].getpieza()->getcolor()!=m_c[index].getpieza()->getcolor()){
                        ///pintarrojo;
                        if(m_c[indice(m_c[index].m_x1+x[i],m_c[index].m_y1+y[i])].m_color==0){
                   m_c[indice(m_c[index].m_x1+x[i],m_c[index].m_y1+y[i])].mostrar(4);  }
                        else{
                    m_c[indice(m_c[index].m_x1+x[i],m_c[index].m_y1+y[i])].mostrar(12);
                    }
                 }

             }
        }
     }

 }
 }

 void tablero::moverpieza(unsigned x,unsigned y){
//Se verifica el valor de la casilla corresponda a un peon para implementar los posibles movimientos de la pieza
     if (m_c[getindexgraf(x,y)].getpieza()->getvalor()==1){
        checarpeon(getindexgraf(x,y));}
     else {
//Se verifica que la pieza en la casilla corresponda a un caballo o un rey para implementar sus posibles movimientos
            if((m_c[getindexgraf(x,y)].getpieza()->getnombre()=="caballo")||
                (m_c[getindexgraf(x,y)].getpieza()->getnombre()=="rey")){
                checarreycab(m_c[getindexgraf(x,y)].m_p->posiblesmov(),getindexgraf(x,y));
                }else
//Si la pieza corresponde a reina, torre o alfil se implementan los posibles movimientos
    checarmov(m_c[getindexgraf(x,y)].m_p->posiblesmov(),getindexgraf(x,y));
 }
    int _x,_y;
//Sirve para obtener la coordenada del pixel donde se hizo clic con el cursor
    while (!ismouseclick(WM_LBUTTONDOWN)) {}
      getmouseclick(WM_LBUTTONDOWN,_x,_y);
    clearmouseclick(WM_LBUTTONDOWN);
do{
//Asegura que el lugar donde se dio clic sea valido
            while (!ismouseclick(WM_LBUTTONDOWN)) {}
      getmouseclick(WM_LBUTTONDOWN,_x,_y);
    clearmouseclick(WM_LBUTTONDOWN);
    std::cout<<"while"<<std::endl;
        }
    while((getpixel(_x,_y)==0)||(getpixel(_x,_y)==15)||(getpixel(_x,_y)==9)||(getpixel(_x,_y)==2));
 mover(x,y,_x,_y);

 }
//esta funcion mueve las piezas, para esto entran las coordenadas actuales y las nuevas
 void tablero::mover(unsigned xold, unsigned yold, unsigned xnew, unsigned ynew){
     // Verifica si el color del pixel seleccionado corresponde a una casilla marcada donde un movimiento es posible
    if((getpixel(xnew,ynew)!=0)&&(getpixel(xnew,ynew)!=15)&&(getpixel(xnew,ynew)!=9)&&(getpixel(xnew,ynew)!=2)){
        //deja la pieza de la nueva casilla seleccionada como nula
       m_c[getindexgraf(xnew,ynew)].m_p=nullptr;
       //borra la pieza de la casilla anterior
       m_c[getindexgraf(xold,yold)].m_p->borrar();
       //Le asigna la nueva posición a la pieza que se moverá
       m_c[getindexgraf(xold,yold)].m_p->repos((xnew-400)/75,(ynew-50)/75);
       //Mueve la direccion de memoria de la pieza de la casilla inicial a la nueva casilla
       m_c[getindexgraf(xnew,ynew)].m_p=m_c[getindexgraf(xold,yold)].m_p;
       //Deja la pieza de la casilla inicial como nula
       m_c[getindexgraf(xold,yold)].m_p=nullptr;
       mostrar();
       //Aumenta en uno el contador de la pieza
       m_c[getindexgraf(xnew,ynew)].m_p->modcont();
    }
 }

 casilla tablero::getcasilla(unsigned index){
    return m_c[index];
 }
//Comprueba la jugada jaque (posición de advertencia de rey)
 void tablero::checar(unsigned index){
//Verifica si el valor de la pieza corresponde a un peon
if(m_c[index].getpieza()==nullptr)return;
     if (m_c[index].getpieza()->getvalor()==1){
//Comprueba los posibles movimientos en modo logico
        checarpeonl(index);
//Posibles opciones de jaque dado el jugador
            if(matriz[m_rbl.atx()][m_rbl.aty()]==1)
            MessageBoxA(NULL,"Jaque rey azul",MB_OK,MB_ICONEXCLAMATION);
            if(matriz[m_rgr.atx()][m_rgr.aty()]==1)
            MessageBoxA(NULL,"Jaque rey verde",MB_OK,MB_ICONEXCLAMATION);
        }

     else {
//Verifica que la pieza corresponda a un caballo o un rey
            if((m_c[index].getpieza()->getnombre()=="caballo")||
                (m_c[index].getpieza()->getnombre()=="rey")){
//Comprueba los posibles movimientos en modo logico
                checarreycabl(m_c[index].m_p->posiblesmov(),index);
                if(matriz[m_rbl.atx()][m_rbl.aty()]==1)
//Posibles opciones de jaque dado el jugador
            MessageBoxA(NULL,"Jaque rey azul",MB_OK,MB_ICONEXCLAMATION);
            if(matriz[m_rgr.atx()][m_rgr.aty()]==1)
            MessageBoxA(NULL,"Jaque rey verde",MB_OK,MB_ICONEXCLAMATION);
                }else{
//Dado que las piezas corresponden a una torre, reina o alfil revisa los movimientos en modo logico
    checarmovl(m_c[index].m_p->posiblesmov(),index);
    if(matriz[m_rbl.atx()][m_rbl.aty()]==1)
            MessageBoxA(NULL,"Jaque rey azul",MB_OK,MB_ICONEXCLAMATION);
            if(matriz[m_rgr.atx()][m_rgr.aty()]==1)
            MessageBoxA(NULL,"Jaque rey verde",MB_OK,MB_ICONEXCLAMATION);}
 }

 }
//Regresa ka pieza rey (color verde)
 rey tablero::getrgr(){
 return m_rgr;
 }
//Regresa ka pieza rey (color azul)
 rey tablero::getrbl(){
 return m_rbl;
 }
//esta funcion comprobara los posibles movimientos del rey y del caballo de modo lógico
  void tablero::checarreycabl(int* pos, unsigned index){
    unsigned tam=m_c[index].getpieza()->getjugadas();
    int x[tam],y[tam];
    for(unsigned i=0;i<tam;i+=1){
        x[i]=(pos[i*2]);
        y[i]=(pos[i*2+1]);
    }
    //se utilizan variables(marcadores)para comparar modo grafico con el logico
    int rojo=1,azul=2;
    // se crea una matriz dle tamaño del tablero
    for(unsigned i=0;i<8;i+=1){
        for(unsigned j=0;j<8;j+=1){

            matriz[j][i]=0;
        }
    }
    //se verifica que los posibles movimientos esten dentro del tablero
    for(unsigned i=0;i<tam;i+=1){
        if(m_c[index].m_x1+x[i]>=0 && m_c[index].m_x1+x[i]<8)
        {
             if(m_c[index].m_y1+y[i]>=0 && m_c[index].m_y1+y[i]<8)
             {
                //se marcan los valores de los movimientos en la matriz creada
                 if (m_c[indice(m_c[index].m_x1+x[i],m_c[index].m_y1+y[i])].getpieza()==nullptr){
                    ///pintarazul;
                    matriz[m_c[index].m_x1+x[i]][m_c[index].m_y1+y[i]]=azul;

                 }
                 else{
                    if(m_c[indice(m_c[index].m_x1+x[i],m_c[index].m_y1+y[i])].getpieza()->getcolor()!=m_c[index].getpieza()->getcolor()){
                        ///pintarrojo;
                         matriz[m_c[index].m_x1+x[i]][m_c[index].m_y1+y[i]]=rojo;

                 }

             }
        }
     }

 }
 }
//esta funcion comprobara los posibles movimientos del peon de modo lógico
 void tablero::checarpeonl(unsigned index){
    int signo=(m_c[index].getpieza()->getcolor()&1)? -1:1;
    //se utilizan variables(marcadores)para comparar modo grafico con el logico
     int rojo=1,azul=2;
    // se crea una matriz dle tamaño del tablero
    for(unsigned i=0;i<8;i+=1){
        for(unsigned j=0;j<8;j+=1){
             matriz[j][i]=0;
        }
    }
    //Se marcan los valores de los movimientos(rojos) en la matriz creada
    if(m_c[indice(m_c[index].m_x1+1,m_c[index].m_y1+signo)].getpieza()!=nullptr){
    if(m_c[indice(m_c[index].m_x1+1,m_c[index].m_y1+signo)].getpieza()->getcolor()!=m_c[index].getpieza()->getcolor()){
      ///pintarrojo
      matriz[m_c[index].m_x1+1][m_c[index].m_y1+signo]=rojo;
    }
    }
    if(m_c[indice(m_c[index].m_x1-1,m_c[index].m_y1+signo)].getpieza()!=nullptr){
    if(m_c[indice(m_c[index].m_x1-1,m_c[index].m_y1+signo)].getpieza()->getcolor()!=m_c[index].getpieza()->getcolor()){
            ///pintarrrojo
            matriz[m_c[index].m_x1-1][m_c[index].m_y1+signo]=rojo;
          }}
    //Se marcan los valores de los movimientos(azules) en la matriz creada
    if(m_c[indice(m_c[index].m_x1,m_c[index].m_y1+signo)].getpieza()==nullptr){ ///pintar azul
        matriz[m_c[index].m_x1][m_c[index].m_y1+signo]=azul;
    }
    //esto solo lo hace en el primer movimiento dadas las caracteristicas de movimiento del peon
     if((m_c[indice(m_c[index].m_x1,m_c[index].m_y1+signo+signo)].getpieza()==nullptr)&&(m_c[index].getpieza()->getcontador()==0)&&(m_c[indice(m_c[index].m_x1,m_c[index].m_y1+signo)].getpieza()==nullptr))
        {
           matriz[m_c[index].m_x1][m_c[index].m_y1+signo+signo]=azul;
    }
}

//esta funcion comprobara los posibles movimientos de la torre, alfil  y reina de modo lógico
void tablero::checarmovl(int* pos, unsigned index){
    unsigned tam=m_c[index].getpieza()->getjugadas();
    int x[tam],y[tam];
    for(unsigned i=0;i<tam;i+=1){
        x[i]=(pos[i*2]);
        y[i]=(pos[i*2+1]);
    }
    //se utilizan variables(marcadores)para comparar modo grafico con el logico
    int rojo=1,azul=2;
    // se crea una matriz dle tamaño del tablero
    for(unsigned i=0;i<8;i+=1){
        for(unsigned j=0;j<8;j+=1){
            matriz[j][i]=0;
        }
    }

    int bandera=0;
    for(unsigned i=0;i<tam;i+=1){
        if((i)%7==0) bandera=0;
        if(bandera==0){
        if(m_c[index].m_x1+x[i]>=0 && m_c[index].m_x1+x[i]<8)
        {
             if(m_c[index].m_y1+y[i]>=0 && m_c[index].m_y1+y[i]<8)
             {
                 if (m_c[indice(m_c[index].m_x1+x[i],m_c[index].m_y1+y[i])].getpieza()==nullptr){
                    ///pintarazul;
                    matriz[m_c[index].m_x1+x[i]][m_c[index].m_y1+y[i]]=azul;

                 }
                 else{
                         bandera=1;
                    if(m_c[indice(m_c[index].m_x1+x[i],m_c[index].m_y1+y[i])].getpieza()->getcolor()!=m_c[index].getpieza()->getcolor()){
                        ///pintarrojo;
                        matriz[m_c[index].m_x1+x[i]][m_c[index].m_y1+y[i]]=rojo;
                 }

          }
       }
     }
   }
 }
 }
