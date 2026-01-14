// string 基本

// 本质
// string 是 C++ 风格的字符串，而 string 本质上是一个类

// string 和 char* 的区别
// - char* 是一个指针
// - string 是一个类，类内部封装了 char*，管理这个字符串，是一个 char* 型的容器。

// 查找 find，拷贝 copy，删除 delete，替换 replace，插入 insert
// string 管理 char* 所分配的内存，不用担心复制越界和取值越界等，由类内部进行负责

#include<iostream>

using namespace std;


// string 构造函数

void test01(){
    string s1; // 默认构造

    const char *str = "hello world";
    string s2(str); // 字符串构造

    cout << "S2 = " << s2 << endl;

    string s3(s2); // 拷贝构造
    cout << "S3 = " << s3 << endl;

    string s4(10, 'a');
    cout << s4 << endl;

}


int main(){
    test01();
    return 0;
}