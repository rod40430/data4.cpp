void do_something(int n, int m, int a)
// mn이란 2차원 행렬에 뭔가를 한다.
{
  for (int i = 0; i != n; ++i)
    for (int j = 0; j != m; ++j)
      if (nm[i][j] == a)
        goto found;  // goto문으로 found가 선언된 곳으로 이동한다(사이에 코드들은 건너뜀)
  // 발견되지 않음
  // ...
  found:  // found가 아닌 다른 이름도 상관 없다
  {
    // 발견됨
  }
}
