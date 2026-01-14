// deque 数据存取

// at(iny idx);
// operator[];
// front();
// back();

#include<iostream>
#include<deque>


using namespace std;

void printDeque(const deque<int> &d){
    for (deque<int>::const_iterator it=d.begin(); it!=d.end(); it++){
        cout << *it << " ";
    }
    cout << endl;
}

void test01(){
    deque<int> d;
    d.push_back(1);
    d.push_back(2);
    d.push_back(3);
    d.push_front(100);
    d.push_front(200);
    d.push_front(300);

    // 通过 [] 访问元素
    for (int i=0; i<d.size(); i++){
        cout << d[i] << " ";
    }
    cout << endl;

    // 通过 at 访问
    for (int i=0; i<d.size(); i++){
        cout << d.at(i) << " ";
    }
    cout << endl;

    // front, back
    cout << "front " << d.front() << endl;
    cout << "back " << d.back() << endl;
}

int main(){
    test01();

    return 0;
}