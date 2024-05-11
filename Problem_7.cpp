#include <iostream>
#include <vector>

using namespace std;

bool isSafe(int v, vector<vector<int>>& graph, vector<int>& color, int c) {
    for (int i = 0; i < graph.size(); ++i) {
        if (graph[v][i] && color[i] == c) {
            return false;
        }
    }
    return true;
}

bool graphColoringUtil(int v, int M, vector<vector<int>>& graph, vector<int>& color) {
    if (v == graph.size()) {
        return true;
    }

    for (int c = 1; c <= M; ++c) {
        if (isSafe(v, graph, color, c)) {
            color[v] = c;
            if (graphColoringUtil(v + 1, M, graph, color)) {
                return true;
            }
            color[v] = 0;
        }
    }

    return false;
}

bool graphColoring(int N, int M, vector<vector<int>>& graph) {
    vector<int> color(N, 0); 

    return graphColoringUtil(0, M, graph, color);
}

int main() {
    // Ex - 1
    int N1 = 4, M1 = 3;
    vector<vector<int>> graph1 = { {0, 1, 0, 1},
                                   {1, 0, 1, 0},
                                   {0, 1, 0, 1},
                                   {1, 0, 1, 0} };
    cout << graphColoring(N1, M1, graph1) << endl; // Output: 1

    // Ex - 2
    int N2 = 3, M2 = 2;
    vector<vector<int>> graph2 = { {0, 1, 1},
                                   {1, 0, 1},
                                   {1, 1, 0} };
    cout << graphColoring(N2, M2, graph2) << endl; // Output: 0

    return 0;
}
