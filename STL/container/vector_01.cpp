// vector 与 数组
// vector 可以动态扩展，而数组是静态空间
// vector 动态扩展：不是在原空间之后续接新空间，而是找更大的内存空间，然后将原数据拷贝新空间，释放原空间

// vector<T> v;                 // 采用模板实现类实现，默认构造函数
// vector(v.begin(), v.end());  // 将 v[begin(), end()] 区间中的元素拷贝给本身
// vector(n, elem);             // 构造函数将 n 个 elem 拷贝给本身
// vector(const vector &vec);   // 拷贝构造函数

#include<iostream>
#include<vector>

using namespace std;

void printVector(vector<int> &v){
    for (vector<int>::iterator it = v.begin(); it!=v.end(); it++){
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

    // 区间
    vector<int> v2(v1.begin(), v1.end());
    printVector(v2);

    // n 个 elem 
    vector<int> v3(10, 100);
    printVector(v3);

    // 拷贝构造
    vector<int> v4(v3);
    printVector(v4);
}


int main(){
    test01();
    return 0;
}