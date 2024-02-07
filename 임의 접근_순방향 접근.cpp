#include <iostream>
#include <iterator>
#include <vector>
using namespace std;

template<typename C>
using value_type = typename C::value_type;

template<typename Ran>  // 임의 접근 반복자용 
void sort_helper(Ran beg, Ran end, random_access_iterator_tag)  // [ beg:end]로 첨자 연산을
// 할 수 있다.
{
  sort(beg,end);  // 단순 정렬한다
}

template<typename For>  // 순방향 연산자용
void sort_helper(For beg, For end, forward_iterator_tag)  // [ beg:end]를 순회 탐색할 수 있다
{
  vector<value_type<For>> v {beg, end};  // [beg:end]의 벡터를 초기화한다
  sort(v.begin, v.end());
  copy(v.begin(), v.end(), beg);  // 원소를 되돌려서 복사한다
}
// template<typename C>
  // using Iterator_type = typename C::iterator;  // C의 반복자 타입
// template<typename Iter>
  // using Iterator_category = typename std::iterator_traits<Iter>::iterator_category;  // Iter의 카테고리
