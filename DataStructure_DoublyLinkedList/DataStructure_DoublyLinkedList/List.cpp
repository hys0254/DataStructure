#include "List.h"
#include<assert.h>

void List::insert(const ListElementType& elem)
{
    Link addedNode = new Node;
    assert(addedNode);
    addedNode->elem = elem;
    addedNode->next = head;
    if (head) 
        head->prev = addedNode;   
    addedNode->prev = 0;
    head = addedNode;
}


bool List::previous(ListElementType& elem)
{
    assert(current);
    if (current->prev == 0)
        return false;
    else {
        current = current->prev;
        elem = current->elem;
        return true;
    }
}

bool List::first(ListElementType& elem)
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
bool List::next(ListElementType& elem)
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
List::List()
{
	head = NULL;
	current = NULL;
}