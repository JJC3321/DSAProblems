#include <vector>
#include <iostream>
using namespace std;

int main()
{
    int size = 0;
    int n = 0, k = 0, p = 0; 
    cin >> size;
    for(int i = 0; i < size; i++){
        cin >> n >> k >> p;
        if(k < 0){
            if(-1 * n * p > k){
                cout << -1 << "\n";
                continue;
            }
        }
        else{
            if(n * p < k){
                cout << -1 << "\n";
                continue;
            }
        }
        if(k % p == 0){
            cout << abs(k / p) << "\n";
        }
        else{
            cout << abs(k / p) + 1 << "\n";
        }
        
    }

    return 0;
}
