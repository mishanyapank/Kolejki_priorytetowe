#include "heap.h"

//metoda insert dodaje nowy element do kopca
void Heap::insert(Element elem) {
    data.pushBack(elem);
    int i = data.getSize() - 1;
    while (i != 0 && data[parent(i)].key < data[i].key) {
        swap(data[i], data[parent(i)]);
        i = parent(i);
    }
}

//metoda extractMax() usuwa i zwraca element z największym kluczem
Element Heap::extractMax() {
    if (data.isEmpty()) {
        cout << "Kopiec jest pusty";
    }

    Element max = data[0];
    data[0] = data[data.getSize() - 1];
    data.setSize(data.getSize() - 1);
    heapify(0);
    return max;
}
//Metoda findMax zwraca element z największym kluczem bez jego usuwania
Element Heap::findMax() {
    if (data.isEmpty()) {
        cout<< "Kopiec jest pusty";
    }
    return data[0];
}
//metoda displayMax wyświetla element z największym kluczem
void Heap::displayMax() {
    const Element& maxElement = data[0];
    cout << maxElement.value <<"(" << maxElement.key <<")"<<endl;
}
//rekurencyjna metoda heapify która przez porównywanie i zamianę elementów 
//przywraca właściwości kopca
void Heap::heapify(int index) {
    int l = left(index);
    int r = right(index);
    int largest = index;
    if (l < data.getSize() && data[l].key > data[largest].key)
        largest = l;
    if (r < data.getSize() && data[r].key > data[largest].key)
        largest = r;
    if (largest != index) {
        swap(data[index], data[largest]);
        heapify(largest);
    }
}
//metoda buubbleUp podbija element w górę kopca jeśli jego nowy klucz jest 
//większy od klucza rodzica
void Heap::bubbleUp(int index) {
    while (index != 0 && data[parent(index)].key < data[index].key) {
        swap(data[index], data[parent(index)]);
        index = parent(index);
    }
}
//modyfikuje klucz elementu o danym indeksie i przywraca właściwości kopca
//wywołujac jedną z dwóch wyżej wymienionych metod
void Heap::modifyKey(int index, int newKey) {
    int oldKey = data[index].key;
    data[index].key = newKey;
    if (newKey > oldKey) {
        bubbleUp(index);
    }
    else {
        heapify(index);
    }
}
//wyświetla rozmiar
void Heap::displaySize() {
    cout << "Rozmiar kopca: " << returnSize() << endl;
}
//zwraca rozmiar kopca
int Heap::returnSize() {
    return data.getSize();
}
//czyści kopiec ustawiając rozmiar na 0
void Heap::clear() {
    data.setSize(0);
}
//wyświetla wszystkie elementy kopca
void Heap::display() {
    cout << "Zawartość kopca: ";
    for (int i = 0; i < data.getSize(); ++i) {
        cout << data[i].value << "("<<data[i].key<<")"<< " ";
    }
    cout << endl;
}
