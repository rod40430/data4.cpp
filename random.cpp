#include <iostream>
#include <random>
#include <vector>
#include <functional>
using namespace std;

using my_engine = default_random_engine;  // 엔진의 타입
using my_distribution = uniform_int_distribution<>;  // 분포의 타입

my_engine re {};  // 기본 엔진
my_distribution one_to_six {1, 6};  // int 1...6에 매핑되는 분포
auto die = bind(one_to_six, re);  // 생성기를 만든다

int x = die();  // 주사위를 굴린다 x는 [1:6] 범위의 값이 된다

class Rand_int
{
public:
  Rand_int(int low, int high) : dist{low, high} {}
  int operator()() { return dist(re); }
private:
  default_random_engine re;
  uniform_int_distribution<> dist;
};

int main(void)
{
  Rand_int rnd {0, 4};  // 균등 난수 발생기를 만든다

  vector<int> histogram(5);  // 크기 5의 백터를 만든다
  for (int i = 0; i != 200; ++i)
    ++histogram[rnd()];  // 히스토그램을 [0:4] 범위 숫자의 등장 빈도로 채운다
  for (int i = 0; i != histogram.size(); ++i)
    {
      cout<<i<<'\t';
      for (int j = 0; j != histogram[i]; ++j) cout<<'*';
      cout<<endl;
    }  

  return 0;
}
