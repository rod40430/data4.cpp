template<typename C, typename Oper>
void for_all(C& c, Oper op)  // C를 포인터로 이뤄진 컨테이너라고 가정한다
{
  for (auto& x : c)
    op(*x);  // op()에 가리켜지는 각 원소에 대한 참조자를 전달한다
}
