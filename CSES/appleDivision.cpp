
#include <bits/stdc++.h>

using namespace std;

int main() {
    
    int n;
    cin >> n;
    vector<long long> nums(n);
    long long totalSum = 0;

    for(int i = 0; i < n; i++){
        cin >> nums[i];
        totalSum += nums[i];
    }

    long long minDiff = totalSum;
    int totalMasks = 1 << n;

    for (int mask = 0; mask < totalMasks; mask++) {
        long long group1 = 0;
        for (int i = 0; i < n; ++i) {
            if ((mask >> i) & 1) {
                group1 += nums[i];
            }
        }
        long long group2 = totalSum - group1;
        long long diff = abs(group1 - group2);
        minDiff = min(minDiff, diff);
    }

    cout << minDiff;

    return 0;
}
