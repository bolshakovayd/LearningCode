#include <iostream>
#include "Stack.h"
#include <string>

using namespace std;

int main() {
    Stack s;

    string str;
    cout << "Enter brackets sequence: ";
    cin >> str;
    for (auto i = 0; i < str.length(); ++i) {
        if (str[i] == '(') {
            s.push(1);
        }
        if (str[i] == ')') {
            if (s.isEmpty()) {
                cout << "Sequence is incorrect";
                return 0;
            }
            s.pop();
        }
    }
    if (s.isEmpty()) {
        cout << "Sequence is correct";
    } else {
        cout << "Sequence is incorrect";
    }
    return 0;
}
