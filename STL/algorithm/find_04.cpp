// binary_search
// 查找指定元素是否存在

// bool binary_search(iterator_beg, iterator_end, value);
// 查找成功返回 true；失败返回 false
// 注意：在无序序列中不可使用

#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

void test01(){
    vector<int> v;
    for (int i=0; i<10; i++){
        v.push_back(i);
    }

    bool res = binary_search(v.begin(), v.end(), 3);
    if (res){
        cout << "success" << endl;
    }else {
        cout << "not find" << endl;
    }
}

int main(){
    test01();
    return 0;
}