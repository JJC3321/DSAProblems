#include <bits/stdc++.h>

using namespace std;

int main() {

    int h, w;
    long long mod = 1e9 + 7;
    cin >> h >> w;
    vector<string> a(h);

    for(int i = 0; i < h; i++){
        cin >> a[i];
    }

    vector<vector<long long>> dp(h, vector<long long>(w, 0));

    if(a[0][0] != '#') dp[0][0] = 1;

    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            if(a[i][j] == '#') continue;
            if(i > 0) dp[i][j] = (dp[i][j] + dp[i -1][j]) % mod;
            if(j > 0) dp[i][j] = (dp[i][j] + dp[i][j - 1]) % mod;
        }
    }

    cout << dp[h - 1][w -1];

    return 0;
}