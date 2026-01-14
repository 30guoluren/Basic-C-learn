#include "workerManager.h"

WorkerManager :: WorkerManager(){
    // 文件不存在
    ifstream ifs;
    ifs.open(FILENAME, ios::in);

    if (!ifs.is_open()){
        cout << "文件不存在" << endl;
        this->m_EmpNum = 0;
        this->m_EmpArray = NULL;
        // 初始化文件是否为空
        this->m_FileIsEmpty = true;
        ifs.close();
        return;
    }

    // 文件存在，但是数据为空
    char ch;
    ifs >> ch;
    if (ifs.eof()){
        cout << "文件为空" << endl;
        this->m_EmpNum = 0;
        this->m_EmpArray = NULL;
        // 初始化文件是否为空
        this->m_FileIsEmpty = true;
        ifs.close();
        return;
    }

    // 文件存在，并且记录数据
    int num = this->get_EmpNum();
    // cout << "职工人数为:" << num << endl;
    this->m_EmpNum = num;

    // 开辟空间
    this->m_EmpArray = new Worker*[this->m_EmpNum];
    // 将文件中的数据存到数组中
    this->init_Emp();
}



void WorkerManager :: Show_Menu(){
    cout << "-----------------------" << endl;
    cout << "------欢迎使用本系统-----" << endl;
    cout << endl;
}

void WorkerManager :: ExitSystem(){
    cout << "欢迎下次使用" << endl;
    exit(0);
}

void WorkerManager :: Add_Emp(){
    cout << "请输入添加职工数量" << endl;

    int addNum = 0;
    cin >> addNum;

    if (addNum > 0){
        // 添加
        // 计算添加空间大小
        int newSize = this->m_EmpNum + addNum;

        // 开辟新空间
        Worker ** newSpace = new Worker*[newSize];

        // 将原来空间下的数据，拷贝到新空间下
        if (this->m_EmpArray != NULL){
            for(int i=0; i<this->m_EmpNum; i++){
                newSpace[i] = this->m_EmpArray[i];
            }
        }

        // 添加新数据
        for (int i=0; i<addNum; i++){
            int id;
            string name;
            int dSelect;

            cout << "请输入第" << i+1 << "个新职工编号：" << endl;
            cin >> id;

            cout << "请输入第" << i+1 << "个新职工姓名：" << endl;
            cin >> name;

            cout << "请选择该职工岗位:" << endl;
            cout << "1、普通职工" << endl;
            cout << "2、经理" << endl;
            cout << "3、老板" << endl;
            cin >> dSelect;

            Worker * worker = NULL;
            switch(dSelect){
                case 1:
                    worker = new Employee(id,name,1);
                    break;
                case 2:
                    worker = new Manager(id,name,2);
                    break;
                case 3:
                    worker = new Boss(id,name,3);
            }

            // 将创建的职工指针，保存到数组中
            newSpace[this->m_EmpNum+i] = worker;
        }

        // 释放原有的空间
        delete [] this->m_EmpArray;

        // 更改新空间的指向
        this->m_EmpArray = newSpace;

        // 更新新的职工人数
        this->m_EmpNum = newSize;

        // 更新职工不为空的标志
        this->m_FileIsEmpty = false;

        // 提示添加成功
        cout << "成功添加" << addNum << "名新职工" << endl;

        // 保存数据
        this->save();
    }
    else{
        cout << "输入数据有误" << endl;
    }
}

// 保存文件
void WorkerManager :: save(){
    ofstream ofs;
    ofs.open(FILENAME, ios::out);

    // 将每个人的数据写到文件中
    for (int i=0; i<this->m_EmpNum; i++){
        ofs << this->m_EmpArray[i]->m_Id << " "
        << this->m_EmpArray[i]->m_Name << " "
        << this->m_EmpArray[i]->m_DeptId << endl;
    }
    ofs.close();
}

int WorkerManager :: get_EmpNum(){
    ifstream ifs;
    ifs.open(FILENAME, ios::in);

    int id;
    string name;
    int dId;

    int num = 0;
    while (ifs>>id && ifs>>name && ifs>>dId){
        num++;
    }
    return num;
}

void WorkerManager :: init_Emp(){
    ifstream ifs;
    ifs.open(FILENAME, ios::in);

    int id;
    string name;
    int dId;

    int index = 0;
    while (ifs>>id && ifs>>name && ifs>>dId){
        Worker *worker = NULL;

        if (dId == 1){
            worker = new Employee(id,name,dId);
        }
        else if (dId == 2){
            worker = new Manager(id,name,dId);
        }else{
            worker = new Boss(id,name,dId);
        }
        this->m_EmpArray[index] = worker;
        index ++;
    }

    ifs.close();
    
}

void WorkerManager :: Show_Emp(){
    // 判断文件是否为空
    if (this->m_FileIsEmpty){
        cout << "文件不存在或则记录为空" << endl;
    }
    else{
        for (int i=0; i<this->m_EmpNum; i++){
            this->m_EmpArray[i]->showInfo();
        }
    }
}

void WorkerManager :: Del_Emp(){
    if (this->m_FileIsEmpty){
        cout << "文件不存在" << endl;
    }else {
        cout << "请输入要删除职工的编号" << endl;
        int id = 0;
        cin >> id;

        int index = this->IsExist(id);
        if (index != -1){
            for (int i=index; i<this->m_EmpNum-1; i++){
                this->m_EmpArray[i] = this->m_EmpArray[i+1];
            }
            this->m_EmpNum --;
            // 同步更新到文件中
            this->save();
            cout << "删除成功" << endl;
        }else {
            cout << "删除失败，为找到该职工" << endl;
        }
    }
}

