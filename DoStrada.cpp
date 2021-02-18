#include <windows.h>
#include <iostream>
#include "DoStrada.hpp"
using namespace std;

void DoStrada::gotoXY(int x, int y)
{
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}


DoStrada::DoStrada(){
    for(int i= 0; i < lun; i++)
        for(int j= 0; j < lar; j++)
            strada[j][i]= '?';
    for(int i= 0; i < lun; i++) {
        strada[0][i] = '#';
        strada[lars-1][i] = '#';
    }
    strada[65][2]= 'F';
    strada[66][2]= 'U';
    strada[67][2]= 'E';
    strada[68][2]= 'L';
    strada[65][7]= 'S';
    strada[66][7]= 'C';
    strada[67][7]= 'O';
    strada[68][7]= 'R';
    strada[69][7]= 'E';
    strada[65][12]= 'L';
    strada[66][12]= 'V';
    strada[67][12]= 'L';
}

void DoStrada::print(){
    HANDLE hconsole;
    hconsole= GetStdHandle(STD_OUTPUT_HANDLE);
    for(int i= 0; i < lun; i++) {
        for (int j = 0; j < lar; j++) {
            if(strada[j][i] != '?') {
                gotoXY(j, i);
                if(strada[j][i] == '@')
                    SetConsoleTextAttribute(hconsole, 14);
                else
                    SetConsoleTextAttribute(hconsole, 7);
                if(((strada[j][i] == 'H') ) && (j <= 65))
                    SetConsoleTextAttribute(hconsole, 12);
                if(strada[j][i] == 'G')
                    SetConsoleTextAttribute(hconsole, 10);
                if((strada[j][i] == 'O') && (j <= 65))
                    SetConsoleTextAttribute(hconsole, 1);
                if(strada[j][i] == 'M')
                    SetConsoleTextAttribute(hconsole, 13);
                cout << strada[j][i];
            }
            if(strada[j][i] == '?')
                cout << " ";
        }

    }
}
