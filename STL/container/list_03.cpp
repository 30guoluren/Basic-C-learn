// 大小操作

// empty();
// size();
// resize(num);
// resize(num, elem);

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
    list<int> l1;
    l1.push_back(1);
    l1.push_back(2);
    l1.push_back(3);
    printList(l1);

    if (l1.empty()){
        cout << "l1 is empty" << endl;
    }else {
        cout << "l1 size is " << l1.size() << endl;
    }

    l1.resize(10);
    printList(l1);

    l1.resize(2, 100);
    printList(l1);
}

int main(){
    test01();
    return 0;
}