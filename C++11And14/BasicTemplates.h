#pragma once

#include <memory>
#include <iostream>
#include <vld.h>

template <typename T>
class ArrayListNode {
public:
	T t;
	std::shared_ptr<ArrayListNode<T>> next;
	std::shared_ptr<ArrayListNode<T>> prev;
	ArrayListNode(T p_t);
};

template<typename T>
ArrayListNode<T>::ArrayListNode(T p_t) : t(p_t) {
	next = nullptr;
}

template<typename T>
class ArrayList {
public:
	std::shared_ptr<ArrayListNode<T>> root;
	int size;
	int current;

	ArrayList();
	void Add(T p_t);
	void PrintList();
	bool Search(T p_t, std::shared_ptr<ArrayListNode<T>>& p_node);
	void Delete(T p_t);

};

template <typename T>
ArrayList<T>::ArrayList() : size(0), current(0) {
	root = nullptr;
}

template <typename T>
void ArrayList<T>::Add(T p_t) {
	std::shared_ptr<ArrayListNode<T>> new_root = std::make_shared<ArrayListNode<T>>(p_t);
	new_root->next = root;
	if (root != nullptr) {
		root->prev = new_root;
	}
	root = new_root;
	root->prev = nullptr;

}

template <typename T>
void ArrayList<T>::PrintList() {
	std::shared_ptr<ArrayListNode<T>> current = root;

	if (current != nullptr) {

		while (current != nullptr) {
			std::cout << current->t << std::endl;
			current = current->next;
		}

	}

}

template<typename T>
bool ArrayList<T>::Search(T p_t, std::shared_ptr<ArrayListNode<T>>& p_node)
{

	std::shared_ptr<ArrayListNode<T>> current = root;
	while (current != nullptr && current->t != p_t) {
		current = current->next;
		p_node = current;
	}
	if (p_node == nullptr) {
		return false;
	}
	else {
		return true;
	}
}

template<typename T>
void ArrayList<T>::Delete(T p_t)
{
	std::shared_ptr<ArrayListNode<T>> node = nullptr;
	if (Search(p_t, node)) {
		if (node->prev != nullptr) {
			node->prev->next = node->next;
		}
		else {
			root = node->next;
		}

		if (node->next != nullptr) {
			node->next->prev = node->prev;
		}
	}
}

void TestBasicTemplate() {
	ArrayList<int> list;

	list.Add(20);
	list.Add(1);
	list.Add(2);
	list.Add(3);
	list.Add(4);
	list.Add(5);
	list.Add(6);

	list.PrintList();

	std::shared_ptr<ArrayListNode<int>> result_node = nullptr;
	bool result = list.Search(3, result_node);
	if (result) {
		std::cout << "5 has been found" << std::endl;
	}
	else {
		std::cout << "5 has not been found" << std::endl;
	}

	list.Delete(5);

	list.PrintList();

}