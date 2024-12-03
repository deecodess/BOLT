#ifndef Vector_H
#define Vector_H

#include <iostream>
#include <stdexcept>

template <typename T>
class Vector {
private:
    T* data;       
    size_t size;   
    size_t capacity; 

public:
    Vector();      
    Vector(size_t initialCapacity); 
    ~Vector();                

    void push_back(const T& value); 
    void pop_back();                
    T& operator[](size_t index);    
    size_t getSize() const;         
    size_t getCapacity() const;     

private:
    void resize();                 
};


template <typename T>
Vector<T>::Vector() : data(nullptr), size(0), capacity(0) {}

template <typename T>
Vector<T>::Vector(size_t initialCapacity) : size(0), capacity(initialCapacity) {
    data = new T[capacity];
}

template <typename T>
Vector<T>::~Vector() {
    delete[] data;
}

template <typename T>
void Vector<T>::push_back(const T& value) {
    if (size == capacity) {
        resize();
    }
    data[size++] = value;
}

template <typename T>
void Vector<T>::resize() {
    size_t newCapacity = (capacity == 0) ? 1 : capacity * 2;
    T* newData = new T[newCapacity];
    for (size_t i = 0; i < size; ++i) {
        newData[i] = data[i];
    }
    delete[] data;
    data = newData;
    capacity = newCapacity;
}

template <typename T>
void Vector<T>::pop_back() {
    if (size > 0) {
        --size;
    } else {
        throw std::underflow_error("Vector is empty");
    }
}

template <typename T>
T& Vector<T>::operator[](size_t index) {
    if (index >= size) {
        throw std::out_of_range("Index out of range");
    }
    return data[index];
}

template <typename T>
size_t Vector<T>::getSize() const {
    return size;
}

template <typename T>
size_t Vector<T>::getCapacity() const {
    return capacity;
}

#endif
