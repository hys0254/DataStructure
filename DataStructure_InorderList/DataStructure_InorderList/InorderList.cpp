#include "InorderList.h"
#include <assert.h>

InorderList::InorderList()
{
	// Initialize an empty List
	head = 0;
	tail = 0;
	current = 0;
}
InorderList::~InorderList()
{
	while (head != 0) {
		Link delNode = head;
		head = head->next;
		delete delNode;
	}

}
void InorderList::insert(const ListElementType& elem)
{
	
	Link addedNode(new Node);
	assert(addedNode);
	addedNode->elem = elem;
	
	if (head == 0 || elem <= head->elem) {
		addedNode->next = head;
 		head = addedNode;
	}
	else {
		
		Link pred(head);
		
		while (pred->next != 0 && pred->next->elem <= addedNode->elem)
			
			pred = pred->next;
		
		addedNode->next = pred->next;
		pred->next = addedNode;
		
	}
}
bool InorderList::first(ListElementType& elem)
{
	// After calling first, current points to first item in list
	if (head == 0)
		return false;
	else {
		elem = head->elem;
		current = head;
		return true;
	}
}
bool InorderList::next(ListElementType& elem)
{
	// with proper use, current should always be nonzero
	assert(current);

	// After each call, current always points to the item
	// that next has just returned.
	if (current->next == 0)
		return false;
	else {
		current = current->next;
		elem = current->elem;
		return true;
	}
}
