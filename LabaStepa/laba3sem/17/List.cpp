/*#include "List.h"
#include "exception.h"

template<typename T>
List<T>::List()
{
    begin = new Node<T>(); 
    begin->next = end;
    size_of_list = 0;  
}
template<typename T>
List<T>::List(const T &item)
{
    begin = new Node<T>(item);
    begin->next = end;
    size_of_list = 1;
}

template<typename T>
int List<T>::size()
{
    return size_of_list;
}

template<typename T>
T& List<T>::at(int pos)
{
    if (pos > size_of_list)
		throw exception("Out of range");
    Node<T> *tmp = begin;
    for(int i = 0; i < pos; i++)
        tmp = tmp->next;
    return tmp;
}

template<typename T>
void List<T>::push_back(const T& item)
{
    end = end->next;
    end = new Node<T>(item);
    size_of_list++;
}

template<typename T>
void List<T>::push_front(const T& item)
{
    Node<T> *tmp = begin;
    begin = new Node<T>(item);
    begin->next = tmp;
    i++;
}

template<typename T>
bool List<T>::find_and_erase(const T& value)
{
    Node<T> *tmp = begin;
    while(tmp->next->data != value)
    {
        tmp = tmp->next;
        if(tmp == nullptr)
            throw exception("List hasn't this element");
    }
    Node<T> *tmpTwo = tmp->next;
    tmp->next = tmpTwo->next;
    delete tmpTwo;
    size_of_list--;
}

template<typename T>
List<T>::~List()
{
    Node<T> *tmp;
    while(begin == nullptr)
    {
        tmp = begin;
        begin = begin->next;
        delete tmp;
    }
}*/