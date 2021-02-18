class Score{
private:
    int score;
    int MaxScore;
    int lvl;
    int aumento;
public:
    void increaseScore();
    Score();
    void setAumento(int a);
    void decreaseScore(int value);
    void increaseByGas(int value);
    void stampaScoreLvl(DoStrada &s);
    void aggiornaLivello();
    void stampaLivello(DoStrada &s);
    void CalcMaxScore();
    int getLvl();
    int getScore();
    int getMaxScore();
};