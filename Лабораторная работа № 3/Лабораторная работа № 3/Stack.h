#pragma once

class stack
{
private:
	class Element
	{
	public:
		Element(int data, Element* next = nullptr, Element* prev = nullptr) {
			this->data = data;
			this->next = next;
			this->prev = prev;
		}
		~Element() {}

		int data;
		Element* next;
		Element* prev;
	};

	Element* head;
	Element* tail;
	size_t size_of_stack;

public:
	stack();
	~stack();

	void add_first(int elem);
	void reset_list();

	void push_back(int elem); 
	void pop_back(); 
	int at(size_t index); 
	size_t get_size(); 
	bool isEmpty(); 
};

