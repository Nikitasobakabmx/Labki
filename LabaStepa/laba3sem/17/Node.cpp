/*#include "Node.h"

template<typename T>
Node<T>::Node(const T &item):data(item)
{
    if(next != nullptr)
        delete next;
    next = new Node<T>;
}
/*
template<typename T>
void Node<T>::InsertAfter(Node<T> *p)
{
    if(next == nullptr)
    {
        next = p;
        return;
    }
    Node<T> *tmp = next;
    next = p;
    next->next = tmp;
    return;
}

template<typename T>
Node<T>* Node<T>::DeleteAfter()
{
    if(next == nullptr)
        return nullptr;
    Node<T> *tmp = next->next;
    delete next;
    next = tmp;
    return next;
}

template<typename T>
Node<T>* Node<T>::NextNode() const
{
    return next;
}

template<typename T>
T Node<T>getData()
{
    return data;
}
*/
// template<typename T>
// Node<T>::~Node()
// {
    
// }