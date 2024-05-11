#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

bool isValidMove(int x, int y, int N, vector<vector<int>>& m, vector<vector<bool>>& visited) {
    return x >= 0 && x < N && y >= 0 && y < N && m[x][y] == 1 && !visited[x][y];
}

void findPaths(int x, int y, int N, vector<vector<int>>& m, vector<vector<bool>>& visited, string path, vector<string>& result) {
    visited[x][y] = true;

    if (x == N - 1 && y == N - 1) {
        result.push_back(path);
    }
    else {
        if (isValidMove(x + 1, y, N, m, visited)) findPaths(x + 1, y, N, m, visited, path + 'D', result); // Down
        if (isValidMove(x - 1, y, N, m, visited)) findPaths(x - 1, y, N, m, visited, path + 'U', result); // Up
        if (isValidMove(x, y + 1, N, m, visited)) findPaths(x, y + 1, N, m, visited, path + 'R', result); // Right
        if (isValidMove(x, y - 1, N, m, visited)) findPaths(x, y - 1, N, m, visited, path + 'L', result); // Left
    }

    visited[x][y] = false;
}

vector<string> printPath(int N, vector<vector<int>>& m) {
    vector<string> result;

    if (m[0][0] == 0 || m[N - 1][N - 1] == 0) return result;

    vector<vector<bool>> visited(N, vector<bool>(N, false));

    findPaths(0, 0, N, m, visited, "", result);

    sort(result.begin(), result.end());

    return result;
}

int main() {
    // Ex - 1
    int N1 = 4;
    vector<vector<int>> m1 = { {1, 0, 0, 0},
                               {1, 1, 0, 1},
                               {1, 1, 0, 0},
                               {0, 1, 1, 1} };
    vector<string> result1 = printPath(N1, m1);
    for (const string& path : result1) {
        cout << path << " ";
    }
    cout << endl;  // Output: DDRDRR DRDDRR

    // Ex - 2
    int N2 = 2;
    vector<vector<int>> m2 = { {1, 0},
                               {1, 0} };
    vector<string> result2 = printPath(N2, m2);
    if (result2.empty()) {
        cout << "-1" << endl; // Output: -1
    }

    return 0;
}
