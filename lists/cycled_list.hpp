#pragma once
#include <cstddef>
#include <iostream>
#include <initializer_list>
#include "node.hpp"

template<typename KeyT>
class cycled_list
{
	using pointer = Node<KeyT>*;

private:

	pointer mhead{nullptr};
	size_t msize{0};
	int mcycle_pos;
	pointer mcycle_root;

public:

	cycled_list() : mhead{nullptr}, mcycle_root{nullptr}, msize{0}, mcycle_pos{0} {};

	cycled_list(int pos) : mhead{nullptr}, mcycle_root{nullptr}, msize{0}, mcycle_pos{pos} {};

	cycled_list(int pos, std::initializer_list<KeyT> il)
	{
		mcycle_pos = pos;
		for (auto it = il.begin(); it != il.end(); it++)
			push_back(*it);
	}

	void push_back(const KeyT& data)
	{
		if (!mhead) {
			mhead = new Node{data};
			msize++;
			if (mcycle_pos == 0)
				mcycle_root = mhead;
			return;
		}

		pointer cur = mhead;
		
		int turn = 1;
		while (turn != size()) {
			cur = cur->next;
			turn++;
		}

		if (turn == mcycle_pos) {
			cur->next = new Node{data};
			mcycle_root = cur->next;
		}
		else
			cur->next = new Node{data, mcycle_root};
		msize++;
	}

	void clear()
	{
		pointer cur = mhead;
		pointer tmp = cur->next;

		while(tmp)
		{
			delete cur;
			msize--;

			cur = tmp;
			tmp = cur->next;
		}
	}

	size_t size() const {return msize;}

	bool iscycled() const
	{
		if (!mhead || !mhead->next)
			return false;

		pointer slow = mhead;
		pointer fast = mhead->next;

		while (slow != fast)
		{
			if (!fast || !fast->next)
				return false;

			slow = slow->next;
			fast = fast->next->next;
		}
		return true;
	}

	~cycled_list() {clear();}
};