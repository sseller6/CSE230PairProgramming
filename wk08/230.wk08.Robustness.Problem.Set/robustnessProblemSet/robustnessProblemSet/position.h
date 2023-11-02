#pragma once


/****************************************************************
* POSITION
****************************************************************/
class Position
{
private:
    char position;
public:
    Position();
    int getRow();
    int getColumn();
    void set(int row, int column);
    void display();

};

