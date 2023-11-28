#ifndef LB6_MYCONTAINER_H
#define LB6_MYCONTAINER_H

#include <iostream>
using namespace std;

template <class T>
struct Node
{
    T data;
    Node<T>* previous;
    Node<T>* next;
};

template <class T>
class List
{
private:
    Node<T> *head = nullptr;
    Node<T> *tail = nullptr;
    int amount = 0;
public:
    List() {};
    ~List();
    int size();
    void push(T&);
    T pop();
    T& operator[](int);
    Node<T>* begin();
    Node<T>* end();

};

template<class T>
void List<T>::push(T& obj)
{
    if (head == nullptr)
    {
        head = new Node<T>;
        head->data = obj;
        head->next = nullptr;
        head->previous = nullptr;
        tail = head;
        amount++;
    }
    else
    {
        Node<T> *node = new Node<T>;
        node->data = obj;
        node->next = head;
        node->previous = nullptr;
        head->previous = node;
        head = node;
        amount++;
    }
}

template<class T>
int List<T>::size(){
    return this->amount;
}

template<class T>
T List<T>::pop()
{
    if (!(head)) return T();
    T data = head->data;
    Node<T>* node = head;
    if (head != tail)
    {
        head = head->next;
        head->previous = nullptr;
    }
    else
    {
        head = tail = nullptr;
    }
    delete node;
    amount--;
    return data;
}

template<class T>
T& List<T>::operator[](int num)
{
    Node<T> *curr = head;
    if (num < 0 || num >= amount) return curr->data;
    for (int i = 0; i < num; i++)
    {
        curr = curr->next;
    }
    return curr->data;
}

template<class T>
Node<T>* List<T>::begin()
{
    return head;
}

template<class T>
Node<T>* List<T>::end()
{
    return tail;
}

template<class T>
List<T>::~List()
{
    while (this->head)
    {
        this->pop();
    }
}

#endif //LB6_MYCONTAINER_H
