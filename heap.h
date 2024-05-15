//tworzenie kopca za pomocą tablicy dynamicznej
#ifndef HEAP_H
#define HEAP_H

#include "DynamicArray.h"
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

class DynamicArray;

class Heap {
private:
    DynamicArray data;

    //przywracanie właściwości kopca
    void heapify(int index);
    void bubbleUp(int index);
    //funkcje pomocnicze zawierające indeksy rodzica i obu potomków
    int parent(int index) { return (index - 1) / 2; }
    int left(int index) { return 2 * index + 1; }
    int right(int index) { return 2 * index + 2; }

public:
    Heap() {}
    void insert(Element elem);
    Element extractMax();
    Element findMax();
    void modifyKey(int index, int newKey);
    int returnSize();
    bool isEmpty() { return data.isEmpty(); }
    void clear();
    void display();
    void displaySize();
    void displayMax();
};

#endif
