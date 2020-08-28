
#include <iostream>
#include <string>
#include "Stack.h"
using namespace std;

int main(int argc, char* argv[])
{
	cout << "Input RPN Equation" << endl;
	Stack < double > s;
	double op1, op2;
	char c;

	while ((c = cin.peek()) != '\n') {
		if (isdigit(c)) { 
			cin >> op1;
			s.push(op1);
		}


		else {
			cin >> c; 
			op2 = s.pop();
			op1 = s.pop();
			switch (c) {
				case '+': s.push(op1 + op2); break;
				case '-':   s.push(op1 - op2); break;
				case '*':   s.push(op1 * op2); break;
					case '/': if (op2 == 0) cerr << "Division by zero!\n";
					  else	s.push(op1 / op2); break;
			}
		}
		while ((c = cin.peek()) == ' ') {
			cin.ignore(1, ' ');
		}
	}
	cout << " Result: " << s.pop();
	return 0;
}
