enum class Traffic_light {red, yellow, green};
enum class Warning {green, yellow, orange, red};  // 경고 레벨 출력

Warning a1 = 7;  // 오류 : int->Warning 변환은 불가
int a2 = green;  // 오류 : green은 유효 범위 내에 없음
int a3 = Warning::green;  // 오류 : Warning->int 변환은 불가
Warning a4 = Warning::green;  // OK

void f(Traffic_light x)
{
  if (x) {};  // 오류 : 0으로 암시적 비교는 불가
  if (x == 9) {};  // 오류 : 9는 Traffic_light가 아님
  if (x == red) {};  // 오류 : red가 유효 범위 내에 없음
  if (x == Traffic_light::red) {};  // OK
}

// enum class의 기본 값은 : int이다
enum class Warning : int {green, yellow, orange, red};  // sizeof(Waring) == sizeof(int)
// 위 방식이 공간 낭비가 지나치게 심하다고 생각한다면 대신 char을 사용할 수도 있다
enum class Warnng : char {green, yellow, orange, red};  // sizeof(Waring) == 1
