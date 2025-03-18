#include <iostream>

using namespace std;

int main() {

    int n,ans;
    cin >> n;
    for(int i = 0; i < n; i++){
        int q, p;
        cin >> p >> q;
        if(q - p > 1){
            ans++;
        }
    }
    
    cout << ans;
    
    
    return 0;
}
