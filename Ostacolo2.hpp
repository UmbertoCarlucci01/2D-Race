class Ostacolo2 {
protected:
    int xPos;
    int yPos;
    int value=10;
    char simbolo = 'O';
public:
    void appear(int z, int lvl);
    Ostacolo2();
    void print(DoStrada &s);
    void Disegna(int x, int y, DoStrada &s);
    void move();
    bool collision(int X, int Y);
    int getValue();
    int getyPos();
};
