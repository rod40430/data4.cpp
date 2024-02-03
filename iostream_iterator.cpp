#include <iostream>
#include <fstream>
#include <iterator>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// ostream_iterator<string> oo{cout};  // cout에 string을 쓴다

// int main(void)
// {
//   *oo = "Hello, ";  // cout<<"Hello, "를 의미한다
//   ++oo;
//   *oo = "world!\n";
// }

// istream_iterator<string> ii {cin};  // 입력 반복자는 시퀀스를 나타내는 쌍에서 사용되므로,
// istream_iterator<string> eos {};    // 입력의 끝을 알려주기 위해

int main(void)
{
  string from, to;
  cin>>from>>to;
  ifstream is {from};                    // 파일 "from"을 위한 입력 스트림
  istream_iterator<string> ii {is};      // 스트림을 위한 입력 반복자
  istream_iterator<string> eos {};       // 입려 검사

  ofstream os {to};                      // 파일 "to"을 위한 출력 스트림
  ostream_iterator<string> oo {os, "\n"};// 스트림을 위한 출력 반복자

  vector<string> b {ii, eos};            // b는 출력으로 초기화된 백터
  sort(b.begin(), b.end());              // 버퍼를 정렬한다

  unique_copy(b.begin(), b.end(), oo);   // 버퍼를 출력으로 복사하고, 중복된 값을 버린다

  return !is.eof() || !os;
}
