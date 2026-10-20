
#include <bits/stdc++.h>

using namespace std;

int main() {
    
    long long n;
    cin >> n;
    
    while(n--){
        int a, b;
        cin >> a >> b;
        if ((a + b) % 3 == 0 && a <= 2 * b && b <= 2 * a){
            cout << "YES" << endl;
        }
        else{
            cout << "NO" << endl;
        }
    }


    return 0;
}
