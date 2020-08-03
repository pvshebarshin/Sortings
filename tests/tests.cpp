#include <algorithm>
#include "../src/Sorter.cpp"

using testing::Eq;

namespace {
    class SortingsTests : public testing::Test {
    public:
        Sorter<float>* fSorter = nullptr;
        Sorter<int>* iSorter = nullptr;
        int* A = nullptr;
        int* B = nullptr;
        float* A1 = nullptr;
        float* B1 = nullptr;
        SortingsTests(){
            fSorter = new Sorter<float>();
            iSorter = new Sorter<int>();
        }

        ~SortingsTests() override{
            delete fSorter;
            delete iSorter;

            delete[] A;
            delete[] B;
            delete[] A1;
            delete[] B1;
        }

        void fillIntMas(int* mas, const uint32_t& size, const uint32_t& r)
        {
            srand(r);
            for (int i = 0; i < size; ++i)
                mas[i] = rand();
        }
        void fillfloatMas(float* mas, const uint32_t& size, const uint32_t& r)
        {
            srand(r);
            for (int i = 0; i < size; ++i)
                mas[i] = rand() / RAND_MAX + rand();
        }
    };
}

TEST_F(SortingsTests, countingSort_Test) {
    uint32_t size = 10;
    A = new int[size];
    B = new int[size];

    fillIntMas(A, size, 1);
    iSorter->simpleSort(A, size);

    fillIntMas(B, size, 1);
    iSorter->countingSort(B, size);

    for(uint32_t i = 0; i < size; ++i)
        ASSERT_EQ(A[i], B[i]);
}

//TEST_F(SortingsTests, radixSort_Test) {
//    uint32_t size = 10;
//    A = new int[size];
//    B = new int[size];
//
//    fillIntMas(A, size, 4);
//    iSorter->simpleSort(A, size);
//
//    fillIntMas(B, size, 4);
//    iSorter->radixSort(B, size);
//
//    for(uint32_t i = 0; i < size; ++i)
//        ASSERT_EQ(A[i], B[i]);
//}

TEST_F(SortingsTests, mergeSort_Test) {
    uint32_t size = 10;
    A1 = new float[size];
    B1 = new float[size];

    fillfloatMas(A1, size, 4);
    fSorter->simpleSort(A1, size);

    fillfloatMas(B1, size, 4);
    fSorter->mergeSort(B1, size);

    for(uint32_t i = 0; i < size; ++i)
        ASSERT_EQ(A1[i], B1[i]);
}

//TEST_F(SortingsTests, heapSort_Test) {
//    uint32_t size = 10;
//    A1 = new float[size];
//    B1 = new float[size];
//
//    fillfloatMas(A1, size, 33);
//    fSorter->simpleSort(A1, size);
//
//    fillfloatMas(B1, size, 33);
//    fSorter->heapSort(B1, size);
//
//    for(uint32_t i = 0; i < size; ++i)
//        ASSERT_EQ(A1[i], B1[i]);
//}

TEST_F(SortingsTests, quickSort_Test) {
    uint32_t size = 10;
    A1 = new float[size];
    B1 = new float[size];

    fillfloatMas(A1, size, 4);
    fSorter->simpleSort(A1, size);

    fillfloatMas(B1, size, 4);
    fSorter->quickSort(B1, size);

    for(uint32_t i = 0; i < size; ++i)
        ASSERT_EQ(A1[i], B1[i]);
}

TEST_F(SortingsTests, bubbleSort_Test) {
    uint32_t size = 10;
    A1 = new float[size];
    B1 = new float[size];

    fillfloatMas(A1, size, 4);
    fSorter->quickSort(A1, size);

    fillfloatMas(B1, size, 4);
    fSorter->bubbleSort(B1, size);

    for(uint32_t i = 0; i < size; ++i)
        ASSERT_EQ(A1[i], B1[i]);
}

TEST_F(SortingsTests, shakerSort_Test) {
    uint32_t size = 10;
    A1 = new float[size];
    B1 = new float[size];

    fillfloatMas(A1, size, 4);
    fSorter->simpleSort(A1, size);

    fillfloatMas(B1, size, 4);
    fSorter->shakerSort(B1, size);

    for(uint32_t i = 0; i < size; ++i)
        ASSERT_EQ(A1[i], B1[i]);
}

