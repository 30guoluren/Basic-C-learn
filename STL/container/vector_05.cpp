// vector 数据存取

// at(int idx); // 返回索引 idx 所指的数据
// operator[];  // 返回索引 idx 所指的数据
// front();     // 返回容器中第一个数据元素
// back();      // 返回容器中最后一个数据元素

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
    vector<int> v1;
    for (int i=0; i<10; i++){
        v1.push_back(i);
    }

    for (int i=0; i<v1.size(); i++){
        cout << v1[i] << " ";
    }
    cout << endl;

    // 利用 at
    for (int i=0; i<v1.size(); i++){
        cout << v1.at(i) << " ";
    }
    cout << endl;

    // 第一个元素
    cout << v1.front() << endl;

    // 最后一个元素
    cout << v1.back() << endl;
}


int main(){
    test01();
    return 0;
}