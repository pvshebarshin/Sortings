#ifndef SORTINGS_SORTER_H
#define SORTINGS_SORTER_H

#include <list>

template<typename T>
class Sorter {
public:

    // Функция сортировки подсчетом
    // Подходит только для неотрицательных целых чисел, линейная, устойчивая
    void countingSort(int* numbers, const uint32_t& array_size);

    // Функция цифровой сортировки
    // Подходит только для неотрицательных целых чисел, линейная
    void radixSort(int* numbers, const uint32_t& array_size);

    // Сортировка слиянием
    void mergeSort(T* arr, const uint32_t& array_size);

    // Сортировка кучей (Пирамидальная сортировка)
    void heapSort(T* numbers, const uint32_t& array_size);

    // Быстрая сортировка (сортировка Хора)
    void quickSort(T* numbers, const uint32_t& array_size);

    // Сортировка пузырьком
    // Подходит для любых чисел
    void bubbleSort(T* arr, const uint32_t& array_size);

    // Шейкерная сортировка
    void shakerSort(T* arr, const uint32_t& array_size);

    // Сортировка расческой
    void combSort(T* arr, const uint32_t& array_size);

    // Сортировка Шелла
    void shellSort(T* arr, const uint32_t& array_size);

    // Сортировка чёт-нечет
    void oddEvenSort(T* arr, const uint32_t& array_size);

    // Самая простая сортировка
    void simpleSort(T* arr, const uint32_t& array_size);

    // Сортировка выбором
    void selectionSort(T* arr, const uint32_t& array_size);

    // Сортировка вставками
    void insertionSort(T* arr, const uint32_t& array_size);

    // Гномья Сортировка
    void gnomeSort(T* arr, const uint32_t& array_size);

    // Бетонная Сортировка
    // может использоваться только если количество элементов в
    // массиве 2^n
    void bitonicSort(T* arr, const uint32_t& array_size);

    // Обезьянья Сортировка
    void bogoSort(T* arr, const uint32_t& array_size);

    // Сортировка Тима
    void timSort(T* arr, const uint32_t& array_size);

    // Нитевидная сортировка
    void strandSort(T* arr, const uint32_t& array_size);

    // Сортировка деревом двоичного поиска
    // Пока некорректно сортирует массивы с большим количеством чисел (более 250)
    void treeSort(T* arr, const uint32_t& array_size);

    // Сортировка Блин
    void pancakeSort(T* arr, const uint32_t& array_size);

    // Блуждающая (Придурковатая) Сортировка
    void stoogeSort(T* arr, const uint32_t& array_size);

    // Циклическая Сортировка
    void cycleSort(T* arr, const uint32_t& array_size);

    // Интроспективная Сортировка
    void introSort(T* arr, const uint32_t& array_size);

    // Клоунская сортировка
    void bozoSort(T* arr, const uint32_t& array_size);

    // Сортировка перестановками
    void permSort(T* arr, const uint32_t& array_size);

private:

    const int RUN = 32;

    void merge(T* arr,  const uint32_t& first, const uint32_t& second, const uint32_t& end);

    void divide_and_merge(T* arr, const uint32_t& left, const uint32_t& right);

    void heaping(T* numbers, uint32_t begin, const uint32_t &end);

    void heapSort(T* numbers, const uint32_t &begin, const uint32_t &end);

    void quickSort(T* numbers, const uint32_t& left, const uint32_t& right);

    uint32_t rerange(T* numbers, const uint32_t& left, const uint32_t& right, const uint32_t& x);

    void bitonicSort(T* arr, const uint32_t& begin, const uint32_t& end, const int& marker);

    void bitonicMerge(T* arr, const uint32_t& begin, const uint32_t& end, const int& marker);

    bool isGood(T* arr, uint32_t array_size);

    void insertion(T* arr, const uint32_t &left, const uint32_t &right);

    void strandSort(std::list<T>& input, std::list<T>& output);

    union UNION
    {
        unsigned int value;
        unsigned char mas[4];
    };

    struct Node
    {
        T key;
        Node *left, *right;
    };

    Node* newNode(T item);

    void storeSorted(Node *root, T *arr, uint32_t& i);

    Node* insert(Node *node, T key);

    void destroyTree(Node* node);

    uint32_t findMax(T* arr, const uint32_t& array_size);

    void flip(T* arr, uint32_t i);

    void stoogeSort(T *arr, const uint32_t &left, const uint32_t &right);

