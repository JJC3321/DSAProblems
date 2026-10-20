
#include <bits/stdc++.h>

using namespace std;

int main() {
    
    long long n;
    cin >> n; 

    long long num = 1;
    long long mod = 1000000007;

    for(int i = 0; i < n; i++){
        num = (num * 2) % mod;  
    }

    cout << num; 

    return 0;
}
