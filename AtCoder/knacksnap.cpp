#include <bits/stdc++.h>

using namespace std;

int main() {

    int n, w;
    cin >> n >> w;
    vector<pair<int, long long>> item;

    for(int i = 0; i < n; i++){
        int temp = 0;
        long long temp2 = 0;
        cin >> temp >> temp2;
        item.push_back({temp, temp2});
    }

    vector<long long> dp (w+1, 0);  


    for(auto [wt, val] : item){
        for(int i = w; i >= wt; --i){
            dp[i] = max(dp[i], dp[i - wt] + val);
        }
    } 

    cout << dp[w];

    return 0;
}

