#include "DoStrada.hpp"
#include "Ostacolo2.hpp"

using namespace std;

void Ostacolo2::appear(int z, int lvl){
    if(yPos>=29){
        int randomC= 0;
        if(lvl<6)
            randomC= z%(6-lvl);
        if (randomC == 0) {
            int randomNo = z % 52 + 1;
            xPos = randomNo;
            yPos = 0;
        }
    }
}

Ostacolo2::Ostacolo2(){
    xPos=25;
    yPos=30;
}

void Ostacolo2::print(DoStrada &s){
    if(yPos<29) {
        Disegna(xPos, yPos, s);
        Disegna(xPos, yPos - 1, s);
        Disegna(xPos + 1, yPos, s);
        Disegna(xPos + 1, yPos - 1, s);
        Disegna(xPos + 2, yPos, s);
        Disegna(xPos + 2, yPos - 1, s);
        Disegna(xPos + 3, yPos, s);
        Disegna(xPos + 3, yPos - 1, s);
    }
}

void Ostacolo2::Disegna(int x, int y, DoStrada &s){
    if(y>=0){
        if((s.strada[x][y]!='?')  && (s.strada[x][y]!='@')) {
            yPos = 30;
        }
        else s.strada[x][y]=simbolo;
    }
}

bool Ostacolo2::collision(int X, int Y){
    bool collisione = false;
    if((((X>=xPos) && (X<=xPos+3)) && ((Y<=yPos) && (Y>=yPos-1)))
        || (((X+1 >= xPos) && (X+1 <= xPos+3)) && (((Y+1 <= yPos) && (Y+1 >= yPos-1)) || ((Y+3 <= yPos) && (Y+3 >= yPos-1))))
        || (((X-1 >= xPos) && (X-1 <= xPos+3)) && (((Y+1 <= yPos) && (Y+1 >= yPos-1)) || ((Y+3 <= yPos) && (Y+3 >= yPos-1))))){
        yPos=30;
        collisione=true;
    }
    return collisione;
}

void Ostacolo2::move(){
    yPos++;
}

int Ostacolo2::getValue(){
    return value;
}

int Ostacolo2::getyPos(){
    return yPos;
}