#include <algorithm>
#include <gtest/gtest.h>
#include "../src/Sorter.h"

namespace
{
    class SortingsTests : public testing::Test
    {
    public:
        Sorter<float>* fSorter = nullptr;
        Sorter<int>* iSorter = nullptr;
        int* A = nullptr;
        int* B = nullptr;
        float* A1 = nullptr;
        float* B1 = nullptr;
        SortingsTests()
        {
            fSorter = new Sorter<float>();
            iSorter = new Sorter<int>();
        }

        ~SortingsTests() override
        {
            delete fSorter;
            delete iSorter;

            delete[] A;
            delete[] B;
            delete[] A1;
            delete[] B1;
        }

        void fillIntMas(int *mas, const uint32_t &size, const uint32_t &r)
        {
            srand(r);
            for (uint32_t i = 0; i < size; ++i)
                mas[i] = rand();
        }
        static void fillFloatMas(float* mas, const uint32_t& size, const uint32_t& r)
        {
            srand(r);
            for (uint32_t i = 0; i < size; ++i)
                mas[i] = (float) rand() / RAND_MAX + rand();
        }
    };
}

TEST_F(SortingsTests, countingSort_Test1)
{
    uint32_t size = 10;
    A = new int[size];
    B = new int[size];

    fillIntMas(A, size, 1);
    iSorter->simpleSort(A, size);

    fillIntMas(B, size, 1);
    iSorter->countingSort(B, size);

    for (uint32_t i = 0; i < size; ++i)
        ASSERT_EQ(A[i], B[i]);
}

TEST_F(SortingsTests, countingSort_Test2)
{
    uint32_t size = 15;
    A = new int[size];
    B = new int[size];

    fillIntMas(A, size, 3);
    iSorter->simpleSort(A, size);

    fillIntMas(B, size, 3);
    iSorter->countingSort(B, size);

    for (uint32_t i = 0; i < size; ++i)
        ASSERT_EQ(A[i], B[i]);
}

TEST_F(SortingsTests, countingSort_Test3)
{
    uint32_t size = 100;
    A = new int[size];
    B = new int[size];

    fillIntMas(A, size, 666);
    iSorter->simpleSort(A, size);

    fillIntMas(B, size, 666);
    iSorter->countingSort(B, size);

    for (uint32_t i = 0; i < size; ++i)
        ASSERT_EQ(A[i], B[i]);
}

TEST_F(SortingsTests, countingSort_Test4)
{
    uint32_t size = 1000;
    A = new int[size];
    B = new int[size];

    fillIntMas(A, size, 6666);
    iSorter->simpleSort(A, size);

    fillIntMas(B, size, 6666);
    iSorter->countingSort(B, size);

    for (uint32_t i = 0; i < size; ++i)
        ASSERT_EQ(A[i], B[i]);
}


TEST_F(SortingsTests, radixSort_Test1)
{
    uint32_t size = 10;
    A = new int[size];
    B = new int[size];

    fillIntMas(A, size, 4);
    iSorter->simpleSort(A, size);

    fillIntMas(B, size, 4);
    iSorter->radixSort(B, size);

    for (uint32_t i = 0; i < size; ++i)
        ASSERT_EQ(A[i], B[i]);
}

TEST_F(SortingsTests, radixSort_Test2)
{
    uint32_t size = 100;
    A = new int[size];
    B = new int[size];

    fillIntMas(A, size, 14);
    iSorter->simpleSort(A, size);

    fillIntMas(B, size, 14);
    iSorter->radixSort(B, size);

    for (uint32_t i = 0; i < size; ++i)
        ASSERT_EQ(A[i], B[i]);
}

TEST_F(SortingsTests, radixSort_Test3)
{
    uint32_t size = 1000;
    A = new int[size];
    B = new int[size];

    fillIntMas(A, size, 41);
    iSorter->simpleSort(A, size);

    fillIntMas(B, size, 41);
    iSorter->radixSort(B, size);

    for (uint32_t i = 0; i < size; ++i)
        ASSERT_EQ(A[i], B[i]);
}


