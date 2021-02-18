#include "Menu.hpp"
#include "DoStrada.hpp"
#include <iostream>
#include <windows.h>
#include <conio.h>
#include "Funzioni.h"
#include "Score.hpp"
#include "Pausa.hpp"
using namespace std;

Menu::Menu(){
    c = 10;
    y = 29;
    opz = 1;
    start = false;
    GameOver = false;
    MaxScore = 0;
}

Pausa pausa = Pausa();

int Menu::ControlliMenu(int o) {

    char input = ' ';
    if (_kbhit()) {
        input = _getch();
        if (input == 'w' && o>1) {
            o = o-1;
        }
        else if (input == 's' && o<2) {
            o = o+1;
        }
        else if (o==1) { //START || RESTART || RESUME
            if (input == '\r') {
                system("cls");
                Scelta();
            }
        }
        else if (o==2) { //EXIT
            if (input == '\r') {
                exit(0);
            }
        }
    }
    return o;
}

int Menu::ControlliDifficolta(int o) {
    HANDLE hconsole;
    hconsole= GetStdHandle(STD_OUTPUT_HANDLE);

    char input = ' ';
    bool Running= false;
    if (_kbhit()) {
        input = _getch();
        if (input == 'w' && o>1) {
            o = o-1;
        }
        else if (input == 's' && o<3) {
            o = o+1;
        }
        else if (o==1) { //FACILE
            if (input == '\r') {
                start = true;
                system("cls");
                SetConsoleTextAttribute(hconsole, 7);
                Difficolta=1;
                pausa.timer();
                Running= true;
            }
        }
        else if (o==2) {  //NORMALE
            if (input == '\r') {
                start = true;
                system("cls");
                SetConsoleTextAttribute(hconsole, 7);
                Difficolta=2;
                pausa.timer();
                Running= true;
            }
        }
        else if (o==3) {  //DIFFICILE
            if (input == '\r') {
                start = true;
                system("cls");
                SetConsoleTextAttribute(hconsole, 7);
                Difficolta=3;
                pausa.timer();
                Running= true;
            }
        }
        if(Running)
            MaxScore = StartGame(Difficolta);
        Running=false;
    }
    return o;
}


void Menu::Scelta() {
    HANDLE hconsole;
    hconsole = GetStdHandle(STD_OUTPUT_HANDLE);

    while (!start) {
        if (opz == 1) {
            SetConsoleTextAttribute(hconsole, 7);
            gotoXY(12, 16);
            cout << "DIFFICILE";
            SetConsoleTextAttribute(hconsole, 7);
            gotoXY(12, 14);
            cout << "NORMALE";
            gotoXY(11, 12);
            SetConsoleTextAttribute(hconsole, c);
            cout << ">";
            gotoXY(12, 12);
            cout << "FACILE";
            Sleep(250);
            gotoXY(11, 12);
            cout << " ";
            Sleep(250);
        } else if (opz == 2) {
            SetConsoleTextAttribute(hconsole, 7);
            gotoXY(12, 16);
            cout << "DIFFICILE";
            gotoXY(12, 14);
            SetConsoleTextAttribute(hconsole, 7);
            cout << ">";
            gotoXY(12, 12);
            cout << "FACILE";
            SetConsoleTextAttribute(hconsole, c);
            gotoXY(11, 14);
            cout << ">";
            gotoXY(12, 14);
            cout << "NORMALE";
            Sleep(250);
            gotoXY(11, 14);
            cout << " ";
            Sleep(250);
        }
        else if (opz == 3) {
            SetConsoleTextAttribute(hconsole, 7);
            cout << ">";
            gotoXY(12, 14);
            cout << "NORMALE";
            SetConsoleTextAttribute(hconsole, c);
            gotoXY(11, 16);
            cout << ">";
            gotoXY(12, 16);
            cout << "DIFFICILE";
            Sleep(250);
            gotoXY(11, 16);
            cout << " ";
            Sleep(250);
        }
        opz = ControlliDifficolta(opz);
    }
}

void Menu::MenuIniziale() {
    start = false;

    HANDLE hconsole;
    hconsole= GetStdHandle(STD_OUTPUT_HANDLE);

    while(!start) {
        if (opz==1) {
            SetConsoleTextAttribute(hconsole, 7);
            gotoXY(12, 17);
            cout << "EXIT";
            gotoXY(11, 15);
            SetConsoleTextAttribute(hconsole, c);cout << ">";
            gotoXY(12, 15);
            if (!GameOver) cout << "START";
            else {
                cout << "RESTART";
                gotoXY(12, 19);
                SetConsoleTextAttribute(hconsole, c);cout << "HIGH SCORE: " << MaxScore << " PUNTI";
            }
            Sleep(250);
            gotoXY(11, 15);
            cout << " ";
            Sleep(250);
        }
        else if (opz==2) {
            SetConsoleTextAttribute(hconsole, 7);cout << ">";
            gotoXY(12, 15);
            if (!GameOver) cout << "START";
            else {
                cout << "RESTART";
                gotoXY(12, 19);
                SetConsoleTextAttribute(hconsole, c);cout << "HIGH SCORE: " << MaxScore << " PUNTI";
            }
            SetConsoleTextAttribute(hconsole, c);gotoXY(11, 17);
            cout << ">";
            gotoXY(12, 17);
            cout << "EXIT";
            Sleep(250);
            gotoXY(11, 17);
            cout << " ";
            Sleep(250);
        }
        opz=ControlliMenu(opz);
    }
    GameOver = true;
}
