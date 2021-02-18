#include "DoStrada.hpp"
#include "Fuel.hpp"
using namespace std;

Fuel::Fuel(){
    fuel= 300;
    for(int i= 0; i < 10; i++)
        ast[i]= '*';
}

int Fuel::getfuel(){
    return fuel;
}

void Fuel::Decr(int D){
    if (D <= fuel) {
        fuel = fuel - D;
        for (int i = 0; i < fuel / 30; i++)
            ast[i] = '*';
        for (int i = fuel / 30; i < 10; i++)
            ast[i] = '?';
    } else
        fuel=0;
}

void Fuel::Incr(int D){
    if (D + fuel <= 300) {
        fuel = fuel + D;
        for (int i = 0; i < fuel / 30; i++)
            ast[i] = '*';
        for (int i = fuel / 30; i < 10; i++)
            ast[i] = '?';
    } else {
        for (int i= 0; i < 10; i++)
            ast[i] = '*';
        fuel = 300;
    }
}


void Fuel::drawast(DoStrada &s)
{
    for(int i= 0; i < 10; i++)
        s.strada[65+i][3]= ast[i];
}
