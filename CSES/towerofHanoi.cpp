
#include <bits/stdc++.h>

using namespace std;

void solve(int n, int source, int target, int auxiliary, vector<pair<int, int>>& moves) {
    if (n == 0) return;
    solve(n - 1, source, auxiliary, target, moves);
    moves.push_back({source, target});
    solve(n - 1, auxiliary, target, source, moves);
}

int main() {
    
    int n;
    cin >> n;

    vector<pair<int, int>> moves;
    solve(n, 1, 3, 2, moves);
    
    cout << moves.size() << "\n";
    for (const auto& p : moves) {
        cout << p.first << " " << p.second << "\n";
    }


    return 0;
}
