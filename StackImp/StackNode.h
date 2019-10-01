#pragma once
#include <cstddef>
class StackNode
{
private:
	StackNode* top = NULL;
public:
	int data;
	StackNode* next;

	bool is_empty();
	void push(int data);
	void print();
	int pop();
	int peek();
	void swap();
	void reverse();
	void delete_stack();
	bool contains(int val);
};