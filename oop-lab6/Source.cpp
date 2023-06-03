#include <iostream>
#include <ctime>
#include <deque>
using namespace std;

template <class Container>
void printContainer(Container& cont);
template <class T>
void findMaxAndPush(deque<T>& deq);
template <class T>
void findAndErase(deque<T>& deq);
template <class T>
void AddAverage(deque<T>& deq);

void task1();
void task2();

int main()
{
	setlocale(0, "");
	srand(time(NULL));

	task1();

	return 0;
}

template <class Container>
void printContainer(Container& cont)
{
	cout << "Содержимое двусторонней очереди:" << endl;
	for (auto it = cont.begin(); it != cont.end(); ++it)
	{
		cout << *it << " ";
	}
	cout << endl;
	return;
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
