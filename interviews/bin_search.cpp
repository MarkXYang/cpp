#include <iostream>
#include <vector>

using namespace std;

template <typename T>
int bin_search(vector<T> &v, T target, int low, int high)
{
    if (low > high)
        return -1;
    int middle = low + (high - low) / 2;
    if (target == v.at(middle))
    {
        return middle;
    }
    else if (target < v.at(middle))
    {
        return bin_search(v, target, low, middle - 1);
    }
    else
    {
        return bin_search(v, target, middle + 1, high);
    }
}

int main()
{
    // Create a sorted vector of integers
    vector<int> numbers = {1, 3, 4, 6, 8, 9, 11, 13, 16, 17, 19, 20};

    cout << "Vector contents: ";
    for (const auto &num : numbers)
    {
        cout << num << " ";
    }
    cout << endl;

    // Test cases
    vector<int> targets = {1, 11, 20, 7, 21};

    for (const auto &target : targets)
    {
        int result = bin_search(numbers, target, 0, numbers.size() - 1);

        if (result != -1)
        {
            cout << "Target " << target << " found at index " << result << endl;
        }
        else
        {
            cout << "Target " << target << " not found in the vector" << endl;
        }
    }

    return 0;
}