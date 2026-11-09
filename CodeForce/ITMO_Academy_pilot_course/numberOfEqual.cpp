#include <bits/stdc++.h>

using namespace std;

int main(){

    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    vector<int> b(m);
    
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    
    for(int i = 0; i < m; i++){
        cin >> b[i];
    }
    
    long long ans = 0;
    int aPtr = 0;
    int bPtr = 0;

    while(bPtr < m && aPtr < n){

        if(a[aPtr] < b[bPtr]){
            aPtr++;
        }
        else if(a[aPtr] > b[bPtr]){
            bPtr++;
        }
        else{
            long long countA = 0;
            long long countB = 0;
            int curr = a[aPtr];

            while(aPtr < n && a[aPtr] == curr){
                countA++;
                aPtr++;
            }

            while(bPtr < m && b[bPtr] == curr){
                countB++;
                bPtr++;
            }
            
            ans += countA * countB;
        }
    }

    cout <<  ans;

    return 0;
}
