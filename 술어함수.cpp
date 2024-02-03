#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

void f(map<string, int>& m)
{
  auto p = find_if(m.begin(), m.end(), 
  [](const pair<string, int>& p) { return p.second > 0;});  // 0자리에 비교가 될 값을 선언
}
