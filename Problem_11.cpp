#include <iostream>
#include <vector>
#include <climits>
#include <numeric>

using namespace std;

bool isPossible(vector<int>& A, int N, int M, int mid) {
    int students = 1;
    int pagesRead = 0;

    for (int i = 0; i < N; ++i) {
        if (A[i] > mid) {
            return false;
        }

        if (pagesRead + A[i] > mid) {
            students++;
            pagesRead = A[i];
            if (students > M) {
                return false;
            }
        }
        else {
            pagesRead += A[i];
        }
    }

    return true;
}

int findPages(vector<int>& A, int N, int M) {
    if (N < M) {
        return -1;
    }

    int totalSum = accumulate(A.begin(), A.end(), 0);
    int low = 0, high = totalSum;
    int result = INT_MAX;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (isPossible(A, N, M, mid)) {
            result = min(result, mid);
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }

    return result;
}

int main() {
    // Ex - 1
    int N1 = 4, M1 = 2;
    vector<int> A1 = { 12, 34, 67, 90 };
    cout << findPages(A1, N1, M1) << endl; // Output: 113

    // Ex - 2
    int N2 = 3, M2 = 2;
    vector<int> A2 = { 15, 17, 20 };
    cout << findPages(A2, N2, M2) << endl; // Output: 32

    return 0;
}
