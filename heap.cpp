#include "heap.h"


void Heap::insert(Element elem) {
    data.pushBack(elem);
    int i = data.getSize() - 1;
    while (i != 0 && data[parent(i)].key < data[i].key) {
        swap(data[i], data[parent(i)]);
        i = parent(i);
    }
}

Element Heap::extractMax() {
    if (data.isEmpty()) {
        cout << "";
    }

    Element max = data[0];
    data[0] = data[data.getSize() - 1];
    data.setSize(data.getSize() - 1);
    heapify(0);
    return max;
}

Element Heap::findMax() {
    if (data.isEmpty())
        throw runtime_error("Kopiec jest pusty");

    return data[0];
}
void Heap::displayMax() {
    const Element& maxElement = data[0];
    cout << maxElement.value <<"(" << maxElement.key <<")"<<endl;
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
        swap(data[index], data[largest]);
        heapify(largest);
    }
}

void Heap::bubbleUp(int index) {
    while (index != 0 && data[parent(index)].key < data[index].key) {
        swap(data[index], data[parent(index)]);
        index = parent(index);
    }
}

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
void Heap::displaySize() {
    cout << "Rozmiar kopca: " << returnSize() << endl;
}
int Heap::returnSize() {
    return data.getSize();
}
void Heap::clear() {
    data.setSize(0);
}
void Heap::display() {
    cout << "Zawartość kopca: ";
    for (int i = 0; i < data.getSize(); ++i) {
        cout << data[i].value << "("<<data[i].key<<")"<< " ";
    }
    cout << endl;
}
