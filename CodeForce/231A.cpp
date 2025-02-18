#include <iostream>

using namespace std;

int main()
{
    int n,a;
    int ans = 0;
    cin >> n;
    for(int i = 0; i < n; i++){
        int count = 0;
        for(int j = 0; j < 3; j++){
            cin >> a;
            if(a == 1){
                count++;
            }
        }
        if(count >= 2){
            ans++;
        }
    }
    cout << ans;
}
