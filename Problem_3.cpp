#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Job {
    int id;
    int deadline;
    int profit;
};

bool compareJobs(const Job& a, const Job& b) {
    return a.profit > b.profit; 
}


vector<int> JobScheduling(int N, vector<Job>& jobs) {

    sort(jobs.begin(), jobs.end(), compareJobs);

    vector<bool> slot(N, false); 
    vector<int> result(2, 0);     

    for (int i = 0; i < N; ++i) {
        for (int j = min(N, jobs[i].deadline) - 1; j >= 0; --j) {
            if (!slot[j]) {
                slot[j] = true;  
                result[0]++;     
                result[1] += jobs[i].profit; 
                break;
            }
        }
    }

    return result;
}

int main() {
    // Ex - 1
    int N1 = 4;
    vector<Job> jobs1 = { {1, 4, 20}, {2, 1, 10}, {3, 1, 40}, {4, 1, 30} };
    vector<int> result1 = JobScheduling(N1, jobs1);
    cout << result1[0] << " " << result1[1] << endl;  // Output: 2 60

    // Ex - 2
    int N2 = 5;
    vector<Job> jobs2 = { {1, 2, 100}, {2, 1, 19}, {3, 2, 27}, {4, 1, 25}, {5, 1, 15} };
    vector<int> result2 = JobScheduling(N2, jobs2);
    cout << result2[0] << " " << result2[1] << endl;  // Output: 2 127

    return 0;
}
