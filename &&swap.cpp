template<typename T>
void swap(T& a, T& b)  // (거의)완벽한 바꿔치기
{
  T tem {move(a)};  // a에서 이동한다
  a = move(b);  // b에서 이동한다
  b = move(tem);  // tem에서 이동한다
}
