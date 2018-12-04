#include "Node.h"
#include "except.h"

template<typename T>
class List
{
private:
	Node<T> *begin;
	Node<T> *end;
	int size_of_list = 0;
public:
	List() {};
	List(const T &item);
	List(const List<T> &copy);
	void operator= (const List<T> &copy);
	T at(int pos);
	void push_back(const T& item);
	void push_front(const T& item);
	int size();
	void find_and_erase(T value);
	~List();
};

template<typename T>
List<T>::List(const List<T> &copy)
{
	*(this) = (copy);
}

template<typename T>
void List<T>::operator= (const List<T> &copy)
{
	this->size_of_list = copy.size_of_list;
	if (this->size_of_list == 0)
		return;
	this->begin = new Node<T>(copy.begin->data);
	if (this->size_of_list == 1)
		return; 
	end = begin;
	Node<T> *tmp = copy.begin;
	for(int i = 1; i < this->size_of_list; i++)
	{
		end->next = new Node<T>(tmp->next->data);
		end = end->next;
		tmp = tmp->next;
	}
}

template<typename T>
List<T>::List(const T &item)
{
	begin = new Node<T>(item);
	size_of_list++;
}

template<typename T>
int List<T>::size()
{
	return size_of_list;
}

template<typename T>
T List<T>::at(int pos)
{
	if (pos >= size_of_list)
		throw except((char*)"You out of range!");
	if ((pos + 1) == size_of_list)
		return end->data;
	Node<T> *tmp = begin;
	for (int i = 0; i < pos; i++)
		tmp = tmp->next;
	return tmp->data;
}

template<typename T>
void List<T>::push_back(const T& item)
{
	if (size_of_list == 0)
	{
		begin = new Node<T>(item);
		size_of_list++;
		return;
	}
	if (end == nullptr)
	{
		Node<T> *tmp = begin;
		for (int i = 1; i < size_of_list; i++)
			tmp = tmp->next;
		tmp->next = new Node<T>(item);
		end = tmp->next;
		size_of_list++;
		return;
	}
	end->next = new Node<T>(item);
	end = end->next;
	size_of_list++;
	return;
}

template<typename T>
void List<T>::push_front(const T& item)
{
	if (begin == nullptr)
	{
		begin = new Node<T>(item);
		size_of_list++;
		return;
	}
	Node<T> *tmp = new Node<T>(item);
	tmp->next = begin;
	begin = tmp;
	size_of_list++;
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
		size_of_list--;
		return;
	}
	while (tmp->next->data != value)
	{
		tmp = tmp->next;
		if (tmp->next == nullptr)
			throw except((char*)"List hasn't this element!");
	}
	Node<T> *tmpOne = tmp->next;
	tmp->next = tmpOne->next;
	size_of_list--;
	delete tmpOne;
}

template<typename T>
List<T>::~List()
{
	Node<T> *tmp;
	while (begin != nullptr)
	{
		tmp = begin;
		begin = begin->next;
		delete tmp;
	}
}