//tworzenie dynamicznej tablicy do przechowywania elementów kopca
#ifndef DYNAMIC_ARRAY_H
#define DYNAMIC_ARRAY_H

#include <iostream>
#include <random>
#include <fstream>
#include <string>
#include <chrono>
#include <conio.h>
#include <stdexcept>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

//definiuje typ danych Element
struct Element {
    int key;
    int value;
};
//Implementacja tablicy dynamicznej dla elementów typu Element
class DynamicArray {
private:
    Element* array;
    int size;
    int capacity;

public:
    DynamicArray(int initCapacity = 2) : size(0), capacity(initCapacity) {
        array = new Element[capacity];
    }
    ~DynamicArray() {
        delete[] array;

    }

    void doubleCapacity();
    void pushBack(Element elem);
    Element& operator[](int index);
    int getSize() const { return size; }
    void setSize(int newSize) { size = newSize; }
    bool isEmpty() const { return size == 0; }
};

#endif
