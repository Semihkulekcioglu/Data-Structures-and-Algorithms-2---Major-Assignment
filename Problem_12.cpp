#include <iostream>
#include <vector>

using namespace std;

int numberSequence(int m, int n) {
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    for (int i = 1; i <= m; ++i) {
        dp[i][1] = 1;
    }

    for (int j = 2; j <= n; ++j) {
        for (int i = 1; i <= m; ++i) {
            for (int k = 1; k <= i / 2; ++k) {
                dp[i][j] += dp[k][j - 1];
            }
        }
    }

    int ans = 0;
    for (int i = 1; i <= m; ++i) {
        ans += dp[i][n];
    }

    return ans;
}

int main() {
    // Ex - 1
    int m1 = 10, n1 = 4;
    cout << numberSequence(m1, n1) << endl; // Output: 4

    // Ex - 2
    int m2 = 5, n2 = 2;
    cout << numberSequence(m2, n2) << endl; // Output: 6

    return 0;
}
