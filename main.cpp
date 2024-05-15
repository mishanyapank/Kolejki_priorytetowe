#include "heap.h"
#include "DynamicArrayPriorityQueue.h"


using namespace std;

void wyczysc() {
#ifdef _WIN32
    system("cls");    // Dla Windows.
#endif
}

void generateRandomElementsAndSaveToFile(const string& filename, int n) {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> disKey(0, n*6);
    uniform_int_distribution<> disValue(0, n*2);

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
void add_to_heap(Heap& heap, const string& filename, int n) {
    ifstream file(filename);
    if (!file) {
        cout << "Nie można otworzyc pliku do odczytu." << endl;
    }

    int value, key;
    while (file >> value >> key) {
        heap.insert({ key, value });
    }

    file.close();
}
void add_to_file(const string& nazwaPliku, const vector<float>& czasy) {
    ofstream plik(nazwaPliku);

    if (!plik.is_open()) {
        cerr << "Nie udalo sie otworzyc pliku do zapisu." << endl;
        return;
    }
    for (int i = 0; i < czasy.size(); i++) {
        plik << czasy[i] << endl;
    }

    plik.close();

    cout << "Dane zostaly zapisane do pliku czasy.csv" << endl;
}
void add_to_array(DynamicArrayPQ& pq, const string& filename, int n) {
    ifstream file(filename);
    if (!file) {
        cout << "Nie można otworzyc pliku do odczytu." << endl;

    }
    int value, key;
    while (file >> value >> key) {
        pq.insert({ key, value });
    }
    file.close();
}

int main() {
    /*
    //   MENU
    */
    random_device rd;
    mt19937 gen(rd());
    Heap heap;
    DynamicArrayPQ pq;
    string algorytm;
    int demo;
    string data;
    int n = 0;
    int funkcja = 0;
    int funkcja_tab = 0;
    string filename = "data.txt";
    //Dane w pliku są wformacie "wartość klucz"

    cout << "Wybierz algorytm implementacji kolejki pryorytetowej. ( K - kopiec, T - tablica dynamiczna)";
    cin >> algorytm;
    cout << "1. Program demonstracyjny" << endl;
    cout << "2. Program pomiarowy" << endl;
    cin >> demo;
    if (demo == 1) {
        cout << "Czy trzeba wylosowac nowy zakres danych? ( T - tak, N - nie)";
        cin >> data;
        if (algorytm == "K" or algorytm == "k") {
            if (data == "T" or data == "t") {
                cout << "Podaj liczbe elementów n do wygenerowania: " << endl;
                cin >> n;
                generateRandomElementsAndSaveToFile(filename, n);
                add_to_heap(heap, filename, n);
            }
            else if (algorytm == "N" or algorytm == "n") {
                ifstream file(filename);
                if (!file) {
                    cout << "Nie można otworzyc pliku do odczytu." << endl;
                    return 1;
                }
                int value, key;
                while (file >> value >> key) {
                    heap.insert({ key, value });
                    n++;
                }
                file.close();
            }
            
            uniform_int_distribution<> disKey(0, n * 6);
            uniform_int_distribution<> disValue(0, n * 2);
            wyczysc();
            while (funkcja != 8) {
                //wyczysc();
                cout << "Co trzeba zrobic?" << endl;
                cout << "1 - dodanie elementu " << endl;
                cout << "2 - usuniecie i zwrocenie elementu o najwiekszym priorytecie " << endl;
                cout << "3 - zwrocenie elementu o najwiekszym priorytecie " << endl;
                cout << "4 - zmiana priorytetu elementu " << endl;
                cout << "5 - zwrocenie rozmiaru " << endl;
                cout << "8 - zakoncz program  " << endl;
                cin >> funkcja;
                //wyczysc();
                if (funkcja == 1) {
                    int key_losowe = disKey(gen);
                    int value_losowe = disValue(gen);
                    auto start = chrono::high_resolution_clock::now();
                    heap.insert({ key_losowe, value_losowe });
                    auto end = chrono::high_resolution_clock::now();
                    auto duration = chrono::duration_cast<chrono::nanoseconds>(end - start);
                    cout << "---------------------" << endl;
                    cout << "CZAS WYKONANIA: " << duration.count() << "NS" << endl;
                    cout << "---------------------" << endl;
                    heap.display();
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
                    heap.display();
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
                    heap.displayMax();
                    _getch();
                }
                else if (funkcja == 4) {
                    uniform_int_distribution<> index(0, n);
                    uniform_int_distribution<> wartosc(0, n * 6);
                    int index_losowe = index(gen);
                    int key_losowe2 = wartosc(gen);
                    auto start = chrono::high_resolution_clock::now();
                    heap.modifyKey(index_losowe, key_losowe2);
                    auto end = chrono::high_resolution_clock::now();
                    auto duration = chrono::duration_cast<chrono::nanoseconds>(end - start);
                    cout << "---------------------" << endl;
                    cout << "CZAS WYKONANIA: " << duration.count() << "NS" << endl;
                    cout << "---------------------" << endl;
                    heap.display();
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
                    heap.displaySize();
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
                cout << "Nie mozna otworzyc pliku do odczytu." << endl;
                return 1;
            }

            int value, key;
            while (file >> value >> key) {
                pq.insert({ key, value });
            }

            file.close();
            random_device rd;
            mt19937 gen(rd());
            uniform_int_distribution<> disKey(0, n * 6);
            uniform_int_distribution<> disValue(0, n * 2);
            wyczysc();
            while (funkcja_tab != 8) {
                //wyczysc();
                cout << "Co trzeba zrobic?" << endl;
                cout << "1 - dodanie elementu " << endl;
                cout << "2 - usuniecie i zwrocenie elementu o najwiekszym priorytecie " << endl;
                cout << "3 - zwrocenie elementu o najwiekszym priorytecie " << endl;
                cout << "4 - zmiana priorytetu elementu " << endl;
                cout << "5 - zwrocenie rozmiaru " << endl;
                cout << "8 - zakoncz program  " << endl;
                cin >> funkcja_tab;
                //wyczysc();
                if (funkcja_tab == 1) {
                    int key_losowe = disKey(gen);
                    int value_losowe = disValue(gen);
                    auto start = chrono::high_resolution_clock::now();
                    pq.insert({ key_losowe, value_losowe });
                    auto end = chrono::high_resolution_clock::now();
                    auto duration = chrono::duration_cast<chrono::nanoseconds>(end - start);
                    cout << "---------------------" << endl;
                    cout << "CZAS WYKONANIA: " << duration.count() << "NS" << endl;
                    cout << "---------------------" << endl;
                    pq.displayinsert({ key, value });
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
                    pq.displayinsert({ key, value });
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
                    pq.displayMax();
                    _getch();
                }
                else if (funkcja_tab == 4) {
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
                    pq.displayinsert({ key, value });
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
                    pq.displaySize();
                    _getch();
                }
            }
        }
        else {
            cout << "Nie ma takiej opcji." << endl;
        }
    }
    else if (demo == 2) {
        cout << "Czy trzeba wylosowac nowy zakres danych? ( T - tak, N - nie)";
        cin >> data;
        if (algorytm == "K" or algorytm == "k") {
            if (data == "T" or data == "t") {
                cout << "Podaj liczbe elementów n do wygenerowania: " << endl;
                cin >> n;
                generateRandomElementsAndSaveToFile(filename, n);
            }
            else if (algorytm == "N" or algorytm == "n") {
                ifstream file(filename);
                if (!file) {
                    cout << "Nie można otworzyc pliku do odczytu." << endl;
                    return 1;
                }
                int value, key;
                while (file >> value >> key) {
                    heap.insert({ key, value });
                    n++;
                }
                file.close();
            }
            uniform_int_distribution<> disKey(0, n * 6);
            uniform_int_distribution<> disValue(0, n * 2);
            wyczysc();
            while (funkcja != 8) {
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
                    vector<float> czasy;
                    for (int x = 0; x < 50; x++) {
                        heap.clear();
                        add_to_heap(heap, filename, n);
                        int key_losowe = disKey(gen);
                        int value_losowe = disValue(gen);
                        auto start = chrono::high_resolution_clock::now();
                        heap.insert({ key_losowe, value_losowe });
                        auto end = chrono::high_resolution_clock::now();
                        auto duration = chrono::duration_cast<chrono::nanoseconds>(end - start);
                        czasy.push_back(duration.count());
                    }
                    add_to_file("czasy.csv", czasy);
                    vector<float>().swap(czasy);

                }
                else if (funkcja == 2) {
                        vector<float> czasy;
                        for (int x = 0; x < 50; x++) {
                            heap.clear();
                            add_to_heap(heap, filename, n);
                            auto start = chrono::high_resolution_clock::now();
                            heap.extractMax();
                            auto end = chrono::high_resolution_clock::now();
                            auto duration = chrono::duration_cast<chrono::nanoseconds>(end - start);
                            czasy.push_back(duration.count());
                        }
                        add_to_file("czasy.csv", czasy);
                        vector<float>().swap(czasy);
                    }
                    else if (funkcja == 3) {
                        vector<float> czasy;
                        for (int x = 0; x < 50; x++) {
                            heap.clear();
                            add_to_heap(heap, filename, n);
                            auto start = chrono::high_resolution_clock::now();
                            heap.findMax();
                            auto end = chrono::high_resolution_clock::now();
                            auto duration = chrono::duration_cast<chrono::nanoseconds>(end - start);
                            czasy.push_back(duration.count());
                        }
                        add_to_file("czasy.csv", czasy);
                        vector<float>().swap(czasy);

                    }
                    else if (funkcja == 4) {
                        vector<float> czasy;
                        for (int x = 0; x < 1; x++) {
                            heap.clear();
                            add_to_heap(heap, filename, n);
                            uniform_int_distribution<> index(0, n);
                            uniform_int_distribution<> wartosc(0, n * 6);
                            int index_losowe = index(gen);
                            int key_losowe2 = wartosc(gen);
                            auto start = chrono::high_resolution_clock::now();
                            heap.modifyKey(index_losowe, key_losowe2);
                            auto end = chrono::high_resolution_clock::now();
                            auto duration = chrono::duration_cast<chrono::nanoseconds>(end - start);
                            czasy.push_back(duration.count());

                        }
                        add_to_file("czasy.csv", czasy);
                        vector<float>().swap(czasy);
                    }
                    else if (funkcja == 5) {
                        vector<float> czasy;
                        for (int x = 0; x < 50; x++) {
                            heap.clear();
                            add_to_heap(heap, filename, n);
                            auto start = chrono::high_resolution_clock::now();
                            heap.returnSize();
                            auto end = chrono::high_resolution_clock::now();
                            auto duration = chrono::duration_cast<chrono::nanoseconds>(end - start);
                            czasy.push_back(duration.count());

                        }
                        add_to_file("czasy.csv", czasy);
                        vector<float>().swap(czasy);
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
                    cout << "Nie mozna otworzyc pliku do odczytu." << endl;
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
                        vector<float> czasy;
                        for (int x = 0; x < 50; x++) {
                            pq.clear();
                            add_to_array(pq, filename, n);
                            uniform_int_distribution<> disKey(0, n);
                            uniform_int_distribution<> disValue(0, 6 * n);
                            int key_losowe = disKey(gen);
                            int value_losowe = disValue(gen);
                            auto start = chrono::high_resolution_clock::now();
                            pq.insert({ key_losowe, value_losowe });
                            auto end = chrono::high_resolution_clock::now();
                            auto duration = chrono::duration_cast<chrono::nanoseconds>(end - start);
                            czasy.push_back(duration.count());
                        }
                        add_to_file("czasy.csv", czasy);
                        vector<float>().swap(czasy);
                    }
                    else if (funkcja_tab == 2) {
                        vector<float> czasy;
                        for (int x = 0; x < 50; x++) {
                            pq.clear();
                            add_to_array(pq, filename, n);
                            auto start = chrono::high_resolution_clock::now();
                            pq.extractMax();
                            auto end = chrono::high_resolution_clock::now();
                            auto duration = chrono::duration_cast<chrono::nanoseconds>(end - start);
                            czasy.push_back(duration.count());
                        }
                        add_to_file("czasy.csv", czasy);
                        vector<float>().swap(czasy);
                    }
                    else if (funkcja_tab == 3) {
                        vector<float> czasy;
                        for (int x = 0; x < 50; x++) {
                            pq.clear();
                            add_to_array(pq, filename, n);
                            auto start = chrono::high_resolution_clock::now();
                            pq.findMax();
                            auto end = chrono::high_resolution_clock::now();
                            auto duration = chrono::duration_cast<chrono::nanoseconds>(end - start);
                            czasy.push_back(duration.count());
                        }
                        add_to_file("czasy.csv", czasy);
                        vector<float>().swap(czasy);
                    }
                    else if (funkcja_tab == 4) {
                        vector<float> czasy;
                        for (int x = 0; x < 50; x++) {
                            pq.clear();
                            add_to_array(pq, filename, n);
                            uniform_int_distribution<> disKey(0, n);
                            uniform_int_distribution<> disValue(0, 6 * n);
                            int index_losowe = disKey(gen);
                            int key_losowe2 = disValue(gen);
                            auto start = chrono::high_resolution_clock::now();
                            pq.modifyKey(index_losowe, key_losowe2);
                            auto end = chrono::high_resolution_clock::now();
                            auto duration = chrono::duration_cast<chrono::nanoseconds>(end - start);
                            czasy.push_back(duration.count());
                        }
                        add_to_file("czasy.csv", czasy);
                        vector<float>().swap(czasy);

                    }
                    else if (funkcja_tab == 5) {
                        vector<float> czasy;
                        for (int x = 0; x < 50; x++) {
                            pq.clear();
                            add_to_array(pq, filename, n);
                            auto start = chrono::high_resolution_clock::now();
                            pq.returnSize();
                            auto end = chrono::high_resolution_clock::now();
                            auto duration = chrono::duration_cast<chrono::nanoseconds>(end - start);
                            czasy.push_back(duration.count());
                        }
                        add_to_file("czasy.csv", czasy);
                        vector<float>().swap(czasy);
                    }
                    else {
                        cout << "Nie ma takiej opcji." << endl;
                    }

                }
            }
    }
    return 0;
