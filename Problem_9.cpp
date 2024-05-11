#include <iostream>
#include <vector>
#include <unordered_set>
#include <string>

using namespace std;

struct TrieNode {
    TrieNode* children[26];
    bool isEnd;

    TrieNode() {
        for (int i = 0; i < 26; ++i) {
            children[i] = nullptr;
        }
        isEnd = false;
    }
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }

    void insert(string word) {
        TrieNode* node = root;
        for (char c : word) {
            int index = c - 'A'; 
            if (!node->children[index]) {
                node->children[index] = new TrieNode();
            }
            node = node->children[index];
        }
        node->isEnd = true;
    }

    TrieNode* getRoot() {
        return root;
    }

private:
    TrieNode* root;
};

bool isValid(int i, int j, int R, int C) {
    return i >= 0 && i < R && j >= 0 && j < C;
}

void findWords(int i, int j, vector<vector<char>>& board, TrieNode* node, string& current, unordered_set<string>& result, vector<vector<bool>>& visited, int R, int C) {
    if (node->isEnd) {
        result.insert(current);
    }

    int dx[] = { -1, -1, -1, 0, 0, 1, 1, 1 };
    int dy[] = { -1, 0, 1, -1, 1, -1, 0, 1 };
    for (int k = 0; k < 8; ++k) {
        int ni = i + dx[k];
        int nj = j + dy[k];
        if (isValid(ni, nj, R, C) && !visited[ni][nj] && node->children[board[ni][nj] - 'A']) {
            visited[ni][nj] = true;
            current.push_back(board[ni][nj]);
            findWords(ni, nj, board, node->children[board[ni][nj] - 'A'], current, result, visited, R, C);
            current.pop_back();
            visited[ni][nj] = false;
        }
    }
}

unordered_set<string> wordBoggle(vector<string>& dictionary, vector<vector<char>>& board, int R, int C) {
    Trie trie;
    for (string word : dictionary) {
        trie.insert(word);
    }

    unordered_set<string> result;
    vector<vector<bool>> visited(R, vector<bool>(C, false));

    for (int i = 0; i < R; ++i) {
        for (int j = 0; j < C; ++j) {
            if (trie.getRoot()->children[board[i][j] - 'A']) {
                visited[i][j] = true;
                string current = "";
                current.push_back(board[i][j]);
                findWords(i, j, board, trie.getRoot()->children[board[i][j] - 'A'], current, result, visited, R, C);
                visited[i][j] = false;
            }
        }
    }

    return result;
}

int main() {
    // Ex - 1
    int N1 = 1, R1 = 3, C1 = 3;
    vector<string> dictionary1 = { "CAT" };
    vector<vector<char>> board1 = { {'C', 'A', 'P'},
                                    {'A', 'N', 'D'},
                                    {'T', 'I', 'E'} };
    unordered_set<string> result1 = wordBoggle(dictionary1, board1, R1, C1);
    for (const string& word : result1) {
        cout << word << " "; // Output: CAT
    }
    cout << endl;

    // Ex - 2
    int N2 = 4, R2 = 3, C2 = 3;
    vector<string> dictionary2 = { "GEEKS", "FOR", "QUIZ", "GO" };
    vector<vector<char>> board2 = { {'G', 'I', 'Z'},
                                    {'U', 'E', 'K'},
                                    {'Q', 'S', 'E'} };
    unordered_set<string> result2 = wordBoggle(dictionary2, board2, R2, C2);
    for (const string& word : result2) {
        cout << word << " "; // Output: GEEKS QUIZ
    }
    cout << endl;

    return 0;
}
