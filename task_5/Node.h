#pragma once
#include "InfoAboutUniversity.h"

struct Node
{
	InfoAboutUniversity info; 
	Node* next; 
	Node* prev;
};

