#pragma once
class VectorIterator {
	friend class MyVector;
public:
	VectorIterator(const VectorIterator& _it) : m_data(_it.m_data)
	{}
	bool operator==(const VectorIterator& _it) const {
		return m_data == _it.m_data;
	}
	bool operator!=(const VectorIterator& _it) const {
		return m_data != _it.m_data;
	}
	VectorIterator& operator++() {
		m_data++;
		return *this;
	}
	Student& operator*() const {
		return *m_data;
	}
	VectorIterator(Student* _p) : m_data(_p) {}
private:
	Student* m_data;
};

class Dector 
{
public:
	typedef VectorIterator iterator;
	typedef VectorIterator const_iterator;
	Dector()
	{
		m_DectorSize = 0;
		m_DectorCapacity = 1;
		m_DectorStorage = new Student[m_DectorCapacity];
	}
	void resize(int index)
	{
		if (m_DectorSize == 0)
		{
			m_DectorSize = index;
			m_DectorCapacity = index;
			m_DectorStorage = new Student[m_DectorCapacity];
		}
		else {
			Student* TemporaryStorage = new Student[index];
			for (int i = 0; i < index; i++)
			{
				TemporaryStorage[i] = m_DectorStorage[i];
			}

			m_DectorSize = index;
			m_DectorCapacity = index;
			m_DectorStorage = new Student[m_DectorCapacity];
			for (int i = 0; i < index; i++)
			{
				m_DectorStorage[i] = TemporaryStorage[i];
			}
			delete[] TemporaryStorage;
		}
	}
	bool Empty()
	{
		if (m_DectorSize == 0)
		{
			return true;
		}
		else
		{
			false;
		}
	}
	void RemoveAt(int index)
	{
		for (int i = index; i < m_DectorSize-1; i++)
		{
			m_DectorStorage[i] = m_DectorStorage[i + 1];
		}
		m_DectorSize--;
	}
	int size()
	{
		return m_DectorSize;
	}
	Student&operator[] (int index) const
	{
		return m_DectorStorage[index];
	}
	void push_back(Student value)
	{
		if (m_DectorSize >= m_DectorCapacity)
		{
			memory_up();
		}
		m_DectorStorage[m_DectorSize++] = value;
	}
	iterator begin() {
		return iterator(m_DectorStorage);
	}
	iterator end() {
		return iterator(m_end);
	}
	const_iterator begin() const {
		return const_iterator(m_DectorStorage);
	}
	const_iterator end() const {
		return const_iterator(m_end);
	}
private:
	 size_t m_DectorSize{};
	long long int m_DectorCapacity{};
	 Student* m_DectorStorage;
	Student* m_end;
	void memory_up()
	{
		Student* TemporaryStorage = new Student[m_DectorSize];
		for (int i = 0; i < m_DectorSize; i++)
		{
			TemporaryStorage[i] = m_DectorStorage[i];
		}
		m_DectorCapacity += 16;
		m_DectorStorage = new Student[m_DectorCapacity];
		for (int i=0;i<m_DectorSize;i++)
		{
			m_DectorStorage[i] = TemporaryStorage[i];
		}
		delete[] TemporaryStorage;
	}

};
