#ifndef ITERATOR_H
#define ITERATOR_H
template <typename T>
class Iterator {
	template <typename V>
	friend class Dector;
public:
	Iterator(const Iterator<T>&);
	bool operator==(const Iterator<T>&) const;
	bool operator!=(const Iterator<T>&) const;
	Iterator<T>& operator++();
	T& operator*() const;

private:
	T* m_data;
	Iterator(T* p) : m_data(p) {};
};

template <typename T>
Iterator<T>::Iterator(const Iterator& it) : m_data(it.m_data) {}

template <typename T>
bool Iterator<T>::operator==(const Iterator<T>& it) const {
	return m_data == it.m_data;
}
template <typename T>
bool Iterator<T>::operator!=(const Iterator<T>& it) const {
	return m_data != it.m_data;
}
template <typename T>
Iterator<T>& Iterator<T>::operator++() {
	m_data++;
	return *this;
}
template <typename T>
T& Iterator<T>::operator*() const {
	return *m_data;
}
#endif