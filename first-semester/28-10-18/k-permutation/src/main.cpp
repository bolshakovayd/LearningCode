#include <iostream>

using namespace std;

int search(bool *used, int key, int n) {
    int i;
    for (i = 1; i <= n; i++) {
        if (!used[i]) {
            key--;
        }
        if (key == 0)
            return i;
    }
    return 0;
}

void kPermutation(int n, int k) {
    int i;
    int key, value;
    bool *used = new bool[n + 1];
    int *fact = new int[n];
    int *ans = new int[n];
    for (i = 0; i <= n; ++i) {
        used[i] = false;
    }
    fact[n - 1] = 1;
    for (i = n - 2; i >= 0; --i) {
        fact[i] = fact[i + 1] * (n - i - 1);
    }
    k--;
    for (i = 0; i < n; ++i) {
        key = k / fact[i];
        value = search(used, key + 1, n);
        ans[i] = value;
        used[value] = true;
        k = k % fact[i];
    }
    for (i = 0; i < n; ++i) {
        cout << ans[i] << " ";
    }
    cout << endl;
    delete[] used;
    delete[] fact;
    delete[] ans;
}

int main() {
    kPermutation(10, 10000);
    return 0;
}
