#pragma once

#include <iostream>
#include <stack>
using namespace std;

template <class T>
class StackList
{
public:
	StackList();
	StackList(const StackList<T>& object);
	~StackList();

	StackList<T>& operator=(const StackList<T>& object);
	void push(T value);
	void findMaxAndPush();
	void findAndErase();
	void AddAverage();

	friend ostream& operator<< <T>(ostream& out, const StackList<T>& object);
private:
	stack<T> stk;
};

template<class T>
StackList<T>::StackList() {}

template<class T>
StackList<T>::StackList(const StackList<T>& object)
{
	this->stk = object.stk;
}

template<class T>
StackList<T>::~StackList()
{
	while (!stk.empty())
	{
		stk.pop();
	}
}

template<class T>
StackList<T>& StackList<T>::operator=(const StackList<T>& object)
{
	if (this != &object)
	{
		this->stk = object.stk;
	}
	return *this;
}

template<class T>
void StackList<T>::push(T value)
{
	stk.push(value);
}

template<class T>
void StackList<T>::findMaxAndPush()
{
	cout << "Задача 3" << endl;
	stack<T> temp(this->stk);
	T max = temp.top();
	temp.pop();
	while (!temp.empty())
	{
		if (temp.top() > max) max = temp.top();
		temp.pop();
	}
	this->stk.emplace(max);
	return;
}

template<class T>
void StackList<T>::findAndErase()
{
	cout << "Задача 4" << endl;
	cout << "Введите диапазон значений: ";
	T left, right;
	cin >> left >> right;
	stack<T> temp;
	while (!this->stk.empty())
	{
		if (!(this->stk.top() > left && this->stk.top() < right)) temp.push(this->stk.top());
		this->stk.pop();
	}
	while (!temp.empty())
	{
		this->stk.emplace(temp.top());
		temp.pop();
	}
	return;
}

template<class T>
void StackList<T>::AddAverage()
{
	cout << "Задача 5" << endl;
	stack<T> temp(this->stk);
	T average = T();
	while (!temp.empty())
	{
		average += temp.top();
		temp.pop();
	}
	average /= this->stk.size();
	while (!this->stk.empty())
	{
		temp.emplace(this->stk.top());
		this->stk.pop();
	}
	while (!temp.empty())
	{
		this->stk.push(temp.top());
		this->stk.top() += average;
		temp.pop();
	}
	return;
}

template <class T>
ostream& operator<<(ostream& out, const StackList<T>& object)
{
	cout << "Содержимое списка:" << endl;
	stack<T> temp(object.stk);
	while (!temp.empty())
	{
		cout << temp.top();
		temp.pop();
	}
	cout << endl;
	return out;
}