TEST_F(SortingsTests, mergeSort_Test1)
{
    uint32_t size = 10;
    A1 = new float[size];
    B1 = new float[size];

    fillFloatMas(A1, size, 4);
    fSorter->simpleSort(A1, size);

    fillFloatMas(B1, size, 4);
    fSorter->mergeSort(B1, size);

    for (uint32_t i = 0; i < size; ++i)
        ASSERT_EQ(A1[i], B1[i]);
}

TEST_F(SortingsTests, mergeSort_Test2)
{
    uint32_t size = 100;
    A1 = new float[size];
    B1 = new float[size];

    fillFloatMas(A1, size, 44);
    fSorter->simpleSort(A1, size);

    fillFloatMas(B1, size, 44);
    fSorter->mergeSort(B1, size);

    for (uint32_t i = 0; i < size; ++i)
        ASSERT_EQ(A1[i], B1[i]);
}

TEST_F(SortingsTests, mergeSort_Test3)
{
    uint32_t size = 1000;
    A1 = new float[size];
    B1 = new float[size];

    fillFloatMas(A1, size, 41);
    fSorter->simpleSort(A1, size);

    fillFloatMas(B1, size, 41);
    fSorter->mergeSort(B1, size);

    for (uint32_t i = 0; i < size; ++i)
        ASSERT_EQ(A1[i], B1[i]);
}

TEST_F(SortingsTests, heapSort_Test1)
{
    uint32_t size = 10;
    A1 = new float[size];
    B1 = new float[size];

    fillFloatMas(A1, size, 133);
    fSorter->simpleSort(A1, size);

    fillFloatMas(B1, size, 133);
    fSorter->heapSort(B1, size);

    for (uint32_t i = 0; i < size; ++i)
        ASSERT_EQ(A1[i], B1[i]);
}

TEST_F(SortingsTests, heapSort_Test2)
{
    uint32_t size = 100;
    A1 = new float[size];
    B1 = new float[size];

    fillFloatMas(A1, size, 1313);
    fSorter->simpleSort(A1, size);

    fillFloatMas(B1, size, 1313);
    fSorter->heapSort(B1, size);

    for (uint32_t i = 0; i < size; ++i)
        ASSERT_EQ(A1[i], B1[i]);
}

TEST_F(SortingsTests, heapSort_Test3)
{
    uint32_t size = 1000;
    A1 = new float[size];
    B1 = new float[size];

    fillFloatMas(A1, size, 1133);
    fSorter->simpleSort(A1, size);

    fillFloatMas(B1, size, 1133);
    fSorter->heapSort(B1, size);

    for (uint32_t i = 0; i < size; ++i)
        ASSERT_EQ(A1[i], B1[i]);
}

TEST_F(SortingsTests, quickSort_Test1)
{
    uint32_t size = 10;
    A1 = new float[size];
    B1 = new float[size];

    fillFloatMas(A1, size, 4);
    fSorter->simpleSort(A1, size);

    fillFloatMas(B1, size, 4);
    fSorter->quickSort(B1, size);

    for (uint32_t i = 0; i < size; ++i)
        ASSERT_EQ(A1[i], B1[i]);
}

TEST_F(SortingsTests, quickSort_Test2)
{
    uint32_t size = 100;
    A1 = new float[size];
    B1 = new float[size];

    fillFloatMas(A1, size, 42);
    fSorter->simpleSort(A1, size);

    fillFloatMas(B1, size, 42);
    fSorter->quickSort(B1, size);

    for (uint32_t i = 0; i < size; ++i)
        ASSERT_EQ(A1[i], B1[i]);
}

TEST_F(SortingsTests, quickSort_Test3)
{
    uint32_t size = 1000;
    A1 = new float[size];
    B1 = new float[size];

    fillFloatMas(A1, size, 411);
    fSorter->simpleSort(A1, size);

    fillFloatMas(B1, size, 411);
    fSorter->quickSort(B1, size);

    for (uint32_t i = 0; i < size; ++i)
        ASSERT_EQ(A1[i], B1[i]);
}

