#include<assert.h>
using namespace std;

#ifndef queue
#define queue


const int maxQueue = 4;

template < class queueElementType >
class Queue {
public:
	Queue();
	~Queue();
	void enqueue(queueElementType e);
	queueElementType dequeue();
	queueElementType front();
	bool isEmpty();
	bool isFull();
private:
	int f; // marks the front of the queue
	int r; // marks the rear of the queue
	queueElementType elements[maxQueue];
	int m_nElement;
};

#endif
// cx9-3.cpp
// Code Example 9-3: Implementation of a Circular Queue

int nextPos(int p)
{
	if (p == maxQueue - 1) // at end of circle
		return 0;
	else
		return p + 1;
}
template < class queueElementType >
Queue < queueElementType >::Queue()
{
	// start both front and rear at 0
	f = 0;
	r = 0;
	m_nElement = 0;
}

template<class queueElementType>
inline Queue<queueElementType>::~Queue()
{
}

template < class queueElementType >
void
Queue < queueElementType >::enqueue(queueElementType e)
{	
	if(!isFull()){
	//assert(nextPos(r) != f);
		r = nextPos(r);
		elements[r] = e;
		m_nElement++;
	}else {
		cout << "Queue is FULL" << endl;
	}
	
}

template < class queueElementType >
queueElementType
Queue < queueElementType >::dequeue()
{
	
	if (!isEmpty()) {
		//assert(f != r);
		f = nextPos(f);
		m_nElement--;
		return elements[f];
	}
	else {
		cout << "Queue is EMPTY" << endl;
		return NULL;
	}
}
template < class queueElementType >
queueElementType
Queue < queueElementType >::front()
{
	// return value of element at the front
	assert(f != r);
	return elements[nextPos(f)];
}
template < class queueElementType >
bool
Queue < queueElementType >::isEmpty()
{
	// return true if the queue is empty, that is,
	// if front is the same as rear
	return bool(m_nElement==0);
}
template < class queueElementType >
bool
Queue<queueElementType>::isFull() {
	return bool(m_nElement == sizeof(elements)/sizeof(elements[0]));
}
