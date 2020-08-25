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
#include<fstream>
#include<iostream>
#include "expression.h"
#include "stack.h"
#include "queue.h"
using namespace std;

int main() {
	ifstream infix;
	ofstream output;
	queue<expression> exQueue;
	expression exp;
	infix.open("inputfile");
	output.open("outputfile");

	if (!infix.is_open())
	{
		cout << "Input File Not Found";
		return 0;
	}
	while (!exp.last) {
		infix >> exp;
		exQueue.push(exp);
	}

	while (!exQueue.empty()) {
		cout << exQueue.front();
		output << exQueue.front();
		exQueue.pop();
	}

	output.close();
	infix.close();

	return 0;
}