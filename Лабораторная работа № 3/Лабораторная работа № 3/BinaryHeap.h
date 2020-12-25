#pragma once

#include "Iterator.h"
#include "Stack.h"

class BinaryHeap
{
private:
	const int size = 10000;
	int* h;
	int h_size;

public:

	BinaryHeap();
	~BinaryHeap();

	bool contains(int number);
	void insert(int number);
	void remove(int number);
	void heapify(int index);
	void siftDown(int index);
	void siftUp(int index);

	Iterator* create_bft_iterator();
	Iterator* create_dft_iterator();

	class bft_iterator : public Iterator
	{
	public:
		bft_iterator(int* cur, int h_size, int index);
		~bft_iterator();
		int next() override;
		bool has_next() override;

	private:
		int* cur;
		int h_size;
		int index;
	};

	class dft_iterator : public Iterator
	{
	public:
		dft_iterator(int* cur, int h_size, int index);
		~dft_iterator();
		int next() override;
		bool has_next() override;

	private:
		int* cur;
		int h_size;
		int index;
		stack stack;
	};
};