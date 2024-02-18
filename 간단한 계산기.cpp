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
  char ch;

  do  // '\n'을 제외한 공백을 건너뛴다
    {
      if (!ip->get(ch)) return ct = {Kind::end};
    }while (ch != '\n' && isspace(ch));
  switch (ch)
    {
      case ';':
      case '\n':
        return ct = {Kind::print};
      default:  // NAME, NAME =가 아니면 오류
        if (isalpha(ch))
        {
          ct.string_value = ch;
          while (ip->get(ch))
            if (isalnum(ch))
              ct.string_value += ch;  // ch를 string_value의 끝에 붙인다
            else
            {
              ip->putback(ch);
              break;
            }
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
