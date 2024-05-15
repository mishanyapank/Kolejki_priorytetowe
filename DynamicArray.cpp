#include "DynamicArray.h"

void DynamicArray::doubleCapacity() {
    capacity *= 2;
    Element* newArray = new Element[capacity];
    for (int i = 0; i < size; i++) {
        newArray[i] = array[i];
    }
    delete[] array;
    array = newArray;
}

void DynamicArray::pushBack(Element elem) {
    if (size == capacity) {
        doubleCapacity();
    }
    array[size++] = elem;
}

Element& DynamicArray::operator[](int index) {
    return array[index];
}
