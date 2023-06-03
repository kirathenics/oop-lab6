#include <iostream>
#include <ctime>
#include <deque>
#include <stack>
#include "Pair.h"
#include "DequeList.h"
#include "StackList.h"
using namespace std;

template <class Container>
void printContainer(Container& cont);
template <class Adapter>
void printAdapter(Adapter cont);
template <class T>
void findMaxAndPush(deque<T>& deq);
template <class T>
void findMaxAndPush(stack<T>& stk);
template <class T>
void findAndErase(deque<T>& deq);
template <class T>
void findAndErase(stack<T>& stk);
template <class T>
void AddAverage(deque<T>& deq);
template <class T>
void AddAverage(stack<T>& stk);

void task1();
void task2();
void task3();
void task4();
void task5();

int main()
{
	setlocale(0, "");
	srand(time(NULL));

	//task1();
	//task2();
	//task3();
	//task4();
	task5();

	return 0;
}

template <class Container>
void printContainer(Container& cont)
{
	cout << "Содержимое двусторонней очереди:" << endl;
	for (auto it = cont.begin(); it != cont.end(); ++it)
	{
		cout << *it << "";
	}
	cout << endl;
	return;
}

template<class Adapter>
void printAdapter(Adapter adapter)
{
	cout << "Содержимое стека:" << endl;
	while (!adapter.empty())
	{
		cout << adapter.top();
		adapter.pop();
	}
	cout << endl;
}

template <class T>
void findMaxAndPush(deque<T>& deq)
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
void findMaxAndPush(stack<T>& stk)
{
	cout << "Задача 3" << endl;
	stack<T> temp(stk);
	T max = temp.top();
	temp.pop();
	while (!temp.empty())
	{
		if (temp.top() > max) max = temp.top();
		temp.pop();
	}
	stk.push(max);
	return;
}

template <class T>
void findAndErase(deque<T>& deq)
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

template <class T>
void findAndErase(stack<T>& stk)
{
	cout << "Задача 4" << endl;
	cout << "Введите диапазон значений: ";
	T left, right;
	cin >> left >> right;
	stack<T> temp;
	while (!stk.empty())
	{
		if (!(stk.top() > left && stk.top() < right)) temp.push(stk.top());
		stk.pop();
	}
	while (!temp.empty())
	{
		stk.push(temp.top());
		temp.pop();
	}
	return;
}

template <class T>
void AddAverage(deque<T>& deq)
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
void AddAverage(stack<T>& stk)
{
	cout << "Задача 5" << endl;
	stack<T> temp(stk);
	T average = T();
	while (!temp.empty())
	{
		average += temp.top();
		temp.pop();
	}
	average /= stk.size();
	while (!stk.empty())
	{
		temp.push(stk.top());
		stk.pop();
	}
	while (!temp.empty())
	{
		stk.push(temp.top());
		stk.top() += average;
		temp.pop();
	}
	return;
}

void task1()
{
	cout << "Задание 1" << endl;
	cout << "Введите размер двусторонней очереди: ";
	int size;
	cin >> size;
	deque<double> doubleDeque;
	for (int i = 0; i < size; i++)
	{
		doubleDeque.push_back((double)rand() * (200 - 100) / RAND_MAX + 100);
	}
	printContainer(doubleDeque);

	findMaxAndPush(doubleDeque);
	printContainer(doubleDeque);
	findAndErase(doubleDeque);
	printContainer(doubleDeque);
	AddAverage(doubleDeque);
	printContainer(doubleDeque);
	return;
}

void task2()
{
	cout << "Задание 2" << endl;
	cout << "Введите размер двусторонней очереди: ";
	int size;
	cin >> size;
	deque<Pair<int, double>> doubleDeque;
	for (int i = 0; i < size; i++)
	{
		Pair<int, double> temp;
		cin >> temp;
		doubleDeque.push_back(temp);
	}
	printContainer(doubleDeque);

	findMaxAndPush(doubleDeque);
	printContainer(doubleDeque);
	findAndErase(doubleDeque);
	printContainer(doubleDeque);
	AddAverage(doubleDeque);
	printContainer(doubleDeque);
	return;
}

void task3()
{
	cout << "Задание 3" << endl;
	DequeList<Pair<double, int>> deqList(4);
	cin >> deqList;
	cout << deqList;
	deqList.findMaxAndPush();
	cout << deqList;
	deqList.findAndErase();
	cout << deqList;
	deqList.AddAverage();
	cout << deqList;
	return;
}

void task4()
{
	cout << "Задание 4" << endl;
	cout << "Введите количество элементов: ";
	int size;
	cin >> size;
	stack<Pair<int, double>> stk;
	for (int i = 0; i < size; i++)
	{
		Pair<int, double> temp(rand() % 100, (double)rand() * (200 - 100) / RAND_MAX + 100);
		stk.push(temp);
	}
	printAdapter(stk);

	findMaxAndPush(stk);
	printAdapter(stk);
	findAndErase(stk);
	printAdapter(stk);
	AddAverage(stk);
	printAdapter(stk);
	return;
}

void task5()
{
	cout << "Задание 5" << endl;
	cout << "Введите количество элементов: ";
	int size;
	cin >> size;
	StackList<Pair<int, double>> stkList;
	for (int i = 0; i < size; i++)
	{
		Pair<int, double> temp(rand() % 100, (double)rand() * (200 - 100) / RAND_MAX + 100);
		stkList.push(temp);
	}
	cout << stkList;

	stkList.findMaxAndPush();
	cout << stkList;
	stkList.findAndErase();
	cout << stkList;
	stkList.AddAverage();
	cout << stkList;
	return;
}