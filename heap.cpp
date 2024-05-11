#include "heap.h"
#include <algorithm>  // dla std::swap

void Heap::insert(Element elem) {
    data.pushBack(elem);
    int i = data.getSize() - 1;
    while (i != 0 && data[parent(i)].key < data[i].key) {
        std::swap(data[i], data[parent(i)]);
        i = parent(i);
    }
}

Element Heap::extractMax() {
    if (data.isEmpty())
        throw std::runtime_error("Heap is empty");

    Element max = data[0];
    data[0] = data[data.getSize() - 1];
    data.setSize(data.getSize() - 1);
    heapify(0);
    return max;
}

Element Heap::findMax()  {
    if (data.isEmpty())
        throw std::runtime_error("Heap is empty");
 
    return data[0]; 
}

void Heap::heapify(int index) {
    int l = left(index);
    int r = right(index);
    int largest = index;
    if (l < data.getSize() && data[l].key > data[largest].key)
        largest = l;
    if (r < data.getSize() && data[r].key > data[largest].key)
        largest = r;
    if (largest != index) {
        std::swap(data[index], data[largest]);
        heapify(largest);
    }
}

void Heap::bubbleUp(int index) {
    while (index != 0 && data[parent(index)].key < data[index].key) {
        std::swap(data[index], data[parent(index)]);
        index = parent(index);
    }
}

void Heap::modifyKey(int index, int newKey) {
    if (index < 0 || index >= data.getSize())
        throw std::runtime_error("Index out of bounds");

    int oldKey = data[index].key;
    data[index].key = newKey;
    if (newKey > oldKey) {
        bubbleUp(index);
    }
    else {
        heapify(index);
    }
}

int Heap::returnSize() {
    return data.getSize();  
}