
#include <bits/stdc++.h>

using namespace std;

int main() {
    
    long long  n;
    cin >> n;

    for(long long i = 1; i <= n; i++){
        long long num = ((i - 1) * (i + 4) * ( i * i - 3 * i + 4)) / 2;
        cout << num << endl;
    }



    return 0;
}
