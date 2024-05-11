#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Pair {
    int first;
    int second;
};

bool comparePairs(const Pair& a, const Pair& b) {
    return a.first < b.first;
}

int maxChainLen(vector<Pair>& pairs) {
    sort(pairs.begin(), pairs.end(), comparePairs);

    vector<int> dp(pairs.size(), 1);

    for (int i = 1; i < pairs.size(); ++i) {
        for (int j = 0; j < i; ++j) {
            if (pairs[i].first > pairs[j].second && dp[i] < dp[j] + 1) {
                dp[i] = dp[j] + 1;
            }
        }
    }

    int maxLength = *max_element(dp.begin(), dp.end());

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
