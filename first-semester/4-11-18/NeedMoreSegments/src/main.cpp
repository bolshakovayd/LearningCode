#include "Segment.h"

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    std::cout << "Enter the number segments: ";
    int n;
    cin >> n;
    vector<Segment> segments;
    std::cout << "Enter beginnings and endings of segments lying in the interval [0, 100]: ";
    for (auto i = 0; i < n; ++i) {
        Segment temp{};
        cin >> temp.beginning >> temp.ending;
        segments.push_back(temp);
    }
    sort(segments.begin(), segments.end(),
         [](Segment a, Segment b) {
             return a.ending < b.ending;
         }
    );

    int ans = 1;
    for (auto i = 1; i < segments.size(); ++i) {
        if (segments[i - 1].ending > segments[i].beginning) {
            segments.erase(segments.begin() + i);
            --i;
            continue;
        }
        if (segments[i].ending <= 100) {
            ans++;
        } else {
            break;
        }
    }
    cout << "Maximum number of non-intersecting segments is " << ans;
    return 0;
}
