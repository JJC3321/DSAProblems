#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n = 0, k =0, ans = 0; 
    vector<int> nums;
    cin >> n;
    cin >> k;
    for(int i = 0; i < n; i++){
        int temp;
        cin >> temp;
        nums.push_back(temp);
    }
    for(int i = 0; i < n; i++){
        
        if(nums[i] >= nums[k-1] and nums[i] > 0){
            ans++;
        }

    }
    cout << ans;
}