TEST_F(SortingsTests, bubbleSort_Test)
{
    uint32_t size = 1000;
    A1 = new float[size];
    B1 = new float[size];

    fillFloatMas(A1, size, 4);
    fSorter->quickSort(A1, size);

    fillFloatMas(B1, size, 4);
    fSorter->bubbleSort(B1, size);

    for (uint32_t i = 0; i < size; ++i)
        ASSERT_EQ(A1[i], B1[i]);
}

TEST_F(SortingsTests, shakerSort_Test1)
{
    uint32_t size = 10;
    A1 = new float[size];
    B1 = new float[size];

    fillFloatMas(A1, size, 4);
    fSorter->simpleSort(A1, size);

    fillFloatMas(B1, size, 4);
    fSorter->shakerSort(B1, size);

    for (uint32_t i = 0; i < size; ++i)
        ASSERT_EQ(A1[i], B1[i]);
}

TEST_F(SortingsTests, shakerSort_Test2)
{
    uint32_t size = 100;
    A1 = new float[size];
    B1 = new float[size];

    fillFloatMas(A1, size, 14);
    fSorter->simpleSort(A1, size);

    fillFloatMas(B1, size, 14);
    fSorter->shakerSort(B1, size);

    for (uint32_t i = 0; i < size; ++i)
        ASSERT_EQ(A1[i], B1[i]);
}

TEST_F(SortingsTests, shakerSort_Test3)
{
    uint32_t size = 1000;
    A1 = new float[size];
    B1 = new float[size];

    fillFloatMas(A1, size, 1);
    fSorter->simpleSort(A1, size);

    fillFloatMas(B1, size, 1);
    fSorter->shakerSort(B1, size);

    for (uint32_t i = 0; i < size; ++i)
        ASSERT_EQ(A1[i], B1[i]);
}

TEST_F(SortingsTests, combSort_Test1)
{
    uint32_t size = 10;
    A1 = new float[size];
    B1 = new float[size];

    fillFloatMas(A1, size, 4);
    fSorter->combSort(A1, size);

    fillFloatMas(B1, size, 4);
    fSorter->bubbleSort(B1, size);

    for (uint32_t i = 0; i < size; ++i)
        ASSERT_EQ(A1[i], B1[i]);
}

TEST_F(SortingsTests, combSort_Test2)
{
    uint32_t size = 100;
    A1 = new float[size];
    B1 = new float[size];

    fillFloatMas(A1, size, 24);
    fSorter->combSort(A1, size);

    fillFloatMas(B1, size, 24);
    fSorter->bubbleSort(B1, size);

    for (uint32_t i = 0; i < size; ++i)
        ASSERT_EQ(A1[i], B1[i]);
}

TEST_F(SortingsTests, combSort_Test3)
{
    uint32_t size = 1000;
    A1 = new float[size];
    B1 = new float[size];

    fillFloatMas(A1, size, 74);
    fSorter->combSort(A1, size);

    fillFloatMas(B1, size, 74);
    fSorter->bubbleSort(B1, size);

    for (uint32_t i = 0; i < size; ++i)
        ASSERT_EQ(A1[i], B1[i]);
}

TEST_F(SortingsTests, shellSort_Test1)
{
    uint32_t size = 10;
    A1 = new float[size];
    B1 = new float[size];

    fillFloatMas(A1, size, 4);
    fSorter->shellSort(A1, size);

    fillFloatMas(B1, size, 4);
    fSorter->simpleSort(B1, size);

    for (uint32_t i = 0; i < size; ++i)
        ASSERT_EQ(A1[i], B1[i]);
}

TEST_F(SortingsTests, shellSort_Test2)
{
    uint32_t size = 100;
    A1 = new float[size];
    B1 = new float[size];

    fillFloatMas(A1, size, 24);
    fSorter->shellSort(A1, size);

    fillFloatMas(B1, size, 24);
    fSorter->simpleSort(B1, size);

    for (uint32_t i = 0; i < size; ++i)
        ASSERT_EQ(A1[i], B1[i]);
}

