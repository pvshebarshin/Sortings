#include <iostream>
#include "src/Sorter.cpp"

template <typename T>
void printMas(T* mas, const uint32_t& size);

template <typename T>
void fillIntMas(T* mas, const uint32_t& size);


int main() {
    int size = 20;
    int* mas1 = new int[size];
    float* mas2 = new float[size];
    fillIntMas(mas1, size);
    printMas(mas1, size);
    Sorter<int> *sorter = new Sorter<int>();
    sorter->countingSort(mas1, size);
    printMas(mas1, size);


    delete[] mas1;
    delete[] mas2;
    delete sorter;
    return 0;
}

template <typename T>
void printMas(T* mas, const uint32_t& size)
{
    for(uint32_t i = 0; i < size; ++i)
        std::cout << std::to_string(mas[i]) << " ";
    std::cout << '\n' << '\n';
}

template <typename T>
void fillIntMas(T* mas, const uint32_t& size)
{
    for (int i = 0; i < size; ++i)
        mas[i] = rand();
}