
#include <bits/stdc++.h>

using namespace std;

int main() {
    
    long long n;
    cin >> n;
    long long total = 0;


    for(long long i = 5;  n / i > 0; i *= 5){
        total += n / i;
    }

    cout << total;


    return 0;
}