    void insertion (T* arr, const uint32_t& array_size);

    void introSort(T* arr, const uint32_t& first, uint32_t last, const int& depth);

    uint32_t partition (T* arr, uint32_t first, const uint32_t& last);

    bool isSorted(const T* arr, const uint32_t& array_size);

    bool isSortedIntro(const T* arr);

    uint32_t fac(uint32_t array_size);

    void permute(T* arr, uint32_t l, uint32_t r, T** permutations, uint32_t& count);

    void findMinPermutation(T** permutations, uint32_t count, T* minPerm);
};

template<typename T>
void Sorter<T>::findMinPermutation(T** permutations, uint32_t count, T* minPerm) {
    bool isLess;
    for (uint32_t i = 0; i < count; ++i) {
        isLess = false;
        for (uint32_t j = 0; j < count; ++j) {
            if (permutations[i][j] < minPerm[j]) {
                isLess = true;
                break;
            } else if (permutations[i][j] > minPerm[j]) {
                isLess = false;
                break;
            }
        }
        if (isLess) {
            for (uint32_t j = 0; j < count; ++j) {
                minPerm[j] = permutations[i][j];
            }
        }
    }
}

template<typename T>
void Sorter<T>::permute(T *arr, const uint32_t l, const uint32_t r, T **permutations, uint32_t &count) {
    if (l == r) {
        for (uint32_t i = 0; i <= r; ++i) {
            permutations[count][i] = arr[i];
        }
        count++;
    } else {
        T t;
        for (uint32_t i = l; i <= r; ++i) {
            t = arr[i];
            arr[i] = arr[l];
            arr[l] = t;
            permute(arr, l + 1, r, permutations, count);
            t = arr[i];
            arr[i] = arr[l];
            arr[l] = t;
        }
    }
}

template<typename T>
uint32_t Sorter<T>::fac(uint32_t array_size) {
    if (array_size > 1) {
        return array_size * fac(array_size - 1);
    } else {
        return 1;
    }
}

template<typename T>
void Sorter<T>::permSort(T *arr, const uint32_t &array_size) {
    uint32_t maxPermutations = fac(array_size);
    T* permutations[maxPermutations];
    for (uint32_t i = 0; i < maxPermutations; ++i) {
        permutations[i] = new T[array_size];
    }

    uint32_t count = 0;
    permute(arr, 0, array_size - 1, permutations, count);

    T* minPerm = new T[array_size];
    for (uint32_t i = 0; i < array_size; ++i) {
        minPerm[i] = permutations[0][i];
    }

    findMinPermutation(permutations, count, minPerm);
    for (uint32_t i = 0; i < array_size; ++i) {
        arr[i] = minPerm[i];
    }

    for (int i = 0; i < maxPermutations; ++i) {
        delete[] permutations[i];
    }
    delete[] minPerm;
}

template<typename T>
void Sorter<T>::bozoSort(T* arr, const uint32_t &array_size) {
    srand(static_cast<unsigned int>(time(nullptr)));
    T t;
    while (!isSorted(arr, array_size)) {
        int i = rand() % array_size;
        int j = rand() % array_size;

        t = arr[i];
        arr[i] = arr[j];
        arr[j] = t;
    }
}

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

    for (i = 0; i < array_size; ++i)
        ++C[numbers[i]];

    for (i = 1; i < max; ++i)
        C[i] += C[i - 1];

    for (i = array_size - 1; i >= 0; --i)
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
void Sorter<T>::radixSort(int* numbers, const uint32_t& array_size)
{
    UNION* un_mass = new UNION[array_size];

    uint32_t i;
    int* C = nullptr;
    int k;
    for(int index = 0; index < 4; ++index)
    {
        for (i = 0; i < array_size; ++i)
            un_mass[i].value = numbers[i];

        k = un_mass[0].mas[index];
        for (i = 0; i < array_size; ++i)
            if(un_mass[i].mas[index] > k)
                k = un_mass[i].mas[index];

        C = new int[k + 1];

        for (i = 0; i < k + 1; ++i)
            C[i] = 0;
        for (i = 0; i < array_size; ++i)
            C[un_mass[i].mas[index]] += 1;
        for (i = 1; i < k + 1; ++i)
            C[i] += C[i - 1];

        for (i = array_size - 1; i >= 0; --i)
        {
            numbers[C[un_mass[i].mas[index]] - 1] = un_mass[i].value;
            C[un_mass[i].mas[index]] -= 1;
            if(i == 0)
                break;
        }
        delete[] C;
    }
    delete[] un_mass;
}

