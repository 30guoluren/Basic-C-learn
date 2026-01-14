// 谓词

// 概念：
// - 返回 bool 类型的仿函数称为谓词
// - 如果 operator() 接受一个参数，那么叫做一元谓词
// - 如果 operator() 接受俩个参数，叫做二元谓词

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class GreaterFive{
    public:
    bool operator()(int val){
        return val > 5;
    }
};

void test01(){
    vector<int> v;
    for (int i=0; i<10; i++){
        v.push_back(i);
    }

    // 查找容器中，有没有大于 5 的数字
    // GreaterFive() // 匿名函数对象
    vector<int>::iterator it = find_if(v.begin(), v.end(), GreaterFive());
    if (it == v.end()){
        cout << "not found" << endl;
    }else {
        cout << "success found: " << *it << endl;
    }
}

int main(){
    test01();
    return 0;
}