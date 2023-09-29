#pragma once
#include "iostream"
template <typename T>
class  Vector {
public:
	Vector();
	typedef T * iterator;
	Vector(const Vector<T>& v);
	~Vector();
	//geters
	unsigned int capacity() const;
	unsigned int size() const;
	bool empty() const;
	T& front();
	T& back();
	iterator begin();
	iterator end();
	void push_back(const T& value);
	void pop_back();
	void reserve(unsigned int capacity);
	T & operator[](unsigned int index);
	T &  operator[](unsigned int index)const ;
	void clear();
	Vector<T> & operator = (const Vector<T> &);
private:
	unsigned int size_;
	unsigned int capacity_;
	T* buffer;
};

template<class T>
Vector<T>::Vector() {
	capacity_ = 0;
	size_ = 0;
	buffer = nullptr;
}

template<class T>
Vector<T>::~Vector() {
	if (this->capacity_)
		delete[] buffer;
}
template<class T>
Vector<T>::Vector(const Vector<T> & v) {
	size_ = v.size_;
	this->capacity_ = v.capacity_;
	if (this->buffer)
	{
		delete[] buffer;
	}
	buffer = new T[this->capacity_];
	for (unsigned int i = 0; i < size_; i++)
		buffer[i] = v.buffer[i];
}
template<class T>
void Vector<T>::reserve(unsigned int capacity) {
	T * newBuffer = new T[capacity];
	for (int i = 0; i < this->size_; i++)
		newBuffer[i] = buffer[i];
	this->capacity_ = capacity;
	delete[] buffer;
	buffer = newBuffer;
}

template<class T>
void Vector<T>::push_back(const T & v) {
	if (this->size_ >= this->capacity_) {
		if (!this->capacity_)
		{
			this->capacity_ = 1;
		}
		reserve(2 * capacity_);
	}
	buffer[size_++] = v;
}

template<class T>
void Vector<T>::pop_back() {// at the end we delete vector at size capacity
	size_--;
}
template<class T>
T& Vector<T>::front() {
	return buffer[0];
}

template<class T>
T& Vector<T>::back() {
	return buffer[this->size_ - 1];
}

template<class T>
typename Vector<T>::iterator Vector<T>::end() {
	return buffer + size_;
}

template<class T>
typename Vector<T>::iterator Vector<T>::begin() {
	return buffer;
}
template <class T>
bool Vector<T>::empty() const {
	return size_ == 0;
}

template<class T>
Vector<T>& Vector<T>::operator = (const Vector<T> & v) {
	if (buffer)
		delete[] buffer;
	this->size_ = v.size_;
	this->capacity_ = v.capacity_;
	buffer = new T[this->capacity_];
	for (unsigned int i = 0; i < this->size_; i++)
		buffer[i] = v.buffer[i];
	return *this;
}
template<class T>
unsigned int Vector<T>::size() const {
	return size_;
}

template<class T>
T& Vector<T>::operator[](unsigned int index) {
	return buffer[index];
}
template<class T>
 T& Vector<T>::operator[](unsigned int index)const  {
	return buffer[index];
}

template<class T>
void Vector<T>::clear() {// at the end we delete vector at size capacity
	if (buffer != nullptr)
		delete[] buffer;
	this->size_ = 0;
	this->capacity_ = 0;
}

template<class T>
unsigned int Vector<T>::capacity()const {
	return this->capacity_;
}