TEST_F(SortingsTests, shellSort_Test3)
{
    uint32_t size = 1000;
    A1 = new float[size];
    B1 = new float[size];

    fillFloatMas(A1, size, 43);
    fSorter->shellSort(A1, size);

    fillFloatMas(B1, size, 43);
    fSorter->simpleSort(B1, size);

    for (uint32_t i = 0; i < size; ++i)
        ASSERT_EQ(A1[i], B1[i]);
}

TEST_F(SortingsTests, oddEvenSort_Test1)
{
    uint32_t size = 10;
    A1 = new float[size];
    B1 = new float[size];

    fillFloatMas(A1, size, 4);
    fSorter->bubbleSort(A1, size);

    fillFloatMas(B1, size, 4);
    fSorter->oddEvenSort(B1, size);

    for (uint32_t i = 0; i < size; ++i)
        ASSERT_EQ(A1[i], B1[i]);
}

TEST_F(SortingsTests, oddEvenSort_Test2)
{
    uint32_t size = 100;
    A1 = new float[size];
    B1 = new float[size];

    fillFloatMas(A1, size, 94);
    fSorter->bubbleSort(A1, size);

    fillFloatMas(B1, size, 94);
    fSorter->oddEvenSort(B1, size);

    for (uint32_t i = 0; i < size; ++i)
        ASSERT_EQ(A1[i], B1[i]);
}

TEST_F(SortingsTests, oddEvenSort_Test3)
{
    uint32_t size = 1000;
    A1 = new float[size];
    B1 = new float[size];

    fillFloatMas(A1, size, 2);
    fSorter->bubbleSort(A1, size);

    fillFloatMas(B1, size, 2);
    fSorter->oddEvenSort(B1, size);

    for (uint32_t i = 0; i < size; ++i)
        ASSERT_EQ(A1[i], B1[i]);
}

TEST_F(SortingsTests, simpleSort_Test)
{
    uint32_t size = 10;
    A1 = new float[size];
    B1 = new float[size];

    fillFloatMas(A1, size, 4);
    fSorter->bubbleSort(A1, size);

    fillFloatMas(B1, size, 4);
    fSorter->simpleSort(B1, size);

    for (uint32_t i = 0; i < size; ++i)
        ASSERT_EQ(A1[i], B1[i]);
}

TEST_F(SortingsTests, selectionSort_Test1)
{
    uint32_t size = 10;
    A1 = new float[size];
    B1 = new float[size];

    fillFloatMas(A1, size, 4);
    fSorter->bubbleSort(A1, size);

    fillFloatMas(B1, size, 4);
    fSorter->selectionSort(B1, size);

    for (uint32_t i = 0; i < size; ++i)
        ASSERT_EQ(A1[i], B1[i]);
}

TEST_F(SortingsTests, selectionSort_Test2)
{
    uint32_t size = 100;
    A1 = new float[size];
    B1 = new float[size];

    fillFloatMas(A1, size, 40);
    fSorter->bubbleSort(A1, size);

    fillFloatMas(B1, size, 40);
    fSorter->selectionSort(B1, size);

    for (uint32_t i = 0; i < size; ++i)
        ASSERT_EQ(A1[i], B1[i]);
}

TEST_F(SortingsTests, selectionSort_Test3)
{
    uint32_t size = 1000;
    A1 = new float[size];
    B1 = new float[size];

    fillFloatMas(A1, size, 400);
    fSorter->bubbleSort(A1, size);

    fillFloatMas(B1, size, 400);
    fSorter->selectionSort(B1, size);

    for (uint32_t i = 0; i < size; ++i)
        ASSERT_EQ(A1[i], B1[i]);
}

TEST_F(SortingsTests, insertionSort_Test1)
{
    uint32_t size = 10;
    A1 = new float[size];
    B1 = new float[size];

    fillFloatMas(A1, size, 4);
    fSorter->bubbleSort(A1, size);

    fillFloatMas(B1, size, 4);
    fSorter->insertionSort(B1, size);

    for (uint32_t i = 0; i < size; ++i)
        ASSERT_EQ(A1[i], B1[i]);
}

