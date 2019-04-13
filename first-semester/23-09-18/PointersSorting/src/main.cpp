#include "WordMap.h"

#include <iostream>
#include <string>

using namespace std;

void swap(std::string *stringPtr1, std::string *stringPtr2) {
    std::string temp = *stringPtr1;
    *stringPtr1 = *stringPtr2;
    *stringPtr2 = temp;
}

int main() {
    unsigned int n;
    cout << "Enter a number of elements: ";
    cin >> n;
    std::string *array = new string[n];

    cout << "Enter n \"words\" using symbols 0...9 or A/a...Z/z: ";

    for (auto i = 0; i < n; ++i) {
        cin >> array[i];
    }

    //sorting lexicographically

    //for each word
    for (auto i = array; i < array + n; ++i) {
        for (auto j = array + n - 1; j > i; --j) {
            //for each letter
            for (auto l = 0; l < (*j).size() && l < (*(j - 1)).size(); ++l) {
                if (wordMap[(*j)[l]] < wordMap[((*(j - 1))[l])]) {
                    swap(j, j - 1);
                    break;
                } else if (wordMap[(*j)[l]] > wordMap[((*(j - 1))[l])]) {
                    break;
                }
            }
        }
    }

    for (auto i = array; i < array + n; ++i) {
        cout << *i << endl;
    }
    return 0;
}
