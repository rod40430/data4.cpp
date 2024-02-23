// 배열에 대한 참조자의 주된 용도는 템플릿에서다
template<typename T, int N>
void f(T(&r)[N])
{
  // ...
}

int a1[10];
double a2[100];

void g()
{
  f(a1);  // T는 int다. N은 10이다
  f(a2);  // T는 double이다. N은 100이다
}
