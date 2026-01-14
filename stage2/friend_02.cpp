// 类做友元

#include<iostream>
using namespace std;

class Building;
class goodGay{
    public:
    goodGay();

    public:
    void visit(); // 参观函数，访问 Building 中的属性。

    Building * building;
};

class Building{
    // goodGay 是本类的好朋友，可以访问本类的私有成员
    friend class goodGay;

    public:
    Building();

    public:

    string m_SittingRoom;

    private:

    string m_BedRoom;
};

// 类外写成员函数
Building :: Building(){
    m_SittingRoom = "客厅";
    m_BedRoom = "卧室";
}

goodGay :: goodGay(){
    // 创建建筑物对象
    building = new Building;
}

void goodGay :: visit(){
    cout << "好基友类正在访问：" << building->m_SittingRoom << endl;

    cout << "好基友类正在访问：" << building->m_BedRoom << endl;

}

void test01(){
    goodGay gg;
    gg.visit();
}

int main(){
    test01();
    return 0;
}