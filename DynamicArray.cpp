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
    if (index < 0 || index >= size) {
        std::cerr << "Index out of bounds" << std::endl;
        exit(1);
    }
    return array[index];
}