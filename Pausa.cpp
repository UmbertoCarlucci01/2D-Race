#include "Pausa.hpp"
#include <iostream>
#include <windows.h>
#include <conio.h>
#include "Funzioni.h"
using namespace std;

Pausa::Pausa(){
    pause = false;
    c = 10;
    opz = 1;
}

void Pausa::timer(){
    gotoXY(27,12);
    cout<<"3";
    Sleep(1000);
    gotoXY(27,12);
    cout<<"2";
    Sleep(1000);
    gotoXY(27,12);
    cout<<"1";
    Sleep(1000);
    gotoXY(26,12);
    cout<<"VIA";
    Sleep(500);
}

int Pausa::ControlliMenu(int o) {

    char input = ' ';
    if (_kbhit()) {
        input = _getch();
        if (input == 'w' && o>1) {
            o = o-1;
        }
        else if (input == 's' && o<2) {
            o = o+1;
        }
        if (o==1) { //RESUME
            if (input == '\r' && pause == true) {
                pause = false;
                timer();
            }
        }
    }
    if (o==2) { //EXIT
        if (input == '\r') {
            pause = false;
        }
    }
    return o;
}

int Pausa::MenuPausa() {
    pause = true;

    HANDLE hconsole;
    hconsole= GetStdHandle(STD_OUTPUT_HANDLE);

    gotoXY(25,10);
    cout<<"PAUSA";

    while(pause) {
        if (opz==1) {
            SetConsoleTextAttribute(hconsole, 7);
            gotoXY(12, 14);
            cout << "MENU";
            gotoXY(11, 12);
            SetConsoleTextAttribute(hconsole, c);cout << ">";
            gotoXY(12, 12);
            cout << "RESUME";
            Sleep(250);
            gotoXY(11, 12);
            cout << " ";
            Sleep(250);
        }
        else if (opz==2) {
            SetConsoleTextAttribute(hconsole, 7);cout << ">";
            gotoXY(12, 12);
            cout << "RESUME";
            SetConsoleTextAttribute(hconsole, c);gotoXY(11, 14);
            cout << ">";
            gotoXY(12, 14);
            cout << "MENU";
            Sleep(250);
            gotoXY(11, 14);
            cout << " ";
            Sleep(250);
        }
        opz=ControlliMenu(opz);
    }
    return opz;
}
