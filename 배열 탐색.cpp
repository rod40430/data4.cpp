void fp(char v[], int size)
{
  for (int i = 0; i != size; ++i)
    use(v[i]);  // v가 최소한 크기 원소를 갖고 있기를 기대한다
  for (int x : v)
    use(x);  // 오류 : 포인터에는 통하지 않는다

  const int N = 7;
  char v2[N];
  for (int i = 0; i != N; ++i)
    use(v2[i]);
  for (int x : v2)
    use(x);  // 크기를 알고 있는 배열에는 사용할 수 있다.
}