template<typename T>
void Sorter<T>::mergeSort(T* arr, const uint32_t& array_size)
{
    divide_and_merge(arr, 0, array_size - 1);
}

template<typename T>
void Sorter<T>::merge(T* arr, const uint32_t& first, const uint32_t& second, const uint32_t& end)
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
void Sorter<T>::divide_and_merge(T* arr, const uint32_t& left, const uint32_t& right)
{
    if (left == right)
        return;
    if (right - 1 == left)
    {
        if (arr[right] < arr[left])
        {
            T t = arr[right];
            arr[right] = arr[left];
            arr[left] = t;
        }
        return;
    }

    uint32_t index = left + (right - left) / 2;

    divide_and_merge(arr, left, index);
    divide_and_merge(arr, index + 1, right);
    merge(arr, left, index, right);
}

template<typename T>
void Sorter<T>::heapSort(T* numbers, const uint32_t& array_size)
{
    heapSort(numbers, 0, array_size);
}

template<typename T>
void Sorter<T>::heapSort(T* numbers, const uint32_t& begin, const uint32_t& end)
{
    uint32_t i;
    T t;
    for (i = (end - 1) / 2; i >= begin; --i){
        heaping(numbers, i , end - 1);
        if (i == 0)
            break;
    }

    for (i = end - 1; i > begin; --i)
    {
        t = numbers[i];
        numbers[i] = numbers[begin];
        numbers[begin] = t;
        heaping(numbers, begin, i - 1);
        if (i == 0)
            break;
    }
}

template<typename T>
void Sorter<T>::heaping(T* numbers, uint32_t begin, const uint32_t& end)
{
    T save = numbers[begin];
    uint32_t k;
    while (begin <= end / 2) {
        k = 2 * begin;
        while (k < end && numbers[k] < numbers[k + 1])
            ++k;
        if (save >= numbers[k])
            break;
        numbers[begin] = numbers[k];
        begin = k;
    }
    numbers[begin] = save;
}

template<typename T>
void Sorter<T>::quickSort(T* numbers, const uint32_t& array_size)
{
    quickSort(numbers, 0, array_size - 1);
}

template<typename T>
void Sorter<T>::quickSort(T* numbers, const uint32_t& left, const uint32_t& right)
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
uint32_t Sorter<T>::rerange(T* numbers, const uint32_t& left, const uint32_t& right, const uint32_t& x)
{
    T pivot = numbers[x];
    uint32_t i = left - 1;
    uint32_t j = right + 1;
    T t;
    while (true)
    {
        do {
            ++i;
        } while (numbers[i] < pivot);

        do {
            --j;
        } while (numbers[j] > pivot);

        if (i >= j)
            return j;

        t = numbers[i];
        numbers[i] = numbers[j];
        numbers[j] = t;
    }
}

template<typename T>
void Sorter<T>::bubbleSort(T* arr, const uint32_t& array_size)
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
void Sorter<T>::shakerSort(T* arr, const uint32_t& array_size)
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
void Sorter<T>::combSort(T* arr, const uint32_t& array_size)
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
void Sorter<T>::shellSort(T* arr, const uint32_t& array_size)
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
void Sorter<T>::oddEvenSort(T* arr, const uint32_t& array_size)
{
    uint32_t i;
    T t;
    bool isSorted = false;

    while (!isSorted) {
        isSorted = true;

        for (i = 1; i < array_size - 1; i += 2) {
            if (arr[i] > arr[i + 1]) {
                t = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = t;
                isSorted = false;
            }
        }

        for (i = 0; i < array_size - 1; i += 2) {
            if (arr[i] > arr[i + 1]) {
                t = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = t;
                isSorted = false;
            }
        }
    }
}

template<typename T>
void Sorter<T>::simpleSort(T* arr, const uint32_t& array_size)
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
void Sorter<T>::selectionSort(T* arr, const uint32_t& array_size)
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
void Sorter<T>::insertionSort(T* arr, const uint32_t& array_size)
{
    uint32_t i, j;
    T t;

    for (i = 1; i < array_size; ++i)
        for (j = i; j > 0 && arr[j - 1] > arr[j]; --j)
        {
            t = arr[j];
            arr[j] = arr[j - 1];
            arr[j - 1] = t;
        }
}

