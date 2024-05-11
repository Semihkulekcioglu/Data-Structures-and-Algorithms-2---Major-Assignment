#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool isValidSegment(const string& segment) {
    if (segment.empty() || segment.size() > 3) {
        return false;
    }
    if (segment[0] == '0' && segment.size() > 1) {
        return false;
    }
    int num = stoi(segment);
    return num >= 0 && num <= 255;
}

void genIpUtil(const string& s, int start, vector<string>& current, vector<string>& result) {
    if (current.size() == 4) {
        if (start == s.size()) {
            result.push_back(current[0] + '.' + current[1] + '.' + current[2] + '.' + current[3]);
        }
        return;
    }

    for (int len = 1; len <= 3; ++len) {
        if (start + len <= s.size()) {
            string segment = s.substr(start, len);
            if (isValidSegment(segment)) {
                current.push_back(segment);
                genIpUtil(s, start + len, current, result);
                current.pop_back();
            }
        }
    }
}

vector<string> genIp(string S) {
    vector<string> result;
    if (S.size() < 4 || S.size() > 12) {
        result.push_back("-1");
        return result;
    }
    vector<string> current;
    genIpUtil(S, 0, current, result);
    return result;
}

int main() {
    // Ex - 1
    string S1 = "1111";
    vector<string> result1 = genIp(S1);
    for (const string& ip : result1) {
        cout << ip << " "; // Output: 1.1.1.1
    }
    cout << endl;

    // Ex - 2
    string S2 = "55";
    vector<string> result2 = genIp(S2);
    for (const string& ip : result2) {
        cout << ip << " "; // Output: -1
    }
    cout << endl;

    return 0;
}
