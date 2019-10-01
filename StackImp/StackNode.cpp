#include "StackNode.h"
#include <cstddef>
#include <iostream>

bool StackNode::is_empty()
{
	if (!top) return true;
	return false;
}

void StackNode::push(int data)
{
	StackNode* temp = new StackNode();
	if (!temp) return;

	temp->data = data;
	temp->next = top;
	top = temp;
	std::cout << data << " pushed to the stack.\n";
}

void StackNode::print()
{
	if (is_empty())
	{
		std::cout << "Stack is empty.\n";
		return;
	}

	StackNode* trav = top;
	while (trav)
	{
		std::cout << trav->data << " ";
		trav = trav->next;
	}
	std::cout << std::endl;
}

int StackNode::pop()
{
	StackNode* trav = top;
	trav = trav->next;
	int popped = top->data;
	delete top;
	top = trav;
	
	std::cout << popped << " popped from the stack.\n";
	return popped;
}


int StackNode::peek()
{
	if (!is_empty())
	{
		std::cout << "Top element is " << top->data << std::endl;
		return top->data;
	}
	return INT_MAX;
}

void StackNode::swap()
{
	if (is_empty()) return;

	StackNode* bot = top;
	StackNode* bot_prev = top;

	while (bot->next)
	{
		bot_prev = bot;
		bot = bot->next;
	}
	
	bot_prev->next = top;
	bot->next = top->next;
	top->next = NULL;
	top = bot;
}

void StackNode::reverse()
{
	// Initialize current, previous and 
		// next pointers 
	StackNode* current = top;
	StackNode* prev = NULL;
	StackNode* next = NULL;

	while (current != NULL) 
	{
		// Store next 
		next = current->next;

		// Reverse current node's pointer 
		current->next = prev;

		// Move pointers one position atop. 
		prev = current;
		current = next;
	}
	top = prev;
}

void StackNode::delete_stack()
{
	if (is_empty()) return;

	StackNode* trav = top;
	while (top)
	{
		top = top->next;
		delete trav;
		trav = top;
	}
}

bool StackNode::contains(int val)
{
	if (is_empty()) return false;

	StackNode* trav = top;
	while (trav)
	{
		if (trav->data == val) return true;
		trav = trav->next;
	}
	return false;
}