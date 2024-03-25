class Nomlocal
{
public:
  // ...
  void destroy() { delete this; }  // 명시적 소멸
private:
  // ...
  ~Nonlocal();  // 암시적으로 소멸시키지 않는다
};

void user()
{
  Nonlocal x;  // 오류 : Nonlocal을 소멸시킬 수 없다
  Nonlocal* p = new Nonlocal;  // OK
  // ...
  delete p;  // 오류 : Nonlocal을 소멸시킬 수 없다
  p.distroy();  // OK
}
