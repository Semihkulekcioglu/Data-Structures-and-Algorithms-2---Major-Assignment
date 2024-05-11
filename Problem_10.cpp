#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int findKthElement(vector<int>& arr1, vector<int>& arr2, int N, int M, int k) {
    if (N > M) {
        return findKthElement(arr2, arr1, M, N, k);
    }

    int low = max(0, k - M); 
    int high = min(k, N);

    while (low <= high) {
        int i = (low + high) / 2;
        int j = k - i;

        int arr1LeftMax = (i == 0) ? INT_MIN : arr1[i - 1];
        int arr1RightMin = (i == N) ? INT_MAX : arr1[i];
        int arr2LeftMax = (j == 0) ? INT_MIN : arr2[j - 1];
        int arr2RightMin = (j == M) ? INT_MAX : arr2[j];

        if (arr1LeftMax <= arr2RightMin && arr2LeftMax <= arr1RightMin) {
            return max(arr1LeftMax, arr2LeftMax);
        }
        else if (arr1LeftMax > arr2RightMin) {
            high = i - 1;
        }
        else {
            low = i + 1;
        }
    }

    return -1;
}

int main() {
    // Ex - 1
    vector<int> arr1 = { 2, 3, 6, 7, 9 };
    vector<int> arr2 = { 1, 4, 8, 10 };
    int N1 = arr1.size();
    int M1 = arr2.size();
    int k1 = 5;
    cout << findKthElement(arr1, arr2, N1, M1, k1) << endl; // Output: 6

    // Ex - 2
    vector<int> arr3 = { 100, 112, 256, 349, 770 };
    vector<int> arr4 = { 72, 86, 113, 119, 265, 445, 892 };
    int N2 = arr3.size();
    int M2 = arr4.size();
    int k2 = 7;
    cout << findKthElement(arr3, arr4, N2, M2, k2) << endl; // Output: 256

    return 0;
}
