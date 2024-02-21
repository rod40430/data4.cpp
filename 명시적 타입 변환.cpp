template<typename Target, typename Source>
Target narrow_cast(Source v)
{
  auto r = static_cast<Target>(v);
  if (static_cast<Source>(r) != v)
    throw runtime_error("narrow_cast<>() failed");
  return r;
}

void test(double d, int i, char* p)
{
  auto c1 = narrow_cast<char>(64);
  auto c2 = narrow_cast<char>(-64);  // char가 부호가 없다면 예외를 던질 것이다
  auto c3 = narrow_cast<char>(264);  // char가 8비트라면 예외를 던질 것이다

  auto d1 = narrow_cast<double>(1 / 3.0F);  // OK
  auto f1 = narrow_cast<double>(1 / 3.0);  // 아마도 예외를 던질 듯하다
  
  auto c4 = narrow_cast<char>(i);  // 예외를 던질지도 모른다
  auto f2 = narrow_cast<float>(d);  // 예외를 던질지도 모른다

  auto p1 = narrow_cast<char*>(i);  // 컴파일 타입 오류
  auto i1 = narrow_cast<int>(p);  // 컴파일 타입 오류

  auto d2 = narrow_cast<double>(i);  // 예외를 던질 수 있다(하지만 그렇게는 하지 않을 것이다)
  auto i2 = narrow_cast<int>(d);  // 예외를 던질 수 있다
}
