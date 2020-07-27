#ifndef SORTINGS_SORTER_H
#define SORTINGS_SORTER_H

class Sorter
{
public:

    // Функция сортировки подсчетом
    // Подходит только для неотрицательных целых чисел, линейная, устойчивая
    void countingSort(int *numbers, const int& array_size);

    // Функция цифровой сортировки
    // Подходит только для неотрицательных целых чисел, линейная
    void radixSort(int *numbers, const int& array_size);

    // Сортировка слиянием
    void mergeSort(int *arr, const int& length);

    // Сортировка кучей(Пирамидальная сортировка)
    void heapSort(int *numbers, const int& array_size);

    // Быстрая сортировка(сортировка Хора)
    void quickSort(int *numbers, const int& array_size);

    // Сортировка пузырьком
    // Подходит для любых чисел
    void bubbleSort(int *arr, const int& array_size);

    // Шейкерная сортировка
    void shakerSort(int *arr, const int& array_size);

    // Сортировка расческой
    void combSort(int *arr, const int& array_size);

    // Сортировка Шелла
    void shellSort(int *arr, const int& array_size);

    // Сортировка чёт-нечет
    void oddEvenSort(int *arr, const int& array_size);

    // Самая простая сортировка
    void simpleSort(int *arr, const int& array_size);

    // Сортировка выбором
    void selectionSort(int *arr, const int& array_size);

    // Сортировка вставками
    void insertionSort(int *arr, const int& array_size);

private:

    void merge(int* arr, int first, int second, int end);

    void divide_and_merge(int *arr, int left, int right);

    void heaping(int *numbers, int array_size, int index);

    void quickSort(int *numbers, int left, int right);

    int rerange(int* numbers, int left, int right, int x);

};

#endif