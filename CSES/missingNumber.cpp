#include <bits/stdc++.h>

using namespace std;

int main() {
    long long  n;
    cin >> n;
    vector<long long> nums(n-1);

    

    for(int i = 0; i < n-1; i++){
        cin >> nums[i];
    }

    sort(nums.begin(), nums.end());

    long long number = 1;

    for(int x : nums){
       
        if(x != number){
            break;
        }
        number++;

    }

    cout << number;

    return 0;
}
