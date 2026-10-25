
#include <bits/stdc++.h>

using namespace std;

int main() {

    int n;
    cin >> n;
    vector<int> nums(n);
    
    for(int i = 0; i < n; i++){
        cin >> nums[i];
    }   

    int dp[n] = {0}; 

    for(int i = n - 2; i >= 0; i--){
        if(i + 2 < n){
            dp[i] = min(dp[i+1] + abs(nums[i] - nums[i+1]), dp[i+2] + abs(nums[i] - nums[i+2]));
        } 
        else{
            dp[i] += dp[i + 1] + abs(nums[i] - nums[i + 1]);
        }
    }
    
    cout << dp[0];

    return 0;
}

