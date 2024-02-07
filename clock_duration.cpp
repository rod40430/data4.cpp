#include <iostream>
#include <chrono>
using namespace std;
using namespace std::chrono;

int main(void)
{
  auto t0 = chrono::high_resolution_clock::now();
  do_work();
  auto t1 = high_resolution_clock::now();

  cout<<duration<milliseconds>(t1 = t0).count()<<"msec\n";

  return 0;
}
