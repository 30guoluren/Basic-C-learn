#include<iostream>
using namespace std;
// 点和圆关系的案例

class Point{
public:
    void setX(int X){
        m_X = X;
    }
    void setY(int Y){
        m_Y = Y;
    }

    int getX(){
        return m_X;
    }

    int getY(){
        return m_Y;
    }


private:
    int m_X;
    int m_Y;
};


class Circle{
public:
    void setRadis(int R){
        m_R = R;
    }
    
    int getRadis(){
        return m_R;
    }

    void setCenter(Point Center){
        m_Center = Center;
    }

    Point getCenter(){
        return m_Center;
    }

private:
    int m_R;
    Point m_Center;
};

// 判断点和圆的关系
void isInCircle(Circle &c, Point &p){
    // 计算两点之间距离的平方
    int s_p_to_c = (c.getCenter().getX() - p.getX()) * (c.getCenter().getX() - p.getX()) +
    (c.getCenter().getY() - p.getY()) * (c.getCenter().getY() - p.getY());
    int s_r = c.getRadis() * c.getRadis();

    if (s_p_to_c > s_r){
        cout << "点在圆外" << endl;
    }
    else if (s_p_to_c < s_r){
        cout << "点在圆内" << endl;
    }
    else{
        cout << "点在圆上" << endl;
    }

}


int main(){
    Circle c;
    Point p_center, p_random;
    p_center.setX(10);
    p_center.setY(0);
    p_random.setX(10);
    p_random.setY(10);
    c.setCenter(p_center);
    c.setRadis(10);
    isInCircle(c, p_random);
    return 0;
}