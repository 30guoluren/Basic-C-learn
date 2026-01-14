// vector 互换容器
// 实现俩个容器内元素进行互换
// swap(vec); // 将 vec 与本身的元素互换

#include <cstddef>
#include<iostream>
#include<vector>


using namespace std;

void printVector(vector<int> &v){
    for (vector<int>::iterator it=v.begin(); it!=v.end(); it++){
        cout << *it << " ";
    }
    cout << endl;
}


void test01(){
    vector<int> v;
    for (int i=0; i<10; i++){
        v.push_back(i);
    }
    printVector(v);

    vector<int> v2;
    for (int i=10; i>0; i--){
        v2.push_back(i);
    }
    printVector(v2);

    cout << "swap" << endl;
    v.swap(v2);
    printVector(v);
    printVector(v2);

}

// 实际用途
// 巧用 swap 可以收缩内存空间
void test02(){
    vector<int> v;
    for (int i=0; i<100000; i++){
        v.push_back(i);
    }
    cout << "capacity: " << v.capacity() << endl;
    cout << "size: " << v.size() << endl;

    v.resize(3); // 重新指定大小
    cout << "capacity: " << v.capacity() << endl;
    cout << "size: " << v.size() << endl;

    // 使用 vector 收缩内存
    vector<int>(v).swap(v);
    cout << "capacity: " << v.capacity() << endl;
    cout << "size: " << v.size() << endl;

}


int main(){
    // test01();
    test02();
    return 0;
}