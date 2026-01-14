// 数据存取

// front(); 返回第一个元素
// back(); // 返回最后一个元素

#include<iostream>
#include<list>

using namespace std;

void printList(const list<int> &l){
    for (list<int>::const_iterator it=l.begin(); it!=l.end(); it++){
        cout << *it << " ";
    }
    cout << endl;
}

void test01(){
    list<int> l;
    l.push_back(1);
    l.push_back(2);
    l.push_back(3);

    cout << l.front() << " " << l.back() << endl;

    printList(l);

    // 该迭代器不支持随即访问
    list<int>::iterator it = l.begin();
    it++; // 支持双向
    it--;

    // it = it + 1; // 错误，不支持随即访问
}

int main(){
    test01();
    return 0;
}