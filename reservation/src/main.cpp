#include "Identity.h"
#include <cstddef>
#include <cstdlib>
#include <fstream>
#include<iostream>
#include "globalFile.h"
#include "manager.h"
#include "path_utils.h"
#include "student.h"
#include "teacher.h"

using namespace std;

// 进入学生的子菜单界面
void studentMenu(Identity * &student){
    while (true){
        // 调用学生子菜单
        student->operMenu();

        // 转换为学生指针
        Student * stu = (Student *)student;

        int select = 0;
        cin >> select;

        if (select == 1){
            // 申请预约
            stu->applyOrder();
        }else if (select == 2){
            // 查看自身的预约
            stu->showMyOrder();
        }else if (select == 3){
            // 查看所有人的预约
            stu->showAllOrder();
        }else if (select == 4){
            // 取消预约
            stu->cancelOrder();
        }else if(select == 0){
            // 注销登陆
            delete student;
            cout << "注销成功" << endl;
            return;
        }
    }
}

// 进入教师子菜单管理界面
void teacherMenu(Identity * &teacher){
    while (true){
        // 调用子菜单的界面
        teacher->operMenu();

        Teacher * tea = (Teacher *)teacher;

        int select = 0;
        cin >> select;
        if (select == 1){
            tea->showAllOrder();
        }else if (select == 2){
            tea->validOrder();
        }else if (select == 0){
            delete teacher;
            cout << "注销成功" << endl;
            return;
        }
    }
}


// 进入管理员的子菜单界面
void managerMenu(Identity * &manager){
    while (true){
        // 调用管理员子菜单、
        // 多态，通过父类的指针调用子类的方法
        manager->operMenu();

        // 将父类的指针转为子类的指针，调用子类中其他特有的接口
        Manager * man = (Manager*)manager;
        
        int select = 0;
        cin >> select;

        if (select == 1){
            // cout << "添加账号" << endl;
            man->addPerson();
        }else if (select == 2){
            // cout << "查看账号" << endl;
            man->showPerson();
        }else if (select == 3){
            // cout << "查看机房" << endl;
            man->showComputer();
        }else if (select == 4){
            // cout << "清空记录" << endl;
            man->cleanFile();
        }else if (select == 0){
            delete manager;
            cout << "注销成功" << endl;
            return;
        }

    }
}


// 登录功能
// fileName 操作文件名, type 操作身份类型
void LoginIn(string fileName, int type){

    // 父类指针，用来指向子类对象
    Identity * person = NULL;

    // 度文件
    ifstream ifs;
    ifs.open(fileName, ios::in);

    if (!ifs.is_open()){
        cout << "文件不存在" << endl;
        ifs.close();
        return;
    }

    // 准备接受用户的信息
    int id = 0;
    string name;
    string pwd;

    // 判断身份
    if (type == 1){
        // 学生身份
        cout << "请输入您的学号" << endl;
        cin >> id;
    }
    else if (type == 2){
        cout << "请输入您的职工号" << endl;
        cin >> id;
    }
    cout << "请输入用户名: " << endl;
    cin >> name;

    cout << "请输入密码: " << endl;
    cin >> pwd;

    if (type == 1){
        // 学生身份验证
        int fId;
        string fName;
        string fPwd;
        while (ifs >> fId && ifs >> fName && ifs >> fPwd){
            // cout << fId << "\t" << fName << "\t" << fPwd << endl;
            if (fId == id && fName == name && fPwd == pwd){
                cout << "学生的验证登陆成功" << endl;

                person = new Student(id, name, pwd);
                // 进入到学生的子菜单
                studentMenu(person);

                return;
            }
        }
    }
    else if (type == 2){
        // 教师身份验证
        int fId;
        string fName;
        string fPwd;

        while (ifs >> fId && ifs >> fName && ifs >> fPwd){
            if (fId==id && fName==name && fPwd==pwd){
                cout << "教师验证登陆成功" << endl;

                person = new Teacher(id, name, pwd);
                // 进入教师的子菜单
                teacherMenu(person);

                return;
            }
        }
    }
    else if (type == 3){
        // 管理员身份验证
        string fName;
        string fPwd;

        while (ifs >> fName && ifs >> fPwd){
            if (fName==name && fPwd==pwd){
                cout << "管理员验证登陆成功" << endl;

                person = new Manager(name, pwd);
                // 进入管理员子菜单
                managerMenu(person);

                return;
            }
        }
    }
    cout << "验证登陆失败" << endl;
    // system("clear");
    return;

}


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
            LoginIn(project_path(STUDENT_FILE), 1);
            break;
        case 2: // 老师身份
        LoginIn(project_path(TEACHER_FILE), 2);
            break;
        case 3: // 管理员身份
            LoginIn(project_path(ADMIN_FILE), 3);
            break;
        default: // 输入有误，请从新选择
            cout << "输入有误，清重新选择" << endl;
            system("clear");
            break;
        }
    }

    
    return 0;
}