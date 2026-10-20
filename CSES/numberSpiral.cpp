
#include <bits/stdc++.h>

using namespace std;

int main() {
    
    long long  t;
    cin >> t;

    for(int i = 0; i < t; i++){
        long long x, y;
        cin >> x >> y;
        long long z = max(y, x);
        if(z % 2 != 0){
            if( y == z){
                cout << z * z - (x-1) << endl;
            }
            else{
                cout << (z - 1) * (z- 1) + y << endl;
            }
        }else{
            if(y == z){
                cout << (z - 1) * (z- 1) + x << endl;
            }
            else{
                cout << z * z - (y - 1) << endl;
            }
        }
        

    }


    return 0;
}
