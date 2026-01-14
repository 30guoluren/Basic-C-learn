// deque 大小操作

// deque.empty();
// deque.szie();
// deque.resize();
// deque.resize(num, elem);
// deque 没有容量的概念


#include<iostream>
#include<deque>

using namespace std;

void printDeque(const deque<int> d){
    for (deque<int>::const_iterator it=d.begin(); it!=d.end(); it++){
        cout << *it << " ";
    }
    cout << endl;
}

void test01(){
    deque<int> d;
    for (int i=0; i<10; i++){
        d.push_back(i);
    }

    if (d.empty()){
        cout << "d is empty" << endl;
    }else {
        cout << "d size is" << d.size() << endl;
    }

    d.resize(3);
    printDeque(d);

    d.resize(13, 3);
    printDeque(d);
}


int main(){
    test01();
    return 0;
}