//metody klasy DynamicArray
#include "DynamicArray.h"

//podwajanie pojemności tablicy
void DynamicArray::doubleCapacity() {
    capacity *= 2;
    Element* newArray = new Element[capacity];
    for (int i = 0; i < size; i++) {
        newArray[i] = array[i];
    }
    delete[] array;
    array = newArray;
}
//dodawanie nowego elementu na końcu tablicy
void DynamicArray::pushBack(Element elem) {
    if (size == capacity) {
        doubleCapacity();
    }
    array[size++] = elem;
}
//przeciążenie umożliwiające dostep do elementów tablicy po ich indeksie
Element& DynamicArray::operator[](int index) {
    return array[index];
}
