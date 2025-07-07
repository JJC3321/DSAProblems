#include <iostream>
#include <vector>
using namespace std;


int main() {
    
    int n, t, temp;
    cin >> n >> t;
    int ans = 0;
    vector<int> book;
    
    for(int i = 0; i < n; i++){
        cin >> temp;
        book.push_back(temp);
    }
    
    int sum = 0;
    int slow = 0;
    
    for(int fast = 0; fast < n; fast++){
        sum += book[fast];
        
        while(sum > t){
            sum -= book[slow];
            slow++;
        }
        
        ans = max(ans, fast - slow + 1);
    }

    
    cout << ans;
    return 0;
}
