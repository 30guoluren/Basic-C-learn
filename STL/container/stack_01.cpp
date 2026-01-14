// stack

// 构造函数
// stack<T> stk;
// stack(const stack &stk); // 拷贝构造函数

// 赋值操作
// stack& operator=(const stack &stk);

// 数据存取
// push(elem);
// pop();
// top(); // 返回栈顶元素

// 大小操作
// empty();
// size();

#include<iostream>
#include<stack>


using namespace std;

void test01(){
    stack<int> s;

    // 入栈
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);

    // 只要栈不空，就查看栈顶，并出栈
    while(!s.empty()){
        cout << s.top() << endl;
        s.pop();
    }

    cout << "stack size " << s.size() << endl;
}

int main(){
    test01();
    return 0;
}