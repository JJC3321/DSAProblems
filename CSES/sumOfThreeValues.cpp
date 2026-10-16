#include <iostream>
#include <vector> 
#include <map>
#include <utility>
#include <algorithm>
 
using namespace std;
 
int main()
{
   
    int n;
    long long target;
    int temp = 0;
    cin >> n;
    cin >> target;
   
    vector<pair<long long ,int>> nums(n); 
    
    for(int i = 0; i < n; i++){
        cin >> nums[i].first;
        nums[i].second = i + 1;
    }
    
    sort(nums.begin(), nums.end());
    
    for(int i = 0; i < n - 2; i++){
        int left = i + 1;
        int right =  n - 1;
        while(left < right){
            long long currentSum = nums[i].first + nums[left].first + nums[right].first;
            if(currentSum == target){
                cout << nums[i].second << " " << nums[left].second << " " << nums[right].second << "\n";
                return 0;
            }
            else if(currentSum < target){
                left++;
            }
            else{
                right--;
            }
        }
    }
 
    cout << "IMPOSSIBLE";
        
    return 0;
}