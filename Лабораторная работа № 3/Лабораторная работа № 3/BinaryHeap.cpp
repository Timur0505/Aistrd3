#include "BinaryHeap.h"
#include <iostream>

using namespace std;

BinaryHeap::BinaryHeap()
{
	h = new int[size];
	h_size = 0;
}

BinaryHeap::~BinaryHeap()
{
	delete h;
	h_size = 0;
}

void BinaryHeap::siftDown(int index) {
	int left, right;
	int j, temp;
	while (2 * index + 1 < h_size) {
		left = 2 * index + 1;
		right = 2 * index + 2;
		j = left;
		if (right < h_size && h[right] < h[left])
			j = right;
		if (h[index] <= h[j])
			break;
		temp = h[index];
		h[index] = h[j];
		h[j] = temp;
		index = j;
	}
}

void BinaryHeap::siftUp(int index) {
	int temp;
	while (h[index] < h[(index - 1) / 2]) {
		temp = h[index];
		h[index] = h[(index - 1) / 2];
		h[(index - 1) / 2] = temp;
		index = (index - 1) / 2;
	}
}

void BinaryHeap::heapify(int index)
{
	if (h[index] > h[2 * index + 1] || h[index] > h[2 * index + 2]) siftDown(index);
	if (h[index] < h[(index - 1) / 2]) siftUp(index);
}



void BinaryHeap::insert(int number)
{
	int index, parent, temp;
	index = h_size;
	h[index] = number;
	parent = (index - 1) / 2;
	while (parent >= 0 && index > 0) {
		if (h[index] < h[parent]) {
			temp = h[index];
			h[index] = h[parent];
			h[parent] = temp;
		}
		index = parent;
		parent = (index - 1) / 2;
	}
	h_size++;
}

bool BinaryHeap::contains(int number)
{
	for (int i = 0; i < h_size; i++) {
		if (h[i] == number) return true;
	}
	return false;
}

void BinaryHeap::remove(int number)
{
	int temp;
	for (int i = 0; i < h_size; i++) {
		if (h[i] == number) {
			temp = h[i];
			h[i] = h[h_size - 1];
			h[h_size - 1] = temp;
			h_size--;
			heapify(i);
			break;
		}
	}
}

Iterator* BinaryHeap::create_bft_iterator()
{
	return new bft_iterator(h, size, 0);
}

BinaryHeap::bft_iterator::bft_iterator(int* cur, int h_size, int index = 0)
{
	this->cur = cur;
	this->h_size = h_size;
	this->index = index;
}

BinaryHeap::bft_iterator::~bft_iterator()
{
	delete cur;
}

int BinaryHeap::bft_iterator::next()
{
	if (!has_next())
		throw ("No more elements");
	index++;
	return cur[index - 1];
}

bool BinaryHeap::bft_iterator::has_next()
{
	return index != this->h_size;
}

Iterator* BinaryHeap::create_dft_iterator()
{
	return new dft_iterator(h, h_size, 0);
}

BinaryHeap::dft_iterator::dft_iterator(int* cur, int h_size, int index = 0)
{
	this->cur = cur;
	this->h_size = h_size;
	this->index = index;
}

BinaryHeap::dft_iterator::~dft_iterator()
{
	delete cur;
}

int BinaryHeap::dft_iterator::next()
{
	if (!has_next())
		throw ("No more elements");
	int temp = cur[index];
	int left = index * 2 + 1;
	int right = index * 2 + 2;
	if (index == 0) stack.push_back(0);
	if (right < this->h_size) {
		stack.push_back(right);
		index = left;
	}
	else if (left < this->h_size) index = left;
	else {
		if (stack.at(stack.get_size() - 1) == 0)
			stack.pop_back();
		else {
			index = stack.at(stack.get_size() - 1);
			stack.pop_back();
		}
		if (this->h_size == 1) index = -1;
	}
	return temp;
}

bool BinaryHeap::dft_iterator::has_next()
{
	if (h_size == 0) return false;
	if (index == 0) return true;
	if (stack.isEmpty() && index != 0) return false;
	else return true;
}