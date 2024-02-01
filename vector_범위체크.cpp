#include <iostream>
#include <vector>
using namespace std;

// void silly(vector<Entry>& book)
// {
//   int i = book[book.size()].number;  // book.size()는 범위를 벗어난다
//   // ...
// }

// 위 이러한 초과 오류를 해결하기 위한 방법으로 범위 체크 기능을 갖춘 vector의 응용버전
template<typename T>
class Vec : public vector<T>
{
public:
  using vector<T>::vector;  // vector의 생성자를 (Vec이란 이름으로)사용한다
  T& operator[](int i) {return vector<T>::at(i);}  // 범위 체크
  const T& operator[](int i) const {return vector<T>::at(i);}  // const 객체 범위 체크
};
