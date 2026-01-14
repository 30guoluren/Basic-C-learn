// vector 预留空间
// 减少 vector 在动态扩展容量时的扩展次数
// reserve(int len); // 容器预留 len 个元素长度，预留位置不初始化，元素不可访问

#include<iostream>
#include<vector>

using namespace std;

void test01(){
    vector<int> v;

    // 利用 reserve() 预留空间
    v.reserve(100000);

    int num = 0;
    int *p = NULL;

    for (int i=0; i<100000; i++){
        v.push_back(i);
        if (p != &v[0]){
            p = &v[0];
            num ++;
        }
    }
    cout << num << endl;
}


int main(){
    test01();
    return 0;
}