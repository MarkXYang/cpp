#include <iostream>
#include <sstream>
#include <string>

using namespace std;

string encode(string orig_str)
{
    if(orig_str.empty()) {
        return "";
    }

    stringstream ss; 
    int curIndex = 0;
    while(curIndex < orig_str.length() ) {
        char curChar = orig_str.at(curIndex);

        int num = 0;
        int compareIndex = curIndex;
        while(compareIndex < orig_str.length() && curChar == orig_str.at(compareIndex)) {
            compareIndex++;
            num++;
        }
        ss << num << curChar;

        curIndex = compareIndex;
    }
    return ss.str();
}

string decode(string encoded_str)
{
    if(encoded_str.empty()) {
        return "";
    }

    stringstream ss(encoded_str);
    string result;
    int count;
    char ch;

    while (ss >> count >> ch) {
        result.append(count, ch);
    }

    return result;
}

int main()
{

    string s = "AABBCCC";
    cout << encode(s) << endl;

    string coded = "1a23b3c";

    cout << decode(coded) << endl;

    return 0;
}

