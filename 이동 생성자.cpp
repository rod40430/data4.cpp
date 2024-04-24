template <typename T>
class<T>::class(class&& a)
	: dim{ a.dim }, elem{ a.elem }
{
	a.dim = { 0, 0 };
	a.elem = nullptr
}

template<typename T>
void swap(T& a, T& b)
{
	T tmp = std::move(a);
	a = std::move(b);
	b = std::move(tmp);
}
// std::move()는 자신의 인자에 대한 우변 값 참조자를 반환
