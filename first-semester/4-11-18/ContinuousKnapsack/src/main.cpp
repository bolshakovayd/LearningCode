#include "Object.h"

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
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
    cout << "\nEnter knapsack capacity: ";
    cin >> capacity;
    sort(objects.begin(), objects.end(), [](Object a, Object b) {
             return a.price / a.weight < b.price / b.weight;
         }
    );
    int sum = 0;
    for (auto i = objects.size() - 1; i >= 0; --i) {
        if (capacity >= objects[i].weight) {
            sum += objects[i].price;
            capacity -= objects[i].weight;
        } else {
            sum += capacity * objects[i].price / objects[i].weight;
            break;
        }
    }
    cout << "\nReceived price of knapsack: " << sum;
    return 0;
}
