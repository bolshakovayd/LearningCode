#include <iostream>
#include <vector>

using namespace std;

void deleteDuplication(vector<int> &a) {
    int n = a.size();
    for (int i = 0, m = 0; i != n; ++i, n = m) {
        for (int j = m = i + 1; j != n; ++j) {
            if (a[j] != a[i]) {
                if (m != j) a[m] = a[j];
                m++;
            }
        }
    }

    if (n != a.size()) {
        vector<int> b;
        for (int i = 0; i < n; ++i) {
            b.push_back(a[i]);
        }
        a = b;
    }
}

void print(vector<int> a) {
    cout << endl;
    for (auto i = 0; i < a.size(); ++i) {
        cout << a[i] << "  ";
    }
    cout << endl;
}

int main() {
    int n;
    cout << "\nEnter number of elements: ";
    cin >> n;
    vector<int> a(n);
    cout << "\nEnter " << n << " elements: ";
    for (auto i = 0; i < n; ++i) {
        cin >> a[i];
    }
    cout << "\nGiven: ";
    print(a);
    deleteDuplication(a);
    cout << "\nReceived: ";
    print(a);
    return 0;
}
