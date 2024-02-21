// 람다표현식
void print_modulo(const vector<int>& v, ostream& os, int m)
// v[i] % m == 0이면 v[i]를 os로 출력한다
{
  for_each(begin(v), end(v),
    [&os, m](int x) {if (x % m == 0) os << x << " ";});

  // 람다식에 이름을 붙여 사용할 수 있다
  auto printr = [&os, m](int x) {if (x % m == 0) os << x << " ";}
  for_each(begin(v), end(v), printrr);
}

// 이것을 펑터로 표현한다면
class Modulo_print
{
private:
  ostream& os;  // 캡처 리스트를 보관할 멤버
  int m;
public:
  Modulo_print(ostream& s, int mm) : os(s), m(mm) {}  // 캡처
  void operator()(int x) const
  {
    if (x % m == 0) os << x << '\n';
  }
};
