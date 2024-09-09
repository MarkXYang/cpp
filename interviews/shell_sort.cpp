#include <iostream>
#include <array>

template <typename T, size_t N>
void swap(std::array<T, N> &arr, size_t i, size_t j)
{
    arr[i] = arr[i] ^ arr[j];
    arr[j] = arr[i] ^ arr[j];
    arr[i] = arr[i] ^ arr[j];
}

template <typename T, size_t N>
void printArray(const std::array<T, N> &arr)
{
    for (const auto &element : arr)
    {
        std::cout << element << " ";
    }
    std::cout << std::endl;
}

template <typename T, size_t N>
void insertSort(std::array<T, N> &a, size_t start, size_t incr)
{
    for (int i = start; i < N; i += incr)
    {
        for (int j = std::min(i + incr, N - 1); j - (int)incr >= 0; j -= (int)incr)
        {
            if (a[j] < a[j - incr])
            {
                swap(a, j, j - incr);
            }
            else
            {
                std::cout << "breaked: i, j: " << i << ", " << j << ", incr:" << incr << std::endl;
                break;
            }
            printArray(a);
        }
    }
}

template <typename T, size_t N>
void shellSort(std::array<T, N> &a)
{
    int incr = N / 2;
    while (incr >= 1)
    {
        for (int start = 0; start < incr; ++start)
        {
            std::cout << "start, incr: " << start << "," << incr << std::endl;
            insertSort(a, start, incr);
        }

        incr = incr / 2;
    }
}
int main()
{
    std::array<int, 20> arr = {7, 4, 2, 6, 5, 8, 9, 1, 3, 10};
    srand(time(nullptr)); // Seed the random number generator

    for (int i = 0; i < 20; ++i)
    {
        arr[i] = rand() % 20; // Generate random numbers between 0 and 20
    }

    std::cout << "Original array: ";
    printArray(arr);
    shellSort(arr);
    std::cout << "Sorted array: ";
    printArray(arr);

    std::cout << std::endl;
}