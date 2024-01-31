#include <string>
using std::string;
template<typename Key, typename Value>
class Map
{
  //... 
};

template<typename Value>
using String_map = Map<std::string, Value>;

String_map<int> m;  // m은 Map<string, int>이다
