#include <cstddef>
#include <iostream>
#include "workermanager.h"
// #include "worker.h"
// #include "employee.h"
// #include "manager.h"
// #include "boss.h"

using namespace std;

int main() {
    system("chcp 65001 >nul");

    // // 测试
    // Worker * worker = NULL;
    // worker = new Employee(12,"张三",1222);
    // worker->showInfo();
    // delete worker;

    // worker = new Manager(13, "经理", 122202);
    // worker->showInfo();
    // delete worker;

    // worker = new Boss(13, "老板", 1222002);
    // worker->showInfo();
    // delete worker;

    // 实例化一个管理者对象
    WorkerManager wm;

    int choice = 0;

    while (true) {
        wm.Show_Menu();

        cout << "请输入您的选着" << endl;
        cin >> choice;

        switch (choice) {
            case 0:  // 退出系统
                wm.ExitSystem();
                break;
            case 1:  // 添加职工
                break;
            case 2:  // 显示职工
                break;
            case 3:  // 删除职工
                break;
            case 4:  // 修改职工
                break;
            case 5:  // 查找职工
                break;
            case 6:  // 排序
                break;
            case 7:  // 清空文档
                break;
            default:
                system("cls");
                break;
        }
    }

    // 调用成员函数

    system("pause");
    return 0;
}
