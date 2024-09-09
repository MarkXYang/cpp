#include <iostream>
#include <vector>

using namespace std;

template <typename T>
void printVector(const vector<T> &v)
{
    for (const auto &element : v)
    {
        cout << element << " ";
    }
    cout << endl;
}

template <typename T>
void swap(vector<T> &vToSort, int low, int high)
{
    T temp = vToSort[low];
    vToSort[low] = vToSort[high];
    vToSort[high] = temp;
}

template <class T>
int partition(vector<T> &vToSort, int low, int high)
{
    // int len = vToSort.size();
    int pivot = vToSort.at(low);
    int l = low;
    int h = high;

    // scan from low and high to the middle
    while (l < h)
    {
        while (vToSort.at(l) <= pivot && l < h)
        {
            l++;
        }
        while (vToSort[h] > pivot)
        {
            h--;
        }
        if (l < h)
        {
            swap(vToSort, l, h);
        }
    }
    swap(vToSort, low, h);

    cout << "Pivot: " << pivot << endl;
    printVector(vToSort);
    return h;
}

template <typename T>
void quickSort(vector<T> &vToSort, int low, int high)
{
    if (low >= high)
        return;

    int pivotIndex = partition(vToSort, low, high);
    quickSort(vToSort, low, pivotIndex - 1);
    quickSort(vToSort, pivotIndex + 1, high);
}

int main()
{

    // Create a vector of integers with 20 elements to sort, limited to max value of 20
    std::vector<int> numbers = {7, 4, 2, 6, 5, 8, 9, 1, 3, 10, 15, 12, 18, 20, 11, 13, 16, 19, 14, 17};

    std::cout << "Original vector: ";
    printVector(numbers);

    // Call quickSort function
    quickSort(numbers, 0, numbers.size() - 1);

    std::cout << "Sorted vector: ";
    printVector(numbers);

    return 0;
}
