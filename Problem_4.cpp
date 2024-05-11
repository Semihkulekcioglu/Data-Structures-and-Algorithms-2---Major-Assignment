#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Pair {
    int first;
    int second;
};

bool comparePairs(const Pair& a, const Pair& b) {
    return a.second < b.second;
}

int maxChainLen(vector<Pair>& pairs) {
    sort(pairs.begin(), pairs.end(), comparePairs);

    int maxLength = 0;
    int currentEnd = INT_MIN;

    for (const auto& pair : pairs) {
        if (pair.first > currentEnd) {
            maxLength++;
            currentEnd = pair.second;
        }
    }

    return maxLength;
}

int main() {
    // Ex - 1
    int N1 = 5;
    vector<Pair> pairs1 = { {5, 24}, {39, 60}, {15, 28}, {27, 40}, {50, 90} };
    cout << maxChainLen(pairs1) << endl;  // Output: 3

    // Ex - 2
    int N2 = 2;
    vector<Pair> pairs2 = { {5, 10}, {1, 11} };
    cout << maxChainLen(pairs2) << endl;  // Output: 1

    return 0;
}
