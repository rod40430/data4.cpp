template<typename T, typename U>
auto operator+(const Matrix<T>& a, const Matrix<U>& b) -> Matric<decltype(T{}+U{})>
{
  Matrix<decltype(T{} + U{})> res;
  for (int i = 0; i !=a.rows(); ++i)
    for (int j = 0; j != a.cols(); ++j)
      res(i, j) += a(i, j) + b(i, j);
  return res;
}
