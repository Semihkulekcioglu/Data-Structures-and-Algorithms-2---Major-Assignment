#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


struct Meeting {
    int start;
    int end;
};

bool compareEndTimes(const Meeting& a, const Meeting& b) {
    return a.end < b.end;
}

int maxMeetingsCount(vector<int>& start, vector<int>& end, int N) {
    vector<Meeting> meetings(N);
    for (int i = 0; i < N; ++i) {
        meetings[i] = { start[i], end[i] };
    }

    sort(meetings.begin(), meetings.end(), compareEndTimes);

    int count = 1; 
    int prevEnd = meetings[0].end;  

    for (int i = 1; i < N; ++i) {
        if (meetings[i].start > prevEnd) {
            count++;
            prevEnd = meetings[i].end;
        }
    }

    return count;
}

int main() {
    // Ex - 1
    int N1 = 6;
    vector<int> start1 = { 1, 3, 0, 5, 8, 5 };
    vector<int> end1 = { 2, 4, 6, 7, 9, 9 };
    cout << maxMeetingsCount(start1, end1, N1) << endl;  // Output: 4

    // Ex - 2
    int N2 = 3;
    vector<int> start2 = { 10, 12, 20 };
    vector<int> end2 = { 20, 25, 30 };
    cout << maxMeetingsCount(start2, end2, N2) << endl;  // Output: 1

    return 0;
}
