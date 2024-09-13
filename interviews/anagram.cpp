#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<string> insertCharAtEveryIdx(const vector<std::string> &potentialAnaList, char currChar)
{
    vector<std::string> anaList;
    for (const auto &aword : potentialAnaList)
    {
        for (size_t idx = 0; idx <= aword.length(); ++idx)
        {
            string new_word = aword;
            new_word.insert(idx, 1, currChar);
            anaList.push_back(new_word);
        }
    }
    return anaList;
}

vector<string> findAnagrams(const string &word)
{
    if (word.length() == 1)
    {
        return {word};
    }

    char ch = word[0];
    string substr = word.substr(1);
    vector<string> potentialAnaList = findAnagrams(substr);
    return insertCharAtEveryIdx(potentialAnaList, ch);
}

int main()
{
    vector<std::string> test_words = {"cat", "dog", "hello"};
    for (const auto &word : test_words)
    {
        cout << "Anagrams of '" << word << "':" << endl;
        vector<string> anagrams = findAnagrams(word);
        for (const auto &anagram : anagrams)
        {
            cout << anagram << endl;
        }
        cout << endl; // Empty line for better readability
    }
    return 0;
}