TEST_F(SortingsTests, combSort_Test) {
    uint32_t size = 10;
    A1 = new float[size];
    B1 = new float[size];

    fillfloatMas(A1, size, 4);
    fSorter->combSort(A1, size);

    fillfloatMas(B1, size, 4);
    fSorter->bubbleSort(B1, size);

    for(uint32_t i = 0; i < size; ++i)
        ASSERT_EQ(A1[i], B1[i]);
}

TEST_F(SortingsTests, shellSort_Test) {
    uint32_t size = 10;
    A1 = new float[size];
    B1 = new float[size];

    fillfloatMas(A1, size, 4);
    fSorter->shellSort(A1, size);

    fillfloatMas(B1, size, 4);
    fSorter->simpleSort(B1, size);

    for(uint32_t i = 0; i < size; ++i)
        ASSERT_EQ(A1[i], B1[i]);
}

TEST_F(SortingsTests, oddEvenSort_Test) {
    uint32_t size = 10;
    A1 = new float[size];
    B1 = new float[size];

    fillfloatMas(A1, size, 4);
    fSorter->bubbleSort(A1, size);

    fillfloatMas(B1, size, 4);
    fSorter->oddEvenSort(B1, size);

    for(uint32_t i = 0; i < size; ++i)
        ASSERT_EQ(A1[i], B1[i]);
}

TEST_F(SortingsTests, simpleSort_Test) {
    uint32_t size = 10;
    A1 = new float[size];
    B1 = new float[size];

    fillfloatMas(A1, size, 4);
    fSorter->bubbleSort(A1, size);

    fillfloatMas(B1, size, 4);
    fSorter->simpleSort(B1, size);

    for(uint32_t i = 0; i < size; ++i)
        ASSERT_EQ(A1[i], B1[i]);
}

TEST_F(SortingsTests, selectionSort_Test) {
    uint32_t size = 10;
    A1 = new float[size];
    B1 = new float[size];

    fillfloatMas(A1, size, 4);
    fSorter->bubbleSort(A1, size);

    fillfloatMas(B1, size, 4);
    fSorter->selectionSort(B1, size);

    for(uint32_t i = 0; i < size; ++i)
        ASSERT_EQ(A1[i], B1[i]);
}

TEST_F(SortingsTests, insertionSort_Test) {
    uint32_t size = 10;
    A1 = new float[size];
    B1 = new float[size];

    fillfloatMas(A1, size, 4);
    fSorter->bubbleSort(A1, size);

    fillfloatMas(B1, size, 4);
    fSorter->insertionSort(B1, size);

    for(uint32_t i = 0; i < size; ++i)
        ASSERT_EQ(A1[i], B1[i]);
}

TEST_F(SortingsTests, gnomeSort_Test) {
    uint32_t size = 10;
    A1 = new float[size];
    B1 = new float[size];

    fillfloatMas(A1, size, 4);
    fSorter->bubbleSort(A1, size);

    fillfloatMas(B1, size, 4);
    fSorter->gnomeSort(B1, size);

    for(uint32_t i = 0; i < size; ++i)
        ASSERT_EQ(A1[i], B1[i]);
}

TEST_F(SortingsTests, bitonicSort_Test) {
    uint32_t size = 16;
    A1 = new float[size];
    B1 = new float[size];

    fillfloatMas(A1, size, 4);
    fSorter->bubbleSort(A1, size);

    fillfloatMas(B1, size, 4);
    fSorter->bitonicSort(B1, size);

    for(uint32_t i = 0; i < size; ++i)
        ASSERT_EQ(A1[i], B1[i]);
}

TEST_F(SortingsTests, bogoSort_Test) {
    uint32_t size = 10;
    A1 = new float[size];
    B1 = new float[size];

    fillfloatMas(A1, size, 4);
    fSorter->bubbleSort(A1, size);

    fillfloatMas(B1, size, 4);
    fSorter->bogoSort(B1, size);

    for(uint32_t i = 0; i < size; ++i)
        ASSERT_EQ(A1[i], B1[i]);
}