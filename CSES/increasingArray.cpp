
#include <bits/stdc++.h>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<long long> nums(n);

    for(int i = 0; i < n; i++){
        cin >> nums[i];
    }
    
    long long res = 0;

    for(int i = 0; i < n - 1; i++){

        if(nums[i] <= nums[i+1]) continue;
        else{
            res += nums[i] - nums[i+1];
            nums[i+1] += nums[i] - nums[i+1];
        }

    }

    cout << res;


    return 0;
}
