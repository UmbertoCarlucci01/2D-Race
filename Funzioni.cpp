#include "Menu.hpp"
#include "DoStrada.hpp"
#include "Fuel.hpp"
#include "Score.hpp"
#include "Macchina.hpp"
#include "Ostacolo1.hpp"
#include "Gas.hpp"
#include "Ostacolo2.hpp"
#include "Ostacolo3.hpp"
#include "cstdlib"
#include "conio.h"
#include "Liste.h"
#include "time.h"
#include <windows.h>
#include <iostream>
using namespace std;

void ShowConsoleCursor(bool Show)
{
    int Size=25;
    _CONSOLE_CURSOR_INFO CurInfo;
    if (Size<=0)
        Size=1;
    if (Size>100)
        Size=100;
    CurInfo.dwSize = Size;
    CurInfo.bVisible = Show;
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE),&CurInfo);
}

void gotoXY(int x, int y)
{
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void Clear(DoStrada &s){
    for(int j=0;j<57;j++){
        for(int i=1;i<57;i++){
            s.strada[i][j]='?';
        }
    }
    for(int i=65;i<=74;i++){
            s.strada[i][9]='?';
            s.strada[i][14]='?';
    }
}

int objSelector(int oCounter, int CurrLvl, const int MAX_OSTACOLI, const int MIN_SPAWNRATE, listaOs1* &headOs1, listaOs2* &headOs2, listaOs3* &headOs3) {
    if ((oCounter <= MAX_OSTACOLI) && (CurrLvl > 10)) {
        int who = 0;
        if ((MIN_SPAWNRATE - CurrLvl) < 7) {
            who = rand() % 7;
        } else {
            who = rand() % (MIN_SPAWNRATE - CurrLvl);
        }
        if (who == 2 || who == 5)
            headOs1 = addOs1(headOs1, 1, rand() % 3 + CurrLvl);
        if (who == 1 || who == 4)
            headOs2 = addOs2(headOs2, 1, rand() % 3 + CurrLvl);
        if (who == 0 || who == 3)
            headOs3 = addOs3(headOs3, 1, rand() % 3 + CurrLvl);
        if (who < 6)
            oCounter++;
    }
    headOs1= delOs1(headOs1, oCounter);
    headOs2= delOs2(headOs2, oCounter);
    headOs3= delOs3(headOs3, oCounter);
    return oCounter;
}

void fuoriStrada(bool b, int D, int CurrLvl, int &Flashes, Score &t, Fuel &f){
    if (b == true){
        Flashes = 4;
        t.decreaseScore((D * 20) + (CurrLvl * 8));
        f.Decr(D*7);
    }
}

int StartGame(int D){
    HANDLE hconsole;
    hconsole= GetStdHandle(STD_OUTPUT_HANDLE);
    const int CAP_OST= 9+D;       //Numero di ostacoli totali consentito
    const int MIN_SPAWNRATE= 300; //Possibilità di spawn di un oggetto == 1/(MIN_SPAWNRATE-LivelloAttuale)
    const int FUEL_DECR= D;     //Diminuzione-per-ciclo del fuel
    Fuel f= Fuel();
    DoStrada s= DoStrada();
    Macchina macchinam=Macchina();
    listaOs1 *headOs1= NULL;
    headOs1= addOs1(headOs1, 1, 1);
    listaOs2 *headOs2= NULL;
    headOs2= addOs2(headOs2, 1, 6);
    listaOs3 *headOs3= NULL;
    headOs3= addOs3(headOs3, 1, 10);
    listaGas *headGas= NULL;
    headGas= addGas(headGas, 1, 1);
    headGas= addGas(headGas, 1, 11);
    Score t= Score();
    srand(time (NULL));
    int oCounter= 5; //Numero di ostacoli a schermo
    bool end = false;
    int Flashes= 0;
    int Mx= 0;
    int My= 0;
    int CurrLvl= 1;
    int MAX_OSTACOLI= 5+D;   //Numero di ostacoli consentito (cambia in base al livello fino a CAP_OST)
    if(D==1) t.setAumento(10);
    else if(D==2) t.setAumento(15);
    else if(D==3) t.setAumento(20);
    while((f.getfuel() > 0) && (t.getScore() > 0 ) && (end == false)){
        if(MAX_OSTACOLI < CAP_OST) MAX_OSTACOLI= MAX_OSTACOLI + (CurrLvl/10);
        macchinam.Controlli();
        end = macchinam.getEnd();
        macchinam.disegna(s);
        f.drawast(s);
        Mx= macchinam.getX();
        My= macchinam.getY();
        CurrLvl=t.getLvl();
        ManOs1(headOs1, D, CurrLvl, s, Mx, My, Flashes, t, f);
        ManOs2(headOs2, D, CurrLvl, s, Mx, My, Flashes, t, f);
        ManGas(headGas, D, CurrLvl, s, Mx, My, t, f);
        ManOs3(headOs3, D, CurrLvl, s, Mx, My, Flashes, t, f);
        fuoriStrada(macchinam.getFuoriStrada(), D, CurrLvl, Flashes, t, f);
        if(Flashes > 0) Flashes--;
        macchinam.Flashing(Flashes);
        oCounter= objSelector(oCounter, CurrLvl, MAX_OSTACOLI, MIN_SPAWNRATE, headOs1, headOs2, headOs3);
        t.increaseScore();
        t.aggiornaLivello();
        t.CalcMaxScore();
        t.stampaScoreLvl(s);
        t.stampaLivello(s);
        f.Decr(FUEL_DECR);
        s.print();
        /*if((D < 3) && (t.getLvl() < 8))
            Sleep(300 - (t.getLvl() * 20));
        else
            Sleep(40);*/
        Clear(s);
    }
    system("cls");
    gotoXY(23, 13);
    SetConsoleTextAttribute(hconsole, 5);
    cout << "GAME OVER";
    SetConsoleTextAttribute(hconsole, 5);
    Sleep(2000);
    system("cls");
    return t.getMaxScore();
}


