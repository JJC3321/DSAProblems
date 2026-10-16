#include <iostream>
#include <vector>
#include <map>
 
using namespace std;
 
int main()
{
    int n;
    long long res = 0;
    cin >> n;
    vector<int>nums(n);
    map<long long, int> freqReminder;
    
    for(int i = 0; i < n; i++){
        cin >> nums[i];
    }
    
    long long prev = 0;
    freqReminder[0] = 1;
    
    for(int i = 0; i < n; i++){
        prev += nums[i];
        freqReminder[(prev % n + n) % n ]++;
    }
    
    for(auto x : freqReminder){
 
        if(x.second > 1){
            res += (x.second * (x.second - 1LL)) / 2;
        }
    }
    
    
    cout << res;    
 
    return 0;
}