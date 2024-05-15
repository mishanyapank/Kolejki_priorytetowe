#include "DynamicArrayPriorityQueue.h"


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
    sort(elements, elements + size, [](const ElementDynamicArray& a, const ElementDynamicArray& b) {
        return a.key > b.key;
        });
}
void DynamicArrayPQ::displayinsert(ElementDynamicArray elem) {
    for (int i = 0; i < size; ++i) {
        cout << elements[i].value << "(" << elements[i].key << ")" << " ";
    }
    cout << endl;
}

ElementDynamicArray DynamicArrayPQ::extractMax() {
    if (isEmpty()) {
        throw runtime_error("kolejka jest pusta");
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
        throw runtime_error("kolejka jest pusta");
    }
    return elements[0];
}
void DynamicArrayPQ::displayMax() {
    const ElementDynamicArray& maxElement = elements[0];
    cout << maxElement.value << "(" << maxElement.key << ")" << endl;
}

void DynamicArrayPQ::modifyKey(int index, int newKey) {
    if (index < 0 || index >= size) {
        throw runtime_error("index poza zakresem");
    }
    elements[index].key = newKey;
    sort(elements, elements + size, [](const ElementDynamicArray& a, const ElementDynamicArray& b) {
        return a.key > b.key;
        });
}

int DynamicArrayPQ::returnSize() {
    return size;
}
void DynamicArrayPQ::displaySize() {
    cout << "Rozmiar kolejki: " << returnSize() << endl;
}
void DynamicArrayPQ::clear() {
    if (elements != nullptr) {
        delete[] elements;
        elements = nullptr;
    }
    size = 0;
}
