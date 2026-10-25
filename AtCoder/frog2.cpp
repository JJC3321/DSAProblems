
#include <bits/stdc++.h>

using namespace std;

int main() {

    int n, k;
    cin >> n >> k;
    vector<int> nums(n);
    
    for(int i = 0; i < n; i++){
        cin >> nums[i];
    }   

    int dp[n] = {0}; 

    for(int i = n - 2; i >= 0; i--){
        int smallest = dp[i + 1] + abs(nums[i] - nums[i + 1]);
        for(int j = 2; j <= min(k, n - 1 - i); j++){
            smallest = min(smallest, dp[i + j] + abs(nums[i] - nums[i + j]));
        }
        dp[i] = smallest;
    }
    
    cout << dp[0];

    return 0;
}

