#include <cstdlib>
#include<iostream>

using namespace std;

int main(){

    int select = 0;

    while (true){

        cout << "欢迎使用机房预约系统" << endl;
        cout << "----------------" << endl;
        cout << "请输入您的身份" << endl;
        cout << "\t 1、学生代表" << endl;
        cout << "\t 2、老师" << endl;
        cout << "\t 3、系统管理员" << endl;
        cout << "\t 0、退出" << endl;
        cout << "请输入您的选择" << endl;

        cin >> select;

        switch (select) {
        case 0: // 退出系统
            cout << "欢迎下一次使用" << endl;
            return 0;
            break;
        case 1: // 学生身份
            break;
        case 2: // 老师身份
            break;
        case 3: // 管理员身份
            break;
        default: // 输入有误，请从新选择
            cout << "输入有误，清重新选择" << endl;
            system("clear");
            break;
        }
    }

    
    return 0;
}