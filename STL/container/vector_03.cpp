// vector 容量和大小

// empty();                     // 判断是否为空
// capacity();                  // 容器的容量
// size();                      // 返回容器中元素的个数
// resize(int num);             // 重新指定容器的长度为 num
// ，若容器变长，则以默认值填充新位置
// 如果容器变短，则末尾超出容器的长度的元素将被删除
// resize(int num, elem);       // 重新指定容器的长度为 num ，若容器变长，则以
// elem 填充新位置 如果容器变短，则末尾超出容器的长度的元素将被删除

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
    printVector(v1);

    if (!v1.empty()){
        cout << "v1 is empty" << endl;
        cout << "v1 capacity is: " << v1.capacity() << endl;
        cout << "v1 size is: " << v1.size() << endl;
    }else {
        cout << "v1 is not empty" << endl;
    }

    // 重新指定大小
    v1.resize(15, 119);
    printVector(v1);

    v1.resize(1);
    printVector(v1);
}


int main(){
    test01();
    return 0;
}
