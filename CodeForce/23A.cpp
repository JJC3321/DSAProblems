#include <bits/stdc++.h>
using namespace std;

bool hasDuplicateSubstring(const string &str, int len) {
    unordered_set<string> seen;
    for (int i = 0; i <= str.size() - len; i++) {
        string sub = str.substr(i, len);
        if (seen.count(sub)) return true;
        seen.insert(sub);
    }
    return false;
}

int main() {
    string str;
    cin >> str;
    int left = 0, right = str.size();
    int res = 0;

    while (left <= right) {
        int mid = (left + right) / 2;
        if (hasDuplicateSubstring(str, mid)) {
            res = mid;  
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    cout << res << endl;
    return 0;
}
