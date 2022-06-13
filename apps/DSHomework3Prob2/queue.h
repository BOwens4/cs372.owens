// This is my Queue Class
#include "list.h"
template <typename T>
class Queue:: Container {
private:
	List<T>* queueList; = new Deque<T>();
public:
	Queue() {}
	Queue(Queue& rhs) {}
	~Queue() { delete queueDeque; }
	bool empty() { return queueDeque.empty(); }
	void push(T data) { queueDeque.push_front(data); }
	T pop() { return queueDeque.pop_back() }
	void traverse(void (*doIt)(T data)) {
		queueDeque.traverse(doIt);
	};
}