#include <iostream>
#include <vector>

using namespace std;

int partition(vector<int> &vec, int left, int right) {
    int separator = vec[(left + right) / 2];
    int i = left;
    int j = right;
    while (i <= j) {
        while (vec[i] < separator) {
            i++;
        }
        while (vec[j] > separator) {
            j--;
        }
        if (i >= j) {
            break;
        }
        swap(vec[i++], vec[j--]);
    }
    return j;
}

int kStats(vector<int> vec, int k) {
    int left = 0;
    int right = static_cast<int>(vec.size());
    while (true) {
        int middle = partition(vec, left, right);
        if (middle == k) {
            return vec[middle];
        } else if (k < middle) {
            right = middle;
        } else {
            k -= middle + 1;
            left = middle + 1;
        }
    }
}

int main() {
    vector<int> vec;
    int n;
    cin >> n;
    for (auto i = 0; i < n; ++i) {
        int temp;
        cin >> temp;
        vec.push_back(temp);
    }
    int k;
    cin >> k;
    kStats(vec, k);
    return 0;
}
