#include <stdexcept>
#include "iostream"
#include "Stack.h"

using namespace std;

void stack::reset_list()
{
	head = nullptr;
	tail = nullptr;
}

stack::stack()
{
	reset_list();
	size_of_stack = 0;
}

stack::~stack()
{
	Element* current = head->next;
	while (current->next != nullptr) {
		delete head;
		head = current;
		current = head->next;
	}
	delete head;
	delete tail;
	size_of_stack = 0;
}

void stack::add_first(int elem)
{
	head = new Element(elem);
	tail = head;
}

void stack::push_back(int elem)
{
	if (size_of_stack == 0) {
		add_first(elem);
	}
	else {
		tail->next = new Element(elem, nullptr, tail);
		tail = tail->next;
	}
	size_of_stack++;
}

void stack::pop_back()
{
	if (size_of_stack == 0) return;

	if (size_of_stack == 1) {
		delete head;
		reset_list();
	}
	else {
		Element* current = tail->prev;
		current->next = nullptr;
		delete tail;
		tail = current;
	}
	size_of_stack--;
}

int stack::at(size_t index)
{
	if (index >= size_of_stack) {
		throw out_of_range("Error");
	}
	else {
		Element* current = head;
		size_t counter = 0;
		while (counter != index) {
			current = current->next;
			counter++;
		}
		return current->data;
	}
}

size_t stack::get_size()
{
	return size_of_stack;
}

bool stack::isEmpty()
{
	if (size_of_stack == 0) return true;
	else return false;
}

