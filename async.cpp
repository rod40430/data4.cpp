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

double comp4(vector<double>& v)
  // v가 충분히 크다면 다수의 태스크를 생성한다
{
  if (v.size() < 10000) return accum(v.begin(), v.end(), 0.0);

  auto v0 = &v[0];
  auto sz = v.size();
  auto f0 = async(accum, v0, v0 + sz / 4, 0.0);
  auto f1 = async(accum, v0 + sz / 4, v0 + sz / 2, 0.0);
  auto f2 = async(accum, v0 + sz / 2, v0 + sz *3/4, 0.0);
  auto f3 = async(accum, v0 + sz * 3/4, v0 + sz, 0.0);

  return f0.get() + f1.get() + f2.get() + f3.get();
}
