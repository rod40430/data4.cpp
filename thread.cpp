#include <iostream>
#include <thread>
#include <vector>
using namespace std;

void f(const vector<double>& v, double* res);  // v에서 입력을 받아들이고, *res에 결과를 넣는다

class F
{
public:
  F(const vector<double>& vv, double* p) : v(vv), res(p) {}
  void operator()();
private:
  const vector<double>& v;
  double* res;
};

int main(void)
{
  vector<double> some_vec;
  vector<double> vec2;
  // ...
  double res1;
  double res2;

  thread t1 {f, ref(some_vec), &res1};
  thread t2 {F{vec2, &res2}};

  t1.join();  // join은 스레드가 종료 될 때 까지 기다린다
  t2.join();

  cout<<res1<<' '<<res2<<endl;

  return 0;
}
