#include "DoStrada.hpp"
#include "Gas.hpp"
#include "stdlib.h"
#include "time.h"
using namespace std;

void Gas::appear(int z){
    if(yPos>=29){
        int randomNo = z % 54 + 1;
        xPos = randomNo;
        yPos = 0;
    }
}

Gas::Gas(){
    value= 60;
    xPos=25;
    yPos=30;
}

void Gas::print(DoStrada &s){
    if(yPos<29) {
        Disegna(xPos, yPos, s);
        Disegna(xPos + 1, yPos, s);
        Disegna(xPos + 1, yPos - 1, s);
        Disegna(xPos, yPos - 1, s);
    }
}

void Gas::Disegna(int x, int y, DoStrada &s){
    if(y>=0){
        if((s.strada[x][y]!='?')  && (s.strada[x][y]!='@')) {
            yPos = 30;
        }
        else s.strada[x][y]=simbolo;
    }
}


void Gas::move(){
    yPos++;
}

int Gas::getX(){
    return xPos;
}

int Gas::getY(){
    return yPos;
}

bool Gas::collision(int X, int Y)
{
    bool collisione= false;
    if   ((((X >= xPos) && (X <= xPos+1)) && ((Y <= yPos) && (Y >= yPos-1)))
          || (((X+1 >= xPos) && (X+1 <= xPos+1)) && (((Y+1 <= yPos) && (Y+1 >= yPos-1)) || ((Y+3 <= yPos) && (Y+3 >= yPos-1))))
          || (((X-1 >= xPos) && (X-1 <= xPos+1)) && (((Y+1 <= yPos) && (Y+1 >= yPos-1)) || ((Y+3 <= yPos) && (Y+3 >= yPos-1))))){
        yPos = 30;
        collisione = true;
    }
    return collisione;
}

int Gas::getValue(){
    return value;
}
