//Source.cpp
#include <iostream>
#include <string>
using namespace std;
template <class T>
class Sampler
{
	T* v;
	int size;
public:
	Sampler(int newsize);
	Sampler(Sampler&);
	~Sampler();
	T& operator [] (int index); // індексування
	Sampler& operator = (const Sampler&); // присвоєння
	friend istream& operator >> <>(istream&, Sampler&);
};
template <class T>
Sampler<T>::Sampler(int newsize)
{
	v = new T[size = newsize];
	for (int i = 0; i < size; i++)
		v[i] = T();
}
template <class T>
Sampler<T>::Sampler(Sampler<T>& x)
{
	v = new T[size = x.size];
	for (int i = 0; i < size; i++)
		v[i] = x.v[i];
}
template <class T>
Sampler<T>::~Sampler()
{
	delete[] v;
}
template <class T>
T& Sampler<T>::operator [] (int index)
{
	if (index < 0 || index >= size)
	{
		throw exception("Index out of the range");
	}
	return v[index];
}
template <class T>
Sampler<T>& Sampler<T>::operator = (const Sampler<T>& x)
{
	if (this != &x)
	{
		delete[] v;
		v = new T[size = x.size];
		for (int i = 0; i < size; i++)
			v[i] = x.v[i];
	}
	return *this;
}
template <class T>
istream& operator >> (istream& is, Sampler<T>& x)
{
	cout << "Input " << x.size << " elements of massif" << endl;
	for (int i = 0; i < x.size; i++)
	{
		cout << "element[" << i << "] = ? "; is >> x.v[i];
	}
	return is;
}
template <class T>
ostream& operator << (ostream& os, Sampler<T>& x)
{
	for (int i = 0; i < x.size; i++)
		os << x.v[i] << ' ';
	os << endl;
	return os;
}
int main()
{
	try
	{
		Sampler<int> V(10), U(5);
		cin >> V;
		cin >> U;
	}
	catch (exception e)
	{
		cerr << e.what() << endl;
	}
	return 0;
}
