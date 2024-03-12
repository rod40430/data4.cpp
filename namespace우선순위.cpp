#include <iostream>

using namespace std;

namespace N
{
	template <typename T>
		void f(T, int);	// N::f()
	class X {};
}
namespace N2
{
	N::X x;
	void f(N::X, unsigned);
	void g()
	{
		f(x, 1);	// N::f(x, int)를 호출한다
	}
}

int main(void)
{
	


	return 0;
}
