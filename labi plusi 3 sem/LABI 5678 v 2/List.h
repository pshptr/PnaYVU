#pragma once
#include <iostream>
using namespace std;
template<typename T>//��������� ������ ������ ����������� � .h
class List
{
public:
	class iterator;
	List();
	~List();
	iterator begin();
	iterator end();
	void push_back(T data);
	void push_front(T data);
	int GetSize();
	T& operator[] (const int index);//������� �� �������
	void pop_front();//������� ������ ������� ������
	void clear();//������� ������
	void insert(T value, int index);
	void removeAt(int index);//�������� �������� �� ��. �������
	void popback();
private:
	template<typename T>
	class Node //����
	{
	public:

		Node* pNext;
		T data;
		Node(T data = T(), Node* pNext = nullptr)//pNext=nullptr ��� ���������� �������� � ������; data=T()-��������� ����������� �� ��������� ���� �����, ��� �������� �� ��������� ���� ���� ������ , ������� �������
		{
			this->data = data;
			this->pNext = pNext;
		}
	};
	int Size;
	Node<T>* head;
};
template <typename T>
class List<T>::iterator
{
public:
	iterator(Node<T>* pointer) :m_pointer(pointer) {}

	T& operator*() const;

	iterator& operator++();
	iterator operator++(int);

	bool operator==(const iterator& other) const;
	bool operator!=(const iterator& other) const;

private:
	Node<T>* m_pointer;
};
template <typename T>
typename List<T>::iterator List<T>::begin()
{
	return List::iterator(head);
}

template <typename T>
typename List<T>::iterator List<T>::end()
{
	return List::iterator(nullptr);
}
template<typename T>
T& List<T>::iterator::operator*() const
{
	return m_pointer->data;
}

template<typename T>
typename List<T>::iterator& List<T>::iterator::operator++()
{
	m_pointer = m_pointer->next;
	return *this;
}

template<typename T>
typename List<T>::iterator List<T>::iterator::operator++(int)
{
	iterator tmp = *this;
	m_pointer = m_pointer->pNext;
	return tmp;
}
template<typename T>
bool List<T>::iterator::operator==(const List<T>::iterator& other) const
{
	return m_pointer == other.m_pointer;
}

template<typename T>
bool List<T>::iterator::operator!=(const List<T>::iterator& other) const
{
	return m_pointer != other.m_pointer;
}
template<typename T>
inline List<T>::List()
{
	Size = 0;
	head = nullptr;
}

template<typename T>
List<T>::~List()
{
	clear();
}

template<typename T>
void List<T>::push_back(T data)
{
	if (head == nullptr)
	{
		head = new Node<T>(data);
	}
	else
	{
		Node<T>* current = this->head;//��������� �� ������ ������ 
		while (current->pNext != nullptr)//���� ��������� ������� 
		{
			current = current->pNext;

		}
		current->pNext = new Node<T>(data);
	}
	Size++;
}

template<typename T>
inline int List<T>::GetSize()
{
	return Size;
}

template<typename T>
inline T& List<T>::operator[](const int index)
{
	int counter=0;
	Node<T>* current = this->head;
	while (current != nullptr)
	{
		if (counter == index)
		{
			return current->data;
		}
		current = current->pNext;
		counter++;
	}
	// TODO: �������� ����� �������� return
}

template<typename T>
inline void List<T>::pop_front()
{
	Node<T> *temp = head;
	head = head->pNext;
	delete temp;
	Size--;
}

template<typename T>
inline void List<T>::clear()
{
	while (Size)
	{
		pop_front();
	}
}

template<typename T>
inline void List<T>::push_front(T data)
{
	head = new Node<T>(data,head);
	Size++;
}

template<typename T>
inline void List<T>::insert(T value, int index)
{
	if (index == 0 || index>Size)
	{
		push_back(value);
	}
	else
	{
		Node<T>* previous = this->head;
		for (int i = 0; i < index - 1; i++)
		{
			previous = previous->pNext;
		}
		Node<T>* newNode = new Node<T>(value, previous->pNext);
		previous->pNext = newNode;
		Size++;
	}
	
}

template<typename T>
inline void List<T>::removeAt(int index)
{
	if (index == 0)
	{
		pop_front();
	}
	else
	{
		Node<T>* previous = this->head;
		for (int i = 0; i < index - 1; i++)
		{
			previous = previous->pNext;
		}
		Node<T>* toDelete = previous->pNext;
		previous->pNext = toDelete->pNext;
		delete toDelete;
	}
	Size--;

}

template<typename T>
inline void List<T>::popback()
{
	removeAt(Size - 1);
}

