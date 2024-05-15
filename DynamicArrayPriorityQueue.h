#ifndef DYNAMIC_ARRAY_PRIORITY_QUEUE_H
#define DYNAMIC_ARRAY_PRIORITY_QUEUE_H

#include <iostream>
#include <random>
#include <fstream>
#include <string>
#include <chrono>
#include <conio.h>
#include <stdexcept>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

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
        clear();
    }

    void insert(ElementDynamicArray elem);
    ElementDynamicArray extractMax();
    ElementDynamicArray findMax();
    void modifyKey(int index, int newKey);
    int returnSize();
    bool isEmpty() const { return size == 0; }
    int getSize() const { return size; }
    void ensureCapacity();
    void displayinsert(ElementDynamicArray elem);
    void displayMax();
    void displaySize();
    void clear();
};

