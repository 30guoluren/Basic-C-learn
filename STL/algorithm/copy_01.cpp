// 常见的拷贝和替换算法

// copy() 容器内指定范围的元素拷贝到另一容器中
// replace() 将容器内指定范围的旧元素修改为新元素
// replace_if() 容器内指定范围满足条件的元素替换为新元素
// swap() 互换两个容器的元素


// copy(iterator_beg, iterator_end, iterator_dest);

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

void print01(int val){
    cout << val << " ";
}

void test01(){
    vector<int> v1;
    for (int i=0; i<10; i++){
        v1.push_back(i);
    }

    vector<int> v2;
    v2.resize(v1.size());

    copy(v1.begin(), v1.end(), v2.begin());

    for_each(v2.begin(), v2.end(), print01);
    cout << endl;
}

int main(){
    test01();
    return 0;
}