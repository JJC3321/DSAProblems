#include <iostream>
#include <cmath>
using namespace std;

int main() {

    long long  n, ans = 0;
    cin >> n;
    
    if(pow(-1, n) * n < 0)
        ans = pow(-1, n) * n + (n / 2);
    else{
        ans = pow(-1, n) *n - (n/2);
    }
    
    cout << ans;
    
    return 0;
}
