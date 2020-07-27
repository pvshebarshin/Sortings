#include "Sorter.h"

void Sorter::countingSort(int* numbers, const int& array_size)
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

void Sorter::radixSort(int *numbers, const int &array_size)
{
    int max_value = -1, i;

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

void Sorter::mergeSort(int *arr, const int& length)
{
    divide_and_merge(arr, 0, length - 1);
}

void Sorter::merge(int *arr, int first, int second, int end)
{
    int current_number = 0,
    index_left = first,
    index_right = second + 1;

    int* mas = new int[end + 1];
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

    int arrayPointer = first;
    for (current_number = 0; arrayPointer <= end; ++arrayPointer)
    {
        arr[arrayPointer] = mas[current_number];
        ++current_number;
    }

    delete[] mas;
}

void Sorter::divide_and_merge(int *arr, int left, int right)
{
    if(left == right)
        return;
    if (right - 1 == left)
    {
        if(arr[right] < arr[left])
        {
            int t = arr[right];
            arr[right] = arr[left];
            arr[left] = t;
        }
        return;
    }

    int index = (right + left) / 2;

    divide_and_merge(arr, left, index);
    divide_and_merge(arr, index + 1, right);
    merge(arr, left, index, right);
}

void Sorter::heapSort(int *numbers, const int& array_size)
{
    int i, t;
    for (i = array_size / 2 - 1; i >= 0; --i)
        heaping(numbers, array_size, i);

    for (i = array_size - 1; i >= 0; --i)
    {
        t = numbers[0];
        numbers[0] = numbers[i];
        numbers[i] = t;

        heaping(numbers, i, 0);
    }
}

void Sorter::heaping(int *numbers, int array_size, int index)
{
    int largest_index = index;
    int left_index = 2 * index + 1;
    int right_index = 2 * index + 2;

    if (left_index < array_size && numbers[left_index] > numbers[largest_index])
        largest_index = left_index;

    if (right_index < array_size && numbers[right_index] > numbers[largest_index])
        largest_index = right_index;

    if (largest_index != index)
    {
        int t = numbers[index];
        numbers[index] = numbers[largest_index];
        numbers[largest_index] = t;
        heaping(numbers, array_size, largest_index);
    }
}

void Sorter::quickSort(int *numbers, const int& array_size)
{
    quickSort(numbers, 0, array_size - 1);
}

void Sorter::quickSort(int *numbers, int left, int right)
{
    if (left < right)
    {
        int x = left + (right - left) / 2;
        int pivot  = rerange(numbers, left, right, x);
        quickSort(numbers, left, pivot);
        quickSort(numbers, pivot + 1, right);

    }
}

int Sorter::rerange(int *numbers, int left, int right, int x)
{
    int pivot = numbers[x];
    int i = left - 1;
    int j = right + 1;
    int t;
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

void Sorter::bubbleSort(int *arr, const int& array_size)
{
    int t, j;

    for (int i = 0; i < array_size - 1; ++i)
        for (j = 0; j < array_size - i - 1; ++j)
            if (arr[j] > arr[j + 1])
            {
                t = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = t;
            }
}

void Sorter::shakerSort(int *arr, const int &array_size)
{
    int t, i;
    int left = 0;
    int right = array_size - 1;
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

void Sorter::combSort(int *arr, const int &array_size)
{
    int t, temp_shift, N = array_size, i;
    int shift = array_size;

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

void Sorter::shellSort(int *arr, const int &array_size)
{
    int i, j, t;

    for (int step = array_size / 2; step > 0; step /= 2)
        for (i = step; i < array_size; --i)
            for (j = i - step; j >= 0 && arr[j] > arr[j + step]; j -= step)
            {
                t = arr[j];
                arr[j] = arr[j + step];
                arr[j + step] = t;
            }
}

void Sorter::oddEvenSort(int *arr, const int &array_size)
{
    int j, t;
    for (int i = 0; i < array_size; ++i)
        for (j = (i % 2) ? 0 : 1; j + 1 < array_size; j += 2)
            if (arr[j] > arr[j + 1])
            {
                t = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = t;
            }
}

void Sorter::simpleSort(int *arr, const int &array_size)
{
    int t, j;

    for (int i = 0; i < array_size - 1; ++i)
        for (j = 0; j < array_size - 1; ++j)
            if (arr[j] > arr[j + 1])
            {
                t = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = t;
            }
}

void Sorter::selectionSort(int *arr, const int &array_size)
{
    int min_index, j, t;
    for (int i = 0; i < array_size - 1; ++i)
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

void Sorter::insertionSort(int *arr, const int &array_size)
{
    int i, j, t;
    for(i = 1; i < array_size; ++i)
        for(j = i; j > 0 && arr[j-1] > arr[j]; --j)
        {
            t = arr[j];
            arr[j] = arr[j - 1];
            arr[j - 1] = t;
        }

}
