#include <cstdlib>
#include <iostream>
#include <ostream>
#include <regex>
#include <string>
using namespace std;

#define Max 1000

struct Person {
    string m_Name;
    int    m_Sex;
    int    m_Age;
    string m_Phone;
    string m_Addr;
};

struct Addressbooks {
    struct Person personArray[Max];
    int           m_Size = 0;
};

void addPerson(Addressbooks* abs) {
    if (abs->m_Size == Max) {
        cout << "无法添加，通讯录已满。" << endl;
        return;
    } else {
        // 姓名
        string name;
        cout << "请输入姓名。" << endl;
        cin >> name;
        abs->personArray[abs->m_Size].m_Name = name;

        // 性别
        int sex = 0;
        cout << "请输入性别" << endl;
        cout << "1:男；2:女" << endl;

        while (true) {
            cin >> sex;
            if (sex == 1 || sex == 2) {
                abs->personArray[abs->m_Size].m_Sex = sex;
                break;
            }
            cout << "输入有误，请重新输入" << endl;
        }

        // 年龄
        cout << "请输入年龄" << endl;
        int age;

        while (true) {
            cin >> age;
            if (age >= 0 && age <= 150) {
                abs->personArray[abs->m_Size].m_Age = age;
                break;
            }
            cout << "输入年龄有误，请重新输入。" << endl;
        }

        // 电话
        cout << "请输入联系电话" << endl;
        string phone;
        cin >> phone;
        abs->personArray[abs->m_Size].m_Phone = phone;

        // 地址
        cout << "请输入家庭住址" << endl;
        string addr;
        cin >> addr;
        abs->personArray[abs->m_Size].m_Addr = addr;

        abs->m_Size++;

        cout << "添加成功" << endl;
    }
    system("pause");
    system("cls");
}

// 显示联系人
void showPerson(Addressbooks* abs) {
    // 判断为0，记录为空；不为0，显示信息
    if (abs->m_Size == 0) {
        cout << "当前记录为空" << endl;
    } else {
        for (int i = 0; i < abs->m_Size; i++) {
            cout << "姓名：" << abs->personArray[i].m_Name << "\t";
            cout << "性别：" << (abs->personArray[i].m_Sex == 1 ? "男" : "女") << "\t";
            cout << "年龄：" << abs->personArray[i].m_Age << "\t";
            cout << "电话：" << abs->personArray[i].m_Phone << "\t";
            cout << "地址：" << abs->personArray[i].m_Addr << "\t";
        }
    }
    system("pause");
    system("cls");
}

int isExist(Addressbooks* abs, string name) {
    for (int i = 0; i < abs->m_Size; i++) {
        if (abs->personArray[i].m_Name == name) {
            return i;
        }
    }
    return -1;
}

// 删除指定联系人
void deletePerson(Addressbooks* abs) {
    cout << "请输入要删除的联系人：" << endl;
    string name;
    cin >> name;
    int ret = isExist(abs, name);
    if (ret == -1) {
        cout << "未查到：" << endl;
    } else {
        for (int i = ret; i < abs->m_Size; i++) {
            abs->personArray[i] = abs->personArray[i + 1];
        }
        abs->m_Size--;
        cout << "删除成功：" << endl;
    }
    system("pause");
    system("cls");
}

// 查找指定的联系人信息
void findPerson(Addressbooks* abs) {
    cout << "请输入您要查找的联系人：" << endl;
    string name;
    cin >> name;
    int ret = isExist(abs, name);
    if (ret == -1) {
        cout << "查无此人：" << endl;
    } else {
        cout << "姓名：" << abs->personArray[ret].m_Name << "\t";
        cout << "性别：" << (abs->personArray[ret].m_Sex == 1 ? "男" : "女") << "\t";
        cout << "年龄：" << abs->personArray[ret].m_Age << "\t";
        cout << "电话：" << abs->personArray[ret].m_Phone << "\t";
        cout << "地址：" << abs->personArray[ret].m_Addr << "\t";
    }
    system("pause");
    system("cls");
}

// 修改指定的联系人信息
void modifyPerson(Addressbooks* abs) {
    cout << "请输入您要修改的联系人信息：" << endl;
    string name;
    cin >> name;

    int ret = isExist(abs, name);

    if (ret == -1) {
        cout << "查无此人" << endl;
    } else {
        string name;
        cout << "请输入姓名" << endl;
        cin >> name;
        abs->personArray[ret].m_Name = name;

        int sex = 0;
        cout << "请输入性别：" << endl;
        cout << "1: 男； 2: 女" << endl;

        while (true) {
            cin >> sex;
            if (sex == 1 || sex == 2) {
                abs->personArray[ret].m_Sex = sex;
                break;
            } else {
                cout << "请从新输入：" << endl;
            }
        }

        cout << "请输入年龄：" << endl;
        int age;
        cin >> age;
        abs->personArray[ret].m_Age = age;

        cout << "请输入联系电话" << endl;
        string phone;
        cin >> phone;
        abs->personArray[ret].m_Phone = phone;

        cout << "请输入家庭住址：" << endl;
        string addr;
        cin >> addr;
        abs->personArray[ret].m_Addr = addr;

        cout << "修改成功 " << endl;
    }
    system("pause");
    system("cls");
}

void clearPerson(Addressbooks* abs) {
    abs->m_Size = 0;
    cout << "通讯录清空成功：" << endl;
    system("pause");
    system("cls");
}

void showMenu() {
    cout << "1、添加联系人" << endl;
    cout << "2、显示联系人" << endl;
    cout << "3、删除联系人" << endl;
    cout << "4、查找联系人" << endl;
    cout << "5、修改联系人" << endl;
    cout << "6、清空联系人" << endl;
    cout << "0、推出通讯录" << endl;
}

int main() {
    struct Addressbooks abs;
    abs.m_Size = 0;

    int select = 0;
    while (true) {
        showMenu();

        cin >> select;

        switch (select) {
            case 1:
                addPerson(&abs);  // 利用地址传递
                break;
            case 2:
                showPerson(&abs);
                break;
            case 3:
                // {
                //     cout << "请输入删除联系人的姓名：" << endl;
                //     string name;
                //     cin >> name;

                //     if (isExist(&abs, name)==-1){
                //         cout << "查无此人" << endl;
                //     }else{
                //         cout << "找到此人" << endl;
                //     }
                //     break;
                // }
                deletePerson(&abs);
                break;
            case 4:
                findPerson(&abs);
                break;
            case 5:
                modifyPerson(&abs);
                break;
            case 6:
                clearPerson(&abs);
                break;
            case 0:
                cout << "欢迎下次使用" << endl;
                return 0;
                break;
            default:
                break;
        }
    }

    return 0;
}