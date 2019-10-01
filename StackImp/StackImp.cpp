#include <iostream>
#include "StackNode.h"
#include <string>

int main()
{
	StackNode* stack = new StackNode();

	while (true)
	{
		std::cout << "Input integer data to push: ";
		std::string ans;
		std::cin >> ans;
		if (ans == "stop") break;

		stack->push(std::stoi(ans));
	}

	std::cout << std::endl << "Choose the option below. Write 'print' to print a list." << std::endl;
	std::cout << "1. Push." << std::endl;
	std::cout << "2. Pop." << std::endl;
	std::cout << "3. Peek." << std::endl;
	std::cout << "4. Swap." << std::endl;
	std::cout << "5. Reverse." << std::endl;
	std::cout << "6. Delete stack." << std::endl;
	std::cout << "7. Check if stack contains particular element." << std::endl;

	while (true)
	{
		std::cout << std::endl << "Your choice: ";

		std::string ans;
		std::cin >> ans;

		if (ans == "print")
		{
			stack->print();
		}

		if (ans == "1")
		{
			std::cout << "Input integer to push: ";
			int n;
			std::cin >> n;

			stack->push(n);
			continue;
		}

		if (ans == "2")
		{
			stack->pop();
			continue;
		}

		if (ans == "3")
		{
			if (stack->peek() == INT_MAX)
				std::cout << "Stack is empty." << std::endl;
			continue;
		}

		if (ans == "4")
		{
			stack->swap();
			continue;
		}

		if (ans == "5")
		{
			stack->reverse();
			continue;
		}

		if (ans == "6")
		{
			stack->delete_stack();
			continue;
		}

		if (ans == "7")
		{
			std::cout << "Input integer to check: ";
			int n;
			std::cin >> n;

			if (stack->contains(n))
				std::cout << "There is at least one element with value "
				<< n << "!" << std::endl;
			else
				std::cout << n << " is missing." << std::endl;
			continue;
		}
	}
}