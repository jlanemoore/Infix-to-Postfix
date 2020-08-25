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
#ifndef stack__h
#define stack__h
#include <vector>
template<class T>
class stack {
	public:
		stack(size_t = 10);
		stack(const stack<T>&);
		void push(const T&);
		void pop();
		size_t size() const;
		bool empty() const;
		const T& top() const;
	private:
		std::vector<T> items;
};

///////////////////////////////////////////////////////////////////////////////
//
//  Function: stack<T>::stack(size_t size)
//
//  Description:
//  Constructor that reserves "size" memory for the stack
//
//  Preconditions:
//  none
//
//  Postconditions:
//  allocated memory
//
///////////////////////////////////////////////////////////////////////////////
template<class T>
stack<T>::stack(size_t size) {
	items.reserve(size);
}

///////////////////////////////////////////////////////////////////////////////
//
//  Function: stack<T>::stack(const stack<T>& source)
//
//  Description:
//  Copy constructor
//
//  Preconditions:
//  existing stack
//
//  Postconditions:
//  new stack matching existing
//
///////////////////////////////////////////////////////////////////////////////
template<class T>
stack<T>::stack(const stack<T>& source) {
	items = source.items;
}

///////////////////////////////////////////////////////////////////////////////
//
//  Function: void stack<T>::push(const T& item)
//
//  Description:
//  Adds new item to top of stack
//
//  Preconditions:
//  existing stack
//
//  Postconditions:
//  new item on stack
//
///////////////////////////////////////////////////////////////////////////////
template<class T>
void stack<T>::push(const T& item) {
	items.push_back(item);
}

///////////////////////////////////////////////////////////////////////////////
//
//  Function: void stack<T>::pop()
//
//  Description:
//  Removes top item from stack
//
//  Preconditions:
//  existing stack
//
//  Postconditions:
//  item removed from top of stack
//
///////////////////////////////////////////////////////////////////////////////
template<class T>
void stack<T>::pop() {
	items.pop_back();
}

///////////////////////////////////////////////////////////////////////////////
//
//  Function: size_t stack<T>::size() const 
//
//  Description:
//  Returns the number of items in the stack
//
//  Preconditions:
//  existing stack
//
//  Postconditions:
//  nothing changed
//
///////////////////////////////////////////////////////////////////////////////
template<class T>
size_t stack<T>::size() const {
	return items.size();
}

///////////////////////////////////////////////////////////////////////////////
//
//  Function: bool stack<T>::empty() const 
//
//  Description:
//  Returns whether or not the stack is empty
//
//  Preconditions:
//  existing stack
//
//  Postconditions:
//  nothing changed
//
///////////////////////////////////////////////////////////////////////////////
template<class T>
bool stack<T>::empty() const {
	return items.empty();
}

///////////////////////////////////////////////////////////////////////////////
//
//  Function: const T& stack<T>::top() const
//
//  Description:
//  Returns item at the top of the stack
//
//  Preconditions:
//  existing stack
//
//  Postconditions:
//  the stack is unchanged
//
///////////////////////////////////////////////////////////////////////////////
template<class T>
const T& stack<T>::top() const {
	return items.back();
}


#endif // !stack__h
