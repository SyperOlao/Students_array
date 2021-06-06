#pragma once
#include "Node.h"
#include "InfoAboutUniversity.h"

class List
{
public:
	Node* head, * tail;
	int size;
	List() {
		head = nullptr;
		tail = nullptr;
		size = 0;
	}

	void add(InfoAboutUniversity info);
	void delete_elem(int index);
	InfoAboutUniversity get(int index);
};
 