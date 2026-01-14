// map 插入和删除

// insert<elem>;
// clear();
// erase(pos);
// erase(beg, end);
// erase(key);

#include <iostream>
#include <map>
#include <utility>

using namespace std;

void printMap(map<int, int> &mp) {
  for (map<int, int>::iterator it = mp.begin(); it != mp.end(); it++) {
    cout << "key = " << (*it).first << " value = " << it->second << endl;
  }
  cout << endl;
}

void test01() {
    map<int, int> m;
    m.insert(pair<int,int>(1, 10));
    
    m.insert(make_pair(2, 20));

    m.insert(map<int,int>::value_type(3, 30));

    // [] 不建议插入，用途：可以通过 key 访问到 value
    m[4] = 40;

    cout << m[4] << endl;

    printMap(m);

    // 删除
    m.erase(m.begin());
    printMap(m);

    m.erase(3);
    printMap(m);

    m.erase(m.begin(), m.end());
    printMap(m);
}

int main() {
  test01();
  return 0;
}