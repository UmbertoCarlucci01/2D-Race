class Macchina {
protected:
    int xPos;
    int yPos;
    char simbolo;
    bool end;
    bool FuoriStrada;
public:
    Macchina();
    void disegna(DoStrada &s);
    void MuoviSX();
    void MuoviDX();
    void MuoviUP();
    void MuoviDW();
    void DisegnaPunto(int x, int y, DoStrada &s);
    void Controlli();
    int getX();
    int getY();
    void Flashing(int t);
    bool getEnd();
    bool getFuoriStrada();
};

