class Fuel {
protected:
    int fuel;
    char ast[10];
public:
    Fuel();
    int getfuel();
    void Decr(int D);
    void Incr(int D);
    void drawast(DoStrada &s);
};

