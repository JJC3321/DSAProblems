#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main() {
    
    vector<int> nums;
    set<int> u; 
    
    for(int i = 0; i < 4; i++){
        int a;
        cin >>a;
        nums.push_back(a);
    }
    for(int i = 0; i < 4; i++){
        
        u.insert(nums[i]);
    }
    
    cout << 4 - u.size();

    return 0;
}
