// 成员函数做友元

#include<iostream>
using namespace std;

class Building;

class GoodGay{
    public:

    GoodGay();

    void visit(); // 让 visit 可以访问 Building 中私有成员
    void visit2(); // 让 visit 不可以访问 Building 中私有成员

    Building *building;
};

class Building{

    friend void GoodGay :: visit(); // 告诉编译器 GoogGay 类下的 visit 成员函数作为本类的好朋友，可以访问私有成员

    public:
    Building();

    public:
    string m_SittingRoom;

    private:
    string m_BedRoom;
};

Building :: Building(){
    m_BedRoom = "卧室";
    m_SittingRoom = "客厅";
}

GoodGay :: GoodGay(){
    building = new Building;
}

void GoodGay :: visit(){
    cout << "visit 函数正在访问: " << building->m_SittingRoom << endl;

    cout << "visit 函数正在访问: " << building->m_BedRoom << endl;

}

void GoodGay :: visit2(){
    cout << "visit2 函数正在访问: " << building->m_SittingRoom << endl;

    // cout << "visit 函数正在访问: " << building->m_BedRoom << endl;


}

void test01(){
    GoodGay gg;
    gg.visit();
    gg.visit2();
}

int main(){
    test01();
    return 0;
}