class SimpleLockGuard {
	// 전달받은 mutex 객체를 자동으로 lock하고, 자동으로 unlock 해주는 랩퍼 클래스
public:
	SimpleLockGuard(mutex& m) {
		this->m = &m;
		this->m->lock();
	}
	~SimpleLockGuard() {
		this->m->unlock();
	}
private:
	mutex* m;
};
void Push_withRAII() {
	for (int32 i = 0; i < 10000; i++) {
		SimpleLockGuard lockGuard(m);
		
		vec.push_back(i);
		
        // 특정 예외 처리
        if(...) {
        	break;
        }
        
		// lockGuard 소멸 (내부적으로 unlock)
	}
}
