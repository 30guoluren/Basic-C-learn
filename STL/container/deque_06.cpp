// deque 排序
// sort(iterator beg, iterator end);

#include<iostream>
#include<deque>
#include<algorithm>

using namespace std;

void printDeque(const deque<int> &d){
    for (deque<int>::const_iterator it=d.begin(); it!=d.end(); it++){
        cout << *it << " ";
    }
    cout << endl;
}

void test01(){
    deque<int> d;
    d.push_back(1);
    d.push_back(2);
    d.push_back(34);
    d.push_front(333);
    d.push_front(43);
    printDeque(d);

    // 排序
    sort(d.begin(), d.end()); // 默认从小到大
    printDeque(d);

}


int main(){
    test01();    
    return 0;
}