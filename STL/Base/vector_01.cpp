#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

void myPrint(int val){
    cout << val << endl;
}


// vector 容器存放内置数据类型
void test01(){
    vector<int> v;

    // 向容器中插入
    v.push_back(1); // 尾插数据
    v.push_back(2);

    // 通过迭代器访问容器中的数据
    vector<int> :: iterator itBegin = v.begin(); // 起始迭代器，指向容器第一个元素
    vector<int> :: iterator itEnd = v.end(); // 结束迭代器，指向容器中最后一个元素的下一个位置

    // 第一种遍历方式
    while (itBegin != itEnd){
        cout << *itBegin << endl;
        itBegin ++;
    }


    // 第二种遍历方式
    for (vector<int>::iterator it=v.begin(); it!=v.end(); it++){
        cout << *it << endl;
    }


    // 第三种遍历方式，利用 STL 提供遍历算法
    for_each(v.begin(), v.end(), myPrint);
}


int main(){
    test01();
    return 0;
}
