#include <iostream>
#include <vector>

using namespace std;

// 0. print vector
template <typename T>
void printVector(const vector<T> &v)
{
    for (const auto &element : v)
    {
        cout << element << " ";
    }
    cout << endl;
}

// 1. Split function
template <typename T>
void split(vector<T> &v, vector<T> &vFirst, vector<T> &vSecond)
{
    int len = v.size();

    int index = 0;
    int index_second = len / 2;
    vFirst.clear();
    vSecond.clear();

    for (auto &e : v)
    {
        if (index < index_second)
        {
            vFirst.push_back(v.at(index));
        }
        else
        {
            vSecond.push_back(v.at(index));
        }
        ++index;
    }
    /*
    cout << "vFirst\n";
    printVector(vFirst);
    cout << "vSecond\n";
    printVector(vSecond);
    */
}
// 2. Merge function
template <typename T>
void merge(vector<T> &vMerged, vector<T> &vFirst, vector<T> &vSecond)
{
    int index = 0;
    int idx_first = 0;
    int idx_second = 0;
    vMerged.clear();
    while (idx_first < vFirst.size() && idx_second < vSecond.size())
    {
        if (vFirst.at(idx_first) < vSecond.at(idx_second))
        {
            vMerged.push_back(vFirst.at(idx_first++));
        }
        else if (idx_second < vSecond.size())
        {
            vMerged.push_back(vSecond.at(idx_second++));
        }
    }

    while (idx_first < vFirst.size())
    {
        vMerged.push_back(vFirst.at(idx_first++));
    }

    while (idx_second < vSecond.size())
    {
        vMerged.push_back(vSecond.at(idx_second++));
    }
}
// 3. Mergesort function to recursive call
template <typename T>
void mergeSort(vector<T> &vToSort)
{
    if (vToSort.size() == 1)
    {
        return;
    }

    vector<T> vFirst;
    vector<T> vSecond;
    split(vToSort, vFirst, vSecond);
    vToSort.clear();

    mergeSort(vFirst);
    mergeSort(vSecond);

    merge(vToSort, vFirst, vSecond);

    // printVector(vToSort);
}

int main()
{
    // Create a vector of integers with 20 elements to sort, limited to max value of 20
    std::vector<int> numbers = {7, 4, 2, 6, 5, 8, 9, 1, 3, 10, 15, 12, 18, 20, 11, 13, 16, 19, 14, 17};

    std::cout
        << "Original vector: ";

    printVector(numbers);

    // Call mergeSort function
    mergeSort(numbers);

    std::cout << "Sorted vector: ";
    printVector(numbers);

    return 0;
}
