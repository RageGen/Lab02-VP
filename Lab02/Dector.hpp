#ifndef MYVECTOR_H
#define MYVECTOR_H
#include "DectorIterator.hpp"
template <typename T>
class Dector {
public:
	Dector();
	Iterator<T>  begin() const;
	Iterator<T>  end() const;
	size_t size();
	void resize(int index);
	void push_back(const T&);
	void RemoveAt(size_t index);
	T& operator[](int index);
	void memory_up();
private:
	T* m_array{};
	size_t m_size{};
	size_t m_capacity{};
	size_t m_DectorSize{};
	long long int m_DectorCapacity{};
	T* m_DectorStorage;
	T* m_end;
};
template <typename T>
Dector<T>::Dector() {
	m_DectorSize = 0;
	m_DectorCapacity = 1;
	m_DectorStorage = new T[m_DectorCapacity];
	m_end = m_DectorStorage + m_DectorSize;
}
template <typename T>
void Dector<T>::memory_up()
{
	T* TemporaryStorage = new T[m_DectorSize];
	for (int i = 0; i < m_DectorSize; i++)
	{
		TemporaryStorage[i] = m_DectorStorage[i];
	}
	m_DectorCapacity += 16;
	m_DectorStorage = new T[m_DectorCapacity];
	for (int i = 0; i < m_DectorSize; i++)
	{
		m_DectorStorage[i] = TemporaryStorage[i];
	}
	delete[] TemporaryStorage;
}
template <typename T>
Iterator<T> Dector<T>::begin() const {
	return Iterator<T>(m_array);
}
template <typename T>
Iterator<T> Dector<T>::end() const {
	return Iterator<T>(m_array + m_size);
}

template <typename T>
size_t Dector<T>::size() {
	return m_DectorSize;
}
template <typename T>
void Dector<T>::resize(int index)
{
	if (m_DectorSize == 0)
	{
		m_DectorSize = index;
		m_DectorCapacity = index;
		m_DectorStorage = new T[m_DectorCapacity];
		m_end = m_DectorStorage + m_DectorSize;
	}
	else {
		T* TemporaryStorage = new T[index];
		for (int i = 0; i < index; i++)
		{
			TemporaryStorage[i] = m_DectorStorage[i];
		}

		m_DectorSize = index;
		m_DectorCapacity = index;
		m_DectorStorage = new T[m_DectorCapacity];
		m_end = m_DectorStorage + m_DectorSize;
		for (int i = 0; i < index; i++)
		{
			m_DectorStorage[i] = TemporaryStorage[i];
		}
		delete[] TemporaryStorage;
	}
}
template <typename T>
void Dector<T>::push_back(const T& value) {
	if (m_DectorSize >= m_DectorCapacity)
	{
		memory_up();
	}
	m_DectorStorage[m_DectorSize++] = value;
}
template <typename T>
void Dector<T>::RemoveAt(size_t index) {
	for (int i = index; i < m_DectorSize - 1; i++)
	{
		m_DectorStorage[i] = m_DectorStorage[i + 1];
	}
	m_DectorSize--;
	m_end = m_DectorStorage + m_DectorSize;
}
template <typename T>
T& Dector<T>::operator[](int index) {
	return m_DectorStorage[index];
}
#endif