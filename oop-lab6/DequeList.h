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
	deque<T> stk;
};

template<class T>
DequeList<T>::DequeList()
{
	this->stk = deque<T>(0);
}

template<class T>
DequeList<T>::DequeList(int size)
{
	this->stk = deque<T>(size);
}

template<class T>
DequeList<T>::DequeList(const DequeList<T>& object)
{
	this->stk = object.stk;
}

template<class T>
DequeList<T>::~DequeList()
{
	stk.clear();
}

template<class T>
DequeList<T>& DequeList<T>::operator=(const DequeList<T>& object)
{
	if (this != &object)
	{
		this->stk = object.stk;
	}
	return *this;
}

template<class T>
void DequeList<T>::findMaxAndPush()
{
	cout << "Задача 3" << endl;
	T max = *stk.begin();
	for (auto it = stk.begin(); it != stk.end(); ++it)
	{
		if (*it > max) max = *it;
	}
	stk.push_back(max);
	return;
}

template<class T>
void DequeList<T>::findAndErase()
{
	cout << "Задача 4" << endl;
	cout << "Введите диапазон значений: ";
	T left, right;
	cin >> left >> right;
	for (auto it = stk.begin(); it != stk.end(); )
	{
		if (*it > left && *it < right)
		{
			it = stk.erase(it);
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
	for (auto it = stk.begin(); it != stk.end(); ++it)
	{
		average += *it;
	}
	average /= stk.size();
	for (auto it = stk.begin(); it != stk.end(); ++it)
	{
		*it += average;
	}
	return;
}

template <class T>
ostream& operator<<(ostream& out, const DequeList<T>& object)
{
	out << "Содержимое списка:" << endl;
	for (auto it = object.stk.begin(); it != object.stk.end(); ++it)
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
	for (auto it = object.stk.begin(); it != object.stk.end(); ++it)
	{
		in >> *it;
	}
	return in;
}
