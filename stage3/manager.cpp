#include "manager.h"
#include <string>

Manager :: Manager(int id, string name, int dId){
    this->m_Id = id;
    this->m_Name = name;
    this->m_DeptId = dId;
};

void Manager :: showInfo(){
    cout << "职工姓名: " << this->m_Name << "\t职工编号: " << this->m_Id << "\t部门编号: " << this->getDeptName()
    << "\t岗位职责: 完成老板交代的任务, 并下发给员工任务" << endl;
}

string Manager :: getDeptName(){
    return string("经理");
}