template<typename T>
void Sorter<T>::gnomeSort(T* arr, const uint32_t& array_size)
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
void Sorter<T>::bitonicSort(T* arr, const uint32_t& array_size)
{
    bitonicSort(arr, 0, array_size, 1);
}

template<typename T>
void Sorter<T>::bitonicSort(T* arr, const uint32_t& begin, const uint32_t& end, const int& marker)
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
void Sorter<T>::bitonicMerge(T *arr, const uint32_t& begin, const uint32_t& end, const int& marker)
{
    if (end > 1)
    {
        T t;
        uint32_t x = end / 2;
        for (uint32_t i = begin; i < begin + x; ++i)
        {
            if (marker == arr[i] > arr[i + x])
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
void Sorter<T>::bogoSort(T* arr, const uint32_t& array_size)
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
    for(--array_size; array_size > 0; --array_size)
        if (arr[array_size - 1] > arr[array_size])
            return false;
    return true;
}

template<typename T>
void Sorter<T>::timSort(T* arr, const uint32_t& array_size)
{
    for (uint32_t i = 0; i < array_size; i += RUN)
        if (i + 31 < array_size - 1) {
            insertion(arr, i, i + 31);
        } else {
            insertion(arr, i, array_size - 1);
        }

    uint32_t size, left, midl, right;
    for (size = RUN; size < array_size; size = 2 * size)
        for (left = 0; left < array_size; left += 2 * size)
        {
            midl = left + size - 1;
            if(left + 2 * size - 1 < array_size - 1) {
                right = left + 2 * size - 1;
            } else {
                right = array_size - 1;
            }
            merge(arr, left, midl, right);
        }
}

template<typename T>
void Sorter<T>::insertion(T* arr, const uint32_t& left, const uint32_t& right)
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

template<typename T>
void Sorter<T>::strandSort(T* arr, const uint32_t& array_size)
{
    std::list<T> input, output;
    for(uint32_t i = 0; i < array_size; ++i)
        input.push_back(arr[i]);

    strandSort(input, output);

    for(uint32_t i = 0; i < array_size; ++i)
    {
        arr[i] = output.front();
        output.pop_front();
    }
}

template<typename T>
void Sorter<T>::strandSort(std::list<T>& input, std::list<T>& output)
{
    if (!input.empty())
    {
        std::list<T> temp;
        temp.push_back(input.front());
        input.pop_front();

        typename std::list<T>::iterator it = input.begin();
        while (it != input.end())
            if (*it > temp.back()) {
                temp.push_back(*it);
                it = input.erase(it);
            } else {
                ++it;
            }

        output.merge(temp);
        strandSort(input, output);
    }
}

template<typename T>
void Sorter<T>::treeSort(T* arr, const uint32_t& array_size)
{
    struct Node *root = nullptr;

    root = insert(root, arr[0]);
    for (uint32_t i = 1; i < array_size; ++i)
        root = insert(root, arr[i]);

    uint32_t i = 0;
    storeSorted(root, arr, i);
    destroyTree(root);
}

template<typename T>
void Sorter<T>::storeSorted(Sorter::Node *root, T* arr, uint32_t& i)
{
    if (root != nullptr)
    {
        storeSorted(root->left, arr, i);
        arr[i] = root->key;
        ++i;
        storeSorted(root->right, arr, i);
    }
}

template<typename T>
typename Sorter<T>::Node *Sorter<T>::insert(Sorter::Node* node, T key)
{
    if (node == nullptr)
        return newNode(key);

    if (key < node->key) {
        node->left = insert(node->left, key);
    } else if (key > node->key) {
        node->right = insert(node->right, key);
    }

    return node;
}

template<typename T>
typename Sorter<T>::Node *Sorter<T>::newNode(T item)
{
    Node *temp = new Node;
    temp->key = item;
    temp->left = temp->right = nullptr;
    return temp;
}

template<typename T>
void Sorter<T>::destroyTree(Sorter::Node* node)
{
    if(node != nullptr)
    {
        destroyTree(node->left);
        destroyTree(node->right);
        delete node;
    }
}

template<typename T>
void Sorter<T>::pancakeSort(T *arr, const uint32_t& array_size)
{
    for (uint32_t i = array_size, max_i; i > 1; --i)
    {
        max_i = findMax(arr, i);

        if (max_i != i - 1)
        {
            flip(arr, max_i);
            flip(arr, i - 1);
        }
    }
}

template<typename T>
uint32_t Sorter<T>::findMax(T *arr, const uint32_t& array_size)
{
    uint32_t max_i = 0;
    for (uint32_t i = 0; i < array_size; ++i)
        if (arr[i] > arr[max_i])
            max_i = i;
    return max_i;
}

template<typename T>
void Sorter<T>::flip(T *arr, uint32_t i)
{
    T temp;
    for(uint32_t start = 0; start < i; ++start, --i)
    {
        temp = arr[start];
        arr[start] = arr[i];
        arr[i] = temp;
    }
}

template<typename T>
void Sorter<T>::stoogeSort(T *arr, const uint32_t& array_size)
{
    stoogeSort(arr, 0, array_size - 1);
}

template<typename T>
void Sorter<T>::stoogeSort(T *arr, const uint32_t& left, const uint32_t& right)
{
    if (left < right)
    {
        if (arr[left] > arr[right])
        {
            T t = arr[left];
            arr[left] = arr[right];
            arr[right] = t;
        }

        if (right - left + 1 > 2)
        {
            uint32_t t = (right - left + 1) / 3;
            stoogeSort(arr, left, right - t);
            stoogeSort(arr, left + t, right);
            stoogeSort(arr, left, right - t);
        }
    }
}

template<typename T>
void Sorter<T>::cycleSort(T *arr, const uint32_t& array_size)
{
    uint32_t writes = 0, i, j, pos;
    T temp, t;

    for (uint32_t index = 0; index <= array_size - 2; ++index)
    {
        temp = arr[index];
        pos = index;
        for (i = index + 1; i < array_size; ++i)
            if (arr[i] < temp)
                ++pos;

        if (pos == index)
            continue;

        while (temp == arr[pos])
            ++pos;

        if (pos != index)
        {
            t = temp;
            temp = arr[pos];
            arr[pos] = t;
            ++writes;
        }

        while (pos != index)
        {
            pos = index;

            for (j = index + 1; j < array_size; ++j)
                if (arr[j] < temp)
                    ++pos;

            while (temp == arr[pos])
                ++pos;

            if (temp != arr[pos])
            {
                t = temp;
                temp = arr[pos];
                arr[pos] = t;
                ++writes;
            }
        }
    }
}

template<typename T>
void Sorter<T>::introSort(T* arr, const uint32_t& array_size)
{
    introSort(arr, 0, array_size - 1, (int(2*log(double(array_size)))));
    insertion(arr, array_size);
}

template<typename T>
void Sorter<T>::insertion(T *arr, const uint32_t& array_size)
{
    uint32_t i, j;
    T t;
    for (i = 1; i < array_size; ++i)
    {
        t = arr[i];
        for (j = i; j >= 1 && arr[j - 1] > t; --j)
            arr[j] = arr[j - 1];
        arr[j] = t;
    }
}

template<typename T>
void Sorter<T>::introSort(T *arr, const uint32_t& first, uint32_t last, const int& depth)
{
    uint32_t pivot;
    while(last - first > 0)
    {
        if(depth == 0) {
            heapSort(&arr[first], first, last - first + 1);
        } else {
            if(isSortedIntro(arr))
                break;
            pivot = partition(arr, first, last);
            introSort(arr, pivot + 1, last, depth - 1);
            last = pivot - 1;
        }
    }
}

template<typename T>
uint32_t Sorter<T>::partition(T *arr, uint32_t first, const uint32_t& last)
{
    uint32_t pivot,
            mid = first + (last - first) / 2;
    T t;

    pivot = arr[first] > arr[mid] ? first : mid;

    if(arr[pivot] > arr[last])
        pivot = last;

    t = arr[pivot];
    arr[pivot] = arr[first];
    arr[first] = t;

    pivot = first;

    while (first < last)
    {
        if (arr[first] <= arr[last])
        {
            t = arr[pivot];
            arr[pivot] = arr[first];
            arr[first] = t;
            ++pivot;
        }
        ++first;
    }

    t = arr[pivot];
    arr[pivot] = arr[last];
    arr[last] = t;

    return pivot;
}

template<typename T>
bool Sorter<T>::isSorted(const T *arr, const uint32_t& array_size)
{
    for (uint32_t i = 1; i < array_size; ++i) {
        if (arr[i] < arr[i - 1]) {
            return false;
        }
    }
    return true;
}

template<typename T>
bool Sorter<T>::isSortedIntro(const T *arr) {
    if(arr[0] > arr[1]){
        return false;
    } else {
        return true;
    }
}

#endif