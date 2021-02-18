#include "DoStrada.hpp"
#include "Ostacolo3.hpp"

void Ostacolo3::appear(int z, int lvl){
    if(yPos>=29){
        int randomC= 0;
        if(lvl<6)
            randomC= z%(6-lvl);
        if (randomC == 0) {
            int randomNo = z % 53 + 2;
            xPos = randomNo;
            yPos = 0;
        }
    }
}

Ostacolo3::Ostacolo3(){
    xPos=25;
    yPos=32;
}

void Ostacolo3::print(DoStrada &s){
    if(yPos<29) {
        Disegna(xPos, yPos, s);
        Disegna(xPos, yPos - 1, s);
        Disegna(xPos + 1, yPos - 1, s);
        Disegna(xPos - 1, yPos - 1, s);
        Disegna(xPos, yPos - 2, s);
        Disegna(xPos, yPos - 3, s);
        Disegna(xPos + 1, yPos - 3, s);
        Disegna(xPos - 1, yPos - 3, s);
    }
}

void Ostacolo3::Disegna(int x, int y, DoStrada &s){
    if(y>=0){
        if((s.strada[x][y] != '?') && (s.strada[x][y] != '@'))
            yPos=32;
        else
            s.strada[x][y]=simbolo;
    }
}

void Ostacolo3::RandomMove(int z, DoStrada &s){
    int randomNo=z%10;
        if(randomNo==1 && isPossibleLeft(s)) moveLeft();
        else if(randomNo==2 && isPossibleRight(s)) moveRight();
}

void Ostacolo3::moveLeft(){
    if(xPos>2) xPos--;
}

void Ostacolo3::moveRight(){
    if(xPos<54) xPos++;
}

bool Ostacolo3::isPossibleLeft(DoStrada &s){
    return(((s.strada[xPos-2][yPos-3]=='?')&&(s.strada[xPos-2][yPos-1]=='?'))&&((s.strada[xPos-3][yPos-3]!='M')&&(s.strada[xPos-3][yPos-1]!='M'))&&(s.strada[xPos-1][yPos]== '?'));
}

bool Ostacolo3::isPossibleRight(DoStrada &s){
    return(((s.strada[xPos+2][yPos-3]=='?')&&(s.strada[xPos+2][yPos-1]=='?'))&&((s.strada[xPos+3][yPos-3]!='M')&&(s.strada[xPos+3][yPos-1]!='M'))&&(s.strada[xPos+1][yPos]== '?'));
}

void Ostacolo3::move(){
    yPos++;
}

int Ostacolo3::getValue(){
    return value;
}

bool Ostacolo3::collision(int X, int Y){
    bool collision = false;
    if(((X==xPos) && (Y==yPos))  || (((X==xPos+1) && (Y==yPos-1)) || ((X==xPos-1) && (Y==yPos-1)))
        || (((X+1 >= xPos-1) && (X+1 <= xPos+1)) && (((Y+1 <= yPos-1) && (Y+1 >= yPos-3)) || ((Y+3 <= yPos-1) && (Y+3 >= yPos-3))))
        || (((X-1 >= xPos-1) && (X-1 <= xPos+1)) && (((Y+1 <= yPos-1) && (Y+1 >= yPos-3)) || ((Y+3 <= yPos-1) && (Y+3 >= yPos-3))))){
        collision=true;
        yPos=32;
    }
    return collision;
}

int Ostacolo3::getyPos(){
    return yPos;
}