#include <iostream>
using namespace std;

enum class Traffic_ligth {green, yellow, red};

Traffic_ligth& operator++(Traffic_ligth& t)
{
  switch(t)
    {
      case Traffic_ligth::green: return t = Traffic_ligth::yellow;
      case Traffic_ligth::yellow: return t = Traffic_ligth::red;
      case Traffic_ligth::red: return t = Traffic_ligth::green;
    }
}

int main(void)
{
  Traffic_ligth a = Traffic_ligth::red;
  cout<<(int) a<<endl;
  cout<<(int) ++a<<endl;
  
  return 0;
}