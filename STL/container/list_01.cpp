// list 链表：双向循环链表

// list<T> lst;
// list(beg, end); // list 将[begin, end) 之间的元素拷贝给本身
// list(n, elem); // 将 n 个 elem 拷贝给本身
// list(const list &lst); // 拷贝构造函数

#include<iostream>
#include<list>

using namespace std;

void printList(const list<int> &l){
    for (list<int> :: const_iterator it=l.begin(); it!=l.end(); it++){
        cout << *it << " ";
    }
    cout << endl;
}

void test01(){
    list<int> l1; // 默认构造
    // 添加数据
    l1.push_back(10);
    l1.push_back(20);
    l1.push_back(30);
    printList(l1);

    // 区间方式构造
    list<int> l2(l1.begin(), l1.end());
    printList(l2);

    // 拷贝构造
    list<int>l3(l2);
    printList(l3);

    // n ge elem
    list<int> l4(3, 100);
    printList(l4);
}

int main(){
    test01();
    return 0;
}