///////////////////////////////////////////////////////////////////////////////
//
//  Hayden Bowden
//  Program 04
//  Due: 04/28/2020
//
//  Description:
//  Read in infix expression and add them to a queue. Convert them to
//  postfix and output them to the screen 
//
//  Input:
//  A file of infix expressions called inputfile
//
//  Output:
//  Will display the infix expression followed by its postfix representation
//
//  Assumptions:
//  Most of this program was written at 3 am. I'm honestly not sure what 
//  assumptions were made or even how I managed to figure it out.
//
///////////////////////////////////////////////////////////////////////////////
#ifndef queue__h
#define queue__h
#include "QNodeType.h"

template<class T>
class queue {
	public:
		queue();
		queue(const queue<T>&);
		~queue();
		const queue<T>& operator=(const queue<T>&);
		void push(const T&);
		void pop();
		const T& front() const;
		const T& back() const;
		size_t size() const;
		bool empty() const;
	private:
		void destroy();
		void copy(const queue<T>&);
		QNodeType<T>* front_;
		QNodeType<T>* back_;
		size_t count;
};

///////////////////////////////////////////////////////////////////////////////
//
//  Function: queue<T>::queue()
//
//  Description:
//  Constructor for queue. Sets front and back pointers to null 
//  and count to 0
//
//  Preconditions:
//  none
//
//  Postconditions:
//  bront and back are nullptr and count is 0
//
///////////////////////////////////////////////////////////////////////////////
template<class T>
queue<T>::queue() {
	front_ = back_ = nullptr;
	count = 0;
}

///////////////////////////////////////////////////////////////////////////////
//
//  Function: queue<T>::queue(const queue<T>& source)
//
//  Description:
//  Copy Constructor for queue. copies existing queue to new queue
//
//  Preconditions:
//  existing queue
//
//  Postconditions:
//  new queue is same as existing queue
//
///////////////////////////////////////////////////////////////////////////////
template<class T>
queue<T>::queue(const queue<T>& source) {
	copy(source);
	count = source.count;
}

///////////////////////////////////////////////////////////////////////////////
//
//  Function: queue<T>::~queue()
//
//  Description:
//  Destructor for queue. Destroys all pointers
//
//  Preconditions:
//  existing queue
//
//  Postconditions:
//  Queue is null
//
///////////////////////////////////////////////////////////////////////////////
template<class T>
queue<T>::~queue() {
	destroy();
}

///////////////////////////////////////////////////////////////////////////////
//
//  Function: const queue<T>& queue<T>::operator=(const queue<T>& source)
//
//  Description:
//  assingment overload for queue. set queue equal to another queue
//
//  Preconditions:
//  existing queue
//
//  Postconditions:
//  queue is equal to source queue
//
///////////////////////////////////////////////////////////////////////////////
template<class T>
const queue<T>& queue<T>::operator=(const queue<T>& source) {
	if (this != &source) {
		copy(source);
		count = source.count;
	}
	return *this;
}

///////////////////////////////////////////////////////////////////////////////
//
//  Function: void queue<T>::push(const T& item)
//
//  Description:
//  Pushes new node to back of queue
//
//  Preconditions:
//  existing queue
//
//  Postconditions:
//  new node at back of queue, count is one higher
//
///////////////////////////////////////////////////////////////////////////////
template<class T>
void queue<T>::push(const T& item) {
	if (front_ == nullptr) {
		front_ = new QNodeType<T>;
		front_->item = item;
		front_->next = nullptr;
		back_=front_;
	}else{
		back_->next = new QNodeType<T>;
		back_ = back_->next;
		back_->item = item;
	}
	++count;
}

///////////////////////////////////////////////////////////////////////////////
//
//  Function: void queue<T>::pop()
//
//  Description:
//  Removes front node from queue
//
//  Preconditions:
//  existing queue
//
//  Postconditions:
//  removed node at front of queue, count is one lower
//
///////////////////////////////////////////////////////////////////////////////
template<class T>
void queue<T>::pop() {
	if (!empty()) {
		QNodeType<T>* temp = front_;
		front_ = front_->next;
		delete temp;
		--count;
		if (front_ == nullptr) {
			back_ = nullptr;
		}
	}
}

///////////////////////////////////////////////////////////////////////////////
//
//  Function: const T& queue<T>::front() const 
//
//  Description:
//  Returns item of front queue node
//
//  Preconditions:
//  existing queue
//
//  Postconditions:
//  Queue is unchanged
//
///////////////////////////////////////////////////////////////////////////////
template<class T>
const T& queue<T>::front() const {
	if (!empty()) {
		return front_->item;
	}
}

///////////////////////////////////////////////////////////////////////////////
//
//  Function: const T& queue<T>::back() const 
//
//  Description:
//  Returns item of back queue node
//
//  Preconditions:
//  existing queue
//
//  Postconditions:
//  Queue is unchanged
//
///////////////////////////////////////////////////////////////////////////////
template<class T>
const T& queue<T>::back() const {
	if (!empty()) {
		return back_->item;
	}
}

///////////////////////////////////////////////////////////////////////////////
//
//  Function: size_t queue<T>::size() const 
//
//  Description:
//  Returns count of nodes in queue
//
//  Preconditions:
//  existing queue
//
//  Postconditions:
//  Queue is unchanged
//
///////////////////////////////////////////////////////////////////////////////
template<class T>
size_t queue<T>::size() const {
	return count;
}

///////////////////////////////////////////////////////////////////////////////
//
//  Function: bool queue<T>::empty() const
//
//  Description:
//  Returns whether queue is empty
//
//  Preconditions:
//  existing queue
//
//  Postconditions:
//  Queue is unchanged
//
///////////////////////////////////////////////////////////////////////////////
template<class T>
bool queue<T>::empty() const{
	return count == 0;
}

///////////////////////////////////////////////////////////////////////////////
//
//  Function: void queue<T>::destroy()
//
//  Description:
//  pops each node in queue
//
//  Preconditions:
//  existing queue
//
//  Postconditions:
//  Queue is empty
//
///////////////////////////////////////////////////////////////////////////////
template<class T>
void queue<T>::destroy() {
	while (!empty()) {
		pop();
	}
}

///////////////////////////////////////////////////////////////////////////////
//
//  Function: void queue<T>::copy(const queue<T>& source)
//
//  Description:
//  copys one queue to another
//
//  Preconditions:
//  existing queue
//
//  Postconditions:
//  queue and count are equal to existing queue
//
///////////////////////////////////////////////////////////////////////////////
template<class T>
void queue<T>::copy(const queue<T>& source) {
	QNodeType<T>* temp = source.front_;
	front_ = back_ = nullptr;
	if (temp != nullptr) {
		front = new QNodeType<T>;
		front_->item = temp->item;
		front_->next = nullptr;
		back_ = front_;
		temp = temp->next;
		while (temp != nullptr) {
			back_->next = new QNodeType<T>;
			back_ = back_->next;
			back_->item = temp->next;
			temp = temp->next;
		}
		back_->next = nullptr;
	}else {
		front_ = back_ = nullptr;
	}
	count = source.count;
}
#endif // !queue__h
