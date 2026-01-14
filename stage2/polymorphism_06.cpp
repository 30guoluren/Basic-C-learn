// case: 电脑组装

#include<iostream>
#include<vector>
#include<string>

using namespace std;

class CPU{
    public:

    virtual ~CPU() = 0;

    virtual void calculate() = 0;
};

class VideoCard{
    public:

    virtual ~VideoCard() = 0;

    virtual void display() = 0;
};

class Memory{
    public:

    virtual ~Memory() = 0;

    virtual void storage() = 0;
};

CPU :: ~CPU(){
    cout << "CPU 纯虚析构函数" << endl;
}

VideoCard :: ~VideoCard(){
    cout << "VideoCard 纯虚析构函数" << endl;
}

Memory :: ~Memory(){
    cout << "Memory 纯虚析构函数" << endl;
}


// 电脑类
class Computer{
    public:

    Computer(CPU *cpu, VideoCard *vc, Memory *mem){
        m_cpu = cpu;
        m_vc = vc;
        m_mem = mem;
    }

    void work(){
        m_cpu->calculate();
        m_vc->display();
        m_mem->storage();
    }

    // 提供析构函数，来释放电脑的零件
    ~Computer(){
        if (m_cpu != NULL){
            delete m_cpu;
            m_cpu = NULL;
        }

        if (m_vc != NULL){
            delete m_vc;
            m_vc = NULL;
        }

        if (m_mem != NULL){
            delete m_mem;
            m_mem = NULL;
        }
    }

    private:

    CPU * m_cpu;
    VideoCard * m_vc;
    Memory * m_mem;
};


// 具体厂商
// Inter
class InterCPU : public CPU{
    public:

    virtual void calculate(){
        cout << "Inter 的 CPU 计算" << endl;
    }
};

class InterVideoCard : public VideoCard{
    public:

    virtual void display(){
        cout << "Inter 的 VideoCard 显示" << endl;
    }
};

class InterMemory : public Memory{
    public:

    virtual void storage(){
        cout << "Inter 的 Memory 存储" << endl;
    }
};


// Lenovo 厂商

class LenovoCPU : public CPU{
    public:

    virtual void calculate(){
        cout << "Lenovo 的 CPU 计算" << endl;
    }
};

class LenovoVideoCard : public VideoCard{
    public:

    virtual void display(){
        cout << "Lenovo 的 VideoCard 显示" << endl;
    }
};

class LenovoMemory : public Memory{
    public:

    virtual void storage(){
        cout << "Lenovo 的 Memory 存储" << endl;
    }
};


void test01(){
    // 第一台电脑零件
    CPU * interCpu = new InterCPU;
    VideoCard * interCard = new InterVideoCard;
    Memory * interMem = new InterMemory;

    // 创建第一台电脑
    Computer * computer1 = new Computer(interCpu,interCard, interMem);
    computer1->work();
    delete computer1;

    // 创建第二台电脑
    Computer *computer2 = new Computer(new LenovoCPU, new LenovoVideoCard, new LenovoMemory);
    computer2->work();
    delete computer2;
}

int main(){
    system("chcp 65001");
    test01();
    return 0;
}