// case:
// 实现俩个操作数进行运算的计算器类

// 多态的优点：
// - 代码组织结构清晰
// - 可读性强
// - 利于前期和后期的扩展以及维护

#include <cstddef>
#include<iostream>
#include<vector>
#include<string>

using namespace std;

class Calculator{
public:

    int getResult(string oper){
        if (oper == "+"){
            return m_Num1 + m_Num2;
        }
        else if (oper == "-"){
            return m_Num1 - m_Num2;
        }else if (oper == "*"){
            return m_Num1 * m_Num2;
        }else if (oper == "/"){
            return m_Num1 / m_Num2;
        }
        return 0;
    }
    
    int m_Num1;
    int m_Num2;
};

void test01(){
    // 创建一个计算器对象
    Calculator c;
    c.m_Num1 = 10;
    c.m_Num2 = 29;

    cout << c.m_Num1 << "+" << c.m_Num2 << "=" << c.getResult("+") << endl;

    cout << c.m_Num1 << "-" << c.m_Num2 << "=" << c.getResult("-") << endl;

}


// 利用多态实现计算器

// 实现计算器的基类/抽象类
class AbstractCalculator{
    public:

    virtual int getResult(){
        return 0;
    }

    int m_Num1;
    int m_Num2;
};

// 加法计算器类
class AddCalculator : public AbstractCalculator{
    public:

    int getResult(){
        return m_Num1 + m_Num2;
    }
};

// 假发计算器类
class SubCalculator : public AbstractCalculator{
    public:

    int getResult(){
        return m_Num1 - m_Num2;
    }
};

// 乘法计算器类
class MulCalculator : public AbstractCalculator{
    public:

    int getResult(){
        return m_Num1 * m_Num2;
    }
};


void test02(){
    // 多态的使用条件
    // 父类的指针 或 引用 指向子类的对象

    // 加法
    AbstractCalculator * abc = new AddCalculator;
    abc->m_Num1 = 29;
    abc->m_Num2 = 38;

    cout << abc->m_Num1 << "+" << abc->m_Num2 << "=" << abc->getResult() << endl;

    // 用完后，销毁
    delete abc;

    // 减法运算
    abc = new SubCalculator;
    abc->m_Num1 = 100;
    abc->m_Num2 = 100;

    cout << abc->m_Num1 << "-" << abc->m_Num2 << "=" << abc->getResult() << endl;
    delete abc;
}


int main(){
    system("chcp 65001");
    // test01();
    test02();
    return 0;
}