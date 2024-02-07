#include <iostream>
#include <regex>
#include <vector>
#include <string>
using namespace std;

regex pat (R"(\w{2}\s*\d{5}(-\d{4})?)");  // ZIP 코드 패턴 : XXddddd-dddd 및 기타 철자법

int lineno = 0;
for (string line; getline(cin, line);)  // line 버퍼로 읽어 들인다
  {
    ++lineno;
    smatch matches;  // 일치하는 문자열은 이곳으로 간다
    if (regex_search(line, matches, pat))  // line에서 pat을 찾는다
      cout<<lineno<<" : "<<matches[0]<<'\n';
  }
