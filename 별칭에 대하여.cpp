using Pchar = char*;  // 문자를 가리키는 포인터
using PF = int(*)(double);  // double을 받아들이고 int를 반환하는 함수를 가리키는 포인터

template<typename T>
class vector
{
  using value_type = T;  // 모든 컨테이너는 value_type을 갖고 있다
  // ...
};

template<typename T>
class list
{
  using value_type = T;  // 모든 컨테이너는 value_type을 갖고 있다
  // ...
};

Pchar p1 = nullptr;  // p1은 char*다
char* p3 = p1;  // 문제 없음

typedef int int32_t;  // using int32_t = int;과 동일
typedef short int16_t;  // using int16_t = short;과 동일
typedef void(*PtoF)(int);  // using PtoF = void(*)(int);과 동일

// using 키워드는 템플릿 별칭을 지을 때에도 사용될 수 있다
template<typename T>
using Vector = std::vector<T, My_allocator<T>>;

// unsigned 같은 타입 지정자는 별칭에 적용할 수 없다
using Char = char;
using Uchar = unsigned Char;  // 오류
using Uchar = unsigned char;  // Ok
