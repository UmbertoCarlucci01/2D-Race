class Menu {
protected:
    int c;
    int y;
    bool start;
    bool GameOver;
    int opz;
    int Difficolta;
    int MaxScore;

public:
    Menu();
    void MenuIniziale();
    void Scelta();
    int ControlliMenu(int o);
    int ControlliDifficolta(int o);
};