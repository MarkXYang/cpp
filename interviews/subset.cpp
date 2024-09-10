#include <iostream>

/* Get all the subset for a set. E.g. a set is {1, 2}, the subset will be {}, {1}, {2}, {1,2}*/
#include <vector>
#include <cmath>

using namespace std;
// Optimized version of getSubsets function
template <typename T>
vector<vector<T>> getSubsets(const vector<T> &set)
{
    vector<vector<T>> subsets;
    subsets.reserve(1 << set.size()); // Pre-allocate memory for efficiency

    for (size_t i = 0; i < (1 << set.size()); ++i)
    {
        vector<T> subset;
        subset.reserve(__builtin_popcount(i)); // Pre-allocate based on set bits

        for (size_t j = 0; j < set.size(); ++j)
        {
            if (i & (1 << j))
            {
                subset.push_back(set[j]);
            }
        }
        subsets.push_back(move(subset)); // Use move semantics
    }

    return subsets;
}

// Optimized version of printSubsets function
template <typename T>
void printSubsets(const vector<vector<T>> &subsets)
{
    for (const auto &subset : subsets)
    {
        cout << '{';
        if (!subset.empty())
        {
            cout << subset[0];
            for (size_t i = 1; i < subset.size(); ++i)
            {
                cout << ", " << subset[i];
            }
        }
        cout << "}\n";
    }
}

int main()
{
    std::vector<int> set = {1, 2, 3};
    std::cout << "Set: {1, 2, 3}" << std::endl;
    std::cout << "Subsets:" << std::endl;
    auto subsets = getSubsets(set);
    printSubsets(subsets);

    return 0;
}
