#include <bits/stdc++.h>

using namespace std;

int main() {

    int n;
    cin >> n;
    vector<int> swim(n);
    vector<int> bug(n);
    vector<int> homework(n);

    int ans = 0;

    for(int i = 0; i < n; i++){
        cin >> swim[i];
        cin >> bug[i];
        cin >> homework[i];
    }

    vector<vector<int>> dp(n, vector<int>(3, 0));
    dp[0][0] = swim[0];
    dp[0][1] = bug[0];
    dp[0][2] = homework[0];
    

    for(int i = 1; i < n; i++){
        dp[i][0] = swim[i] + max(dp[i-1][1], dp[i-1][2]);
        dp[i][1] = bug[i] + max(dp[i-1][0], dp[i-1][2]);
        dp[i][2] = homework[i] + max(dp[i-1][0], dp[i-1][1]);
    }



    cout << max({dp[n-1][0], dp[n-1][1], dp[n-1][2]});

    return 0;
}

