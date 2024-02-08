#include <iostream>
#include <limits>
using namespace std;

int main(void)
{
  cout<<"size of long "<<sizeof(1L)<<'\n';
  cout<<"size of long long "<<sizeof(1LL)<<'\n';
  
  cout<<"largest float "<<numeric_limits<float>::max()<<'\n';
  cout<<"char is signed "<<numeric_limits<char>::is_signed<<'\n';

  return 0;
}
