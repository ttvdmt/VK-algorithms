#pragma once
#include <cstddef>
#include <iostream>
#include <initializer_list>
#include "node.hpp"

template<typename KeyT>
class forward_list 
{
	using pointer = Node<KeyT>*;

private:

	pointer mhead{nullptr};
	size_t msize{0};

public:

	forward_list() : mhead{nullptr}, msize{0} {};

	forward_list(std::initializer_list<KeyT> il)
	{
		for (auto it = il.begin(); it != il.end(); it++)
			push_front(*it);
	}

	void push_front(const KeyT& data)
	{
		if (!mhead) {
			mhead = new Node<KeyT>{data};
			msize++;
			return;
		}

		mhead = new Node<KeyT>{data, mhead};
		msize++;
	}

	void push_back(const KeyT& data)
	{
		if (!mhead) {
			mhead = new Node<KeyT>{data};
			msize++;
			return;
		}

		pointer cur = mhead;
		while (cur->next)
			cur = cur->next;

		cur->next = new Node<KeyT>{data};
		msize++;
	}

	void insert_after(const KeyT& after, const KeyT& data)
	{
		pointer cur = mhead;
		while (cur)
		{
			if (cur->data == after)
				break;

			cur = cur->next;
		}

		if (cur) {
			cur->next = new Node<KeyT>{data, cur->next}; 
			msize++;
		}
	}

	pointer erase(const KeyT& val)
	{
		Node<KeyT> dummy{0, mhead};
		pointer prev = &dummy;
		pointer cur = mhead;
		while (cur)
		{
			if (cur->data == val) {
				
				prev->next = cur->next;
				msize--;

				pointer tmp = cur;
				cur = cur->next;
				delete tmp;
			}
			else {
				prev = cur;
				cur = cur->next;
			}
		}
		mhead = dummy.next;
		return mhead;
	}

	pointer middle_elem() const
	{
		pointer slow = mhead, fast = mhead;
		while (fast && fast->next)
		{
			slow = slow->next;
			fast = fast->next->next;
		}
		return slow;
	}

	pointer reverse()
	{
		pointer prev = nullptr;
		pointer current = mhead;

		while (current)
		{
			pointer next = current->next;
			current->next = prev;
			prev = current;
			current = next;
		}
		mhead = prev;
		return mhead;
	}

	void clear()
	{
		pointer cur = mhead; 
		pointer tmp = cur ? cur->next : nullptr;

		while(tmp)
		{
			delete cur;
			msize--;

			cur = tmp;
			tmp = cur->next;
		}
	}

	void print() const
	{
		
			pointer cur = mhead;
			while(cur)
			{
				std::cout << cur->data << ' ';
				cur = cur->next;
			}
			std::cout << std::endl;
		
	}

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

	size_t size() const {return msize;}

	bool empty() const {return msize > 0;}

	friend pointer merge(forward_list& main, forward_list& second)
	{
		Node<KeyT> dummy{0, main.mhead};
		pointer prev = &dummy;
		pointer cur = main.mhead;
		pointer tcur = second.mhead;
		
		while (cur && tcur)
		{
			if (cur->data < tcur->data) {
				prev = cur;
				cur = cur->next;
			}
			else {
				prev->next = tcur;
				tcur = tcur->next;
				prev->next->next = cur;
				prev = prev->next;

				main.msize++;
				second.msize--;
				second.mhead = nullptr;
			}
		}

		while (tcur)
		{
			prev->next = tcur;
			tcur = tcur->next;
			prev->next->next = cur;
			prev = prev->next;

			main.msize++;
			second.msize--;
		}
		
		main.mhead = dummy.next;
		return main.mhead;
	}

	~forward_list() {clear();}
};