#include <iostream>

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
}

int main(void)
{



  return 0;
}
