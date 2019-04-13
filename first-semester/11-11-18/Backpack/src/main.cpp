#include "Object.h"

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>

using namespace std;

int main() {
    auto my_max = [](int a, int b) {
        if (a > b) {
            return a;
        }
        return b;
    };

    vector<Object> objects;
    int numberOfObjects;
    cout << "\nEnter number of objects: ";
    cin >> numberOfObjects;
    cout << "\nEnter name (one word), weight, price of new object:\n";
    for (int i = 0; i < numberOfObjects; ++i) {
        Object temp;
        cin >> temp.name >> temp.weight >> temp.price;
        objects.push_back(temp);
    }

    int capacity;
    cout << "\nEnter backpack capacity: ";
    cin >> capacity;
    vector<vector<int>> mat(static_cast<unsigned long>(numberOfObjects + 1), vector<int>(capacity + 1, INT32_MIN));
    for (auto i = 0; i <= capacity; ++i) {
        mat[0][i] = 0;
    }
    for (auto i = 0; i <= numberOfObjects; ++i) {
        mat[i][0] = 0;
    }

    for (int k = 1; k <= numberOfObjects; ++k) {
        for (int s = 1; s <= capacity; ++s) {
            if (s >= objects[k].weight) {
                mat[k][s] = my_max(mat[k - 1][s], mat[k - 1][s - objects[k].weight] + objects[k].price);
            } else {
                mat[k][s] = mat[k - 1][s];
            }
        }
    }

    vector<int> ans;
    function<void(int, int)> findAns;
    findAns = [&](int k, int s) {
        if (mat[k][s] == 0) {
            return;
        }
        if (mat[k - 1][s] == mat[k][s]) {
            findAns(k - 1, s);
        } else {
            findAns(k - 1, s - objects[k].weight);
            ans.push_back(k);
        }
    };
    findAns(numberOfObjects, capacity);

    cout << "\nObjects in backpack: ";
    for_each(ans.begin(), ans.end(), [&](int current) { cout << ' ' << objects[current].name; });
    cout << endl;
    return 0;
}
