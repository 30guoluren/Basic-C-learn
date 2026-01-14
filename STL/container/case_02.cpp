// 员工分组

#include <cstdlib>
#include <iostream>
#include <string>
#include <utility>
#include <vector>
#include <map>

#define CEHUA 0
#define MEISHU 1
#define YANFA 2

using namespace std;

class Worker {
public:
    string m_Name;
    int    m_Salary;
};

void createWorker(vector<Worker> &v) {
    string nameSeed = "ABCDEFGHIJ";
    for (int i = 0; i < 10; i++) {
        Worker worker;
        worker.m_Name = "员工";
        worker.m_Name += nameSeed[i];

        worker.m_Salary = rand() % 10000 + 10000;
        v.push_back(worker);
    }
}

void setGroup(vector<Worker> &v, multimap<int, Worker> &m) {
    for (vector<Worker>::iterator it = v.begin(); it != v.end(); it++) {
        // 产生随即部门编号
        int depId = rand() % 3;

        // 将员工插入到分组中
        // key 代表部门编号，
        m.insert(make_pair(depId, *it));
    }
}

void showWorkerByGroup(multimap<int, Worker> &m) {
    cout << "策划部门信息: " << endl;
    int                             count = m.count(CEHUA);
    multimap<int, Worker>::iterator pos   = m.find(CEHUA);
    int                             index = 0;
    for (; pos != m.end() && index < count; pos++, index++) {
        cout << "姓名: " << pos->second.m_Name << " 工资: " << pos->second.m_Salary << endl;
    }

    cout << "美术部门信息: " << endl;
    pos   = m.find(MEISHU);
    count = m.count(MEISHU);
    index = 0;
    for (; pos != m.end() && index < count; pos++, index++) {
        cout << "姓名: " << pos->second.m_Name << " 工资: " << pos->second.m_Salary << endl;
    }

    cout << "研发部门信息: " << endl;
    pos   = m.find(YANFA);
    count = m.count(YANFA);
    index = 0;
    for (; pos != m.end() && index < count; pos++, index++) {
        cout << "姓名: " << pos->second.m_Name << " 工资: " << pos->second.m_Salary << endl;
    }
}

int main() {
    srand((unsigned int)time(NULL));

    // 创建员工
    vector<Worker> vWorker;
    createWorker(vWorker);

    // for (vector<Worker>::iterator it=vWorker.begin(); it!=vWorker.end(); it++){
    //   cout << (*it).m_Name << it->m_Salary << endl;
    // }

    // 2、员工分组
    multimap<int, Worker> mWorker;
    setGroup(vWorker, mWorker);

    // 分部门显示员工
    showWorkerByGroup(mWorker);

    return 0;
}