auto z1 {99};  // z1은 initializer_list<int>
auto z2 = 99;  // s2는 int

vector<int> v1 {99};  // v1은 99의 값을 가진 1 원소의 vector
vector<int> v2(99);  // v2는 각각 기본 값 0을 가진 99원소의 vector

vector<string> v1{"hello!"};  // v1은 "hello!"값을 가진 1원소의 vector
vector<string> v2("hello!");  // 오류 : vector 생성자는 문자열 리터럴을 받지 않는다

// 따라서 특별한 이유가 있지 않는 한, 다른 방법 대신 {}초기화 식을 사용한다

int x4 {};  // x4는 0이 된다
double d4 {};  // d4는 0.0이 된다
char* p {};  // p는 nullptr이 된다
vector<int> v4{};  // v4는 빈 vector가 된다
string s4 {};  // s4는 ""이 된다
