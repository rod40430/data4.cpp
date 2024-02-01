#include <iostream>
#include <list>
using namespace std;

void f(const Entry&ee, list<Entry>::iterator p, list<Entry>::iterator q)
{
  phone_book.insert(p, ee);  // p가 참조하는 원소 앞에 ee를 추가한다.
  phone_book.erase(q);  // q가 참조하는 원소를 삭제한다
}
