// 全局函数做友元

#include<iostream>
using namespace std;

class Building{

    // goodGay 全局函数是 building 好朋友，可以访问 Building 中的私有成员
    friend void goodGay(Building &building);

    public:
    Building(){
        m_SittingRoom = "客厅";
        m_BedRoom = "卧室";
    }
    public:
    string m_SittingRoom;

    private:
    string m_BedRoom;
};

void goodGay(Building &building){
    cout << "好基友的全局函数，正在访问：" << building.m_SittingRoom << endl;

    cout << "好基友的全局函数，正在访问：" << building.m_BedRoom << endl;

}

void test01(){
    Building building;
    goodGay(building);
}

int main(){
    test01();
    return 0;
}