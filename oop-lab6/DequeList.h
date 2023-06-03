#pragma once

#include <iostream>
#include <deque>
using namespace std;

template <class T>
class DequeList
{
public:
	DequeList();
	DequeList(int size);
	DequeList(const DequeList<T>& object);
	~DequeList();

	DequeList<T>& operator=(const DequeList<T>& object);
	void findMaxAndPush();
	void findAndErase();
	void AddAverage();

	friend ostream& operator<< <T>(ostream& out, const DequeList<T>& object);
	friend istream& operator>> <T>(istream& in, DequeList<T>& object);
private:
	deque<T> deq;
};

template<class T>
DequeList<T>::DequeList()
{
	this->deq = deque<T>(0);
}

template<class T>
DequeList<T>::DequeList(int size)
{
	this->deq = deque<T>(size);
}

template<class T>
DequeList<T>::DequeList(const DequeList<T>& object)
{
	this->deq = object.deq;
}

template<class T>
DequeList<T>::~DequeList()
{
	deq.clear();
}

template<class T>
DequeList<T>& DequeList<T>::operator=(const DequeList<T>& object)
{
	if (this != &object)
	{
		this->deq = object.deq;
	}
	return *this;
}

template<class T>
void DequeList<T>::findMaxAndPush()
{
	cout << "Задача 3" << endl;
	T max = *deq.begin();
	for (auto it = deq.begin(); it != deq.end(); ++it)
	{
		if (*it > max) max = *it;
	}
	deq.push_back(max);
	return;
}

template<class T>
void DequeList<T>::findAndErase()
{
	cout << "Задача 4" << endl;
	cout << "Введите диапазон значений: ";
	T left, right;
	cin >> left >> right;
	for (auto it = deq.begin(); it != deq.end(); )
	{
		if (*it > left && *it < right)
		{
			it = deq.erase(it);
		}
		else
		{
			++it;
		}
	}
	return;
}

template<class T>
void DequeList<T>::AddAverage()
{
	cout << "Задача 5" << endl;
	T average = T();
	for (auto it = deq.begin(); it != deq.end(); ++it)
	{
		average += *it;
	}
	average /= deq.size();
	for (auto it = deq.begin(); it != deq.end(); ++it)
	{
		*it += average;
	}
	return;
}

template <class T>
ostream& operator<<(ostream& out, const DequeList<T>& object)
{
	out << "Содержимое списка:" << endl;
	for (auto it = object.deq.begin(); it != object.deq.end(); ++it)
	{
		cout << *it << "";
	}
	out << endl;
	return out;
}

template <class T>
istream& operator>>(istream& in, DequeList<T>& object)
{
	cout << "Введите элементы списка:" << endl;
	for (auto it = object.deq.begin(); it != object.deq.end(); ++it)
	{
		in >> *it;
	}
	return in;
}