TEST_F(SortingsTests, insertionSort_Test2)
{
    uint32_t size = 100;
    A1 = new float[size];
    B1 = new float[size];

    fillFloatMas(A1, size, 54);
    fSorter->bubbleSort(A1, size);

    fillFloatMas(B1, size, 54);
    fSorter->insertionSort(B1, size);

    for (uint32_t i = 0; i < size; ++i)
        ASSERT_EQ(A1[i], B1[i]);
}

TEST_F(SortingsTests, insertionSort_Test3)
{
    uint32_t size = 1000;
    A1 = new float[size];
    B1 = new float[size];

    fillFloatMas(A1, size, 41);
    fSorter->bubbleSort(A1, size);

    fillFloatMas(B1, size, 41);
    fSorter->insertionSort(B1, size);

    for (uint32_t i = 0; i < size; ++i)
        ASSERT_EQ(A1[i], B1[i]);
}

TEST_F(SortingsTests, gnomeSort_Test1)
{
    uint32_t size = 10;
    A1 = new float[size];
    B1 = new float[size];

    fillFloatMas(A1, size, 4);
    fSorter->bubbleSort(A1, size);

    fillFloatMas(B1, size, 4);
    fSorter->gnomeSort(B1, size);

    for (uint32_t i = 0; i < size; ++i)
        ASSERT_EQ(A1[i], B1[i]);
}

TEST_F(SortingsTests, gnomeSort_Test2)
{
    uint32_t size = 100;
    A1 = new float[size];
    B1 = new float[size];

    fillFloatMas(A1, size, 47);
    fSorter->bubbleSort(A1, size);

    fillFloatMas(B1, size, 47);
    fSorter->gnomeSort(B1, size);

    for (uint32_t i = 0; i < size; ++i)
        ASSERT_EQ(A1[i], B1[i]);
}

TEST_F(SortingsTests, gnomeSort_Test3)
{
    uint32_t size = 1000;
    A1 = new float[size];
    B1 = new float[size];

    fillFloatMas(A1, size, 477);
    fSorter->bubbleSort(A1, size);

    fillFloatMas(B1, size, 477);
    fSorter->gnomeSort(B1, size);

    for (uint32_t i = 0; i < size; ++i)
        ASSERT_EQ(A1[i], B1[i]);
}

TEST_F(SortingsTests, bitonicSort_Test1)
{
    uint32_t size = 16;
    A1 = new float[size];
    B1 = new float[size];

    fillFloatMas(A1, size, 4);
    fSorter->bubbleSort(A1, size);

    fillFloatMas(B1, size, 4);
    fSorter->bitonicSort(B1, size);

    for (uint32_t i = 0; i < size; ++i)
        ASSERT_EQ(A1[i], B1[i]);
}

TEST_F(SortingsTests, bitonicSort_Test2)
{
    uint32_t size = 512;
    A1 = new float[size];
    B1 = new float[size];

    fillFloatMas(A1, size, 512);
    fSorter->bubbleSort(A1, size);

    fillFloatMas(B1, size, 512);
    fSorter->bitonicSort(B1, size);

    for (uint32_t i = 0; i < size; ++i)
        ASSERT_EQ(A1[i], B1[i]);
}

TEST_F(SortingsTests, bitonicSort_Test3)
{
    uint32_t size = 4096;
    A1 = new float[size];
    B1 = new float[size];

    fillFloatMas(A1, size, 4096);
    fSorter->bubbleSort(A1, size);

    fillFloatMas(B1, size, 4096);
    fSorter->bitonicSort(B1, size);

    for (uint32_t i = 0; i < size; ++i)
        ASSERT_EQ(A1[i], B1[i]);
}

TEST_F(SortingsTests, bogoSort_Test)
{
    uint32_t size = 10;
    A1 = new float[size];
    B1 = new float[size];

    fillFloatMas(A1, size, 4);
    fSorter->bubbleSort(A1, size);

    fillFloatMas(B1, size, 4);
    fSorter->bogoSort(B1, size);

    for (uint32_t i = 0; i < size; ++i)
        ASSERT_EQ(A1[i], B1[i]);
}

