#include "LinkedList.h"
#include <assert.h>

LinkedList::LinkedList()
{
	// Initialize an empty List
	head = 0;
	tail = 0;
	current = 0;
}
LinkedList::~LinkedList()
{
	while (head != 0) {
		Link delNode = head;
		head = head->next;
		delete delNode;
	}
	
}
void LinkedList::insert(const ListElementType& elem)
{
	//Insert(tail)
	//Link addedNode = new Node;
	//assert(addedNode); // check to make sure node was allocated
	//addedNode->elem = elem;
	//if (head == 0) // list was empty -- set head
	//	head = addedNode;v
	//else
	//	tail->next = addedNode;
	//tail = addedNode;
	//addedNode->next = 0;
	//Insert(head)
	Link addedNode = new Node;
	assert(addedNode); // check to make sure node was allocated
	addedNode->elem = elem;
	if (head == 0) { // list was empty -- set head
		head = addedNode;
		addedNode->next = NULL;
	}
	else
		addedNode->next = head;
	head = addedNode;

	
}
bool LinkedList::first(ListElementType& elem)
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
bool LinkedList::next(ListElementType& elem)
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
