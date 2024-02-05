#include <iostream>
#include <thread>
#include <future>
#include <vector>
#include <numeric>
using namespace std;

double accum(double* beg, double* end, double init)
  // 초기 값 init으로 시작되는 [beg:end] 범위의 합을 계산
{
  return accumulate(beg, end, init);  // 배열의 합을 구하는 함수
}

double comp2(vector<double>& v)
{
  using Task_type = double(double*, double*, double);  // 태스크의 타입

  packaged_task<Task_type> pt0 {accum};  // 태스크를 묶는다
  packaged_task<Task_type> pt1 {accum};

  future<double> f0 {pt0.get_future()};  // pt0의 future를 잡는다
  future<double> f1 {pt1.get_future()};

  double* first = &v[0];
  thread t1 {move(pt0), first, first + v.size() / 2, 0};  // pt0에 대한 스레드를 시작한다
  thread t2 {move(pt0), first + v.size() / 2, first+v.size(), 0};

  // ...
  return f0.get() + f1.get();  // 결과를 구한다
}
