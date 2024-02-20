constexpr const char* p1 = "asdf";
constexpr const char* p2 = p1;  // OK
constexpr const char* p2 = p1 + 2;  // 오류 : 컴파일러는 p1의 값을 알지 못한다
constexpr const char c = p1[2];  // Ok, c == 'd' - 컴파일러는 p1이 가리키는 값을 알고 있다
