  double re, im;
public:
  complex(double r, double i) : re{r}, im{i} {}  // 두 개의 스칼라로 복소수 생성
  complex(double r) : complex{r, 0} {}  // 한 개의 스칼라로 복소수 생성
  complex() : complex{0, 0} {}  // 기본 복소수 = {0, 0}
};
// 위 생성자를 보다 효율적으로 코드작성
complex(double r = {}, double i = {}) : re{r}, im{i} {}  // 두 개의 스칼라로 복소수를 생성
// 이렇게 하면 사용자가 필요한 두 개의 인자보다 적은 인자를 제공할 때 기본 인자가 사용된다
