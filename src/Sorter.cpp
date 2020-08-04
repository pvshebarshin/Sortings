#include "Sorter.h"

template<typename T>
void Sorter<T>::countingSort(int* numbers, const uint32_t& array_size)
{
    int max = -1, i;
    for (i = 0; i < array_size; ++i)
        if (max <= numbers[i])
            max = numbers[i] + 1;

    int* B = new int[array_size];
    int* C = new int[max];

    for (i = 0; i < max; ++i)
        C[i] = 0;

    for(i = 0; i < array_size; ++i)
        ++C[numbers[i]];

    for(i = 1; i < max; ++i)
        C[i] += C[i - 1];

    for(i = array_size - 1; i >= 0; --i)
    {
        B[C[numbers[i]] - 1] = numbers[i];
        --C[numbers[i]];
    }
    for(i = 0; i < array_size; ++i)
        numbers[i] = B[i];

    delete[] C;
    delete[] B;
}

template<typename T>
void Sorter<T>::radixSort(int *numbers, const uint32_t &array_size)
{
    int max_value = -1;
    uint32_t i;

    for (i = 0; i < array_size; ++i)
        if (numbers[i] > max_value)
            max_value = numbers[i];

    for (int discharge = 1; max_value/discharge > 0; discharge *= 256)
    {
        int output[array_size];
        int count[256] = {0};

        for (i = 0; i < array_size; ++i)
            ++count[numbers[i] / discharge % 256];

        for (i = 1; i < 256; ++i)
            count[i] += count[i - 1];

        for (i = array_size - 1; i >= 0; --i)
        {
            output[count[numbers[i] / discharge % 256] - 1] = numbers[i];
            --count[numbers[i] / discharge % 256 ];
        }

        for (i = 0; i < array_size; ++i)
            numbers[i] = output[i];
    }
}

template<typename T>
void Sorter<T>::mergeSort(T *arr, const uint32_t& length)
{
    divide_and_merge(arr, 0, length - 1);
}

template<typename T>
void Sorter<T>::merge(T *arr, uint32_t first, uint32_t second, uint32_t end)
{
    uint32_t current_number = 0,
    index_left = first,
    index_right = second + 1;

    T* mas = new T[end + 1];
    while (index_left <= second && index_right <= end)
    {
        if (arr[index_left] < arr[index_right])
        {
            mas[current_number] = arr[index_left];
            ++index_left;
        } else {
            mas[current_number] = arr[index_right];
            ++index_right;
        }
        ++current_number;
    }

    if (index_left <= second)
    {
        for(; index_left <= second; ++index_left)
        {
            mas[current_number] = arr[index_left];
            ++current_number;
        }
    } else {
        for(; index_right <= end; mas[current_number++] = arr[index_right++]);
    }

    uint32_t arrayPointer = first;
    for (current_number = 0; arrayPointer <= end; ++arrayPointer)
    {
        arr[arrayPointer] = mas[current_number];
        ++current_number;
    }

    delete[] mas;
}

template<typename T>
void Sorter<T>::divide_and_merge(T *arr, uint32_t left, uint32_t right)
{
    if(left == right)
        return;
    if (right - 1 == left)
    {
        if(arr[right] < arr[left])
        {
            T t = arr[right];
            arr[right] = arr[left];
            arr[left] = t;
        }
        return;
    }

    uint32_t index = (right + left) / 2;

    divide_and_merge(arr, left, index);
    divide_and_merge(arr, index + 1, right);
    merge(arr, left, index, right);
}

template<typename T>
void Sorter<T>::heapSort(T *numbers, const uint32_t& array_size)
{
    uint32_t i;
    T t;

    for (i = array_size / 2 - 1; i >= 0; --i)
        heaping(numbers, array_size, i, array_size);

    for (i = array_size - 1; i >= 0; --i)
    {
        t = numbers[0];
        numbers[0] = numbers[i];
        numbers[i] = t;

        heaping(numbers, i, 0, i);
    }
}

