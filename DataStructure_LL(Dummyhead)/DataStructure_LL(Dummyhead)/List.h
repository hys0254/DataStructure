#pragma once
typedef int ListElementType;

class List {
	
public:
	List();	
	void insert(const ListElementType& elem);
	bool first(ListElementType& elem);
	bool next(ListElementType& elem);
	void remove(const ListElementType& target);

private:
	struct Node; 
	typedef Node* Link; 
	struct Node { 
		ListElementType elem;
		Link next;
	};
	Link head;
	Link current;
};



