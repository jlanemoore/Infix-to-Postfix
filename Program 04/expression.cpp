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
#include "expression.h"
#include "stack.h"
#include "queue.h"
#include "QNodeType.h"
#include <fstream>
#include <iostream>


///////////////////////////////////////////////////////////////////////////////
//
//  Function: expression::expression()
//
//  Description:
//  constructer for expression. sets ifix and pfix to empty strings. 
//  sets last equal to false
//
//  Preconditions:
//  none
//
//  Postconditions:
//  ifix and pfix are empty strings. last is false.
//
///////////////////////////////////////////////////////////////////////////////
expression::expression() {
	ifix = pfix = "";
	last = false;
}


///////////////////////////////////////////////////////////////////////////////
//
//  Function: void expression::converToPostfix()
//
//  Description:
//  Adds $ to top of stack so you know when youve reached the end. Add 
//  infix to stack in an order according to the operation and its
//  precedence. empty the stack into postfix.
//
//  Preconditions:
//  a infix expression must be read in
//
//  Postconditions:
//  pfix is set to postfix representation of expression.
//
///////////////////////////////////////////////////////////////////////////////
void expression::convertToPostfix() {
	stack<char> st;
	st.push('$');
	pfix = "";
	for (size_t i = 0; i < ifix.size() - 1; ++i) {
		switch (ifix[i]) {
		case '(':
			st.push(ifix[i]);
			break;
		case')':
			while (st.top() != '(') {
				pfix += st.top();
				st.pop();
			}
			st.pop();
			break;
		case '+':
		case '-':
		case '*':
		case '/':
			while (precedence(st.top(), ifix[i])) {
				pfix += st.top();
				st.pop();
			}
			st.push(ifix[i]);
			break;
		default:
			pfix += ifix[i];
			break;
		}
	}
	while (st.top() != '$') {
		pfix += st.top();
		st.pop();
	}
}

///////////////////////////////////////////////////////////////////////////////
//
//  Function: bool expression::precedence(char one, char two) const
//
//  Description:
//  Returns true or false depending on precedence of operation. This one
//  took some research
//
//  Preconditions:
//  none
//
//  Postconditions:
//  * and / have the highest precedence and will return true first. 
//  after that, paraenthesis do not have precedence and $ is the top of 
//  the stack and not an operation. Then + and - are the only 
//  operations left with precedence
//
///////////////////////////////////////////////////////////////////////////////
bool expression::precedence(char one, char two) const {
	if (one == '*' || one == '/') return true;
	if (one == '(' || one == '$') return false;
	return (two == '+' || two == '-');
}

///////////////////////////////////////////////////////////////////////////////
//
//  std::ostream& operator<<(std::ostream& out, const expression& source)
//
//  Description:
//  Outputs the infix expression followed by the postfix expression
//
//  Preconditions:
//  none
//
//  Postconditions:
//  will return infix and postfix as ostream object.
//
///////////////////////////////////////////////////////////////////////////////
std::ostream& operator<<(std::ostream& out, const expression& source) {
	out << "Infix:    " << source.ifix << std::endl;
	out << "Postfix:  " << source.pfix << std::endl;
	return out;
}

///////////////////////////////////////////////////////////////////////////////
//
//  std::istream& operator>>(std::istream& in, expression& source)
//
//  Description:
//  Reads in expression from input stream. adds them to ifix until
//  stop symbol is reached. marks if expression is the last in the file.
//  then calls the convert to postfix
//
//  Preconditions:
//  correctly formatted input file
//
//  Postconditions:
//  will return infix and postfix as ostream object.
//
///////////////////////////////////////////////////////////////////////////////
std::istream& operator>>(std::istream& in, expression& source) {
	char sym;
	source.ifix = "";
	do {
		in >> sym;
		source.ifix += sym;
	} while (sym != ';' && sym != '.');
	if (sym == '.') {
		source.last = true;
	}
	source.convertToPostfix();
	return in;
}