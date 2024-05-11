#include "DynamicArrayPriorityQueue.h"
#include <algorithm>

void DynamicArrayPQ::ensureCapacity() {
    if (size >= capacity) {
        capacity *= 2;
        ElementDynamicArray* newElements = new ElementDynamicArray[capacity];
        for (int i = 0; i < size; i++) {
            newElements[i] = elements[i];
        }
        delete[] elements;
        elements = newElements;
    }
}

void DynamicArrayPQ::insert(ElementDynamicArray elem) {
    ensureCapacity();
    elements[size++] = elem;
    std::sort(elements, elements + size, [](const ElementDynamicArray& a, const ElementDynamicArray& b) {
        return a.key > b.key; 
        });
}

ElementDynamicArray DynamicArrayPQ::extractMax() {
    if (isEmpty()) {
        throw std::runtime_error("Array is empty");
    }
    ElementDynamicArray maxElement = elements[0];
    for (int i = 1; i < size; i++) {
        elements[i - 1] = elements[i];
    }
    size--;
    return maxElement;
}

ElementDynamicArray DynamicArrayPQ::findMax() {
    if (isEmpty()) {
        throw std::runtime_error("Array is empty");
    }
    return elements[0];
}

void DynamicArrayPQ::modifyKey(int index, int newKey) {
    if (index < 0 || index >= size) {
        throw std::runtime_error("Index out of bounds");
    }
    elements[index].key = newKey;
    std::sort(elements, elements + size, [](const ElementDynamicArray& a, const ElementDynamicArray& b) {
        return a.key > b.key; 
        });
}

int DynamicArrayPQ::returnSize() {
    return size;
}