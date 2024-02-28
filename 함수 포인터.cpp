// 함수 포인터로 오버로딩된 함수도 가르킬 수 있다
void f(int);
int f(char);

void (*pf1)(int) = &f;  // void f(int)
int (*pf2)(char) = &f;  // int f(char)
void (*pf3)(char) = &f;  // 오류 : void f(char)는 허용되지 않음

// 멤버 함수의 주소를 얻을 수도 있지만 멤버 함수를 가르키는 포인터 함수는 함수 포인터와 상당히 다르다
// noexcept 함수를 가리키는 포인터는 noexcept로 선언될 수 있다

void fe(int) noexcept;
void g(int);

void (*p1)(int) = fe;  // OK : 하지만 유용한 정보를 날려버린다
void (*p2)(int) noexcept = fe;  // OK noexcept 정보를 보존한다
void (*p3)(int) noexcept = g;  // 오류 : g가 던지지 않는다는 것을 모른다

// 함수를 가리키는 포인터는 함수의 링크 관계를 반영해야 한다. 링크 관계 지정이나 noexcept는 타입 별칭에 등장할 수 없다
using pc = extern "C" void(int);  // 오류 : 링크 관계 지정이 별칭에 등장
using pn = void(int) noexcept;  // 오류 : noexcept가 별칭에 등장
