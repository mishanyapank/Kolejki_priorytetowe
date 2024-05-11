#pragma once
#ifndef DYNAMIC_ARRAY_PRIORITY_QUEUE_H
#define DYNAMIC_ARRAY_PRIORITY_QUEUE_H

#include <stdexcept>
#include <algorithm>

struct ElementDynamicArray {
    int key;
    int value;
};

class DynamicArrayPQ {
private:
    ElementDynamicArray* elements;
    int size;
    int capacity;

public:
    DynamicArrayPQ(int initCapacity = 2) : size(0), capacity(initCapacity) {
        elements = new ElementDynamicArray[capacity];
    }
    ~DynamicArrayPQ() {
        delete[] elements;
    }

    void insert(ElementDynamicArray elem);
    ElementDynamicArray extractMax();
    ElementDynamicArray findMax();
    void modifyKey(int index, int newKey);
    int returnSize();
    bool isEmpty() const { return size == 0; }
    int getSize() const { return size; }
    void ensureCapacity();
};

#endif
