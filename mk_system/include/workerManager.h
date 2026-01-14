#pragma once
#include<iostream>
#include "worker.h"
#include "employee.h"
#include "manager.h"
#include "boss.h"

#include<fstream>
#define FILENAME "expFile.txt"
using namespace std;

class WorkerManager{
    public:

    WorkerManager();

    void Show_Menu();

    void ExitSystem();

    // 记录职工人数
    int m_EmpNum;

    // 职工数组指针
    Worker ** m_EmpArray;

    //添加职工
    void Add_Emp();

    // 保存文件
    void save();

    // 判断文件是否为空
    bool m_FileIsEmpty;

    // 统计文件中的人数
    int get_EmpNum();

    // 初始化员工
    void init_Emp();

    // 显示员工
    void Show_Emp();

    // 判断职工是否存在
    int IsExist(int id);

    // 删除职工
    void Del_Emp();

    // 修改职工
    void Mod_Emp();

    // 查找职工
    void Find_Emp();

    // 排序
    void Sort_Emp();

    // 清空
    void Clean_File();

    ~WorkerManager();
};