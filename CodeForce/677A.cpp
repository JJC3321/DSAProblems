#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    
    int n, h, ans = 0;
    cin >> n >> h;
    
    
    for(int i = 0; i < n; i++){
        int a;
        cin >> a;
        if(a <= h)
            ans++;
        else{
            ans += 2;
        }
    }
    
    cout << ans; 
    
    return 0;
}
