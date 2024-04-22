class Image
{
public:
	// ...
	Image(const Image& a);	// 복사 생성자
	// ...
	void write_block(Descriptor);
	// ...
private:
	Representation* clone();	// *rep를 복사한다
	shared_ptr<Representation> rep;	// 공유 가능성 있음
};

Image::Image(const Image& a)	// 얕은 복사를 한다
	: rep{ a.rep }	// a.rep는 이제 두 명의 사용자를 가진다
{
	// ...
}

void Image::write_block(Descriptor d)
{
	if (rep.use_count() > 1)
		rep = shared_ptr<Representation>{ clone() };
	// ... 이제 안전하게 우리 자신의 rep 사본에 쓰기를 할 수 있다...
}
