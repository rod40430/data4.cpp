#include <iostream>
#include <string>

using namespace std;

void use_file(const char* fn)  // 불편한 코드
{
  FILE* f = fopen(fn, "r");
  try
    {
      // ...use f...
    }
    catch(...)  // 가능한 모든 예외를 잡는다
    {
      fclose(f);
      throw;
    }
  fclose(f);
}  // 하지만 위 코드는 자원을 많이 차지한다

// FILE* 선언보단 객체를 정의할 수 있다

class File_ptr
{
  FILE* p;
public:
  File_ptr(const char* n, const char* a)  // 파일 n을 연다
    : p(fopen(n, a))
  {
    if (p == nullptr) throw runtime_error{"file_ptr : Can't open file"}:
  }
  File_ptr(const string& n, const char* a)  // 파일 n을 연다
    : File_ptr(n.c_str(), a)
  {}
  explicit File_ptr(FILE* pp)  // pp를 소유한다고 가정한다
    : p(pp)
  {
    if (p == nullptr) throw runtime_error{"file_ptr : Can't open file"}:
  }
  // ... 적절한 이동 및 복사 연산들...
  ~File_ptr() {fclose(p);}
  operator FILE*() {return p;}
};

int main(void)
{



  return 0;
}
