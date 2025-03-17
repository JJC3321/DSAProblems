#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    
    int n, a=0, b=0, m = 0, current = 0; 
    
    cin >> n;
    
    for(int i = 0; i < n; i++){
        cin >> a >> b;
        current -= a;
        current += b;
        m = max(current, m);
    }
    
    cout << m;
    
    
    return 0;
}
