#include<iostream>
#include "List.h"

using namespace std;

int main()
{
	List l;
	ListElementType i; // header file defines this to be int
	cout << "Enter items to add to list, add 0 to stop: ";
	cin >> i;
	while (i != 0) {
		l.insert(i);
		cin >> i;
	}
	cout << "Here are the items in the list.\n";
	ListElementType elem;
	bool notEmpty(l.first(elem));
	while (notEmpty) {
		cout << elem << endl;
		notEmpty = l.next(elem);
	}
	l.previous(elem);
	cout << "마지막에서 두번째 " << elem << endl;
	l.previous(elem);
	cout << "마지막에서 세번째 " << elem << endl;
	l.next(elem);
	cout << "마지막에서 두번째 " << elem << endl;
	l.next(elem);
	cout << "마지막 " << elem << endl;
	l.first(elem);
	cout <<"첫번째 " <<elem << endl;


	return 0;
}


