#pragma once
#include<iostream>
using namespace std;

class Point{
public:
    void setX(int X);

    void setY(int Y);

    int getX();

    int getY();


private:
    int m_X;
    int m_Y;
};