#include "Dector.hpp"
#include "Student.hpp"
class VectorIterator {
	friend class Dector;
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
