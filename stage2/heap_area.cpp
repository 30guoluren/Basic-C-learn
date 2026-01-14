// 堆区
// 由程序员分配释放，若程序员不释放，结束时由操作系统释放
// 在 C++ 中主要利用 new 来在堆区中开辟内存

#include <iostream>
using namespace std;

int* func() {
    // 利用 new 关键字，可以将数据开辟到堆区
    int* p = new int(10);
    return p;
}

int main() {
    // 在堆区开辟数据
    int* p = func();
    cout << *p << endl;
    return 0;
}