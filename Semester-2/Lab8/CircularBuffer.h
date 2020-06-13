#pragma once

#include <exception>
#include <iterator>


template <class T>
class CircularBuffer
{
public:
    class Iterator : public std::iterator<std::random_access_iterator_tag, T>
    {
    public:
        Iterator(CircularBuffer<T> *, size_t);
        T &operator*();
        Iterator operator+(int) const;
        Iterator operator+(const Iterator &) const;
        Iterator operator-(int) const;
        ptrdiff_t operator-(const Iterator &) const;
        Iterator &operator++();
        Iterator &operator+=(int);
        Iterator &operator--();
        Iterator &operator-=(int);

        bool operator==(const Iterator &) const;
        bool operator!=(const Iterator &) const;
        bool operator<(const Iterator &) const;
        bool operator>(const Iterator &) const;
        bool operator<=(const Iterator &) const;
        bool operator>=(const Iterator &) const;

    private:
        size_t cur_;
        CircularBuffer<T> *array_;
    };

    explicit CircularBuffer(size_t);
    ~CircularBuffer();

    size_t size() const;
    void resize(size_t);
    bool empty() const;

    void push_front(const T &);
    void push_back(const T &);
    Iterator push_it(const Iterator &, const T &);

    void pop_back();
    void pop_front();
    void pop_it(Iterator);

    T &front() const;
    T &back();

    T &operator[](size_t);
    const T &operator[](size_t) const;

    Iterator begin();
    Iterator end();

private:
    T *buf_;
    size_t cap_, first_, last_;
    size_t next(size_t, int) const;
    size_t prev(size_t, int) const;
    void copy(T *, size_t) const;
};

#include "CircularBuffer.tpp"
