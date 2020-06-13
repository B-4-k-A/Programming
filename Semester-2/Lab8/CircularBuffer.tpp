#include "CircularBuffer.h"

template <class T>
CircularBuffer<T>::Iterator::Iterator(CircularBuffer<T> *array, size_t curr)
{
    this->cur_ = curr;
    this->array_ = array;
}

template <class T>
T &CircularBuffer<T>::Iterator::operator*()
{
    return (*array_)[cur_];
}

template <class T>
typename CircularBuffer<T>::Iterator &CircularBuffer<T>::
    Iterator::operator++()
{
    cur_ = array_->next(cur_, 1);
    return *this;
}

template <class T>
typename CircularBuffer<T>::Iterator &CircularBuffer<T>::
    Iterator::operator--()
{
    cur_ = array_->prev(cur_, 1);
    return *this;
}

template <class T>
typename CircularBuffer<T>::Iterator &CircularBuffer<T>::
    Iterator::operator+=(int other)
{
    cur_ = array_->next(cur_, other);
    return *this;
}

template <class T>
typename CircularBuffer<T>::Iterator &CircularBuffer<T>::
    Iterator::operator-=(int other)
{
    cur_ = array_->prev(cur_, other);
    return *this;
}

template <class T>
typename CircularBuffer<T>::Iterator CircularBuffer<T>::
    Iterator::operator+(int val) const
{
    return Iterator(array_, array_->next(cur_, val));
}

template <class T>
typename CircularBuffer<T>::Iterator
CircularBuffer<T>::Iterator::operator-(int val) const
{
    return Iterator(array_, array_->prev(cur_, val));
}

template <class T>
typename CircularBuffer<T>::Iterator CircularBuffer<T>::
    Iterator::operator+(
        const CircularBuffer::Iterator &Iterator) const
{
    return Iterator(array_, array_->prev(cur_, Iterator.cur_));
}

template <class T>
ptrdiff_t CircularBuffer<T>::Iterator::operator-(
    const CircularBuffer::Iterator &Iterator) const
{
    return array_->prev(cur_, Iterator.cur_);
}

template <class T>
bool CircularBuffer<T>::Iterator::operator==(
    const CircularBuffer::Iterator &Iterator) const
{
    return cur_ == Iterator.cur_;
}

template <class T>
bool CircularBuffer<T>::Iterator::operator!=(
    const CircularBuffer::Iterator &Iterator) const
{
    return !(*this == Iterator);
}

template <class T>
bool CircularBuffer<T>::Iterator::operator<(
    const CircularBuffer::Iterator &Iterator) const
{
    if ((cur_ < array_->first_ && Iterator.cur_ < array_->first_) ||
        (cur_ >= array_->first_ && Iterator.cur_ >= array_->first_))
    {
        return cur_ < Iterator.cur_;
    }
    else
    {
        return cur_ > Iterator.cur_;
    }
}

template <class T>
bool CircularBuffer<T>::Iterator::operator>(
    const CircularBuffer::Iterator &Iterator) const
{
    return !(*this < Iterator);
}

template <class T>
bool CircularBuffer<T>::Iterator::operator<=(
    const CircularBuffer::Iterator &Iterator) const
{
    return *this == Iterator || *this < Iterator;
}

template <class T>
bool CircularBuffer<T>::Iterator::operator>=(
    const CircularBuffer::Iterator &Iterator) const
{
    return *this == Iterator || *this > Iterator;
}

template <class T>
CircularBuffer<T>::CircularBuffer(size_t cap)
{
    cap_ = cap;
    buf_ = new T[cap_ + 1];
    first_ = 0;
    last_ = 0;
}

template <class T>
CircularBuffer<T>::~CircularBuffer()
{
    delete[] buf_;
}

template <class T>
bool CircularBuffer<T>::empty() const
{
    return first_ == last_;
}

template <class T>
void CircularBuffer<T>::push_back(const T &obj)
{
    if (last_ == (first_ - 1) % (cap_ + 1))
    {
        first_ = (first_ + 1) % (cap_ + 1);
    }
    buf_[last_] = obj;
    last_ = (last_ + 1) % (cap_ + 1);
}

template <class T>
void CircularBuffer<T>::push_front(const T &obj)
{
    if (last_ == (first_ - 1) % (cap_ + 1))
    {
        last_ = (last_ - 1) % (cap_ + 1);
    }
    first_ = (first_ - 1) % (cap_ + 1);
    buf_[first_] = obj;
}

template <class T>
void CircularBuffer<T>::resize(size_t newSize)
{
    T *buf_ = new T[newSize + 1];
    copy(buf_, std::min((last_ - first_) % (cap_ + 1), newSize));
    delete[] buf_;
    buf_ = buf_;
    cap_ = newSize;
    first_ = 0;
    last_ = newSize;
}

template <class T>
void CircularBuffer<T>::pop_back()
{
    if (empty())
    {
        throw std::range_error("buf_ is empty");
    }
    else
    {
        last_ = (last_ - 1) % (cap_ + 1);
    }
}

template <class T>
void CircularBuffer<T>::pop_front()
{
    if (empty())
    {
        throw std::range_error("buf_ is empty");
    }
    else
    {
        first_ = (first_ + 1) % (cap_ + 1);
    }
}

template <class T>
T &CircularBuffer<T>::front() const
{
    return buf_[first_];
}

template <class T>
T &CircularBuffer<T>::back()
{
    return buf_[(last_ - 1) % (cap_ + 1)];
}

template <class T>
T &CircularBuffer<T>::operator[](size_t index)
{
    return buf_[(first_ + index) % (cap_ + 1)];
}

template <class T>
const T &CircularBuffer<T>::operator[](size_t index) const
{
    return buf_[(first_ + index) % (cap_ + 1)];
}

template <class T>
size_t CircularBuffer<T>::size() const
{
    return (last_ - first_) % (cap_ + 1);
}

template <class T>
typename CircularBuffer<T>::Iterator CircularBuffer<T>::begin()
{
    return Iterator(this, 0);
}

template <class T>
typename CircularBuffer<T>::Iterator CircularBuffer<T>::end()
{
    return Iterator(this, last_);
}

template <class T>
typename CircularBuffer<T>::Iterator
CircularBuffer<T>::push_it(const CircularBuffer::Iterator &Iterator, const T &Item)
{
    auto it = Iterator;
    T buf_ = Item;
    last_ = (last_ + 1) % (cap_ + 1);
    for (; it != end(); ++it)
    {
        std::swap(*it, buf_);
    }
    if (last_ == first_)
    {
        first_ = (first_ + 1) % (cap_ + 1);
    }
    return Iterator;
}

template <class T>
void CircularBuffer<T>::pop_it(CircularBuffer::Iterator Iterator)
{
    auto it = end() - 1;
    T buf_ = *it;
    for (; Iterator <= it; --it)
    {
        std::swap(*it, buf_);
    }
    last_ = (last_ -) % (cap_ + 1);
}

template <class T>
size_t CircularBuffer<T>::next(size_t position, int val) const
{
    return (position + val) % (cap_ + 1);
}

template <class T>
size_t CircularBuffer<T>::prev(size_t position, int val) const
{
    return (position - val) % (cap_ + 1);
}

template <class T>
void CircularBuffer<T>::copy(T *array_, size_t newSize) const
{
    for (size_t i = 0; i < newSize; i++)
    {
        array_[i] = (*this)[i];
    }
}

template <class Type>
void print(const CircularBuffer<Type> &buf_)
{
    for (size_t i = 0; i < buf_.size(); i++)
    {
        std::cout << buf_[i] << ' ';
    }
    std::cout << std::endl;
}