class Ostacolo3 {
protected:
    int xPos;
    int yPos;
    int value=15;
    char simbolo = 'M';
public:
    void appear(int z, int lvl);
    Ostacolo3();
    void print(DoStrada &s);
    void Disegna(int x, int y, DoStrada &s);
    void move();
    bool collision(int X, int Y);
    int getValue();
    void RandomMove(int z, DoStrada &s);
    void moveLeft();
    void moveRight();
    bool isPossibleRight(DoStrada &s);
    bool isPossibleLeft(DoStrada &s);
    int getyPos();
};
