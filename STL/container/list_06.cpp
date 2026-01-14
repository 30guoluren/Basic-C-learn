// list 反转和排序

// reverse();
// sort();

#include<iostream>
#include<list>

using namespace std;

bool myCompare(int v1, int v2){
    // 降序，第一个大于第二个数
    return v1 > v2;
}


void printList(const list<int> &l){
    for (list<int>::const_iterator it=l.begin(); it!=l.end(); it++){
        cout << *it << " ";
    }
    cout << endl;
}

void testr01(){
    list<int> l1;
    l1.push_back(1);
    l1.push_back(2);
    l1.push_back(3);
    l1.push_back(54);
    printList(l1);

    l1.reverse();
    printList(l1);


    // 所有不支持随即访问的迭代器容器，不可以用标准算法
    // 此处不可以使用algorithm，即
    // sort(beg, end);
    // 但内部会提供一些对应的成员方法

    l1.sort(); // 默认升序
    printList(l1);

    l1.sort();
    printList(l1);

    l1.sort(myCompare);
    printList(l1);
    
}

int main(){
    testr01();
    return 0;
}