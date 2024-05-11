#pragma once
#ifndef HEAP_H
#define HEAP_H

#include "DynamicArray.h"

class Heap {
private:
    DynamicArray data;

    void heapify(int index);
    void bubbleUp(int index);
    int parent(int index) { return (index - 1) / 2; }
    int left(int index) { return 2 * index + 1; }
    int right(int index) { return 2 * index + 2; }

public:
    Heap() {}
    void insert(Element elem);
    Element extractMax();
    Element findMax() ;
    void modifyKey(int index, int newKey);
    int returnSize();
    bool isEmpty() { return data.isEmpty(); }
};

#endif