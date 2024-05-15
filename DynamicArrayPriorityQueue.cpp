#include "DynamicArrayPriorityQueue.h"

//metoda podwaja rozmiar tablicy
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
//metoda dodaje nowy element do tablicy po czym wykonuje sortowanie malejące według klucza
void DynamicArrayPQ::insert(ElementDynamicArray elem) {
    ensureCapacity();
    elements[size++] = elem;
    sort(elements, elements + size, [](const ElementDynamicArray& a, const ElementDynamicArray& b) {
        return a.key > b.key;
        });
}
//metoda wyswietla wszystkie elementy kolejki
void DynamicArrayPQ::displayinsert(ElementDynamicArray elem) {
    for (int i = 0; i < size; ++i) {
        cout << elements[i].value << "(" << elements[i].key << ")" << " ";
    }
    cout << endl;
}
//Metoda usuwa i zwraca pierwszy element kolejki
ElementDynamicArray DynamicArrayPQ::extractMax() {
    if (isEmpty()) {
        cout<<"kolejka jest pusta";
    }
    ElementDynamicArray maxElement = elements[0];
    for (int i = 1; i < size; i++) {
        elements[i - 1] = elements[i];
    }
    size--;
    return maxElement;
}
//metoda zwraca element o najwyższym priorytecie
ElementDynamicArray DynamicArrayPQ::findMax() {
    if (isEmpty()) {
        cout<<"kolejka jest pusta";
    }
    return elements[0];
}
//metoda wyświetla ten element
void DynamicArrayPQ::displayMax() {
    const ElementDynamicArray& maxElement = elements[0];
    cout << maxElement.value << "(" << maxElement.key << ")" << endl;
}
//metoda zmienia klucz elementu o podanym indeksie
void DynamicArrayPQ::modifyKey(int index, int newKey) {
    if (index < 0 || index >= size) {
        throw runtime_error("index poza zakresem");
    }
    elements[index].key = newKey;
    sort(elements, elements + size, [](const ElementDynamicArray& a, const ElementDynamicArray& b) {
        return a.key > b.key;
        });
}
//metoda zwraca rozmiar kolejki
int DynamicArrayPQ::returnSize() {
    return size;
}
//metoda wyświetla rozmiar kolejki
void DynamicArrayPQ::displaySize() {
    cout << "Rozmiar kolejki: " << returnSize() << endl;
}
//metoda usuwa wszystkie elementy z kolejki i ustawia jej rozmiar na 0
void DynamicArrayPQ::clear() {
    if (elements != nullptr) {
        delete[] elements;
        elements = nullptr;
    }
    size = 0;
}
