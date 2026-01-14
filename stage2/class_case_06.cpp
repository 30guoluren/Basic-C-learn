#include<iostream>
using namespace std;

class Cube{
private:
    int m_L;
    int m_W;
    int m_H;

public:
    // 设置长宽高
    void setLWH(int L, int W, int H){
        m_H = H;
        m_L = L;
        m_W = W;
    }

    int getL(){
        return m_L;
    }
    int getW(){
        return m_W;
    }
    int getH(){
        return m_H;
    }

    // 获取立方体面积
    int calculateS(){
        return 2*m_H*m_L + 2*m_H*m_W + 2*m_L*m_W;
    }
    // 获取立方体体积
    int calculateV(){
        return m_H*m_L*m_W;
    }

    // 利用成员函数判断两个函数是否相等
    bool isEqualByClass(Cube &c){
        if (m_H == c.getH() && m_L == c.getL() && m_W == c.getW()){
            return true;
        }else{
            return false;
        }
    }
};

// 利用全局函数判断 两个立方体是否相等
bool isEqualCube(Cube &c1, Cube &c2){
    if (c1.getL() == c2.getL() && c1.getW() == c2.getW() && c1.getH() == c2.getH()){
        return true;
    }else{
        return false;
    }
}

int main(){
    Cube c1;
    c1.setLWH(12, 10, 10);
    int S = c1.calculateS();
    int V = c1.calculateV();
    cout << "c1 的面积：" << S << endl;
    cout << "c1 的体积：" << V << endl;

    // 创建第二个立方体
    Cube c2;
    c2.setLWH(12, 10, 10);

    bool ret = isEqualCube(c1, c2);
    if (ret){
        cout << "c1 与 c2 相等" << endl;
    }else{
        cout << "c1 与 c2 不相等" << endl;
    }

    // 利用成员函数判断
    bool ret1 = c1.isEqualByClass(c2);

    if (ret1){
        cout << "成员函数判断结果, c1 与 c2 相等" << endl;
    }else{
        cout << "成员函数判断结果, c1 与 c2 不相等" << endl;
    }
    return 0;
}