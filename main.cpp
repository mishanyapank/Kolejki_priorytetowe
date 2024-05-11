#include "heap.h"
#include "DynamicArrayPriorityQueue.h"
#include <iostream>
#include <random>
#include <fstream>
#include <string>
#include <chrono>
#include <conio.h>

using namespace std;

void wyczysc() {
#ifdef _WIN32
    system("cls");    // Dla Windows.
#else
    system("clear");    // Dla Unix/Linux/MacOS.
#endif
}

void generateRandomElementsAndSaveToFile(const std::string& filename, int n) {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> disKey(0, 6 * n);
    uniform_int_distribution<> disValue(0, 2 * n);

    ofstream file(filename);
    if (!file) {
        cout << "Nie mozna otworzyc pliku do zapisu." << endl;
        return;
    }

    for (int i = 0; i < n; ++i) {
        int key = disKey(gen);
        int value = disValue(gen);
        file << value << " " << key << endl;
    }

    file.close();
}

int main() {
    /*
    //   MENU
    */
    
    Heap heap;
    DynamicArrayPQ pq;
    string algorytm;
    string data;
    int n = 0;
    int funkcja = 0;
    int funkcja_tab = 0;
    string filename = "data.txt";
    //Dane w pliku są wformacie "wartość klucz"
    
    cout << "Wybierz algorytm implementacji kolejki pryorytetowej. ( K - kopiec, T - tablica dynamiczna)";
    cin >> algorytm;
    cout << "Czy trzeba wylosowac nowy zakres danych? ( T - tak, N - nie)";
    cin >> data;
    if (algorytm == "K" or algorytm == "k") {
        if (data == "T" or data == "t") {
            cout << "Podaj liczbe elementów n do wygenerowania: " << endl;
            cin >> n;
            generateRandomElementsAndSaveToFile(filename, n);
        }
        ifstream file(filename);
        if (!file) {
            std::cerr << "Nie można otworzyc pliku do odczytu." << std::endl;
            return 1;
        }

        int value, key;
        while (file >> value >> key) {
            heap.insert({ key, value });
            n++;
        }

        file.close();
        wyczysc();
        while (funkcja != 8) {
            wyczysc();
            cout << "Co trzeba zrobic?" << endl;
            cout << "1 - dodanie elementu " << endl;
            cout << "2 - usuniecie i zwrocenie elementu o najwiekszym priorytecie " << endl;
            cout << "3 - zwrocenie elementu o najwiekszym priorytecie " << endl;
            cout << "4 - zmiana priorytetu elementu " << endl;
            cout << "5 - zwrocenie rozmiaru " << endl;
            cout << "8 - zakoncz program  " << endl;
            cin >> funkcja;
            wyczysc();
            if (funkcja == 1) {
                random_device rd;
                mt19937 gen(rd());
                uniform_int_distribution<> disKey(0, 6 * n);
                uniform_int_distribution<> disValue(0, 2 * n);
                int key_losowe = disKey(gen);
                int value_losowe = disValue(gen);
                auto start = chrono::high_resolution_clock::now();
                heap.insert({ key_losowe, value_losowe });
                auto end = chrono::high_resolution_clock::now();
                auto duration = chrono::duration_cast<chrono::nanoseconds>(end - start);
                cout << "---------------------" << endl;
                cout << "CZAS WYKONANIA: " << duration.count() << "NS" << endl;
                cout << "---------------------" << endl;
                _getch();
            }
            else if (funkcja == 2) {
                auto start = chrono::high_resolution_clock::now();
                heap.extractMax();
                auto end = chrono::high_resolution_clock::now();
                auto duration = chrono::duration_cast<chrono::nanoseconds>(end - start);
                cout << "---------------------" << endl;
                cout << "CZAS WYKONANIA: " << duration.count() << "NS" << endl;
                cout << "---------------------" << endl;
                _getch();
            }
            else if (funkcja == 3) {
                auto start = chrono::high_resolution_clock::now();
                heap.findMax();
                auto end = chrono::high_resolution_clock::now();
                auto duration = chrono::duration_cast<chrono::nanoseconds>(end - start);
                cout << "---------------------" << endl;
                cout << "CZAS WYKONANIA: " << duration.count() << "NS" << endl;
                cout << "---------------------" << endl;
                _getch();
            }
            else if (funkcja == 4) {
                random_device rd;
                mt19937 gen(rd());
                uniform_int_distribution<> disKey(0, n);
                uniform_int_distribution<> disValue(0, 6 * n);
                int index_losowe = disKey(gen);
                int key_losowe2 = disValue(gen);
                auto start = chrono::high_resolution_clock::now();
                heap.modifyKey(index_losowe, key_losowe2);
                auto end = chrono::high_resolution_clock::now();
                auto duration = chrono::duration_cast<chrono::nanoseconds>(end - start);
                cout << "---------------------" << endl;
                cout << "CZAS WYKONANIA: " << duration.count() << "NS" << endl;
                cout << "---------------------" << endl;
                _getch();
            }
            else if (funkcja == 5) {
                auto start = chrono::high_resolution_clock::now();
                heap.returnSize();
                auto end = chrono::high_resolution_clock::now();
                auto duration = chrono::duration_cast<chrono::nanoseconds>(end - start);
                cout << "---------------------" << endl;
                cout << "CZAS WYKONANIA: " << duration.count() << "NS" << endl;
                cout << "---------------------" << endl;
                _getch();
            }
        }
    }
    else if (algorytm == "T" or algorytm == "t") {
        if (data == "T" or data == "t") {
            cout << "Podaj liczbe elementow n do wygenerowania: ";
            cin >> n;
            generateRandomElementsAndSaveToFile(filename, n);
        }
        ifstream file(filename);
        if (!file) {
            std::cerr << "Nie mozna otworzyc pliku do odczytu." << std::endl;
            return 1;
        }

        int value, key;
        while (file >> value >> key) {
            pq.insert({ key, value });
        }

        file.close();
        wyczysc();
        while (funkcja_tab != 8) {
            wyczysc();
            cout << "Co trzeba zrobic?" << endl;
            cout << "1 - dodanie elementu " << endl;
            cout << "2 - usuniecie i zwrocenie elementu o najwiekszym priorytecie " << endl;
            cout << "3 - zwrocenie elementu o najwiekszym priorytecie " << endl;
            cout << "4 - zmiana priorytetu elementu " << endl;
            cout << "5 - zwrocenie rozmiaru " << endl;
            cout << "8 - zakoncz program  " << endl;
            cin >> funkcja_tab;
            wyczysc();
            if (funkcja_tab == 1) {
                random_device rd;
                mt19937 gen(rd());
                uniform_int_distribution<> disKey(0, 6 * n);
                uniform_int_distribution<> disValue(0, 2 * n);
                int key_losowe = disKey(gen);
                int value_losowe = disValue(gen);
                auto start = chrono::high_resolution_clock::now();
                pq.insert({ key_losowe, value_losowe });
                auto end = chrono::high_resolution_clock::now();
                auto duration = chrono::duration_cast<chrono::nanoseconds>(end - start);
                cout << "---------------------" << endl;
                cout << "CZAS WYKONANIA: " << duration.count() << "NS" << endl;
                cout << "---------------------" << endl;
                _getch();
            }
            else if (funkcja_tab == 2) {
                auto start = chrono::high_resolution_clock::now();
                pq.extractMax();
                auto end = chrono::high_resolution_clock::now();
                auto duration = chrono::duration_cast<chrono::nanoseconds>(end - start);
                cout << "---------------------" << endl;
                cout << "CZAS WYKONANIA: " << duration.count() << "NS" << endl;
                cout << "---------------------" << endl;
                _getch();
            }
            else if (funkcja_tab == 3) {
                auto start = chrono::high_resolution_clock::now();
                pq.findMax();
                auto end = chrono::high_resolution_clock::now();
                auto duration = chrono::duration_cast<chrono::nanoseconds>(end - start);
                cout << "---------------------" << endl;
                cout << "CZAS WYKONANIA: " << duration.count() << "NS" << endl;
                cout << "---------------------" << endl;
                _getch();
            }
            else if (funkcja_tab == 4) {
                random_device rd;
                mt19937 gen(rd());
                uniform_int_distribution<> disKey(0, n);
                uniform_int_distribution<> disValue(0, 6 * n);
                int index_losowe = disKey(gen);
                int key_losowe2 = disValue(gen);
                auto start = chrono::high_resolution_clock::now();
                pq.modifyKey(index_losowe, key_losowe2);
                auto end = chrono::high_resolution_clock::now();
                auto duration = chrono::duration_cast<chrono::nanoseconds>(end - start);
                cout << "---------------------" << endl;
                cout << "CZAS WYKONANIA: " << duration.count() << "NS" << endl;
                cout << "---------------------" << endl;
                _getch();
            }
            else if (funkcja_tab == 5) {
                auto start = chrono::high_resolution_clock::now();
                pq.returnSize();
                auto end = chrono::high_resolution_clock::now();
                auto duration = chrono::duration_cast<chrono::nanoseconds>(end - start);
                cout << "---------------------" << endl;
                cout << "CZAS WYKONANIA: " << duration.count() << "NS" << endl;
                cout << "---------------------" << endl;
                _getch();
            }
        }
    }
    else {
        cout << "Nie ma takiej opcji." << endl;
    }
    
    /*
    //   BADANIA
    */
/*
ofstream plik_tekstowy("badania10000kopiec.txt");
if (plik_tekstowy.is_open()) {
    plik_tekstowy << "10000 probek kopiec\n";
    std::string filename = "daneDoBadan.txt";
    const int n = 10000;
    long long czas_insert = 0;
    long long czas_extractmax = 0;
    long long czas_findmax = 0;
    long long czas_modifykey = 0;
    long long czas_returnsize = 0;

    Heap heap;

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> disKey(0, 6 * n);
    std::uniform_int_distribution<> disValue(0, 2 * n);

    for (int i = 0; i < 10; i++) {
        heap = Heap(); // Resetowanie kopca przed każdym przebiegiem
        // Przygotowanie danych
        for (int j = 0; j < n; j++) {
            int key = disKey(gen);
            int value = disValue(gen);
            heap.insert({ key, value });
        }

        auto start = std::chrono::high_resolution_clock::now();
        int key_losowe = disKey(gen);
        int value_losowe = disValue(gen);
        heap.insert({ key_losowe, value_losowe });
        auto end = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);
        plik_tekstowy << "CZAS WYKONANIA INSERT: " << duration.count() << " ns\n";
        czas_insert += duration.count();

        start = std::chrono::high_resolution_clock::now();
        heap.extractMax();
        end = std::chrono::high_resolution_clock::now();
        duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);
        plik_tekstowy << "CZAS WYKONANIA EXTRACTMAX: " << duration.count() << " ns\n";
        czas_extractmax += duration.count();

        start = std::chrono::high_resolution_clock::now();
        heap.findMax();
        end = std::chrono::high_resolution_clock::now();
        duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);
        plik_tekstowy << "CZAS WYKONANIA FINDMAX: " << duration.count() << " ns\n";
        czas_findmax += duration.count();

        int index_losowe = disKey(gen) % n; // Aby uniknąć przekroczenia indeksu
        int key_losowe2 = disKey(gen);
        start = std::chrono::high_resolution_clock::now();
        heap.modifyKey(index_losowe, key_losowe2);
        end = std::chrono::high_resolution_clock::now();
        duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);
        plik_tekstowy << "CZAS WYKONANIA MODIFYKEY: " << duration.count() << " ns\n";
        czas_modifykey += duration.count();

        start = std::chrono::high_resolution_clock::now();
        heap.returnSize();
        end = std::chrono::high_resolution_clock::now();
        duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);
        plik_tekstowy << "CZAS WYKONANIA RETURNSIZE: " << duration.count() << " ns\n";
        czas_returnsize += duration.count();
    }

    plik_tekstowy << "Usrednione\n";
    plik_tekstowy << "Sredni czas wykonania insert: " << czas_insert / 10 << " ns\n";
    plik_tekstowy << "Sredni czas wykonania extractmax: " << czas_extractmax / 10 << " ns\n";
    plik_tekstowy << "Sredni czas wykonania findmax: " << czas_findmax / 10 << " ns\n";
    plik_tekstowy << "Sredni czas wykonania modifykey: " << czas_modifykey / 10 << " ns\n";
    plik_tekstowy << "Sredni czas wykonania returnsize: " << czas_returnsize / 10 << " ns\n";

    plik_tekstowy.close();
}
else {
    std::cout << "Unable to open file";
}
*/
    return 0;
}