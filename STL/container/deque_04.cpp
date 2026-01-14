// deque 插入和删除

// 两端
// push_back(elem);
// push_front(elem);
// pop_back(elem);
// pop_front(elem);

// 指定位置
// insert(pos, elem);  // 返回新元素的位置
// insert(pos, n, elem);  // 无返回值
// insert(pos, beg, end); // 在 pos 位置插入 [beg,end)区间的数据，无返回值
// clear();
// erase(beg, end); // 返回下一个数据的位置
// erase(pos); // 删除 pos 位置数据，返回下一个数据位置

#include<iostream>
#include<deque>

using namespace std;

void printDeque(const deque<int> &d){
    for (deque<int>::const_iterator it=d.begin(); it!=d.end(); it++){
        cout << *it << " ";
    }
    cout << endl;
}


// 两端
void test01(){
    deque<int> d1;
    d1.push_back(10);
    d1.push_back(9);
    d1.push_front(1);
    d1.push_front(2);
    printDeque(d1);

    // 尾删
    d1.pop_back();
    d1.pop_front();
    printDeque(d1);

}

// insert
void test02(){
    deque<int> d1;
    d1.push_back(10);
    d1.push_back(20);
    d1.push_back(30);
    printDeque(d1);

    // insert
    d1.insert(d1.begin(), 1000);
    printDeque(d1);

    d1.insert(d1.begin(), 2, 999);
    printDeque(d1);

    // 按照区间来进行插入
    deque<int> d2;
    d2.push_back(1);
    d2.push_back(2);
    d2.push_back(3);
    d1.insert(d1.begin(), d2.begin(), d2.end());
    printDeque(d1);
}

void test03(){
    deque<int> d2;
    d2.push_back(1);
    d2.push_back(2);
    d2.push_back(3);

    // 删除
    deque<int>::iterator it = d2.begin();
    it++;
    d2.erase(it);
    printDeque(d2);

    // 区间
    d2.erase(d2.begin(), d2.end()); // d2.clear();
}


int main(){
    // test01();
    // test02();
    test03();
    return 0;
}