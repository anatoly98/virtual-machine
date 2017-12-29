#include "stack_class.h"

void Stack::push(int value) {
	node_s *node = new node_s;
	node->data = value;
	node->prev = top;
	top = node;
}
int Stack::pop()
{
	int newdata = top->data;
	node_s *save_topptr;
	save_topptr = top;
	top = top->prev;
	delete save_topptr;
	return newdata;
}