TEST_F(SortingsTests, timSort_Test1)
{
    uint32_t size = 10;
    A = new int[size];
    B = new int[size];

    fillIntMas(A, size, 1);
    iSorter->simpleSort(A, size);

    fillIntMas(B, size, 1);
    iSorter->timSort(B, size);

    for (uint32_t i = 0; i < size; ++i)
        ASSERT_EQ(A[i], B[i]);
}

TEST_F(SortingsTests, timSort_Test2)
{
    uint32_t size = 100;
    A1 = new float[size];
    B1 = new float[size];

    fillFloatMas(A1, size, 6);
    fSorter->bubbleSort(A1, size);

    fillFloatMas(B1, size, 6);
    fSorter->timSort(B1, size);

    for (uint32_t i = 0; i < size; ++i)
        ASSERT_EQ(A1[i], B1[i]);
}

TEST_F(SortingsTests, timSort_Test3)
{
    uint32_t size = 1000;
    A1 = new float[size];
    B1 = new float[size];

    fillFloatMas(A1, size, 16);
    fSorter->bubbleSort(A1, size);

    fillFloatMas(B1, size, 16);
    fSorter->timSort(B1, size);

    for (uint32_t i = 0; i < size; ++i)
        ASSERT_EQ(A1[i], B1[i]);
}

TEST_F(SortingsTests, strandSort_Test1)
{
    uint32_t size = 10;
    A1 = new float[size];
    B1 = new float[size];

    fillFloatMas(A1, size, 16);
    fSorter->bubbleSort(A1, size);

    fillFloatMas(B1, size, 16);
    fSorter->strandSort(B1, size);

    for (uint32_t i = 0; i < size; ++i)
        ASSERT_EQ(A1[i], B1[i]);
}

TEST_F(SortingsTests, strandSort_Test2)
{
    uint32_t size = 100;
    A1 = new float[size];
    B1 = new float[size];

    fillFloatMas(A1, size, 11);
    fSorter->bubbleSort(A1, size);

    fillFloatMas(B1, size, 11);
    fSorter->strandSort(B1, size);

    for (uint32_t i = 0; i < size; ++i)
        ASSERT_EQ(A1[i], B1[i]);
}

TEST_F(SortingsTests, strandSort_Test3)
{
    uint32_t size = 1000;
    A1 = new float[size];
    B1 = new float[size];

    fillFloatMas(A1, size, 6);
    fSorter->bubbleSort(A1, size);

    fillFloatMas(B1, size, 6);
    fSorter->strandSort(B1, size);

    for (uint32_t i = 0; i < size; ++i)
        ASSERT_EQ(A1[i], B1[i]);
}

TEST_F(SortingsTests, treeSort_Test1)
{
    uint32_t size = 10;
    A1 = new float[size];
    B1 = new float[size];

    fillFloatMas(A1, size, 16);
    fSorter->bubbleSort(A1, size);

    fillFloatMas(B1, size, 16);
    fSorter->treeSort(B1, size);

    for (uint32_t i = 0; i < size; ++i)
        ASSERT_EQ(A1[i], B1[i]);
}

TEST_F(SortingsTests, treeSort_Test2)
{
    uint32_t size = 100;
    A1 = new float[size];
    B1 = new float[size];

    fillFloatMas(A1, size, 106);
    fSorter->bubbleSort(A1, size);

    fillFloatMas(B1, size, 106);
    fSorter->treeSort(B1, size);

    for (uint32_t i = 0; i < size; ++i)
        ASSERT_EQ(A1[i], B1[i]);
}

TEST_F(SortingsTests, treeSort_Test3)
{
    uint32_t size = 250;
    A1 = new float[size];
    B1 = new float[size];

    fillFloatMas(A1, size, 2);
    fSorter->bubbleSort(A1, size);

    fillFloatMas(B1, size, 2);
    fSorter->treeSort(B1, size);

    for (uint32_t i = 0; i < size; ++i)
        ASSERT_EQ(A1[i], B1[i]);
}

