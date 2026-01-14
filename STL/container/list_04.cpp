// list 插入和删除

// push_back(elem);
// pop_back();
// push_front(elem);
// pop_front();
// insert(pos, elem);
// insert(pos, n, elem);
// insert(pos, beg, end);
// clear();
// erase(beg, end); // 返回下一个元素位置
// erase(pos);  // 删除，返回下一个元素位置
// remove(elem); // 删除容器中所有与 elem 值匹配的元素

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
    l1.push_back(10);
    l1.push_back(20);
    l1.push_back(30);
    l1.push_front(100);
    l1.push_front(200);
    l1.push_front(300);
    printList(l1);

    // 尾删
    l1.pop_back();

    // 头删
    l1.pop_front();

    printList(l1);

    // insert
    l1.insert(l1.begin(), 1000);
    printList(l1);

    list<int>::iterator it = l1.begin();
    l1.insert(++it, 12000);
    printList(l1);

    // 删除
    it = l1.begin();
    l1.erase(it);
    printList(l1);

    // remove
    l1.remove(10);
    printList(l1);
    

}

int main(){
    test01();
    return 0;
}