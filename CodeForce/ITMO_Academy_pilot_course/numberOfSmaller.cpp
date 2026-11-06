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
    vector<int> ans;
    int aPtr = 0;
    int bPtr = 0;

    while(bPtr < m){

        if(aPtr < n && b[bPtr] > a[aPtr]){
            aPtr++;    
        } 
        else{
            ans.push_back(aPtr);
            bPtr++;
        }
    }

    for(int x : ans) cout << x << " ";

    return 0;
}