TEST_F(SortingsTests, pancakeSort_Test1)
{
    uint32_t size = 10;
    A1 = new float[size];
    B1 = new float[size];

    fillFloatMas(A1, size, 16);
    fSorter->bubbleSort(A1, size);

    fillFloatMas(B1, size, 16);
    fSorter->pancakeSort(B1, size);

    for (uint32_t i = 0; i < size; ++i)
        ASSERT_EQ(A1[i], B1[i]);
}

TEST_F(SortingsTests, pancakeSort_Test2)
{
    uint32_t size = 100;
    A1 = new float[size];
    B1 = new float[size];

    fillFloatMas(A1, size, 106);
    fSorter->bubbleSort(A1, size);

    fillFloatMas(B1, size, 106);
    fSorter->pancakeSort(B1, size);

    for (uint32_t i = 0; i < size; ++i)
        ASSERT_EQ(A1[i], B1[i]);
}

TEST_F(SortingsTests, pancakeSort_Test3)
{
    uint32_t size = 1000;
    A1 = new float[size];
    B1 = new float[size];

    fillFloatMas(A1, size, 2);
    fSorter->bubbleSort(A1, size);

    fillFloatMas(B1, size, 2);
    fSorter->pancakeSort(B1, size);

    for (uint32_t i = 0; i < size; ++i)
        ASSERT_EQ(A1[i], B1[i]);
}

TEST_F(SortingsTests, stoogeSort_Test1)
{
    uint32_t size = 10;
    A1 = new float[size];
    B1 = new float[size];

    fillFloatMas(A1, size, 16);
    fSorter->bubbleSort(A1, size);

    fillFloatMas(B1, size, 16);
    fSorter->stoogeSort(B1, size);

    for (uint32_t i = 0; i < size; ++i)
        ASSERT_EQ(A1[i], B1[i]);
}

TEST_F(SortingsTests, stoogeSort_Test2)
{
    uint32_t size = 100;
    A1 = new float[size];
    B1 = new float[size];

    fillFloatMas(A1, size, 106);
    fSorter->bubbleSort(A1, size);

    fillFloatMas(B1, size, 106);
    fSorter->stoogeSort(B1, size);

    for (uint32_t i = 0; i < size; ++i)
        ASSERT_EQ(A1[i], B1[i]);
}

TEST_F(SortingsTests, stoogeSort_Test3)
{
    uint32_t size = 1000;
    A1 = new float[size];
    B1 = new float[size];

    fillFloatMas(A1, size, 2);
    fSorter->bubbleSort(A1, size);

    fillFloatMas(B1, size, 2);
    fSorter->stoogeSort(B1, size);

    for (uint32_t i = 0; i < size; ++i)
        ASSERT_EQ(A1[i], B1[i]);
}

TEST_F(SortingsTests, cycleSort_Test1)
{
    uint32_t size = 10;
    A1 = new float[size];
    B1 = new float[size];

    fillFloatMas(A1, size, 1);
    fSorter->bubbleSort(A1, size);

    fillFloatMas(B1, size, 1);
    fSorter->cycleSort(B1, size);

    for (uint32_t i = 0; i < size; ++i)
        ASSERT_EQ(A1[i], B1[i]);
}

TEST_F(SortingsTests, cycleSort_Test2)
{
    uint32_t size = 100;
    A1 = new float[size];
    B1 = new float[size];

    fillFloatMas(A1, size, 106);
    fSorter->bubbleSort(A1, size);

    fillFloatMas(B1, size, 106);
    fSorter->cycleSort(B1, size);

    for (uint32_t i = 0; i < size; ++i)
        ASSERT_EQ(A1[i], B1[i]);
}

TEST_F(SortingsTests, cycleSort_Test3)
{
    uint32_t size = 1000;
    A1 = new float[size];
    B1 = new float[size];

    fillFloatMas(A1, size, 2);
    fSorter->cycleSort(A1, size);

    fillFloatMas(B1, size, 2);
    fSorter->pancakeSort(B1, size);

    for (uint32_t i = 0; i < size; ++i)
        ASSERT_EQ(A1[i], B1[i]);
}

