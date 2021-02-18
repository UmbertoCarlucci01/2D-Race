#include "DoStrada.hpp"
#include "Score.hpp"
#include "cmath"
#include <iostream>
using namespace std;

struct Cifre {
    int c;
    Cifre* next;
};

Cifre* aggiungiCoda(int d, Cifre* head){
    if(head==NULL) {
        head=new Cifre;
        head->c=d;
        head->next=NULL;
    }
    else {
        Cifre *p1, *p2;
        p1 = new Cifre;
        p1->c=d;
        p1->next=NULL;
        p2 = head;
        while(p2->next!=NULL) p2=p2->next;
        p2->next=p1;
    }
    return head;
}

Score::Score(){
    lvl = 1;
    score = 1;
    MaxScore = 0;
}

void Score::CalcMaxScore(){
    if (score>MaxScore) MaxScore = score;
}

void Score::increaseScore(){
    score=score+aumento;
}

void Score::setAumento(int a){
    aumento=a+25;
}

void Score::decreaseScore(int value){
    score=score-(value*10);
}

void Score::increaseByGas(int value){
    score=score+value;
}

void Score::stampaScoreLvl(DoStrada &s){
    if(score<999999999){
        int scoreLen = (int)(log10(score))+1;
        int h=score;
        int tmp=0;
        Cifre* head=NULL;
            for (int i = 0; i < scoreLen; i++) {
                tmp = (int) (h / pow(10, scoreLen - (i + 1)));
                head = aggiungiCoda(tmp + 48, head);
                h = h - tmp * pow(10, scoreLen - (i + 1));
            }
        Cifre* tmpPointer=head;
        Cifre* cestino;
        int j=0;
        while(tmpPointer!=NULL && j<scoreLen){
            s.strada[65+j][9]=(char)tmpPointer->c;
            cestino=tmpPointer;
            tmpPointer=tmpPointer->next;
            delete cestino;
            j++;
        }
    }
    else{
        for(int i=0; i<9; i++){
            s.strada[65+i][9]='9';
        }
    }
}

void Score::aggiornaLivello(){
    lvl=(int)(score/1000)+1;
}

void Score::stampaLivello(DoStrada &s){
    if(lvl<999999){
        int lvlLen = (int)(log10(lvl))+1;
        int h = lvl;
        int tmp = 0;
        Cifre* head=NULL;
        for (int i = 0; i < lvlLen; i++) {
            tmp = (int) (h / pow(10, lvlLen - (i + 1)));
            head = aggiungiCoda(tmp + 48, head);
            h = h - tmp * pow(10, lvlLen - (i + 1));
        }
        Cifre* tmpPointer=head;
        Cifre* cestino;
        int j=0;
        while(tmpPointer!=NULL && j<lvlLen){
            s.strada[65+j][14]=(char)tmpPointer->c;
            cestino=tmpPointer;
            tmpPointer=tmpPointer->next;
            delete cestino;
            j++;
        }
    }
    else{
        for(int i=0; i<9; i++){
            s.strada[65+i][14]='9';
        }
    }
}

int Score::getLvl(){
    return lvl;
}

int Score::getScore(){
    return score;
}

int Score::getMaxScore(){
    return MaxScore;
}