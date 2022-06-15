#include "deque.h"
template <typename T>
class Stack::Container, iterator {
private:
	Deque<T>* stackDeque; = new Deque<T>();
public:
	next() = 0;
	Stack() {}
	Stack(Stack & rhs){}
	~Stack() { delete stackDeque; }
	void push(T data) { stackDeque.push_front(data); }
	T pop() { return stackDeque.pop_front() }
	void traverse(void(*doIt)(T data)) {
		stackDeque.traverse(doIt);
	};
	size_t size() override;
	size_t max_size() override;
	bool empty() override { return stackDeque.empty(); };
	void swap(Container&, Container&) override;
	void clear() override;
	next() = nullptr;
}