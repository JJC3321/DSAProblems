#include <iostream>

using namespace std;

int main()
{
    int t,x,y,n,k;
    cin >> t;
    while(t--){
        cin >> x >> y >> n;
        if((n - y) % x == y ){
            cout << n - y << endl;
        }
         else{
            k = (n - y) % x;
            n = n - k;
            cout << n << endl;
        }

    }

    return 0;
}
