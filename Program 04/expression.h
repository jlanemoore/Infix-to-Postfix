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
#ifndef expression__h
#define expression__h
#include<iostream>
#include<string>
class expression {
	public:
		expression();
		friend std::ostream& operator<<(std::ostream&, const expression&);
		friend std::istream& operator>>(std::istream&, expression&);
		bool last;
	private:
		void convertToPostfix();
		bool precedence(char, char) const;
		std::string ifix;
		std::string pfix;
};

#endif // !expression__h
