#include "teacher.h"
#include "orderFile.h"
#include <ostream>
#include<vector>

// 默认构造
Teacher :: Teacher(){

}

// 有参构造
Teacher :: Teacher(int empId, string name, string pwd){
    this->m_EmpId = empId;
    this->m_Name = name;
    this->m_Pwd = pwd;
}

// 菜单界面
void Teacher :: operMenu(){
    cout << "欢迎教师" << this->m_Name << "登陆" << endl;
    cout << "----------" << endl;
    cout << "1、查看所有的预约" << endl;
    cout << "2、审核预约" << endl;
    cout << "0、注销登录" << endl;
    cout << "请选择您的操作" << endl;
}

// 查看所有预约
void Teacher :: showAllOrder(){
    OrderFile of;
    
    if (of.m_Size == 0){
        cout << "无预约记录" << endl;
        return;
    }

    for (int i=0; i<of.m_Size; i++){
        cout << i+1 << "、 ";
        cout << "预约的日期： 周" << of.m_orderData[i]["date"];
        cout << " 时间段" << (of.m_orderData[i]["interval"] == "1" ? "上午" : "下午");
        cout << " 学号" << of.m_orderData[i]["stuId"];
        cout << " 姓名" << of.m_orderData[i]["stuName"];
        cout << "机房编号" << of.m_orderData[i]["roodId"];
        string status = "状态";
        if (of.m_orderData[i]["status"] == "1"){
            status += "审核中";
        }else if (of.m_orderData[i]["status"] == "2"){
            status += "审核成功";
        }else if (of.m_orderData[i]["status"] == "-1"){
            status += "预约失败";
        }else if (of.m_orderData[i]["status"] == "0"){
            status += "取消预约";
        }
        cout << status << endl;
    }
}

// 审核预约
void Teacher :: validOrder(){
    OrderFile of;
    if (of.m_Size == 0){
        cout << "无预约记录" << endl;
        return;
    }

    vector<int> v;
    int index = 0;
    cout << "代审核的预约记录如下" << endl;

    for (int i=0; i<of.m_Size; i++){
        if (of.m_orderData[i]["status"] == "1"){
            v.push_back(i);
            cout << ++index << "、 ";
            cout << "预约日期: 周" << of.m_orderData[i]["date"];
            cout << "时间段" << (of.m_orderData[i]["interval"] == "1" ? "上午" : "下午");
            cout << " 学号" << of.m_orderData[i]["stuId"];
            cout << " 姓名" << of.m_orderData[i]["stuName"];   
            cout << "机房编号" << of.m_orderData[i]["roodId"];
            string status = "状态，审核中";
            cout << status << endl;
        }
    }
    cout << "请输入审核的预约记录, 0代表返回" << endl;
    int select = 0;
    int ret = 0;

    while (true){
        cin >> select;
        if (select >= 0&& select <= v.size()){
            if (select == 0){
                break;
            }else {
                cout << "请输入审核的结果" << endl;
                cout << "1、代表通过" << endl;
                cout << "2、代表不通过" << endl;
                cin >> ret;
                if (ret == 1){
                    of.m_orderData[v[select-1]]["status"] = "2";
                }else {
                    of.m_orderData[v[select-1]]["status"] = "-1";
                }
                of.updateOrder();
                cout << "审核完毕" << endl;
                break;
            }
        }else {
            cout << "输入有误，请重新输入" << endl;
        }
    }
}