#include <iostream>
#include <utility>
#include <tuple>
#include <vector>
#include <string>
using namespace std;

tuple<string, int, double> t2 {"Sild", 123, 3.14};  // 타입이 명시적으로 지정된다

auto t = make_tuple(string{"Herring"}, 10, 1.23);  // 타입 추론

string s = get<0>(t);  // tuple의 첫 번째 원소, "Herring"을 얻는다
int x = get<1>(t);  // 10
double d = get<2>(t);  // 1.23