template<typename T>
void Sorter<T>::heaping(T *numbers, const uint32_t& array_size,
        uint32_t index, const uint32_t max)
{
    uint32_t largest_index = index;
    uint32_t left_index = 2 * index + 1;
    uint32_t right_index = left_index + 1;

    while(index < max)
    {
        if (left_index < array_size && numbers[left_index] > numbers[largest_index])
            largest_index = left_index;

        if (right_index < array_size && numbers[right_index] > numbers[largest_index])
            largest_index = right_index;

        if(largest_index == index)
            return;

        T t = numbers[index];
        numbers[index] = numbers[largest_index];
        numbers[largest_index] = t;
        index = largest_index;
    }
}

template<typename T>
void Sorter<T>::quickSort(T *numbers, const uint32_t& array_size)
{
    quickSort(numbers, 0, array_size - 1);
}

template<typename T>
void Sorter<T>::quickSort(T *numbers, uint32_t left, uint32_t right)
{
    if (left < right)
    {
        uint32_t x = left + (right - left) / 2;
        uint32_t pivot  = rerange(numbers, left, right, x);
        quickSort(numbers, left, pivot);
        quickSort(numbers, pivot + 1, right);

    }
}

template<typename T>
uint32_t Sorter<T>::rerange(T *numbers, uint32_t left, uint32_t right, uint32_t x)
{
    T pivot = numbers[x];
    uint32_t i = left - 1;
    uint32_t j = right + 1;
    T t;
    while (true)
    {
        do
            ++i;
        while (numbers[i] < pivot);

        do
            --j;
        while (numbers[j] > pivot);

        if (i >= j)
            return j;

        t = numbers[i];
        numbers[i] = numbers[j];
        numbers[j] = t;
    }
}

template<typename T>
void Sorter<T>::bubbleSort(T *arr, const uint32_t& array_size)
{
    uint32_t i, j;
    T t;

    for (i = 0; i < array_size - 1; ++i)
        for (j = 0; j < array_size - i - 1; ++j)
            if (arr[j] > arr[j + 1])
            {
                t = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = t;
            }
}

template<typename T>
void Sorter<T>::shakerSort(T *arr, const uint32_t &array_size)
{
    uint32_t i;
    T t;
    uint32_t left = 0;
    uint32_t right = array_size - 1;
    do {

        for (i = left; i < right; ++i)
            if (arr[i] > arr[i + 1])
            {
                t = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = t;
            }
        --right;

        for (i = right; i > left; --i)
            if (arr[i] < arr[i - 1])
            {
                t = arr[i];
                arr[i] = arr[i - 1];
                arr[i - 1] = t;
            }
        ++left;

    } while (left < right);
}

template<typename T>
void Sorter<T>::combSort(T *arr, const uint32_t &array_size)
{
    T t;
    uint32_t temp_shift, N = array_size, i;
    uint32_t shift = array_size;

    while(N > 1)
    {
        shift /= 1.24733f;
        temp_shift = 0;
        if (shift < 1)
            shift = 1;

        for (i = 0; i + shift < N; ++i)
            if(arr[i] / 10 > arr[i + shift] / 10)
            {
                temp_shift = i;

                t = arr[i];
                arr[i] = arr[i + shift];
                arr[i + shift] = t;
            }

        if (shift == 1)
            N = temp_shift + 1;
    }
}

template<typename T>
void Sorter<T>::shellSort(T *arr, const uint32_t &array_size)
{
    uint32_t i, j, step;
    T t;
    for (step = array_size / 2; step > 0; step /= 2)
        for (i = step; i < array_size; ++i)
        {
            t = arr[i];
            for (j = i; j >= step; j -= step)
            {
                if (t < arr[j - step]) {
                    arr[j] = arr[j - step];
                } else {
                    break;
                }
            }
            arr[j] = t;
        }
}

template<typename T>
void Sorter<T>::oddEvenSort(T *arr, const uint32_t &array_size)
{
    uint32_t i, j;
    T t;
    for (i = 0; i < array_size; ++i)
        for (j = i % 2 ? 0 : 1; j + 1 < array_size; j += 2)
            if (arr[j] > arr[j + 1])
            {
                t = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = t;
            }
}

template<typename T>
void Sorter<T>::simpleSort(T *arr, const uint32_t &array_size)
{
    uint32_t i, j;
    T t;

    for (i = 0; i < array_size - 1; ++i)
        for (j = 0; j < array_size - 1; ++j)
            if (arr[j] > arr[j + 1])
            {
                t = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = t;
            }
}

