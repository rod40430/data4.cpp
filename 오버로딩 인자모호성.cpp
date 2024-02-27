void f1(char);
void f1(long);

void f2(char*);
void f2(int*);

void k(int i)
{
  f1(i);  // 모호하다
  f2(0);  // 모호하다
}

// 수동 오버로딩 해결
inline void f1(int n) { f1(long(n)); }
f2(static_cast<int*>(0));