TEST_F(SortingsTests, introSort_Test1)
{
    uint32_t size = 10;
    A = new int[size];
    B = new int[size];

    fillIntMas(A, size, 666);
    iSorter->simpleSort(A, size);

    fillIntMas(B, size, 666);
    iSorter->introSort(B, size);

    for (uint32_t i = 0; i < size; ++i)
        ASSERT_EQ(A[i], B[i]);
}

TEST_F(SortingsTests, introSort_Test2)
{
    uint32_t size = 100;
    A = new int[size];
    B = new int[size];

    fillIntMas(A, size, 3);
    iSorter->simpleSort(A, size);

    fillIntMas(B, size, 3);
    iSorter->introSort(B, size);

    for (uint32_t i = 0; i < size; ++i)
        ASSERT_EQ(A[i], B[i]);
}

TEST_F(SortingsTests, introSort_Test3)
{
    uint32_t size = 1000;
    A = new int[size];
    B = new int[size];

    fillIntMas(A, size, 6666);
    iSorter->simpleSort(A, size);

    fillIntMas(B, size, 6666);
    iSorter->introSort(B, size);

    for (uint32_t i = 0; i < size; ++i)
        ASSERT_EQ(A[i], B[i]);
}

TEST_F(SortingsTests, introSort_Test4)
{
    uint32_t size = 10000;
    A = new int[size];
    B = new int[size];

    fillIntMas(A, size, 8);
    iSorter->simpleSort(A, size);

    fillIntMas(B, size, 8);
    iSorter->introSort(B, size);

    for (uint32_t i = 0; i < size; ++i)
        ASSERT_EQ(A[i], B[i]);
}

TEST_F(SortingsTests, introSort_Test5)
{
    uint32_t size = 10;
    A1 = new float[size];
    B1 = new float[size];

    fillFloatMas(A1, size, 21);
    fSorter->cycleSort(A1, size);

    fillFloatMas(B1, size, 21);
    fSorter->introSort(B1, size);

    for (uint32_t i = 0; i < size; ++i)
        ASSERT_EQ(A1[i], B1[i]);
}

TEST_F(SortingsTests, introSort_Test6)
{
    uint32_t size = 100;
    A1 = new float[size];
    B1 = new float[size];

    fillFloatMas(A1, size, 2);
    fSorter->cycleSort(A1, size);

    fillFloatMas(B1, size, 2);
    fSorter->introSort(B1, size);

    for (uint32_t i = 0; i < size; ++i)
        ASSERT_EQ(A1[i], B1[i]);
}

TEST_F(SortingsTests, introSort_Test7)
{
    uint32_t size = 500;
    A1 = new float[size];
    B1 = new float[size];

    fillFloatMas(A1, size, 12);
    fSorter->cycleSort(A1, size);

    fillFloatMas(B1, size, 12);
    fSorter->introSort(B1, size);

    for (uint32_t i = 0; i < size; ++i)
        ASSERT_EQ(A1[i], B1[i]);
}

TEST_F(SortingsTests, bozoSort_Test)
{
    uint32_t size = 10;
    A1 = new float[size];
    B1 = new float[size];

    fillFloatMas(A1, size, 69);
    fSorter->bubbleSort(A1, size);

    fillFloatMas(B1, size, 69);
    fSorter->bozoSort(B1, size);

    for (uint32_t i = 0; i < size; ++i)
        ASSERT_EQ(A1[i], B1[i]);
}

TEST_F(SortingsTests, permSort_Test)
{
    uint32_t size = 5;
    A1 = new float[size];
    B1 = new float[size];

    fillFloatMas(A1, size, 635);
    fSorter->bubbleSort(A1, size);

    fillFloatMas(B1, size, 635);
    fSorter->permSort(B1, size);

    for (uint32_t i = 0; i < size; ++i)
        ASSERT_EQ(A1[i], B1[i]);
}