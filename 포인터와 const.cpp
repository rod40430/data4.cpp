void f1(char* p)
{
  char s[] = "Gorm";

  const char* pc = s;  // 상수를 가리키는 포인터
  pc[3] = 'g';  // 오류 : pc는 상수를 가리킨다
  pc = p;  // OK

  char *const cp = s;  // 상수 포인터
  cp[3] = 'a';  // OK
  cp = p;  // 오류 : cp는 상수

  const char *const cpc = s;  // const를 가리키는 const 포인터
  cpc[3] = 'a';  // 오류 : cpc는 상수를 가리킨다
  cpc = p;  // 오류 : cpc는 상수

  char *const cp;  // char를 가리키는 const 포인터
  char const* pc;  // const char를 가리키는 포인터
  const char* pc2;  // const char를 가리키는 포인터
}
