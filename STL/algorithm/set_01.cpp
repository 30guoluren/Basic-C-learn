// 常见的集合算法

// set_intersection 求两个集合的交集
// set_union 求两个容器的并集
// set_difference 求两个集合的差集


#include <algorithm>
#include<iostream>
#include <new>
#include <vector>

using namespace std;

// set_intersection(iterator_beg1, iterator_end1, iterator_beg2, iterator_end2, iterator_dest);
// 求交集的两个集合必须为有序序列
// 目标容器开辟空间需要从两个容器中取小值
// set_intersection 返回值是交集中最后一个元素的迭代器位置



void print01(int val){
    cout << val << " ";
}

void test01(){
    vector<int> v1;
    vector<int> v2;

    for (int i=0; i<10; i++){
        v1.push_back(i);
        v2.push_back(i+1);
    }

    vector<int> vInter;
    vInter.resize(min(v1.size(), v2.size()));

    vector<int>::iterator itEnd = set_intersection(v1.begin(), v1.end(), v2.begin(), v2.end(), vInter.begin());

    for_each(vInter.begin(), itEnd, print01);
    cout << endl;
}

int main(){
    test01();
    return 0;
}