template<typename T>
void Sorter<T>::selectionSort(T *arr, const uint32_t &array_size)
{
    uint32_t min_index, i, j;
    T t;

    for (i = 0; i < array_size - 1; ++i)
    {
        min_index = i;

        for (j = i + 1; j < array_size; ++j)
            if (arr[j] < arr[min_index])
                min_index = j;

        if (min_index != i)
        {
            t = arr[i];
            arr[i] = arr[min_index];
            arr[min_index] = t;
        }
    }
}

template<typename T>
void Sorter<T>::insertionSort(T *arr, const uint32_t &array_size)
{
    uint32_t i, j;
    T t;

    for(i = 1; i < array_size; ++i)
        for(j = i; j > 0 && arr[j - 1] > arr[j]; --j)
        {
            t = arr[j];
            arr[j] = arr[j - 1];
            arr[j - 1] = t;
        }

}

template<typename T>
void Sorter<T>::gnomeSort(T *arr, const uint32_t &array_size)
{
    uint32_t i = 0;
    T t;

    while (i < array_size) {
        if (i == 0)
            ++i;
        if (arr[i] >= arr[i - 1]) {
            ++i;
        } else {
            t = arr[i];
            arr[i] = arr[i - 1];
            arr[i - 1] = t;
            --i;
        }
    }
}

template<typename T>
void Sorter<T>::bitonicSort(T *arr, const uint32_t &array_size)
{
    bitonicSort(arr, 0, array_size, 1);
}

template<typename T>
void Sorter<T>::bitonicSort(T* arr, uint32_t begin, uint32_t end, int marker)
{
    if (end > 1)
    {
        uint32_t x = end / 2;
        bitonicSort(arr, begin, x, 1);
        bitonicSort(arr, begin + x, x, 0);
        bitonicMerge(arr, begin, end, marker);
    }
}

template<typename T>
void Sorter<T>::bitonicMerge(T *arr, uint32_t begin, uint32_t end, int marker)
{
    if (end > 1)
    {
        T t;
        uint32_t x = end / 2;
        for (uint32_t i = begin; i < begin + x; ++i)
        {
            if(marker == arr[i] > arr[i + x])
            {
                t = arr[i];
                arr[i] = arr[i + x];
                arr[i + x] = t;
            }
        }
        bitonicMerge(arr, begin, x, marker);
        bitonicMerge(arr, begin + x, x, marker);
    }
}

template<typename T>
void Sorter<T>::bogoSort(T *arr, const uint32_t &array_size)
{
    T t, temp;
    uint32_t index;
    while (!isGood(arr, array_size))
        for (int i = 0; i < array_size; ++i)
        {
            t = arr[i];
            index = rand() % array_size;
            temp = arr[index];
            arr[i] = temp;
            arr[index] = t;
        }
}

template<typename T>
bool Sorter<T>::isGood(T *arr, uint32_t array_size)
{
    while (array_size-- > 0)
        if (arr[array_size - 1] > arr[array_size])
            return false;
    return true;
}

template<typename T>
void Sorter<T>::timSort(T *arr, const uint32_t& array_size)
{
    for (uint32_t i = 0; i < array_size; i += RUN)
        if(i + 31 < array_size - 1) {
            insertion(arr, i, i + 31);
        } else {
            insertion(arr, i, array_size - 1);
        }

    uint32_t size, left, mid, right;
    for (size = RUN; size < array_size; size = 2 * size)
        for (left = 0; left < array_size; left += 2 * size)
        {
            mid = left + size - 1;
            if(left + 2 * size - 1 < array_size - 1) {
                right = left + 2 * size - 1;
            } else {
                right = array_size - 1;
            }
            merge(arr, left, mid, right);
        }
}

template<typename T>
void Sorter<T>::insertion(T *arr, uint32_t left, uint32_t right)
{
    T t;
    uint32_t i, j;
    for (i = left + 1; i <= right; ++i)
    {
        t = arr[i];
        for(j = i - 1; j >= left && arr[j] > t; --j)
            arr[j + 1] = arr[j];
        arr[j + 1] = t;
    }
}
