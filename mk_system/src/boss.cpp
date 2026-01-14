#include "boss.h"

Boss :: Boss(int id, string name, int dId){
    this->m_Id = id;
    this->m_Name = name;
    this->m_DeptId = dId;
}

void Boss :: showInfo(){
    cout << this->getDeptName() << endl;
}

string Boss :: getDeptName(){
    return string("老板");
}