#include <iostream>

using namespace std;

int main()
{
    int k,n,w;
    cin >> k >> n >> w;
    n -= k;
    for(int i = 2; i <= w; i++){
        n -= k * i;
    }
    if(n >= 0){
        cout << 0;
    }
    else{
        cout << abs(n);
    }
    return 0;
}
