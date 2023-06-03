#pragma once

#include <iostream>
using namespace std;

template <class T1, class T2>
class Pair
{
public:
	Pair();
	Pair(T1 first, T2 second);
	Pair(const Pair<T1, T2>& object);
	~Pair();

	Pair<T1, T2>& operator=(const Pair<T1, T2>& object);
	bool operator==(const Pair<T1, T2>& object);
	bool operator!=(const Pair<T1, T2>& object);
	bool operator>(const Pair<T1, T2>& object);
	bool operator<(const Pair<T1, T2>& object);
	Pair<T1, T2>& operator+=(const Pair<T1, T2>& object);
	Pair<T1, T2>& operator/=(int value);

	friend ostream& operator<< <T1, T2>(ostream& out, const Pair<T1, T2>& object);
	friend istream& operator>> <T1, T2>(istream& in, Pair<T1, T2>& object);

	T1 first;
	T2 second;	
};

template <class T1, class T2>
Pair<T1, T2>::Pair() : first(T1()), second(T2()) {}

template <class T1, class T2>
Pair<T1, T2>::Pair(T1 first, T2 second) : first(first), second(second) {}

template<class T1, class T2>
Pair<T1, T2>::Pair(const Pair<T1, T2>& object) : first(object.first), second(object.second) {}

template <class T1, class T2>
Pair<T1, T2>::~Pair() {}

template<class T1, class T2>
Pair<T1, T2>& Pair<T1, T2>::operator=(const Pair& object)
{
	if (this != &object)
	{
		this->first = object.first;
		this->second = object.second;
	}
	return *this;
}

template<class T1, class T2>
bool Pair<T1, T2>::operator==(const Pair<T1, T2>& object)
{
	return (this->first == object.first && this->second == object.second);
}

template<class T1, class T2>
bool Pair<T1, T2>::operator!=(const Pair<T1, T2>& object)
{
	return !(*this == object);
}

template<class T1, class T2>
bool Pair<T1, T2>::operator>(const Pair<T1, T2>& object)
{
	return (this->first > object.first && this->second > object.second);
}

template<class T1, class T2>
bool Pair<T1, T2>::operator<(const Pair<T1, T2>& object)
{
	return (this->first < object.first && this->second < object.second);
}

template<class T1, class T2>
Pair<T1, T2>& Pair<T1, T2>::operator+=(const Pair<T1, T2>& object)
{
	this->first += object.first;
	this->second += object.second;
	return *this;
}

template<class T1, class T2>
Pair<T1, T2>& Pair<T1, T2>::operator/=(int value)
{
	this->first /= value;
	this->second /= value;
	return *this;
}

template <class T1, class T2>
ostream& operator<<(ostream& out, const Pair<T1, T2>& object)
{
	out << "first: " << object.first << endl;
	out << "second: " << object.second << endl;
	return out;
}

template <class T1, class T2>
istream& operator>>(istream& in, Pair<T1, T2>& object)
{
	cout << "¬ведите first: ";
	in >> object.first;
	cout << "¬ведите second: ";
	in >> object.second;
	return in;
}
