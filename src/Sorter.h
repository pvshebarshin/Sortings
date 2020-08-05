#ifndef SORTINGS_SORTER_H
#define SORTINGS_SORTER_H

#include <stdint-gcc.h>
#include <variant>

template <typename T>
class Sorter
{
public:

    // Функция сортировки подсчетом
    // Подходит только для неотрицательных целых чисел, линейная, устойчивая
    void countingSort(int *numbers, const uint32_t& array_size);

    // Функция цифровой сортировки
    // Подходит только для неотрицательных целых чисел, линейная
    void radixSort(int *numbers, const uint32_t& array_size);

    // Сортировка слиянием
    void mergeSort(T *arr, const uint32_t& length);

    // Сортировка кучей(Пирамидальная сортировка)
    void heapSort(T *numbers, const uint32_t& array_size);

    // Быстрая сортировка(сортировка Хора)
    void quickSort(T *numbers, const uint32_t& array_size);

    // Сортировка пузырьком
    // Подходит для любых чисел
    void bubbleSort(T *arr, const uint32_t& array_size);

    // Шейкерная сортировка
    void shakerSort(T *arr, const uint32_t& array_size);

    // Сортировка расческой
    void combSort(T *arr, const uint32_t& array_size);

    // Сортировка Шелла
    void shellSort(T *arr, const uint32_t& array_size);

    // Сортировка чёт-нечет
    void oddEvenSort(T *arr, const uint32_t& array_size);

    // Самая простая сортировка
    void simpleSort(T *arr, const uint32_t& array_size);

    // Сортировка выбором
    void selectionSort(T *arr, const uint32_t& array_size);

    // Сортировка вставками
    void insertionSort(T *arr, const uint32_t& array_size);

    // Гномья Сортировка
    void gnomeSort(T *arr, const uint32_t& array_size);

    // Бетонная Сортировка
    // может использоваться только если количество элементов в
    // массиве 2^n
    void bitonicSort(T *arr, const uint32_t& array_size);

    // Обезьянья Сортировка
    void bogoSort(T *arr, const uint32_t& array_size);

    // Сортировка Тима
    void timSort(T *arr, const uint32_t& array_size);

private:

    const int RUN = 32;

    void merge(T* arr, uint32_t first, uint32_t second, uint32_t end);

    void divide_and_merge(T *arr, uint32_t left, uint32_t right);

    void heaping(T *numbers, uint32_t begin, uint32_t end);

    void heapSort(T *numbers, const uint32_t& begin, const  uint32_t& end);

    void quickSort(T *numbers, uint32_t left, uint32_t right);

    uint32_t rerange(T* numbers, uint32_t left, uint32_t right, uint32_t x);

    void bitonicSort(T* arr, uint32_t begin, uint32_t end, int marker);

    void bitonicMerge(T* arr, uint32_t begin, uint32_t end, int marker);

    bool isGood(T *arr, uint32_t array_size);

    void insertion(T *arr, uint32_t left, uint32_t right);

    union UNION
    {
        unsigned int value;
        unsigned char mas[4];
    };

};

#endif