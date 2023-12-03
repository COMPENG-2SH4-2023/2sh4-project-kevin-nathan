#pragma once

// semi generic array template in a single header
template <typename T> class Array {
private:
  T *data;
  int _size;
  int capacity;
  void ensureCapacity();

public:
  Array();
  ~Array();
  T &get(int i) const;
  void add(T item);
  void remove(int i);
  int size() const;
};

// constructor
template <typename T> Array<T>::Array() {
  this->_size = 0;
  // start with a capacity of 1
  this->capacity = 1;
  this->data = new T[capacity];
}

// destructor
template <typename T> Array<T>::~Array() { delete[] this->data; }

// ensures thta the array has enough capacity to add another item
template <typename T> void Array<T>::ensureCapacity() {
  // if the array is full, double the capacity
  if (this->_size == this->capacity) {
    this->capacity *= 2;
    // create a new array with the new capacity
    T *temp = new T[capacity];
    // copy the old array into the new array
    for (int i = 0; i < this->_size; i++) {
      temp[i] = this->data[i];
    }
    // delete the old array
    delete[] this->data;
    this->data = temp;
  }
}

// returns the size of the array
template <typename T> int Array<T>::size() const { return this->_size; }

// returns the item at the given index
template <typename T> T &Array<T>::get(int i) const { return this->data[i]; }

// removes the item at the given index
template <typename T> void Array<T>::remove(int i) {
  // shift all items after the given index down one
  for (int j = i; j < this->_size - 1; j++) {
    this->data[j] = this->data[j + 1];
  }
  // decrement the size
  this->_size--;
}

// adds an item to the array
template <typename T> void Array<T>::add(T item) {
  // ensure there is enough capacity
  this->ensureCapacity();
  // add the item to the array
  this->data[this->_size] = item;
  // increment the size
  this->_size++;
}
