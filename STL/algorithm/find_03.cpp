// adjacent_find(iterator_beg, iterator_end);
// 查找相邻的重复元素，返回相邻元素的第一个位置的迭代器，失败返回 end

#include<iostream>
#include<vector>
#include<algorithm>


using namespace std;

void test01(){
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(1);
    v.push_back(1);
    v.push_back(1);

    vector<int>::iterator pos = adjacent_find(v.begin(), v.end());
    if (pos == v.end()){
        cout << "not find" << endl;
    }else {
        cout << "success find " << *pos << endl;
    }

}

int main(){
    test01();
    return 0;
}