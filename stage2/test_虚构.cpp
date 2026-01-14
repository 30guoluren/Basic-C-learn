#include<iostream>
#include<vector>
#include<string>

using namespace std;

class Base{
    public:
    Base(){
        cout << "父类构造函数" << endl;
    }

    virtual ~Base(){
        cout << "父类析构函数" << endl;
    }

};

class Son : public Base{
    public:

    Son(){
        cout << "子类构造函数" << endl;
    }

    ~Son(){
        cout << "子类析构函数" << endl;
    }
};

void test01(){
    // Son s;
    Base * base = new Son;
    delete  base;
}

int main(){
    system("chcp 65001");
    test01();
    return 0;
}