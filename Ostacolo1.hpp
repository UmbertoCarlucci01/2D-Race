class Ostacolo1 {
protected:
    int xPos;
    int yPos;
    int value=25;
    char simbolo = 'H';
public:
    void appear(int z, int lvl);
    Ostacolo1();
    void print(DoStrada &s);
    void Disegna(int x, int y, DoStrada &s);
    void move();
    bool collision(int X, int Y);
    int getValue();
    int getyPos();
};