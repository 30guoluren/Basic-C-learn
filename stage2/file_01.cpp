// C++ 对文件的操作需要包含头文件 <fstream>

// 文件类型分为两种：
// - 文本文件：文件以文本的 ASCII 码形式存储在计算机中
// - 二进制文件：文件以文本的 二进制 形式存储在计算机中，用户一般不能直接读他们

// 操作文件的三大类
// ofstream ：写操作
// ifstream ：读操作
// fstream ：读写操作

// 文件的打开方式
// ios::in      为读文件而打开文件
// ios::out     为写文件而打开文件
// ios::ate     初始位置：文件尾
// ios::app     追加方式写文件
// ios::trunc   如果文件存在先删除，再创建
// ios::binary  二进制方式

// 注：文件打开方式可以配合使用，使用 | 操作符
// 例如，用二进制方式写文件：ios::binary | ios::out

#include<iostream>
#include<vector>
#include<string>
#include<fstream>

using namespace std;

void test01(){
    // 1、包含头文件

    // 2、创建流对象
    ofstream ofs;

    // 3、指定打开方式
    ofs.open("text.txt",ios::out);

    // 4、写内容
    ofs << "姓名：张三" << endl;
    ofs << "性别：男" << endl;

    // 5、关闭文件
    ofs.close();
}


int main(){
    system("chcp 65001");
    test01();
    return 0;
}