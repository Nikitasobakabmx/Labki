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
	this->begin = new Node<T>(copy.begin->data);
	Node<T> *thisTmp = this->begin;
	Node<T> *copyTmp = copy.begin;
	for (int i = 1; i < this->size_of_list; i++)
	{
		thisTmp->next = new Node<T>(copyTmp->next->data);
		thisTmp = thisTmp->next;
		copyTmp = copyTmp->next;
	}
	return;
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
		throw except((char*)"Out of range");
	if (pos == size_of_list - 1)
		return end->data;
	Node<T> *tmp = begin;
	for (int i = 0; i < pos; i++)
		tmp = tmp->next;
	return tmp->data;
}

template<typename T>
void List<T>::push_back(const T& item)
{
	if (begin == nullptr)
		begin = new Node<T>(item);
	if (begin->next == nullptr)
	{
		begin->next = new Node<T>(item);
		end = begin->next;
	}
	end->next = new Node<T>(item);
	end = end->next;
	size_of_list++;
}

template<typename T>
void List<T>::push_front(const T& item)
{
	if (begin == nullptr)
		begin = end = new Node<T>(item);
	Node<T> *tmp = new Node<T>(item);
	tmp->next = begin;
	begin = tmp;
	size_of_list++;
}

template<typename T>
void List<T>::find_and_erase(T value)
{
	Node<T> *tmp = begin;
	if (begin->data == value)
	{
		begin = tmp->next;
		delete tmp;
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
	delete tmpOne;
}

template<typename T>
List<T>::~List()
{
	Node<T> *tmp;
	while (begin == nullptr)
	{
		tmp = begin;
		begin = begin->next;
		delete tmp;
	}
}
