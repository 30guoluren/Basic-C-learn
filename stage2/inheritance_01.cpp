// 继承

#include<iostream>
using namespace std;

// class Java{
//     public:
//     void header(){
//         cout << "首页、公开课、登录、注册..(公共头部)" << endl;
//     }

//     void footer(){
//         cout << "帮助中心、交流合作、站内地图..(公共底部)" << endl;
//     }

//     void left(){
//         cout << "Java, python " << endl;
//     }

//     void center(){
//         cout << "Java 学科视频" << endl;
//     }
// };

// 继承实现页面

// 子类也成为派生类
// 父类：基类

class BasePage{
    public:
    void header(){
        cout << "首页、公开课、登录、注册..(公共头部)" << endl;
    }

    void footer(){
        cout << "帮助中心、交流合作、站内地图..(公共底部)" << endl;
    }

    void left(){
        cout << "Java, python " << endl;
    }
};

class Java: public BasePage{
    public:
    void center(){
        cout << "Java 学科视频" << endl;
    }
};

class CPP: public BasePage{
    public:
    void center(){
        cout << "CPP 学科视频" << endl;
    }
};

class Python: public BasePage{
    public:
    void center(){
        cout << "Python 学科视频" << endl;
    }
};

void test01(){
    Java java;
    java.center();
    java.footer();
    java.header();
    java.left();
}


int main(){
    system("chcp 65001");
    test01();
    return 0;
}

