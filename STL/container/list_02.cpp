// list 赋值和交换

// assign(beg, end);
// assign(n, elem);
// list& operator=(const list &lst);
// swap(lst);

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
    list<int> l1;
    l1.push_back(1);
    l1.push_back(2);
    l1.push_back(3);
    printList(l1);

    // operator=
    list<int> l2 = l1;
    printList(l2);

    // assign
    list<int> l3;
    l3.assign(l2.begin(), l2.end());
    printList(l3);

    // n 个 elem
    list<int> l4;
    l4.assign(3, 3);
    printList(l4);

    // swap
    l3.swap(l4);
    printList(l3);
}


int main(){
    test01();
    return 0;
}