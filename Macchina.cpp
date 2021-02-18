#include "DoStrada.hpp"
#include "Pausa.hpp"
#include "Funzioni.h"
#include "conio.h"
#include "Macchina.hpp"
using namespace std;

Macchina::Macchina() {
    xPos = 27;
    yPos = 25;
    simbolo= '@';
    end = false;
    FuoriStrada = false;
}

Pausa p= Pausa();

void Macchina::disegna(DoStrada &s) {
    DisegnaPunto(xPos, yPos, s);
    DisegnaPunto(xPos - 1, yPos + 1, s);
    DisegnaPunto(xPos + 1, yPos + 1, s);
    DisegnaPunto(xPos, yPos + 1, s);
    DisegnaPunto(xPos, yPos + 2, s);
    DisegnaPunto(xPos - 1, yPos + 3, s);
    DisegnaPunto(xPos + 1, yPos + 3, s);
    DisegnaPunto(xPos, yPos + 3, s);
}

void Macchina::MuoviSX() {
    if (xPos>5) xPos = xPos-4;
}

void Macchina::MuoviDX() {
    if (xPos<54) xPos = xPos+4;
}
void Macchina::MuoviUP() {
    if (yPos>1) yPos = yPos-4;
}
void Macchina::MuoviDW() {
    if (yPos<25) yPos = yPos+4;
}

void Macchina::DisegnaPunto(int x, int y, DoStrada &s){
    if(y<60 & y>=0){
        s.strada[x][y]=simbolo;
    }
}

void Macchina::Controlli() {
    FuoriStrada = false;
    char input = ' ';
    if (_kbhit()) {
        input = _getch();
        if (input == 'w') {
            MuoviUP();
        } else if (input == 'a') {
            if(xPos == 3){
                FuoriStrada = true;
            }
            else MuoviSX();
        } else if (input == 's') {
            MuoviDW();
        } else if (input == 'd') {
            if(xPos == 55){
                FuoriStrada = true;
            }
            else MuoviDX();
        } else if (input == 'p') {
            if(p.MenuPausa() == 2) {
                end = true;
            }
        }
        input = ' ';
    }
}

int Macchina::getX(){
    return xPos;
}

int Macchina::getY(){
    return yPos;
}

void Macchina::Flashing(int t){
    if(t%2 == 1)
        simbolo= ' ';
    else
        simbolo= '@';
}

bool Macchina::getEnd(){
    return end;
}

bool Macchina::getFuoriStrada(){
    return FuoriStrada;
}
