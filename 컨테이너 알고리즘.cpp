#include <iostream>
#include <algorithm>

namespace Estd
{
  using namespace std;
  template<typename C>
  void sort(C& c)
  {
    sort(c.begin(), c.end());
  }
  template<typename C, typename Pred>
  void sort(C& c, Pred p)
  {
    sort(c.begin(), c.end(), p);
  }
  // ...
}
