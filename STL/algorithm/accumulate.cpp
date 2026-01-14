// 常用的算术生成算法，使用时包含头文件 #include<numeric>

// accumulate 计算容器元素累计总和
// fill 向容器中添加元素

#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>

// accumulate(iterator_beg, iterator_end, value);
// value 起始的累加值

using namespace std;

void test01(){
    vector<int> v;
    for (int i=0; i<=100; i++){
        v.push_back(i);
    }

    int res = accumulate(v.begin(), v.end(), 0);
    cout << "accumulate is : " << res << endl;

}

int main(){
    test01();
    return 0;
}