int WorkerManager :: IsExist(int id){
    int index = -1;
    for (int i=0; i<this->m_EmpNum; i++){
        if (this->m_EmpArray[i]->m_Id == id){
            // 找到职工
            index = i;
            break;
        }
    }
    return index;
}

void WorkerManager :: Mod_Emp(){
    if (this->m_FileIsEmpty){
        cout << "文件不存在或记录为空" << endl;
    }
    else {
        cout << "请输入要修改的职工编号" << endl;
        int id;
        cin >> id;
        int ret = this->IsExist(id);
        
        if (ret != -1){
            delete this->m_EmpArray[ret];

            int newId = 0;
            string newName = "";
            int dSelect = 0;

            cout << "查到" << id << "号职工，请输入新的职工号" << endl;
            cin >> newId;
            cout << "请输入新的姓名" << endl;
            cin >> newName;
            cout << "请输入岗位：" << endl;
            cout << "1、普通职工" << endl;
            cout << "2、经理" << endl;
            cout << "3、老板" << endl;
            cin >> dSelect; 

            Worker *worker = NULL;
            switch(dSelect){
                case 1:
                    worker = new Employee(newId,newName,dSelect);
                    break;
                case 2:
                    worker = new Manager(newId,newName,dSelect);
                    break;
                case 3:
                    worker = new Boss(newId,newName,dSelect);
                    break;
                default:
                    break;
            }

            //  更新数据到数组中
            this->m_EmpArray[ret] = worker;
            cout << "修改成功" << endl;
            this->save();

        }else {
            cout << "查无此人" << endl;
        }
    }
}


void WorkerManager :: Find_Emp(){
    if (this->m_FileIsEmpty){
        cout << "文件不存在或记录为空" << endl;
    }
    else {
        cout << "请输入查找的方式" << endl;
        cout << "1、按照职工编号查找" << endl;
        cout << "2、按照职工姓名查找" << endl;

        int select = 0;
        cin >> select;

        if (select == 1){
            int id;
            cout << "请输入查找编号" << endl;
            cin >> id;

            int ret = this->IsExist(id);
            if (ret != -1){
                cout << "查找成功，职工信息如下" << endl;
                this->m_EmpArray[ret]->showInfo();
            }else {
                cout << "查找失败，查无此人" << endl;
            }
        }else if (select == 2) {
            string name;
            cout << "请输入查找的姓名" << endl;
            cin >> name;

            // 默认查找失败
            bool flag = false;
            for (int i=0; i<this->m_EmpNum; i++){
                if (this->m_EmpArray[i]->m_Name == name){
                    cout << "查找成功，职工编号为：" << this->m_EmpArray[i]->m_Id
                    << "职工信息如下" << endl;
                    this->m_EmpArray[i]->showInfo();
                    flag = true;
                    break;
                }
            }
            if (flag == false){
                cout << "查找失败" << endl;
            }
        }
        else {
            cout << "输入有误，清重新输入" << endl;
        }
    }
}

void WorkerManager :: Sort_Emp(){
    if (this->m_FileIsEmpty){
        cout << "文件不存在或记录为空" << endl;
    }else {
        cout << "请选择排序的方式" << endl;
        cout << "1、按照职工号升序" << endl;
        cout << "2、降序" << endl;

        int select = 0;
        cin >> select;
        for (int i=0; i<this->m_EmpNum; i++){
            int minOrMax = i;
            for (int j=i+1; j<this->m_EmpNum; j++){
                if (select == 1){
                    if (this->m_EmpArray[minOrMax]->m_Id > this->m_EmpArray[j]->m_Id){
                        minOrMax = j;
                    }
                }
                else {
                    if (this->m_EmpArray[minOrMax]->m_Id < this->m_EmpArray[j]->m_Id){
                        minOrMax = j;
                    }
                }
            }

            // 判断
            if (minOrMax != i){
                Worker *temp = this->m_EmpArray[i];
                this->m_EmpArray[i] = this->m_EmpArray[minOrMax];
                this->m_EmpArray[minOrMax] = temp;
            }
        }
        cout << "排序成功" << endl;
        this->save();
        this->Show_Emp();
    }
}

void WorkerManager :: Clean_File(){
    cout << "确定清空" << endl;
    cout << "1、确定" << endl;
    cout << "2、返回" << endl;

    int select = 0;
    cin >> select;

    if (select == 1){
        ofstream ofs(FILENAME, ios::trunc); // 删除文件后重新创建
        ofs.close();

        if (this->m_EmpArray != NULL){
            for (int i=0; i<this->m_EmpNum; i++){
                delete this->m_EmpArray[i];
                this->m_EmpArray[i] = NULL;
            }

            // 删除堆区的数组指针
            delete[] this->m_EmpArray;
            this->m_EmpArray = NULL;
            this->m_EmpNum = 0;
            this->m_FileIsEmpty = true;
        }
        cout << "清空成功" << endl;
    }
}

WorkerManager :: ~WorkerManager(){
    if (this->m_EmpArray!=NULL){
        delete [] this->m_EmpArray;
        this->m_EmpArray = NULL;
    }
}