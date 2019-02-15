#include "Node.h"
#include "except.h"
#include <iostream>

template<typename T>
class List
{
private:
	Node<T> *begin = NULL;
	Node<T> *end = NULL;
	int size_of_List;
public:
	List();
	List(const T &item);
	List(const List<T> &copy);
	void operator= (const List<T> &copy);
	T at(int pos) const;
	void push_back(const T& item);
	void push_front(const T& item);
	int size() const;
	void find_and_erase(T value);
	~List();
};
template<typename T>
List<T>::List()
{
	size_of_List = 0;
}

template<typename T>
List<T>::List(const T &item)
{
	begin = new Node<T>(item);
	end = begin;
	size_of_List = 1;
}

template<typename T>
List<T>::List(const List<T> &copy)
{
	*(this) = (copy);
}

template<typename T>
void List<T>::operator= (const List<T> &copy)
{
	Node<T> *delTmp;
	while (begin != NULL)
	{
		delTmp = begin;
		begin = begin->next;
		delete delTmp;
	}
	this->size_of_List = copy.size_of_List;
	if (this->size_of_List == 0)
		return;
	this->begin = new Node<T>(copy.begin->data);
	end = begin;
	if (this->size_of_List == 1)
		return; 
	Node<T> *tmp = copy.begin;
	for(int i = 1; i < this->size_of_List; i++)
	{
		end->next = new Node<T>(tmp->next->data);
		end = end->next;
		tmp = tmp->next;
	}
}

template<typename T>
int List<T>::size() const
{
	return size_of_List;
}

template<typename T>
T List<T>::at(int pos) const
{
	if (pos >= size_of_List)
		throw except("You out of range!");
	if(pos == size_of_List - 1)
		return end->data;
	Node<T> *tmp = begin;
	for (int i = 0; i < pos; i++)
		tmp = tmp->next;
	return tmp->data;
}

template<typename T>
void List<T>::push_back(const T& item)
{
	if (size_of_List == 0)
	{
		begin = new Node<T>(item);
		end = begin;
		size_of_List++;
		return;
	}
	end->next = new Node<T>(item);
	end = end->next;
	size_of_List++;
	return;
}

template<typename T>
void List<T>::push_front(const T& item)
{
	if (begin == NULL)
	{
		begin = new Node<T>(item);
		end = begin;
		size_of_List++;
		return;
	}
	Node<T> *tmp = new Node<T>(item);
	tmp->next = begin;
	begin = tmp;
	size_of_List++;
	return;
}

template<typename T>
void List<T>::find_and_erase(T value)
{
	Node<T> *tmp = begin;
	if (begin->data == value)
	{
		begin = tmp->next;
		delete tmp;
		size_of_List--;
		return;
	}
	while (tmp->next->data != value)
	{
		tmp = tmp->next;
		if (tmp->next == NULL)
			throw except("List haven't this element!");
	}
	Node<T> *tmpOne = tmp->next;
	tmp->next = tmpOne->next;
	size_of_List--;
	delete tmpOne;
}

template<typename T>
List<T>::~List()
{
	Node<T> *tmp;
	while (begin != NULL)
	{
		tmp = begin;
		begin = begin->next;
		delete tmp;
	}
}