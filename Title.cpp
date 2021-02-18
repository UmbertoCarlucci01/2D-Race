#include "Title.hpp"
#include "Menu.hpp"
#include <iostream>
#include <conio.h>
#include "Funzioni.h"
#include "windows.h"
using namespace std;

Menu menu= Menu();
Title::Title(){
    stampa = false;
    buffer = ' ';
    xMax = 105;
    yMax = 12;
    decoration = 0;
    xCar = 68;
    yCar = 4;
};

void Title::stampaTitle() {
    ShowConsoleCursor(false);
    while(true) {
        x = rand() % xMax;
        y = rand() % yMax;
        if (!stampa) {
            gotoXY(0, 2);
            cout << "   /$$$$$$  /$$$$$$$        /$$$$$$$   /$$$$$$   /$$$$$$  /$$$$$$$$\n";Sleep(100);
            cout << "  /$$__  $$| $$__  $$      | $$__  $$ /$$__  $$ /$$__  $$| $$_____/\n";Sleep(100);
            cout << " |__/  \\ $$| $$  \\ $$      | $$  \\ $$| $$  \\ $$| $$  \\__/| $$      \n";Sleep(100);
            cout << "   /$$$$$$/| $$  | $$      | $$$$$$$/| $$$$$$$$| $$      | $$$$$   \n";Sleep(100);
            cout << "  /$$____/ | $$  | $$      | $$__  $$| $$__  $$| $$      | $$__/   \n";Sleep(100);
            cout << " | $$      | $$  | $$      | $$  \\ $$| $$  | $$| $$    $$| $$      \n";Sleep(100);
            cout << " | $$$$$$$$| $$$$$$$/      | $$  | $$| $$  | $$|  $$$$$$/| $$$$$$$$\n";Sleep(100);
            cout << " |________/|_______/       |__/  |__/|__/  |__/ \\______/ |________/";Sleep(400);


            gotoXY(xCar, yCar);cout << "    _-_-  _/\\______\\\\__\n";
            gotoXY(xCar, yCar+1);cout << " _-_-__  / ,-. -|-  ,-.`-.\n";
            gotoXY(xCar, yCar+2);cout << "    _-_- `( o )----( o )-'\n";
            gotoXY(xCar, yCar+3);cout << "           `-'      `-'";

            gotoXY(35, 13);
            cout << "| PREMI UN TASTO PER CONTINUARE |";
        }
        if ((stampa) && (decoration<30) && ((x > 94) || (y > 9) || (x < 1) || (y < 2))) {
            gotoXY(x, y);
            cout << "*";
            Sleep(400);
            decoration++;
        }

        stampa = true;
        if (kbhit()) {
            gotoXY(35, 13);
            cout << "                                 ";
            buffer = getch();
            while (true) {
                menu.MenuIniziale();
            }
        }
    }
}