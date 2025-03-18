#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> nums(n); 
    vector<int> result(n); 

    for (int i = 0; i < n; i++) {
        cin >> nums[i];
        nums[i]--; 
    }

    for (int i = 0; i < n; i++) {
        result[nums[i]] = i;
    }

    for (int i = 0; i < n; i++) {
        cout << result[i] + 1 << " "; 
    }

    return 0;
}
