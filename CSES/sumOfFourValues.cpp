#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;
 
int main()
{
    int n;
    long long target;
    cin >> n;
	cin >> target;
	
	vector<long long> nums(n);
	
	for(int i = 0; i < n; i++){
	    cin >> nums[i];
	}
	
	unordered_map<long long, pair<int, int>> pairs;
	
	for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            long long reminder = target - nums[i] - nums[j];
            if(pairs.count(reminder)){
                auto p = pairs[reminder];
                cout << p.first + 1 << " " << p.second + 1  << " "<< i + 1 << " " << j + 1;
                return 0;
            }
        }	    
	    for(int j = 0; j < i; j++){
	        pairs[nums[j] + nums[i]] = {j, i};
	    }
	}
    
	cout << "IMPOSSIBLE";
    
    return 0;
}
