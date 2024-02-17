enum class Kind : char
{
  name, number, end,
  plus = '+', minus = '-', mul = '*', div = '/', print = ';', assign = '=',
  lp = '(', rp =')'
};

struct Token
{
  Kind kind;
  string string_value;
  double number_value;
};

class Token_stream
{
public:
  Token_stream(istream& s) : ip{&s}, owns{false} {}
  Token_stream(istream* s) : ip{s}, owns{true} {}

  ~Token_stream() {close();}

  Token get();  // 다음 토큰을 읽고 반환한다
  const Token& current() {return ct;}  // 가장 최근에 읽혀진 토큰

  void set_input(istream& s) {close(); ip = &s; owns = false;}
  void set_input(istream* p) {close(); ip = p; owns = true;}
private:
  void close() {if (owns) delete ip;}

  istream* ip;
  bool owns;  // Token_stream이 istream을 소유하고 있는가?
  Token ct{Kind::end};  // 현재의 토큰
};

Token Token_stream::get()
{
  char ch = 0;
  *ip>>ch;

  switch (ch)
    {
      case 0:
        return ct = {Kind::end};  // 대입과 반환
      case ';':                   // 표현식의 끝 ;을 출력한다
      case '*':
      case '/':
      case '+':
      case '-':
      case '(':
      case ')':
      case '=':
        return ct = {static_cast<Kind>(ch)};  // char에서 Kind로 암시적 변환 불가
      case '0':
      case '1':
      case '2':
      case '3':
      case '4':
      case '5':
      case '6':
      case '7':
      case '8':
      case '9':
      case '.':
        ip->putback(ch);  // 첫 번째 수치 (또는 .)입력 스트림에 다시 집어넣는다
        *ip>>ct.number_value;  // ct로 숫자를 읽어 들인다
        ct.kind = Kind::number;
        return ct;
      default:  // name, name =가 아니면 오류
      if (isalpha(ch))
      {
        ip->putback(ch);  // 첫 번째 문자를 입력 스트림에 돌려놓는다
        *ip>>ct.string_value;  // 문자열을 ct로 읽어 들인다
        ct.kind = Kind::name;
        return ct;
      }
    }
  error("bad token");
  return ct = {Kind::print};
} 

double expr(bool get)  // 덧셈과  뺄셈
{
  double left = term(get);

  for (;;)  // 무한루프
    {
      switch (ts.current().kind))
        {
          case Kind::plus:
            left += term(true);
            break;
          case Kind::minus:
            left -= term(true);
            break;
          default:
            return left;
        }
    }
}

double term(bool get)  // 곱셈과 나눗셈
{
  double left = prim(get);

  for (;;)
    {
      switch (ts.current().kind)
        {
          case Kind::mul:
            left *= prim(true);
            break;
          case Kind::div:
            if (auto d = prim(true))
            {
              left /= d;
              break;
            }
          return error("divide by 0");
          
          default:
            return left;
        }
    }
}

double prim(bool get)  // 기본 단위를 처리한다
{
  if (get) ts.get();  // 다음 토큰을 읽는다

  switch (ts.current().kind)
    {
      case Kind::number:  // 부동소수점 상수
        {
          double v = ts.current().number_value;
          ts.get();
          return v;
        }
      case Kind::name:
        {
          double& v = table[ts.current().string_value];  // 대응되는 것을 찾는다
          if (ts.get.Kind == Kind::assign) v = expr(true);  // '='은 대입
          return v;
        }
      case Kind::minus:  // 단항 음수화
        return =prim(true);
      case Kind::lp;  //괄호
      {
        auto e = expr(true);
        if (ts.current().kind != Kind::rp) return error("')' expected");
        ts.get();  // 닫는 소괄호 ')'를 먹어 버린다
      }
      default:
        return error("primary expected");
    }
}
