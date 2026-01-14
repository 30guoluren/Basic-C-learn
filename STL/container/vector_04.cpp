// vector 插入与删除

// push_back(ele);                                  // 尾部插入元素 ele
// pop_back();                                      // 删除最后一个元素
// insert(const_iterator pos, ele);                 // 迭代器指向位置 pos 插入元素 ele
// insert(const_iterator pos, int count, ele);      // 迭代器指向位置 pos 插入 count 个元素 ele
// erase(const_iterator pos);                       // 删除迭代器指向的元素
// erase(const_iterator start, const_iterator end); // 删除迭代器从 start 到 end 之间的元素
// clear();                                         // 删除容器中所有元素

#include<iostream>
#include<vector>

using namespace std;

void printVector(vector<int> &v){
    for (vector<int>::iterator it=v.begin(); it!=v.end(); it++){
        cout << *it << " ";
    }
    cout << endl;
}


void test01(){
    vector<int> v1;
    for (int i=0; i<10; i++){
        v1.push_back(i);
    }
    v1.pop_back();
    printVector(v1);

    // 插入
    v1.insert(v1.begin(), 100);
    printVector(v1);

    v1.insert(v1.begin(), 2,1000);
    printVector(v1);

    // 删除
    v1.erase(v1.begin());
    printVector(v1);

    // v1.erase(v1.begin(), v1.end()); // 类似清空
    v1.clear();
    printVector(v1);
}


int main(){
    test01();
    return 0;
}


