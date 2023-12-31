#ifndef OBJPOS_H
#define OBJPOS_H

class objPos {
  public:
    int x;
    int y;
    char symbol;

    objPos();
    objPos(const objPos &o);
    objPos(int xPos, int yPos, char sym);

    void setObjPos(objPos o);
    void setObjPos(int xPos, int yPos, char sym);
    void getObjPos(objPos &returnPos);
    char getSymbol();

    void setX(int xPos);
    void setY(int yPos);
    int getX() const;
    int getY() const;


    bool isPosEqual(const objPos *refPos);

    char getSymbolIfPosEqual(const objPos *refPos);
};

#endif
