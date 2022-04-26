#pragma once
template <typename T>
class Dector 
{
public:
	Dector()
	{
		m_DectorSize = 0;
		m_DectorCapacity = 1;
		m_DectorStorage = new T[m_DectorCapacity];
	}
	void resize(int index)
	{
			T* TemporaryStorage = new T[index];
			for (int i = 0; i < index; i++)
			{
				TemporaryStorage[i] = m_DectorStorage[i];
			}

			m_DectorSize = index;
			m_DectorCapacity = index;
			m_DectorStorage = new T[m_DectorCapacity];
			for (int i = 0; i < index; i++)
			{
				m_DectorStorage[i] = TemporaryStorage[i];
			}
			delete[] TemporaryStorage;
	}
	bool Empty()
	{
		if (size() == 0)
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
	T &operator[] (int index) const
	{
		return m_DectorStorage[index];
	}
	void push_back(T value) 
	{
		if (m_DectorSize >= m_DectorCapacity)
		{
			memory_up();
		}
		m_DectorStorage[m_DectorSize++] = value;
	}
private:
	long long int m_DectorSize{};
	long long int m_DectorCapacity{};
	T* m_DectorStorage;
	void memory_up()
	{
		T* TemporaryStorage = new T[m_DectorSize];
		for (int i = 0; i < m_DectorSize; i++)
		{
			TemporaryStorage[i] = m_DectorStorage[i];
		}
		m_DectorCapacity += 16;
		m_DectorStorage = new T[m_DectorCapacity];
		for (int i=0;i<m_DectorSize;i++)
		{
			m_DectorStorage[i] = TemporaryStorage[i];
		}
		delete[] TemporaryStorage;
	}
};
