#include <iostream>
using namespace std;
#pragma region class_Pair_and_input/output
class Pair {
public:
	Pair(int _x = 0, int _y = 0) : x(_x), y(_y) {};
	friend ostream& operator<<(ostream&, const Pair);
	friend istream& operator>>(istream&, Pair&);
private:
	int x, y;
};
ostream& operator<<(ostream& out, const Pair obj) {
	out << "x: " << obj.x << ", y : " << obj.y << ".\n";
	return out;
}
istream& operator>>(istream& in, Pair& obj) {
	cout << "enter x -> ";
	in >> obj.x;
	cout << "enter y -> ";
	in >> obj.y;
	return in;
}
#pragma endregion
#pragma region VectorIterator
class VectorIterator {
	friend class MyVector;
public:
	VectorIterator(const VectorIterator& _it) : m_pair(_it.m_pair)
	{}
	bool operator==(const VectorIterator& _it) const {
		return m_pair == _it.m_pair;
	}
	bool operator!=(const VectorIterator& _it) const {
		return m_pair != _it.m_pair;
	}
	VectorIterator& operator++() {
		m_pair++;
		return *this;
	}
	Pair& operator*() const {
		return *m_pair;
	}
private:
	Pair* m_pair;
	VectorIterator(Pair* _p) : m_pair(_p) {}
};
#pragma endregion
#pragma region class_MyVector
class MyVector {
public:
	typedef VectorIterator iterator;
	typedef VectorIterator const_iterator;
	MyVector() : m_array(nullptr), m_end(nullptr), m_size(0) {}
	MyVector(unsigned _size) : m_size(_size) {
		m_array = new Pair[m_size];
		if (m_size) {
			Pair _temp;
			for (int i = 0; i < m_size; ++i) {
				m_array[i] = _temp;
			}
		}
		m_end = m_array + m_size;
	}
	MyVector(unsigned _size, Pair _value) : m_size(_size) {
		m_array = new Pair[m_size];
		if (m_size) {
			m_array[0] = _value;
			Pair _temp;
			for (int i = 1; i < m_size; ++i) {
				m_array[i] = _temp;
			}
		}
		m_end = m_array + m_size;
	}
		iterator begin() {
		return iterator(m_array);
	}
	iterator end() {
		return iterator(m_end);
	}
	const_iterator begin() const {
		return const_iterator(m_array);
	}
	const_iterator end() const {
		return const_iterator(m_end);
	}
	friend ostream& operator<<(ostream&, const MyVector);
private:
	Pair* m_array{};
	Pair* m_end;
	size_t m_size{};
};
ostream& operator<<(ostream& out, const MyVector obj) {
	for (int i = 0; i < obj.m_size; i++) {
		out << obj.m_array[i];
	}
	out << "\n";
	return out;
}
#pragma endregion
int main() {
	Pair p1(1, 2), p2(3, 4);
	cout << p1 << p2;
	Pair p3;
	cout << p3;
	cin >> p3;
	cout << p3;
	MyVector v1, v2(3), v3(3, p1);
	cout << "My vector v1 is:\n";
	cout << v1;
	cout << "My vector v2 is:\n";
	cout << v2;
	cout << "My vector v3 is:\n";
	cout << v3;
	cout << "Iterator works:\n";
	for (Pair p : v3) {
		cout << p;
	}
	return 0;
}