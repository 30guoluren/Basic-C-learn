#include "manager.h"
#include <fstream>
#include <iostream>
#include "computerRoom.h"
#include "globalFile.h"
#include "path_utils.h"
#include "student.h"
#include "teacher.h"
#include<algorithm>

// 默认构造
Manager :: Manager(){

}

// 有参构造
Manager :: Manager(string name, string pwd){
    this->m_Name = name;
    this->m_Pwd = pwd;

    this->initVector();

    // 初始化机房的信息
    ifstream ifs;
    ifs.open(project_path(COMPUTER_FILE), ios::in);
    ComputerRoom com;
    while (ifs >> com.m_ComId && ifs >> com.m_MaxNum){
        vCom.push_back(com);
    }
    ifs.close();
    cout << "机房的数量为多少" <<  vCom.size() << endl;

}

// 菜单界面
void Manager :: operMenu(){
    cout << "欢迎" << this->m_Name << "登陆" << endl;
    cout << "-------------" << endl;
    cout << "1、添加账号" << endl;
    cout << "2、查看账号" << endl;
    cout << "3、查看机房" << endl;
    cout << "4、清空预约" << endl;
    cout << "0、注销登陆" << endl;
    cout << "请选择您的操作" << endl;
}

// 添加账号
void Manager :: addPerson(){
    cout << "请输入添加账号的类型" << endl;
    cout << "1、添加学生" << endl;
    cout << "2、添加老师" << endl;

    string fileName;
    string tip;
    string errorTip;

    ofstream ofs;

    int select = 0;
    cin >> select;

    if (select == 1){
        // 添加学生
        fileName = STUDENT_FILE;
        tip = "请输入学号";
        errorTip = "学号错误，请重新输入";
    }else {
        fileName = TEACHER_FILE;
        tip = "请输入教师号";
        errorTip = "教师号错误，请重新输入";
    }

    ofs.open(project_path(fileName), ios::out | ios::app);
    
    int id;
    string name;
    string pwd;

    cout << tip << endl;
    while (true){
        cin >> id;
        bool ret = checkRepeat(id, select);
        if (ret){
            cout << errorTip << endl;
        }
        else {
            break;
        }
    }


    cout << "姓名" << endl;
    cin >> name;

    cout << "请输入密码" << endl;
    cin >> pwd;

    // 向文件中添加数据
    ofs << id << " " << name << " " << pwd << " " << endl;
    cout << "添加成功" << endl;

    ofs.close();

    // 初始化容器的接口，获取容器中的数据
    this->initVector();
}


// 查看账号
void printStu(Student & s){
    cout << "学号: " << s.m_Sid << "姓名: " << s.m_Name << "学号: " << s.m_Pwd << endl;
}

void printTea(Teacher & t){
    cout << "教师号: " << t.m_EmpId << "姓名: " << t.m_Name << "教师密码: " << t.m_Pwd << endl;
}

void Manager :: showPerson(){
    cout << "请选择查看的内容" << endl;
    cout << "1、查看所有的学生" << endl;
    cout << "2、查看所有的老师" << endl;

    int select = 0;
    cin >> select;

    if (select == 1){
        cout << "所有的学生信息如下" << endl;
        for_each(vStu.begin(), vStu.end(),printStu);
    }
    else if (select == 2){
        cout << "所有的教师信息如下" << endl;
        for_each(vTea.begin(), vTea.end(), printTea);
    }
}

// 查看机房信息
void Manager :: showComputer(){
    cout << "机房的信息如下" << endl;
    for(vector<ComputerRoom>::iterator it=vCom.begin(); it!=vCom.end(); it++){
        cout << "机房id: " << it->m_ComId << "\t机房容量: " << it->m_MaxNum << endl;
    }
}

// 清空预约记录
void Manager :: cleanFile(){
    ofstream ofs(project_path(ORDER_FILE), ios::trunc); // trunc 打开文件，文件存在则删除重新创建
    ofs.close();
    
    cout << "文件清空完成" << endl;
}

// 初始化容器
void Manager :: initVector(){

    // 确保文件是清空的状态
    vStu.clear();
    vTea.clear();

    // 读取信息
    ifstream ifs;
    ifs.open(project_path(STUDENT_FILE), ios::in);

    if (!ifs.is_open()){
        cout << "文件打开失败" << endl;
        return;
    }

    Student s;
    while (ifs >> s.m_Sid && ifs >> s.m_Name && ifs >> s.m_Pwd){
        vStu.push_back(s);
    }
    cout << "当前的学生数量为: " << vStu.size() << endl;
    ifs.close();

    ifs.open(project_path(TEACHER_FILE), ios::in);
    if (!ifs.is_open()){
        cout << "文件打开失败" << endl;
        return;
    }
    Teacher t;
    while (ifs >> t.m_EmpId && ifs >> m_Name && ifs >> m_Pwd){
        vTea.push_back(t);
    }
    cout << "当前教师的数量为: " << vTea.size() << endl;
    ifs.close();

}

bool Manager :: checkRepeat(int id, int type){
    if (type == 1){
        // 检测学生
        for (vector<Student>::iterator it=vStu.begin(); it!=vStu.end(); it++){
            if (id == it->m_Sid){
                return true;
            }
        }
    }else {
        // 检测老师
        for (vector<Teacher>::iterator it=vTea.begin(); it!=vTea.end(); it++){
            if (id == it->m_EmpId){
                return true;
            }
        }
    }
}