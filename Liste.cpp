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
#include <iostream>


struct listaOs1{
    Ostacolo1 c;
    int Diff;
    int spawnLvl;
    listaOs1 *next;
};

struct listaOs2{
    Ostacolo2 o;
    int Diff;
    int spawnLvl;
    listaOs2 *next;
};

struct listaOs3{
    Ostacolo3 o;
    int Diff;
    int spawnLvl;
    listaOs3 *next;
};

struct listaGas{
    Gas g;
    int Diff;
    int spawnLvl;
    listaGas *next;
};

listaOs1* addOs1(listaOs1* head, int D, int l){
    if(head==NULL){
        head= new listaOs1;
        head->c= Ostacolo1();
        head->Diff= D;
        head->spawnLvl= l;
        head->next= NULL;
    }
    else{
        listaOs1 *tmp1, *tmp2;
        tmp2= new listaOs1;
        tmp2->c= Ostacolo1();
        tmp2->Diff= D;
        tmp2->spawnLvl= l;
        tmp2->next= NULL;
        tmp1=head;
        while(tmp1->next != NULL) tmp1= tmp1->next;
        tmp1->next= tmp2;
    }
    return head;
}

listaOs2* addOs2(listaOs2* head, int D, int l){
    if(head==NULL){
        head= new listaOs2;
        head->o= Ostacolo2();
        head->Diff= D;
        head->spawnLvl= l;
        head->next= NULL;
    }
    else{
        listaOs2 *tmp1, *tmp2;
        tmp2= new listaOs2;
        tmp2->o= Ostacolo2();
        tmp2->Diff= D;
        tmp2->spawnLvl= l;
        tmp2->next= NULL;
        tmp1=head;
        while(tmp1->next != NULL) tmp1= tmp1->next;
        tmp1->next= tmp2;
    }
    return head;
}

listaOs3* addOs3(listaOs3* head, int D, int l){
    if(head==NULL){
        head= new listaOs3;
        head->o= Ostacolo3();
        head->Diff= D;
        head->spawnLvl= l;
        head->next= NULL;
    }
    else{
        listaOs3 *tmp1, *tmp2;
        tmp2= new listaOs3;
        tmp2->o= Ostacolo3();
        tmp2->Diff= D;
        tmp2->spawnLvl= l;
        tmp2->next= NULL;
        tmp1=head;
        while(tmp1->next != NULL) tmp1= tmp1->next;
        tmp1->next= tmp2;
    }
    return head;
}

listaGas* addGas(listaGas* head, int D, int l){
    if(head==NULL){
        head= new listaGas;
        head->g= Gas();
        head->Diff= D;
        head->spawnLvl= l;
        head->next= NULL;
    }
    else{
        listaGas *tmp1, *tmp2;
        tmp2= new listaGas;
        tmp2->g= Gas();
        tmp2->Diff= D;
        tmp2->spawnLvl= l;
        tmp2->next= NULL;
        tmp1=head;
        while(tmp1->next != NULL) tmp1= tmp1->next;
        tmp1->next= tmp2;
    }
    return head;
}

const int DEL_CHANCE= 2;

listaOs1* delOs1(listaOs1* head, int &oCounter)
{
    if(rand()%DEL_CHANCE == 0)
    {
        if (head->c.getyPos() == 29 && head != NULL) {
            if(head->next != NULL) {
                listaOs1 *tmp = head;
                head = head->next;
                head->spawnLvl= tmp->spawnLvl;
                delete tmp;
                oCounter--;
            }
        }
    }
    return head;
}

listaOs2* delOs2(listaOs2* head, int &oCounter)
{
    if(rand()%DEL_CHANCE == 0)
    {
        if (head->o.getyPos() == 29 && head != NULL) {
            if(head->next != NULL) {
                listaOs2 *tmp = head;
                head = head->next;
                head->spawnLvl= tmp->spawnLvl;
                delete tmp;
                oCounter--;
            }
        }
    }
    return head;
}

