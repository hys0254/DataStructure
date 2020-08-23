#include "List.h"
#include <assert.h>

List::List()
{
	// initialize to an empty list
	numberOfElements = 0;
	currentPosition = -1;
}
void List::insert(const ListElementType& elem)
{
    assert(numberOfElements < maxListSize);
    listArray[numberOfElements] = elem;
    numberOfElements++;
}
bool List::first(ListElementType& elem)
{
    if (numberOfElements == 0)
        return false;
    else {
        currentPosition = 0;
        elem = listArray[currentPosition];
        return true;
    }
}
bool List::next(ListElementType& elem)
{
    // with proper use, currentPosition should always be
    // greater than or equal to zero
    assert(currentPosition >= 0);
    if (currentPosition >= numberOfElements - 1)
        return false;
    else {
        currentPosition++;
        elem = listArray[currentPosition];
        return true;
    }
}