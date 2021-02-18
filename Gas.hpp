class Gas {
protected:
    int xPos;
    int yPos;
    int value;
    char simbolo = 'G';
public:
    void appear(int z);
    Gas();
    void print(DoStrada &s);
    void Disegna(int x, int y, DoStrada &s);
    void move();
    int getX();
    int getY();
    bool collision(int X, int Y);
    int getValue();
};