listaOs3* delOs3(listaOs3* head, int &oCounter)
{
    if(rand()%DEL_CHANCE == 0)
    {
        if (head->o.getyPos() == 29 && head != NULL) {
            if(head->next != NULL) {
                listaOs3 *tmp = head;
                head = head->next;
                head->spawnLvl= tmp->spawnLvl;
                delete tmp;
                oCounter--;
            }
        }
    }
    return head;
}

const int DScore= 20;
const int LvlScore= 8;
const int DFuel= 6;
//const int LvlFuel=3;
const int FlashN= 6;
const int LvlScoreG= LvlScore - 3;
const int DFuelG= DFuel - 1;
const int LvlFuelG= 2;


void ManOs1(listaOs1* tmpOs1, int D, int CurrLvl, DoStrada &s, int Mx, int My, int &Flashes, Score &t, Fuel &f){
    while(tmpOs1 != NULL) {
        if (tmpOs1->c.collision(Mx, My)) {
            t.decreaseScore(tmpOs1->c.getValue() + (D * DScore) + (CurrLvl * LvlScore));
            f.Decr(tmpOs1->c.getValue() + (D * DFuel));
            Flashes = FlashN;
        }
        if((D >= tmpOs1->Diff) && (CurrLvl >= tmpOs1->spawnLvl))
            tmpOs1->c.appear(rand(), CurrLvl);
        tmpOs1->c.print(s);
        tmpOs1->c.move();
        tmpOs1= tmpOs1->next;
    }
}

void ManOs2(listaOs2* tmpOs2, int D, int CurrLvl, DoStrada &s, int Mx, int My, int &Flashes, Score &t, Fuel &f){
    while(tmpOs2 != NULL) {
        if (tmpOs2->o.collision(Mx, My)) {
            t.decreaseScore(tmpOs2->o.getValue() + (D * DScore) + (CurrLvl * LvlScore));
            f.Decr(tmpOs2->o.getValue() + (D * DFuel));
            Flashes = FlashN;
        }
        if((D >= tmpOs2->Diff) && (CurrLvl >= tmpOs2->spawnLvl))
            tmpOs2->o.appear(rand(), CurrLvl);
        tmpOs2->o.print(s);
        tmpOs2->o.move();
        tmpOs2= tmpOs2->next;
    }
}

void ManOs3(listaOs3* tmpOs3, int D, int CurrLvl, DoStrada &s, int Mx, int My, int &Flashes, Score &t, Fuel &f){
    while(tmpOs3 != NULL) {
        if (tmpOs3->o.collision(Mx, My)) {
            t.decreaseScore(tmpOs3->o.getValue() + (D * DScore) + (CurrLvl * LvlScore));
            f.Decr(tmpOs3->o.getValue() + (D * DFuel));
            Flashes = 6;
        }
        if((D >= tmpOs3->Diff) && (CurrLvl >= tmpOs3->spawnLvl))
            tmpOs3->o.appear(rand(), CurrLvl);
        tmpOs3->o.RandomMove(rand(), s);
        tmpOs3->o.print(s);
        tmpOs3->o.move();
        tmpOs3= tmpOs3->next;
    }
}

void ManGas(listaGas* tmpGas, int D, int CurrLvl, DoStrada &s, int Mx, int My, Score &t, Fuel &f){
    while(tmpGas != NULL) {
        if((tmpGas->g.collision(Mx, My))) {
            t.increaseByGas(tmpGas->g.getValue()*2 + LvlScoreG);
            f.Incr(tmpGas->g.getValue() + (D * DFuelG));
        }
        if((D >= tmpGas->Diff) && (CurrLvl >= tmpGas->spawnLvl))
            tmpGas->g.appear(rand());
        tmpGas->g.print(s);
        tmpGas->g.move();
        tmpGas= tmpGas->next;
    }
}


